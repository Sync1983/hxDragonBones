#include <hxcpp.h>

#ifndef INCLUDED_List
#include <List.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_Type
#include <Type.h>
#endif
#ifndef INCLUDED_haxe_TypeTools
#include <haxe/TypeTools.h>
#endif
namespace haxe{

Void TypeTools_obj::__construct()
{
	return null();
}

TypeTools_obj::~TypeTools_obj() { }

Dynamic TypeTools_obj::__CreateEmpty() { return  new TypeTools_obj; }
hx::ObjectPtr< TypeTools_obj > TypeTools_obj::__new()
{  hx::ObjectPtr< TypeTools_obj > result = new TypeTools_obj();
	result->__construct();
	return result;}

Dynamic TypeTools_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< TypeTools_obj > result = new TypeTools_obj();
	result->__construct();
	return result;}

::List TypeTools_obj::getClassNames( Dynamic value){
	HX_STACK_PUSH("TypeTools::getClassNames","haxe/TypeTools.hx",40);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(41)
	::List result = ::List_obj::__new();		HX_STACK_VAR(result,"result");
	HX_STACK_LINE(43)
	::Class valueClass = (  ((::Std_obj::is(value,hx::ClassOf< ::Class >()))) ? ::Class(value) : ::Class(::Type_obj::getClass(value)) );		HX_STACK_VAR(valueClass,"valueClass");
	HX_STACK_LINE(52)
	while(((null() != valueClass))){
		HX_STACK_LINE(53)
		result->add(::Type_obj::getClassName(valueClass));
		HX_STACK_LINE(54)
		valueClass = ::Type_obj::getSuperClass(valueClass);
	}
	HX_STACK_LINE(56)
	return result;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(TypeTools_obj,getClassNames,return )


TypeTools_obj::TypeTools_obj()
{
}

void TypeTools_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(TypeTools);
	HX_MARK_END_CLASS();
}

void TypeTools_obj::__Visit(HX_VISIT_PARAMS)
{
}

Dynamic TypeTools_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 13:
		if (HX_FIELD_EQ(inName,"getClassNames") ) { return getClassNames_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic TypeTools_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void TypeTools_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("getClassNames"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(TypeTools_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(TypeTools_obj::__mClass,"__mClass");
};

Class TypeTools_obj::__mClass;

void TypeTools_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxe.TypeTools"), hx::TCanCast< TypeTools_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void TypeTools_obj::__boot()
{
}

} // end namespace haxe
