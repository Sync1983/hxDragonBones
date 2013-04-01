package hxDragonBones;

import hxDragonBones.animation.Animation;
import hxDragonBones.animation.IAnimatable;
import hxDragonBones.animation.IAnimatable;
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
		boneDepthList = [];
		_rootBoneList = [];
		animation = new Animation(this);
		bonesIndexChanged = false;
	}
	
	public var name:String;
	public var userData:Dynamic;
	public var colorTransform(default, set_colorTransform):ColorTransform;
	public var display(default, null):Dynamic;
	public var animation(default, null):Animation;
	public var bonesIndexChanged:Bool;
	public var boneDepthList:Array<Bone>;
	public var colorTransformChange:Bool;
	
	function set_colorTransfrom(value:ColorTransform):ColorTransform {
		colorTransform = value;
		colorTransformChange = true;
		return value;
	}
	
	var _rootBoneList:Array<Bone>;
	
	public function dispose() {
		for (bone in _rootBoneList) {
			bone.dispose();
		}
		
		boneDepthList = [];
		_rootBoneList = [];
		
		animation.dispose();
		animation = null;
	}
	
	public function getBone(name:String):Bone {
		if(name != null) {
			for(bone in boneDepthList) {
				if(bone.name == name) {
					return bone;
				}
			}
		}
		return null;
	}
	
	public function getBoneByDisplay(display:Dynamic):Bone {
		if(display != null) {
			for (bone in boneDepthList) {
				if(bone.display == display) {
					return bone;
				}
			}
		}
		return null;
	}
	
	public function getBones():Array<Bone> 	{
		return boneDepthList.concat();
	}
	
	public function addBone(bone:Bone, parentName:String = null) {
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
		boneDepthList.sort(sortBoneZIndex);
		for (bone in boneDepthList){
			if(bone._isOnStage) {
				bone._displayBridge.addDisplay(_display);
			}
		}
		bonesIndexChanged = false;
		
		if(hasEventListener(ArmatureEvent.Z_ORDER_UPDATED)) {
			dispatchEvent(new ArmatureEvent(ArmatureEvent.Z_ORDER_UPDATED));
		}
	}
	
	function update() {
		for (bone in _rootBoneList) {
			bone.update();
		}
		
		if(bonesIndexChanged) {
			updateBonesZ();
		}
	}
	
	function addToBones(bone:Bone, root:Bool = false) {
		var boneIndex:Int = Lambda.indexOf(boneDepthList, bone);
		if(boneIndex == -1) {
			boneDepthList.push(bone);
		}
		
		boneIndex = Lambda.indexOf(_rootBoneList, bone);
		if(root) {
			if(boneIndex == -1) {
				_rootBoneList.push(bone);
			}
		} else if(boneIndex != -1) {
			_rootBoneList.splice(boneIndex, 1);
		}
		
		bone.armature = this;
		bone.displayBridge.addDisplay(display, bone.global.z);
		for(child in bone.children) {
			addToBones(child);
		}
		bonesIndexChanged = true;
	}
	
	function removeFromBones(bone:Bone)	{
		var boneIndex:Int = Lambda.indexOf(boneDepthList, bone);
		if(boneIndex >= 0) {
			boneDepthList.splice(boneIndex, 1);
		}
		
		boneIndex = Lambda.indexOf(_rootBoneList, bone);
		if(boneIndex != -1) {
			_rootBoneList.splice(boneIndex, 1);
		}
		
		bone.armature = null;
		bone.displayBridge.removeDisplay();
		for(child in bone.children) {
			removeFromBones(child);
		}
		bonesIndexChanged = true;
	}
	
	function sortBoneZIndex(bone1:Bone, bone2:Bone):Int {
		return (bone1.global.z >= bone2.global.z) ? 1: -1;
	}

	
}