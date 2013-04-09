#include <hxcpp.h>

#ifndef INCLUDED_hxDragonBones_Armature
#include <hxDragonBones/Armature.h>
#endif
#ifndef INCLUDED_hxDragonBones_Bone
#include <hxDragonBones/Bone.h>
#endif
#ifndef INCLUDED_hxDragonBones_animation_IAnimatable
#include <hxDragonBones/animation/IAnimatable.h>
#endif
#ifndef INCLUDED_hxDragonBones_events_SoundEvent
#include <hxDragonBones/events/SoundEvent.h>
#endif
#ifndef INCLUDED_hxDragonBones_utils_IDisposable
#include <hxDragonBones/utils/IDisposable.h>
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
namespace hxDragonBones{
namespace events{

Void SoundEvent_obj::__construct(::String type,hx::Null< bool >  __o_cancelable)
{
HX_STACK_PUSH("SoundEvent::new","hxDragonBones/events/SoundEvent.hx",14);
bool cancelable = __o_cancelable.Default(false);
{
	HX_STACK_LINE(14)
	super::__construct(type,false,cancelable);
}
;
	return null();
}

SoundEvent_obj::~SoundEvent_obj() { }

Dynamic SoundEvent_obj::__CreateEmpty() { return  new SoundEvent_obj; }
hx::ObjectPtr< SoundEvent_obj > SoundEvent_obj::__new(::String type,hx::Null< bool >  __o_cancelable)
{  hx::ObjectPtr< SoundEvent_obj > result = new SoundEvent_obj();
	result->__construct(type,__o_cancelable);
	return result;}

Dynamic SoundEvent_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< SoundEvent_obj > result = new SoundEvent_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

::native::events::Event SoundEvent_obj::clone( ){
	HX_STACK_PUSH("SoundEvent::clone","hxDragonBones/events/SoundEvent.hx",24);
	HX_STACK_THIS(this);
	HX_STACK_LINE(25)
	::hxDragonBones::events::SoundEvent event = ::hxDragonBones::events::SoundEvent_obj::__new(this->get_type(),this->get_cancelable());		HX_STACK_VAR(event,"event");
	HX_STACK_LINE(26)
	event->movementID = this->movementID;
	HX_STACK_LINE(27)
	event->sound = this->sound;
	HX_STACK_LINE(28)
	event->soundEffect = this->soundEffect;
	HX_STACK_LINE(29)
	event->armature = this->armature;
	HX_STACK_LINE(30)
	event->bone = this->bone;
	HX_STACK_LINE(31)
	return event;
}


::String SoundEvent_obj::SOUND;


SoundEvent_obj::SoundEvent_obj()
{
}

void SoundEvent_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(SoundEvent);
	HX_MARK_MEMBER_NAME(bone,"bone");
	HX_MARK_MEMBER_NAME(armature,"armature");
	HX_MARK_MEMBER_NAME(soundEffect,"soundEffect");
	HX_MARK_MEMBER_NAME(sound,"sound");
	HX_MARK_MEMBER_NAME(movementID,"movementID");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void SoundEvent_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(bone,"bone");
	HX_VISIT_MEMBER_NAME(armature,"armature");
	HX_VISIT_MEMBER_NAME(soundEffect,"soundEffect");
	HX_VISIT_MEMBER_NAME(sound,"sound");
	HX_VISIT_MEMBER_NAME(movementID,"movementID");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic SoundEvent_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"bone") ) { return bone; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"SOUND") ) { return SOUND; }
		if (HX_FIELD_EQ(inName,"clone") ) { return clone_dyn(); }
		if (HX_FIELD_EQ(inName,"sound") ) { return sound; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"armature") ) { return armature; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"movementID") ) { return movementID; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"soundEffect") ) { return soundEffect; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic SoundEvent_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"bone") ) { bone=inValue.Cast< ::hxDragonBones::Bone >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"SOUND") ) { SOUND=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"sound") ) { sound=inValue.Cast< ::String >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"armature") ) { armature=inValue.Cast< ::hxDragonBones::Armature >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"movementID") ) { movementID=inValue.Cast< ::String >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"soundEffect") ) { soundEffect=inValue.Cast< ::String >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void SoundEvent_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("bone"));
	outFields->push(HX_CSTRING("armature"));
	outFields->push(HX_CSTRING("soundEffect"));
	outFields->push(HX_CSTRING("sound"));
	outFields->push(HX_CSTRING("movementID"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("SOUND"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("clone"),
	HX_CSTRING("bone"),
	HX_CSTRING("armature"),
	HX_CSTRING("soundEffect"),
	HX_CSTRING("sound"),
	HX_CSTRING("movementID"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(SoundEvent_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(SoundEvent_obj::SOUND,"SOUND");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(SoundEvent_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(SoundEvent_obj::SOUND,"SOUND");
};

Class SoundEvent_obj::__mClass;

void SoundEvent_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("hxDragonBones.events.SoundEvent"), hx::TCanCast< SoundEvent_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void SoundEvent_obj::__boot()
{
	SOUND= HX_CSTRING("sound");
}

} // end namespace hxDragonBones
} // end namespace events
