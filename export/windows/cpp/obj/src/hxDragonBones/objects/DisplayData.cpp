#include <hxcpp.h>

#ifndef INCLUDED_hxDragonBones_objects_DisplayData
#include <hxDragonBones/objects/DisplayData.h>
#endif
namespace hxDragonBones{
namespace objects{

Void DisplayData_obj::__construct()
{
HX_STACK_PUSH("DisplayData::new","hxDragonBones/objects/DisplayData.hx",8);
{
	HX_STACK_LINE(8)
	this->isArmature = false;
}
;
	return null();
}

DisplayData_obj::~DisplayData_obj() { }

Dynamic DisplayData_obj::__CreateEmpty() { return  new DisplayData_obj; }
hx::ObjectPtr< DisplayData_obj > DisplayData_obj::__new()
{  hx::ObjectPtr< DisplayData_obj > result = new DisplayData_obj();
	result->__construct();
	return result;}

Dynamic DisplayData_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< DisplayData_obj > result = new DisplayData_obj();
	result->__construct();
	return result;}


DisplayData_obj::DisplayData_obj()
{
}

void DisplayData_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(DisplayData);
	HX_MARK_MEMBER_NAME(isArmature,"isArmature");
	HX_MARK_MEMBER_NAME(pivotY,"pivotY");
	HX_MARK_MEMBER_NAME(pivotX,"pivotX");
	HX_MARK_END_CLASS();
}

void DisplayData_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(isArmature,"isArmature");
	HX_VISIT_MEMBER_NAME(pivotY,"pivotY");
	HX_VISIT_MEMBER_NAME(pivotX,"pivotX");
}

Dynamic DisplayData_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"pivotY") ) { return pivotY; }
		if (HX_FIELD_EQ(inName,"pivotX") ) { return pivotX; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"isArmature") ) { return isArmature; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic DisplayData_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"pivotY") ) { pivotY=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"pivotX") ) { pivotX=inValue.Cast< Float >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"isArmature") ) { isArmature=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void DisplayData_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("isArmature"));
	outFields->push(HX_CSTRING("pivotY"));
	outFields->push(HX_CSTRING("pivotX"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("isArmature"),
	HX_CSTRING("pivotY"),
	HX_CSTRING("pivotX"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(DisplayData_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(DisplayData_obj::__mClass,"__mClass");
};

Class DisplayData_obj::__mClass;

void DisplayData_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("hxDragonBones.objects.DisplayData"), hx::TCanCast< DisplayData_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void DisplayData_obj::__boot()
{
}

} // end namespace hxDragonBones
} // end namespace objects
