package;

import com.fermmmtools.debug.Stats;
import nme.display.Sprite;
import nme.display.StageAlign;
import nme.display.StageScaleMode;
import nme.events.Event;
import nme.Lib;
import nme.utils.Timer;
import starling.core.Starling;

/**
 * @author SlavaRa
 */
class Main extends Sprite {
	
	public function new() {
		super();
		Lib.current.stage.align = StageAlign.TOP_LEFT;
		Lib.current.stage.scaleMode = StageScaleMode.NO_SCALE;
		addEventListener(Event.ADDED_TO_STAGE, onStageAddedToStage);
	}
	
	function onStageAddedToStage(_) {
		removeEventListener(Event.ADDED_TO_STAGE, onStageAddedToStage);
		#if ios
		haxe.Timer.delay(initialize, 100);// iOS 6
		#else
		initialize();
		#end
	}
	
	function initialize() {
		addChild(new Stats());
		#if flash11
		new Starling(StarlingTestView, Lib.current.stage).start();
		#else
		cast(addChild(new NMETestView()), NMETestView).start();
		#end
	}
}