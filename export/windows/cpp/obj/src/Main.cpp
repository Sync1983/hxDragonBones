#include <hxcpp.h>

#ifndef INCLUDED_Main
#include <Main.h>
#endif
#ifndef INCLUDED_haxe_io_Bytes
#include <haxe/io/Bytes.h>
#endif
#ifndef INCLUDED_native_display_BitmapData
#include <native/display/BitmapData.h>
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
#ifndef INCLUDED_native_display_MovieClip
#include <native/display/MovieClip.h>
#endif
#ifndef INCLUDED_native_display_Sprite
#include <native/display/Sprite.h>
#endif
#ifndef INCLUDED_native_display_Stage
#include <native/display/Stage.h>
#endif
#ifndef INCLUDED_native_display_StageAlign
#include <native/display/StageAlign.h>
#endif
#ifndef INCLUDED_native_display_StageScaleMode
#include <native/display/StageScaleMode.h>
#endif
#ifndef INCLUDED_native_events_Event
#include <native/events/Event.h>
#endif
#ifndef INCLUDED_native_events_EventDispatcher
#include <native/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_native_events_IEventDispatcher
#include <native/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_native_utils_ByteArray
#include <native/utils/ByteArray.h>
#endif
#ifndef INCLUDED_native_utils_IDataInput
#include <native/utils/IDataInput.h>
#endif
#ifndef INCLUDED_native_utils_IMemoryRange
#include <native/utils/IMemoryRange.h>
#endif
#ifndef INCLUDED_nme_Lib
#include <nme/Lib.h>
#endif
#ifndef INCLUDED_nme_installer_Assets
#include <nme/installer/Assets.h>
#endif

Void Main_obj::__construct()
{
HX_STACK_PUSH("Main::new","Main.hx",20);
{
	HX_STACK_LINE(21)
	super::__construct();
	HX_STACK_LINE(22)
	this->setupStage();
	HX_STACK_LINE(23)
	this->addListeners();
}
;
	return null();
}

Main_obj::~Main_obj() { }

Dynamic Main_obj::__CreateEmpty() { return  new Main_obj; }
hx::ObjectPtr< Main_obj > Main_obj::__new()
{  hx::ObjectPtr< Main_obj > result = new Main_obj();
	result->__construct();
	return result;}

Dynamic Main_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Main_obj > result = new Main_obj();
	result->__construct();
	return result;}

Void Main_obj::onStageResize( ::native::events::Event event){
{
		HX_STACK_PUSH("Main::onStageResize","Main.hx",89);
		HX_STACK_THIS(this);
		HX_STACK_ARG(event,"event");
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Main_obj,onStageResize,(void))

Void Main_obj::onStageDeactivate( ::native::events::Event event){
{
		HX_STACK_PUSH("Main::onStageDeactivate","Main.hx",86);
		HX_STACK_THIS(this);
		HX_STACK_ARG(event,"event");
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Main_obj,onStageDeactivate,(void))

Void Main_obj::onStageActivate( ::native::events::Event event){
{
		HX_STACK_PUSH("Main::onStageActivate","Main.hx",83);
		HX_STACK_THIS(this);
		HX_STACK_ARG(event,"event");
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Main_obj,onStageActivate,(void))

Void Main_obj::onStageAddedToStage( ::native::events::Event event){
{
		HX_STACK_PUSH("Main::onStageAddedToStage","Main.hx",73);
		HX_STACK_THIS(this);
		HX_STACK_ARG(event,"event");
		HX_STACK_LINE(74)
		this->removeEventListener(::native::events::Event_obj::ADDED_TO_STAGE,this->onStageAddedToStage_dyn(),null());
		HX_STACK_LINE(75)
		::nme::Lib_obj::get_current()->get_stage()->addEventListener(::native::events::Event_obj::RESIZE,this->onStageResize_dyn(),null(),null(),null());
		HX_STACK_LINE(79)
		this->initialize();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Main_obj,onStageAddedToStage,(void))

Void Main_obj::onFactoryComplete( ::native::events::Event event){
{
		HX_STACK_PUSH("Main::onFactoryComplete","Main.hx",69);
		HX_STACK_THIS(this);
		HX_STACK_ARG(event,"event");
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Main_obj,onFactoryComplete,(void))

Void Main_obj::initialize( ){
{
		HX_STACK_PUSH("Main::initialize","Main.hx",48);
		HX_STACK_THIS(this);
		HX_STACK_LINE(49)
		if ((this->_isInitialized)){
			HX_STACK_LINE(49)
			return null();
		}
		HX_STACK_LINE(52)
		this->_isInitialized = true;
		HX_STACK_LINE(57)
		::native::display::BitmapData bitmapData = ::nme::installer::Assets_obj::getBitmapData(HX_CSTRING("assets/img/character_output.png"),null());		HX_STACK_VAR(bitmapData,"bitmapData");
		HX_STACK_LINE(59)
		::native::utils::ByteArray bytes = bitmapData->encode(HX_CSTRING("png"),null());		HX_STACK_VAR(bytes,"bytes");
		HX_STACK_LINE(60)
		::nme::Lib_obj::trace((HX_CSTRING("lenght:") + bytes->length));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Main_obj,initialize,(void))

Void Main_obj::addListeners( ){
{
		HX_STACK_PUSH("Main::addListeners","Main.hx",42);
		HX_STACK_THIS(this);
		HX_STACK_LINE(43)
		this->addEventListener(::native::events::Event_obj::ADDED_TO_STAGE,this->onStageAddedToStage_dyn(),null(),null(),null());
		HX_STACK_LINE(44)
		::nme::Lib_obj::get_current()->get_stage()->addEventListener(::native::events::Event_obj::ACTIVATE,this->onStageActivate_dyn(),null(),null(),null());
		HX_STACK_LINE(45)
		::nme::Lib_obj::get_current()->get_stage()->addEventListener(::native::events::Event_obj::DEACTIVATE,this->onStageDeactivate_dyn(),null(),null(),null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Main_obj,addListeners,(void))

Void Main_obj::setupStage( ){
{
		HX_STACK_PUSH("Main::setupStage","Main.hx",37);
		HX_STACK_THIS(this);
		HX_STACK_LINE(38)
		::nme::Lib_obj::get_current()->get_stage()->set_align(::native::display::StageAlign_obj::TOP_LEFT_dyn());
		HX_STACK_LINE(39)
		::nme::Lib_obj::get_current()->get_stage()->set_scaleMode(::native::display::StageScaleMode_obj::NO_SCALE_dyn());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Main_obj,setupStage,(void))


Main_obj::Main_obj()
{
}

void Main_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Main);
	HX_MARK_MEMBER_NAME(_isInitialized,"_isInitialized");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Main_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_isInitialized,"_isInitialized");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic Main_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 10:
		if (HX_FIELD_EQ(inName,"initialize") ) { return initialize_dyn(); }
		if (HX_FIELD_EQ(inName,"setupStage") ) { return setupStage_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"addListeners") ) { return addListeners_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"onStageResize") ) { return onStageResize_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"_isInitialized") ) { return _isInitialized; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"onStageActivate") ) { return onStageActivate_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"onStageDeactivate") ) { return onStageDeactivate_dyn(); }
		if (HX_FIELD_EQ(inName,"onFactoryComplete") ) { return onFactoryComplete_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"onStageAddedToStage") ) { return onStageAddedToStage_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Main_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 14:
		if (HX_FIELD_EQ(inName,"_isInitialized") ) { _isInitialized=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Main_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_isInitialized"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("onStageResize"),
	HX_CSTRING("onStageDeactivate"),
	HX_CSTRING("onStageActivate"),
	HX_CSTRING("onStageAddedToStage"),
	HX_CSTRING("onFactoryComplete"),
	HX_CSTRING("initialize"),
	HX_CSTRING("addListeners"),
	HX_CSTRING("setupStage"),
	HX_CSTRING("_isInitialized"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Main_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Main_obj::__mClass,"__mClass");
};

Class Main_obj::__mClass;

void Main_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("Main"), hx::TCanCast< Main_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Main_obj::__boot()
{
}

