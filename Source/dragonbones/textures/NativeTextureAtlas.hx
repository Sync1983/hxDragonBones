package dragonbones.textures;
import haxe.Log;
import dragonbones.utils.ConstValues;
import dragonbones.utils.IDisposable;
import nme.display.BitmapData;
import nme.display.MovieClip;
import nme.geom.Rectangle;
import nme.ObjectHash;

/**
 * @author SlavaRa
 */
class NativeTextureAtlas implements ITextureAtlas {

	public function new(texture:Dynamic, texAtlasXml:Xml, scale:Float = 1, ?isDifferentXML:Bool) {
		this.scale = scale;
		_isDifferentXML = isDifferentXML;
		
		_name2SubTexData = new Hash<Rectangle>();
		
		if (Std.is(texture, BitmapData)) {
			bitmapData = cast(texture, BitmapData);
		} else if(Std.is(texture, MovieClip)) {
			movieClip = cast(texture, MovieClip);
			movieClip.stop();
		}
		
		parseData(texAtlasXml);
	}
	
	public var movieClip(default, null):MovieClip;
	public var bitmapData(default, null):BitmapData;
	public var scale(default, null):Float;
	
	var _name2SubTexData:Hash<Rectangle>;
	var _isDifferentXML:Bool;
	
	//{ region INTERFACE dragonbones.textures.ITextureAtlas
	
	public var name(default, null):String;
	
	public function dispose() {
		movieClip = null;
		
		if(bitmapData != null) {
			bitmapData.dispose();
			bitmapData = null;
		}
		
		_name2SubTexData = null;
	}
	
	public function getRegion(name:String):Rectangle {
		return _name2SubTexData.get(name);
	}
	
	//} endregion
	
	function parseData(texAtlasXml:Xml) {
		name = texAtlasXml.firstElement().get(ConstValues.A_NAME);
		
		var scale:Float = _isDifferentXML ? scale : 1;
		
		for (subTexXml in texAtlasXml.firstElement().elementsNamed(ConstValues.SUB_TEXTURE)) {
			var subTexName:String 			= subTexXml.get(ConstValues.A_NAME);
			var subTexData:SubTextureData 	= new SubTextureData();
			
			subTexData.x 		= Std.parseInt(subTexXml.get(ConstValues.A_X)) 		/ scale;
			subTexData.y 		= Std.parseInt(subTexXml.get(ConstValues.A_Y)) 		/ scale;
			subTexData.width 	= Std.parseInt(subTexXml.get(ConstValues.A_WIDTH)) 	/ scale;
			subTexData.height 	= Std.parseInt(subTexXml.get(ConstValues.A_HEIGHT)) / scale;
			
			//1.4
			subTexData.pivotX 	= Std.parseInt(subTexXml.get(ConstValues.A_PIVOT_X));
			subTexData.pivotY 	= Std.parseInt(subTexXml.get(ConstValues.A_PIVOT_Y));
			
			_name2SubTexData.set(subTexName, subTexData);
		}
	}
	
}