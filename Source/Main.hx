package;

import haxe.Log;
import hxDragonBones.animation.WorldClock;
import hxDragonBones.Armature;
import hxDragonBones.factorys.BaseFactory;
import nme.Assets;
import nme.display.FPS;
import nme.display.Sprite;
import nme.display.StageAlign;
import nme.display.StageScaleMode;
import nme.events.Event;
import nme.Lib;
import nme.utils.Timer;
#if flash11
import hxDragonBones.factorys.StarlingFactory;
import starling.core.Starling;
import starling.display.Sprite;
import starling.events.Event;
#end

/**
 * @author SlavaRa
 */
class Main extends Sprite {
	
	public function new() {
		super();
		setupStage();
		addListeners();
	}
	
	function setupStage() {
		Lib.current.stage.align = StageAlign.TOP_LEFT;
		Lib.current.stage.scaleMode = StageScaleMode.NO_SCALE;
	}
	
	function addListeners() {
		addEventListener(Event.ADDED_TO_STAGE, onStageAddedToStage);
	}
	
	function initialize() {
		addChild(new FPS(50, 50, 0xFFFFFF));
		
		#if flash11
		new Starling(TestView, Lib.current.stage).start();
		#else
		var factory:BaseFactory = new BaseFactory();
		factory.addEventListener(Event.COMPLETE, onFactoryComplete);
		factory.parseData(Assets.getBytes("assets/img/character_output_bin"));
		#end
	}
	
	function onFactoryComplete(event:Event) {
		var factory:BaseFactory = cast(event.currentTarget, BaseFactory);
		
		var columnNum:Int = 15;
		var paddingWidth:Int = 50;
		var paddingHeight:Int = 20;
		var paddingLeft:Int = 25;
		var paddingTop:Int = 200;
		var Dx:Int = 25;
		
		for (i in 0 ... 100) {
			var armature:Armature = factory.buildArmature("CharacterAnimations");
			var display:Sprite = cast(armature.display, nme.display.Sprite);
			display.x = (i % columnNum) * paddingWidth + paddingLeft + ((i / columnNum) % 2) * Dx;
			display.y = ((i / columnNum)) * paddingHeight + paddingTop;
			armature.animation.gotoAndPlay("Idle", -1, -1, true);
			addChild(display);
			WorldClock.instance.add(armature);
		}
		addEventListener(Event.ENTER_FRAME, onEnterFrame);
	}
	
	function onEnterFrame(_) {
		WorldClock.instance.advanceTime( -1);
	}
	
	function onStageAddedToStage(_) {
		removeEventListener(Event.ADDED_TO_STAGE, onStageAddedToStage);
		#if ios
		haxe.Timer.delay(initialize, 100); // iOS 6
		#else
		initialize();
		#end
	}
	
}

#if flash11
class TestView extends starling.display.Sprite {
	
	public function new() {
		super();
		var factory:StarlingFactory = new StarlingFactory();
		factory.addEventListener(Event.COMPLETE, onFactoryComplete);
		factory.parseData(Assets.getBytes("assets/img/character_output_bin"));
	}
	
	function onFactoryComplete(event:Event)  {
		var factory:StarlingFactory = cast(event.currentTarget, StarlingFactory);
		var columnNum:Int = 15;
		var paddingWidth:Int = 50;
		var paddingHeight:Int = 20;
		var paddingLeft:Int = 25;
		var paddingTop:Int = 300;
		var Dx:Int = 25;
		
		for (i in 0 ... 100) {
			var armature:Armature = factory.buildArmature("CharacterAnimations");
			var display:starling.display.Sprite = cast(armature.display, starling.display.Sprite);
			display.x = (i % columnNum) * paddingWidth + paddingLeft + ((i / columnNum) % 2) * Dx;
			display.y = ((i / columnNum)) * paddingHeight + paddingTop;
			armature.animation.gotoAndPlay("Idle", -1, -1, true);
			//armature.animation.stop();
			addChild(display);
			WorldClock.instance.add(armature);
		}
		addEventListener(starling.events.Event.ENTER_FRAME, onEnterFrame);
	}
	
	function onEnterFrame(_) {
		WorldClock.instance.advanceTime( -1);
	}
	
}
#end