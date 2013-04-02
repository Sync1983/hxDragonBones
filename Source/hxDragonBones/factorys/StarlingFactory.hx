package hxDragonBones.factorys;
import flash.xml.XML;
import hxDragonBones.Armature;
import hxDragonBones.Bone;
import hxDragonBones.display.StarlingDisplayBridge;
import hxDragonBones.textures.StarlingTextureAtlas;
import hxDragonBones.textures.SubTextureData;
import hxDragonBones.utils.ConstValues;
import nme.display.BitmapData;
import nme.display.MovieClip;
import nme.geom.Rectangle;
import starling.core.Starling;
import starling.display.Image;
import starling.display.Sprite;
import starling.textures.SubTexture;
import starling.textures.Texture;
import starling.textures.TextureAtlas;

/**
 * @author SlavaRa
 */
class StarlingFactory extends BaseFactory{

	public function new() {
		super();
		generateMipMaps = true;
		optimizeForRenderToTexture = true;
		scaleForTexture = 1;
	}
	
	public var generateMipMaps:Bool;
	public var optimizeForRenderToTexture:Bool;
	public var scaleForTexture:Float;
	
	override function generateArmature():Armature {
		return new Armature(new Sprite());
	}
	
	override function generateBone():Bone {
		return new Bone(new StarlingDisplayBridge());
	}
	
	override function generateTextureDisplay(textureAtlas:Dynamic, fullName:String, pivotX:Int, pivotY:Int):Dynamic {
		//1.4
		if(Std.is(textureAtlas, StarlingTextureAtlas)) {
			var starlingTextureAtlas:StarlingTextureAtlas = cast(textureAtlas, StarlingTextureAtlas);
			var rectangle:Rectangle = starlingTextureAtlas.getRegion(fullName);
			if(Std.is(rectangle, SubTextureData)){
				var subTextureData:SubTextureData = cast(rectangle, SubTextureData);
				pivotX = (pivotX != 0) ? pivotX : subTextureData.pivotX;
				pivotY = (pivotY != 0) ? pivotY : subTextureData.pivotY;
			}
		}
		
		var texture:Texture = cast(textureAtlas, TextureAtlas).getTexture(fullName);
		if(Std.is(texture, SubTexture)) {
			var image:Image = new Image(cast(texture, SubTexture));
			image.pivotX = pivotX;
			image.pivotY = pivotY;
			return image;
		}
		
		return null;
	}
	
	override function generateTextureAtlas(content:Dynamic, textureAtlasXML:Dynamic):Dynamic {
		var texAtlasXML:XML = cast(textureAtlasXML, XML);
		var texture:Texture = null;
		var bitmapData:BitmapData = null;
		if(Std.is(content, BitmapData)) {
			bitmapData = cast(content, BitmapData);
			texture = Texture.fromBitmapData(bitmapData, generateMipMaps, optimizeForRenderToTexture, scaleForTexture);
		} else if(Std.is(content, MovieClip)) {
			var width:Int = Std.parseInt(texAtlasXML.attribute(ConstValues.A_WIDTH).toString()) * cast(scaleForTexture, Int);
			var height:Int = Std.parseInt(texAtlasXML.attribute(ConstValues.A_HEIGHT).toString()) * cast(scaleForTexture, Int);
			
			_helpMatrix.a = 1;
			_helpMatrix.b = 0;
			_helpMatrix.c = 0;
			_helpMatrix.d = 1;
			_helpMatrix.scale(scaleForTexture, scaleForTexture);
			_helpMatrix.tx = 0;
			_helpMatrix.ty = 0;
			
			var movieClip:MovieClip = cast(content, MovieClip);
			movieClip.gotoAndStop(1);
			bitmapData = new BitmapData(width, height, true, 0xFF00FF);
			bitmapData.draw(movieClip, _helpMatrix);
			movieClip.gotoAndStop(movieClip.totalFrames);
			texture = Texture.fromBitmapData(bitmapData, generateMipMaps, optimizeForRenderToTexture, scaleForTexture);
		} else {
			//
		}
		
		var textureAtlas:StarlingTextureAtlas = new StarlingTextureAtlas(texture, texAtlasXML);
		
		if(Starling.handleLostContext) {
			textureAtlas.bitmapData = bitmapData;
		} else {
			bitmapData.dispose();
		}
		return textureAtlas;
	}
	
}