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

	private static var _helpPoint:Point = new Point();
	
	public function new(displayBridge:IDisplayBridge) {
		super();
		
		origin = new Node();
		global = new Node();
		node = new Node();
		
		_displayBridge = displayBridge;
		
		_children = [];
		
		_globalTransformMatrix = new Matrix();
		_displayList = [];
		_displayIndex = -1;
		visible = true;
		
		tweenNode = new Node();
		tweenColorTransform = new ColorTransform();
		
		_tween = new Tween(this);
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
	
	var _tween:Tween;
	var _children:Array<Bone>;
	var _displayBridge:IDisplayBridge;
	var _isOnStage:Bool;
	var _globalTransformMatrix:Matrix;
	var _displayList:Array<Dynamic>;
	var _displayIndex:Int;
	
	function get_childArmature():Armature {
		return cast(_displayList[_displayIndex], Armature);
	}
	
	function get_display():Dynamic {
		return _displayBridge.display;
	}
	
	function set_display(value:Dynamic):Dynamic {
		if(_displayBridge.display == value) {
			return;
		}
		_displayList[_displayIndex] = value;
		if(Std.is(value, Armature)) {
			value = cast(value, Armature).display;
		}
		_displayBridge.display = value;
		return value;
	}
	
	function changeDisplay(displayIndex:Int) {
		if(displayIndex < 0) {
			if(_isOnStage) {
				_isOnStage = false;
				_displayBridge.removeDisplay();
			}
		} else {
			if(!_isOnStage) {
				_isOnStage = true;
				if(armature != null) {
					_displayBridge.addDisplay(armature.display, global.z);
					armature._bonesIndexChanged = true;
				}
			}
			if(_displayIndex != displayIndex) {
				var length:UInt = _displayList.length;
				if((displayIndex >= length) && (length > 0)) {
					displayIndex = length - 1;
				}
				_displayIndex = displayIndex;
				display = _displayList[_displayIndex];
			}
		}
	}
	
	public function changeDisplayList(displayList:Array<Dynamic>) {
		var indexBackup:Int = _displayIndex;
		
		var length:UInt = Math.min(_displayList.length, displayList.length);
		for (i in 0 ... length) {
			changeDisplay(i);
			display = displayList[i];
		}
		
		changeDisplay(indexBackup);
	}
	
	public function dispose() {
		for (child in _children) {
			cast(child, Bone).dispose();
		}
		
		_displayList = [];
		_children = [];
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
		if (!Lambda.has(_children, child)) {
			child.removeFromParent();
			
			_children.push(child);
			child.setParent(this);
			
			if (armature) {
				armature.addToBones(child);
			}
		}
	}
	
	public function removeChild(child:Bone) {
		var index:Int = Lambda.indexOf(_children, child);
		if (index != -1) {
			if (armature != null) {
				armature.removeFromBones(child);
			}
			child.setParent(null);
			_children.splice(index, 1);
		}
	}
	
	public function removeFromParent() {
		if(parent != null) {
			parent.removeChild(this);
		}
	}
	
	function update() {
		if ((_children.length > 0) || _isOnStage)
		{
			global.x = origin.x + node.x + tweenNode.x;
			global.y = origin.y + node.y + tweenNode.y;
			global.skewX = origin.skewX + node.skewX + tweenNode.skewX;
			global.skewY = origin.skewY + node.skewY + tweenNode.skewY;
			global.scaleX = origin.scaleX + node.scaleX + tweenNode.scaleX;
			global.scaleY = origin.scaleY + node.scaleY + tweenNode.scaleY;
			global.pivotX = origin.pivotX + node.pivotX + tweenNode.pivotX;
			global.pivotY = origin.pivotY + node.pivotY + tweenNode.pivotY;
			global.z = origin.z + node.z + tweenNode.z;
			
			if(_parent != null) {
				_helpPoint.x = global.x;
				_helpPoint.y = global.y;
				_helpPoint = _parent._globalTransformMatrix.transformPoint(_helpPoint);
				global.x = _helpPoint.x;
				global.y = _helpPoint.y;
				global.skewX += _parent.global.skewX;
				global.skewY += _parent.global.skewY;
			}
			
			_globalTransformMatrix.a = global.scaleX * Math.cos(global.skewY);
			_globalTransformMatrix.b = global.scaleX * Math.sin(global.skewY);
			_globalTransformMatrix.c = -global.scaleY * Math.sin(global.skewX);
			_globalTransformMatrix.d = global.scaleY * Math.cos(global.skewX);
			_globalTransformMatrix.tx = global.x;
			_globalTransformMatrix.ty = global.y;
			
			if (_children.length > 0) {
				for (child in _children) {
					cast(child, Bone).update();
				}
			}
			
			var childArmature:Armature = this.childArmature;
			if(childArmature) {
				childArmature.update();
			}
			
			var currentDisplay:Dynamic = _displayBridge.display;
			
			if(_isOnStage && (currentDisplay != null)) {
				var colorTransform:ColorTransform;
				if(_tween._differentColorTransform != null) {
					if(armature.colorTransform != null){
						tweenColorTransform.concat(armature.colorTransform);
					}
					colorTransform = tweenColorTransform;
				} else if(armature._colorTransformChange != null) {
					colorTransform = armature.colorTransform;
					armature._colorTransformChange = false;
				}
				
				_displayBridge.update(_globalTransformMatrix, global, colorTransform, visible);
			}
		}
	}
	
	function setParent(parent:Bone) {
		if ((parent != null) && parent.contains(this, true)) {
			throw "An Bone cannot be added as a child to itself or one of its children (or children's children, etc.)";
		}
		_parent = parent;
	}
}