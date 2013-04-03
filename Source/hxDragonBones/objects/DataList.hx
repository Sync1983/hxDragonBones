package hxDragonBones.objects;

import haxe.Log;
import nme.ObjectHash;

/**
 * @author SlavaRa
 */
class DataList{

	public function new() {
		_dataDic = new ObjectHash<String, Dynamic>();
		dataNames = [];
	}
	
	public var dataNames:Array<String>;
	var _dataDic:ObjectHash<String, Dynamic>;
	
	public function dispose() {
		_dataDic = new ObjectHash<String, Dynamic>();
		dataNames = [];
	}
	
	public function getData(dataName:String):Dynamic {
		return _dataDic.get(dataName);
	}
	
	public function getDataAt(index:Int):Dynamic {
		return _dataDic.get(dataNames[index]);
	}
	
	public function addData(data:Dynamic, dataName:String) {
		if((data != null) && (dataName != null)) {
			_dataDic.set(dataName, data);
			if(!Lambda.has(dataNames, dataName)) {
				dataNames.push(dataName);
			}
		}
	}
	
	public function removeData(data:Dynamic) {
		if(data != null) {
			for(dataName in _dataDic) {
				if(_dataDic.get(dataName) == data) {
					removeDataByName(dataName);
					return;
				}
			}
		}
	}
	
	public function removeDataByName(dataName:String) {
		var data:Dynamic = _dataDic.get(dataName);
		if (data != null) {
			_dataDic.remove(dataName);
			dataNames.splice(Lambda.indexOf(dataNames, dataName), 1);
		}
	}
}