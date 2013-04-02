package hxDragonBones.textures;
import hxDragonBones.utils.ConstValues;
import nme.display.BitmapData;
import nme.display.MovieClip;
import nme.geom.Rectangle;
import nme.ObjectHash;

/**
 * @author SlavaRa
 */
class NativeTextureAtlas implements ITextureAtlas{

	public function new(texture:Dynamic, textureAtlasXML:Xml, textureScale:Float = 1, isDifferentXML:Bool = false) {
		scale = textureScale;
		_isDifferentXML = isDifferentXML;
		
		_subTextureDataDic = new ObjectHash<String, Rectangle>();
		
		if(Std.is(texture, BitmapData)) {
			bitmapData = cast(texture, BitmapData);
		} else if(Std.is(texture, MovieClip)) {
			movieClip = cast(texture, MovieClip);
			movieClip.stop();
		}
		
		parseData(textureAtlasXML);
	}
	
	public var movieClip(default, null):MovieClip;
	public var bitmapData(default, null):BitmapData;
	public var scale(default, null):Float;
	
	var _width:Int;
	var _height:Int;
	var _subTextureDataDic:ObjectHash<String, Rectangle>;
	var _isDifferentXML:Bool;
	
	//{ region INTERFACE hxDragonBones.textures.ITextureAtlas
	
	public var name(default, null):String;
	
	public function dispose() {
		movieClip = null;
		
		if(bitmapData != null) {
			bitmapData.dispose();
			bitmapData = null;
		}
		
		_subTextureDataDic = new ObjectHash<String, Rectangle>();
	}
	
	public function getRegion(name:String):Rectangle {
		return _subTextureDataDic.get(name);
	}
	
	//} endregion
	
	function parseData(textureAtlasXML:Xml) {
		name 	= textureAtlasXML.firstElement().get(ConstValues.A_NAME);
		_width 	= Std.parseInt(textureAtlasXML.firstElement().get(ConstValues.A_WIDTH));
		_height = Std.parseInt(textureAtlasXML.firstElement().get(ConstValues.A_HEIGHT));
		
		var scale:Float = _isDifferentXML ? scale : 1;
		
		for (subTextureXML in textureAtlasXML.elementsNamed(ConstValues.SUB_TEXTURE)) {
			var subTextureName:String = subTextureXML.get(ConstValues.A_NAME);
			var subTextureData:SubTextureData = new SubTextureData();
			subTextureData.x 		= Std.parseInt(subTextureXML.get(ConstValues.A_X)) 		/ scale;
			subTextureData.y 		= Std.parseInt(subTextureXML.get(ConstValues.A_Y)) 		/ scale;
			subTextureData.width 	= Std.parseInt(subTextureXML.get(ConstValues.A_WIDTH)) 	/ scale;
			subTextureData.height 	= Std.parseInt(subTextureXML.get(ConstValues.A_HEIGHT)) / scale;
			//1.4
			subTextureData.pivotX 	= Std.parseInt(subTextureXML.get(ConstValues.A_PIVOT_X));
			subTextureData.pivotY 	= Std.parseInt(subTextureXML.get(ConstValues.A_PIVOT_Y));
			_subTextureDataDic.set(subTextureName, subTextureData);
		}
	}
	
	function movieClipToBitmapData() {
		if ((bitmapData != null) && (movieClip != null)) {
			movieClip.gotoAndStop(1);
			bitmapData = new BitmapData(_width, _height);
			bitmapData.draw(movieClip);
			movieClip.gotoAndStop(movieClip.totalFrames);
		}
	}
}