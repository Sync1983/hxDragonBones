#include <hxcpp.h>

#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_hxDragonBones_display_IDisplayBridge
#include <hxDragonBones/display/IDisplayBridge.h>
#endif
#ifndef INCLUDED_hxDragonBones_display_NativeDisplayBridge
#include <hxDragonBones/display/NativeDisplayBridge.h>
#endif
#ifndef INCLUDED_hxDragonBones_objects_Node
#include <hxDragonBones/objects/Node.h>
#endif
#ifndef INCLUDED_native_display_DisplayObject
#include <native/display/DisplayObject.h>
#endif
#ifndef INCLUDED_native_display_DisplayObjectContainer
#include <native/display/DisplayObjectContainer.h>
#endif
#ifndef INCLUDED_native_display_IBitmapDrawable
#include <native/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_native_display_InteractiveObject
#include <native/display/InteractiveObject.h>
#endif
#ifndef INCLUDED_native_events_EventDispatcher
#include <native/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_native_events_IEventDispatcher
#include <native/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_native_geom_ColorTransform
#include <native/geom/ColorTransform.h>
#endif
#ifndef INCLUDED_native_geom_Matrix
#include <native/geom/Matrix.h>
#endif
namespace hxDragonBones{
namespace display{

Void NativeDisplayBridge_obj::__construct()
{
HX_STACK_PUSH("NativeDisplayBridge::new","hxDragonBones/display/NativeDisplayBridge.hx",13);
{
}
;
	return null();
}

NativeDisplayBridge_obj::~NativeDisplayBridge_obj() { }

Dynamic NativeDisplayBridge_obj::__CreateEmpty() { return  new NativeDisplayBridge_obj; }
hx::ObjectPtr< NativeDisplayBridge_obj > NativeDisplayBridge_obj::__new()
{  hx::ObjectPtr< NativeDisplayBridge_obj > result = new NativeDisplayBridge_obj();
	result->__construct();
	return result;}

Dynamic NativeDisplayBridge_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< NativeDisplayBridge_obj > result = new NativeDisplayBridge_obj();
	result->__construct();
	return result;}

hx::Object *NativeDisplayBridge_obj::__ToInterface(const type_info &inType) {
	if (inType==typeid( ::hxDragonBones::display::IDisplayBridge_obj)) return operator ::hxDragonBones::display::IDisplayBridge_obj *();
	return super::__ToInterface(inType);
}

Void NativeDisplayBridge_obj::removeDisplayFromParent( ){
{
		HX_STACK_PUSH("NativeDisplayBridge::removeDisplayFromParent","hxDragonBones/display/NativeDisplayBridge.hx",61);
		HX_STACK_THIS(this);
		HX_STACK_LINE(61)
		if (((bool((this->display != null())) && bool((this->display->__Field(HX_CSTRING("parent"),true) != null()))))){
			HX_STACK_LINE(62)
			this->display->__Field(HX_CSTRING("parent"),true)->__Field(HX_CSTRING("removeChild"),true)(this->display);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(NativeDisplayBridge_obj,removeDisplayFromParent,(void))

Void NativeDisplayBridge_obj::addDisplayTo( Dynamic container,hx::Null< int >  __o_index){
int index = __o_index.Default(-1);
	HX_STACK_PUSH("NativeDisplayBridge::addDisplayTo","hxDragonBones/display/NativeDisplayBridge.hx",51);
	HX_STACK_THIS(this);
	HX_STACK_ARG(container,"container");
	HX_STACK_ARG(index,"index");
{
		HX_STACK_LINE(51)
		if (((bool((container != null())) && bool((this->display != null()))))){
			HX_STACK_LINE(52)
			if (((index < (int)0))){
				HX_STACK_LINE(53)
				container->__Field(HX_CSTRING("addChild"),true)(this->display);
			}
			else{
				HX_STACK_LINE(55)
				container->__Field(HX_CSTRING("addChildAt"),true)(this->display,::Math_obj::min(index,container->__Field(HX_CSTRING("numChildren"),true)));
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(NativeDisplayBridge_obj,addDisplayTo,(void))

Void NativeDisplayBridge_obj::update( ::native::geom::Matrix matrix,::hxDragonBones::objects::Node node,::native::geom::ColorTransform colorTransform,bool visible){
{
		HX_STACK_PUSH("NativeDisplayBridge::update","hxDragonBones/display/NativeDisplayBridge.hx",38);
		HX_STACK_THIS(this);
		HX_STACK_ARG(matrix,"matrix");
		HX_STACK_ARG(node,"node");
		HX_STACK_ARG(colorTransform,"colorTransform");
		HX_STACK_ARG(visible,"visible");
		HX_STACK_LINE(39)
		Float pivotX = node->pivotX;		HX_STACK_VAR(pivotX,"pivotX");
		HX_STACK_LINE(40)
		Float pivotY = node->pivotY;		HX_STACK_VAR(pivotY,"pivotY");
		HX_STACK_LINE(41)
		hx::SubEq(matrix->tx,((matrix->a * pivotX) + (matrix->c * pivotY)));
		HX_STACK_LINE(42)
		hx::SubEq(matrix->ty,((matrix->b * pivotX) + (matrix->d * pivotY)));
		HX_STACK_LINE(44)
		this->display->__Field(HX_CSTRING("transform"),true)->__FieldRef(HX_CSTRING("matrix")) = matrix;
		HX_STACK_LINE(45)
		if (((colorTransform != null()))){
			HX_STACK_LINE(45)
			this->display->__Field(HX_CSTRING("transform"),true)->__FieldRef(HX_CSTRING("colorTransform")) = colorTransform;
		}
		HX_STACK_LINE(48)
		this->display->__FieldRef(HX_CSTRING("visible")) = visible;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(NativeDisplayBridge_obj,update,(void))

Dynamic NativeDisplayBridge_obj::set_display( Dynamic value){
	HX_STACK_PUSH("NativeDisplayBridge::set_display","hxDragonBones/display/NativeDisplayBridge.hx",20);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(21)
	if (((value == this->display))){
		HX_STACK_LINE(21)
		return value;
	}
	HX_STACK_LINE(24)
	int index = (int)0;		HX_STACK_VAR(index,"index");
	HX_STACK_LINE(25)
	::native::display::DisplayObjectContainer parent = null();		HX_STACK_VAR(parent,"parent");
	HX_STACK_LINE(26)
	if (((this->display != null()))){
		HX_STACK_LINE(27)
		parent = this->display->__Field(HX_CSTRING("parent"),true);
		HX_STACK_LINE(28)
		if (((parent != null()))){
			HX_STACK_LINE(28)
			index = parent->getChildIndex(this->display);
		}
		HX_STACK_LINE(31)
		this->removeDisplayFromParent();
	}
	HX_STACK_LINE(33)
	this->display = value;
	HX_STACK_LINE(34)
	this->addDisplayTo(parent,index);
	HX_STACK_LINE(35)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(NativeDisplayBridge_obj,set_display,return )


NativeDisplayBridge_obj::NativeDisplayBridge_obj()
{
}

void NativeDisplayBridge_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(NativeDisplayBridge);
	HX_MARK_MEMBER_NAME(display,"display");
	HX_MARK_END_CLASS();
}

void NativeDisplayBridge_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(display,"display");
}

Dynamic NativeDisplayBridge_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"display") ) { return display; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"set_display") ) { return set_display_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"addDisplayTo") ) { return addDisplayTo_dyn(); }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"removeDisplayFromParent") ) { return removeDisplayFromParent_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic NativeDisplayBridge_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"display") ) { if (inCallProp) return set_display(inValue);display=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void NativeDisplayBridge_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("display"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("removeDisplayFromParent"),
	HX_CSTRING("addDisplayTo"),
	HX_CSTRING("update"),
	HX_CSTRING("set_display"),
	HX_CSTRING("display"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(NativeDisplayBridge_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(NativeDisplayBridge_obj::__mClass,"__mClass");
};

Class NativeDisplayBridge_obj::__mClass;

void NativeDisplayBridge_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("hxDragonBones.display.NativeDisplayBridge"), hx::TCanCast< NativeDisplayBridge_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void NativeDisplayBridge_obj::__boot()
{
}

} // end namespace hxDragonBones
} // end namespace display
