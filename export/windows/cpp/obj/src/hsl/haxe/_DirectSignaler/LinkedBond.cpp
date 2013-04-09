#include <hxcpp.h>

#ifndef INCLUDED_hsl_haxe_Bond
#include <hsl/haxe/Bond.h>
#endif
#ifndef INCLUDED_hsl_haxe__DirectSignaler_LinkedBond
#include <hsl/haxe/_DirectSignaler/LinkedBond.h>
#endif
namespace hsl{
namespace haxe{
namespace _DirectSignaler{

Void LinkedBond_obj::__construct()
{
HX_STACK_PUSH("LinkedBond::new","hsl/haxe/DirectSignaler.hx",234);
{
	HX_STACK_LINE(235)
	super::__construct();
	HX_STACK_LINE(238)
	this->destroyed = false;
}
;
	return null();
}

LinkedBond_obj::~LinkedBond_obj() { }

Dynamic LinkedBond_obj::__CreateEmpty() { return  new LinkedBond_obj; }
hx::ObjectPtr< LinkedBond_obj > LinkedBond_obj::__new()
{  hx::ObjectPtr< LinkedBond_obj > result = new LinkedBond_obj();
	result->__construct();
	return result;}

Dynamic LinkedBond_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< LinkedBond_obj > result = new LinkedBond_obj();
	result->__construct();
	return result;}

Void LinkedBond_obj::unlink( ){
{
		HX_STACK_PUSH("LinkedBond::unlink","hsl/haxe/DirectSignaler.hx",261);
		HX_STACK_THIS(this);
		HX_STACK_LINE(261)
		if (((false == this->destroyed))){
			HX_STACK_LINE(264)
			this->previous->next = this->next;
			HX_STACK_LINE(265)
			this->next->previous = this->previous;
			HX_STACK_LINE(266)
			this->destroyed = true;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(LinkedBond_obj,unlink,(void))

Void LinkedBond_obj::destroy( ){
{
		HX_STACK_PUSH("LinkedBond::destroy","hsl/haxe/DirectSignaler.hx",254);
		HX_STACK_THIS(this);
		HX_STACK_LINE(254)
		if (((false == this->destroyed))){
			HX_STACK_LINE(257)
			this->previous->next = this->next;
			HX_STACK_LINE(257)
			this->next->previous = this->previous;
			HX_STACK_LINE(257)
			this->destroyed = true;
		}
	}
return null();
}


bool LinkedBond_obj::determineEquals( ::hsl::haxe::_DirectSignaler::LinkedBond value){
	HX_STACK_PUSH("LinkedBond::determineEquals","hsl/haxe/DirectSignaler.hx",251);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(251)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC1(LinkedBond_obj,determineEquals,return )

int LinkedBond_obj::callListener( Dynamic data,Dynamic currentTarget,Dynamic origin,int propagationStatus){
	HX_STACK_PUSH("LinkedBond::callListener","hsl/haxe/DirectSignaler.hx",244);
	HX_STACK_THIS(this);
	HX_STACK_ARG(data,"data");
	HX_STACK_ARG(currentTarget,"currentTarget");
	HX_STACK_ARG(origin,"origin");
	HX_STACK_ARG(propagationStatus,"propagationStatus");
	HX_STACK_LINE(244)
	return (int)0;
}


HX_DEFINE_DYNAMIC_FUNC4(LinkedBond_obj,callListener,return )


LinkedBond_obj::LinkedBond_obj()
{
}

void LinkedBond_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(LinkedBond);
	HX_MARK_MEMBER_NAME(previous,"previous");
	HX_MARK_MEMBER_NAME(next,"next");
	HX_MARK_MEMBER_NAME(destroyed,"destroyed");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void LinkedBond_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(previous,"previous");
	HX_VISIT_MEMBER_NAME(next,"next");
	HX_VISIT_MEMBER_NAME(destroyed,"destroyed");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic LinkedBond_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"next") ) { return next; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"unlink") ) { return unlink_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"destroy") ) { return destroy_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"previous") ) { return previous; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"destroyed") ) { return destroyed; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"callListener") ) { return callListener_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"determineEquals") ) { return determineEquals_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic LinkedBond_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"next") ) { next=inValue.Cast< ::hsl::haxe::_DirectSignaler::LinkedBond >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"previous") ) { previous=inValue.Cast< ::hsl::haxe::_DirectSignaler::LinkedBond >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"destroyed") ) { destroyed=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void LinkedBond_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("previous"));
	outFields->push(HX_CSTRING("next"));
	outFields->push(HX_CSTRING("destroyed"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("unlink"),
	HX_CSTRING("destroy"),
	HX_CSTRING("determineEquals"),
	HX_CSTRING("callListener"),
	HX_CSTRING("previous"),
	HX_CSTRING("next"),
	HX_CSTRING("destroyed"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(LinkedBond_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(LinkedBond_obj::__mClass,"__mClass");
};

Class LinkedBond_obj::__mClass;

void LinkedBond_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("hsl.haxe._DirectSignaler.LinkedBond"), hx::TCanCast< LinkedBond_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void LinkedBond_obj::__boot()
{
}

} // end namespace hsl
} // end namespace haxe
} // end namespace _DirectSignaler
