package hxDragonBones.events;

import hxDragonBones.Armature;
import hxDragonBones.Bone;
import nme.events.Event;

/**
 * @author SlavaRa
 */
class SoundEvent extends Event{

	public static inline var SOUND:String = "sound";
	
	public function new(type:String, cancelable:Bool = false) {
		super(type, false, cancelable);
	}
	
	public var movementID:String;
	public var sound:String;
	public var soundEffect:String;
	public var armature(default, null):Armature;
	public var bone(default, null):Bone;
	
	public override function clone():Event {
		var event:SoundEvent = new SoundEvent(type, cancelable);
		event.movementID = movementID;
		event.sound = sound;
		event.soundEffect = soundEffect;
		event.armature = armature;
		event.bone = bone;
		return event;
	}
}