package;

import com.fermmmtools.debug.Stats;
import haxe.Log;
import dragonbones.animation.WorldClock;
import dragonbones.Armature;
import dragonbones.factorys.BaseFactory;
import dragonbones.utils.IDisposable;
import nme.Assets;
import nme.display.FPS;
import nme.display.InterpolationMethod;
import nme.display.Sprite;
import nme.display.StageAlign;
import nme.display.StageScaleMode;
import nme.events.Event;
import nme.Lib;
import nme.utils.Timer;
#if flash11
import dragonbones.factorys.StarlingFactory;
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
	
	#if !flash
	var factory:BaseFactory;
	#end
	
	function setupStage() {
		Lib.current.stage.align = StageAlign.TOP_LEFT;
		Lib.current.stage.scaleMode = StageScaleMode.NO_SCALE;
	}
	
	function addListeners() {
		addEventListener(Event.ADDED_TO_STAGE, onStageAddedToStage);
	}
	
	function onStageAddedToStage(_) {
		removeEventListener(Event.ADDED_TO_STAGE, onStageAddedToStage);
		#if ios
		haxe.Timer.delay(initialize, 100); // iOS 6
		#else
		initialize();
		#end
	}
	
	function initialize() {
		Lib.current.addChild(new Stats());
		#if flash11
		new Starling(TestView, Lib.current.stage).start();
		#else
		factory = new BaseFactory();
		factory.onDataParsed.bindVoid(onFactoryDataParsed);
		factory.parseData(Assets.getBytes("assets/img/character_output_bin"));
		#end
	}
	
	#if !flash11
	function onFactoryDataParsed() {
		var columnNum:Int = 15;
		var paddingWidth:Int = 50;
		var paddingHeight:Int = 20;
		var paddingLeft:Int = 25;
		var paddingTop:Int = 200;
		var Dx:Int = 25;
		
		for (i in 0 ... 1) {
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
		WorldClock.instance.advanceTime();
	}
	#end
}

#if flash11
class TestView extends starling.display.Sprite {
	
	public function new() {
		super();
		factory = new StarlingFactory();
		factory.onDataParsed.bindVoid(onFactoryDataParsed);
		factory.parseData(Assets.getBytes("assets/img/character_output_bin"));
	}
	
	var factory:StarlingFactory;
	
	function onFactoryDataParsed():Void  {
		var columnNum:Int = 10;
		var paddingWidth:Int = 50;
		var paddingHeight:Int = 20;
		var paddingLeft:Int = 25;
		var paddingTop:Int = 100;
		var Dx:Int = 25;
		
		//for (i in 0 ... 1000) {
		for (i in 0 ... 250) {
		//for (i in 0 ... 1) {
			var armature:Armature = factory.buildArmature("CharacterAnimations");
			var display:starling.display.Sprite = cast(armature.display, starling.display.Sprite);
			display.x = (i % columnNum) * paddingWidth + paddingLeft + ((i / columnNum) % 2) * Dx;
			display.y = ((i / columnNum)) * paddingHeight + paddingTop;
			armature.animation.gotoAndPlay("Idle", -1, -1, true);
			addChild(display);
			//WorldClock.instance.add(armature);
			Starling.juggler.add(armature);
		}
		//addEventListener(starling.events.Event.ENTER_FRAME, onEnterFrame);
	}
	
	//function onEnterFrame(_) {
		//WorldClock.instance.advanceTime();
	//}
	
}
#end