package hxDragonBones;

import haxe.Log;
import hxDragonBones.animation.Animation;
import hxDragonBones.animation.IAnimatable;
import hxDragonBones.animation.IAnimatable;
import hxDragonBones.events.ArmatureEvent;
import nme.display.Sprite;
import nme.events.EventDispatcher;
import nme.events.IEventDispatcher;
import nme.geom.ColorTransform;

/**
 * @author SlavaRa
 */
class Armature extends EventDispatcher, implements IAnimatable{

	public function new(display:Dynamic) {
		super();
		this.display = display;
		bones = [];
		_rootBones = [];
		animation = new Animation(this);
		bonesIndexChanged = false;
	}
	
	public var name:String;
	public var userData:Dynamic;
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
		Lambda.iter(_rootBones, function(b) b.dispose());
		
		userData = null;
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
	
	public function getBones():Array<Bone> 	{
		return bones.slice(0);
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
	
	public function advanceTime(passedTime:Float) {
		animation.advanceTime(passedTime);
		update();
	}
	
	public function updateBonesZ() {
		bones.sort(function(a, b) return Reflect.compare(a.global.z, b.global.z));
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
	
	public function update() {
		Lambda.iter(_rootBones, function(b) b.update());
		
		if(bonesIndexChanged) {
			updateBonesZ();
		}
	}
	
	public function addToBones(bone:Bone, ?root:Bool) {
		if(!Lambda.has(bones, bone)) {
			bones.push(bone);
		}
		
		var index:Int = Lambda.indexOf(_rootBones, bone);
		if(root) {
			if(index == -1) {
				_rootBones.push(bone);
			}
		} else if(index != -1) {
			_rootBones.splice(index, 1);
		}
		
		bone.armature = this;
		bone.displayBridge.addDisplayTo(display, Std.int(bone.global.z));
		Lambda.iter(bone.children, function(b) addToBones(b));
		bonesIndexChanged = true;
	}
	
	public function removeFromBones(bone:Bone)	{
		var index:Int = Lambda.indexOf(bones, bone);
		if(index != -1) {
			bones.splice(index, 1);
		}
		
		index = Lambda.indexOf(_rootBones, bone);
		if(index != -1) {
			_rootBones.splice(index, 1);
		}
		
		bone.armature = null;
		bone.displayBridge.removeDisplayFromParent();
		Lambda.iter(bone.children, function(b) removeFromBones(b));
		bonesIndexChanged = true;
	}
	
}