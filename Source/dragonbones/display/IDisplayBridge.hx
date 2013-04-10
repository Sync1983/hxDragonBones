package dragonbones.display;
import dragonbones.objects.Node;
import nme.geom.ColorTransform;
import nme.geom.Matrix;

/**
 * @author SlavaRa
 */

interface IDisplayBridge {
	var display(default, set_display):Dynamic;
	function update(matrix:Matrix, node:Node, ?colorTransform:ColorTransform, visible:Bool):Void;
	function addDisplayTo(container:Dynamic, index:Int = -1):Void;
	function removeDisplayFromParent():Void;
}