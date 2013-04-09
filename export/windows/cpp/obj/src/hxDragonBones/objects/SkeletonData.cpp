#include <hxcpp.h>

#ifndef INCLUDED_hxDragonBones_objects_AnimationData
#include <hxDragonBones/objects/AnimationData.h>
#endif
#ifndef INCLUDED_hxDragonBones_objects_ArmatureData
#include <hxDragonBones/objects/ArmatureData.h>
#endif
#ifndef INCLUDED_hxDragonBones_objects_DataList
#include <hxDragonBones/objects/DataList.h>
#endif
#ifndef INCLUDED_hxDragonBones_objects_DisplayData
#include <hxDragonBones/objects/DisplayData.h>
#endif
#ifndef INCLUDED_hxDragonBones_objects_SkeletonData
#include <hxDragonBones/objects/SkeletonData.h>
#endif
#ifndef INCLUDED_hxDragonBones_utils_IDisposable
#include <hxDragonBones/utils/IDisposable.h>
#endif
namespace hxDragonBones{
namespace objects{

Void SkeletonData_obj::__construct()
{
HX_STACK_PUSH("SkeletonData::new","hxDragonBones/objects/SkeletonData.hx",10);
{
	HX_STACK_LINE(11)
	this->armatureDataList = ::hxDragonBones::objects::DataList_obj::__new();
	HX_STACK_LINE(12)
	this->animationDataList = ::hxDragonBones::objects::DataList_obj::__new();
	HX_STACK_LINE(13)
	this->displayDataList = ::hxDragonBones::objects::DataList_obj::__new();
}
;
	return null();
}

SkeletonData_obj::~SkeletonData_obj() { }

Dynamic SkeletonData_obj::__CreateEmpty() { return  new SkeletonData_obj; }
hx::ObjectPtr< SkeletonData_obj > SkeletonData_obj::__new()
{  hx::ObjectPtr< SkeletonData_obj > result = new SkeletonData_obj();
	result->__construct();
	return result;}

Dynamic SkeletonData_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< SkeletonData_obj > result = new SkeletonData_obj();
	result->__construct();
	return result;}

hx::Object *SkeletonData_obj::__ToInterface(const type_info &inType) {
	if (inType==typeid( ::hxDragonBones::utils::IDisposable_obj)) return operator ::hxDragonBones::utils::IDisposable_obj *();
	return super::__ToInterface(inType);
}

::hxDragonBones::objects::DisplayData SkeletonData_obj::getDisplayData( ::String name){
	HX_STACK_PUSH("SkeletonData::getDisplayData","hxDragonBones/objects/SkeletonData.hx",52);
	HX_STACK_THIS(this);
	HX_STACK_ARG(name,"name");
	HX_STACK_LINE(52)
	return this->displayDataList->getDataByName(name);
}


HX_DEFINE_DYNAMIC_FUNC1(SkeletonData_obj,getDisplayData,return )

::hxDragonBones::objects::AnimationData SkeletonData_obj::getAnimationData( ::String name){
	HX_STACK_PUSH("SkeletonData::getAnimationData","hxDragonBones/objects/SkeletonData.hx",48);
	HX_STACK_THIS(this);
	HX_STACK_ARG(name,"name");
	HX_STACK_LINE(48)
	return this->animationDataList->getDataByName(name);
}


HX_DEFINE_DYNAMIC_FUNC1(SkeletonData_obj,getAnimationData,return )

::hxDragonBones::objects::ArmatureData SkeletonData_obj::getArmatureData( ::String name){
	HX_STACK_PUSH("SkeletonData::getArmatureData","hxDragonBones/objects/SkeletonData.hx",44);
	HX_STACK_THIS(this);
	HX_STACK_ARG(name,"name");
	HX_STACK_LINE(44)
	return this->armatureDataList->getDataByName(name);
}


HX_DEFINE_DYNAMIC_FUNC1(SkeletonData_obj,getArmatureData,return )

Void SkeletonData_obj::dispose( ){
{
		HX_STACK_PUSH("SkeletonData::dispose","hxDragonBones/objects/SkeletonData.hx",32);
		HX_STACK_THIS(this);
		HX_STACK_LINE(33)
		{
			HX_STACK_LINE(33)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			Array< ::String > _g1 = this->armatureDataList->names;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(33)
			while(((_g < _g1->length))){
				HX_STACK_LINE(33)
				::String name = _g1->__get(_g);		HX_STACK_VAR(name,"name");
				HX_STACK_LINE(33)
				++(_g);
				HX_STACK_LINE(34)
				{
					HX_STACK_LINE(34)
					::hxDragonBones::utils::IDisposable d = this->armatureDataList->getDataByName(name);		HX_STACK_VAR(d,"d");
					HX_STACK_LINE(34)
					if (((d != null()))){
						HX_STACK_LINE(34)
						d->dispose();
					}
				}
			}
		}
		HX_STACK_LINE(36)
		{
			HX_STACK_LINE(36)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			Array< ::String > _g1 = this->animationDataList->names;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(36)
			while(((_g < _g1->length))){
				HX_STACK_LINE(36)
				::String name = _g1->__get(_g);		HX_STACK_VAR(name,"name");
				HX_STACK_LINE(36)
				++(_g);
				HX_STACK_LINE(37)
				{
					HX_STACK_LINE(37)
					::hxDragonBones::utils::IDisposable d = this->animationDataList->getDataByName(name);		HX_STACK_VAR(d,"d");
					HX_STACK_LINE(37)
					if (((d != null()))){
						HX_STACK_LINE(37)
						d->dispose();
					}
				}
			}
		}
		HX_STACK_LINE(39)
		{
			HX_STACK_LINE(39)
			::hxDragonBones::utils::IDisposable d = this->armatureDataList;		HX_STACK_VAR(d,"d");
			HX_STACK_LINE(39)
			if (((d != null()))){
				HX_STACK_LINE(39)
				d->dispose();
			}
		}
		HX_STACK_LINE(40)
		{
			HX_STACK_LINE(40)
			::hxDragonBones::utils::IDisposable d = this->animationDataList;		HX_STACK_VAR(d,"d");
			HX_STACK_LINE(40)
			if (((d != null()))){
				HX_STACK_LINE(40)
				d->dispose();
			}
		}
		HX_STACK_LINE(41)
		{
			HX_STACK_LINE(41)
			::hxDragonBones::utils::IDisposable d = this->displayDataList;		HX_STACK_VAR(d,"d");
			HX_STACK_LINE(41)
			if (((d != null()))){
				HX_STACK_LINE(41)
				d->dispose();
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(SkeletonData_obj,dispose,(void))

Array< ::String > SkeletonData_obj::get_animationNames( ){
	HX_STACK_PUSH("SkeletonData::get_animationNames","hxDragonBones/objects/SkeletonData.hx",28);
	HX_STACK_THIS(this);
	HX_STACK_LINE(28)
	return this->animationDataList->names->slice((int)0,null());
}


HX_DEFINE_DYNAMIC_FUNC0(SkeletonData_obj,get_animationNames,return )

Array< ::String > SkeletonData_obj::get_armatureNames( ){
	HX_STACK_PUSH("SkeletonData::get_armatureNames","hxDragonBones/objects/SkeletonData.hx",24);
	HX_STACK_THIS(this);
	HX_STACK_LINE(24)
	return this->armatureDataList->names->slice((int)0,null());
}


HX_DEFINE_DYNAMIC_FUNC0(SkeletonData_obj,get_armatureNames,return )


SkeletonData_obj::SkeletonData_obj()
{
}

void SkeletonData_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(SkeletonData);
	HX_MARK_MEMBER_NAME(displayDataList,"displayDataList");
	HX_MARK_MEMBER_NAME(animationDataList,"animationDataList");
	HX_MARK_MEMBER_NAME(armatureDataList,"armatureDataList");
	HX_MARK_MEMBER_NAME(animationNames,"animationNames");
	HX_MARK_MEMBER_NAME(armatureNames,"armatureNames");
	HX_MARK_MEMBER_NAME(frameRate,"frameRate");
	HX_MARK_MEMBER_NAME(name,"name");
	HX_MARK_END_CLASS();
}

void SkeletonData_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(displayDataList,"displayDataList");
	HX_VISIT_MEMBER_NAME(animationDataList,"animationDataList");
	HX_VISIT_MEMBER_NAME(armatureDataList,"armatureDataList");
	HX_VISIT_MEMBER_NAME(animationNames,"animationNames");
	HX_VISIT_MEMBER_NAME(armatureNames,"armatureNames");
	HX_VISIT_MEMBER_NAME(frameRate,"frameRate");
	HX_VISIT_MEMBER_NAME(name,"name");
}

Dynamic SkeletonData_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"name") ) { return name; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"dispose") ) { return dispose_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"frameRate") ) { return frameRate; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"armatureNames") ) { return inCallProp ? get_armatureNames() : armatureNames; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"getDisplayData") ) { return getDisplayData_dyn(); }
		if (HX_FIELD_EQ(inName,"animationNames") ) { return inCallProp ? get_animationNames() : animationNames; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"getArmatureData") ) { return getArmatureData_dyn(); }
		if (HX_FIELD_EQ(inName,"displayDataList") ) { return displayDataList; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"getAnimationData") ) { return getAnimationData_dyn(); }
		if (HX_FIELD_EQ(inName,"armatureDataList") ) { return armatureDataList; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"get_armatureNames") ) { return get_armatureNames_dyn(); }
		if (HX_FIELD_EQ(inName,"animationDataList") ) { return animationDataList; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"get_animationNames") ) { return get_animationNames_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic SkeletonData_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"name") ) { name=inValue.Cast< ::String >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"frameRate") ) { frameRate=inValue.Cast< int >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"armatureNames") ) { armatureNames=inValue.Cast< Array< ::String > >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"animationNames") ) { animationNames=inValue.Cast< Array< ::String > >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"displayDataList") ) { displayDataList=inValue.Cast< ::hxDragonBones::objects::DataList >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"armatureDataList") ) { armatureDataList=inValue.Cast< ::hxDragonBones::objects::DataList >(); return inValue; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"animationDataList") ) { animationDataList=inValue.Cast< ::hxDragonBones::objects::DataList >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void SkeletonData_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("displayDataList"));
	outFields->push(HX_CSTRING("animationDataList"));
	outFields->push(HX_CSTRING("armatureDataList"));
	outFields->push(HX_CSTRING("animationNames"));
	outFields->push(HX_CSTRING("armatureNames"));
	outFields->push(HX_CSTRING("frameRate"));
	outFields->push(HX_CSTRING("name"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("getDisplayData"),
	HX_CSTRING("getAnimationData"),
	HX_CSTRING("getArmatureData"),
	HX_CSTRING("dispose"),
	HX_CSTRING("get_animationNames"),
	HX_CSTRING("get_armatureNames"),
	HX_CSTRING("displayDataList"),
	HX_CSTRING("animationDataList"),
	HX_CSTRING("armatureDataList"),
	HX_CSTRING("animationNames"),
	HX_CSTRING("armatureNames"),
	HX_CSTRING("frameRate"),
	HX_CSTRING("name"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(SkeletonData_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(SkeletonData_obj::__mClass,"__mClass");
};

Class SkeletonData_obj::__mClass;

void SkeletonData_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("hxDragonBones.objects.SkeletonData"), hx::TCanCast< SkeletonData_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void SkeletonData_obj::__boot()
{
}

} // end namespace hxDragonBones
} // end namespace objects
