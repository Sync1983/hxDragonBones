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
		return movementDataList.dataNames.slice(0);
	}
	
	
	public function dispose() {
		for (movementName in movementDataList.dataNames) {
			var movementData:MovementData = cast(movementDataList.getData(movementName), MovementData);
			movementData.dispose();
		}
		
		movementDataList.dispose();
	}
	
	public function getMovementData(name:String):MovementData {
		return cast(movementDataList.getData(name), MovementData);
	}
	
}