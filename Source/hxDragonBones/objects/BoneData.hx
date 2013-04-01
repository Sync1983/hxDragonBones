package hxDragonBones.objects;

/**
 * @author SlavaRa
 */
class BoneData{

	public function new() {
		displayNames = [];
		node = new Node();
	}
	
	public var parent:String;
	public var node:Node;
	public var displayNames:Array<String>;
	
	public function dispose() {
		displayNames = [];
	}
	
}