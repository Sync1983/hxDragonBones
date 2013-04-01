package hxDragonBones.textures;
import nme.geom.Rectangle;

/**
 * @author SlavaRa
 */

interface ITextureAtlas {
	var name(default, null):String;
	function dispose():Void;
	function getRegion(name:String):Rectangle;
}