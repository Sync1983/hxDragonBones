package hxDragonBones.objects;

/**
 * @author SlavaRa
 */
class DataList{

	public function new() {
		dispose();
	}
	
	public var names:Array<String>;
	var _name2Data:Hash<Dynamic>;
	
	public function dispose() {
		_name2Data = new Hash<Dynamic>();
		names = [];
	}
	
	public function getData(name:String):Dynamic {
		return _name2Data.exists(name) ? _name2Data.get(name) : null;
	}
	
	public function getDataAt(index:Int):Dynamic {
		return getData(names[index]);
	}
	
	public function addData(data:Dynamic, name:String) {
		if ((data == null) || (name == null)) {
			return;
		}
		_name2Data.set(name, data);
		if(!Lambda.has(names, name)) {
			names.push(name);
		}
	}
	
	public function removeData(data:Dynamic) {
		if (data == null) {
			return;
		}
		for(name in _name2Data) {
			if(_name2Data.get(name) == data) {
				removeDataByName(name);
				return;
			}
		}
	}
	
	public function removeDataByName(name:String) {
		if (_name2Data.exists(name)) {
			_name2Data.remove(name);
			names.splice(Lambda.indexOf(names, name), 1);
		}
	}
}