#include <hxcpp.h>

#ifndef INCLUDED_Type
#include <Type.h>
#endif
#ifndef INCLUDED_haxe_Stack
#include <haxe/Stack.h>
#endif
#ifndef INCLUDED_haxe_StackItem
#include <haxe/StackItem.h>
#endif
#ifndef INCLUDED_haxe_exception_Exception
#include <haxe/exception/Exception.h>
#endif
namespace haxe{
namespace exception{

Void Exception_obj::__construct(::String message,::haxe::exception::Exception innerException,Dynamic numberOfStackTraceShifts)
{
HX_STACK_PUSH("Exception::new","haxe/exception/Exception.hx",60);
{
	HX_STACK_LINE(62)
	this->message = (  (((null() == message))) ? ::String(HX_CSTRING("Unknown exception")) : ::String(message) );
	HX_STACK_LINE(68)
	this->innerException = innerException;
	HX_STACK_LINE(69)
	{
		HX_STACK_LINE(69)
		int numberOfStackTraceShifts1 = numberOfStackTraceShifts;		HX_STACK_VAR(numberOfStackTraceShifts1,"numberOfStackTraceShifts1");
		HX_STACK_LINE(69)
		this->stackTraceArray = ::haxe::Stack_obj::callStack()->slice((numberOfStackTraceShifts1 + (int)1),null());
		HX_STACK_LINE(69)
		::Class exceptionClass = ::Type_obj::getClass(hx::ObjectPtr<OBJ_>(this));		HX_STACK_VAR(exceptionClass,"exceptionClass");
		HX_STACK_LINE(69)
		while(((hx::ClassOf< ::haxe::exception::Exception >() != exceptionClass))){
			HX_STACK_LINE(69)
			this->stackTraceArray->shift();
			HX_STACK_LINE(69)
			exceptionClass = ::Type_obj::getSuperClass(exceptionClass);
		}
	}
	HX_STACK_LINE(70)
	this->stackTrace = this->stackTraceArray;
}
;
	return null();
}

Exception_obj::~Exception_obj() { }

Dynamic Exception_obj::__CreateEmpty() { return  new Exception_obj; }
hx::ObjectPtr< Exception_obj > Exception_obj::__new(::String message,::haxe::exception::Exception innerException,Dynamic numberOfStackTraceShifts)
{  hx::ObjectPtr< Exception_obj > result = new Exception_obj();
	result->__construct(message,innerException,numberOfStackTraceShifts);
	return result;}

Dynamic Exception_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Exception_obj > result = new Exception_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}

::String Exception_obj::toString( ){
	HX_STACK_PUSH("Exception::toString","haxe/exception/Exception.hx",97);
	HX_STACK_THIS(this);
	HX_STACK_LINE(97)
	return (this->message + ::haxe::Stack_obj::toString(this->stackTraceArray));
}


HX_DEFINE_DYNAMIC_FUNC0(Exception_obj,toString,return )

::haxe::exception::Exception Exception_obj::getBaseException( ){
	HX_STACK_PUSH("Exception::getBaseException","haxe/exception/Exception.hx",90);
	HX_STACK_THIS(this);
	HX_STACK_LINE(91)
	::haxe::exception::Exception result = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(result,"result");
	HX_STACK_LINE(92)
	while(((null() != result->innerException))){
		HX_STACK_LINE(92)
		result = result->innerException;
	}
	HX_STACK_LINE(95)
	return result;
}


HX_DEFINE_DYNAMIC_FUNC0(Exception_obj,getBaseException,return )

Void Exception_obj::generateStackTrace( int numberOfStackTraceShifts){
{
		HX_STACK_PUSH("Exception::generateStackTrace","haxe/exception/Exception.hx",77);
		HX_STACK_THIS(this);
		HX_STACK_ARG(numberOfStackTraceShifts,"numberOfStackTraceShifts");
		HX_STACK_LINE(79)
		this->stackTraceArray = ::haxe::Stack_obj::callStack()->slice((numberOfStackTraceShifts + (int)1),null());
		HX_STACK_LINE(81)
		::Class exceptionClass = ::Type_obj::getClass(hx::ObjectPtr<OBJ_>(this));		HX_STACK_VAR(exceptionClass,"exceptionClass");
		HX_STACK_LINE(82)
		while(((hx::ClassOf< ::haxe::exception::Exception >() != exceptionClass))){
			HX_STACK_LINE(83)
			this->stackTraceArray->shift();
			HX_STACK_LINE(84)
			exceptionClass = ::Type_obj::getSuperClass(exceptionClass);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Exception_obj,generateStackTrace,(void))


Exception_obj::Exception_obj()
{
}

void Exception_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Exception);
	HX_MARK_MEMBER_NAME(stackTraceArray,"stackTraceArray");
	HX_MARK_MEMBER_NAME(stackTrace,"stackTrace");
	HX_MARK_MEMBER_NAME(message,"message");
	HX_MARK_MEMBER_NAME(innerException,"innerException");
	HX_MARK_MEMBER_NAME(baseException,"baseException");
	HX_MARK_END_CLASS();
}

void Exception_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(stackTraceArray,"stackTraceArray");
	HX_VISIT_MEMBER_NAME(stackTrace,"stackTrace");
	HX_VISIT_MEMBER_NAME(message,"message");
	HX_VISIT_MEMBER_NAME(innerException,"innerException");
	HX_VISIT_MEMBER_NAME(baseException,"baseException");
}

Dynamic Exception_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"message") ) { return message; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"toString") ) { return toString_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"stackTrace") ) { return stackTrace; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"baseException") ) { return inCallProp ? getBaseException() : baseException; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"innerException") ) { return innerException; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"stackTraceArray") ) { return stackTraceArray; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"getBaseException") ) { return getBaseException_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"generateStackTrace") ) { return generateStackTrace_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Exception_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"message") ) { message=inValue.Cast< ::String >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"stackTrace") ) { stackTrace=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"baseException") ) { baseException=inValue.Cast< ::haxe::exception::Exception >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"innerException") ) { innerException=inValue.Cast< ::haxe::exception::Exception >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"stackTraceArray") ) { stackTraceArray=inValue.Cast< Array< ::haxe::StackItem > >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Exception_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("stackTraceArray"));
	outFields->push(HX_CSTRING("stackTrace"));
	outFields->push(HX_CSTRING("message"));
	outFields->push(HX_CSTRING("innerException"));
	outFields->push(HX_CSTRING("baseException"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("toString"),
	HX_CSTRING("getBaseException"),
	HX_CSTRING("generateStackTrace"),
	HX_CSTRING("stackTraceArray"),
	HX_CSTRING("stackTrace"),
	HX_CSTRING("message"),
	HX_CSTRING("innerException"),
	HX_CSTRING("baseException"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Exception_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Exception_obj::__mClass,"__mClass");
};

Class Exception_obj::__mClass;

void Exception_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxe.exception.Exception"), hx::TCanCast< Exception_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Exception_obj::__boot()
{
}

} // end namespace haxe
} // end namespace exception
