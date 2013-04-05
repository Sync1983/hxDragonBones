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
			cast(movementDataList.getData(name), MovementData).dispose();
		}
		movementDataList.dispose();
	}
	
	public function getMovementData(name:String):MovementData {
		return cast(movementDataList.getData(name), MovementData);
	}
	
}