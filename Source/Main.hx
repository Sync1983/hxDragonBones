package;

import hxDragonBones.factorys.StarlingFactory;
import nme.display.Sprite;
import nme.display.StageAlign;
import nme.display.StageScaleMode;
import nme.events.Event;
import nme.Lib;

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
		
		var factory:StarlingFactory = new StarlingFactory();
		//factory.addEventListener(Event.COMPLETE, onFactoryComplete);
		//factory.parseData(Assets.getBytes("Assets/img/character_output.png"));
	}
	
	// EVENT HANDLERS ----------------------------------------------------------------------/
	
	function onFactoryComplete(event:Event) {
		
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