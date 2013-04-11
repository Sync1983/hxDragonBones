package ;

import dragonbones.Armature;
import dragonbones.factorys.StarlingFactory;
import nme.Assets;
import starling.core.Starling;
import starling.display.Sprite;

/**
 * @author SlavaRa
 */
class StarlingTestView extends Sprite {

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
		
		#if debug
		for (i in 0...1) {
		#else
		for (i in 0...200) {
		#end
			var armature:Armature = factory.buildArmature("CharacterAnimations");
			var display:Sprite = cast(armature.displayContainer, Sprite);
			display.x = (i % columnNum) * paddingWidth + paddingLeft + ((i / columnNum) % 2) * Dx;
			display.y = ((i / columnNum)) * paddingHeight + paddingTop;
			armature.animation.gotoAndPlay("Idle", -1, -1, true);
			addChild(display);
			Starling.juggler.add(armature);
		}
	}
}