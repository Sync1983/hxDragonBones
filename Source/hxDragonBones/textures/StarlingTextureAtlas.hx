package hxDragonBones.textures;

import hxDragonBones.utils.ConstValues;
import nme.display.BitmapData;
import nme.geom.Rectangle;
import nme.ObjectHash;
import starling.textures.Texture;
import starling.textures.TextureAtlas;

/**
 * ...
 * @author SlavaRa
 */
class StarlingTextureAtlas extends TextureAtlas, implements ITextureAtlas{

	public function new(texture:Texture, textureAtlasXML:Xml = null, isDifferentXML:Bool = false) {
		if(texture != null) {
			_scale = texture.scale;
			_isDifferentXML = isDifferentXML;
		}
		super(texture, textureAtlasXML);
		if(textureAtlasXML != null) {
			name = textureAtlasXML.get(ConstValues.A_NAME);
		}
		_subTextureDic = new ObjectHash<String, Texture>();
	}
	
	var _bitmapData:BitmapData;
	var _subTextureDic:ObjectHash<String, Texture>;
	var _isDifferentXML:Bool;
	var _scale:Float;
	
	//{ region INTERFACE hxDragonBones.textures.ITextureAtlas
	
	public var name(default, null):String;
	
	public override function dispose() {
		super.dispose();
		
		for (subTexture in _subTextureDic) {
			subTexture.dispose();
		}
		
		_subTextureDic = new ObjectHash<String, Texture>();
		
		if(_bitmapData != null) {
			_bitmapData.dispose();
			_bitmapData = null;
		}
	}
	
	public function getRegion(name:String):Rectangle {
		
	}
	
	//}
	
	public override function getTexture(name:String):Texture {
		var texture:Texture = _subTextureDic.get(name);
		if(texture == null) {
			texture = super.getTexture(name);
			if(texture != null) {
				_subTextureDicset(name, texture);
			}
		}
		return texture;
	}
	
	function parseAtlasXml(atlasXml:Xml) {
		var scale:Float = _isDifferentXML ? _scale : 1;
		
		for (subTexture in atlasXml.SubTexture) {
			var name:String = subTexture.get("name");
			var x:Float = cast(subTexture.get("x"), Float) / scale;
			var y:Float = cast(subTexture.get("y"), Float) / scale;
			var width:Float = cast(subTexture.get("width"), Float) / scale;
			var height:Float = cast(subTexture.get("height"), Float) / scale;
			var frameX:Float = cast(subTexture.get("frameX"), Float) / scale;
			var frameY:Float = cast(subTexture.get("frameY"), Float) / scale;
			var frameWidth:Float = cast(subTexture.get("frameWidth"), Float) / scale;
			var frameHeight:Float = cast(subTexture.get("frameHeight"), Float) / scale;
			
			//1.4
			var region:SubTextureData = new SubTextureData(x, y, width, height);
			region.pivotX = cast(subTexture.get(ConstValues.A_PIVOT_X), Int);
			region.pivotY = cast(subTexture.get(ConstValues.A_PIVOT_Y), Int);
			
			var frame:Rectangle = null;
			if((frameWidth > 0) && (frameHeight > 0)) {
				frame = new Rectangle(frameX, frameY, frameWidth, frameHeight);
			}
			
			addRegion(name, region, frame);
		}
	}
	
}