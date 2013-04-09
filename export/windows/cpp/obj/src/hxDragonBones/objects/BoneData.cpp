#include <hxcpp.h>

#ifndef INCLUDED_hxDragonBones_objects_BoneData
#include <hxDragonBones/objects/BoneData.h>
#endif
#ifndef INCLUDED_hxDragonBones_objects_Node
#include <hxDragonBones/objects/Node.h>
#endif
#ifndef INCLUDED_hxDragonBones_utils_IDisposable
#include <hxDragonBones/utils/IDisposable.h>
#endif
namespace hxDragonBones{
namespace objects{

Void BoneData_obj::__construct()
{
HX_STACK_PUSH("BoneData::new","hxDragonBones/objects/BoneData.hx",9);
{
	HX_STACK_LINE(10)
	this->displayNames = Array_obj< ::String >::__new();
	HX_STACK_LINE(11)
	this->node = ::hxDragonBones::objects::Node_obj::__new();
}
;
	return null();
}

BoneData_obj::~BoneData_obj() { }

Dynamic BoneData_obj::__CreateEmpty() { return  new BoneData_obj; }
hx::ObjectPtr< BoneData_obj > BoneData_obj::__new()
{  hx::ObjectPtr< BoneData_obj > result = new BoneData_obj();
	result->__construct();
	return result;}

Dynamic BoneData_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< BoneData_obj > result = new BoneData_obj();
	result->__construct();
	return result;}

hx::Object *BoneData_obj::__ToInterface(const type_info &inType) {
	if (inType==typeid( ::hxDragonBones::utils::IDisposable_obj)) return operator ::hxDragonBones::utils::IDisposable_obj *();
	return super::__ToInterface(inType);
}

Void BoneData_obj::dispose( ){
{
		HX_STACK_PUSH("BoneData::dispose","hxDragonBones/objects/BoneData.hx",18);
		HX_STACK_THIS(this);
		HX_STACK_LINE(19)
		this->displayNames = null();
		HX_STACK_LINE(20)
		this->node = null();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(BoneData_obj,dispose,(void))


BoneData_obj::BoneData_obj()
{
}

void BoneData_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(BoneData);
	HX_MARK_MEMBER_NAME(displayNames,"displayNames");
	HX_MARK_MEMBER_NAME(node,"node");
	HX_MARK_MEMBER_NAME(parent,"parent");
	HX_MARK_END_CLASS();
}

void BoneData_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(displayNames,"displayNames");
	HX_VISIT_MEMBER_NAME(node,"node");
	HX_VISIT_MEMBER_NAME(parent,"parent");
}

Dynamic BoneData_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"node") ) { return node; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"parent") ) { return parent; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"dispose") ) { return dispose_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"displayNames") ) { return displayNames; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic BoneData_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"node") ) { node=inValue.Cast< ::hxDragonBones::objects::Node >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"parent") ) { parent=inValue.Cast< ::String >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"displayNames") ) { displayNames=inValue.Cast< Array< ::String > >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void BoneData_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("displayNames"));
	outFields->push(HX_CSTRING("node"));
	outFields->push(HX_CSTRING("parent"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("dispose"),
	HX_CSTRING("displayNames"),
	HX_CSTRING("node"),
	HX_CSTRING("parent"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(BoneData_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(BoneData_obj::__mClass,"__mClass");
};

Class BoneData_obj::__mClass;

void BoneData_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("hxDragonBones.objects.BoneData"), hx::TCanCast< BoneData_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void BoneData_obj::__boot()
{
}

} // end namespace hxDragonBones
} // end namespace objects
