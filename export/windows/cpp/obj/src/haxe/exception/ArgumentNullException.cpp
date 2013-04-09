#include <hxcpp.h>

#ifndef INCLUDED_haxe_exception_ArgumentNullException
#include <haxe/exception/ArgumentNullException.h>
#endif
#ifndef INCLUDED_haxe_exception_Exception
#include <haxe/exception/Exception.h>
#endif
namespace haxe{
namespace exception{

Void ArgumentNullException_obj::__construct(::String argumentName,Dynamic numberOfStackTraceShifts)
{
HX_STACK_PUSH("ArgumentNullException::new","haxe/exception/ArgumentNullException.hx",36);
{
	HX_STACK_LINE(36)
	super::__construct(((HX_CSTRING("Argument ") + argumentName) + HX_CSTRING(" must be non-null")),null(),numberOfStackTraceShifts);
}
;
	return null();
}

ArgumentNullException_obj::~ArgumentNullException_obj() { }

Dynamic ArgumentNullException_obj::__CreateEmpty() { return  new ArgumentNullException_obj; }
hx::ObjectPtr< ArgumentNullException_obj > ArgumentNullException_obj::__new(::String argumentName,Dynamic numberOfStackTraceShifts)
{  hx::ObjectPtr< ArgumentNullException_obj > result = new ArgumentNullException_obj();
	result->__construct(argumentName,numberOfStackTraceShifts);
	return result;}

Dynamic ArgumentNullException_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< ArgumentNullException_obj > result = new ArgumentNullException_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}


ArgumentNullException_obj::ArgumentNullException_obj()
{
}

void ArgumentNullException_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(ArgumentNullException);
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void ArgumentNullException_obj::__Visit(HX_VISIT_PARAMS)
{
	super::__Visit(HX_VISIT_ARG);
}

Dynamic ArgumentNullException_obj::__Field(const ::String &inName,bool inCallProp)
{
	return super::__Field(inName,inCallProp);
}

Dynamic ArgumentNullException_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void ArgumentNullException_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(ArgumentNullException_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(ArgumentNullException_obj::__mClass,"__mClass");
};

Class ArgumentNullException_obj::__mClass;

void ArgumentNullException_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxe.exception.ArgumentNullException"), hx::TCanCast< ArgumentNullException_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void ArgumentNullException_obj::__boot()
{
}

} // end namespace haxe
} // end namespace exception
