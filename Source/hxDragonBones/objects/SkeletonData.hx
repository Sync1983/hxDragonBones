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
		return armatureDataList.names.slice(0);
	}
	
	function get_animationNames():Array<String> {
		return animationDataList.names.slice(0);
	}
	
	public function dispose() {
		for (armatureName in armatureDataList.names) {
			var data:Dynamic = armatureDataList.getData(armatureName);
			if (Std.is(data, ArmatureData)) {
				cast(data, ArmatureData).dispose();
			}
		}
		
		for (animationName in animationDataList.names) {
			var data:Dynamic = animationDataList.getData(animationName);
			if (Std.is(data, AnimationData)) {
				cast(data, AnimationData).dispose();
			}
		}
		
		armatureDataList.dispose();
		animationDataList.dispose();
		displayDataList.dispose();
	}
	
	public function getArmatureData(name:String):ArmatureData {
		var d:Dynamic = armatureDataList.getData(name);
		return Std.is(d, ArmatureData) ? cast(d, ArmatureData) : null;
	}
	
	public function getAnimationData(name:String):AnimationData {
		var d:Dynamic = animationDataList.getData(name);
		return Std.is(d, AnimationData) ? cast(d, AnimationData) : null;
	}
	
	public function getDisplayData(name:String):DisplayData {
		var d:Dynamic = displayDataList.getData(name);
		return Std.is(d, DisplayData) ? cast(d, DisplayData) : null;
	}
}