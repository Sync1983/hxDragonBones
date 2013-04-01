package hxDragonBones.objects;

/**
 * @author SlavaRa
 */
class SkeletonData{

	public function new() {
		armatureDataList = new DataList();
		_animationDataList = new DataList();
		displayDataList = new DataList();
	}
	
	public var name:String;
	public var frameRate:UInt;
	public var armatureNames(get_armatureNames, null):Array<String>;
	public var animationNames(get_animationNames, null):Array<String>;
	public var armatureDataList:DataList;
	public var displayDataList:DataList;
	
	var _animationDataList:DataList;
	
	function get_armatureNames():Array<String> {
		return armatureDataList.dataNames.concat();
	}
	
	function get_animationNames():Array<String> {
		return _animationDataList.dataNames.concat();
	}
	
	public function dispose() {
		for (armatureName in armatureDataList.dataNames) {
			cast(armatureDataList.getData(armatureName), ArmatureData).dispose();
		}
		
		for (animationName in _animationDataList.dataNames) {
			cast(_animationDataList.getData(animationName), AnimationData).dispose();
		}
		
		armatureDataList.dispose();
		_animationDataList.dispose();
		displayDataList.dispose();
	}
	
	public function getArmatureData(name:String):ArmatureData {
		return cast(armatureDataList.getData(name), ArmatureData);
	}
	
	public function getAnimationData(name:String):AnimationData {
		return cast(_animationDataList.getData(name), AnimationData);
	}
	
	public function getDisplayData(name:String):DisplayData {
		return cast(displayDataList.getData(name), DisplayData);
	}
}