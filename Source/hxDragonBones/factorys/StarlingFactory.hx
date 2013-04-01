package hxDragonBones.factorys;
import hxDragonBones.Armature;
import hxDragonBones.Bone;
import hxDragonBones.textures.StarlingTextureAtlas;
import hxDragonBones.textures.SubTextureData;
import nme.display.BitmapData;
import nme.display.MovieClip;
import starling.core.Starling;
import starling.display.Image;
import starling.display.Sprite;
import starling.textures.SubTexture;
import starling.textures.Texture;

/**
 * ...
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
		var starlingTextureAtlas:StarlingTextureAtlas = cast(textureAtlas, StarlingTextureAtlas);
		if(starlingTextureAtlas != null)
		{
			//1.4
			var subTextureData:SubTextureData = cast(starlingTextureAtlas.getRegion(fullName), SubTextureData);
			if(subTextureData != null) {
				pivotX = (pivotX != 0) ? pivotX : subTextureData.pivotX;
				pivotY = (pivotY != 0) ? pivotY : subTextureData.pivotY;
			}
		}
		
		var subTexture:SubTexture = cast(cast(textureAtlas, TextureAtlas).getTexture(fullName), SubTexture);
		if(subTexture != null) {
			var image:Image = new Image(subTexture);
			image.pivotX = pivotX;
			image.pivotY = pivotY;
			return image;
		}
		return null;
	}
	
	override function generateTextureAtlas(content:Dynamic, textureAtlasXML:Xml):Dynamic {
		var texture:Texture;
		var bitmapData:BitmapData;
		if(Std.is(content, BitmapData)) {
			bitmapData = cast(content, BitmapData);
			texture = Texture.fromBitmapData(bitmapData, generateMipMaps, optimizeForRenderToTexture, scaleForTexture);
		} else if(Std.is(content, MovieClip)) {
			var width:Int = cast(textureAtlasXML.get(ConstValues.A_WIDTH), Int) * scaleForTexture;
			var height:Int = cast(textureAtlasXML.get(ConstValues.A_HEIGHT), Int) * scaleForTexture;
			
			_helpMatirx.a = 1;
			_helpMatirx.b = 0;
			_helpMatirx.c = 0;
			_helpMatirx.d = 1;
			_helpMatirx.scale(scaleForTexture, scaleForTexture);
			_helpMatirx.tx = 0;
			_helpMatirx.ty = 0;
			
			var movieClip:MovieClip = cast(content, MovieClip);
			movieClip.gotoAndStop(1);
			bitmapData= new BitmapData(width, height, true, 0xFF00FF);
			bitmapData.draw(movieClip, _helpMatirx);
			movieClip.gotoAndStop(movieClip.totalFrames);
			texture = Texture.fromBitmapData(bitmapData, generateMipMaps, optimizeForRenderToTexture, scaleForTexture);
		} else {
			//
		}
		
		var textureAtlas:StarlingTextureAtlas = new StarlingTextureAtlas(texture, textureAtlasXML);
		
		if(Starling.handleLostContext) {
			textureAtlas._bitmapData = bitmapData;
		} else {
			bitmapData.dispose();
		}
		return textureAtlas;
	}
}