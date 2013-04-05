package hxDragonBones.utils;

import hxDragonBones.objects.Node;
import nme.geom.ColorTransform;
import nme.geom.Matrix;
import nme.geom.Point;

/**
 * @author SlavaRa
 */
class TransformUtils{
	static inline var DOUBLE_PI:Float = Math.PI * 2;
	
	static var _helpMatrix:Matrix = new Matrix();
	static var _helpPoint:Point = new Point();
	
	public static function transformPointWithParent(bone:Node, parent:Node) {
		nodeToMatrix(parent, _helpMatrix);
		
		_helpPoint.x = bone.x;
		_helpPoint.y = bone.y;
		
		_helpMatrix.invert();
		_helpPoint = _helpMatrix.transformPoint(_helpPoint);
		
		bone.x = _helpPoint.x;
		bone.y = _helpPoint.y;
		bone.skewX -= parent.skewX;
		bone.skewY -= parent.skewY;
	}
	
	public static inline function nodeToMatrix(node:Node, matrix:Matrix) {
		matrix.a 	= node.scaleX 	* Math.cos(node.skewY);
		matrix.b 	= node.scaleX 	* Math.sin(node.skewY);
		matrix.c 	= -node.scaleY 	* Math.sin(node.skewX);
		matrix.d 	= node.scaleY 	* Math.cos(node.skewX);
		matrix.tx 	= node.x;
		matrix.ty 	= node.y;
	}
	
	public static inline function setOffSetColorTransform(from:ColorTransform, to:ColorTransform, offset:ColorTransform) {
		offset.alphaOffset 		= to.alphaOffset - from.alphaOffset;
		offset.redOffset 		= to.redOffset - from.redOffset;
		offset.greenOffset 		= to.greenOffset - from.greenOffset;
		offset.blueOffset 		= to.blueOffset - from.blueOffset;
		offset.alphaMultiplier 	= to.alphaMultiplier - from.alphaMultiplier;
		offset.redMultiplier 	= to.redMultiplier - from.redMultiplier;
		offset.greenMultiplier 	= to.greenMultiplier - from.greenMultiplier;
		offset.blueMultiplier 	= to.blueMultiplier - from.blueMultiplier;
	}
	
	public static inline function setTweenColorTransform(current:ColorTransform, offSet:ColorTransform, tween:ColorTransform, progress:Float) {
		tween.alphaOffset 		= current.alphaOffset + progress * offSet.alphaOffset;
		tween.redOffset 		= current.redOffset + progress * offSet.redOffset;
		tween.greenOffset 		= current.greenOffset + progress * offSet.greenOffset;
		tween.blueOffset 		= current.blueOffset + progress * offSet.blueOffset;
		tween.alphaMultiplier 	= current.alphaMultiplier + progress * offSet.alphaMultiplier;
		tween.redMultiplier 	= current.redMultiplier + progress * offSet.redMultiplier;
		tween.greenMultiplier 	= current.greenMultiplier + progress * offSet.greenMultiplier;
		tween.blueMultiplier 	= current.blueMultiplier + progress * offSet.blueMultiplier;
	}
	
	public static inline function setOffSetNode(from:Node, to:Node, offSet:Node, tweenRotate:Int = 0) {
		offSet.x 		= to.x - from.x;
		offSet.y 		= to.y - from.y;
		offSet.skewX 	= to.skewX - from.skewX;
		offSet.skewY 	= to.skewY - from.skewY;
		offSet.scaleX 	= to.scaleX - from.scaleX;
		offSet.scaleY 	= to.scaleY - from.scaleY;
		offSet.pivotX 	= to.pivotX - from.pivotX;
		offSet.pivotY 	= to.pivotY - from.pivotY;
		
		offSet.skewX %= DOUBLE_PI;
		if (offSet.skewX > Math.PI) {
			offSet.skewX -= DOUBLE_PI;
		}
		
		if (offSet.skewX < -Math.PI) {
			offSet.skewX += DOUBLE_PI;
		}
		
		offSet.skewY %= DOUBLE_PI;
		if (offSet.skewY > Math.PI) {
			offSet.skewY -= DOUBLE_PI;
		}
		
		if (offSet.skewY < -Math.PI) {
			offSet.skewY += DOUBLE_PI;
		}
		
		if (tweenRotate != 0) {
			var value:Float = tweenRotate * DOUBLE_PI;
			offSet.skewX += value;
			offSet.skewY += value;
		}
	}
	
	public static inline function setTweenNode(current:Node, offSet:Node, tween:Node, progress:Float) {
		tween.setValues(
			current.x + progress * offSet.x,
			current.y + progress * offSet.y,
			current.skewX + progress * offSet.skewX,
			current.skewY + progress * offSet.skewY,
			current.scaleX + progress * offSet.scaleX,
			current.scaleY + progress * offSet.scaleY,
			current.pivotX + progress * offSet.pivotX,
			current.pivotY + progress * offSet.pivotY,
			Std.int(tween.z)
		);
	}

}