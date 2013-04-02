package hxDragonBones.display;
import nme.geom.ColorTransform;
import hxDragonBones.objects.Node;
import nme.geom.Matrix;

import starling.display.DisplayObject;
import starling.display.DisplayObjectContainer;
import starling.display.Quad;

/**
 * @author SlavaRa
 */
class StarlingDisplayBridge implements IDisplayBridge{

	public function new() {
		
	}
	
	//{ region INTERFACE hxDragonBones.display.IDisplayBridge
	
	public var display(default, set_display):Dynamic;
	
	function set_display(value:Dynamic) {
		if(value == display){
			return value;
		}
		
		var parent:DisplayObjectContainer = null;
		var index:Int = 0;
		
		if(display){
			parent = display.parent;
			if(parent != null) {
				index = parent.getChildIndex(display);
			}
			removeDisplay();
		}
		display = value;
		addDisplay(parent, index);
		return value;
	}
	
	public function update(matrix:Matrix, node:Node, colorTransform:ColorTransform, visible:Bool) {
		var pivotX:Float = node.pivotX + display.pivotX;
		var pivotY:Float = node.pivotY + display.pivotY;
		matrix.tx -= matrix.a * pivotX + matrix.c * pivotY;
		matrix.ty -= matrix.b * pivotX + matrix.d * pivotY;
		
		display.transformationMatrix.copyFrom(matrix);
		
		if ((colorTransform != null) && Std.is(display, Quad)) {
			var quad:Quad = cast(display, Quad);
			quad.alpha = colorTransform.alphaMultiplier;
			var r:UInt = cast((colorTransform.redMultiplier * 0xff), Int) << 16;
			var g:UInt = cast((colorTransform.greenMultiplier * 0xff), Int) << 8;
			var b:UInt = cast(colorTransform.blueMultiplier, Int) * 0xff;
			quad.color = r + g + b;
		}
		
		display.visible = visible;
	}
	
	public function addDisplay(container:Dynamic, index:Int = -1) {
		if((container != null) && (display != null)) {
			if(index < 0) {
				container.addChild(display);
			} else {
				container.addChildAt(display, Math.min(index, container.numChildren));
			}
		}
	}
	
	public function removeDisplay() {
		if((display != null) && (display.parent != null)) {
			display.parent.removeChild(display);
		}
	}
	
	//} endregion
}