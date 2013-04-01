package hxDragonBones.objects;

/**
 * @author SlavaRa
 */
class ArmatureData{

	public function new() {
		boneDataList = new DataList();
	}
	
	public var boneNames(get_boneNames, null):Array<String>;
	public function get_boneNames():Array<String> {
		return boneDataList.dataNames.concat();
	}
	
	public var boneDataList:DataList;
	
	public function dispose() {
		for (boneName in boneDataList.dataNames) {
			var boneData:BoneData = cast(boneDataList.getData(boneName), BoneData);
			boneData.dispose();
		}
		
		boneDataList.dispose();
	}
	
	public function getBoneData(name:String):BoneData {
		return cast(boneDataList.getData(name), BoneData);
	}
	
	public function updateBoneList() {
		var boneNames:Array<String> = boneDataList.dataNames;
		
		var sortList:Array<Dynamic> = [];
		for (boneName in boneNames) {
			var boneData:BoneData = cast(boneDataList.getData(boneName), BoneData);
			var levelValue:Int = cast(boneData.node.z, Int);
			var level:Int = 0;
			while(boneData != null) {
				level++;
				levelValue += 1000 * level;
				boneData = getBoneData(boneData.parent);
			}
			sortList.push({level:levelValue, boneName:boneName});
		}
		
		var length:Int = sortList.length;
		if (length > 0) {
			sortList.sort(function(a, b) return Reflect.compare(a.level, b.level));
			boneNames = [];
			var i:Int = 0;
			while(i < length) {
				boneNames[i] = sortList[i].boneName;
				i++;
			}
		}
	}
}