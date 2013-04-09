#include <hxcpp.h>

#ifndef INCLUDED_hsl_haxe_Bond
#include <hsl/haxe/Bond.h>
#endif
namespace hsl{
namespace haxe{

Void Bond_obj::__construct()
{
HX_STACK_PUSH("Bond::new","hsl/haxe/Bond.hx",48);
{
	HX_STACK_LINE(48)
	this->halted = false;
}
;
	return null();
}

Bond_obj::~Bond_obj() { }

Dynamic Bond_obj::__CreateEmpty() { return  new Bond_obj; }
hx::ObjectPtr< Bond_obj > Bond_obj::__new()
{  hx::ObjectPtr< Bond_obj > result = new Bond_obj();
	result->__construct();
	return result;}

Dynamic Bond_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Bond_obj > result = new Bond_obj();
	result->__construct();
	return result;}

Void Bond_obj::resume( ){
{
		HX_STACK_PUSH("Bond::resume","hsl/haxe/Bond.hx",80);
		HX_STACK_THIS(this);
		HX_STACK_LINE(80)
		this->halted = false;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Bond_obj,resume,(void))

Void Bond_obj::halt( ){
{
		HX_STACK_PUSH("Bond::halt","hsl/haxe/Bond.hx",73);
		HX_STACK_THIS(this);
		HX_STACK_LINE(73)
		this->halted = true;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Bond_obj,halt,(void))

::hsl::haxe::Bond Bond_obj::destroyOnUse( ){
	HX_STACK_PUSH("Bond::destroyOnUse","hsl/haxe/Bond.hx",65);
	HX_STACK_THIS(this);
	HX_STACK_LINE(66)
	this->willDestroyOnUse = true;
	HX_STACK_LINE(67)
	return hx::ObjectPtr<OBJ_>(this);
}


HX_DEFINE_DYNAMIC_FUNC0(Bond_obj,destroyOnUse,return )

Void Bond_obj::destroy( ){
{
		HX_STACK_PUSH("Bond::destroy","hsl/haxe/Bond.hx",58);
		HX_STACK_THIS(this);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Bond_obj,destroy,(void))


Bond_obj::Bond_obj()
{
}

void Bond_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Bond);
	HX_MARK_MEMBER_NAME(willDestroyOnUse,"willDestroyOnUse");
	HX_MARK_MEMBER_NAME(halted,"halted");
	HX_MARK_END_CLASS();
}

void Bond_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(willDestroyOnUse,"willDestroyOnUse");
	HX_VISIT_MEMBER_NAME(halted,"halted");
}

Dynamic Bond_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"halt") ) { return halt_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"resume") ) { return resume_dyn(); }
		if (HX_FIELD_EQ(inName,"halted") ) { return halted; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"destroy") ) { return destroy_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"destroyOnUse") ) { return destroyOnUse_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"willDestroyOnUse") ) { return willDestroyOnUse; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Bond_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"halted") ) { halted=inValue.Cast< bool >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"willDestroyOnUse") ) { willDestroyOnUse=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Bond_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("willDestroyOnUse"));
	outFields->push(HX_CSTRING("halted"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("resume"),
	HX_CSTRING("halt"),
	HX_CSTRING("destroyOnUse"),
	HX_CSTRING("destroy"),
	HX_CSTRING("willDestroyOnUse"),
	HX_CSTRING("halted"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Bond_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Bond_obj::__mClass,"__mClass");
};

Class Bond_obj::__mClass;

void Bond_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("hsl.haxe.Bond"), hx::TCanCast< Bond_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Bond_obj::__boot()
{
}

} // end namespace hsl
} // end namespace haxe
