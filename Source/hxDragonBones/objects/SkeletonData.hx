package hxDragonBones.objects;
import nme.Lib;

/**
 * @author SlavaRa
 */
class SkeletonData{

	public function new() {
		armatureDataList = new DataList();
		animationDataList = new DataList();
		displayDataList = new DataList();
	}
	
	public var name:String;
	public var frameRate:Int;
	public var armatureNames(get_armatureNames, null):Array<String>;
	public var animationNames(get_animationNames, null):Array<String>;
	public var armatureDataList:DataList;
	public var animationDataList:DataList;
	public var displayDataList:DataList;
	
	function get_armatureNames():Array<String> {
		return armatureDataList.dataNames.slice(0);
	}
	
	function get_animationNames():Array<String> {
		return animationDataList.dataNames.slice(0);
	}
	
	public function dispose() {
		for (armatureName in armatureDataList.dataNames) {
			cast(armatureDataList.getData(armatureName), ArmatureData).dispose();
		}
		
		for (animationName in animationDataList.dataNames) {
			cast(animationDataList.getData(animationName), AnimationData).dispose();
		}
		
		armatureDataList.dispose();
		animationDataList.dispose();
		displayDataList.dispose();
	}
	
	public function getArmatureData(name:String):ArmatureData {
		return cast(armatureDataList.getData(name), ArmatureData);
	}
	
	public function getAnimationData(name:String):AnimationData {
		return cast(animationDataList.getData(name), AnimationData);
	}
	
	public function getDisplayData(name:String):DisplayData {
		return cast(displayDataList.getData(name), DisplayData);
	}
}