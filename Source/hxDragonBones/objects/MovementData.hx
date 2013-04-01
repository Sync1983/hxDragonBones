package hxDragonBones.objects;

/**
 * @author SlavaRa
 */
class MovementData{

	public function new() {
		duration = 0;
		durationTo = 0;
		durationTween = 0;
		
		_movementBoneDataList = new DataList();
		_movementFrameList = [];
	}
	
	var _movementBoneDataList:DataList;
	var _movementFrameList:Array<MovementFrameData>;
	
	public var duration:Float;
	public var durationTo:Float;
	public var durationTween:Float;
	public var loop:Bool;
	public var tweenEasing:Float;
	
	public function dispose() {
		for (movementBoneName in _movementBoneDataList.dataNames) {
			var movementBoneData:MovementBoneData = cast(_movementBoneDataList.getData(movementBoneName), MovementBoneData);
			movementBoneData.dispose();
		}
		
		_movementBoneDataList.dispose();
		_movementFrameList = [];
	}
	
	public function getMovementBoneData(name:String):MovementBoneData {
		return cast(_movementBoneDataList.getData(name), MovementBoneData);
	}
}