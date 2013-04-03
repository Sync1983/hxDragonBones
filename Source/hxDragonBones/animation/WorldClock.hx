package hxDragonBones.animation;
import hxDragonBones.animation.IAnimatable;
import nme.Lib;

/**
 * @author SlavaRa
 */
class WorldClock implements IAnimatable {
	public static var clock:WorldClock = new WorldClock();
	
	public function new() {
		time = Lib.getTimer() * 0.001;
		timeScale = 1;
		_animatableList = [];
	}
	
	public var time(default, null):Float;
	public var timeScale(default, set_timeScale):Float;
	
	function set_timeScale(value:Float):Float {
		if(value < 0) {
			value = 0;
		}
		timeScale = value;
		return value;
	}
	
	var _animatableList:Array<IAnimatable>;
	var _time:Float;
	
	public function has(animatable:IAnimatable):Bool {
		return Lambda.has(_animatableList, animatable);
	}
	
	public function add(animatable:IAnimatable) {
		if((animatable != null) && !Lambda.has(_animatableList, animatable)) {
			_animatableList.push(animatable);
		}
	}
	
	public function remove(animatable:IAnimatable) {
		var index:Int = Lambda.indexOf(_animatableList, animatable);
		if(index >= 0) {
			_animatableList[index] = null;
		}
	}
	
	public function clear() {
		_animatableList = [];
	}
	
	public function advanceTime(passedTime:Float):Void {
		if(passedTime < 0) {
			var currentTime:Float = Lib.getTimer() * 0.001;
			passedTime = currentTime - time;
			time = currentTime;
		}
		
		passedTime *= timeScale;
		
		var length:Int = _animatableList.length;
		if (length == 0) {
			return;
		}
		var currentIndex:Int = 0;
		var tmpI:Int = length;
		
		for(i in 0 ... length) {
			var animatable:IAnimatable = _animatableList[i];
			if (animatable != null){
				if (currentIndex != i) {
					_animatableList[currentIndex] = animatable;
					_animatableList[i] = null;
				}
				animatable.advanceTime(passedTime);
				currentIndex++;
			}
			tmpI = i;
		}
		
		if (currentIndex != tmpI) {
			length = _animatableList.length;
			while (tmpI < length) {
				_animatableList[currentIndex++] = _animatableList[tmpI++];
			}
			_animatableList = _animatableList.splice(0, currentIndex);
		}
	}
}