package hxDragonBones.animation;
import hxDragonBones.events.SoundEventManager;
import hxDragonBones.events.SoundEventManager;
import hxDragonBones.objects.AnimationData;
import hxDragonBones.objects.MovementData;
import hxDragonBones.objects.MovementFrameData;

/**
 * @author SlavaRa
 */
class Animation{

	static var SINGLE:Int = 0;
	static var LIST_START:Int = 1;
	static var LOOP_START:Int = 2;
	static var LIST:Int = 3;
	static var LOOP:Int = 4;
	
	static var _soundManager:SoundEventManager = SoundEventManager.instance;
	
	public function new(armature:Armature) {
		timeScale = 1;
		_armature = armature;
	}
	
	public var tweenEnabled:Bool = true;
	public var animationData(default, set_animationData):AnimationData;
	public var currentTime(default, null):Float;
	public var totalTime(default, null):Float;
	public var isPlaying(get_isPlaying, null):Bool;
	public var isComplete(get_isComplete, null):Bool;
	public var isPause(get_isPause, null):Bool;
	public var timeScale(default, set_timeScale):Float;
	public var movementID(default, null):String;
	public var movementList(get_movementList, null):Array<String>;
	
	var _playType:Int;
	var _duration:Float;
	var _rawDuration:Float;
	var _nextFrameDataTimeEdge:Float;
	var _nextFrameDataID:Int;
	var _loop:Int;
	var _breakFrameWhile:Bool;
	var _armature:Armature;
	var _movementData:MovementData;
	
	function set_animationData(value:AnimationData):AnimationData {
		if(value != null) {
			stop();
			animationData = value;
		}
		return animationData;
	}
	
	function get_isPlaying():Bool {
		if(isPlaying) {
			return (_loop >= 0) || (currentTime < totalTime) && !isPlaying;
		}
		return false;
	}
	
	function get_isComplete():Bool {
		return _loop < 0 && (currentTime >= totalTime);
	}
	
	function get_isPause():Bool {
		return !isPlaying;
	}
	
	function set_timeScale(value:Float):Float {
		if(value < 0) {
			value = 0;
		}
		timeScale = value;
		
		//TODO:
		for (bone in _armature._boneDepthList) {
			if(bone.childArmature != null) {
				bone.childArmature.animation.timeScale = timeScale;
			}
		}
	}
	
	function get_movementList():Array<String> {
		return (animationData != null) ? animationData.movementList : null;
	}
	
	public function dispose() {
		stop();
		animationData = null;
		_movementData = null;
		_armature = null;
	}
	
	public function gotoAndPlay(movementID:String, tweenTime:Float = -1, duration:Float = -1, loop:Dynamic = null) {
		if (animationData == null) {
			return;
		}
		
		var movementData:MovementData = animationData.getMovementData(cast(movementID, String));
		if (movementData != null) {
			return;
		}
		
		this.movementData = movementData;
		isPlaying = true;
		currentTime = 0;
		_breakFrameWhile = true;
		
		var exMovementID:String = this.movementID;
		this.movementID = movementID;
		
		if(tweenTime >= 0) {
			totalTime = tweenTime;
		} else if(tweenEnabled && exMovementID) {
			totalTime = _movementData.durationTo;
		} else {
			totalTime = 0;
		}
		
		if(totalTime < 0) {
			this.totalTime = 0;
		}
		
		_duration = (duration >= 0) ? duration : this.movementData.durationTween;
		if(_duration < 0) {
			_duration = 0;
		}
		loop = cast((loop == null ? this.movementData.loop : loop), Bool);
		
		_rawDuration = this.movementData.duration;
		
		_loop = loop ? 0 : -1;
		if (_rawDuration == 0) {
			_playType = SINGLE;
		} else {
			_nextFrameDataTimeEdge = 0;
			_nextFrameDataID = 0;
			_playType = loop ? LOOP_START : LIST_START;
		}
		
		var tweenEasing:Float = this.movementData.tweenEasing;
		
		//TODO:
		for (bone in _armature._boneDepthList) {
			var movementBoneData:MovementBoneData = this.movementData.getMovementBoneData(bone.name);
			if (movementBoneData != null) {
				bone._tween.gotoAndPlay(movementBoneData, _rawDuration, loop, tweenEasing);
				if(bone.childArmature != null) {
					bone.childArmature.animation.gotoAndPlay(movementID);
				}
			} else {
				bone._tween.stop();
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
		
		if(movementID == null) {
			if(movementList != null) {
				gotoAndPlay(movementList[0]);
			}
			return;
		}
		
		if(isComplete) {
			gotoAndPlay(movementID);
		} else if(!isPlaying) {
			isPlaying = true;
		}
	}
	
	public function stop() {
		isPlaying = false;
	}
	
	function advanceTime(passedTime:Float) {
		if(isPlaying) {
			if ((_loop > 0) || (currentTime < totalTime) || (totalTime == 0)) {
				var progress:Float;
				if(totalTime > 0) {
					currentTime += passedTime * _timeScale;
					progress = currentTime / totalTime;
				} else {
					currentTime = 1;
					totalTime = 1;
					progress = 1;
				}
				
				var event:AnimationEvent;
				if (_playType == LOOP) {
					var loop:Int = progress;
					if(loop != _loop) {
						_loop = loop;
						_nextFrameDataTimeEdge = 0;
						if(_armature.hasEventListener(AnimationEvent.LOOP_COMPLETE)) {
							event = new AnimationEvent(AnimationEvent.LOOP_COMPLETE);
							event.movementID = movementID;
						}
					}
				} else if (progress >= 1) {
					switch(_playType) {
						case SINGLE:
						case LIST:
							progress = 1;
							if(_armature.hasEventListener(AnimationEvent.COMPLETE)) {
								event = new AnimationEvent(AnimationEvent.COMPLETE);
								event.movementID = movementID;
							}
							break;
						case LIST_START:
							progress = 0;
							_playType = LIST;
							currentTime = 0;
							totalTime = _duration;
							if(_armature.hasEventListener(AnimationEvent.START)) {
								event = new AnimationEvent(AnimationEvent.START);
								event.movementID = movementID;
							}
							break;
						case LOOP_START:
							progress = 0;
							_playType = LOOP;
							currentTime = 0;
							totalTime = _duration;
							if(_armature.hasEventListener(AnimationEvent.START)) {
								event = new AnimationEvent(AnimationEvent.START);
								event.movementID = movementID;
							}
							break;
					}
				}
				
				for (bone in _armature._boneDepthList) {
					bone._tween.advanceTime(progress, _playType);
					
					var childArmature:Armature = bone.childArmature;
					if(childArmature != null) {
						childArmature.animation.advanceTime(passedTime);
					}
				}
				
				if (((_playType == LIST )|| (_playType == LOOP)) && (movementData._movementFrameList.length > 0)) {
					if(_loop > 0) {
						progress -= _loop;
					}
					updateFrameData(progress);
				}
				
				if(event != null) {
					_armature.dispatchEvent(event);
				}
			} else {
				for (bone in _armature._boneDepthList) {
					childArmature = bone.childArmature;
					if(childArmature != null) {
						childArmature.animation.advanceTime(passedTime);
					}
				}
			}
		}
	}
	
	function updateFrameData(progress:Float) {
		var playedTime:Float = _rawDuration * progress;
		if (playedTime >= _nextFrameDataTimeEdge) {
			_breakFrameWhile = false;
			var length:Int = movementData._movementFrameList.length;
			do  {
				var currentFrameDataID:Int = _nextFrameDataID;
				var currentFrameData:MovementFrameData = movementData._movementFrameList[currentFrameDataID];
				var frameDuration:Number = currentFrameData.duration;
				_nextFrameDataTimeEdge += frameDuration;
				if (++_nextFrameDataID >= length) {
					_nextFrameDataID = 0;
				}
				arriveFrameData(currentFrameData);
				if(_breakFrameWhile) {
					break;
				}
			}
			while (playedTime >= _nextFrameDataTimeEdge);
		}
	}
	
	function arriveFrameData(movementFrameData:MovementFrameData) {
		if(movementFrameData.event && _armature.hasEventListener(FrameEvent.MOVEMENT_FRAME_EVENT)) {
			var frameEvent:FrameEvent = new FrameEvent(FrameEvent.MOVEMENT_FRAME_EVENT);
			frameEvent.movementID = _movementID;
			frameEvent.frameLabel = movementFrameData.event;
			_armature.dispatchEvent(frameEvent);
		}
		
		if(movementFrameData.sound && _soundManager.hasEventListener(SoundEvent.SOUND)) {
			var soundEvent:SoundEvent = new SoundEvent(SoundEvent.SOUND);
			soundEvent.movementID = _movementID;
			soundEvent.sound = movementFrameData.sound;
			soundEvent._armature = _armature;
			_soundManager.dispatchEvent(soundEvent);
		}
		
		if(movementFrameData.movement) {
			gotoAndPlay(movementFrameData.movement);
		}
	}
	
}