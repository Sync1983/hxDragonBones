package hxDragonBones.display;
import haxe.Log;
import nme.display.DisplayObjectContainer;
import nme.geom.ColorTransform;
import hxDragonBones.objects.Node;
import nme.geom.Matrix;

/**
 * @author SlavaRa
 */
class NativeDisplayBridge implements IDisplayBridge{

	public function new() {
		
	}
	
	//{ region INTERFACE hxDragonBones.display.IDisplayBridge
	
	public var display(default, set_display):Dynamic;
	
	function set_display(value:Dynamic):Dynamic {
		if (value == display) {
			return value;
		}
		var index:Int = 0;
		var parent:DisplayObjectContainer = null;
		if (display != null) {
			parent = display.parent;
			if (parent != null) {
				index = parent.getChildIndex(display);
			}
			removeDisplayFromParent();
		}
		display = value;
		addDisplayTo(parent, index);
		return value;
	}
	
	public function update(matrix:Matrix, node:Node, ?colorTransform:ColorTransform, visible:Bool) {
		var pivotX:Float = node.pivotX;
		var pivotY:Float = node.pivotY;
		matrix.tx -= matrix.a * pivotX + matrix.c * pivotY;
		matrix.ty -= matrix.b * pivotX + matrix.d * pivotY;
		
		display.transform.matrix = matrix;
		if(colorTransform != null) {
			display.transform.colorTransform = colorTransform;
		}
		display.visible = visible;
	}
	
	public function addDisplayTo(container:Dynamic, index:Int = -1) {
		if((container != null) && (display != null)) {
			if(index < 0) {
				container.addChild(display);
			} else {
				container.addChildAt(display, Math.min(index, container.numChildren));
			}
		}
	}
	
	public function removeDisplayFromParent() {
		if((display != null) && (display.parent != null)) {
			display.parent.removeChild(display);
		}
	}
	
	//} endregion
	
}