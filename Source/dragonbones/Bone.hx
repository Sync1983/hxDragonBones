package dragonbones;

import dragonbones.animation.Tween;
import dragonbones.display.IDisplayBridge;
import dragonbones.objects.Node;
import dragonbones.utils.IDisposable;
import dragonbones.utils.TransformUtils;
import haxe.Log;
import nme.geom.ColorTransform;
import nme.geom.Matrix;
import nme.geom.Point;

/**
 * @author SlavaRa
 */
class Bone implements IDisposable {

	static var _helpPoint:Point = new Point();
	static var counter:Int = 0;
	
	public function new(bridge:IDisplayBridge) {
		origin = Node.create();
		global = Node.create();
		node = Node.create();
		
		displayBridge = bridge;
		
		children = [];
		
		globalTransformMatrix = new Matrix();
		_displayList = [];
		_armatures = [];
		armaturesIsNotEmpty = false;
		_displayIndex = -1;
		visible = true;
		
		tweenNode = Node.create();
		tweenColorTransform = new ColorTransform();
		
		tween = new Tween(this);
		isOnStage = false;
	}
	
	public var name:String;
	public var userData:Dynamic;
	public var global:HelpNode;
	public var origin:HelpNode;
	public var node:HelpNode;
	public var armature:Armature;
	public var childArmature(get_childArmature, null):Armature;
	public var parent(default, null):Bone;
	public var display(get_display, set_display):Dynamic;
	public var visible:Bool;
	public var tweenNode:HelpNode;
	public var tweenColorTransform:ColorTransform;
	public var displayBridge:IDisplayBridge;
	public var children:Array<Bone>;
	public var tween:Tween;
	public var globalTransformMatrix:Matrix;
	public var isOnStage:Bool;
	public var armaturesIsNotEmpty:Bool;
	
	var _displayList:Array<Dynamic>;
	var _armatures:Array<Armature>;
	var _displayIndex:Int;
	
	function get_childArmature():Armature {
		return _armatures[_displayIndex];
	}
	
	function get_display():Dynamic {
		return displayBridge.display;
	}
	
	function set_display(value:Dynamic):Dynamic {
		if(value == displayBridge.display) {
			return;
		}
		_displayList[_displayIndex] = value;
		if (Std.is(value, Armature)) {
			_armatures[_displayIndex] = value;
			armaturesIsNotEmpty = true;
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
					displayBridge.addDisplayTo(armature.display, Std.int(global[Node.z]));
					armature.bonesIndexChanged = true;
				}
			}
			if(displayIndex != _displayIndex) {
				var length:Int = _displayList.length;
				if((displayIndex >= length) && (length > 0)) {
					displayIndex = length - 1;
				}
				_displayIndex = displayIndex;
				display = _displayList[_displayIndex];
			}
		}
	}
	
	public function dispose() {
		for (i in children) {
			i.dispose();
		}
		_displayList = null;
		_armatures = null;
		children = null;
		armature = null;
		parent = null;
		userData = null;
	}
	
	public function contains(bone:Bone, ?deepLevel:Bool):Bool {
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
				armature.addToBones(child);
			}
		}
	}
	
	public function removeChild(child:Bone) {
		if (Lambda.has(children, child)) {
			if (armature != null) {
				armature.removeFromBones(child);
			}
			child.setParent(null);
			children.remove(child);
		}
	}
	
	public function removeFromParent() {
		if(parent != null) {
			parent.removeChild(this);
		}
	}
	
	public function update() {
		if (!isOnStage) {
			return;
		}
		updateGlobalNode();
		TransformUtils.nodeToMatrix(global, globalTransformMatrix);
		updateChildArmature();
		displayBridge.update(globalTransformMatrix, global, getColorTransform(), visible);
	}
	
	inline function updateGlobalNode() {
		global[Node.x] 		= origin[Node.x] 		+ node[Node.x] 		+ tweenNode[Node.x];
		global[Node.y] 		= origin[Node.y] 		+ node[Node.y] 		+ tweenNode[Node.y];
		global[Node.z] 		= origin[Node.z] 		+ node[Node.z] 		+ tweenNode[Node.z];
		global[Node.skewX] 	= origin[Node.skewX] 	+ node[Node.skewX] 	+ tweenNode[Node.skewX];
		global[Node.skewY] 	= origin[Node.skewY] 	+ node[Node.skewY] 	+ tweenNode[Node.skewY];
		global[Node.scaleX]	= origin[Node.scaleX] 	+ node[Node.scaleX] + tweenNode[Node.scaleX];
		global[Node.scaleY]	= origin[Node.scaleY] 	+ node[Node.scaleY] + tweenNode[Node.scaleY];
		global[Node.pivotX]	= origin[Node.pivotX] 	+ node[Node.pivotX] + tweenNode[Node.pivotX];
		global[Node.pivotY]	= origin[Node.pivotY] 	+ node[Node.pivotY] + tweenNode[Node.pivotY];
		
		if (parent != null) {
			_helpPoint.x 	= global[Node.x];
			_helpPoint.y 	= global[Node.y];
			_helpPoint 		= parent.globalTransformMatrix.transformPoint(_helpPoint);
			global[Node.x] 		= _helpPoint.x;
			global[Node.y] 		= _helpPoint.y;
			global[Node.skewX] 	+= parent.global[Node.skewX];
			global[Node.skewY] 	+= parent.global[Node.skewY];
		}
	}
	
	inline function updateChildArmature() {
		if (armaturesIsNotEmpty) {
			_armatures[_displayIndex].update();
		}
	}
	
	inline function getColorTransform():ColorTransform {
		if (tween.differentColorTransform) {
			if (armature.colorTransform != null) {
				tweenColorTransform.concat(armature.colorTransform);
			}
			return tweenColorTransform;
		} else if (armature.colorTransformChange) {
			armature.colorTransformChange = false;
			return armature.colorTransform;
		} else return null;
	}
	
	inline function setParent(value:Bone) {
		if ((value != null) && value.contains(this, true)) {
			throw "An Bone cannot be added as a child to itself or one of its children (or children's children, etc.)";
		}
		this.parent = value;
	}
	
}