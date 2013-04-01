package hxDragonBones.objects;
import hxDragonBones.errors.UnknownDataError;
import hxDragonBones.utils.BytesType;
import hxDragonBones.utils.ConstValues;
import hxDragonBones.utils.ConstValues;
import hxDragonBones.utils.TransformUtils;
import nme.errors.Error;
import nme.geom.ColorTransform;
import nme.utils.ByteArray;

/**
 * @author SlavaRa
 */
class XMLDataParser{

	//TODO: refactor
	
	static inline var ANGLE_TO_RADIAN:Float = Math.PI / 180;
	static inline var HALF_PI:Float = Math.PI * 0.5;
	
	static var _currentSkeletonData:SkeletonData;
	static var _helpNode:Node = new Node();
	static var _helpFrameData:FrameData = new FrameData();
	
	static inline function checkSkeletonXMLVersion(skeletonXML:Xml) {
		var version:String = skeletonXML.get(ConstValues.A_VERSION);
		if ((version != ConstValues.VERSION_14) || (version != ConstValues.VERSION)) {
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
		xmlBytes.writeUTFBytes(textureAtlasXML.toXMLString());
		xmlBytes.compress();
		
		byteArrayCopy.position = byteArrayCopy.length;
		byteArrayCopy.writeBytes(xmlBytes);
		byteArrayCopy.writeInt(xmlBytes.length);
		
		xmlBytes.clear();
		xmlBytes.writeUTFBytes(skeletonXML.toXMLString());
		xmlBytes.compress();
		
		byteArrayCopy.position = byteArrayCopy.length;
		byteArrayCopy.writeBytes(xmlBytes);
		byteArrayCopy.writeInt(xmlBytes.length);
		
		return byteArrayCopy;
	}
	
	public static function decompressData(compressedByteArray:ByteArray):DecompressedData {
		var skeletonXML:Xml;
		var textureAtlasXML:Xml;
		switch(BytesType.getType(compressedByteArray)) {
			case BytesType.SWF:
			case BytesType.PNG:
			case BytesType.JPG:
				try  {
					compressedByteArray.position = compressedByteArray.length - 4;
					var strSize:Int = compressedByteArray.readInt();
					var position:UInt = compressedByteArray.length - 4 - strSize;
					
					var xmlBytes:ByteArray = new ByteArray();
					xmlBytes.writeBytes(compressedByteArray, position, strSize);
					xmlBytes.uncompress();
					compressedByteArray.length = position;
					
					skeletonXML = cast(xmlBytes.readUTFBytes(xmlBytes.length), Xml);
					
					compressedByteArray.position = compressedByteArray.length - 4;
					strSize = compressedByteArray.readInt();
					position = compressedByteArray.length - 4 - strSize;
					
					xmlBytes.clear();
					xmlBytes.writeBytes(compressedByteArray, position, strSize);
					xmlBytes.uncompress();
					compressedByteArray.length = position;
					textureAtlasXML = cast(xmlBytes.readUTFBytes(xmlBytes.length), Xml);
				} catch (error:Error) {
					throw "Decompress error!";
				}
				return new DecompressedData(skeletonXML, textureAtlasXML, compressedByteArray);
			case BytesType.ZIP:
				throw "Can not decompress zip!";
			default:
				throw new UnknownDataError();
		}
		return null;
	}
	
	public static function parseSkeletonData(skeletonXML:Xml):SkeletonData {
		var armatureData:ArmatureData;
		var animationName:String;
		
		checkSkeletonXMLVersion(skeletonXML);
		
		var skeletonData:SkeletonData = new SkeletonData();
		skeletonData.name = skeletonXML.get(ConstValues.A_NAME);
		skeletonData.frameRate = cast(skeletonXML.get(ConstValues.A_FRAME_RATE), Int);
		_currentSkeletonData = skeletonData;
		
		//for (armatureXML in skeletonXML.elementsNamed(ConstValues.ARMATURES).elementsNamed(ConstValues.ARMATURE)) {
		for (armatureXML in skeletonXML.elementsNamed(ConstValues.ARMATURE)) {
			var armatureName:String = armatureXML.get(ConstValues.A_NAME);
			armatureData = skeletonData.getArmatureData(animationName);
			if(armatureData != null) {
				parseArmatureData(armatureXML, armatureData);
			} else {
				armatureData = new ArmatureData();
				parseArmatureData(armatureXML, armatureData);
				skeletonData.armatureDataList.addData(armatureData, armatureName);
			}
		}
		
		//for (animationXML in skeletonXML.elements(ConstValues.ANIMATIONS).elements(ConstValues.ANIMATION)) {
		for (animationXML in skeletonXML.elementsNamed(ConstValues.ANIMATION)) {
			animationName = animationXML.get(ConstValues.A_NAME);
			armatureData = skeletonData.getArmatureData(animationName);
			
			var animationData:AnimationData = skeletonData.getAnimationData(animationName); 
			if(animationData != null) {
				parseAnimationData(animationXML, animationData, armatureData);
			} else {
				animationData = new AnimationData();
				parseAnimationData(animationXML, animationData, armatureData);
				skeletonData._animationDataList.addData(animationData, animationName);
			}
		}
		_currentSkeletonData = null;
		return skeletonData;
	}
	
	static function parseArmatureData(armatureXML:Xml, armatureData:ArmatureData) {
		var boneXMLList:Iterator<Xml> = armatureXML.elementsNamed(ConstValues.BONE);
		for (boneXML in boneXMLList) {
			var boneName:String = boneXML.get(ConstValues.A_NAME);
			var parentName:String = boneXML.get(ConstValues.A_PARENT);
			var parentXML:Xml = getElementsByAttribute(boneXMLList, ConstValues.A_NAME, parentName)[0];
			var boneData:BoneData = armatureData.getBoneData(boneName);
			if(boneData != null) {
				parseBoneData(boneXML, parentXML, boneData);
			} else {
				boneData = new BoneData();
				parseBoneData(boneXML, parentXML, boneData);
				armatureData.boneDataList.addData(boneData, boneName);
			}
		}
		
		armatureData.updateBoneList();
	}
	
	static function parseBoneData(boneXML:Xml, parentXML:Xml, boneData:BoneData) {
		parseNode(boneXML, boneData.node);
		
		if(parentXML != null) {
			boneData.parent = parentXML.get(ConstValues.A_NAME);
			parseNode(parentXML, _helpNode);
			TransformUtils.transformPointWithParent(boneData.node, _helpNode);
		} else {
			boneData.parent = null;
		}
		
		if(_currentSkeletonData != null) {
			var displayXMLList:Iterator<Xml> = boneXML.elementsNamed(ConstValues.DISPLAY);
			var i:Int = 0;
			for(displayXML in displayXMLList) {
				var displayName:String = displayXML.get(ConstValues.A_NAME);
				boneData.displayNames[i] = displayName;
				var displayData:DisplayData = _currentSkeletonData.getDisplayData(displayName);
				if(displayData != null) {
					parseDisplayData(displayXML, displayData);
				} else {
					displayData = new DisplayData();
					parseDisplayData(displayXML, displayData);
					_currentSkeletonData.displayDataList.addData(displayData, displayName);
				}
				i++;
			}
		}
	}
	
	static function parseDisplayData(displayXML:Xml, displayData:DisplayData) {
		displayData.isArmature = cast(displayXML.get(ConstValues.A_IS_ARMATURE), Int) != 0;
		displayData.pivotX = cast(displayXML.get(ConstValues.A_PIVOT_X), Int);
		displayData.pivotY = cast(displayXML.get(ConstValues.A_PIVOT_Y), Int);
	}
	
	static function parseAnimationData(animationXML:Xml, animationData:AnimationData, armatureData:ArmatureData) {
		for (movementXML in animationXML.elementsNamed(ConstValues.MOVEMENT)) {
			var movementName:String = movementXML.get(ConstValues.A_NAME);
			var movementData:MovementData = animationData.getMovementData(movementName);
			if(movementData != null) {
				parseMovementData(movementXML, armatureData, movementData);
			} else {
				movementData = new MovementData();
				parseMovementData(movementXML, armatureData, movementData);
				animationData._movementDataList.addData(movementData, movementName);
			}
		}
	}
	
	static function parseMovementData(movementXML:Xml, armatureData:ArmatureData, movementData:MovementData) {
		if(_currentSkeletonData != null) {
			var frameRate:UInt = _currentSkeletonData.frameRate;
			var duration:Int = cast(movementXML.get(ConstValues.A_DURATION), Int);
			
			movementData.duration = (duration > 1) ? (duration / frameRate) : 0;
			movementData.durationTo = Std.parseInt(movementXML.get(ConstValues.A_DURATION_TO)) / frameRate;
			movementData.durationTween = Std.parseInt(movementXML.get(ConstValues.A_DURATION_TWEEN)) / frameRate;
			movementData.loop = Std.parseInt(movementXML.get(ConstValues.A_LOOP)) == 1;
			movementData.tweenEasing = Std.parseFloat(movementXML.get(ConstValues.A_TWEEN_EASING));
		}
		
		var boneNames:Array<String> = armatureData.boneNames;
		
		var movementBoneXMLList:Iterator<Xml> = movementXML.elementsNamed(ConstValues.BONE);
		for (movementBoneXML in movementBoneXMLList) {
			var boneName:String = movementBoneXML.get(ConstValues.A_NAME);
			var boneData:BoneData = armatureData.getBoneData(boneName);
			var parentMovementBoneXML:Xml = getElementsByAttribute(movementBoneXMLList, ConstValues.A_NAME, boneData.parent)[0];
			var movementBoneData:MovementBoneData = movementData.getMovementBoneData(boneName);
			if(movementBoneXML != null) {
				if(movementBoneData != null) {
					parseMovementBoneData(movementBoneXML, parentMovementBoneXML, boneData, movementBoneData);
				} else {
					movementBoneData = new MovementBoneData();
					parseMovementBoneData(movementBoneXML, parentMovementBoneXML, boneData, movementBoneData);
					movementData._movementBoneDataList.addData(movementBoneData, boneName);
				}
			}
			
			var index:Int = Lambda.indexOf(boneNames, boneName);
			if(index >= 0) {
				boneNames.splice(index, 1);
			}
		}
		
		for (boneName in boneNames) {
			movementData._movementBoneDataList.addData(MovementBoneData.HIDE_DATA, boneName);
		}
		
		var movementFrameXMLList:Iterator<Xml> = movementXML.elementsNamed(ConstValues.FRAME);
		var movementFrameList:Array<MovementFrameData> = movementData._movementFrameList;
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
		movementBoneData.setValues(cast(movementBoneXML.get(ConstValues.A_MOVEMENT_SCALE), Float),cast(movementBoneXML.get(ConstValues.A_MOVEMENT_DELAY), Float));
		
		var i:UInt = 0;
		var parentTotalDuration:UInt = 0;
		var totalDuration:UInt = 0;
		var currentDuration:UInt = 0;
		if(parentMovementBoneXML != null) {
			var parentFrameXMLList:Iterator<Xml> = parentMovementBoneXML.elementsNamed(ConstValues.FRAME);
			var parentFrameCount:UInt = Lambda.count(parentFrameXMLList,);
			var parentFrameXML:Xml;
		}
		
		var frameXMLList:Iterator<Xml> = movementBoneXML.elementsNamed(ConstValues.FRAME);
		var frameCount:UInt = Lambda.count(frameXMLList);
		var frameList:Array<FrameData> = movementBoneData.frameList;
		
		for(j in 0 ... frameCount) {
			var frameXML:Xml = frameXMLList[j];
			var frameData:FrameData = frameList.length > j ? frameList[j] : null;
			
			if(frameData != null) {
				parseFrameData(frameXML, frameData);
			} else {
				frameData = new FrameData();
				parseFrameData(frameXML, frameData);
				if(!Lambda.has(frameList, frameData)) {
					frameList.push(frameData);
				}
			}
			
			if(parentMovementBoneXML) {
				while((i < parentFrameCount) && (parentFrameXML ? (totalDuration < parentTotalDuration || totalDuration >= parentTotalDuration + currentDuration):true)) {
					parentFrameXML = parentFrameXMLList[i];
					parentTotalDuration += currentDuration;
					currentDuration = int(parentFrameXML.attribute(ConstValues.A_DURATION));
					i++;
				}
				
				parseFrameData(parentFrameXML, _helpFrameData);
				
				var tweenFrameXML:Xml = parentFrameXMLList[i];
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
					_helpFrameData.node.x + progress * _helpNode.x,
					_helpFrameData.node.y + progress * _helpNode.y,
					_helpFrameData.node.skewX + progress * _helpNode.skewX,
					_helpFrameData.node.skewY + progress * _helpNode.skewY,
					_helpFrameData.node.scaleX + progress * _helpNode.scaleX,
					_helpFrameData.node.scaleY + progress * _helpNode.scaleY,
					_helpFrameData.node.pivotX + progress * _helpNode.pivotX,
					_helpFrameData.node.pivotY + progress * _helpNode.pivotY
				);
				
				TransformUtils.transformPointWithParent(frameData.node, _helpNode);
			}
			totalDuration += cast(frameXML.get(ConstValues.A_DURATION), Int);
			
			frameData.node.x -= boneData.node.x;
			frameData.node.y -= boneData.node.y;
			frameData.node.skewX -= boneData.node.skewX;
			frameData.node.skewY -= boneData.node.skewY;
			frameData.node.scaleX -= boneData.node.scaleX;
			frameData.node.scaleY -= boneData.node.scaleY;
			frameData.node.pivotX -= boneData.node.pivotX;
			frameData.node.pivotY -= boneData.node.pivotY;
			frameData.node.z -= boneData.node.z;
		}
	}
	
	static function parseMovementFrameData(movementFrameXML:Xml, movementFrameData:MovementFrameData) {
		movementFrameData.setValues(
			cast(movementFrameXML.get(ConstValues.A_DURATION), Float) / _currentSkeletonData.frameRate,
			movementFrameXML.get(ConstValues.A_MOVEMENT),
			movementFrameXML.get(ConstValues.A_EVENT),
			movementFrameXML.get(ConstValues.A_SOUND)
		);
	}
	
	static function parseFrameData(frameXML:Xml, frameData:FrameData) {
		parseNode(frameXML, frameData.node);
		if (_currentSkeletonData != null) {
			var colorTransformXML:Xml = frameXML.elementsNamed(ConstValues.COLOR_TRANSFORM)[0];
			if(colorTransformXML != null) {
				parseColorTransform(colorTransformXML, frameData.colorTransform);
			}
			frameData.duration = Std.parseInt(frameXML.get(ConstValues.A_DURATION)) / _currentSkeletonData._frameRate;
			frameData.tweenEasing = Std.parseFloat(frameXML.get(ConstValues.A_TWEEN_EASING));
			frameData.tweenRotate = Std.parseInt(frameXML.get(ConstValues.A_TWEEN_ROTATE));
			frameData.displayIndex = Std.parseInt(frameXML.get(ConstValues.A_DISPLAY_INDEX));
			frameData.movement = frameXML.get(ConstValues.A_MOVEMENT);
			
			frameData.event = frameXML.get(ConstValues.A_EVENT);
			frameData.sound = frameXML.get(ConstValues.A_SOUND);
			frameData.soundEffect = frameXML.get(ConstValues.A_SOUND_EFFECT);
			
			var visibleStr:String = frameXML.get(ConstValues.A_VISIBLE);
			frameData.visible = (visibleStr == "1" || visibleStr =="");
		}
	}
	
	static function parseNode(xml:Xml, node:Node) {
		node.x = Std.parseFloat(xml.get(ConstValues.A_X));
		node.y = Std.parseFloat(xml.get(ConstValues.A_Y));
		node.skewX = Std.parseFloat(xml.get(ConstValues.A_SKEW_X)) * ANGLE_TO_RADIAN;
		node.skewY = Std.parseFloat(xml.get(ConstValues.A_SKEW_Y)) * ANGLE_TO_RADIAN;
		node.scaleX = Std.parseFloat(xml.get(ConstValues.A_SCALE_X));
		node.scaleY = Std.parseFloat(xml.get(ConstValues.A_SCALE_Y));
		node.pivotX =  Std.parseFloat(xml.get(ConstValues.A_PIVOT_X));
		node.pivotY =  Std.parseFloat(xml.get(ConstValues.A_PIVOT_Y));
		node.z = Std.parseFloat(xml.get(ConstValues.A_Z));
	}
	
	static function parseColorTransform(xml:Xml, colorTransform:ColorTransform) {
		colorTransform.alphaOffset = Std.parseInt(xml.get(ConstValues.A_ALPHA));
		colorTransform.redOffset = Std.parseInt(xml.get(ConstValues.A_RED));
		colorTransform.greenOffset = Std.parseInt(xml.get(ConstValues.A_GREEN));
		colorTransform.blueOffset = Std.parseInt(xml.get(ConstValues.A_BLUE));
		colorTransform.alphaMultiplier = Std.parseInt(xml.get(ConstValues.A_ALPHA_MULTIPLIER)) * 0.01;
		colorTransform.redMultiplier = Std.parseInt(xml.get(ConstValues.A_RED_MULTIPLIER)) * 0.01;
		colorTransform.greenMultiplier = Std.parseInt(xml.get(ConstValues.A_GREEN_MULTIPLIER)) * 0.01;
		colorTransform.blueMultiplier = Std.parseInt(xml.get(ConstValues.A_BLUE_MULTIPLIER)) * 0.01;
	}
	
}