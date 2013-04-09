#include <hxcpp.h>

#ifndef INCLUDED_Reflect
#include <Reflect.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_hsl_haxe_Bond
#include <hsl/haxe/Bond.h>
#endif
#ifndef INCLUDED_hsl_haxe__DirectSignaler_LinkedBond
#include <hsl/haxe/_DirectSignaler/LinkedBond.h>
#endif
#ifndef INCLUDED_hsl_haxe__DirectSignaler_NiladicBond
#include <hsl/haxe/_DirectSignaler/NiladicBond.h>
#endif
namespace hsl{
namespace haxe{
namespace _DirectSignaler{

Void NiladicBond_obj::__construct(Dynamic listener)
{
HX_STACK_PUSH("NiladicBond::new","hsl/haxe/DirectSignaler.hx",365);
{
	HX_STACK_LINE(366)
	super::__construct();
	HX_STACK_LINE(367)
	this->listener = listener;
}
;
	return null();
}

NiladicBond_obj::~NiladicBond_obj() { }

Dynamic NiladicBond_obj::__CreateEmpty() { return  new NiladicBond_obj; }
hx::ObjectPtr< NiladicBond_obj > NiladicBond_obj::__new(Dynamic listener)
{  hx::ObjectPtr< NiladicBond_obj > result = new NiladicBond_obj();
	result->__construct(listener);
	return result;}

Dynamic NiladicBond_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< NiladicBond_obj > result = new NiladicBond_obj();
	result->__construct(inArgs[0]);
	return result;}

bool NiladicBond_obj::determineEquals( ::hsl::haxe::_DirectSignaler::LinkedBond _tmp_value){
	HX_STACK_PUSH("NiladicBond::determineEquals","hsl/haxe/DirectSignaler.hx",378);
	HX_STACK_THIS(this);
	HX_STACK_ARG(_tmp_value,"_tmp_value");
	HX_STACK_LINE(378)
	::hsl::haxe::_DirectSignaler::LinkedBond value = _tmp_value;		HX_STACK_VAR(value,"value");
	HX_STACK_LINE(378)
	return (bool(::Std_obj::is(value,hx::ClassOf< ::hsl::haxe::_DirectSignaler::NiladicBond >())) && bool(::Reflect_obj::compareMethods(value->__Field(HX_CSTRING("listener"),true),this->listener_dyn())));
}


int NiladicBond_obj::callListener( Dynamic _tmp_data,Dynamic currentTarget,Dynamic origin,int propagationStatus){
	HX_STACK_PUSH("NiladicBond::callListener","hsl/haxe/DirectSignaler.hx",369);
	HX_STACK_THIS(this);
	HX_STACK_ARG(_tmp_data,"_tmp_data");
	HX_STACK_ARG(currentTarget,"currentTarget");
	HX_STACK_ARG(origin,"origin");
	HX_STACK_ARG(propagationStatus,"propagationStatus");
	HX_STACK_LINE(370)
	Dynamic data = _tmp_data;		HX_STACK_VAR(data,"data");
	HX_STACK_LINE(370)
	if (((false == this->halted))){
		HX_STACK_LINE(371)
		this->listener();
		HX_STACK_LINE(372)
		if ((this->willDestroyOnUse)){
			HX_STACK_LINE(372)
			if (((false == this->destroyed))){
				HX_STACK_LINE(373)
				this->previous->next = this->next;
				HX_STACK_LINE(373)
				this->next->previous = this->previous;
				HX_STACK_LINE(373)
				this->destroyed = true;
			}
		}
	}
	HX_STACK_LINE(376)
	return propagationStatus;
}



NiladicBond_obj::NiladicBond_obj()
{
}

void NiladicBond_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(NiladicBond);
	HX_MARK_MEMBER_NAME(listener,"listener");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void NiladicBond_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(listener,"listener");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic NiladicBond_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"listener") ) { return listener; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"callListener") ) { return callListener_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"determineEquals") ) { return determineEquals_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic NiladicBond_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"listener") ) { listener=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void NiladicBond_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("determineEquals"),
	HX_CSTRING("callListener"),
	HX_CSTRING("listener"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(NiladicBond_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(NiladicBond_obj::__mClass,"__mClass");
};

Class NiladicBond_obj::__mClass;

void NiladicBond_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("hsl.haxe._DirectSignaler.NiladicBond"), hx::TCanCast< NiladicBond_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void NiladicBond_obj::__boot()
{
}

} // end namespace hsl
} // end namespace haxe
} // end namespace _DirectSignaler
