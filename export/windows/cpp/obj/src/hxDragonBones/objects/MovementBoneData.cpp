#include <hxcpp.h>

#ifndef INCLUDED_hxDragonBones_objects_FrameData
#include <hxDragonBones/objects/FrameData.h>
#endif
#ifndef INCLUDED_hxDragonBones_objects_MovementBoneData
#include <hxDragonBones/objects/MovementBoneData.h>
#endif
#ifndef INCLUDED_hxDragonBones_utils_IDisposable
#include <hxDragonBones/utils/IDisposable.h>
#endif
namespace hxDragonBones{
namespace objects{

Void MovementBoneData_obj::__construct()
{
HX_STACK_PUSH("MovementBoneData::new","hxDragonBones/objects/MovementBoneData.hx",11);
{
	HX_STACK_LINE(12)
	this->scale = (int)1;
	HX_STACK_LINE(13)
	this->delay = (int)0;
	HX_STACK_LINE(14)
	this->frameList = Array_obj< ::hxDragonBones::objects::FrameData >::__new();
}
;
	return null();
}

MovementBoneData_obj::~MovementBoneData_obj() { }

Dynamic MovementBoneData_obj::__CreateEmpty() { return  new MovementBoneData_obj; }
hx::ObjectPtr< MovementBoneData_obj > MovementBoneData_obj::__new()
{  hx::ObjectPtr< MovementBoneData_obj > result = new MovementBoneData_obj();
	result->__construct();
	return result;}

Dynamic MovementBoneData_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< MovementBoneData_obj > result = new MovementBoneData_obj();
	result->__construct();
	return result;}

hx::Object *MovementBoneData_obj::__ToInterface(const type_info &inType) {
	if (inType==typeid( ::hxDragonBones::utils::IDisposable_obj)) return operator ::hxDragonBones::utils::IDisposable_obj *();
	return super::__ToInterface(inType);
}

Void MovementBoneData_obj::setValues( hx::Null< Float >  __o_scale,hx::Null< Float >  __o_delay){
Float scale = __o_scale.Default(1);
Float delay = __o_delay.Default(0);
	HX_STACK_PUSH("MovementBoneData::setValues","hxDragonBones/objects/MovementBoneData.hx",25);
	HX_STACK_THIS(this);
	HX_STACK_ARG(scale,"scale");
	HX_STACK_ARG(delay,"delay");
{
		HX_STACK_LINE(26)
		this->scale = (  (((scale > (int)0))) ? Float(scale) : Float((int)1) );
		HX_STACK_LINE(27)
		this->delay = (  (((delay != (int)0))) ? Float(hx::Mod(delay,(int)1)) : Float((int)0) );
		HX_STACK_LINE(28)
		if (((this->delay > (int)0))){
			HX_STACK_LINE(28)
			hx::SubEq(this->delay,(int)1);
		}
		HX_STACK_LINE(31)
		hx::MultEq(this->delay,(int)-1);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(MovementBoneData_obj,setValues,(void))

Void MovementBoneData_obj::dispose( ){
{
		HX_STACK_PUSH("MovementBoneData::dispose","hxDragonBones/objects/MovementBoneData.hx",21);
		HX_STACK_THIS(this);
		HX_STACK_LINE(21)
		this->frameList = null();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(MovementBoneData_obj,dispose,(void))

::hxDragonBones::objects::MovementBoneData MovementBoneData_obj::HIDE_DATA;


MovementBoneData_obj::MovementBoneData_obj()
{
}

void MovementBoneData_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(MovementBoneData);
	HX_MARK_MEMBER_NAME(delay,"delay");
	HX_MARK_MEMBER_NAME(scale,"scale");
	HX_MARK_MEMBER_NAME(frameList,"frameList");
	HX_MARK_END_CLASS();
}

void MovementBoneData_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(delay,"delay");
	HX_VISIT_MEMBER_NAME(scale,"scale");
	HX_VISIT_MEMBER_NAME(frameList,"frameList");
}

Dynamic MovementBoneData_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"delay") ) { return delay; }
		if (HX_FIELD_EQ(inName,"scale") ) { return scale; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"dispose") ) { return dispose_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"HIDE_DATA") ) { return HIDE_DATA; }
		if (HX_FIELD_EQ(inName,"setValues") ) { return setValues_dyn(); }
		if (HX_FIELD_EQ(inName,"frameList") ) { return frameList; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic MovementBoneData_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"delay") ) { delay=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"scale") ) { scale=inValue.Cast< Float >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"HIDE_DATA") ) { HIDE_DATA=inValue.Cast< ::hxDragonBones::objects::MovementBoneData >(); return inValue; }
		if (HX_FIELD_EQ(inName,"frameList") ) { frameList=inValue.Cast< Array< ::hxDragonBones::objects::FrameData > >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void MovementBoneData_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("delay"));
	outFields->push(HX_CSTRING("scale"));
	outFields->push(HX_CSTRING("frameList"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("HIDE_DATA"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("setValues"),
	HX_CSTRING("dispose"),
	HX_CSTRING("delay"),
	HX_CSTRING("scale"),
	HX_CSTRING("frameList"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(MovementBoneData_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(MovementBoneData_obj::HIDE_DATA,"HIDE_DATA");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(MovementBoneData_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(MovementBoneData_obj::HIDE_DATA,"HIDE_DATA");
};

Class MovementBoneData_obj::__mClass;

void MovementBoneData_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("hxDragonBones.objects.MovementBoneData"), hx::TCanCast< MovementBoneData_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void MovementBoneData_obj::__boot()
{
	HIDE_DATA= ::hxDragonBones::objects::MovementBoneData_obj::__new();
}

} // end namespace hxDragonBones
} // end namespace objects
