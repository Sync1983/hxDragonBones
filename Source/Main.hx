package;

import hxDragonBones.Armature;
import hxDragonBones.factorys.BaseFactory;
import hxDragonBones.factorys.StarlingFactory;
import nme.Assets;
import nme.display.BitmapData;
import nme.display.Sprite;
import nme.display.StageAlign;
import nme.display.StageScaleMode;
import nme.events.Event;
import nme.Lib;
import nme.utils.ByteArray;

/**
 * @author SlavaRa
 */
class Main extends Sprite {
	// CLASS PROPERTIES --------------------------------------------------------------------/
	// CLASS METHODS -----------------------------------------------------------------------/
	// CONSTRUCTOR -------------------------------------------------------------------------/
	
	public function new() {
		super();
		setupStage();
		addListeners();
	}
	
	// OVERRIDEN PROPERTIES ----------------------------------------------------------------/
	// OVERRIDEN METHODS -------------------------------------------------------------------/
	// IMPLEMENTED METHODS -----------------------------------------------------------------/
	// PUBLIC PROPERTIES -------------------------------------------------------------------/
	// PUBLIC METHODS ----------------------------------------------------------------------/
	// PRIVATE PROPERTIES ------------------------------------------------------------------/
	
	var _isInitialized:Bool;
	
	// PRIVATE METHODS ---------------------------------------------------------------------/
	
	function setupStage() {
		Lib.current.stage.align = StageAlign.TOP_LEFT;
		Lib.current.stage.scaleMode = StageScaleMode.NO_SCALE;
	}
	
	function addListeners() {
		addEventListener(Event.ADDED_TO_STAGE, onStageAddedToStage);
		Lib.current.stage.addEventListener(Event.ACTIVATE, onStageActivate);
		Lib.current.stage.addEventListener(Event.DEACTIVATE, onStageDeactivate);
	}
	
	function initialize() {
		if (_isInitialized) {
			return;
		}
		_isInitialized = true;
		
		var factory:BaseFactory = new BaseFactory();
		factory.addEventListener(Event.COMPLETE, onFactoryComplete);
		factory.parseData(Assets.getBytes("assets/img/character_output_bin"));
	}
	
	// EVENT HANDLERS ----------------------------------------------------------------------/
	
	function onFactoryComplete(event:Event) {
		var factory:BaseFactory = cast(event.currentTarget, BaseFactory);
		var armature:Armature = factory.buildArmature("CharacterAnimations");
		Lib.trace("armature: " + armature);
	}
	
	function onStageAddedToStage(event:Event) {
		removeEventListener(Event.ADDED_TO_STAGE, onStageAddedToStage);
		Lib.current.stage.addEventListener(Event.RESIZE, onStageResize);
		#if ios
		haxe.Timer.delay(init, 100); // iOS 6
		#else
		initialize();
		#end
	}
	
	function onStageActivate(event:Event) {
	}
	
	function onStageDeactivate(event:Event) {
	}
	
	function onStageResize(event:Event) {
	}
	
	// ACCESSORS ---------------------------------------------------------------------------/
}