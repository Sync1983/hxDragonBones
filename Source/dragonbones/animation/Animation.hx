package dragonbones.animation;
import dragonbones.Armature;
import dragonbones.Bone;
import dragonbones.events.AnimationEvent;
import dragonbones.events.FrameEvent;
import dragonbones.events.SoundEvent;
import dragonbones.events.SoundEventManager;
import dragonbones.objects.AnimationData;
import dragonbones.objects.MovementBoneData;
import dragonbones.objects.MovementData;
import dragonbones.objects.MovementFrameData;
import dragonbones.utils.IDisposable;
import haxe.Log;

/**
 * @author SlavaRa
 */
class Animation implements IDisposable{

	public static inline var SINGLE:Int = 0;
	public static inline var LIST_START:Int = 1;
	public static inline var LOOP_START:Int = 2;
	public static inline var LIST:Int = 3;
	public static inline var LOOP:Int = 4;
	
	static var _soundManager:SoundEventManager = SoundEventManager.instance;
	
	public function new(armature:Armature) {
		_armature = armature;
		timeScale = 1;
		tweenEnabled = true;
	}
	
	public var tweenEnabled(default, null):Bool;
	public var animationData(default, set_animationData):AnimationData;
	public var isPlaying(default, null):Bool;
	public var isComplete(get_isComplete, null):Bool;
	public var timeScale(default, set_timeScale):Float;
	public var movementID(default, null):String;
	public var movementList(default, null):Array<String>;
	
	var _armature:Armature;
	var _totalTime:Float;
	var _curTime:Float;
	var _playType:Int;
	var _duration:Float;
	var _rawDuration:Float;
	var _nextFrameDataTimeEdge:Float;
	var _nextFrameDataID:Int;
	var _loop:Int;
	var _breakFrameWhile:Bool;
	var _movementData:MovementData;
	
	function set_animationData(value:AnimationData):AnimationData {
		if(value != null) {
			stop();
			animationData = value;
			movementList = value.movementList;
		} else {
			animationData = null;
			movementList = null;
		}
		return value;
	}
	
	function get_isComplete():Bool {
		return (_loop < 0) && (_curTime >= _totalTime);
	}
	
	function set_timeScale(value:Float):Float {
		if (value < 0) {
			value = 0;
		}
		
		timeScale = value;
		
		for (bone in _armature.bones) {
			if(bone.childArmature != null) {
				bone.childArmature.animation.timeScale = timeScale;
			}
		}
		return value;
	}
	
	public function dispose() {
		stop();
		animationData = null;
		_movementData = null;
		_armature = null;
	}
	
	public function gotoAndPlay(movementID:String, tweenTime:Float = -1, duration:Float = -1, ?loop:Dynamic) {
		if (animationData == null) {
			return;
		}
		
		var movementData:MovementData = animationData.getMovementData(movementID);
		if (movementData == null) {
			return;
		}
		
		_movementData = movementData;
		isPlaying = true;
		_curTime = 0;
		_breakFrameWhile = true;
		
		var exMovementID:String = this.movementID;
		this.movementID = movementID;
		
		if(tweenTime >= 0) {
			_totalTime = tweenTime;
		} else if(tweenEnabled && (exMovementID != null)) {
			_totalTime = movementData.durationTo;
		} else {
			_totalTime = 0;
		}
		
		if(_totalTime < 0) {
			_totalTime = 0;
		}
		
		_duration = (duration >= 0) ? duration : _movementData.durationTween;
		if(_duration < 0) {
			_duration = 0;
		}
		
		loop = cast((loop == null ? _movementData.loop : loop), Bool);
		
		_rawDuration = _movementData.duration;
		
		_loop = loop ? 0 : -1;
		if (_rawDuration == 0) {
			_playType = SINGLE;
		} else {
			_nextFrameDataTimeEdge = 0;
			_nextFrameDataID = 0;
			_playType = loop ? LOOP_START : LIST_START;
		}
		
		for (bone in _armature.bones) {
			var movementBoneData:MovementBoneData = _movementData.getMovementBoneData(bone.name);
			if (movementBoneData != null) {
				bone.tween.gotoAndPlay(movementBoneData, _rawDuration, loop, _movementData.tweenEasing);
				if (bone.childArmature != null) {
					bone.childArmature.animation.gotoAndPlay(movementID);
				}
			} else {
				bone.tween.stop();
			}
		}
		
		if(_armature.hasEventListener(AnimationEvent.MOVEMENT_CHANGE)) {
			var event:AnimationEvent = new AnimationEvent(AnimationEvent.MOVEMENT_CHANGE);
			event.exMovementID = exMovementID;
			event.movementID = this.movementID;
			_armature.dispatchEvent(event);
		}
	}
	
	public function play() {
		if (animationData == null) {
			return;
		}
		
		if (movementID == null) {
			if (movementList != null) {
				gotoAndPlay(movementList[0]);
			}
			return;
		}
		
		if (isComplete) {
			gotoAndPlay(movementID);
		} else if(!isPlaying) {
			isPlaying = true;
		}
	}
	
	public function stop() {
		isPlaying = false;
	}
	
	public function advanceTime(passedTime:Float) {
		if (!isPlaying) {
			return;
		}
		
		var bones:Array<Bone> = null;
		var length:Int;
		
		if ((_loop > 0) || (_curTime < _totalTime) || (_totalTime == 0)) {
			
			var event:AnimationEvent = null;
			var progress:Float;
			
			if(_totalTime > 0) {
				_curTime += passedTime * timeScale;
				progress = _curTime / _totalTime;
			} else {
				_curTime = 1;
				_totalTime = 1;
				progress = 1;
			}
			
			if (_playType == LOOP) {
				var loop:Int = Std.int(progress);
				if(loop != _loop) {
					_loop = loop;
					_nextFrameDataTimeEdge = 0;
					if(_armature.hasEventListener(AnimationEvent.LOOP_COMPLETE)) {
						event = new AnimationEvent(AnimationEvent.LOOP_COMPLETE);
					}
				}
			} else if (progress >= 1) {
				switch(_playType) {
					case SINGLE, LIST:
						progress = 1;
						if(_armature.hasEventListener(AnimationEvent.COMPLETE)) {
							event = new AnimationEvent(AnimationEvent.COMPLETE);
						}
					case LIST_START:
						progress = 0;
						_playType = LIST;
						_curTime = 0;
						_totalTime = _duration;
						if(_armature.hasEventListener(AnimationEvent.START)) {
							event = new AnimationEvent(AnimationEvent.START);
						}
					case LOOP_START:
						progress = 0;
						_playType = LOOP;
						_curTime = 0;
						_totalTime = _duration;
						if(_armature.hasEventListener(AnimationEvent.START)) {
							event = new AnimationEvent(AnimationEvent.START);
						}
				}
			}
			
			bones = _armature.bones;
			length = bones.length;
			for (i in 0...length) {
				var bone:Bone = bones[i];
				bone.tween.advanceTime(progress, _playType);
				if (bone.childArmature != null) {
					bone.childArmature.animation.advanceTime(passedTime);
				}
			}
			
			if (((_playType == LIST) || (_playType == LOOP)) && (_movementData.movementFrameList.length > 0)) {
				if(_loop > 0) {
					progress -= _loop;
				}
				updateFrameData(progress);
			}
			
			if (event != null) {
				event.movementID = movementID;
				_armature.dispatchEvent(event);
			}
		} else {
			bones = _armature.bones;
			length = bones.length;
			for (i in 0...length) {
				var bone:Bone = bones[i];
				if(bone.childArmature != null) {
					bone.childArmature.animation.advanceTime(passedTime);
				}
			}
		}
	}
	
	function updateFrameData(progress:Float) {
		var playedTime:Float = _rawDuration * progress;
		if (playedTime < _nextFrameDataTimeEdge) {
			return;
		}
		
		_breakFrameWhile = false;
		var length:Int = _movementData.movementFrameList.length;
		do  {
			var currentFrameData:MovementFrameData = _movementData.movementFrameList[_nextFrameDataID];
			_nextFrameDataTimeEdge += currentFrameData.duration;
			if (++_nextFrameDataID >= length) {
				_nextFrameDataID = 0;
			}
			arriveFrameData(currentFrameData);
			if(_breakFrameWhile) {
				break;
			}
		} while (playedTime >= _nextFrameDataTimeEdge);
	}
	
	function arriveFrameData(movementFrameData:MovementFrameData) {
		if((movementFrameData.event != null) && _armature.hasEventListener(FrameEvent.MOVEMENT_FRAME_EVENT)) {
			var frameEvent:FrameEvent = new FrameEvent(FrameEvent.MOVEMENT_FRAME_EVENT);
			frameEvent.movementID = movementID;
			frameEvent.frameLabel = movementFrameData.event;
			_armature.dispatchEvent(frameEvent);
		}
		
		if((movementFrameData.sound != null) && _soundManager.hasEventListener(SoundEvent.SOUND)) {
			var soundEvent:SoundEvent = new SoundEvent(SoundEvent.SOUND);
			soundEvent.movementID = movementID;
			soundEvent.sound = movementFrameData.sound;
			soundEvent.armature = _armature;
			_soundManager.dispatchEvent(soundEvent);
		}
		
		if(movementFrameData.movement != null) {
			gotoAndPlay(movementFrameData.movement);
		}
	}
	
}