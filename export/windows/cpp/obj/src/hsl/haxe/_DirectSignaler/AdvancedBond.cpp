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
#ifndef INCLUDED_hsl_haxe_Signal
#include <hsl/haxe/Signal.h>
#endif
#ifndef INCLUDED_hsl_haxe__DirectSignaler_AdvancedBond
#include <hsl/haxe/_DirectSignaler/AdvancedBond.h>
#endif
#ifndef INCLUDED_hsl_haxe__DirectSignaler_LinkedBond
#include <hsl/haxe/_DirectSignaler/LinkedBond.h>
#endif
namespace hsl{
namespace haxe{
namespace _DirectSignaler{

Void AdvancedBond_obj::__construct(Dynamic listener)
{
HX_STACK_PUSH("AdvancedBond::new","hsl/haxe/DirectSignaler.hx",397);
{
	HX_STACK_LINE(398)
	super::__construct();
	HX_STACK_LINE(399)
	this->listener = listener;
}
;
	return null();
}

AdvancedBond_obj::~AdvancedBond_obj() { }

Dynamic AdvancedBond_obj::__CreateEmpty() { return  new AdvancedBond_obj; }
hx::ObjectPtr< AdvancedBond_obj > AdvancedBond_obj::__new(Dynamic listener)
{  hx::ObjectPtr< AdvancedBond_obj > result = new AdvancedBond_obj();
	result->__construct(listener);
	return result;}

Dynamic AdvancedBond_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< AdvancedBond_obj > result = new AdvancedBond_obj();
	result->__construct(inArgs[0]);
	return result;}

bool AdvancedBond_obj::determineEquals( ::hsl::haxe::_DirectSignaler::LinkedBond _tmp_value){
	HX_STACK_PUSH("AdvancedBond::determineEquals","hsl/haxe/DirectSignaler.hx",416);
	HX_STACK_THIS(this);
	HX_STACK_ARG(_tmp_value,"_tmp_value");
	HX_STACK_LINE(416)
	::hsl::haxe::_DirectSignaler::LinkedBond value = _tmp_value;		HX_STACK_VAR(value,"value");
	HX_STACK_LINE(416)
	return (bool(::Std_obj::is(value,hx::ClassOf< ::hsl::haxe::_DirectSignaler::AdvancedBond >())) && bool(::Reflect_obj::compareMethods(value->__Field(HX_CSTRING("listener"),true),this->listener_dyn())));
}


int AdvancedBond_obj::callListener( Dynamic _tmp_data,Dynamic currentTarget,Dynamic origin,int propagationStatus){
	HX_STACK_PUSH("AdvancedBond::callListener","hsl/haxe/DirectSignaler.hx",401);
	HX_STACK_THIS(this);
	HX_STACK_ARG(_tmp_data,"_tmp_data");
	HX_STACK_ARG(currentTarget,"currentTarget");
	HX_STACK_ARG(origin,"origin");
	HX_STACK_ARG(propagationStatus,"propagationStatus");
	HX_STACK_LINE(402)
	Dynamic data = _tmp_data;		HX_STACK_VAR(data,"data");
	HX_STACK_LINE(402)
	if (((this->halted == false))){
		HX_STACK_LINE(403)
		::hsl::haxe::Signal signal = ::hsl::haxe::Signal_obj::__new(data,hx::ObjectPtr<OBJ_>(this),currentTarget,origin);		HX_STACK_VAR(signal,"signal");
		HX_STACK_LINE(404)
		this->listener(signal);
		HX_STACK_LINE(405)
		if ((this->willDestroyOnUse)){
			HX_STACK_LINE(405)
			if (((false == this->destroyed))){
				HX_STACK_LINE(406)
				this->previous->next = this->next;
				HX_STACK_LINE(406)
				this->next->previous = this->previous;
				HX_STACK_LINE(406)
				this->destroyed = true;
			}
		}
		HX_STACK_LINE(408)
		if ((signal->immediatePropagationStopped)){
			HX_STACK_LINE(408)
			return (int)1;
		}
		else{
			HX_STACK_LINE(410)
			if ((signal->propagationStopped)){
				HX_STACK_LINE(410)
				return (int)2;
			}
		}
	}
	HX_STACK_LINE(414)
	return propagationStatus;
}



AdvancedBond_obj::AdvancedBond_obj()
{
}

void AdvancedBond_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(AdvancedBond);
	HX_MARK_MEMBER_NAME(listener,"listener");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void AdvancedBond_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(listener,"listener");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic AdvancedBond_obj::__Field(const ::String &inName,bool inCallProp)
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

Dynamic AdvancedBond_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"listener") ) { listener=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void AdvancedBond_obj::__GetFields(Array< ::String> &outFields)
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
	HX_MARK_MEMBER_NAME(AdvancedBond_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(AdvancedBond_obj::__mClass,"__mClass");
};

Class AdvancedBond_obj::__mClass;

void AdvancedBond_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("hsl.haxe._DirectSignaler.AdvancedBond"), hx::TCanCast< AdvancedBond_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void AdvancedBond_obj::__boot()
{
}

} // end namespace hsl
} // end namespace haxe
} // end namespace _DirectSignaler
