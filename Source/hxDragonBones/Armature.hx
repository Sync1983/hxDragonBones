package hxDragonBones;

import haxe.Log;
import hxDragonBones.animation.Animation;
import hxDragonBones.animation.IAnimatable;
import hxDragonBones.events.ArmatureEvent;
import hxDragonBones.utils.IDisposable;
import nme.events.EventDispatcher;
import nme.geom.ColorTransform;
import nme.Lib;

/**
 * @author SlavaRa
 */
class Armature extends EventDispatcher, implements IAnimatable, implements IDisposable{

	public function new(display:Dynamic) {
		super();
		this.display = display;
		bones = [];
		_rootBones = [];
		animation = new Animation(this);
		bonesIndexChanged = false;
	}
	
	public var name:String;
	public var display(default, null):Dynamic;
	public var animation(default, null):Animation;
	public var bones:Array<Bone>;
	public var bonesIndexChanged:Bool;
	public var colorTransform(default, set_colorTransform):ColorTransform;
	public var colorTransformChange:Bool;
	
	function set_colorTransform(value:ColorTransform):ColorTransform {
		if (value == colorTransform) {
			return value;
		}
		colorTransform = value;
		colorTransformChange = true;
		return value;
	}
	
	var _rootBones:Array<Bone>;
	
	public function dispose() {
		for (i in _rootBones) {
			i.dispose();
		}
		
		colorTransform = null;
		bones = null;
		_rootBones = null;
		animation.dispose();
		animation = null;
	}
	
	public function getBone(name:String):Bone {
		if(name != null) {
			for(bone in bones) {
				if(bone.name == name) {
					return bone;
				}
			}
		}
		return null;
	}
	
	public function getBoneByDisplay(display:Dynamic):Bone {
		if(display != null) {
			for (bone in bones) {
				if(bone.display == display) {
					return bone;
				}
			}
		}
		return null;
	}
	
	public function addBone(bone:Bone, ?parentName:String) {
		if (bone != null) {
			var boneParent:Bone = getBone(parentName); 
			if (boneParent != null) {
				boneParent.addChild(bone);
			} else {
				bone.removeFromParent();
				addToBones(bone, true);
			}
		}
	}
	
	public function removeBone(bone:Bone) {
		if (bone != null) {
			if(bone.parent != null) {
				bone.removeFromParent();
			} else {
				removeFromBones(bone);
			}
		}
	}
	
	public function removeBoneByName(boneName:String) {
		removeBone(getBone(boneName));
	}
	
	public function advanceTime(passedTime:Float = -1) {
		animation.advanceTime(passedTime);
		update();
	}
	
	public function update() {
		for (i in _rootBones) {
			i.update();
		}
		
		if(bonesIndexChanged) {
			updateBonesZ();
		}
	}
	
	public function updateBonesZ() {
		bones.sort(compareZ);
		for (bone in bones){
			if(bone.isOnStage) {
				bone.displayBridge.addDisplayTo(display);
			}
		}
		bonesIndexChanged = false;
		
		if(hasEventListener(ArmatureEvent.Z_ORDER_UPDATED)) {
			dispatchEvent(new ArmatureEvent(ArmatureEvent.Z_ORDER_UPDATED));
		}
	}
	
	public function addToBones(bone:Bone, ?root:Bool) {
		if(!Lambda.has(bones, bone)) {
			bones.push(bone);
		}
		
		if (root) {
			if (!Lambda.has(_rootBones, bone)) {
				_rootBones.push(bone);
			}
		} else {
			_rootBones.remove(bone);
		}
		
		bone.armature = this;
		bone.displayBridge.addDisplayTo(display, Std.int(bone.global.z));
		for(i in bone.children) {
			addToBones(i);
		}
		bonesIndexChanged = true;
	}
	
	public function removeFromBones(bone:Bone)	{
		bones.remove(bone);
		_rootBones.remove(bone);
		
		bone.armature = null;
		bone.displayBridge.removeDisplayFromParent();
		for(i in bone.children) {
			removeFromBones(i);
		}
		bonesIndexChanged = true;
	}
	
	function compareZ(a, b):Int {
		return Reflect.compare(a.global.z, b.global.z);
	}
	
}