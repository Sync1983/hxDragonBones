package dragonbones.objects;
import nme.geom.ColorTransform;
import dragonbones.objects.Node;

/**
 * @author SlavaRa
 */
class FrameData{

	public function new() {
		duration = 0;
		tweenEasing = 0;
		node = new HelpNode();
		colorTransform = new ColorTransform();
		visible = true;
	}
	
	public var duration:Float;
	public var tweenEasing:Float;
	public var displayIndex:Int;
	public var movement:String;
	public var visible:Bool;
	public var event:String;
	public var sound:String;
	public var soundEffect:String;
	public var node:HelpNode;
	public var colorTransform:ColorTransform;
	
	public function toString():String {
		return duration + ";" + tweenEasing + ";" + movement;
	}
}