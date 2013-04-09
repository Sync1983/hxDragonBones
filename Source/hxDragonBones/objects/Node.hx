package hxDragonBones.objects;
import haxe.Log;

/**
 * @author SlavaRa
 */
class Node{

	public function new() {
		setValues();
	}
	
	public var x:Float;
	public var y:Float;
	public var z:Float;
	public var scaleX:Float;
	public var scaleY:Float;
	public var skewX:Float;
	public var skewY:Float;
	public var pivotX:Float;
	public var pivotY:Float;
	public var rotation(get_rotation, set_rotation):Float;
	
	function get_rotation():Float {
		return skewX;
	}
	
	function set_rotation(value:Float):Float {
		skewX = value;
		skewY = value;
		return value;
	}
	
	public function setValues(x:Float = 0, y:Float = 0, skewX:Float = 0, skewY:Float = 0, scaleX:Float = 0, scaleY:Float = 0, pivotX:Float = 0, pivotY:Float = 0, z:Int = 0) {
		this.x 		= !Math.isNaN(x) ? x : 0;
		this.y 		= !Math.isNaN(y) ? y : 0;
		this.z 		= z;
		this.skewX 	= !Math.isNaN(skewX) ? skewX : 0;
		this.skewY 	= !Math.isNaN(skewY) ? skewY : 0;
		this.scaleX = !Math.isNaN(scaleX) ? scaleX : 0;
		this.scaleY = !Math.isNaN(scaleY) ? scaleY : 0;
		this.pivotX = !Math.isNaN(pivotX) ? pivotX : 0;
		this.pivotY = !Math.isNaN(pivotY) ? pivotY : 0;
	}
	
	public function copyFrom(node:Node) {
		x 		= node.x;
		y 		= node.y;
		z 		= node.z;
		scaleX 	= node.scaleX;
		scaleY 	= node.scaleY;
		skewX 	= node.skewX;
		skewY 	= node.skewY;
		pivotX 	= node.pivotX;
		pivotY 	= node.pivotY;
	}
}