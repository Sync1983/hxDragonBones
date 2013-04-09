package hxDragonBones.objects;
import hxDragonBones.utils.IDisposable;

/**
 * @author SlavaRa
 */
class MovementBoneData implements IDisposable{

	public static var HIDE_DATA:MovementBoneData = new MovementBoneData();
	
	public function new() {
		scale = 1;
		delay = 0;
		frameList = [];
	}

	public var frameList:Array<FrameData>;
	public var scale:Float;
	public var delay:Float;
	
	public function dispose() {
		frameList = null;
	}
	
	public function setValues(scale:Float = 1, delay:Float = 0) {
		this.scale = (scale > 0) ? scale : 1;
		this.delay = (delay != 0) ? (delay % 1) : 0;
		if (this.delay > 0) {
			this.delay -= 1;
		}
		this.delay *= -1;
	}
}