#include <hxcpp.h>

#ifndef INCLUDED_hxDragonBones_objects_FrameData
#include <hxDragonBones/objects/FrameData.h>
#endif
#ifndef INCLUDED_hxDragonBones_objects_Node
#include <hxDragonBones/objects/Node.h>
#endif
#ifndef INCLUDED_native_geom_ColorTransform
#include <native/geom/ColorTransform.h>
#endif
namespace hxDragonBones{
namespace objects{

Void FrameData_obj::__construct()
{
HX_STACK_PUSH("FrameData::new","hxDragonBones/objects/FrameData.hx",9);
{
	HX_STACK_LINE(10)
	this->duration = (int)0;
	HX_STACK_LINE(11)
	this->tweenEasing = (int)0;
	HX_STACK_LINE(12)
	this->node = ::hxDragonBones::objects::Node_obj::__new();
	HX_STACK_LINE(13)
	this->colorTransform = ::native::geom::ColorTransform_obj::__new(null(),null(),null(),null(),null(),null(),null(),null());
	HX_STACK_LINE(14)
	this->visible = true;
}
;
	return null();
}

FrameData_obj::~FrameData_obj() { }

Dynamic FrameData_obj::__CreateEmpty() { return  new FrameData_obj; }
hx::ObjectPtr< FrameData_obj > FrameData_obj::__new()
{  hx::ObjectPtr< FrameData_obj > result = new FrameData_obj();
	result->__construct();
	return result;}

Dynamic FrameData_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< FrameData_obj > result = new FrameData_obj();
	result->__construct();
	return result;}


FrameData_obj::FrameData_obj()
{
}

void FrameData_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(FrameData);
	HX_MARK_MEMBER_NAME(colorTransform,"colorTransform");
	HX_MARK_MEMBER_NAME(node,"node");
	HX_MARK_MEMBER_NAME(soundEffect,"soundEffect");
	HX_MARK_MEMBER_NAME(sound,"sound");
	HX_MARK_MEMBER_NAME(event,"event");
	HX_MARK_MEMBER_NAME(visible,"visible");
	HX_MARK_MEMBER_NAME(movement,"movement");
	HX_MARK_MEMBER_NAME(displayIndex,"displayIndex");
	HX_MARK_MEMBER_NAME(tweenRotate,"tweenRotate");
	HX_MARK_MEMBER_NAME(tweenEasing,"tweenEasing");
	HX_MARK_MEMBER_NAME(duration,"duration");
	HX_MARK_END_CLASS();
}

void FrameData_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(colorTransform,"colorTransform");
	HX_VISIT_MEMBER_NAME(node,"node");
	HX_VISIT_MEMBER_NAME(soundEffect,"soundEffect");
	HX_VISIT_MEMBER_NAME(sound,"sound");
	HX_VISIT_MEMBER_NAME(event,"event");
	HX_VISIT_MEMBER_NAME(visible,"visible");
	HX_VISIT_MEMBER_NAME(movement,"movement");
	HX_VISIT_MEMBER_NAME(displayIndex,"displayIndex");
	HX_VISIT_MEMBER_NAME(tweenRotate,"tweenRotate");
	HX_VISIT_MEMBER_NAME(tweenEasing,"tweenEasing");
	HX_VISIT_MEMBER_NAME(duration,"duration");
}

Dynamic FrameData_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"node") ) { return node; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"sound") ) { return sound; }
		if (HX_FIELD_EQ(inName,"event") ) { return event; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"visible") ) { return visible; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"movement") ) { return movement; }
		if (HX_FIELD_EQ(inName,"duration") ) { return duration; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"soundEffect") ) { return soundEffect; }
		if (HX_FIELD_EQ(inName,"tweenRotate") ) { return tweenRotate; }
		if (HX_FIELD_EQ(inName,"tweenEasing") ) { return tweenEasing; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"displayIndex") ) { return displayIndex; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"colorTransform") ) { return colorTransform; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic FrameData_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"node") ) { node=inValue.Cast< ::hxDragonBones::objects::Node >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"sound") ) { sound=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"event") ) { event=inValue.Cast< ::String >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"visible") ) { visible=inValue.Cast< bool >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"movement") ) { movement=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"duration") ) { duration=inValue.Cast< Float >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"soundEffect") ) { soundEffect=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"tweenRotate") ) { tweenRotate=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"tweenEasing") ) { tweenEasing=inValue.Cast< Float >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"displayIndex") ) { displayIndex=inValue.Cast< int >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"colorTransform") ) { colorTransform=inValue.Cast< ::native::geom::ColorTransform >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void FrameData_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("colorTransform"));
	outFields->push(HX_CSTRING("node"));
	outFields->push(HX_CSTRING("soundEffect"));
	outFields->push(HX_CSTRING("sound"));
	outFields->push(HX_CSTRING("event"));
	outFields->push(HX_CSTRING("visible"));
	outFields->push(HX_CSTRING("movement"));
	outFields->push(HX_CSTRING("displayIndex"));
	outFields->push(HX_CSTRING("tweenRotate"));
	outFields->push(HX_CSTRING("tweenEasing"));
	outFields->push(HX_CSTRING("duration"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("colorTransform"),
	HX_CSTRING("node"),
	HX_CSTRING("soundEffect"),
	HX_CSTRING("sound"),
	HX_CSTRING("event"),
	HX_CSTRING("visible"),
	HX_CSTRING("movement"),
	HX_CSTRING("displayIndex"),
	HX_CSTRING("tweenRotate"),
	HX_CSTRING("tweenEasing"),
	HX_CSTRING("duration"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(FrameData_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(FrameData_obj::__mClass,"__mClass");
};

Class FrameData_obj::__mClass;

void FrameData_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("hxDragonBones.objects.FrameData"), hx::TCanCast< FrameData_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void FrameData_obj::__boot()
{
}

} // end namespace hxDragonBones
} // end namespace objects
