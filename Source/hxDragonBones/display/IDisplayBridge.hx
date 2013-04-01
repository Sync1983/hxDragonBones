package hxDragonBones.display;
import hxDragonBones.objects.Node;
import nme.geom.ColorTransform;
import nme.geom.Matrix;

/**
 * @author SlavaRa
 */

interface IDisplayBridge {
	var display(default, set_display):Dynamic;
	function update(matrix:Matrix, node:Node, colorTransform:ColorTransform, visible:Bool):Void;
	function addDisplay(container:Dynamic, index:Int = -1):Void;
	function removeDisplay():Void;
}