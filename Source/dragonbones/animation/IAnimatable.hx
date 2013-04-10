package dragonbones.animation;

/**
 * @author SlavaRa
 */
interface IAnimatable {
	function advanceTime(passedTime:Float = -1):Void;
}