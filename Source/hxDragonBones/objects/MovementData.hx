package hxDragonBones.objects;

/**
 * @author SlavaRa
 */
class MovementData{

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
		for (movementBoneName in movementBoneDataList.dataNames) {
			var movementBoneData:MovementBoneData = cast(movementBoneDataList.getData(movementBoneName), MovementBoneData);
			movementBoneData.dispose();
		}
		
		movementBoneDataList.dispose();
		movementFrameList = [];
	}
	
	public function getMovementBoneData(name:String):MovementBoneData {
		return cast(movementBoneDataList.getData(name), MovementBoneData);
	}
}