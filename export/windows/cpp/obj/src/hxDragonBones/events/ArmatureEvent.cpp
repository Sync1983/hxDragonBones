#include <hxcpp.h>

#ifndef INCLUDED_hxDragonBones_events_ArmatureEvent
#include <hxDragonBones/events/ArmatureEvent.h>
#endif
#ifndef INCLUDED_native_events_Event
#include <native/events/Event.h>
#endif
namespace hxDragonBones{
namespace events{

Void ArmatureEvent_obj::__construct(::String type,hx::Null< bool >  __o_bubbles,hx::Null< bool >  __o_cancelable)
{
HX_STACK_PUSH("ArmatureEvent::new","hxDragonBones/events/ArmatureEvent.hx",12);
bool bubbles = __o_bubbles.Default(false);
bool cancelable = __o_cancelable.Default(false);
{
	HX_STACK_LINE(12)
	super::__construct(type,false,false);
}
;
	return null();
}

ArmatureEvent_obj::~ArmatureEvent_obj() { }

Dynamic ArmatureEvent_obj::__CreateEmpty() { return  new ArmatureEvent_obj; }
hx::ObjectPtr< ArmatureEvent_obj > ArmatureEvent_obj::__new(::String type,hx::Null< bool >  __o_bubbles,hx::Null< bool >  __o_cancelable)
{  hx::ObjectPtr< ArmatureEvent_obj > result = new ArmatureEvent_obj();
	result->__construct(type,__o_bubbles,__o_cancelable);
	return result;}

Dynamic ArmatureEvent_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< ArmatureEvent_obj > result = new ArmatureEvent_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}

::native::events::Event ArmatureEvent_obj::clone( ){
	HX_STACK_PUSH("ArmatureEvent::clone","hxDragonBones/events/ArmatureEvent.hx",16);
	HX_STACK_THIS(this);
	HX_STACK_LINE(16)
	return ::hxDragonBones::events::ArmatureEvent_obj::__new(this->get_type(),null(),null());
}


::String ArmatureEvent_obj::Z_ORDER_UPDATED;


ArmatureEvent_obj::ArmatureEvent_obj()
{
}

void ArmatureEvent_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(ArmatureEvent);
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void ArmatureEvent_obj::__Visit(HX_VISIT_PARAMS)
{
	super::__Visit(HX_VISIT_ARG);
}

Dynamic ArmatureEvent_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"clone") ) { return clone_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"Z_ORDER_UPDATED") ) { return Z_ORDER_UPDATED; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic ArmatureEvent_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 15:
		if (HX_FIELD_EQ(inName,"Z_ORDER_UPDATED") ) { Z_ORDER_UPDATED=inValue.Cast< ::String >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void ArmatureEvent_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("Z_ORDER_UPDATED"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("clone"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(ArmatureEvent_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(ArmatureEvent_obj::Z_ORDER_UPDATED,"Z_ORDER_UPDATED");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(ArmatureEvent_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(ArmatureEvent_obj::Z_ORDER_UPDATED,"Z_ORDER_UPDATED");
};

Class ArmatureEvent_obj::__mClass;

void ArmatureEvent_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("hxDragonBones.events.ArmatureEvent"), hx::TCanCast< ArmatureEvent_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void ArmatureEvent_obj::__boot()
{
	Z_ORDER_UPDATED= HX_CSTRING("zOrderUpdated");
}

} // end namespace hxDragonBones
} // end namespace events
