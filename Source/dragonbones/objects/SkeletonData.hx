package dragonbones.objects;
import dragonbones.utils.DisposeUtils;
import dragonbones.utils.IDisposable;

/**
 * @author SlavaRa
 */
class SkeletonData implements IDisposable{

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
		for (name in armatureDataList.names) {
			DisposeUtils.dispose(armatureDataList.getDataByName(name));
		}
		for (name in animationDataList.names) {
			DisposeUtils.dispose(animationDataList.getDataByName(name));
		}
		DisposeUtils.dispose(armatureDataList);
		DisposeUtils.dispose(animationDataList);
		DisposeUtils.dispose(displayDataList);
	}
	
	public function getArmatureData(name:String):ArmatureData {
		return cast armatureDataList.getDataByName(name);
	}
	
	public function getAnimationData(name:String):AnimationData {
		return cast animationDataList.getDataByName(name);
	}
	
	public function getDisplayData(name:String):DisplayData {
		return cast displayDataList.getDataByName(name);
	}
}