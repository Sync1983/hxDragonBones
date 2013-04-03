package hxDragonBones.objects;
import haxe.Log;
import hxDragonBones.animation.Tween;
import hxDragonBones.errors.UnknownDataError;
import hxDragonBones.utils.BytesType;
import hxDragonBones.utils.ConstValues;
import hxDragonBones.utils.TransformUtils;
import nme.errors.Error;
import nme.geom.ColorTransform;
import nme.Lib;
import nme.utils.ByteArray;

/**
 * @author SlavaRa
 */
class XMLDataParser{

	static inline var ANGLE_TO_RADIAN:Float = Math.PI / 180;
	static inline var HALF_PI:Float = Math.PI * 0.5;
	
	static var _currentSkeletonData:SkeletonData;
	static var _helpNode:Node = new Node();
	static var _helpFrameData:FrameData = new FrameData();
	
	static inline function checkSkeletonXMLVersion(skeletonXML:Xml) {
		var version:String = skeletonXML.firstElement().get(ConstValues.A_VERSION);
		if ((version != ConstValues.VERSION_14) && (version != ConstValues.VERSION)) {
			throw "Nonsupport data version!";
		}
	}
	
	public static function getElementsByAttribute(xmlList:Iterator<Xml>, attribute:String, value:String):Array<Xml> {
		var result:Array<Xml> = [];
		for (xml in xmlList) {
			if (xml.get(attribute) == value) {
				result.push(xml);
			}
		}
		return result;
	}
	
	public static function compressData(skeletonXML:Xml, textureAtlasXML:Xml, byteArray:ByteArray):ByteArray  {
		var byteArrayCopy:ByteArray = new ByteArray();
		byteArrayCopy.writeBytes(byteArray);
		
		var xmlBytes:ByteArray = new ByteArray();
		xmlBytes.writeUTFBytes(textureAtlasXML.toString());
		xmlBytes.compress();
		
		byteArrayCopy.position = byteArrayCopy.length;
		byteArrayCopy.writeBytes(xmlBytes);
		byteArrayCopy.writeInt(xmlBytes.length);
		
		#if flash 
		xmlBytes.clear();
		#end
		
		xmlBytes.writeUTFBytes(skeletonXML.toString());
		xmlBytes.compress();
		
		byteArrayCopy.position = byteArrayCopy.length;
		byteArrayCopy.writeBytes(xmlBytes);
		byteArrayCopy.writeInt(xmlBytes.length);
		
		return byteArrayCopy;
	}
	
	public static inline function decompressData(compressedByteArray:ByteArray):DecompressedData {
		switch(BytesType.getType(compressedByteArray)) {
			case BytesType.SWF, BytesType.PNG, BytesType.JPG:
				var skeletonXML:Xml = null;
				var textureAtlasXML:Xml = null;
				try  {
					compressedByteArray.position = compressedByteArray.length - 4;
					var strSize:Int = compressedByteArray.readInt();
					var position:Int = compressedByteArray.length - 4 - strSize;
					
					var xmlBytes:ByteArray = new ByteArray();
					xmlBytes.writeBytes(compressedByteArray, position, strSize);
					xmlBytes.uncompress();
					compressedByteArray.length = position;
					
					skeletonXML = Xml.parse(xmlBytes.readUTFBytes(xmlBytes.length));
					
					compressedByteArray.position = compressedByteArray.length - 4;
					strSize = compressedByteArray.readInt();
					position = compressedByteArray.length - 4 - strSize;
					
					#if flash
					xmlBytes.clear();
					#end
					
					xmlBytes.length = 0;
					xmlBytes.writeBytes(compressedByteArray, position, strSize);
					xmlBytes.uncompress();
					compressedByteArray.length = position;
					textureAtlasXML = Xml.parse(xmlBytes.readUTFBytes(xmlBytes.length));
				} catch (error:Error) {
					throw "Decompress error!";//TODO: понять из-за чего может быть ошибка, исключить try...catch
				}
				return new DecompressedData(skeletonXML, textureAtlasXML, compressedByteArray);
			case BytesType.ZIP:
				throw "Can not decompress zip!";
			default:
				throw new UnknownDataError();
		}
		return null;
	}
	
	public static function parseSkeletonData(skeletonXml:Xml):SkeletonData {
		checkSkeletonXMLVersion(skeletonXml);
		
		var skeletonData:SkeletonData = new SkeletonData();
		skeletonData.name = skeletonXml.firstElement().get(ConstValues.A_NAME);
		skeletonData.frameRate = Std.parseInt(skeletonXml.firstElement().get(ConstValues.A_FRAME_RATE));
		_currentSkeletonData = skeletonData;
		
		parseArmatures(skeletonXml.firstChild());
		parseAnimations(skeletonXml.firstChild());
		
		_currentSkeletonData = null;
		return skeletonData;
	}
	
	static function parseArmatures(armaturesXml:Xml) {
		for (armatures in armaturesXml.elementsNamed(ConstValues.ARMATURES)) {
			for (armature in armatures.elementsNamed(ConstValues.ARMATURE)) {
				var name:String = armature.get(ConstValues.A_NAME);
				var armatureData:ArmatureData = _currentSkeletonData.getArmatureData(name);
				if (armatureData != null) {
					parseArmatureData(armature, armatureData);
				} else {
					armatureData = new ArmatureData();
					parseArmatureData(armature, armatureData);
					_currentSkeletonData.armatureDataList.addData(armatureData, name);
				}
			}
		}
	}
	
	static function parseArmatureData(armatureXml:Xml, armatureData:ArmatureData) {
		//var boneXMLList:Iterator<Xml> = armatureXml.elementsNamed(ConstValues.BONE);
		for (boneXml in armatureXml.elementsNamed(ConstValues.BONE)) {
			var boneName:String 	= boneXml.get(ConstValues.A_NAME);
			var parentName:String 	= boneXml.get(ConstValues.A_PARENT);
			var parentXML:Xml 		= null;//BUG: getElementsByAttribute(boneXMLList, ConstValues.A_NAME, parentName)[0];
			var boneData:BoneData 	= armatureData.getBoneData(boneName);
			if(boneData != null) {
				parseBoneData(boneXml, parentXML, boneData);
			} else {
				boneData = new BoneData();
				parseBoneData(boneXml, parentXML, boneData);
				armatureData.boneDataList.addData(boneData, boneName);
			}
		}
		
		armatureData.updateBoneList();
	}
	
	static function parseBoneData(boneXml:Xml, ?parentXml:Xml, boneData:BoneData) {
		parseNode(boneXml, boneData.node);
		
		if(parentXml != null) {
			boneData.parent = parentXml.get(ConstValues.A_NAME);
			parseNode(parentXml, _helpNode);
			TransformUtils.transformPointWithParent(boneData.node, _helpNode);
		} else {
			boneData.parent = null;
		}
		
		if (_currentSkeletonData != null) {
			var i:Int = 0;
			for (displayXML in boneXml.elementsNamed(ConstValues.DISPLAY)) {
				var name:String = displayXML.get(ConstValues.A_NAME);
				boneData.displayNames[i++] = name;
				var displayData:DisplayData = _currentSkeletonData.getDisplayData(name);
				if(displayData != null) {
					parseDisplayData(displayXML, displayData);
				} else {
					displayData = new DisplayData();
					parseDisplayData(displayXML, displayData);
					_currentSkeletonData.displayDataList.addData(displayData, name);
				}
			}
		}
	}
	
	static inline function parseDisplayData(displayXml:Xml, displayData:DisplayData) {
		displayData.isArmature 	= displayXml.get(ConstValues.A_IS_ARMATURE) != null;
		displayData.pivotX 		= Std.parseInt(displayXml.get(ConstValues.A_PIVOT_X));
		displayData.pivotY 		= Std.parseInt(displayXml.get(ConstValues.A_PIVOT_Y));
	}
	
	static function parseAnimations(animationsXml:Xml) {
		for (animations in animationsXml.elementsNamed(ConstValues.ANIMATIONS)) {
			for (animation in animations.elementsNamed(ConstValues.ANIMATION)) {
				var name:String = animation.get(ConstValues.A_NAME);
				var armatureData:ArmatureData = _currentSkeletonData.getArmatureData(name);
				var animationData:AnimationData = _currentSkeletonData.getAnimationData(name); 
				if (animationData != null) {
					parseAnimationData(animation, animationData, armatureData);
				} else {
					animationData = new AnimationData();
					parseAnimationData(animation, animationData, armatureData);
					_currentSkeletonData.animationDataList.addData(animationData, name);
				}
			}
		}
	}
	
	static function parseAnimationData(animationXml:Xml, animationData:AnimationData, armatureData:ArmatureData) {
		for (movement in animationXml.elementsNamed(ConstValues.MOVEMENT)) {
			var name:String = movement.get(ConstValues.A_NAME);
			var movementData:MovementData = animationData.getMovementData(name);
			if(movementData != null) {
				parseMovementData(movement, armatureData, movementData);
			} else {
				movementData = new MovementData();
				parseMovementData(movement, armatureData, movementData);
				animationData.movementDataList.addData(movementData, name);
			}
		}
	}
	
	static function parseMovementData(movementXml:Xml, armatureData:ArmatureData, movementData:MovementData) {
		if(_currentSkeletonData != null) {
			var frameRate:Int = _currentSkeletonData.frameRate;
			var duration:Int = Std.parseInt(movementXml.get(ConstValues.A_DURATION));
			
			movementData.duration 		= (duration > 1) ? (duration / frameRate) : 0;
			movementData.durationTo 	= Std.parseInt(movementXml.get(ConstValues.A_DURATION_TO))		/ frameRate;
			movementData.durationTween 	= Std.parseInt(movementXml.get(ConstValues.A_DURATION_TWEEN))	/ frameRate;
			movementData.loop 			= Std.parseInt(movementXml.get(ConstValues.A_LOOP)) == 1;
			movementData.tweenEasing 	= Std.parseFloat(movementXml.get(ConstValues.A_TWEEN_EASING));
		}
		
		var boneNames:Array<String> = armatureData.boneNames;
		
		var movementBoneXMLList:Iterator<Xml> = movementXml.elementsNamed(ConstValues.BONE);
		for (movementBoneXML in movementXml.elementsNamed(ConstValues.BONE)) {
			var boneName:String = movementBoneXML.get(ConstValues.A_NAME);
			var boneData:BoneData = armatureData.getBoneData(boneName);
			var parentMovementBoneXml:Xml = null;//BUG: getElementsByAttribute(movementBoneXMLList, ConstValues.A_NAME, boneData.parent)[0];
			var movementBoneData:MovementBoneData = movementData.getMovementBoneData(boneName);
			if(movementBoneXML != null) {
				if(movementBoneData != null) {
					parseMovementBoneData(movementBoneXML, parentMovementBoneXml, boneData, movementBoneData);
				} else {
					movementBoneData = new MovementBoneData();
					parseMovementBoneData(movementBoneXML, parentMovementBoneXml, boneData, movementBoneData);
					movementData.movementBoneDataList.addData(movementBoneData, boneName);
				}
			}
			
			var index:Int = Lambda.indexOf(boneNames, boneName);
			if(index != -1) {
				boneNames.splice(index, 1);
			}
		}
		
		for (boneName in boneNames) {
			movementData.movementBoneDataList.addData(MovementBoneData.HIDE_DATA, boneName);
		}
		
		var movementFrameXMLList:Iterator<Xml> = movementXml.elementsNamed(ConstValues.FRAME);
		var movementFrameList:Array<MovementFrameData> = movementData.movementFrameList;
		var i:Int = 0;
		for (movementFrameXML in movementFrameXMLList) {
			var movementFrameData:MovementFrameData = (movementFrameList.length > i) ? movementFrameList[i] : null;
			if(movementFrameData != null) {
				parseMovementFrameData(movementFrameXML, movementFrameData);
			} else {
				movementFrameData = new MovementFrameData();
				parseMovementFrameData(movementFrameXML, movementFrameData);
				if(!Lambda.has(movementFrameList, movementFrameData)){
					movementFrameList.push(movementFrameData);
				}
			}
			i++;
		}
	}
	
	static function parseMovementBoneData(movementBoneXML:Xml, parentMovementBoneXML:Xml, boneData:BoneData, movementBoneData:MovementBoneData) {
		var scale:Float = Std.parseFloat(movementBoneXML.get(ConstValues.A_MOVEMENT_SCALE));
		var delay:Float = Std.parseFloat(movementBoneXML.get(ConstValues.A_MOVEMENT_DELAY));
		movementBoneData.setValues(scale, delay);
		
		var parentFrameXMLList:Iterator<Xml> = null;
		var parentFrameCount:Int = 0;
		var parentFrameXML:Xml = null;
		var parentTotalDuration:Int = 0;
		var totalDuration:Int = 0;
		var currentDuration:Int = 0;
		if (parentMovementBoneXML != null) {
			parentFrameXMLList 	= parentMovementBoneXML.elementsNamed(ConstValues.FRAME);
			parentFrameCount	= Lambda.count(parentMovementBoneXML);
		}
		
		var frameXMLList:Iterator<Xml> = movementBoneXML.elementsNamed(ConstValues.FRAME);
		var frameList:Array<FrameData> = movementBoneData.frameList;
		
		var i:Int = 0;
		var j:Int = 0;
		for(frameXML in frameXMLList){
			var frameData:FrameData = frameList.length > j ? frameList[j] : null;
			
			if(frameData != null) {
				parseFrameData(frameXML, frameData);
			} else {
				frameData = new FrameData();
				frameList.push(frameData);
				parseFrameData(frameXML, frameData);
			}
			
			if(parentMovementBoneXML != null) {
				while((i < parentFrameCount) && ((parentFrameXML != null) ? (totalDuration < parentTotalDuration || totalDuration >= parentTotalDuration + currentDuration):true)) {
					parentFrameXML = parentFrameXMLList.next();
					parentTotalDuration += currentDuration;
					currentDuration = Std.parseInt(parentFrameXML.get(ConstValues.A_DURATION));
					i++;
				}
				
				parseFrameData(parentFrameXML, _helpFrameData);
				
				var tweenFrameXML:Xml = null;
				var progress:Float;
				if(tweenFrameXML != null) {
					progress = (totalDuration - parentTotalDuration) / currentDuration;
				} else {
					tweenFrameXML = parentFrameXML;
					progress = 0;
				}
				
				if(_helpFrameData.tweenEasing == null) {
					progress = 0;
				} else {
					progress = Tween.getEaseValue(progress, _helpFrameData.tweenEasing);
				}
				
				parseNode(tweenFrameXML, _helpNode);
				TransformUtils.setOffSetNode(_helpFrameData.node, _helpNode, _helpNode, _helpFrameData.tweenRotate);
				
				_helpNode.setValues(
					_helpFrameData.node.x 		+ progress * _helpNode.x,
					_helpFrameData.node.y 		+ progress * _helpNode.y,
					_helpFrameData.node.skewX 	+ progress * _helpNode.skewX,
					_helpFrameData.node.skewY 	+ progress * _helpNode.skewY,
					_helpFrameData.node.scaleX 	+ progress * _helpNode.scaleX,
					_helpFrameData.node.scaleY 	+ progress * _helpNode.scaleY,
					_helpFrameData.node.pivotX 	+ progress * _helpNode.pivotX,
					_helpFrameData.node.pivotY 	+ progress * _helpNode.pivotY
				);
				
				TransformUtils.transformPointWithParent(frameData.node, _helpNode);
			}
			totalDuration += Std.parseInt(frameXML.get(ConstValues.A_DURATION));
			
			frameData.node.x 		-= boneData.node.x;
			frameData.node.y 		-= boneData.node.y;
			frameData.node.skewX 	-= boneData.node.skewX;
			frameData.node.skewY 	-= boneData.node.skewY;
			frameData.node.scaleX 	-= boneData.node.scaleX;
			frameData.node.scaleY 	-= boneData.node.scaleY;
			frameData.node.pivotX 	-= boneData.node.pivotX;
			frameData.node.pivotY 	-= boneData.node.pivotY;
			frameData.node.z 		-= boneData.node.z;
			
			j++;
		}
	}
	
	static inline function parseMovementFrameData(movementFrameXml:Xml, movementFrameData:MovementFrameData) {
		movementFrameData.setValues(
			Std.parseFloat(movementFrameXml.get(ConstValues.A_DURATION)) / _currentSkeletonData.frameRate,
			movementFrameXml.get(ConstValues.A_MOVEMENT),
			movementFrameXml.get(ConstValues.A_EVENT),
			movementFrameXml.get(ConstValues.A_SOUND)
		);
	}
	
	static function parseFrameData(frameXml:Xml, frameData:FrameData) {
		parseNode(frameXml, frameData.node);
		if (_currentSkeletonData != null) {
			var colorTransformXML:Xml = frameXml.elementsNamed(ConstValues.COLOR_TRANSFORM).next();
			if(colorTransformXML != null) {
				parseColorTransform(colorTransformXML, frameData.colorTransform);
			}
			frameData.duration 		= Std.parseInt(frameXml.get(ConstValues.A_DURATION)) / _currentSkeletonData.frameRate;
			frameData.tweenEasing 	= Std.parseFloat(frameXml.get(ConstValues.A_TWEEN_EASING));
			frameData.tweenRotate 	= Std.parseInt(frameXml.get(ConstValues.A_TWEEN_ROTATE));
			frameData.displayIndex 	= Std.parseInt(frameXml.get(ConstValues.A_DISPLAY_INDEX));
			frameData.movement 		= frameXml.get(ConstValues.A_MOVEMENT);
			frameData.event 		= frameXml.get(ConstValues.A_EVENT);
			frameData.sound 		= frameXml.get(ConstValues.A_SOUND);
			frameData.soundEffect 	= frameXml.get(ConstValues.A_SOUND_EFFECT);
			
			var visible:String = frameXml.get(ConstValues.A_VISIBLE);
			frameData.visible = (visible == "1" || visible =="");
		}
	}
	
	static inline function parseNode(xml:Xml, node:Node) {
		node.x 		= Std.parseFloat(xml.get(ConstValues.A_X));
		node.y 		= Std.parseFloat(xml.get(ConstValues.A_Y));
		node.skewX 	= Std.parseFloat(xml.get(ConstValues.A_SKEW_X)) * ANGLE_TO_RADIAN;
		node.skewY 	= Std.parseFloat(xml.get(ConstValues.A_SKEW_Y)) * ANGLE_TO_RADIAN;
		node.scaleX = Std.parseFloat(xml.get(ConstValues.A_SCALE_X));
		node.scaleY = Std.parseFloat(xml.get(ConstValues.A_SCALE_Y));
		node.pivotX = Std.parseFloat(xml.get(ConstValues.A_PIVOT_X));
		node.pivotY = Std.parseFloat(xml.get(ConstValues.A_PIVOT_Y));
		node.z 		= Std.parseFloat(xml.get(ConstValues.A_Z));
	}
	
	static inline function parseColorTransform(xml:Xml, colorTransform:ColorTransform) {
		colorTransform.alphaOffset 		= Std.parseInt(xml.get(ConstValues.A_ALPHA));
		colorTransform.redOffset 		= Std.parseInt(xml.get(ConstValues.A_RED));
		colorTransform.greenOffset 		= Std.parseInt(xml.get(ConstValues.A_GREEN));
		colorTransform.blueOffset 		= Std.parseInt(xml.get(ConstValues.A_BLUE));
		colorTransform.alphaMultiplier 	= Std.parseInt(xml.get(ConstValues.A_ALPHA_MULTIPLIER)) * 0.01;
		colorTransform.redMultiplier 	= Std.parseInt(xml.get(ConstValues.A_RED_MULTIPLIER)) 	* 0.01;
		colorTransform.greenMultiplier 	= Std.parseInt(xml.get(ConstValues.A_GREEN_MULTIPLIER)) * 0.01;
		colorTransform.blueMultiplier 	= Std.parseInt(xml.get(ConstValues.A_BLUE_MULTIPLIER)) 	* 0.01;
	}
	
}