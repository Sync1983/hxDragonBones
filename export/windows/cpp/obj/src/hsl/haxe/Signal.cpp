#include <hxcpp.h>

#ifndef INCLUDED_hsl_haxe_Bond
#include <hsl/haxe/Bond.h>
#endif
#ifndef INCLUDED_hsl_haxe_Signal
#include <hsl/haxe/Signal.h>
#endif
namespace hsl{
namespace haxe{

Void Signal_obj::__construct(Dynamic data,::hsl::haxe::Bond currentBond,Dynamic currentTarget,Dynamic origin)
{
HX_STACK_PUSH("Signal::new","hsl/haxe/Signal.hx",136);
{
	HX_STACK_LINE(137)
	this->data = data;
	HX_STACK_LINE(138)
	this->currentBond = currentBond;
	HX_STACK_LINE(139)
	this->currentTarget = currentTarget;
	HX_STACK_LINE(140)
	this->origin = origin;
	HX_STACK_LINE(144)
	this->immediatePropagationStopped = false;
	HX_STACK_LINE(145)
	this->propagationStopped = false;
}
;
	return null();
}

Signal_obj::~Signal_obj() { }

Dynamic Signal_obj::__CreateEmpty() { return  new Signal_obj; }
hx::ObjectPtr< Signal_obj > Signal_obj::__new(Dynamic data,::hsl::haxe::Bond currentBond,Dynamic currentTarget,Dynamic origin)
{  hx::ObjectPtr< Signal_obj > result = new Signal_obj();
	result->__construct(data,currentBond,currentTarget,origin);
	return result;}

Dynamic Signal_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Signal_obj > result = new Signal_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3]);
	return result;}

Void Signal_obj::stopPropagation( ){
{
		HX_STACK_PUSH("Signal::stopPropagation","hsl/haxe/Signal.hx",226);
		HX_STACK_THIS(this);
		HX_STACK_LINE(226)
		this->propagationStopped = true;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Signal_obj,stopPropagation,(void))

Void Signal_obj::stopImmediatePropagation( ){
{
		HX_STACK_PUSH("Signal::stopImmediatePropagation","hsl/haxe/Signal.hx",213);
		HX_STACK_THIS(this);
		HX_STACK_LINE(213)
		this->immediatePropagationStopped = true;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Signal_obj,stopImmediatePropagation,(void))

Dynamic Signal_obj::getData( ){
	HX_STACK_PUSH("Signal::getData","hsl/haxe/Signal.hx",148);
	HX_STACK_THIS(this);
	HX_STACK_LINE(148)
	return this->data;
}


HX_DEFINE_DYNAMIC_FUNC0(Signal_obj,getData,return )


Signal_obj::Signal_obj()
{
}

void Signal_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Signal);
	HX_MARK_MEMBER_NAME(propagationStopped,"propagationStopped");
	HX_MARK_MEMBER_NAME(origin,"origin");
	HX_MARK_MEMBER_NAME(immediatePropagationStopped,"immediatePropagationStopped");
	HX_MARK_MEMBER_NAME(data1,"data1");
	HX_MARK_MEMBER_NAME(data,"data");
	HX_MARK_MEMBER_NAME(currentTarget,"currentTarget");
	HX_MARK_MEMBER_NAME(currentBond,"currentBond");
	HX_MARK_END_CLASS();
}

void Signal_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(propagationStopped,"propagationStopped");
	HX_VISIT_MEMBER_NAME(origin,"origin");
	HX_VISIT_MEMBER_NAME(immediatePropagationStopped,"immediatePropagationStopped");
	HX_VISIT_MEMBER_NAME(data1,"data1");
	HX_VISIT_MEMBER_NAME(data,"data");
	HX_VISIT_MEMBER_NAME(currentTarget,"currentTarget");
	HX_VISIT_MEMBER_NAME(currentBond,"currentBond");
}

Dynamic Signal_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"data") ) { return data; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"data1") ) { return inCallProp ? getData() : data1; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"origin") ) { return origin; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"getData") ) { return getData_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"currentBond") ) { return currentBond; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"currentTarget") ) { return currentTarget; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"stopPropagation") ) { return stopPropagation_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"propagationStopped") ) { return propagationStopped; }
		break;
	case 24:
		if (HX_FIELD_EQ(inName,"stopImmediatePropagation") ) { return stopImmediatePropagation_dyn(); }
		break;
	case 27:
		if (HX_FIELD_EQ(inName,"immediatePropagationStopped") ) { return immediatePropagationStopped; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Signal_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"data") ) { data=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"data1") ) { data1=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"origin") ) { origin=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"currentBond") ) { currentBond=inValue.Cast< ::hsl::haxe::Bond >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"currentTarget") ) { currentTarget=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"propagationStopped") ) { propagationStopped=inValue.Cast< bool >(); return inValue; }
		break;
	case 27:
		if (HX_FIELD_EQ(inName,"immediatePropagationStopped") ) { immediatePropagationStopped=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Signal_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("propagationStopped"));
	outFields->push(HX_CSTRING("origin"));
	outFields->push(HX_CSTRING("immediatePropagationStopped"));
	outFields->push(HX_CSTRING("data1"));
	outFields->push(HX_CSTRING("data"));
	outFields->push(HX_CSTRING("currentTarget"));
	outFields->push(HX_CSTRING("currentBond"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("stopPropagation"),
	HX_CSTRING("stopImmediatePropagation"),
	HX_CSTRING("getData"),
	HX_CSTRING("propagationStopped"),
	HX_CSTRING("origin"),
	HX_CSTRING("immediatePropagationStopped"),
	HX_CSTRING("data1"),
	HX_CSTRING("data"),
	HX_CSTRING("currentTarget"),
	HX_CSTRING("currentBond"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Signal_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Signal_obj::__mClass,"__mClass");
};

Class Signal_obj::__mClass;

void Signal_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("hsl.haxe.Signal"), hx::TCanCast< Signal_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Signal_obj::__boot()
{
}

} // end namespace hsl
} // end namespace haxe
