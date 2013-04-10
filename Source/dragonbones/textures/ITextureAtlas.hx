package dragonbones.textures;
import dragonbones.utils.IDisposable;
import nme.geom.Rectangle;

/**
 * @author SlavaRa
 */

interface ITextureAtlas implements IDisposable {
	var name(default, null):String;
	function getRegion(name:String):Rectangle;
}