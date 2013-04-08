package hxDragonBones.objects;

/**
 * @author SlavaRa
 */
class AnimationData{

	public function new() {
		movementDataList = new DataList();
	}
	
	public var movementList(get_movementList, null):Array<String>;
	public var movementDataList:DataList;
	
	function get_movementList():Array<String> {
		return movementDataList.names.slice(0);
	}
	
	
	public function dispose() {
		for (name in movementDataList.names) {
			var d:Dynamic = movementDataList.getData(name);
			if (Std.is(d, MovementData)) {
				cast(d, MovementData).dispose();
			}
		}
		movementDataList.dispose();
	}
	
	public function getMovementData(name:String):MovementData {
		var d:Dynamic = movementDataList.getData(name);
		return Std.is(d, MovementData) ? cast(d, MovementData) : null;
	}
	
}