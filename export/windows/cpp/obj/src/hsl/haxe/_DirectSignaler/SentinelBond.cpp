#include <hxcpp.h>

#ifndef INCLUDED_hsl_haxe_Bond
#include <hsl/haxe/Bond.h>
#endif
#ifndef INCLUDED_hsl_haxe__DirectSignaler_LinkedBond
#include <hsl/haxe/_DirectSignaler/LinkedBond.h>
#endif
#ifndef INCLUDED_hsl_haxe__DirectSignaler_SentinelBond
#include <hsl/haxe/_DirectSignaler/SentinelBond.h>
#endif
namespace hsl{
namespace haxe{
namespace _DirectSignaler{

Void SentinelBond_obj::__construct()
{
HX_STACK_PUSH("SentinelBond::new","hsl/haxe/DirectSignaler.hx",283);
{
	HX_STACK_LINE(284)
	super::__construct();
	HX_STACK_LINE(285)
	this->next = this->previous = hx::ObjectPtr<OBJ_>(this);
}
;
	return null();
}

SentinelBond_obj::~SentinelBond_obj() { }

Dynamic SentinelBond_obj::__CreateEmpty() { return  new SentinelBond_obj; }
hx::ObjectPtr< SentinelBond_obj > SentinelBond_obj::__new()
{  hx::ObjectPtr< SentinelBond_obj > result = new SentinelBond_obj();
	result->__construct();
	return result;}

Dynamic SentinelBond_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< SentinelBond_obj > result = new SentinelBond_obj();
	result->__construct();
	return result;}

Void SentinelBond_obj::remove( ::hsl::haxe::_DirectSignaler::LinkedBond value){
{
		HX_STACK_PUSH("SentinelBond::remove","hsl/haxe/DirectSignaler.hx",317);
		HX_STACK_THIS(this);
		HX_STACK_ARG(value,"value");
		HX_STACK_LINE(318)
		::hsl::haxe::_DirectSignaler::LinkedBond node = this->next;		HX_STACK_VAR(node,"node");
		HX_STACK_LINE(319)
		while(((node != hx::ObjectPtr<OBJ_>(this)))){
			HX_STACK_LINE(320)
			if ((node->determineEquals(value))){
				HX_STACK_LINE(321)
				if (((false == node->destroyed))){
					HX_STACK_LINE(321)
					node->previous->next = node->next;
					HX_STACK_LINE(321)
					node->next->previous = node->previous;
					HX_STACK_LINE(321)
					node->destroyed = true;
				}
				HX_STACK_LINE(322)
				break;
			}
			HX_STACK_LINE(324)
			node = node->next;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(SentinelBond_obj,remove,(void))

bool SentinelBond_obj::getIsConnected( ){
	HX_STACK_PUSH("SentinelBond::getIsConnected","hsl/haxe/DirectSignaler.hx",307);
	HX_STACK_THIS(this);
	HX_STACK_LINE(307)
	return (this->next != hx::ObjectPtr<OBJ_>(this));
}


HX_DEFINE_DYNAMIC_FUNC0(SentinelBond_obj,getIsConnected,return )

int SentinelBond_obj::callListener( Dynamic _tmp_data,Dynamic currentTarget,Dynamic origin,int propagationStatus){
	HX_STACK_PUSH("SentinelBond::callListener","hsl/haxe/DirectSignaler.hx",296);
	HX_STACK_THIS(this);
	HX_STACK_ARG(_tmp_data,"_tmp_data");
	HX_STACK_ARG(currentTarget,"currentTarget");
	HX_STACK_ARG(origin,"origin");
	HX_STACK_ARG(propagationStatus,"propagationStatus");
	HX_STACK_LINE(297)
	Dynamic data = _tmp_data;		HX_STACK_VAR(data,"data");
	HX_STACK_LINE(297)
	::hsl::haxe::_DirectSignaler::LinkedBond node = this->next;		HX_STACK_VAR(node,"node");
	HX_STACK_LINE(298)
	while(((bool((node != hx::ObjectPtr<OBJ_>(this))) && bool(((int)1 != propagationStatus))))){
		HX_STACK_LINE(299)
		propagationStatus = node->callListener(data,currentTarget,origin,propagationStatus);
		HX_STACK_LINE(300)
		node = node->next;
	}
	HX_STACK_LINE(302)
	return propagationStatus;
}


::hsl::haxe::_DirectSignaler::LinkedBond SentinelBond_obj::add( ::hsl::haxe::_DirectSignaler::LinkedBond value){
	HX_STACK_PUSH("SentinelBond::add","hsl/haxe/DirectSignaler.hx",291);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(292)
	value->next = hx::ObjectPtr<OBJ_>(this);
	HX_STACK_LINE(293)
	value->previous = this->previous;
	HX_STACK_LINE(294)
	return this->previous = this->previous->next = value;
}


HX_DEFINE_DYNAMIC_FUNC1(SentinelBond_obj,add,return )


SentinelBond_obj::SentinelBond_obj()
{
}

void SentinelBond_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(SentinelBond);
	HX_MARK_MEMBER_NAME(isConnected,"isConnected");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void SentinelBond_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(isConnected,"isConnected");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic SentinelBond_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"add") ) { return add_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"remove") ) { return remove_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"isConnected") ) { return inCallProp ? getIsConnected() : isConnected; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"callListener") ) { return callListener_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"getIsConnected") ) { return getIsConnected_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic SentinelBond_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 11:
		if (HX_FIELD_EQ(inName,"isConnected") ) { isConnected=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void SentinelBond_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("isConnected"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("remove"),
	HX_CSTRING("getIsConnected"),
	HX_CSTRING("callListener"),
	HX_CSTRING("add"),
	HX_CSTRING("isConnected"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(SentinelBond_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(SentinelBond_obj::__mClass,"__mClass");
};

Class SentinelBond_obj::__mClass;

void SentinelBond_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("hsl.haxe._DirectSignaler.SentinelBond"), hx::TCanCast< SentinelBond_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void SentinelBond_obj::__boot()
{
}

} // end namespace hsl
} // end namespace haxe
} // end namespace _DirectSignaler
