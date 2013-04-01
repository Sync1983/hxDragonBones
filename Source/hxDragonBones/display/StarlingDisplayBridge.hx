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
		
		if(display){
			var parent:DisplayObjectContainer = display.parent;
			if(parent != null) {
				var index:Int = parent.getChildIndex(display);
			}
			removeDisplay();
		}
		display = value;
		addDisplay(parent, index);
	}
	
	public function update(matrix:Matrix, node:Node, colorTransform:ColorTransform, visible:Bool) {
		var pivotX:Float = node.pivotX + _display.pivotX;
		var pivotY:Float = node.pivotY + _display.pivotY;
		matrix.tx -= matrix.a * pivotX + matrix.c * pivotY;
		matrix.ty -= matrix.b * pivotX + matrix.d * pivotY;
		
		display.transformationMatrix.copyFrom(matrix);
		
		if ((colorTransform != null) && Std.is(display, Quad)) {
			var quad:Quad = cast(display, Quad);
			quad.alpha = colorTransform.alphaMultiplier;
			quad.color = (cast(colorTransform.redMultiplier * 0xff)<<16, UInt) + (cast(colorTransform.greenMultiplier * 0xff)<<8, UInt) + cast(colorTransform.blueMultiplier * 0xff, UInt);
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