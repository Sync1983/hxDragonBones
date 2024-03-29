package dragonbones.objects;
import dragonbones.utils.IDisposable;
import dragonbones.objects.Node;

/**
 * @author SlavaRa
 */
class BoneData implements IDisposable{

	public function new() {
		displayNames = [];
		node = Node.create();
	}
	
	public var parent:String;//TODO: name?
	public var node:HelpNode;
	public var displayNames:Array<String>;
	
	public function dispose() {
		displayNames = null;
		node = null;
	}
	
}