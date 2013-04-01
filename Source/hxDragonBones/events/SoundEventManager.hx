package hxDragonBones.events;
import nme.events.EventDispatcher;

/**
 * @author SlavaRa
 */

class SoundEventManager extends EventDispatcher {
	
	public static var instance(get_instance, null):SoundEventManager;
	
	static function get_instance():SoundEventManager {
		if (instance == null) {
			instance = new SoundEventManager();
		}
		return instance;
	}
	
	function new() {
	}
	
}