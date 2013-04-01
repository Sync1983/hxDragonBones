package hxDragonBones.objects;

/**
 * @author SlavaRa
 */
class AnimationData{

	public function new() {
		_movementDataList = new DataList();
	}
	
	public var movementList(get_movementList, null):Array<String>;
	
	function get_movementList():Array<String> {
		return _movementDataList.dataNames.concat();
	}
	
	var _movementDataList:DataList;
	
	public function dispose() {
		for (movementName in movementDataList.dataNames) {
			var movementData:MovementData = cast(_movementDataList.getData(movementName), MovementData);
			movementData.dispose();
		}
		
		_movementDataList.dispose();
	}
	
	public function getMovementData(name:String):MovementData {
		return cast(_movementDataList.getData(name), MovementData);
	}
	
}