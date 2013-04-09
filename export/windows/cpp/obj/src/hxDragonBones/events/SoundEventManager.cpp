#include <hxcpp.h>

#ifndef INCLUDED_hxDragonBones_events_SoundEventManager
#include <hxDragonBones/events/SoundEventManager.h>
#endif
#ifndef INCLUDED_native_events_EventDispatcher
#include <native/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_native_events_IEventDispatcher
#include <native/events/IEventDispatcher.h>
#endif
namespace hxDragonBones{
namespace events{

Void SoundEventManager_obj::__construct(::native::events::IEventDispatcher target)
{
HX_STACK_PUSH("SoundEventManager::new","hxDragonBones/events/SoundEventManager.hx",20);
{
	HX_STACK_LINE(20)
	super::__construct(target);
}
;
	return null();
}

SoundEventManager_obj::~SoundEventManager_obj() { }

Dynamic SoundEventManager_obj::__CreateEmpty() { return  new SoundEventManager_obj; }
hx::ObjectPtr< SoundEventManager_obj > SoundEventManager_obj::__new(::native::events::IEventDispatcher target)
{  hx::ObjectPtr< SoundEventManager_obj > result = new SoundEventManager_obj();
	result->__construct(target);
	return result;}

Dynamic SoundEventManager_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< SoundEventManager_obj > result = new SoundEventManager_obj();
	result->__construct(inArgs[0]);
	return result;}

::hxDragonBones::events::SoundEventManager SoundEventManager_obj::instance;

::hxDragonBones::events::SoundEventManager SoundEventManager_obj::get_instance( ){
	HX_STACK_PUSH("SoundEventManager::get_instance","hxDragonBones/events/SoundEventManager.hx",13);
	HX_STACK_LINE(14)
	if (((::hxDragonBones::events::SoundEventManager_obj::instance == null()))){
		HX_STACK_LINE(14)
		::hxDragonBones::events::SoundEventManager_obj::instance = ::hxDragonBones::events::SoundEventManager_obj::__new(null());
	}
	HX_STACK_LINE(17)
	return ::hxDragonBones::events::SoundEventManager_obj::instance;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(SoundEventManager_obj,get_instance,return )


SoundEventManager_obj::SoundEventManager_obj()
{
}

void SoundEventManager_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(SoundEventManager);
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void SoundEventManager_obj::__Visit(HX_VISIT_PARAMS)
{
	super::__Visit(HX_VISIT_ARG);
}

Dynamic SoundEventManager_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"instance") ) { return inCallProp ? get_instance() : instance; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"get_instance") ) { return get_instance_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic SoundEventManager_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"instance") ) { instance=inValue.Cast< ::hxDragonBones::events::SoundEventManager >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void SoundEventManager_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("instance"),
	HX_CSTRING("get_instance"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(SoundEventManager_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(SoundEventManager_obj::instance,"instance");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(SoundEventManager_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(SoundEventManager_obj::instance,"instance");
};

Class SoundEventManager_obj::__mClass;

void SoundEventManager_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("hxDragonBones.events.SoundEventManager"), hx::TCanCast< SoundEventManager_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void SoundEventManager_obj::__boot()
{
}

} // end namespace hxDragonBones
} // end namespace events
