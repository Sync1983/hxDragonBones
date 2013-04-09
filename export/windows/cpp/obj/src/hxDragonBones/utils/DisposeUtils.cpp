#include <hxcpp.h>

#ifndef INCLUDED_hxDragonBones_utils_DisposeUtils
#include <hxDragonBones/utils/DisposeUtils.h>
#endif
#ifndef INCLUDED_hxDragonBones_utils_IDisposable
#include <hxDragonBones/utils/IDisposable.h>
#endif
namespace hxDragonBones{
namespace utils{

Void DisposeUtils_obj::__construct()
{
	return null();
}

DisposeUtils_obj::~DisposeUtils_obj() { }

Dynamic DisposeUtils_obj::__CreateEmpty() { return  new DisposeUtils_obj; }
hx::ObjectPtr< DisposeUtils_obj > DisposeUtils_obj::__new()
{  hx::ObjectPtr< DisposeUtils_obj > result = new DisposeUtils_obj();
	result->__construct();
	return result;}

Dynamic DisposeUtils_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< DisposeUtils_obj > result = new DisposeUtils_obj();
	result->__construct();
	return result;}

Void DisposeUtils_obj::dispose( Dynamic target){
{
		HX_STACK_PUSH("DisposeUtils::dispose","hxDragonBones/utils/DisposeUtils.hx",8);
		HX_STACK_ARG(target,"target");
		HX_STACK_LINE(9)
		::hxDragonBones::utils::IDisposable d = target;		HX_STACK_VAR(d,"d");
		HX_STACK_LINE(10)
		if (((d != null()))){
			HX_STACK_LINE(10)
			d->dispose();
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(DisposeUtils_obj,dispose,(void))


DisposeUtils_obj::DisposeUtils_obj()
{
}

void DisposeUtils_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(DisposeUtils);
	HX_MARK_END_CLASS();
}

void DisposeUtils_obj::__Visit(HX_VISIT_PARAMS)
{
}

Dynamic DisposeUtils_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"dispose") ) { return dispose_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic DisposeUtils_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void DisposeUtils_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("dispose"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(DisposeUtils_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(DisposeUtils_obj::__mClass,"__mClass");
};

Class DisposeUtils_obj::__mClass;

void DisposeUtils_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("hxDragonBones.utils.DisposeUtils"), hx::TCanCast< DisposeUtils_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void DisposeUtils_obj::__boot()
{
}

} // end namespace hxDragonBones
} // end namespace utils
