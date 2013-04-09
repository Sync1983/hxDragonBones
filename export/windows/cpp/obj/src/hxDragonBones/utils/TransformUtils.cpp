#include <hxcpp.h>

#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_hxDragonBones_objects_Node
#include <hxDragonBones/objects/Node.h>
#endif
#ifndef INCLUDED_hxDragonBones_utils_TransformUtils
#include <hxDragonBones/utils/TransformUtils.h>
#endif
#ifndef INCLUDED_native_geom_ColorTransform
#include <native/geom/ColorTransform.h>
#endif
#ifndef INCLUDED_native_geom_Matrix
#include <native/geom/Matrix.h>
#endif
#ifndef INCLUDED_native_geom_Point
#include <native/geom/Point.h>
#endif
namespace hxDragonBones{
namespace utils{

Void TransformUtils_obj::__construct()
{
	return null();
}

TransformUtils_obj::~TransformUtils_obj() { }

Dynamic TransformUtils_obj::__CreateEmpty() { return  new TransformUtils_obj; }
hx::ObjectPtr< TransformUtils_obj > TransformUtils_obj::__new()
{  hx::ObjectPtr< TransformUtils_obj > result = new TransformUtils_obj();
	result->__construct();
	return result;}

Dynamic TransformUtils_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< TransformUtils_obj > result = new TransformUtils_obj();
	result->__construct();
	return result;}

Float TransformUtils_obj::DOUBLE_PI;

::native::geom::Matrix TransformUtils_obj::_helpMatrix;

::native::geom::Point TransformUtils_obj::_helpPoint;

Void TransformUtils_obj::transformPointWithParent( ::hxDragonBones::objects::Node bone,::hxDragonBones::objects::Node parent){
{
		HX_STACK_PUSH("TransformUtils::transformPointWithParent","hxDragonBones/utils/TransformUtils.hx",17);
		HX_STACK_ARG(bone,"bone");
		HX_STACK_ARG(parent,"parent");
		HX_STACK_LINE(18)
		{
			HX_STACK_LINE(18)
			::native::geom::Matrix resultMatrix = ::hxDragonBones::utils::TransformUtils_obj::_helpMatrix;		HX_STACK_VAR(resultMatrix,"resultMatrix");
			HX_STACK_LINE(18)
			resultMatrix->identity();
			HX_STACK_LINE(18)
			resultMatrix->rotate(parent->skewX);
			HX_STACK_LINE(18)
			resultMatrix->scale(parent->scaleX,parent->scaleY);
			HX_STACK_LINE(18)
			resultMatrix->translate(parent->x,parent->y);
		}
		HX_STACK_LINE(20)
		::hxDragonBones::utils::TransformUtils_obj::_helpPoint->x = bone->x;
		HX_STACK_LINE(21)
		::hxDragonBones::utils::TransformUtils_obj::_helpPoint->y = bone->y;
		HX_STACK_LINE(23)
		::hxDragonBones::utils::TransformUtils_obj::_helpMatrix->invert();
		HX_STACK_LINE(24)
		::hxDragonBones::utils::TransformUtils_obj::_helpPoint = ::hxDragonBones::utils::TransformUtils_obj::_helpMatrix->transformPoint(::hxDragonBones::utils::TransformUtils_obj::_helpPoint);
		HX_STACK_LINE(26)
		bone->x = ::hxDragonBones::utils::TransformUtils_obj::_helpPoint->x;
		HX_STACK_LINE(27)
		bone->y = ::hxDragonBones::utils::TransformUtils_obj::_helpPoint->y;
		HX_STACK_LINE(28)
		hx::SubEq(bone->skewX,parent->skewX);
		HX_STACK_LINE(29)
		hx::SubEq(bone->skewY,parent->skewY);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(TransformUtils_obj,transformPointWithParent,(void))

Void TransformUtils_obj::nodeToMatrix( ::hxDragonBones::objects::Node node,::native::geom::Matrix resultMatrix){
{
		HX_STACK_PUSH("TransformUtils::nodeToMatrix","hxDragonBones/utils/TransformUtils.hx",32);
		HX_STACK_ARG(node,"node");
		HX_STACK_ARG(resultMatrix,"resultMatrix");
		HX_STACK_LINE(33)
		resultMatrix->identity();
		HX_STACK_LINE(34)
		resultMatrix->rotate(node->skewX);
		HX_STACK_LINE(35)
		resultMatrix->scale(node->scaleX,node->scaleY);
		HX_STACK_LINE(36)
		resultMatrix->translate(node->x,node->y);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(TransformUtils_obj,nodeToMatrix,(void))

Void TransformUtils_obj::setOffSetColorTransform( ::native::geom::ColorTransform from,::native::geom::ColorTransform to,::native::geom::ColorTransform offset){
{
		HX_STACK_PUSH("TransformUtils::setOffSetColorTransform","hxDragonBones/utils/TransformUtils.hx",39);
		HX_STACK_ARG(from,"from");
		HX_STACK_ARG(to,"to");
		HX_STACK_ARG(offset,"offset");
		HX_STACK_LINE(40)
		offset->alphaOffset = (to->alphaOffset - from->alphaOffset);
		HX_STACK_LINE(41)
		offset->redOffset = (to->redOffset - from->redOffset);
		HX_STACK_LINE(42)
		offset->greenOffset = (to->greenOffset - from->greenOffset);
		HX_STACK_LINE(43)
		offset->blueOffset = (to->blueOffset - from->blueOffset);
		HX_STACK_LINE(44)
		offset->alphaMultiplier = (to->alphaMultiplier - from->alphaMultiplier);
		HX_STACK_LINE(45)
		offset->redMultiplier = (to->redMultiplier - from->redMultiplier);
		HX_STACK_LINE(46)
		offset->greenMultiplier = (to->greenMultiplier - from->greenMultiplier);
		HX_STACK_LINE(47)
		offset->blueMultiplier = (to->blueMultiplier - from->blueMultiplier);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(TransformUtils_obj,setOffSetColorTransform,(void))

Void TransformUtils_obj::setTweenColorTransform( ::native::geom::ColorTransform current,::native::geom::ColorTransform offSet,::native::geom::ColorTransform tween,Float progress){
{
		HX_STACK_PUSH("TransformUtils::setTweenColorTransform","hxDragonBones/utils/TransformUtils.hx",50);
		HX_STACK_ARG(current,"current");
		HX_STACK_ARG(offSet,"offSet");
		HX_STACK_ARG(tween,"tween");
		HX_STACK_ARG(progress,"progress");
		HX_STACK_LINE(51)
		tween->alphaOffset = (current->alphaOffset + (progress * offSet->alphaOffset));
		HX_STACK_LINE(52)
		tween->redOffset = (current->redOffset + (progress * offSet->redOffset));
		HX_STACK_LINE(53)
		tween->greenOffset = (current->greenOffset + (progress * offSet->greenOffset));
		HX_STACK_LINE(54)
		tween->blueOffset = (current->blueOffset + (progress * offSet->blueOffset));
		HX_STACK_LINE(55)
		tween->alphaMultiplier = (current->alphaMultiplier + (progress * offSet->alphaMultiplier));
		HX_STACK_LINE(56)
		tween->redMultiplier = (current->redMultiplier + (progress * offSet->redMultiplier));
		HX_STACK_LINE(57)
		tween->greenMultiplier = (current->greenMultiplier + (progress * offSet->greenMultiplier));
		HX_STACK_LINE(58)
		tween->blueMultiplier = (current->blueMultiplier + (progress * offSet->blueMultiplier));
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(TransformUtils_obj,setTweenColorTransform,(void))

Void TransformUtils_obj::setOffSetNode( ::hxDragonBones::objects::Node from,::hxDragonBones::objects::Node to,::hxDragonBones::objects::Node offSet,hx::Null< int >  __o_tweenRotate){
int tweenRotate = __o_tweenRotate.Default(0);
	HX_STACK_PUSH("TransformUtils::setOffSetNode","hxDragonBones/utils/TransformUtils.hx",61);
	HX_STACK_ARG(from,"from");
	HX_STACK_ARG(to,"to");
	HX_STACK_ARG(offSet,"offSet");
	HX_STACK_ARG(tweenRotate,"tweenRotate");
{
		HX_STACK_LINE(62)
		offSet->x = (to->x - from->x);
		HX_STACK_LINE(63)
		offSet->y = (to->y - from->y);
		HX_STACK_LINE(64)
		offSet->skewX = (to->skewX - from->skewX);
		HX_STACK_LINE(65)
		offSet->skewY = (to->skewY - from->skewY);
		HX_STACK_LINE(66)
		offSet->scaleX = (to->scaleX - from->scaleX);
		HX_STACK_LINE(67)
		offSet->scaleY = (to->scaleY - from->scaleY);
		HX_STACK_LINE(68)
		offSet->pivotX = (to->pivotX - from->pivotX);
		HX_STACK_LINE(69)
		offSet->pivotY = (to->pivotY - from->pivotY);
		HX_STACK_LINE(71)
		hx::ModEq(offSet->skewX,(::Math_obj::PI * (int)2));
		HX_STACK_LINE(72)
		if (((offSet->skewX > ::Math_obj::PI))){
			HX_STACK_LINE(72)
			hx::SubEq(offSet->skewX,(::Math_obj::PI * (int)2));
		}
		HX_STACK_LINE(76)
		if (((offSet->skewX < -(::Math_obj::PI)))){
			HX_STACK_LINE(76)
			hx::AddEq(offSet->skewX,(::Math_obj::PI * (int)2));
		}
		HX_STACK_LINE(80)
		hx::ModEq(offSet->skewY,(::Math_obj::PI * (int)2));
		HX_STACK_LINE(81)
		if (((offSet->skewY > ::Math_obj::PI))){
			HX_STACK_LINE(81)
			hx::SubEq(offSet->skewY,(::Math_obj::PI * (int)2));
		}
		HX_STACK_LINE(85)
		if (((offSet->skewY < -(::Math_obj::PI)))){
			HX_STACK_LINE(85)
			hx::AddEq(offSet->skewY,(::Math_obj::PI * (int)2));
		}
		HX_STACK_LINE(89)
		if (((tweenRotate != (int)0))){
			HX_STACK_LINE(90)
			Float value = (tweenRotate * ((::Math_obj::PI * (int)2)));		HX_STACK_VAR(value,"value");
			HX_STACK_LINE(91)
			hx::AddEq(offSet->skewX,value);
			HX_STACK_LINE(92)
			hx::AddEq(offSet->skewY,value);
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(TransformUtils_obj,setOffSetNode,(void))

Void TransformUtils_obj::setTweenNode( ::hxDragonBones::objects::Node current,::hxDragonBones::objects::Node offSet,::hxDragonBones::objects::Node tween,Float progress){
{
		HX_STACK_PUSH("TransformUtils::setTweenNode","hxDragonBones/utils/TransformUtils.hx",96);
		HX_STACK_ARG(current,"current");
		HX_STACK_ARG(offSet,"offSet");
		HX_STACK_ARG(tween,"tween");
		HX_STACK_ARG(progress,"progress");
		HX_STACK_LINE(96)
		tween->setValues((current->x + (progress * offSet->x)),(current->y + (progress * offSet->y)),(current->skewX + (progress * offSet->skewX)),(current->skewY + (progress * offSet->skewY)),(current->scaleX + (progress * offSet->scaleX)),(current->scaleY + (progress * offSet->scaleY)),(current->pivotX + (progress * offSet->pivotX)),(current->pivotY + (progress * offSet->pivotY)),::Std_obj::_int(tween->z));
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(TransformUtils_obj,setTweenNode,(void))


TransformUtils_obj::TransformUtils_obj()
{
}

void TransformUtils_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(TransformUtils);
	HX_MARK_END_CLASS();
}

void TransformUtils_obj::__Visit(HX_VISIT_PARAMS)
{
}

Dynamic TransformUtils_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 9:
		if (HX_FIELD_EQ(inName,"DOUBLE_PI") ) { return DOUBLE_PI; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"_helpPoint") ) { return _helpPoint; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"_helpMatrix") ) { return _helpMatrix; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"nodeToMatrix") ) { return nodeToMatrix_dyn(); }
		if (HX_FIELD_EQ(inName,"setTweenNode") ) { return setTweenNode_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"setOffSetNode") ) { return setOffSetNode_dyn(); }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"setTweenColorTransform") ) { return setTweenColorTransform_dyn(); }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"setOffSetColorTransform") ) { return setOffSetColorTransform_dyn(); }
		break;
	case 24:
		if (HX_FIELD_EQ(inName,"transformPointWithParent") ) { return transformPointWithParent_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic TransformUtils_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 9:
		if (HX_FIELD_EQ(inName,"DOUBLE_PI") ) { DOUBLE_PI=inValue.Cast< Float >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"_helpPoint") ) { _helpPoint=inValue.Cast< ::native::geom::Point >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"_helpMatrix") ) { _helpMatrix=inValue.Cast< ::native::geom::Matrix >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void TransformUtils_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("DOUBLE_PI"),
	HX_CSTRING("_helpMatrix"),
	HX_CSTRING("_helpPoint"),
	HX_CSTRING("transformPointWithParent"),
	HX_CSTRING("nodeToMatrix"),
	HX_CSTRING("setOffSetColorTransform"),
	HX_CSTRING("setTweenColorTransform"),
	HX_CSTRING("setOffSetNode"),
	HX_CSTRING("setTweenNode"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(TransformUtils_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(TransformUtils_obj::DOUBLE_PI,"DOUBLE_PI");
	HX_MARK_MEMBER_NAME(TransformUtils_obj::_helpMatrix,"_helpMatrix");
	HX_MARK_MEMBER_NAME(TransformUtils_obj::_helpPoint,"_helpPoint");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(TransformUtils_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(TransformUtils_obj::DOUBLE_PI,"DOUBLE_PI");
	HX_VISIT_MEMBER_NAME(TransformUtils_obj::_helpMatrix,"_helpMatrix");
	HX_VISIT_MEMBER_NAME(TransformUtils_obj::_helpPoint,"_helpPoint");
};

Class TransformUtils_obj::__mClass;

void TransformUtils_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("hxDragonBones.utils.TransformUtils"), hx::TCanCast< TransformUtils_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void TransformUtils_obj::__boot()
{
	DOUBLE_PI= (::Math_obj::PI * (int)2);
	_helpMatrix= ::native::geom::Matrix_obj::__new(null(),null(),null(),null(),null(),null());
	_helpPoint= ::native::geom::Point_obj::__new(null(),null());
}

} // end namespace hxDragonBones
} // end namespace utils
