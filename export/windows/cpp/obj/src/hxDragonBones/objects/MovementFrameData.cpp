#include <hxcpp.h>

#ifndef INCLUDED_hxDragonBones_objects_MovementFrameData
#include <hxDragonBones/objects/MovementFrameData.h>
#endif
namespace hxDragonBones{
namespace objects{

Void MovementFrameData_obj::__construct()
{
HX_STACK_PUSH("MovementFrameData::new","hxDragonBones/objects/MovementFrameData.hx",8);
{
}
;
	return null();
}

MovementFrameData_obj::~MovementFrameData_obj() { }

Dynamic MovementFrameData_obj::__CreateEmpty() { return  new MovementFrameData_obj; }
hx::ObjectPtr< MovementFrameData_obj > MovementFrameData_obj::__new()
{  hx::ObjectPtr< MovementFrameData_obj > result = new MovementFrameData_obj();
	result->__construct();
	return result;}

Dynamic MovementFrameData_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< MovementFrameData_obj > result = new MovementFrameData_obj();
	result->__construct();
	return result;}

Void MovementFrameData_obj::setValues( Float duration,::String movement,::String event,::String sound){
{
		HX_STACK_PUSH("MovementFrameData::setValues","hxDragonBones/objects/MovementFrameData.hx",17);
		HX_STACK_THIS(this);
		HX_STACK_ARG(duration,"duration");
		HX_STACK_ARG(movement,"movement");
		HX_STACK_ARG(event,"event");
		HX_STACK_ARG(sound,"sound");
		HX_STACK_LINE(18)
		this->duration = duration;
		HX_STACK_LINE(19)
		this->movement = movement;
		HX_STACK_LINE(20)
		this->event = event;
		HX_STACK_LINE(21)
		this->sound = sound;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(MovementFrameData_obj,setValues,(void))


MovementFrameData_obj::MovementFrameData_obj()
{
}

void MovementFrameData_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(MovementFrameData);
	HX_MARK_MEMBER_NAME(soundEffect,"soundEffect");
	HX_MARK_MEMBER_NAME(sound,"sound");
	HX_MARK_MEMBER_NAME(event,"event");
	HX_MARK_MEMBER_NAME(movement,"movement");
	HX_MARK_MEMBER_NAME(duration,"duration");
	HX_MARK_END_CLASS();
}

void MovementFrameData_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(soundEffect,"soundEffect");
	HX_VISIT_MEMBER_NAME(sound,"sound");
	HX_VISIT_MEMBER_NAME(event,"event");
	HX_VISIT_MEMBER_NAME(movement,"movement");
	HX_VISIT_MEMBER_NAME(duration,"duration");
}

Dynamic MovementFrameData_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"sound") ) { return sound; }
		if (HX_FIELD_EQ(inName,"event") ) { return event; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"movement") ) { return movement; }
		if (HX_FIELD_EQ(inName,"duration") ) { return duration; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"setValues") ) { return setValues_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"soundEffect") ) { return soundEffect; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic MovementFrameData_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"sound") ) { sound=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"event") ) { event=inValue.Cast< ::String >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"movement") ) { movement=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"duration") ) { duration=inValue.Cast< Float >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"soundEffect") ) { soundEffect=inValue.Cast< ::String >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void MovementFrameData_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("soundEffect"));
	outFields->push(HX_CSTRING("sound"));
	outFields->push(HX_CSTRING("event"));
	outFields->push(HX_CSTRING("movement"));
	outFields->push(HX_CSTRING("duration"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("setValues"),
	HX_CSTRING("soundEffect"),
	HX_CSTRING("sound"),
	HX_CSTRING("event"),
	HX_CSTRING("movement"),
	HX_CSTRING("duration"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(MovementFrameData_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(MovementFrameData_obj::__mClass,"__mClass");
};

Class MovementFrameData_obj::__mClass;

void MovementFrameData_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("hxDragonBones.objects.MovementFrameData"), hx::TCanCast< MovementFrameData_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void MovementFrameData_obj::__boot()
{
}

} // end namespace hxDragonBones
} // end namespace objects
