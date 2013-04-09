#include <hxcpp.h>

#ifndef INCLUDED_Main
#include <Main.h>
#endif
#ifndef INCLUDED_com_fermmmtools_debug_Stats
#include <com/fermmmtools/debug/Stats.h>
#endif
#ifndef INCLUDED_haxe_io_Bytes
#include <haxe/io/Bytes.h>
#endif
#ifndef INCLUDED_hsl_haxe_Bond
#include <hsl/haxe/Bond.h>
#endif
#ifndef INCLUDED_hsl_haxe_Signaler
#include <hsl/haxe/Signaler.h>
#endif
#ifndef INCLUDED_hxDragonBones_Armature
#include <hxDragonBones/Armature.h>
#endif
#ifndef INCLUDED_hxDragonBones_animation_Animation
#include <hxDragonBones/animation/Animation.h>
#endif
#ifndef INCLUDED_hxDragonBones_animation_IAnimatable
#include <hxDragonBones/animation/IAnimatable.h>
#endif
#ifndef INCLUDED_hxDragonBones_animation_WorldClock
#include <hxDragonBones/animation/WorldClock.h>
#endif
#ifndef INCLUDED_hxDragonBones_factorys_BaseFactory
#include <hxDragonBones/factorys/BaseFactory.h>
#endif
#ifndef INCLUDED_hxDragonBones_objects_SkeletonData
#include <hxDragonBones/objects/SkeletonData.h>
#endif
#ifndef INCLUDED_hxDragonBones_utils_IDisposable
#include <hxDragonBones/utils/IDisposable.h>
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
HX_STACK_PUSH("Main::new","Main.hx",30);
{
	HX_STACK_LINE(31)
	super::__construct();
	HX_STACK_LINE(32)
	this->setupStage();
	HX_STACK_LINE(33)
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

Void Main_obj::onEnterFrame( Dynamic _){
{
		HX_STACK_PUSH("Main::onEnterFrame","Main.hx",90);
		HX_STACK_THIS(this);
		HX_STACK_ARG(_,"_");
		HX_STACK_LINE(90)
		::hxDragonBones::animation::WorldClock_obj::get_instance()->advanceTime((int)-1);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Main_obj,onEnterFrame,(void))

Void Main_obj::onFactoryDataParsed( ){
{
		HX_STACK_PUSH("Main::onFactoryDataParsed","Main.hx",70);
		HX_STACK_THIS(this);
		HX_STACK_LINE(71)
		int columnNum = (int)15;		HX_STACK_VAR(columnNum,"columnNum");
		HX_STACK_LINE(72)
		int paddingWidth = (int)50;		HX_STACK_VAR(paddingWidth,"paddingWidth");
		HX_STACK_LINE(73)
		int paddingHeight = (int)20;		HX_STACK_VAR(paddingHeight,"paddingHeight");
		HX_STACK_LINE(74)
		int paddingLeft = (int)25;		HX_STACK_VAR(paddingLeft,"paddingLeft");
		HX_STACK_LINE(75)
		int paddingTop = (int)200;		HX_STACK_VAR(paddingTop,"paddingTop");
		HX_STACK_LINE(76)
		int Dx = (int)25;		HX_STACK_VAR(Dx,"Dx");
		HX_STACK_LINE(78)
		{
			HX_STACK_LINE(78)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(78)
			while(((_g < (int)1))){
				HX_STACK_LINE(78)
				int i = (_g)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(79)
				::hxDragonBones::Armature armature = this->factory->buildArmature(HX_CSTRING("CharacterAnimations"),null(),null(),null());		HX_STACK_VAR(armature,"armature");
				HX_STACK_LINE(80)
				::native::display::Sprite display = hx::TCast< native::display::Sprite >::cast(armature->display);		HX_STACK_VAR(display,"display");
				HX_STACK_LINE(81)
				display->set_x((((hx::Mod(i,columnNum) * paddingWidth) + paddingLeft) + (hx::Mod((Float(i) / Float(columnNum)),(int)2) * Dx)));
				HX_STACK_LINE(82)
				display->set_y((((Float(i) / Float(columnNum)) * paddingHeight) + paddingTop));
				HX_STACK_LINE(83)
				armature->animation->gotoAndPlay(HX_CSTRING("Idle"),null(),null(),true);
				HX_STACK_LINE(84)
				this->addChild(display);
				HX_STACK_LINE(85)
				::hxDragonBones::animation::WorldClock_obj::get_instance()->add(armature);
			}
		}
		HX_STACK_LINE(87)
		this->addEventListener(::native::events::Event_obj::ENTER_FRAME,this->onEnterFrame_dyn(),null(),null(),null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Main_obj,onFactoryDataParsed,(void))

Void Main_obj::initialize( ){
{
		HX_STACK_PUSH("Main::initialize","Main.hx",58);
		HX_STACK_THIS(this);
		HX_STACK_LINE(59)
		::nme::Lib_obj::get_current()->addChild(::com::fermmmtools::debug::Stats_obj::__new(null(),null()));
		HX_STACK_LINE(63)
		this->factory = ::hxDragonBones::factorys::BaseFactory_obj::__new();
		HX_STACK_LINE(64)
		this->factory->onDataParsed->bindVoid(this->onFactoryDataParsed_dyn());
		HX_STACK_LINE(65)
		this->factory->parseData(::nme::installer::Assets_obj::getBytes(HX_CSTRING("assets/img/character_output_bin")),null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Main_obj,initialize,(void))

Void Main_obj::onStageAddedToStage( Dynamic _){
{
		HX_STACK_PUSH("Main::onStageAddedToStage","Main.hx",49);
		HX_STACK_THIS(this);
		HX_STACK_ARG(_,"_");
		HX_STACK_LINE(50)
		this->removeEventListener(::native::events::Event_obj::ADDED_TO_STAGE,this->onStageAddedToStage_dyn(),null());
		HX_STACK_LINE(54)
		this->initialize();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Main_obj,onStageAddedToStage,(void))

Void Main_obj::addListeners( ){
{
		HX_STACK_PUSH("Main::addListeners","Main.hx",45);
		HX_STACK_THIS(this);
		HX_STACK_LINE(45)
		this->addEventListener(::native::events::Event_obj::ADDED_TO_STAGE,this->onStageAddedToStage_dyn(),null(),null(),null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Main_obj,addListeners,(void))

Void Main_obj::setupStage( ){
{
		HX_STACK_PUSH("Main::setupStage","Main.hx",40);
		HX_STACK_THIS(this);
		HX_STACK_LINE(41)
		::nme::Lib_obj::get_current()->get_stage()->set_align(::native::display::StageAlign_obj::TOP_LEFT_dyn());
		HX_STACK_LINE(42)
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
	HX_MARK_MEMBER_NAME(factory,"factory");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Main_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(factory,"factory");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic Main_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"factory") ) { return factory; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"initialize") ) { return initialize_dyn(); }
		if (HX_FIELD_EQ(inName,"setupStage") ) { return setupStage_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"onEnterFrame") ) { return onEnterFrame_dyn(); }
		if (HX_FIELD_EQ(inName,"addListeners") ) { return addListeners_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"onFactoryDataParsed") ) { return onFactoryDataParsed_dyn(); }
		if (HX_FIELD_EQ(inName,"onStageAddedToStage") ) { return onStageAddedToStage_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Main_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"factory") ) { factory=inValue.Cast< ::hxDragonBones::factorys::BaseFactory >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Main_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("factory"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("onEnterFrame"),
	HX_CSTRING("onFactoryDataParsed"),
	HX_CSTRING("initialize"),
	HX_CSTRING("onStageAddedToStage"),
	HX_CSTRING("addListeners"),
	HX_CSTRING("setupStage"),
	HX_CSTRING("factory"),
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

