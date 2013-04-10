package dragonbones.objects;
import dragonbones.utils.DisposeUtils;
import dragonbones.utils.IDisposable;

/**
 * @author SlavaRa
 */
class AnimationData implements IDisposable {

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
			DisposeUtils.dispose(movementDataList.getDataByName(name));
		}
		DisposeUtils.dispose(movementDataList);
	}
	
	public function getMovementData(name:String):MovementData {
		return cast movementDataList.getDataByName(name);
	}
	
}