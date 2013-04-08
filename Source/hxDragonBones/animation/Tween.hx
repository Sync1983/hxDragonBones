package hxDragonBones.animation;
import haxe.Log;
import haxe.remoting.FlashJsConnection;
import hxDragonBones.Armature;
import hxDragonBones.Bone;
import hxDragonBones.events.FrameEvent;
import hxDragonBones.events.SoundEvent;
import hxDragonBones.events.SoundEventManager;
import hxDragonBones.objects.FrameData;
import hxDragonBones.objects.MovementBoneData;
import hxDragonBones.objects.Node;
import hxDragonBones.utils.TransformUtils;
import nme.geom.ColorTransform;

/**
 * @author SlavaRa
 */
class Tween{

	static inline var HALF_PI:Float = Math.PI * 0.5;
	static var _soundManager:SoundEventManager = SoundEventManager.instance;
	
	public static inline function getEaseValue(value:Float, ?easing:Float):Float {
		var valueEase:Float = 0;
		if (Math.isNaN(easing)) {
			valueEase = 0;
			easing = 0;
			value = 0;
		} else if (easing > 1) {
			valueEase = 0.5 * (1 - Math.cos(value * Math.PI)) - value;
			easing -= 1;
		} else if (easing > 0) {
			valueEase = Math.sin(value * HALF_PI) - value;
		} else if (easing < 0) {
			valueEase = 1 - Math.cos(value * HALF_PI) - value;
			easing *= -1;
		}
		return valueEase * easing + value;
	}
	
	public function new(bone:Bone) {
		_bone = bone;
		_node = _bone.tweenNode;
		_colorTransform = _bone.tweenColorTransform;
		
		_curNode = new Node();
		_curColorTransform = new ColorTransform();
		
		_offSetNode = new Node();
		_offSetColorTransform = new ColorTransform();
	}
	
	public var differentColorTransform:Bool;
	
	var _bone:Bone;
	var _movementBoneData:MovementBoneData;
	var _node:Node;
	var _colorTransform:ColorTransform;
	var _curNode:Node;
	var _curColorTransform:ColorTransform;
	var _offSetNode:Node;
	var _offSetColorTransform:ColorTransform;
	var _curFrameData:FrameData;
	var _tweenEasing:Float;
	var _frameTweenEasing:Float;
	var _isPause:Bool;
	var _rawDuration:Float;
	var _nextFrameDataTimeEdge:Float;
	var _frameDuration:Float;
	var _nextFrameDataID:Int;
	var _loop:Int;
	
	public function gotoAndPlay(movementBoneData:MovementBoneData, rawDuration:Float, loop:Bool, tweenEasing:Float) {
		
		if(movementBoneData == null) {
			return;
		}
		
		_movementBoneData = movementBoneData;
		var totalFrames:Int = _movementBoneData.frameList.length;
		if(totalFrames == 0) {
			_bone.changeDisplay(-1);
			stop();
			return;
		}
		
		_node.skewX %= 360;
		_node.skewY %= 360;
		_isPause = false;
		_curFrameData = null;
		_loop = loop ? 0 : -1;
		
		_nextFrameDataTimeEdge = 0;
		_nextFrameDataID = 0;
		_rawDuration = rawDuration;
		_tweenEasing = tweenEasing;
		
		var nextFrameData:FrameData = null;
		if (totalFrames == 1) {
			_frameTweenEasing = 1;
			_rawDuration = 0;
			nextFrameData = _movementBoneData.frameList[0];
			setOffset(_node, _colorTransform, nextFrameData.node, nextFrameData.colorTransform);
		} else if (loop && (_movementBoneData.delay != 0)) {
			getLoopListNode();
			setOffset(_node, _colorTransform, _offSetNode, _offSetColorTransform);
		} else {
			nextFrameData = _movementBoneData.frameList[0];
			setOffset(_node, _colorTransform, nextFrameData.node, nextFrameData.colorTransform);
		}
		
		if (nextFrameData != null) {
			updateBoneDisplayIndex(nextFrameData);
		}
	}
	
	public function stop() {
		_isPause = true;
	}
	
	public function advanceTime(progress:Float, playType:Int) {
		if(_isPause) {
			return;
		}
		
		if(_rawDuration == 0) {
			playType = Animation.SINGLE;
			if(progress == 0) {
				progress = 1;
			}
		}
		
		if(playType == Animation.LOOP) {
			progress /= _movementBoneData.scale;
			progress += _movementBoneData.delay;
			var loop:Int = Std.int(progress);
			if(_loop != loop) {
				_nextFrameDataTimeEdge = 0;
				_nextFrameDataID = 0;
				_loop = loop;
			}
			progress -= loop;
			progress = updateFrameData(progress, true);
		} else if (playType == Animation.LIST) {
			progress = updateFrameData(progress, true, true);
		} else if ((playType == Animation.SINGLE) && (progress == 1)) {
			_curFrameData = _movementBoneData.frameList[0];
			_isPause = true;
		} else {
			progress = Math.sin(progress * HALF_PI);
		}
		
		
		if (!Math.isNaN(_frameTweenEasing) || (_curFrameData != null)) {
			TransformUtils.setTweenNode(_curNode, _offSetNode, _node, progress);
			if(differentColorTransform) {
				TransformUtils.setTweenColorTransform(_curColorTransform, _offSetColorTransform, _colorTransform, progress);
			}
		}
		
		if(_curFrameData != null) {
			arriveFrameData(_curFrameData);
			_curFrameData = null;
		}
	}
	
	function getLoopListNode() {
		var playedTime:Float = _rawDuration * _movementBoneData.delay;
		var length:Int = _movementBoneData.frameList.length;
		var nextFrameDataID:Int = 0;
		var nextFrameDataTimeEdge:Float= 0;
		var curFrameDataID:Int;
		var frameDuration:Float;
		do {
			curFrameDataID = nextFrameDataID;
			frameDuration = _movementBoneData.frameList[curFrameDataID].duration;
			nextFrameDataTimeEdge += frameDuration;
			if (++nextFrameDataID >= length) {
				nextFrameDataID = 0;
			}
		} while (playedTime >= nextFrameDataTimeEdge);
		
		var currentFrameData:FrameData = _movementBoneData.frameList[curFrameDataID];
		var nextFrameData:FrameData = _movementBoneData.frameList[nextFrameDataID];
		
		setOffset(currentFrameData.node, currentFrameData.colorTransform, nextFrameData.node, nextFrameData.colorTransform);
		
		var progress:Float = 1 - (nextFrameDataTimeEdge - playedTime) / frameDuration;
		
		var tweenEasing:Float = Math.isNaN(_tweenEasing) ? currentFrameData.tweenEasing : _tweenEasing;
		if (tweenEasing != 0) {
			progress = getEaseValue(progress, tweenEasing);
		}
		
		TransformUtils.setOffSetNode(currentFrameData.node, nextFrameData.node, _offSetNode);
		TransformUtils.setTweenNode(_curNode, _offSetNode, _offSetNode, progress);
		
		TransformUtils.setOffSetColorTransform(currentFrameData.colorTransform, nextFrameData.colorTransform, _offSetColorTransform);
		TransformUtils.setTweenColorTransform(_curColorTransform, _offSetColorTransform, _offSetColorTransform, progress);
	}
	
	function setOffset(currentNode:Node, curColorTransform:ColorTransform, nextNode:Node, nextColorTransform:ColorTransform, tweenRotate:Int = 0) {
		_curNode.copyFrom(currentNode);
		TransformUtils.setOffSetNode(_curNode, nextNode, _offSetNode, tweenRotate);
		
		_curColorTransform.alphaOffset 		= curColorTransform.alphaOffset;
		_curColorTransform.redOffset 		= curColorTransform.redOffset;
		_curColorTransform.greenOffset 		= curColorTransform.greenOffset;
		_curColorTransform.blueOffset 		= curColorTransform.blueOffset;
		_curColorTransform.alphaMultiplier 	= curColorTransform.alphaMultiplier;
		_curColorTransform.redMultiplier 	= curColorTransform.redMultiplier;
		_curColorTransform.greenMultiplier 	= curColorTransform.greenMultiplier;
		_curColorTransform.blueMultiplier 	= curColorTransform.blueMultiplier;
		
		TransformUtils.setOffSetColorTransform(_curColorTransform, nextColorTransform, _offSetColorTransform);
		
		if(
			_offSetColorTransform.alphaOffset 		!= 0 ||
			_offSetColorTransform.redOffset 		!= 0 ||
			_offSetColorTransform.greenOffset 		!= 0 ||
			_offSetColorTransform.blueOffset 		!= 0 ||
			_offSetColorTransform.alphaMultiplier 	!= 0 ||
			_offSetColorTransform.redMultiplier 	!= 0 ||
			_offSetColorTransform.greenMultiplier 	!= 0 ||
			_offSetColorTransform.blueMultiplier 	!= 0
		) {
			differentColorTransform = true;
		} else {
			differentColorTransform = false;
		}
	}
	
	function updateBoneDisplayIndex(frameData:FrameData) {
		if(frameData.displayIndex >= 0) {
			if(_node.z != frameData.node.z) {
				_node.z = frameData.node.z;
				if(_bone.armature != null){
					_bone.armature.bonesIndexChanged = true;
				}
			}
		}
		_bone.changeDisplay(frameData.displayIndex);
	}
	
	function arriveFrameData(frameData:FrameData) {
		updateBoneDisplayIndex(frameData);
		_bone.visible = frameData.visible;
		
		if((frameData.event != null) && _bone.armature.hasEventListener(FrameEvent.BONE_FRAME_EVENT)) {
			var frameEvent:FrameEvent = new FrameEvent(FrameEvent.BONE_FRAME_EVENT, false, _bone);
			frameEvent.movementID = _bone.armature.animation.movementID;
			frameEvent.frameLabel = frameData.event;
			_bone.armature.dispatchEvent(frameEvent);
		}
		
		if((frameData.sound != null) && _soundManager.hasEventListener(SoundEvent.SOUND)) {
			var soundEvent:SoundEvent = new SoundEvent(SoundEvent.SOUND);
			soundEvent.movementID = _bone.armature.animation.movementID;
			soundEvent.sound = frameData.sound;
			soundEvent.armature = _bone.armature;
			soundEvent.bone = _bone;
			_soundManager.dispatchEvent(soundEvent);
		}
		
		if((frameData.movement != null) && (_bone.childArmature != null)) {
			_bone.childArmature.animation.gotoAndPlay(frameData.movement);
		}
	}
	
	function updateFrameData(progress:Float, ?activeFrame:Bool, ?isList:Bool):Float {
		var playedTime:Float = _rawDuration * progress;
		if (playedTime >= _nextFrameDataTimeEdge) {
			var currentFrameDataID:Int;
			var length:Int = _movementBoneData.frameList.length;
			do {
				currentFrameDataID = _nextFrameDataID;
				_frameDuration = _movementBoneData.frameList[currentFrameDataID].duration;
				_nextFrameDataTimeEdge += _frameDuration;
				if (++_nextFrameDataID >= length) {
					_nextFrameDataID = 0;
				}
			} while (playedTime >= _nextFrameDataTimeEdge);
			
			var curFrameData:FrameData = _movementBoneData.frameList[currentFrameDataID];
			var nextFrameData:FrameData = _movementBoneData.frameList[_nextFrameDataID];
			
			if((nextFrameData.displayIndex >= 0) && _bone.armature.animation.tweenEnabled) {
				_frameTweenEasing = curFrameData.tweenEasing;
			} else {
				_frameTweenEasing = Math.NaN;
			}
			
			setOffset(curFrameData.node, curFrameData.colorTransform, nextFrameData.node, nextFrameData.colorTransform, nextFrameData.tweenRotate);
			
			if (activeFrame) {
				_curFrameData = curFrameData;
			}
			
			if(isList && (_nextFrameDataID == 0)) {
				_isPause = true;
				return 0;
			}
		}
		
		progress = 1 - (_nextFrameDataTimeEdge - playedTime) / _frameDuration;
		
		if (!Math.isNaN(_frameTweenEasing)) {
			var tweenEasing:Float = Math.isNaN(_tweenEasing) ? _frameTweenEasing : _tweenEasing;
			if (tweenEasing != 0) {
				progress = getEaseValue(progress, tweenEasing);
			}
		}
		return getEaseValue(progress, _frameTweenEasing);
	}
}