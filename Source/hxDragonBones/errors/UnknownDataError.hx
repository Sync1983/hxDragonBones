package hxDragonBones.errors;

import nme.errors.Error;

/**
 * @author SlavaRa
 */
class UnknownDataError extends Error{

	public function new(?message:Dynamic, id:Dynamic = 0) {
		super(message, id);
	}
	
}