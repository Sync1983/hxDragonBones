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
#ifndef INCLUDED_hsl_haxe__DirectSignaler_RegularBond
#include <hsl/haxe/_DirectSignaler/RegularBond.h>
#endif
namespace hsl{
namespace haxe{
namespace _DirectSignaler{

Void RegularBond_obj::__construct(Dynamic listener)
{
HX_STACK_PUSH("RegularBond::new","hsl/haxe/DirectSignaler.hx",333);
{
	HX_STACK_LINE(334)
	super::__construct();
	HX_STACK_LINE(335)
	this->listener = listener;
}
;
	return null();
}

RegularBond_obj::~RegularBond_obj() { }

Dynamic RegularBond_obj::__CreateEmpty() { return  new RegularBond_obj; }
hx::ObjectPtr< RegularBond_obj > RegularBond_obj::__new(Dynamic listener)
{  hx::ObjectPtr< RegularBond_obj > result = new RegularBond_obj();
	result->__construct(listener);
	return result;}

Dynamic RegularBond_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< RegularBond_obj > result = new RegularBond_obj();
	result->__construct(inArgs[0]);
	return result;}

bool RegularBond_obj::determineEquals( ::hsl::haxe::_DirectSignaler::LinkedBond _tmp_value){
	HX_STACK_PUSH("RegularBond::determineEquals","hsl/haxe/DirectSignaler.hx",346);
	HX_STACK_THIS(this);
	HX_STACK_ARG(_tmp_value,"_tmp_value");
	HX_STACK_LINE(346)
	::hsl::haxe::_DirectSignaler::LinkedBond value = _tmp_value;		HX_STACK_VAR(value,"value");
	HX_STACK_LINE(346)
	return (bool(::Std_obj::is(value,hx::ClassOf< ::hsl::haxe::_DirectSignaler::RegularBond >())) && bool(::Reflect_obj::compareMethods(value->__Field(HX_CSTRING("listener"),true),this->listener_dyn())));
}


int RegularBond_obj::callListener( Dynamic _tmp_data,Dynamic currentTarget,Dynamic origin,int propagationStatus){
	HX_STACK_PUSH("RegularBond::callListener","hsl/haxe/DirectSignaler.hx",337);
	HX_STACK_THIS(this);
	HX_STACK_ARG(_tmp_data,"_tmp_data");
	HX_STACK_ARG(currentTarget,"currentTarget");
	HX_STACK_ARG(origin,"origin");
	HX_STACK_ARG(propagationStatus,"propagationStatus");
	HX_STACK_LINE(338)
	Dynamic data = _tmp_data;		HX_STACK_VAR(data,"data");
	HX_STACK_LINE(338)
	if (((false == this->halted))){
		HX_STACK_LINE(339)
		this->listener(data);
		HX_STACK_LINE(340)
		if ((this->willDestroyOnUse)){
			HX_STACK_LINE(340)
			if (((false == this->destroyed))){
				HX_STACK_LINE(341)
				this->previous->next = this->next;
				HX_STACK_LINE(341)
				this->next->previous = this->previous;
				HX_STACK_LINE(341)
				this->destroyed = true;
			}
		}
	}
	HX_STACK_LINE(344)
	return propagationStatus;
}



RegularBond_obj::RegularBond_obj()
{
}

void RegularBond_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(RegularBond);
	HX_MARK_MEMBER_NAME(listener,"listener");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void RegularBond_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(listener,"listener");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic RegularBond_obj::__Field(const ::String &inName,bool inCallProp)
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

Dynamic RegularBond_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"listener") ) { listener=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void RegularBond_obj::__GetFields(Array< ::String> &outFields)
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
	HX_MARK_MEMBER_NAME(RegularBond_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(RegularBond_obj::__mClass,"__mClass");
};

Class RegularBond_obj::__mClass;

void RegularBond_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("hsl.haxe._DirectSignaler.RegularBond"), hx::TCanCast< RegularBond_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void RegularBond_obj::__boot()
{
}

} // end namespace hsl
} // end namespace haxe
} // end namespace _DirectSignaler
