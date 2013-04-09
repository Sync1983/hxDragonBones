#include <hxcpp.h>

#ifndef INCLUDED_haxe_remoting_FlashJsConnection
#include <haxe/remoting/FlashJsConnection.h>
#endif
namespace haxe{
namespace remoting{

Void FlashJsConnection_obj::__construct()
{
	return null();
}

FlashJsConnection_obj::~FlashJsConnection_obj() { }

Dynamic FlashJsConnection_obj::__CreateEmpty() { return  new FlashJsConnection_obj; }
hx::ObjectPtr< FlashJsConnection_obj > FlashJsConnection_obj::__new()
{  hx::ObjectPtr< FlashJsConnection_obj > result = new FlashJsConnection_obj();
	result->__construct();
	return result;}

Dynamic FlashJsConnection_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< FlashJsConnection_obj > result = new FlashJsConnection_obj();
	result->__construct();
	return result;}


FlashJsConnection_obj::FlashJsConnection_obj()
{
}

void FlashJsConnection_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(FlashJsConnection);
	HX_MARK_END_CLASS();
}

void FlashJsConnection_obj::__Visit(HX_VISIT_PARAMS)
{
}

Dynamic FlashJsConnection_obj::__Field(const ::String &inName,bool inCallProp)
{
	return super::__Field(inName,inCallProp);
}

Dynamic FlashJsConnection_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void FlashJsConnection_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(FlashJsConnection_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(FlashJsConnection_obj::__mClass,"__mClass");
};

Class FlashJsConnection_obj::__mClass;

void FlashJsConnection_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxe.remoting.FlashJsConnection"), hx::TCanCast< FlashJsConnection_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void FlashJsConnection_obj::__boot()
{
}

} // end namespace haxe
} // end namespace remoting
