package hxDragonBones;

import hxDragonBones.animation.Tween;
import hxDragonBones.display.IDisplayBridge;
import hxDragonBones.objects.Node;
import nme.events.EventDispatcher;
import nme.events.IEventDispatcher;
import nme.geom.ColorTransform;
import nme.geom.Matrix;
import nme.geom.Point;

/**
 * @author SlavaRa
 */
class Bone extends EventDispatcher{

	static var _helpPoint:Point = new Point();
	
	public function new(displayBridge:IDisplayBridge) {
		super();
		
		origin = new Node();
		global = new Node();
		node = new Node();
		
		this.displayBridge = displayBridge;
		
		children = [];
		
		globalTransformMatrix = new Matrix();
		_displayList = [];
		_displayIndex = -1;
		visible = true;
		
		tweenNode = new Node();
		tweenColorTransform = new ColorTransform();
		
		tween = new Tween(this);
		isOnStage = false;
	}
	
	public var name:String;
	public var userData:Dynamic;
	public var global:Node;
	public var origin:Node;
	public var node:Node;
	public var armature:Armature;
	public var childArmature(get_childArmature, null):Armature;
	public var parent(default, null):Bone;
	public var display(get_display, set_display):Dynamic;
	public var visible:Bool;
	public var tweenNode:Node;
	public var tweenColorTransform:ColorTransform;
	public var displayBridge:IDisplayBridge;
	public var children:Array<Bone>;
	public var tween:Tween;
	public var globalTransformMatrix:Matrix;
	public var isOnStage:Bool;
	
	var _displayList:Array<Dynamic>;
	var _displayIndex:Int;
	
	function get_childArmature():Armature {
		var d:Dynamic = _displayList[_displayIndex];
		return Std.is(d, Armature) ? cast(d, Armature) : null;
	}
	
	function get_display():Dynamic {
		return displayBridge.display;
	}
	
	function set_display(value:Dynamic):Dynamic {
		if(displayBridge.display == value) {
			return;
		}
		_displayList[_displayIndex] = value;
		if(Std.is(value, Armature)) {
			value = cast(value, Armature).display;
		}
		displayBridge.display = value;
		return value;
	}
	
	public function changeDisplay(displayIndex:Int) {
		if(displayIndex < 0) {
			if(isOnStage) {
				isOnStage = false;
				displayBridge.removeDisplayFromParent();
			}
		} else {
			if(!isOnStage) {
				isOnStage = true;
				if(armature != null) {
					displayBridge.addDisplayTo(armature.display, cast(global.z, Int));
					armature.bonesIndexChanged = true;
				}
			}
			if(_displayIndex != displayIndex) {
				var length:Int = _displayList.length;
				if((displayIndex >= length) && (length > 0)) {
					displayIndex = length - 1;
				}
				_displayIndex = displayIndex;
				display = _displayList[_displayIndex];
			}
		}
	}
	
	public function changeDisplayList(displayList:Array<Dynamic>) {
		var length:Int = cast(Math.min(_displayList.length, displayList.length), Int);
		for (i in 0 ... length) {
			changeDisplay(i);
			display = displayList[i];
		}
		changeDisplay(_displayIndex);
	}
	
	public function dispose() {
		for (child in children) {
			cast(child, Bone).dispose();
		}
		
		_displayList = [];
		children = [];
		armature = null;
		parent = null;
		userData = null;
	}
	
	public function contains(bone:Bone, deepLevel:Bool = false):Bool {
		if(deepLevel) {
			var ancestor:Bone = this;
			while ((ancestor != bone) && (ancestor != null)) {
				ancestor = ancestor.parent;
			}
			if (ancestor == bone) {
				return true;
			}
			return false;
		}
		return bone.parent == this;
	}
	
	public function addChild(child:Bone) {
		if (!Lambda.has(children, child)) {
			child.removeFromParent();
			
			children.push(child);
			child.setParent(this);
			
			if (armature != null) {
				armature.addDisplayToBones(child);
			}
		}
	}
	
	public function removeChild(child:Bone) {
		var index:Int = Lambda.indexOf(children, child);
		if (index != -1) {
			if (armature != null) {
				armature.removeFromBones(child);
			}
			child.setParent(null);
			children.splice(index, 1);
		}
	}
	
	public function removeFromParent() {
		if(parent != null) {
			parent.removeChild(this);
		}
	}
	
	public function update() {
		Log.trace("update");
		if ((children.length > 0) || isOnStage) {
			global.x 		= origin.x + node.x + tweenNode.x;
			global.y 		= origin.y + node.y + tweenNode.y;
			global.skewX 	= origin.skewX + node.skewX + tweenNode.skewX;
			global.skewY 	= origin.skewY + node.skewY + tweenNode.skewY;
			global.scaleX 	= origin.scaleX + node.scaleX + tweenNode.scaleX;
			global.scaleY 	= origin.scaleY + node.scaleY + tweenNode.scaleY;
			global.pivotX 	= origin.pivotX + node.pivotX + tweenNode.pivotX;
			global.pivotY 	= origin.pivotY + node.pivotY + tweenNode.pivotY;
			global.z 		= origin.z + node.z + tweenNode.z;
			
			if(parent != null) {
				_helpPoint.x 	= global.x;
				_helpPoint.y 	= global.y;
				_helpPoint 		= parent.globalTransformMatrix.transformPoint(_helpPoint);
				global.x 		= _helpPoint.x;
				global.y 		= _helpPoint.y;
				global.skewX 	+= parent.global.skewX;
				global.skewY 	+= parent.global.skewY;
			}
			
			globalTransformMatrix.a 	= global.scaleX * Math.cos(global.skewY);
			globalTransformMatrix.b 	= global.scaleX * Math.sin(global.skewY);
			globalTransformMatrix.c 	= -global.scaleY * Math.sin(global.skewX);
			globalTransformMatrix.d 	= global.scaleY * Math.cos(global.skewX);
			globalTransformMatrix.tx 	= global.x;
			globalTransformMatrix.ty 	= global.y;
			
			if (children.length > 0) {
				for (child in children) {
					cast(child, Bone).update();
				}
			}
			
			var childArmature:Armature = this.childArmature;
			if(childArmature != null) {
				childArmature.update();
			}
			
			var currentDisplay:Dynamic = displayBridge.display;
			
			if(isOnStage && (currentDisplay != null)) {
				if(tween.differentColorTransform) {
					if(armature.colorTransform != null){
						tweenColorTransform.concat(armature.colorTransform);
					}
					displayBridge.update(globalTransformMatrix, global, tweenColorTransform, visible);
				} else if(armature.colorTransformChange) {
					armature.colorTransformChange = false;
					displayBridge.update(globalTransformMatrix, global, armature.colorTransform, visible);
				}
			}
		}
	}
	
	function setParent(parent:Bone) {
		if ((parent != null) && parent.contains(this, true)) {
			throw "An Bone cannot be added as a child to itself or one of its children (or children's children, etc.)";
		}
		this.parent = parent;
	}
}