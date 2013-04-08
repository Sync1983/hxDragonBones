package hxDragonBones.objects;
import haxe.Log;
import nme.Lib;

/**
 * @author SlavaRa
 */
class ArmatureData{

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
			var d:Dynamic = boneDataList.getData(name);
			if (Std.is(d, BoneData)) {
				cast(d, BoneData).dispose();
			}
		}
		
		boneDataList.dispose();
	}
	
	public function getBoneData(name:String):BoneData {
		var d:Dynamic = boneDataList.getData(name);
		return Std.is(d, BoneData) ? cast(d, BoneData) : null;
	}
	
	public function updateBoneList() {
		var sortList:Array<Dynamic> = [];
		for (name in boneDataList.names) {
			var d:Dynamic = boneDataList.getData(name);
			if (Std.is(d, BoneData)) {
				var boneData:BoneData = cast(d, BoneData);
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
			sortList.sort(function(a, b) return Reflect.compare(a.level, b.level));
			boneDataList.names = [];
			for (item in sortList) {
				boneDataList.names.push(item.name);
			}
		}
	}
	
}