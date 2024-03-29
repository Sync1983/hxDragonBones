package dragonbones.factorys;
import dragonbones.Armature;
import dragonbones.Bone;
import dragonbones.display.NativeDisplayBridge;
import dragonbones.objects.AnimationData;
import dragonbones.objects.ArmatureData;
import dragonbones.objects.BoneData;
import dragonbones.objects.DecompressedData;
import dragonbones.objects.DisplayData;
import dragonbones.objects.Node;
import dragonbones.objects.SkeletonData;
import dragonbones.objects.XMLDataParser;
import dragonbones.textures.ITextureAtlas;
import dragonbones.textures.NativeTextureAtlas;
import dragonbones.textures.SubTextureData;
import hsl.haxe.direct.DirectSignaler;
import hsl.haxe.Signaler;
import nme.display.Bitmap;
import nme.display.DisplayObject;
import nme.display.DisplayObjectContainer;
import nme.display.Loader;
import nme.display.LoaderInfo;
import nme.display.MovieClip;
import nme.display.Shape;
import nme.display.Sprite;
import nme.events.Event;
import nme.geom.Matrix;
import nme.geom.Rectangle;
import nme.ObjectHash;
import nme.utils.ByteArray;

/**
 * @author SlavaRa
 * проверки вида a != a, используются вместо Math.isNaN(а),
 * т.к. Math.isNaN вызывает утечки памяти для flash платформы
 */
class BaseFactory/*implements IDisposable*/{

	static var helpMatrix:Matrix = new Matrix();
	
	public function new() {
		onDataParsed = new DirectSignaler(this);
		_name2SkeletonData = new Hash<SkeletonData>();
		_name2TexAtlas = new Hash<ITextureAtlas>();
		_loader2TexAtlasXML = new ObjectHash<Loader, Xml>();
	}
	
	public var onDataParsed(default, null):Signaler<Void>;
	
	var _name2SkeletonData:Hash<SkeletonData>;
	var _name2TexAtlas:Hash<ITextureAtlas>;
	var _loader2TexAtlasXML:ObjectHash<Loader, Xml>;
	var _curSkeletonData:SkeletonData;
	var _curTexAtlas:Dynamic;
	var _curSkeletonName:String;
	var _curTexAtlasName:String;
	
	public function parseData(bytes:ByteArray, ?skeletonName:String):SkeletonData {
		var decompressedData:DecompressedData = XMLDataParser.decompressData(bytes);
		
		var skeletonData:SkeletonData = XMLDataParser.parseSkeletonData(decompressedData.skeletonXml);
		if (skeletonName == null) {
			skeletonName = skeletonData.name;
		}
		addSkeletonData(skeletonData, skeletonName);
		
		var loader:Loader = new Loader();
		_loader2TexAtlasXML.set(loader, decompressedData.texAtlasXml);
		loader.name = skeletonName;
		loader.contentLoaderInfo.addEventListener(Event.COMPLETE, loaderCompleteHandler);
		loader.loadBytes(decompressedData.texBytes);
		
		decompressedData.dispose();
		return skeletonData;
	}
	
	//TODO: not use
	public function getSkeletonData(name:String):SkeletonData {
		return _name2SkeletonData.get(name);
	}
	
	//TODO: use only this
	public function addSkeletonData(skeletonData:SkeletonData, ?name:String) {
		if (name == null) {
			name = skeletonData.name;
		}
		
		if(name == null) {
			throw "Unnamed data!";
		}
		
		_name2SkeletonData.set(name, skeletonData);
	}
	
	//TODO: not use
	public function removeSkeletonData(name:String) {
		_name2SkeletonData.remove(name);
	}
	
	//TODO: not use
	public function getTextureAtlas(name:String):Dynamic {
		return _name2TexAtlas.get(name);
	}
	
	//TODO: use only this
	public function addTextureAtlas(texAtlas:ITextureAtlas, ?name:String) {
		if (name == null) {
			name = texAtlas.name;
		}
		
		if(name == null) {
			throw "Unnamed data!";
		}
		
		_name2TexAtlas.set(name, texAtlas);
	}
	
	//TODO: not use
	public function removeTextureAtlas(name:String) {
		_name2TexAtlas.remove(name);
	}
	
	public function dispose(disposeData:Bool = true) {
		if (disposeData) {
			for (i in _name2SkeletonData) {
				i.dispose();
			}
			for (i in _name2TexAtlas) {
				i.dispose();
			}
		}
		
		_name2SkeletonData = null;
		_name2TexAtlas = null;
		_loader2TexAtlasXML = null;
		_curSkeletonData = null;
		_curTexAtlas = null;
		_curSkeletonName = null;
		_curTexAtlasName = null;
	}
	
	public function buildArmature(armatureName:String, ?animationName:String, ?skeletonName:String, ?texAtlasName:String):Armature {
		if (animationName == null) {
			animationName = armatureName;
		}
		
		var skeletonData:SkeletonData = null;
		var armatureData:ArmatureData = null;
		if (skeletonName != null) {
			skeletonData = _name2SkeletonData.get(skeletonName);
			if (skeletonData != null) {
				armatureData = skeletonData.getArmatureData(armatureName);
			}
		} else {
			for (key in _name2SkeletonData.keys()) {
				skeletonData = _name2SkeletonData.get(key);
				armatureData = skeletonData.getArmatureData(armatureName);
				if (armatureData != null) {
					skeletonName = key;
					break;
				}
			}
		}
		
		if(armatureData == null) {
			return null;
		}
		
		_curSkeletonName = skeletonName;
		_curSkeletonData = skeletonData;
		
		if (texAtlasName != null) {
			_curTexAtlasName = texAtlasName;
		} else {
			_curTexAtlasName = skeletonName;
		}
		
		_curTexAtlas = _name2TexAtlas.get(_curTexAtlasName);
		
		var animationData:AnimationData = _curSkeletonData.getAnimationData(animationName);
		
		if (animationData == null) {
			for (value in _name2SkeletonData) {
				animationData = value.getAnimationData(animationName);
				if(animationData != null) {
					break;
				}
			}
		}
		
		var armature:Armature = createArmature();
		armature.name = armatureName;
		armature.animation.animationData = animationData;
		for (name in armatureData.boneNames) {
			var data:BoneData = armatureData.getBoneData(name);
			if(data != null) {
				var bone:Bone = buildBone(data);
				bone.name = name;
				armature.addBone(bone, data.parent);
			}
		}
		armature.bonesIndexChanged = true;
		armature.update();
		return armature;
	}
	
	//TODO: not use
	public function getTextureDisplay(texName:String, ?texAtlasName:String, ?pivotX:Float, ?pivotY:Float):Dynamic {
		var texAtlas:ITextureAtlas = null;
		if(texAtlasName != null) {
			texAtlas = _name2TexAtlas.get(texAtlasName);
		} else {
			for (value in _name2TexAtlas) {
				if (value.getRegion(texName) != null) {
					texAtlas = value;
					break;
				}
				texAtlas = null;
			}
		}
		
		if(texAtlas == null) {
			return null;
		}
		
		if ((pivotX != pivotX) || (pivotY != pivotY)) {
			var skeletonData:SkeletonData = _name2SkeletonData.get(texAtlasName);
			if(skeletonData != null) {
				var displayData:DisplayData = skeletonData.getDisplayData(texName);
				if(displayData != null) {
					if (pivotX != pivotX) {
						pivotX = displayData.pivotX;
					}
					if (pivotY != pivotY) {
						pivotY = displayData.pivotY;
					} 
				}
			}
		}
		return createTextureDisplay(texAtlas, texName, Std.int(pivotX), Std.int(pivotY));
	}
	
	function loaderCompleteHandler(event:Event) {
		var loaderInfo:LoaderInfo = cast(event.target, LoaderInfo);
		loaderInfo.removeEventListener(Event.COMPLETE, loaderCompleteHandler);
		
		var texAtlasXML:Xml = _loader2TexAtlasXML.get(loaderInfo.loader);
		_loader2TexAtlasXML.remove(loaderInfo.loader);
		
		if((loaderInfo.loader.name != null) && (texAtlasXML != null)) {
			
			var texAtlas:ITextureAtlas = createTextureAtlas(getContent(loaderInfo), texAtlasXML);
			addTextureAtlas(texAtlas, loaderInfo.loader.name);
			
			if (Lambda.count(_loader2TexAtlasXML) == 0) {
				onDataParsed.dispatch();
			}
		}
		
		#if flash
		loaderInfo.loader.unloadAndStop();
		#else
		loaderInfo.loader.unload();
		#end
	}
	
	function buildBone(boneData:BoneData):Bone {
		var bone:Bone = createBone();
		Node.copy(boneData.node, bone.origin);
		
		var i:Int = boneData.displayNames.length;
		while (i --> 0) {
			var name:String = boneData.displayNames[i];
			var data:DisplayData = _curSkeletonData.getDisplayData(name);
			bone.changeDisplay(i);
			if (data.isArmature) {
				var armature:Armature = buildArmature(name, null, _curSkeletonName, _curTexAtlasName);
				if(armature != null) {
					armature.animation.play();
					Reflect.callMethod(bone, Reflect.field(bone, Bone.SET_CHILD_ARMATURE), [armature]);
				}
			} else {
				Reflect.callMethod(bone, Reflect.field(bone, Bone.SET_DISPLAY), [createTextureDisplay(_curTexAtlas, name, Std.int(data.pivotX), Std.int(data.pivotY))]);
			}
		}
		return bone;
	}
	
	function getContent(loaderInfo:LoaderInfo):Dynamic {
		if (Std.is(loaderInfo.content, Bitmap)) {
			return cast(loaderInfo.content, Bitmap).bitmapData;
		}
		
		if (Std.is(loaderInfo.content, DisplayObjectContainer)) {
			return cast(loaderInfo.content, DisplayObjectContainer).getChildAt(0);
		}
		
		return throw "non supported type";
	}
	
	function createTextureAtlas(content:Dynamic, textureAtlasXML:Dynamic):ITextureAtlas {
		return new NativeTextureAtlas(content, cast(textureAtlasXML, Xml));
	}
	
	function createArmature():Armature {
		return new Armature(new Sprite());
	}
	
	function createBone():Bone {
		return new Bone(new NativeDisplayBridge());
	}
	
	function createTextureDisplay(texAtlas:ITextureAtlas, fullName:String, pivotX:Int = 0, pivotY:Int = 0):Dynamic {
		if (Std.is(texAtlas, NativeTextureAtlas)) {
			var nativeTexAtlas:NativeTextureAtlas = cast(texAtlas, NativeTextureAtlas);
			var clip:MovieClip = nativeTexAtlas.movieClip;
			if ((clip != null) && (clip.totalFrames >= 3)) {
				clip.gotoAndStop(clip.totalFrames);
				clip.gotoAndStop(fullName);
				if (clip.numChildren > 0) {
					var displayObject:DisplayObject = clip.getChildAt(0);
					displayObject.x = 0;
					displayObject.y = 0;
					return displayObject;
				}
			} else if (nativeTexAtlas.bitmapData != null) {
				var rect:Rectangle = nativeTexAtlas.getRegion(fullName);
				if(Std.is(rect, SubTextureData)){
					var subTexData:SubTextureData = cast(rect, SubTextureData);
					var shape:Shape = new Shape();
					
					//1.4
					if (pivotX == 0) {
						pivotX = subTexData.pivotX;
					}
					if (pivotY == 0) {
						pivotY = subTexData.pivotY;
					}
					
					helpMatrix.identity();
					helpMatrix.scale(nativeTexAtlas.scale, nativeTexAtlas.scale);
					helpMatrix.tx = -subTexData.x - pivotX;
					helpMatrix.ty = -subTexData.y - pivotY;
					
					shape.graphics.beginBitmapFill(nativeTexAtlas.bitmapData, helpMatrix, false, true);
					shape.graphics.drawRect( -pivotX, -pivotY, subTexData.width, subTexData.height);
					shape.graphics.endFill();
					return shape;
				}
			}
		}
		return null;
	}
	
}