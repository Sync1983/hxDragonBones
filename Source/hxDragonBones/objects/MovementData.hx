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
		for (movementBoneName in movementBoneDataList.names) {
			var d:Dynamic = movementBoneDataList.getData(movementBoneName);
			if (Std.is(d, MovementBoneData)) {
				cast(d, MovementBoneData).dispose();
			}
		}
		
		movementBoneDataList.dispose();
		movementFrameList = [];
	}
	
	public function getMovementBoneData(name:String):MovementBoneData {
		var d:Dynamic = movementBoneDataList.getData(name);
		return Std.is(d, MovementBoneData) ? cast(d, MovementBoneData) : null;
	}
}