#include <hxcpp.h>

#ifndef INCLUDED_hxDragonBones_objects_DataList
#include <hxDragonBones/objects/DataList.h>
#endif
#ifndef INCLUDED_hxDragonBones_objects_MovementBoneData
#include <hxDragonBones/objects/MovementBoneData.h>
#endif
#ifndef INCLUDED_hxDragonBones_objects_MovementData
#include <hxDragonBones/objects/MovementData.h>
#endif
#ifndef INCLUDED_hxDragonBones_objects_MovementFrameData
#include <hxDragonBones/objects/MovementFrameData.h>
#endif
#ifndef INCLUDED_hxDragonBones_utils_IDisposable
#include <hxDragonBones/utils/IDisposable.h>
#endif
namespace hxDragonBones{
namespace objects{

Void MovementData_obj::__construct()
{
HX_STACK_PUSH("MovementData::new","hxDragonBones/objects/MovementData.hx",10);
{
	HX_STACK_LINE(11)
	this->duration = (int)0;
	HX_STACK_LINE(12)
	this->durationTo = (int)0;
	HX_STACK_LINE(13)
	this->durationTween = (int)0;
	HX_STACK_LINE(14)
	this->movementBoneDataList = ::hxDragonBones::objects::DataList_obj::__new();
	HX_STACK_LINE(15)
	this->movementFrameList = Array_obj< ::hxDragonBones::objects::MovementFrameData >::__new();
}
;
	return null();
}

MovementData_obj::~MovementData_obj() { }

Dynamic MovementData_obj::__CreateEmpty() { return  new MovementData_obj; }
hx::ObjectPtr< MovementData_obj > MovementData_obj::__new()
{  hx::ObjectPtr< MovementData_obj > result = new MovementData_obj();
	result->__construct();
	return result;}

Dynamic MovementData_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< MovementData_obj > result = new MovementData_obj();
	result->__construct();
	return result;}

hx::Object *MovementData_obj::__ToInterface(const type_info &inType) {
	if (inType==typeid( ::hxDragonBones::utils::IDisposable_obj)) return operator ::hxDragonBones::utils::IDisposable_obj *();
	return super::__ToInterface(inType);
}

::hxDragonBones::objects::MovementBoneData MovementData_obj::getMovementBoneData( ::String name){
	HX_STACK_PUSH("MovementData::getMovementBoneData","hxDragonBones/objects/MovementData.hx",34);
	HX_STACK_THIS(this);
	HX_STACK_ARG(name,"name");
	HX_STACK_LINE(34)
	return this->movementBoneDataList->getDataByName(name);
}


HX_DEFINE_DYNAMIC_FUNC1(MovementData_obj,getMovementBoneData,return )

Void MovementData_obj::dispose( ){
{
		HX_STACK_PUSH("MovementData::dispose","hxDragonBones/objects/MovementData.hx",26);
		HX_STACK_THIS(this);
		HX_STACK_LINE(27)
		{
			HX_STACK_LINE(27)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			Array< ::String > _g1 = this->movementBoneDataList->names;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(27)
			while(((_g < _g1->length))){
				HX_STACK_LINE(27)
				::String movementBoneName = _g1->__get(_g);		HX_STACK_VAR(movementBoneName,"movementBoneName");
				HX_STACK_LINE(27)
				++(_g);
				HX_STACK_LINE(28)
				{
					HX_STACK_LINE(28)
					::hxDragonBones::utils::IDisposable d = this->movementBoneDataList->getDataByName(movementBoneName);		HX_STACK_VAR(d,"d");
					HX_STACK_LINE(28)
					if (((d != null()))){
						HX_STACK_LINE(28)
						d->dispose();
					}
				}
			}
		}
		HX_STACK_LINE(30)
		{
			HX_STACK_LINE(30)
			::hxDragonBones::utils::IDisposable d = this->movementBoneDataList;		HX_STACK_VAR(d,"d");
			HX_STACK_LINE(30)
			if (((d != null()))){
				HX_STACK_LINE(30)
				d->dispose();
			}
		}
		HX_STACK_LINE(31)
		this->movementFrameList = null();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(MovementData_obj,dispose,(void))


MovementData_obj::MovementData_obj()
{
}

void MovementData_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(MovementData);
	HX_MARK_MEMBER_NAME(tweenEasing,"tweenEasing");
	HX_MARK_MEMBER_NAME(loop,"loop");
	HX_MARK_MEMBER_NAME(movementFrameList,"movementFrameList");
	HX_MARK_MEMBER_NAME(movementBoneDataList,"movementBoneDataList");
	HX_MARK_MEMBER_NAME(durationTween,"durationTween");
	HX_MARK_MEMBER_NAME(durationTo,"durationTo");
	HX_MARK_MEMBER_NAME(duration,"duration");
	HX_MARK_END_CLASS();
}

void MovementData_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(tweenEasing,"tweenEasing");
	HX_VISIT_MEMBER_NAME(loop,"loop");
	HX_VISIT_MEMBER_NAME(movementFrameList,"movementFrameList");
	HX_VISIT_MEMBER_NAME(movementBoneDataList,"movementBoneDataList");
	HX_VISIT_MEMBER_NAME(durationTween,"durationTween");
	HX_VISIT_MEMBER_NAME(durationTo,"durationTo");
	HX_VISIT_MEMBER_NAME(duration,"duration");
}

Dynamic MovementData_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"loop") ) { return loop; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"dispose") ) { return dispose_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"duration") ) { return duration; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"durationTo") ) { return durationTo; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"tweenEasing") ) { return tweenEasing; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"durationTween") ) { return durationTween; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"movementFrameList") ) { return movementFrameList; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"getMovementBoneData") ) { return getMovementBoneData_dyn(); }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"movementBoneDataList") ) { return movementBoneDataList; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic MovementData_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"loop") ) { loop=inValue.Cast< bool >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"duration") ) { duration=inValue.Cast< Float >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"durationTo") ) { durationTo=inValue.Cast< Float >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"tweenEasing") ) { tweenEasing=inValue.Cast< Float >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"durationTween") ) { durationTween=inValue.Cast< Float >(); return inValue; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"movementFrameList") ) { movementFrameList=inValue.Cast< Array< ::hxDragonBones::objects::MovementFrameData > >(); return inValue; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"movementBoneDataList") ) { movementBoneDataList=inValue.Cast< ::hxDragonBones::objects::DataList >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void MovementData_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("tweenEasing"));
	outFields->push(HX_CSTRING("loop"));
	outFields->push(HX_CSTRING("movementFrameList"));
	outFields->push(HX_CSTRING("movementBoneDataList"));
	outFields->push(HX_CSTRING("durationTween"));
	outFields->push(HX_CSTRING("durationTo"));
	outFields->push(HX_CSTRING("duration"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("getMovementBoneData"),
	HX_CSTRING("dispose"),
	HX_CSTRING("tweenEasing"),
	HX_CSTRING("loop"),
	HX_CSTRING("movementFrameList"),
	HX_CSTRING("movementBoneDataList"),
	HX_CSTRING("durationTween"),
	HX_CSTRING("durationTo"),
	HX_CSTRING("duration"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(MovementData_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(MovementData_obj::__mClass,"__mClass");
};

Class MovementData_obj::__mClass;

void MovementData_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("hxDragonBones.objects.MovementData"), hx::TCanCast< MovementData_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void MovementData_obj::__boot()
{
}

} // end namespace hxDragonBones
} // end namespace objects
