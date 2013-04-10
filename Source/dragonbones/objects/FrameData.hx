package dragonbones.objects;
import nme.geom.ColorTransform;

/**
 * @author SlavaRa
 */
class FrameData{

	public function new() {
		duration = 0;
		tweenEasing = 0;
		node = new Node();
		colorTransform = new ColorTransform();
		visible = true;
	}
	
	public var duration:Float;
	public var tweenEasing:Float;
	public var tweenRotate:Int;
	public var displayIndex:Int;
	public var movement:String;
	public var visible:Bool;
	public var event:String;
	public var sound:String;
	public var soundEffect:String;
	public var node:Node;
	public var colorTransform:ColorTransform;
}