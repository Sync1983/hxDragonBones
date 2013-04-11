package dragonbones.utils;

/**
 * @author SlavaRa
 */
class MathUtils {

	public static inline function sin(x:Float):Float {
		return x - x*x*x/6;
	}

	public static inline function cos(x:Float):Float {
		return 1 - x*x/2;
	}
	
}