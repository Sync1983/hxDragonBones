#include <hxcpp.h>

#ifndef INCLUDED_hxDragonBones_objects_AnimationData
#include <hxDragonBones/objects/AnimationData.h>
#endif
#ifndef INCLUDED_hxDragonBones_objects_DataList
#include <hxDragonBones/objects/DataList.h>
#endif
#ifndef INCLUDED_hxDragonBones_objects_MovementData
#include <hxDragonBones/objects/MovementData.h>
#endif
#ifndef INCLUDED_hxDragonBones_utils_IDisposable
#include <hxDragonBones/utils/IDisposable.h>
#endif
namespace hxDragonBones{
namespace objects{

Void AnimationData_obj::__construct()
{
HX_STACK_PUSH("AnimationData::new","hxDragonBones/objects/AnimationData.hx",10);
{
	HX_STACK_LINE(10)
	this->movementDataList = ::hxDragonBones::objects::DataList_obj::__new();
}
;
	return null();
}

AnimationData_obj::~AnimationData_obj() { }

Dynamic AnimationData_obj::__CreateEmpty() { return  new AnimationData_obj; }
hx::ObjectPtr< AnimationData_obj > AnimationData_obj::__new()
{  hx::ObjectPtr< AnimationData_obj > result = new AnimationData_obj();
	result->__construct();
	return result;}

Dynamic AnimationData_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< AnimationData_obj > result = new AnimationData_obj();
	result->__construct();
	return result;}

hx::Object *AnimationData_obj::__ToInterface(const type_info &inType) {
	if (inType==typeid( ::hxDragonBones::utils::IDisposable_obj)) return operator ::hxDragonBones::utils::IDisposable_obj *();
	return super::__ToInterface(inType);
}

::hxDragonBones::objects::MovementData AnimationData_obj::getMovementData( ::String name){
	HX_STACK_PUSH("AnimationData::getMovementData","hxDragonBones/objects/AnimationData.hx",29);
	HX_STACK_THIS(this);
	HX_STACK_ARG(name,"name");
	HX_STACK_LINE(29)
	return this->movementDataList->getDataByName(name);
}


HX_DEFINE_DYNAMIC_FUNC1(AnimationData_obj,getMovementData,return )

Void AnimationData_obj::dispose( ){
{
		HX_STACK_PUSH("AnimationData::dispose","hxDragonBones/objects/AnimationData.hx",22);
		HX_STACK_THIS(this);
		HX_STACK_LINE(23)
		{
			HX_STACK_LINE(23)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			Array< ::String > _g1 = this->movementDataList->names;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(23)
			while(((_g < _g1->length))){
				HX_STACK_LINE(23)
				::String name = _g1->__get(_g);		HX_STACK_VAR(name,"name");
				HX_STACK_LINE(23)
				++(_g);
				HX_STACK_LINE(24)
				{
					HX_STACK_LINE(24)
					::hxDragonBones::utils::IDisposable d = this->movementDataList->getDataByName(name);		HX_STACK_VAR(d,"d");
					HX_STACK_LINE(24)
					if (((d != null()))){
						HX_STACK_LINE(24)
						d->dispose();
					}
				}
			}
		}
		HX_STACK_LINE(26)
		{
			HX_STACK_LINE(26)
			::hxDragonBones::utils::IDisposable d = this->movementDataList;		HX_STACK_VAR(d,"d");
			HX_STACK_LINE(26)
			if (((d != null()))){
				HX_STACK_LINE(26)
				d->dispose();
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(AnimationData_obj,dispose,(void))

Array< ::String > AnimationData_obj::get_movementList( ){
	HX_STACK_PUSH("AnimationData::get_movementList","hxDragonBones/objects/AnimationData.hx",17);
	HX_STACK_THIS(this);
	HX_STACK_LINE(17)
	return this->movementDataList->names->slice((int)0,null());
}


HX_DEFINE_DYNAMIC_FUNC0(AnimationData_obj,get_movementList,return )


AnimationData_obj::AnimationData_obj()
{
}

void AnimationData_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(AnimationData);
	HX_MARK_MEMBER_NAME(movementDataList,"movementDataList");
	HX_MARK_MEMBER_NAME(movementList,"movementList");
	HX_MARK_END_CLASS();
}

void AnimationData_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(movementDataList,"movementDataList");
	HX_VISIT_MEMBER_NAME(movementList,"movementList");
}

Dynamic AnimationData_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"dispose") ) { return dispose_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"movementList") ) { return inCallProp ? get_movementList() : movementList; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"getMovementData") ) { return getMovementData_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"get_movementList") ) { return get_movementList_dyn(); }
		if (HX_FIELD_EQ(inName,"movementDataList") ) { return movementDataList; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic AnimationData_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 12:
		if (HX_FIELD_EQ(inName,"movementList") ) { movementList=inValue.Cast< Array< ::String > >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"movementDataList") ) { movementDataList=inValue.Cast< ::hxDragonBones::objects::DataList >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void AnimationData_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("movementDataList"));
	outFields->push(HX_CSTRING("movementList"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("getMovementData"),
	HX_CSTRING("dispose"),
	HX_CSTRING("get_movementList"),
	HX_CSTRING("movementDataList"),
	HX_CSTRING("movementList"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(AnimationData_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(AnimationData_obj::__mClass,"__mClass");
};

Class AnimationData_obj::__mClass;

void AnimationData_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("hxDragonBones.objects.AnimationData"), hx::TCanCast< AnimationData_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void AnimationData_obj::__boot()
{
}

} // end namespace hxDragonBones
} // end namespace objects
