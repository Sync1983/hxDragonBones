package hxDragonBones.objects;
import hxDragonBones.utils.DisposeUtils;
import hxDragonBones.utils.IDisposable;

/**
 * @author SlavaRa
 */
class ArmatureData implements IDisposable{

	public function new() {
		boneDataList = new DataList();
	}
	
	public var boneNames(get_boneNames, null):Array<String>;
	function get_boneNames():Array<String> {
		return boneDataList.names.slice(0);
	}
	
	public var boneDataList:DataList;
	
	public function dispose() {
		for (name in boneDataList.names) {
			DisposeUtils.dispose(boneDataList.getDataByName(name));
		}
		DisposeUtils.dispose(boneDataList);
	}
	
	public function getBoneData(name:String):BoneData {
		return cast boneDataList.getDataByName(name);
	}
	
	public function updateBoneList() {
		var sortList:Array<Dynamic> = [];
		for (name in boneDataList.names) {
			var boneData:BoneData = cast boneDataList.getDataByName(name);
			if (boneData != null) {
				var levelValue:Int = Std.int(boneData.node.z);
				var level:Int = 0;
				while(boneData != null) {
					level++;
					levelValue += 1000 * level;
					boneData = getBoneData(boneData.parent);
				}
				sortList.push({level:levelValue, name:name});
			}
		}
		
		if (sortList.length > 0) {
			sortList.sort(compareLevel);
			boneDataList.names = [];
			for (item in sortList) {
				boneDataList.names.push(item.name);
			}
		}
	}
	
	function compareLevel(a,b):Int {
		return Reflect.compare(a.level, b.level);
	}
	
}