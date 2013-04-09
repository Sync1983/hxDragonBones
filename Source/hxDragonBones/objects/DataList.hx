package hxDragonBones.objects;
import hxDragonBones.utils.IDisposable;
import nme.ObjectHash;

/**
 * @author SlavaRa
 */
class DataList implements IDisposable {

	public function new() {
		_data2name = new ObjectHash<Dynamic, String>();
		_name2data = new Hash<Dynamic>();
		names = [];
	}
	
	public var names:Array<String>;
	var _name2data:Hash<Dynamic>;
	var _data2name:ObjectHash<Dynamic, String>;
	
	public function dispose() {
		_data2name = null;
		_name2data = null;
		names = null;
	}
	
	public function getDataByName(name:String):Dynamic {
		return _name2data.get(name);
	}
	
	public function addData(data:Dynamic, name:String) {
		if ((data == null) || (name == null)) {
			return;
		}
		_name2data.set(name, data);
		_data2name.set(data, name);
		names.push(name);
	}
	
	public function removeData(data:Dynamic) {
		if (data == null) {
			return;
		}
		removeDataByName(_data2name.get(data));
		_data2name.remove(data);
	}
	
	public function removeDataByName(name:String) {
		if (name == null) {
			return;
		}
		_name2data.remove(name);
		names.remove(name);
	}
}