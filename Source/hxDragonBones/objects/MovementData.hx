package hxDragonBones.objects;
import hxDragonBones.utils.DisposeUtils;
import hxDragonBones.utils.IDisposable;

/**
 * @author SlavaRa
 */
class MovementData implements IDisposable{

	public function new() {
		duration = 0;
		durationTo = 0;
		durationTween = 0;
		movementBoneDataList = new DataList();
		movementFrameList = [];
	}
	
	public var duration:Float;
	public var durationTo:Float;
	public var durationTween:Float;
	public var movementBoneDataList:DataList;
	public var movementFrameList:Array<MovementFrameData>;
	public var loop:Bool;
	public var tweenEasing:Float;
	
	public function dispose() {
		for (movementBoneName in movementBoneDataList.names) {
			DisposeUtils.dispose(movementBoneDataList.getDataByName(movementBoneName));
		}
		DisposeUtils.dispose(movementBoneDataList);
		movementFrameList = null;
	}
	
	public function getMovementBoneData(name:String):MovementBoneData {
		return cast movementBoneDataList.getDataByName(name);
	}
}