#include <hxcpp.h>

#ifndef INCLUDED_hxDragonBones_Armature
#include <hxDragonBones/Armature.h>
#endif
#ifndef INCLUDED_hxDragonBones_animation_IAnimatable
#include <hxDragonBones/animation/IAnimatable.h>
#endif
#ifndef INCLUDED_hxDragonBones_events_AnimationEvent
#include <hxDragonBones/events/AnimationEvent.h>
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

Void AnimationEvent_obj::__construct(::String type,hx::Null< bool >  __o_bubbles,hx::Null< bool >  __o_cancelable)
{
HX_STACK_PUSH("AnimationEvent::new","hxDragonBones/events/AnimationEvent.hx",16);
bool bubbles = __o_bubbles.Default(false);
bool cancelable = __o_cancelable.Default(false);
{
	HX_STACK_LINE(16)
	super::__construct(type,false,cancelable);
}
;
	return null();
}

AnimationEvent_obj::~AnimationEvent_obj() { }

Dynamic AnimationEvent_obj::__CreateEmpty() { return  new AnimationEvent_obj; }
hx::ObjectPtr< AnimationEvent_obj > AnimationEvent_obj::__new(::String type,hx::Null< bool >  __o_bubbles,hx::Null< bool >  __o_cancelable)
{  hx::ObjectPtr< AnimationEvent_obj > result = new AnimationEvent_obj();
	result->__construct(type,__o_bubbles,__o_cancelable);
	return result;}

Dynamic AnimationEvent_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< AnimationEvent_obj > result = new AnimationEvent_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}

::native::events::Event AnimationEvent_obj::clone( ){
	HX_STACK_PUSH("AnimationEvent::clone","hxDragonBones/events/AnimationEvent.hx",28);
	HX_STACK_THIS(this);
	HX_STACK_LINE(29)
	::hxDragonBones::events::AnimationEvent event = ::hxDragonBones::events::AnimationEvent_obj::__new(this->get_type(),this->get_cancelable(),null());		HX_STACK_VAR(event,"event");
	HX_STACK_LINE(30)
	event->exMovementID = this->exMovementID;
	HX_STACK_LINE(31)
	event->movementID = this->movementID;
	HX_STACK_LINE(32)
	return event;
}


::hxDragonBones::Armature AnimationEvent_obj::get_armature( ){
	HX_STACK_PUSH("AnimationEvent::get_armature","hxDragonBones/events/AnimationEvent.hx",24);
	HX_STACK_THIS(this);
	HX_STACK_LINE(24)
	return hx::TCast< hxDragonBones::Armature >::cast(this->get_target());
}


HX_DEFINE_DYNAMIC_FUNC0(AnimationEvent_obj,get_armature,return )

::String AnimationEvent_obj::MOVEMENT_CHANGE;

::String AnimationEvent_obj::START;

::String AnimationEvent_obj::COMPLETE;

::String AnimationEvent_obj::LOOP_COMPLETE;


AnimationEvent_obj::AnimationEvent_obj()
{
}

void AnimationEvent_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(AnimationEvent);
	HX_MARK_MEMBER_NAME(armature,"armature");
	HX_MARK_MEMBER_NAME(movementID,"movementID");
	HX_MARK_MEMBER_NAME(exMovementID,"exMovementID");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void AnimationEvent_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(armature,"armature");
	HX_VISIT_MEMBER_NAME(movementID,"movementID");
	HX_VISIT_MEMBER_NAME(exMovementID,"exMovementID");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic AnimationEvent_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"START") ) { return START; }
		if (HX_FIELD_EQ(inName,"clone") ) { return clone_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"COMPLETE") ) { return COMPLETE; }
		if (HX_FIELD_EQ(inName,"armature") ) { return inCallProp ? get_armature() : armature; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"movementID") ) { return movementID; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"get_armature") ) { return get_armature_dyn(); }
		if (HX_FIELD_EQ(inName,"exMovementID") ) { return exMovementID; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"LOOP_COMPLETE") ) { return LOOP_COMPLETE; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"MOVEMENT_CHANGE") ) { return MOVEMENT_CHANGE; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic AnimationEvent_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"START") ) { START=inValue.Cast< ::String >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"COMPLETE") ) { COMPLETE=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"armature") ) { armature=inValue.Cast< ::hxDragonBones::Armature >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"movementID") ) { movementID=inValue.Cast< ::String >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"exMovementID") ) { exMovementID=inValue.Cast< ::String >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"LOOP_COMPLETE") ) { LOOP_COMPLETE=inValue.Cast< ::String >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"MOVEMENT_CHANGE") ) { MOVEMENT_CHANGE=inValue.Cast< ::String >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void AnimationEvent_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("armature"));
	outFields->push(HX_CSTRING("movementID"));
	outFields->push(HX_CSTRING("exMovementID"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("MOVEMENT_CHANGE"),
	HX_CSTRING("START"),
	HX_CSTRING("COMPLETE"),
	HX_CSTRING("LOOP_COMPLETE"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("clone"),
	HX_CSTRING("get_armature"),
	HX_CSTRING("armature"),
	HX_CSTRING("movementID"),
	HX_CSTRING("exMovementID"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(AnimationEvent_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(AnimationEvent_obj::MOVEMENT_CHANGE,"MOVEMENT_CHANGE");
	HX_MARK_MEMBER_NAME(AnimationEvent_obj::START,"START");
	HX_MARK_MEMBER_NAME(AnimationEvent_obj::COMPLETE,"COMPLETE");
	HX_MARK_MEMBER_NAME(AnimationEvent_obj::LOOP_COMPLETE,"LOOP_COMPLETE");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(AnimationEvent_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(AnimationEvent_obj::MOVEMENT_CHANGE,"MOVEMENT_CHANGE");
	HX_VISIT_MEMBER_NAME(AnimationEvent_obj::START,"START");
	HX_VISIT_MEMBER_NAME(AnimationEvent_obj::COMPLETE,"COMPLETE");
	HX_VISIT_MEMBER_NAME(AnimationEvent_obj::LOOP_COMPLETE,"LOOP_COMPLETE");
};

Class AnimationEvent_obj::__mClass;

void AnimationEvent_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("hxDragonBones.events.AnimationEvent"), hx::TCanCast< AnimationEvent_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void AnimationEvent_obj::__boot()
{
	MOVEMENT_CHANGE= HX_CSTRING("movementChange");
	START= HX_CSTRING("start");
	COMPLETE= HX_CSTRING("complete");
	LOOP_COMPLETE= HX_CSTRING("loopComplete");
}

} // end namespace hxDragonBones
} // end namespace events
