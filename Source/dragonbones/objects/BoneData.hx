package dragonbones.objects;
import dragonbones.utils.IDisposable;

/**
 * @author SlavaRa
 */
class BoneData implements IDisposable{

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