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
#ifndef INCLUDED_hxDragonBones_events_FrameEvent
#include <hxDragonBones/events/FrameEvent.h>
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

Void FrameEvent_obj::__construct(::String type,hx::Null< bool >  __o_bubbles,hx::Null< bool >  __o_cancelable,::hxDragonBones::Bone bone)
{
HX_STACK_PUSH("FrameEvent::new","hxDragonBones/events/FrameEvent.hx",15);
bool bubbles = __o_bubbles.Default(false);
bool cancelable = __o_cancelable.Default(false);
{
	HX_STACK_LINE(16)
	super::__construct(type,false,cancelable);
	HX_STACK_LINE(17)
	this->bone = bone;
}
;
	return null();
}

FrameEvent_obj::~FrameEvent_obj() { }

Dynamic FrameEvent_obj::__CreateEmpty() { return  new FrameEvent_obj; }
hx::ObjectPtr< FrameEvent_obj > FrameEvent_obj::__new(::String type,hx::Null< bool >  __o_bubbles,hx::Null< bool >  __o_cancelable,::hxDragonBones::Bone bone)
{  hx::ObjectPtr< FrameEvent_obj > result = new FrameEvent_obj();
	result->__construct(type,__o_bubbles,__o_cancelable,bone);
	return result;}

Dynamic FrameEvent_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< FrameEvent_obj > result = new FrameEvent_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3]);
	return result;}

::native::events::Event FrameEvent_obj::clone( ){
	HX_STACK_PUSH("FrameEvent::clone","hxDragonBones/events/FrameEvent.hx",29);
	HX_STACK_THIS(this);
	HX_STACK_LINE(30)
	::hxDragonBones::events::FrameEvent event = ::hxDragonBones::events::FrameEvent_obj::__new(this->get_type(),this->get_cancelable(),null(),null());		HX_STACK_VAR(event,"event");
	HX_STACK_LINE(31)
	event->movementID = this->movementID;
	HX_STACK_LINE(32)
	event->frameLabel = this->frameLabel;
	HX_STACK_LINE(33)
	event->bone = this->bone;
	HX_STACK_LINE(34)
	return event;
}


::hxDragonBones::Armature FrameEvent_obj::get_armature( ){
	HX_STACK_PUSH("FrameEvent::get_armature","hxDragonBones/events/FrameEvent.hx",25);
	HX_STACK_THIS(this);
	HX_STACK_LINE(25)
	return hx::TCast< hxDragonBones::Armature >::cast(this->get_target());
}


HX_DEFINE_DYNAMIC_FUNC0(FrameEvent_obj,get_armature,return )

::String FrameEvent_obj::MOVEMENT_FRAME_EVENT;

::String FrameEvent_obj::BONE_FRAME_EVENT;


FrameEvent_obj::FrameEvent_obj()
{
}

void FrameEvent_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(FrameEvent);
	HX_MARK_MEMBER_NAME(bone,"bone");
	HX_MARK_MEMBER_NAME(armature,"armature");
	HX_MARK_MEMBER_NAME(frameLabel,"frameLabel");
	HX_MARK_MEMBER_NAME(movementID,"movementID");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void FrameEvent_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(bone,"bone");
	HX_VISIT_MEMBER_NAME(armature,"armature");
	HX_VISIT_MEMBER_NAME(frameLabel,"frameLabel");
	HX_VISIT_MEMBER_NAME(movementID,"movementID");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic FrameEvent_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"bone") ) { return bone; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"clone") ) { return clone_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"armature") ) { return inCallProp ? get_armature() : armature; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"frameLabel") ) { return frameLabel; }
		if (HX_FIELD_EQ(inName,"movementID") ) { return movementID; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"get_armature") ) { return get_armature_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"BONE_FRAME_EVENT") ) { return BONE_FRAME_EVENT; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"MOVEMENT_FRAME_EVENT") ) { return MOVEMENT_FRAME_EVENT; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic FrameEvent_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"bone") ) { bone=inValue.Cast< ::hxDragonBones::Bone >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"armature") ) { armature=inValue.Cast< ::hxDragonBones::Armature >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"frameLabel") ) { frameLabel=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"movementID") ) { movementID=inValue.Cast< ::String >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"BONE_FRAME_EVENT") ) { BONE_FRAME_EVENT=inValue.Cast< ::String >(); return inValue; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"MOVEMENT_FRAME_EVENT") ) { MOVEMENT_FRAME_EVENT=inValue.Cast< ::String >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void FrameEvent_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("bone"));
	outFields->push(HX_CSTRING("armature"));
	outFields->push(HX_CSTRING("frameLabel"));
	outFields->push(HX_CSTRING("movementID"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("MOVEMENT_FRAME_EVENT"),
	HX_CSTRING("BONE_FRAME_EVENT"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("clone"),
	HX_CSTRING("get_armature"),
	HX_CSTRING("bone"),
	HX_CSTRING("armature"),
	HX_CSTRING("frameLabel"),
	HX_CSTRING("movementID"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(FrameEvent_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(FrameEvent_obj::MOVEMENT_FRAME_EVENT,"MOVEMENT_FRAME_EVENT");
	HX_MARK_MEMBER_NAME(FrameEvent_obj::BONE_FRAME_EVENT,"BONE_FRAME_EVENT");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(FrameEvent_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(FrameEvent_obj::MOVEMENT_FRAME_EVENT,"MOVEMENT_FRAME_EVENT");
	HX_VISIT_MEMBER_NAME(FrameEvent_obj::BONE_FRAME_EVENT,"BONE_FRAME_EVENT");
};

Class FrameEvent_obj::__mClass;

void FrameEvent_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("hxDragonBones.events.FrameEvent"), hx::TCanCast< FrameEvent_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void FrameEvent_obj::__boot()
{
	MOVEMENT_FRAME_EVENT= HX_CSTRING("movementFrameEvent");
	BONE_FRAME_EVENT= HX_CSTRING("boneFrameEvent");
}

} // end namespace hxDragonBones
} // end namespace events
