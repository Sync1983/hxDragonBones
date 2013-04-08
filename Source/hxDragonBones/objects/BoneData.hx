package hxDragonBones.objects;

/**
 * @author SlavaRa
 */
class BoneData{

	public function new() {
		displayNames = [];
		node = new Node();
	}
	
	public var parent:String;//TODO: name?
	public var node:Node;
	public var displayNames:Array<String>;
	
	public function dispose() {
		displayNames = null;
		node = null;
	}
	
}