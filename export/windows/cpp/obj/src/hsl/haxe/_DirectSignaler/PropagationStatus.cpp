#include <hxcpp.h>

#ifndef INCLUDED_hsl_haxe__DirectSignaler_PropagationStatus
#include <hsl/haxe/_DirectSignaler/PropagationStatus.h>
#endif
namespace hsl{
namespace haxe{
namespace _DirectSignaler{

Void PropagationStatus_obj::__construct()
{
	return null();
}

PropagationStatus_obj::~PropagationStatus_obj() { }

Dynamic PropagationStatus_obj::__CreateEmpty() { return  new PropagationStatus_obj; }
hx::ObjectPtr< PropagationStatus_obj > PropagationStatus_obj::__new()
{  hx::ObjectPtr< PropagationStatus_obj > result = new PropagationStatus_obj();
	result->__construct();
	return result;}

Dynamic PropagationStatus_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< PropagationStatus_obj > result = new PropagationStatus_obj();
	result->__construct();
	return result;}

int PropagationStatus_obj::IMMEDIATELY_STOPPED;

int PropagationStatus_obj::STOPPED;

int PropagationStatus_obj::UNDISTURBED;


PropagationStatus_obj::PropagationStatus_obj()
{
}

void PropagationStatus_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(PropagationStatus);
	HX_MARK_END_CLASS();
}

void PropagationStatus_obj::__Visit(HX_VISIT_PARAMS)
{
}

Dynamic PropagationStatus_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"STOPPED") ) { return STOPPED; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"UNDISTURBED") ) { return UNDISTURBED; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"IMMEDIATELY_STOPPED") ) { return IMMEDIATELY_STOPPED; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic PropagationStatus_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"STOPPED") ) { STOPPED=inValue.Cast< int >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"UNDISTURBED") ) { UNDISTURBED=inValue.Cast< int >(); return inValue; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"IMMEDIATELY_STOPPED") ) { IMMEDIATELY_STOPPED=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void PropagationStatus_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("IMMEDIATELY_STOPPED"),
	HX_CSTRING("STOPPED"),
	HX_CSTRING("UNDISTURBED"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(PropagationStatus_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(PropagationStatus_obj::IMMEDIATELY_STOPPED,"IMMEDIATELY_STOPPED");
	HX_MARK_MEMBER_NAME(PropagationStatus_obj::STOPPED,"STOPPED");
	HX_MARK_MEMBER_NAME(PropagationStatus_obj::UNDISTURBED,"UNDISTURBED");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(PropagationStatus_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(PropagationStatus_obj::IMMEDIATELY_STOPPED,"IMMEDIATELY_STOPPED");
	HX_VISIT_MEMBER_NAME(PropagationStatus_obj::STOPPED,"STOPPED");
	HX_VISIT_MEMBER_NAME(PropagationStatus_obj::UNDISTURBED,"UNDISTURBED");
};

Class PropagationStatus_obj::__mClass;

void PropagationStatus_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("hsl.haxe._DirectSignaler.PropagationStatus"), hx::TCanCast< PropagationStatus_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void PropagationStatus_obj::__boot()
{
	IMMEDIATELY_STOPPED= (int)1;
	STOPPED= (int)2;
	UNDISTURBED= (int)3;
}

} // end namespace hsl
} // end namespace haxe
} // end namespace _DirectSignaler
