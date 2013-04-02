package hxDragonBones.factorys;
import hxDragonBones.Armature;
import hxDragonBones.Bone;
import hxDragonBones.display.NativeDisplayBridge;
import hxDragonBones.objects.AnimationData;
import hxDragonBones.objects.ArmatureData;
import hxDragonBones.objects.BoneData;
import hxDragonBones.objects.DecompressedData;
import hxDragonBones.objects.DisplayData;
import hxDragonBones.objects.SkeletonData;
import hxDragonBones.objects.XMLDataParser;
import hxDragonBones.textures.ITextureAtlas;
import hxDragonBones.textures.NativeTextureAtlas;
import hxDragonBones.textures.SubTextureData;
import nme.display.Bitmap;
import nme.display.DisplayObject;
import nme.display.DisplayObjectContainer;
import nme.display.Loader;
import nme.display.LoaderInfo;
import nme.display.MovieClip;
import nme.display.Shape;
import nme.display.Sprite;
import nme.errors.Error;
import nme.events.Event;
import nme.events.EventDispatcher;
import nme.events.IEventDispatcher;
import nme.geom.Matrix;
import nme.Lib;
import nme.utils.ByteArray;
import nme.ObjectHash;

/**
 * @author SlavaRa
 */
class BaseFactory extends EventDispatcher{

	public function new(?target:IEventDispatcher) {
		super(target);
		_helpMatrix = new Matrix();
		_skeletonDataDic = new ObjectHash<String, SkeletonData>();
		_textureAtlasDic = new ObjectHash<String, ITextureAtlas>();
		_loader2TexAtlasXML = new ObjectHash<Loader, Xml>();
	}
	
	var _helpMatrix:Matrix;
	var _skeletonDataDic:ObjectHash<String, SkeletonData>;
	var _textureAtlasDic:ObjectHash<String, ITextureAtlas>;
	var _loader2TexAtlasXML:ObjectHash<Loader, Xml>;
	var _currentSkeletonData:SkeletonData;
	var _currentTextureAtlas:Dynamic;
	var _currentSkeletonName:String;
	var _currentTextureAtlasName:String;
	
	public function parseData(bytes:ByteArray, ?skeletonName:String):SkeletonData {
		var decompressedData:DecompressedData = XMLDataParser.decompressData(bytes);
		
		var skeletonData:SkeletonData = XMLDataParser.parseSkeletonData(decompressedData.skeletonXML);
		if (skeletonName == null) {
			skeletonName = skeletonData.name;
		}
		addSkeletonData(skeletonData, skeletonName);
		
		var loader:Loader = new Loader();
		_loader2TexAtlasXML.set(loader, decompressedData.textureAtlasXML);
		loader.name = skeletonName;
		loader.contentLoaderInfo.addEventListener(Event.COMPLETE, loaderCompleteHandler);
		loader.loadBytes(decompressedData.textureBytes);
		
		decompressedData.dispose();
		return skeletonData;
	}
	
	public function getSkeletonData(name:String):SkeletonData {
		return _skeletonDataDic.get(name);
	}
	
	public function addSkeletonData(skeletonData:SkeletonData, ?name:String) {
		if (name == null) {
			name = skeletonData.name;
		}
		
		if(name == null) {
			throw "Unnamed data!";
		}
		
		if(skeletonData != null) {
			_skeletonDataDic.set(name, skeletonData);
		}
	}
	
	public function removeSkeletonData(name:String) {
		_skeletonDataDic.remove(name);
	}
	
	public function getTextureAtlas(name:String):Dynamic {
		return _textureAtlasDic.get(name);
	}
	
	public function addTextureAtlas(textureAtlas:ITextureAtlas, ?name:String) {
		if((name == null) && (textureAtlas != null)) {
			name = textureAtlas.name;
		}
		
		if(name == null) {
			throw "Unnamed data!";
		}
		
		if(textureAtlas != null) {
			_textureAtlasDic.set(name, textureAtlas);
		}
	}
	
	public function removeTextureAtlas(name:String) {
		_textureAtlasDic.remove(name);
	}
	
	public function dispose(disposeData:Bool = true) {
		if(disposeData) {
			for (skeletonData in _skeletonDataDic) {
				skeletonData.dispose();
			}
			
			for (textureAtlas in _textureAtlasDic) {
				textureAtlas.dispose();
			}
		}
		
		_skeletonDataDic = new ObjectHash<String, SkeletonData>();
		_textureAtlasDic = new ObjectHash<String, ITextureAtlas>();
		_loader2TexAtlasXML = new ObjectHash<Loader, Xml>();
		
		_currentSkeletonData = null;
		_currentTextureAtlas = null;
		_currentSkeletonName = null;
		_currentTextureAtlasName = null;
	}
	
	public function buildArmature(armatureName:String, ?animationName:String, ?skeletonName:String, ?textureAtlasName:String):Armature {
		if (animationName == null) {
			animationName = armatureName;
		}
		
		var skeletonData:SkeletonData = null;
		var armatureData:ArmatureData = null;
		if(skeletonName != null) {
			skeletonData = _skeletonDataDic.get(skeletonName);
			if(skeletonData != null) {
				armatureData = skeletonData.getArmatureData(armatureName);
			}
		} else {
			for (skeletonName in _skeletonDataDic.keys()) {
				skeletonData = _skeletonDataDic.get(skeletonName);
				armatureData = skeletonData.getArmatureData(armatureName);
				if(armatureData != null) {
					break;
				}
			}
		}
		
		if(armatureData == null) {
			return null;
		}
		
		_currentSkeletonName = skeletonName;
		_currentSkeletonData = skeletonData;
		
		if (textureAtlasName != null) {
			_currentTextureAtlasName = textureAtlasName;
		} else {
			_currentTextureAtlasName = skeletonName;
		}
		
		_currentTextureAtlas = _textureAtlasDic.get(_currentTextureAtlasName);
		
		var animationData:AnimationData = _currentSkeletonData.getAnimationData(animationName);
		
		if(animationData == null) {
			for (skeletonData in _skeletonDataDic) {
				animationData = skeletonData.getAnimationData(animationName);
				if(animationData != null) {
					break;
				}
			}
		}
		
		var armature:Armature = generateArmature();
		armature.name = armatureName;
		armature.animation.animationData = animationData;
		for (boneName in armatureData.boneNames) {
			var boneData:BoneData = armatureData.getBoneData(boneName);
			if(boneData != null) {
				var bone:Bone = buildBone(boneData);
				bone.name = boneName;
				armature.addBone(bone, boneData.parent);
			}
		}
		armature.bonesIndexChanged = true;
		armature.update();
		return armature;
	}
	
	public function getTextureDisplay(textureName:String, ?textureAtlasName:String, ?pivotX:Null<Float>, ?pivotY:Null<Float>):Dynamic {
		var textureAtlas:ITextureAtlas = null;
		if(textureAtlasName != null) {
			textureAtlas = _textureAtlasDic.get(textureAtlasName);
		} else {
			for (textureAtlas in _textureAtlasDic) {
				if(textureAtlas.getRegion(textureName) != null) {
					break;
				}
				textureAtlas = null;
			}
		}
		
		if(textureAtlas != null) {
			if ((pivotX == null) || (pivotY == null)) {
				var skeletonData:SkeletonData = _skeletonDataDic.get(textureAtlasName);
				if(skeletonData != null) {
					var displayData:DisplayData = skeletonData.getDisplayData(textureName);
					if(displayData != null) {
						pivotX = (pivotX != null) ? pivotX : displayData.pivotX;
						pivotY = (pivotY != null) ? pivotY : displayData.pivotY;
					}
				}
			}
			
			return generateTextureDisplay(textureAtlas, textureName, cast(pivotX, Int), cast(pivotY, Int));
		}
		return null;
	}
	
	function buildBone(boneData:BoneData):Bone {
		var bone:Bone = generateBone();
		bone.origin.copy(boneData.node);
		
		var displayData:DisplayData;
		for (i in (boneData.displayNames.length - 1) ... 0) {
			var displayName:String = boneData.displayNames[i];
			displayData = _currentSkeletonData.getDisplayData(displayName);
			bone.changeDisplay(i);
			if (displayData.isArmature) {
				var childArmature:Armature = buildArmature(displayName, null, _currentSkeletonName, _currentTextureAtlasName);
				if(childArmature != null) {
					childArmature.animation.play();
					bone.display = childArmature;
				}
			} else {
				bone.display = generateTextureDisplay(_currentTextureAtlas, displayName, displayData.pivotX, displayData.pivotY);
			}
		}
		return bone;
	}
	
	function loaderCompleteHandler(event:Event) {
		var loaderInfo:LoaderInfo = cast(event.target, LoaderInfo);
		loaderInfo.removeEventListener(Event.COMPLETE, loaderCompleteHandler);
		
		var texAtlasXML:Xml = _loader2TexAtlasXML.get(loaderInfo.loader);
		_loader2TexAtlasXML.remove(loaderInfo.loader);
		
		if((loaderInfo.loader.name != null) && (texAtlasXML != null)) {
			
			var textureAtlas:ITextureAtlas = generateTextureAtlas(getContent(loaderInfo), texAtlasXML);
			addTextureAtlas(textureAtlas, loaderInfo.loader.name);
			
			if ((Lambda.count(_loader2TexAtlasXML) == 0) && hasEventListener(Event.COMPLETE)) {
				dispatchEvent(new Event(Event.COMPLETE));
			}
		}
		
		#if flash
		loaderInfo.loader.unloadAndStop();
		#else
		loaderInfo.loader.unload();
		#end
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
	
	function generateTextureAtlas(content:Dynamic, textureAtlasXML:Dynamic):ITextureAtlas {
		return new NativeTextureAtlas(content, cast(textureAtlasXML, Xml));
	}
	
	function generateArmature():Armature {
		return new Armature(new Sprite());
	}
	
	function generateBone():Bone {
		return new Bone(new NativeDisplayBridge());
	}
	
	function generateTextureDisplay(textureAtlas:ITextureAtlas, fullName:String, pivotX:Int, pivotY:Int):Dynamic {
		var nativeTextureAtlas:NativeTextureAtlas = cast(textureAtlas, NativeTextureAtlas);
		if(nativeTextureAtlas != null){
			var movieClip:MovieClip = nativeTextureAtlas.movieClip;
			if ((movieClip != null) && (movieClip.totalFrames >= 3)) {
				movieClip.gotoAndStop(movieClip.totalFrames);
				movieClip.gotoAndStop(fullName);
				if (movieClip.numChildren > 0) {
					try {
						var displaySWF:DisplayObject = movieClip.getChildAt(0);
						displaySWF.x = 0;
						displaySWF.y = 0;
						return displaySWF;
					} catch(error:Error) {
						throw "Can not get the movie clip, please make sure the version of the resource compatible with app version!";
					}
				}
			} else if(nativeTextureAtlas.bitmapData != null) {
				var subTextureData:SubTextureData = cast(nativeTextureAtlas.getRegion(fullName), SubTextureData);
				if (subTextureData != null) {
					var displayShape:Shape = new Shape();
					//1.4
					pivotX = (pivotX != 0) ? pivotX : subTextureData.pivotX;
					pivotY = (pivotY != 0) ? pivotY : subTextureData.pivotY;
					_helpMatrix.a = 1;
					_helpMatrix.b = 0;
					_helpMatrix.c = 0;
					_helpMatrix.d = 1;
					_helpMatrix.scale(nativeTextureAtlas.scale, nativeTextureAtlas.scale);
					_helpMatrix.tx = -subTextureData.x - pivotX;
					_helpMatrix.ty = -subTextureData.y - pivotY;
					
					displayShape.graphics.beginBitmapFill(nativeTextureAtlas.bitmapData, _helpMatrix, false, true);
					displayShape.graphics.drawRect(-pivotX, -pivotY, subTextureData.width, subTextureData.height);
					return displayShape;
				}
			}
		}
		return null;
	}
}