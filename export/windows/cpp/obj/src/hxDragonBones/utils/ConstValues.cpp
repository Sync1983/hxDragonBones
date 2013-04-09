#include <hxcpp.h>

#ifndef INCLUDED_hxDragonBones_utils_ConstValues
#include <hxDragonBones/utils/ConstValues.h>
#endif
namespace hxDragonBones{
namespace utils{

Void ConstValues_obj::__construct()
{
	return null();
}

ConstValues_obj::~ConstValues_obj() { }

Dynamic ConstValues_obj::__CreateEmpty() { return  new ConstValues_obj; }
hx::ObjectPtr< ConstValues_obj > ConstValues_obj::__new()
{  hx::ObjectPtr< ConstValues_obj > result = new ConstValues_obj();
	result->__construct();
	return result;}

Dynamic ConstValues_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< ConstValues_obj > result = new ConstValues_obj();
	result->__construct();
	return result;}

::String ConstValues_obj::VERSION_14;

::String ConstValues_obj::VERSION;

::String ConstValues_obj::SKELETON;

::String ConstValues_obj::ARMATURES;

::String ConstValues_obj::ARMATURE;

::String ConstValues_obj::BONE;

::String ConstValues_obj::DISPLAY;

::String ConstValues_obj::ANIMATIONS;

::String ConstValues_obj::ANIMATION;

::String ConstValues_obj::MOVEMENT;

::String ConstValues_obj::FRAME;

::String ConstValues_obj::COLOR_TRANSFORM;

::String ConstValues_obj::TEXTURE_ATLAS;

::String ConstValues_obj::SUB_TEXTURE;

::String ConstValues_obj::AT;

::String ConstValues_obj::A_VERSION;

::String ConstValues_obj::A_FRAME_RATE;

::String ConstValues_obj::A_NAME;

::String ConstValues_obj::A_DURATION;

::String ConstValues_obj::A_DURATION_TO;

::String ConstValues_obj::A_DURATION_TWEEN;

::String ConstValues_obj::A_LOOP;

::String ConstValues_obj::A_MOVEMENT_SCALE;

::String ConstValues_obj::A_MOVEMENT_DELAY;

::String ConstValues_obj::A_PARENT;

::String ConstValues_obj::A_SKEW_X;

::String ConstValues_obj::A_SKEW_Y;

::String ConstValues_obj::A_SCALE_X;

::String ConstValues_obj::A_SCALE_Y;

::String ConstValues_obj::A_Z;

::String ConstValues_obj::A_DISPLAY_INDEX;

::String ConstValues_obj::A_EVENT;

::String ConstValues_obj::A_SOUND;

::String ConstValues_obj::A_SOUND_EFFECT;

::String ConstValues_obj::A_TWEEN_EASING;

::String ConstValues_obj::A_TWEEN_ROTATE;

::String ConstValues_obj::A_IS_ARMATURE;

::String ConstValues_obj::A_MOVEMENT;

::String ConstValues_obj::A_VISIBLE;

::String ConstValues_obj::A_X;

::String ConstValues_obj::A_Y;

::String ConstValues_obj::A_WIDTH;

::String ConstValues_obj::A_HEIGHT;

::String ConstValues_obj::A_PIVOT_X;

::String ConstValues_obj::A_PIVOT_Y;

::String ConstValues_obj::A_ALPHA;

::String ConstValues_obj::A_RED;

::String ConstValues_obj::A_GREEN;

::String ConstValues_obj::A_BLUE;

::String ConstValues_obj::A_ALPHA_MULTIPLIER;

::String ConstValues_obj::A_RED_MULTIPLIER;

::String ConstValues_obj::A_GREEN_MULTIPLIER;

::String ConstValues_obj::A_BLUE_MULTIPLIER;

::String ConstValues_obj::V_SOUND_LEFT;

::String ConstValues_obj::V_SOUND_RIGHT;

::String ConstValues_obj::V_SOUND_LEFT_TO_RIGHT;

::String ConstValues_obj::V_SOUND_RIGHT_TO_LEFT;

::String ConstValues_obj::V_SOUND_FADE_IN;

::String ConstValues_obj::V_SOUND_FADE_OUT;


ConstValues_obj::ConstValues_obj()
{
}

void ConstValues_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(ConstValues);
	HX_MARK_END_CLASS();
}

void ConstValues_obj::__Visit(HX_VISIT_PARAMS)
{
}

Dynamic ConstValues_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"AT") ) { return AT; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"A_Z") ) { return A_Z; }
		if (HX_FIELD_EQ(inName,"A_X") ) { return A_X; }
		if (HX_FIELD_EQ(inName,"A_Y") ) { return A_Y; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"BONE") ) { return BONE; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"FRAME") ) { return FRAME; }
		if (HX_FIELD_EQ(inName,"A_RED") ) { return A_RED; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"A_NAME") ) { return A_NAME; }
		if (HX_FIELD_EQ(inName,"A_LOOP") ) { return A_LOOP; }
		if (HX_FIELD_EQ(inName,"A_BLUE") ) { return A_BLUE; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"VERSION") ) { return VERSION; }
		if (HX_FIELD_EQ(inName,"DISPLAY") ) { return DISPLAY; }
		if (HX_FIELD_EQ(inName,"A_EVENT") ) { return A_EVENT; }
		if (HX_FIELD_EQ(inName,"A_SOUND") ) { return A_SOUND; }
		if (HX_FIELD_EQ(inName,"A_WIDTH") ) { return A_WIDTH; }
		if (HX_FIELD_EQ(inName,"A_ALPHA") ) { return A_ALPHA; }
		if (HX_FIELD_EQ(inName,"A_GREEN") ) { return A_GREEN; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"SKELETON") ) { return SKELETON; }
		if (HX_FIELD_EQ(inName,"ARMATURE") ) { return ARMATURE; }
		if (HX_FIELD_EQ(inName,"MOVEMENT") ) { return MOVEMENT; }
		if (HX_FIELD_EQ(inName,"A_PARENT") ) { return A_PARENT; }
		if (HX_FIELD_EQ(inName,"A_SKEW_X") ) { return A_SKEW_X; }
		if (HX_FIELD_EQ(inName,"A_SKEW_Y") ) { return A_SKEW_Y; }
		if (HX_FIELD_EQ(inName,"A_HEIGHT") ) { return A_HEIGHT; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"ARMATURES") ) { return ARMATURES; }
		if (HX_FIELD_EQ(inName,"ANIMATION") ) { return ANIMATION; }
		if (HX_FIELD_EQ(inName,"A_VERSION") ) { return A_VERSION; }
		if (HX_FIELD_EQ(inName,"A_SCALE_X") ) { return A_SCALE_X; }
		if (HX_FIELD_EQ(inName,"A_SCALE_Y") ) { return A_SCALE_Y; }
		if (HX_FIELD_EQ(inName,"A_VISIBLE") ) { return A_VISIBLE; }
		if (HX_FIELD_EQ(inName,"A_PIVOT_X") ) { return A_PIVOT_X; }
		if (HX_FIELD_EQ(inName,"A_PIVOT_Y") ) { return A_PIVOT_Y; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"VERSION_14") ) { return VERSION_14; }
		if (HX_FIELD_EQ(inName,"ANIMATIONS") ) { return ANIMATIONS; }
		if (HX_FIELD_EQ(inName,"A_DURATION") ) { return A_DURATION; }
		if (HX_FIELD_EQ(inName,"A_MOVEMENT") ) { return A_MOVEMENT; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"SUB_TEXTURE") ) { return SUB_TEXTURE; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"A_FRAME_RATE") ) { return A_FRAME_RATE; }
		if (HX_FIELD_EQ(inName,"V_SOUND_LEFT") ) { return V_SOUND_LEFT; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"TEXTURE_ATLAS") ) { return TEXTURE_ATLAS; }
		if (HX_FIELD_EQ(inName,"A_DURATION_TO") ) { return A_DURATION_TO; }
		if (HX_FIELD_EQ(inName,"A_IS_ARMATURE") ) { return A_IS_ARMATURE; }
		if (HX_FIELD_EQ(inName,"V_SOUND_RIGHT") ) { return V_SOUND_RIGHT; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"A_SOUND_EFFECT") ) { return A_SOUND_EFFECT; }
		if (HX_FIELD_EQ(inName,"A_TWEEN_EASING") ) { return A_TWEEN_EASING; }
		if (HX_FIELD_EQ(inName,"A_TWEEN_ROTATE") ) { return A_TWEEN_ROTATE; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"COLOR_TRANSFORM") ) { return COLOR_TRANSFORM; }
		if (HX_FIELD_EQ(inName,"A_DISPLAY_INDEX") ) { return A_DISPLAY_INDEX; }
		if (HX_FIELD_EQ(inName,"V_SOUND_FADE_IN") ) { return V_SOUND_FADE_IN; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"A_DURATION_TWEEN") ) { return A_DURATION_TWEEN; }
		if (HX_FIELD_EQ(inName,"A_MOVEMENT_SCALE") ) { return A_MOVEMENT_SCALE; }
		if (HX_FIELD_EQ(inName,"A_MOVEMENT_DELAY") ) { return A_MOVEMENT_DELAY; }
		if (HX_FIELD_EQ(inName,"A_RED_MULTIPLIER") ) { return A_RED_MULTIPLIER; }
		if (HX_FIELD_EQ(inName,"V_SOUND_FADE_OUT") ) { return V_SOUND_FADE_OUT; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"A_BLUE_MULTIPLIER") ) { return A_BLUE_MULTIPLIER; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"A_ALPHA_MULTIPLIER") ) { return A_ALPHA_MULTIPLIER; }
		if (HX_FIELD_EQ(inName,"A_GREEN_MULTIPLIER") ) { return A_GREEN_MULTIPLIER; }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"V_SOUND_LEFT_TO_RIGHT") ) { return V_SOUND_LEFT_TO_RIGHT; }
		if (HX_FIELD_EQ(inName,"V_SOUND_RIGHT_TO_LEFT") ) { return V_SOUND_RIGHT_TO_LEFT; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic ConstValues_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"AT") ) { AT=inValue.Cast< ::String >(); return inValue; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"A_Z") ) { A_Z=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"A_X") ) { A_X=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"A_Y") ) { A_Y=inValue.Cast< ::String >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"BONE") ) { BONE=inValue.Cast< ::String >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"FRAME") ) { FRAME=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"A_RED") ) { A_RED=inValue.Cast< ::String >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"A_NAME") ) { A_NAME=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"A_LOOP") ) { A_LOOP=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"A_BLUE") ) { A_BLUE=inValue.Cast< ::String >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"VERSION") ) { VERSION=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"DISPLAY") ) { DISPLAY=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"A_EVENT") ) { A_EVENT=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"A_SOUND") ) { A_SOUND=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"A_WIDTH") ) { A_WIDTH=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"A_ALPHA") ) { A_ALPHA=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"A_GREEN") ) { A_GREEN=inValue.Cast< ::String >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"SKELETON") ) { SKELETON=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"ARMATURE") ) { ARMATURE=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"MOVEMENT") ) { MOVEMENT=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"A_PARENT") ) { A_PARENT=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"A_SKEW_X") ) { A_SKEW_X=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"A_SKEW_Y") ) { A_SKEW_Y=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"A_HEIGHT") ) { A_HEIGHT=inValue.Cast< ::String >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"ARMATURES") ) { ARMATURES=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"ANIMATION") ) { ANIMATION=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"A_VERSION") ) { A_VERSION=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"A_SCALE_X") ) { A_SCALE_X=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"A_SCALE_Y") ) { A_SCALE_Y=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"A_VISIBLE") ) { A_VISIBLE=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"A_PIVOT_X") ) { A_PIVOT_X=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"A_PIVOT_Y") ) { A_PIVOT_Y=inValue.Cast< ::String >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"VERSION_14") ) { VERSION_14=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"ANIMATIONS") ) { ANIMATIONS=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"A_DURATION") ) { A_DURATION=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"A_MOVEMENT") ) { A_MOVEMENT=inValue.Cast< ::String >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"SUB_TEXTURE") ) { SUB_TEXTURE=inValue.Cast< ::String >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"A_FRAME_RATE") ) { A_FRAME_RATE=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"V_SOUND_LEFT") ) { V_SOUND_LEFT=inValue.Cast< ::String >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"TEXTURE_ATLAS") ) { TEXTURE_ATLAS=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"A_DURATION_TO") ) { A_DURATION_TO=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"A_IS_ARMATURE") ) { A_IS_ARMATURE=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"V_SOUND_RIGHT") ) { V_SOUND_RIGHT=inValue.Cast< ::String >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"A_SOUND_EFFECT") ) { A_SOUND_EFFECT=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"A_TWEEN_EASING") ) { A_TWEEN_EASING=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"A_TWEEN_ROTATE") ) { A_TWEEN_ROTATE=inValue.Cast< ::String >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"COLOR_TRANSFORM") ) { COLOR_TRANSFORM=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"A_DISPLAY_INDEX") ) { A_DISPLAY_INDEX=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"V_SOUND_FADE_IN") ) { V_SOUND_FADE_IN=inValue.Cast< ::String >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"A_DURATION_TWEEN") ) { A_DURATION_TWEEN=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"A_MOVEMENT_SCALE") ) { A_MOVEMENT_SCALE=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"A_MOVEMENT_DELAY") ) { A_MOVEMENT_DELAY=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"A_RED_MULTIPLIER") ) { A_RED_MULTIPLIER=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"V_SOUND_FADE_OUT") ) { V_SOUND_FADE_OUT=inValue.Cast< ::String >(); return inValue; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"A_BLUE_MULTIPLIER") ) { A_BLUE_MULTIPLIER=inValue.Cast< ::String >(); return inValue; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"A_ALPHA_MULTIPLIER") ) { A_ALPHA_MULTIPLIER=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"A_GREEN_MULTIPLIER") ) { A_GREEN_MULTIPLIER=inValue.Cast< ::String >(); return inValue; }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"V_SOUND_LEFT_TO_RIGHT") ) { V_SOUND_LEFT_TO_RIGHT=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"V_SOUND_RIGHT_TO_LEFT") ) { V_SOUND_RIGHT_TO_LEFT=inValue.Cast< ::String >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void ConstValues_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("VERSION_14"),
	HX_CSTRING("VERSION"),
	HX_CSTRING("SKELETON"),
	HX_CSTRING("ARMATURES"),
	HX_CSTRING("ARMATURE"),
	HX_CSTRING("BONE"),
	HX_CSTRING("DISPLAY"),
	HX_CSTRING("ANIMATIONS"),
	HX_CSTRING("ANIMATION"),
	HX_CSTRING("MOVEMENT"),
	HX_CSTRING("FRAME"),
	HX_CSTRING("COLOR_TRANSFORM"),
	HX_CSTRING("TEXTURE_ATLAS"),
	HX_CSTRING("SUB_TEXTURE"),
	HX_CSTRING("AT"),
	HX_CSTRING("A_VERSION"),
	HX_CSTRING("A_FRAME_RATE"),
	HX_CSTRING("A_NAME"),
	HX_CSTRING("A_DURATION"),
	HX_CSTRING("A_DURATION_TO"),
	HX_CSTRING("A_DURATION_TWEEN"),
	HX_CSTRING("A_LOOP"),
	HX_CSTRING("A_MOVEMENT_SCALE"),
	HX_CSTRING("A_MOVEMENT_DELAY"),
	HX_CSTRING("A_PARENT"),
	HX_CSTRING("A_SKEW_X"),
	HX_CSTRING("A_SKEW_Y"),
	HX_CSTRING("A_SCALE_X"),
	HX_CSTRING("A_SCALE_Y"),
	HX_CSTRING("A_Z"),
	HX_CSTRING("A_DISPLAY_INDEX"),
	HX_CSTRING("A_EVENT"),
	HX_CSTRING("A_SOUND"),
	HX_CSTRING("A_SOUND_EFFECT"),
	HX_CSTRING("A_TWEEN_EASING"),
	HX_CSTRING("A_TWEEN_ROTATE"),
	HX_CSTRING("A_IS_ARMATURE"),
	HX_CSTRING("A_MOVEMENT"),
	HX_CSTRING("A_VISIBLE"),
	HX_CSTRING("A_X"),
	HX_CSTRING("A_Y"),
	HX_CSTRING("A_WIDTH"),
	HX_CSTRING("A_HEIGHT"),
	HX_CSTRING("A_PIVOT_X"),
	HX_CSTRING("A_PIVOT_Y"),
	HX_CSTRING("A_ALPHA"),
	HX_CSTRING("A_RED"),
	HX_CSTRING("A_GREEN"),
	HX_CSTRING("A_BLUE"),
	HX_CSTRING("A_ALPHA_MULTIPLIER"),
	HX_CSTRING("A_RED_MULTIPLIER"),
	HX_CSTRING("A_GREEN_MULTIPLIER"),
	HX_CSTRING("A_BLUE_MULTIPLIER"),
	HX_CSTRING("V_SOUND_LEFT"),
	HX_CSTRING("V_SOUND_RIGHT"),
	HX_CSTRING("V_SOUND_LEFT_TO_RIGHT"),
	HX_CSTRING("V_SOUND_RIGHT_TO_LEFT"),
	HX_CSTRING("V_SOUND_FADE_IN"),
	HX_CSTRING("V_SOUND_FADE_OUT"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(ConstValues_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(ConstValues_obj::VERSION_14,"VERSION_14");
	HX_MARK_MEMBER_NAME(ConstValues_obj::VERSION,"VERSION");
	HX_MARK_MEMBER_NAME(ConstValues_obj::SKELETON,"SKELETON");
	HX_MARK_MEMBER_NAME(ConstValues_obj::ARMATURES,"ARMATURES");
	HX_MARK_MEMBER_NAME(ConstValues_obj::ARMATURE,"ARMATURE");
	HX_MARK_MEMBER_NAME(ConstValues_obj::BONE,"BONE");
	HX_MARK_MEMBER_NAME(ConstValues_obj::DISPLAY,"DISPLAY");
	HX_MARK_MEMBER_NAME(ConstValues_obj::ANIMATIONS,"ANIMATIONS");
	HX_MARK_MEMBER_NAME(ConstValues_obj::ANIMATION,"ANIMATION");
	HX_MARK_MEMBER_NAME(ConstValues_obj::MOVEMENT,"MOVEMENT");
	HX_MARK_MEMBER_NAME(ConstValues_obj::FRAME,"FRAME");
	HX_MARK_MEMBER_NAME(ConstValues_obj::COLOR_TRANSFORM,"COLOR_TRANSFORM");
	HX_MARK_MEMBER_NAME(ConstValues_obj::TEXTURE_ATLAS,"TEXTURE_ATLAS");
	HX_MARK_MEMBER_NAME(ConstValues_obj::SUB_TEXTURE,"SUB_TEXTURE");
	HX_MARK_MEMBER_NAME(ConstValues_obj::AT,"AT");
	HX_MARK_MEMBER_NAME(ConstValues_obj::A_VERSION,"A_VERSION");
	HX_MARK_MEMBER_NAME(ConstValues_obj::A_FRAME_RATE,"A_FRAME_RATE");
	HX_MARK_MEMBER_NAME(ConstValues_obj::A_NAME,"A_NAME");
	HX_MARK_MEMBER_NAME(ConstValues_obj::A_DURATION,"A_DURATION");
	HX_MARK_MEMBER_NAME(ConstValues_obj::A_DURATION_TO,"A_DURATION_TO");
	HX_MARK_MEMBER_NAME(ConstValues_obj::A_DURATION_TWEEN,"A_DURATION_TWEEN");
	HX_MARK_MEMBER_NAME(ConstValues_obj::A_LOOP,"A_LOOP");
	HX_MARK_MEMBER_NAME(ConstValues_obj::A_MOVEMENT_SCALE,"A_MOVEMENT_SCALE");
	HX_MARK_MEMBER_NAME(ConstValues_obj::A_MOVEMENT_DELAY,"A_MOVEMENT_DELAY");
	HX_MARK_MEMBER_NAME(ConstValues_obj::A_PARENT,"A_PARENT");
	HX_MARK_MEMBER_NAME(ConstValues_obj::A_SKEW_X,"A_SKEW_X");
	HX_MARK_MEMBER_NAME(ConstValues_obj::A_SKEW_Y,"A_SKEW_Y");
	HX_MARK_MEMBER_NAME(ConstValues_obj::A_SCALE_X,"A_SCALE_X");
	HX_MARK_MEMBER_NAME(ConstValues_obj::A_SCALE_Y,"A_SCALE_Y");
	HX_MARK_MEMBER_NAME(ConstValues_obj::A_Z,"A_Z");
	HX_MARK_MEMBER_NAME(ConstValues_obj::A_DISPLAY_INDEX,"A_DISPLAY_INDEX");
	HX_MARK_MEMBER_NAME(ConstValues_obj::A_EVENT,"A_EVENT");
	HX_MARK_MEMBER_NAME(ConstValues_obj::A_SOUND,"A_SOUND");
	HX_MARK_MEMBER_NAME(ConstValues_obj::A_SOUND_EFFECT,"A_SOUND_EFFECT");
	HX_MARK_MEMBER_NAME(ConstValues_obj::A_TWEEN_EASING,"A_TWEEN_EASING");
	HX_MARK_MEMBER_NAME(ConstValues_obj::A_TWEEN_ROTATE,"A_TWEEN_ROTATE");
	HX_MARK_MEMBER_NAME(ConstValues_obj::A_IS_ARMATURE,"A_IS_ARMATURE");
	HX_MARK_MEMBER_NAME(ConstValues_obj::A_MOVEMENT,"A_MOVEMENT");
	HX_MARK_MEMBER_NAME(ConstValues_obj::A_VISIBLE,"A_VISIBLE");
	HX_MARK_MEMBER_NAME(ConstValues_obj::A_X,"A_X");
	HX_MARK_MEMBER_NAME(ConstValues_obj::A_Y,"A_Y");
	HX_MARK_MEMBER_NAME(ConstValues_obj::A_WIDTH,"A_WIDTH");
	HX_MARK_MEMBER_NAME(ConstValues_obj::A_HEIGHT,"A_HEIGHT");
	HX_MARK_MEMBER_NAME(ConstValues_obj::A_PIVOT_X,"A_PIVOT_X");
	HX_MARK_MEMBER_NAME(ConstValues_obj::A_PIVOT_Y,"A_PIVOT_Y");
	HX_MARK_MEMBER_NAME(ConstValues_obj::A_ALPHA,"A_ALPHA");
	HX_MARK_MEMBER_NAME(ConstValues_obj::A_RED,"A_RED");
	HX_MARK_MEMBER_NAME(ConstValues_obj::A_GREEN,"A_GREEN");
	HX_MARK_MEMBER_NAME(ConstValues_obj::A_BLUE,"A_BLUE");
	HX_MARK_MEMBER_NAME(ConstValues_obj::A_ALPHA_MULTIPLIER,"A_ALPHA_MULTIPLIER");
	HX_MARK_MEMBER_NAME(ConstValues_obj::A_RED_MULTIPLIER,"A_RED_MULTIPLIER");
	HX_MARK_MEMBER_NAME(ConstValues_obj::A_GREEN_MULTIPLIER,"A_GREEN_MULTIPLIER");
	HX_MARK_MEMBER_NAME(ConstValues_obj::A_BLUE_MULTIPLIER,"A_BLUE_MULTIPLIER");
	HX_MARK_MEMBER_NAME(ConstValues_obj::V_SOUND_LEFT,"V_SOUND_LEFT");
	HX_MARK_MEMBER_NAME(ConstValues_obj::V_SOUND_RIGHT,"V_SOUND_RIGHT");
	HX_MARK_MEMBER_NAME(ConstValues_obj::V_SOUND_LEFT_TO_RIGHT,"V_SOUND_LEFT_TO_RIGHT");
	HX_MARK_MEMBER_NAME(ConstValues_obj::V_SOUND_RIGHT_TO_LEFT,"V_SOUND_RIGHT_TO_LEFT");
	HX_MARK_MEMBER_NAME(ConstValues_obj::V_SOUND_FADE_IN,"V_SOUND_FADE_IN");
	HX_MARK_MEMBER_NAME(ConstValues_obj::V_SOUND_FADE_OUT,"V_SOUND_FADE_OUT");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(ConstValues_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(ConstValues_obj::VERSION_14,"VERSION_14");
	HX_VISIT_MEMBER_NAME(ConstValues_obj::VERSION,"VERSION");
	HX_VISIT_MEMBER_NAME(ConstValues_obj::SKELETON,"SKELETON");
	HX_VISIT_MEMBER_NAME(ConstValues_obj::ARMATURES,"ARMATURES");
	HX_VISIT_MEMBER_NAME(ConstValues_obj::ARMATURE,"ARMATURE");
	HX_VISIT_MEMBER_NAME(ConstValues_obj::BONE,"BONE");
	HX_VISIT_MEMBER_NAME(ConstValues_obj::DISPLAY,"DISPLAY");
	HX_VISIT_MEMBER_NAME(ConstValues_obj::ANIMATIONS,"ANIMATIONS");
	HX_VISIT_MEMBER_NAME(ConstValues_obj::ANIMATION,"ANIMATION");
	HX_VISIT_MEMBER_NAME(ConstValues_obj::MOVEMENT,"MOVEMENT");
	HX_VISIT_MEMBER_NAME(ConstValues_obj::FRAME,"FRAME");
	HX_VISIT_MEMBER_NAME(ConstValues_obj::COLOR_TRANSFORM,"COLOR_TRANSFORM");
	HX_VISIT_MEMBER_NAME(ConstValues_obj::TEXTURE_ATLAS,"TEXTURE_ATLAS");
	HX_VISIT_MEMBER_NAME(ConstValues_obj::SUB_TEXTURE,"SUB_TEXTURE");
	HX_VISIT_MEMBER_NAME(ConstValues_obj::AT,"AT");
	HX_VISIT_MEMBER_NAME(ConstValues_obj::A_VERSION,"A_VERSION");
	HX_VISIT_MEMBER_NAME(ConstValues_obj::A_FRAME_RATE,"A_FRAME_RATE");
	HX_VISIT_MEMBER_NAME(ConstValues_obj::A_NAME,"A_NAME");
	HX_VISIT_MEMBER_NAME(ConstValues_obj::A_DURATION,"A_DURATION");
	HX_VISIT_MEMBER_NAME(ConstValues_obj::A_DURATION_TO,"A_DURATION_TO");
	HX_VISIT_MEMBER_NAME(ConstValues_obj::A_DURATION_TWEEN,"A_DURATION_TWEEN");
	HX_VISIT_MEMBER_NAME(ConstValues_obj::A_LOOP,"A_LOOP");
	HX_VISIT_MEMBER_NAME(ConstValues_obj::A_MOVEMENT_SCALE,"A_MOVEMENT_SCALE");
	HX_VISIT_MEMBER_NAME(ConstValues_obj::A_MOVEMENT_DELAY,"A_MOVEMENT_DELAY");
	HX_VISIT_MEMBER_NAME(ConstValues_obj::A_PARENT,"A_PARENT");
	HX_VISIT_MEMBER_NAME(ConstValues_obj::A_SKEW_X,"A_SKEW_X");
	HX_VISIT_MEMBER_NAME(ConstValues_obj::A_SKEW_Y,"A_SKEW_Y");
	HX_VISIT_MEMBER_NAME(ConstValues_obj::A_SCALE_X,"A_SCALE_X");
	HX_VISIT_MEMBER_NAME(ConstValues_obj::A_SCALE_Y,"A_SCALE_Y");
	HX_VISIT_MEMBER_NAME(ConstValues_obj::A_Z,"A_Z");
	HX_VISIT_MEMBER_NAME(ConstValues_obj::A_DISPLAY_INDEX,"A_DISPLAY_INDEX");
	HX_VISIT_MEMBER_NAME(ConstValues_obj::A_EVENT,"A_EVENT");
	HX_VISIT_MEMBER_NAME(ConstValues_obj::A_SOUND,"A_SOUND");
	HX_VISIT_MEMBER_NAME(ConstValues_obj::A_SOUND_EFFECT,"A_SOUND_EFFECT");
	HX_VISIT_MEMBER_NAME(ConstValues_obj::A_TWEEN_EASING,"A_TWEEN_EASING");
	HX_VISIT_MEMBER_NAME(ConstValues_obj::A_TWEEN_ROTATE,"A_TWEEN_ROTATE");
	HX_VISIT_MEMBER_NAME(ConstValues_obj::A_IS_ARMATURE,"A_IS_ARMATURE");
	HX_VISIT_MEMBER_NAME(ConstValues_obj::A_MOVEMENT,"A_MOVEMENT");
	HX_VISIT_MEMBER_NAME(ConstValues_obj::A_VISIBLE,"A_VISIBLE");
	HX_VISIT_MEMBER_NAME(ConstValues_obj::A_X,"A_X");
	HX_VISIT_MEMBER_NAME(ConstValues_obj::A_Y,"A_Y");
	HX_VISIT_MEMBER_NAME(ConstValues_obj::A_WIDTH,"A_WIDTH");
	HX_VISIT_MEMBER_NAME(ConstValues_obj::A_HEIGHT,"A_HEIGHT");
	HX_VISIT_MEMBER_NAME(ConstValues_obj::A_PIVOT_X,"A_PIVOT_X");
	HX_VISIT_MEMBER_NAME(ConstValues_obj::A_PIVOT_Y,"A_PIVOT_Y");
	HX_VISIT_MEMBER_NAME(ConstValues_obj::A_ALPHA,"A_ALPHA");
	HX_VISIT_MEMBER_NAME(ConstValues_obj::A_RED,"A_RED");
	HX_VISIT_MEMBER_NAME(ConstValues_obj::A_GREEN,"A_GREEN");
	HX_VISIT_MEMBER_NAME(ConstValues_obj::A_BLUE,"A_BLUE");
	HX_VISIT_MEMBER_NAME(ConstValues_obj::A_ALPHA_MULTIPLIER,"A_ALPHA_MULTIPLIER");
	HX_VISIT_MEMBER_NAME(ConstValues_obj::A_RED_MULTIPLIER,"A_RED_MULTIPLIER");
	HX_VISIT_MEMBER_NAME(ConstValues_obj::A_GREEN_MULTIPLIER,"A_GREEN_MULTIPLIER");
	HX_VISIT_MEMBER_NAME(ConstValues_obj::A_BLUE_MULTIPLIER,"A_BLUE_MULTIPLIER");
	HX_VISIT_MEMBER_NAME(ConstValues_obj::V_SOUND_LEFT,"V_SOUND_LEFT");
	HX_VISIT_MEMBER_NAME(ConstValues_obj::V_SOUND_RIGHT,"V_SOUND_RIGHT");
	HX_VISIT_MEMBER_NAME(ConstValues_obj::V_SOUND_LEFT_TO_RIGHT,"V_SOUND_LEFT_TO_RIGHT");
	HX_VISIT_MEMBER_NAME(ConstValues_obj::V_SOUND_RIGHT_TO_LEFT,"V_SOUND_RIGHT_TO_LEFT");
	HX_VISIT_MEMBER_NAME(ConstValues_obj::V_SOUND_FADE_IN,"V_SOUND_FADE_IN");
	HX_VISIT_MEMBER_NAME(ConstValues_obj::V_SOUND_FADE_OUT,"V_SOUND_FADE_OUT");
};

Class ConstValues_obj::__mClass;

void ConstValues_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("hxDragonBones.utils.ConstValues"), hx::TCanCast< ConstValues_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void ConstValues_obj::__boot()
{
	VERSION_14= HX_CSTRING("1.4");
	VERSION= HX_CSTRING("2.0");
	SKELETON= HX_CSTRING("skeleton");
	ARMATURES= HX_CSTRING("armatures");
	ARMATURE= HX_CSTRING("armature");
	BONE= HX_CSTRING("b");
	DISPLAY= HX_CSTRING("d");
	ANIMATIONS= HX_CSTRING("animations");
	ANIMATION= HX_CSTRING("animation");
	MOVEMENT= HX_CSTRING("mov");
	FRAME= HX_CSTRING("f");
	COLOR_TRANSFORM= HX_CSTRING("colorTransform");
	TEXTURE_ATLAS= HX_CSTRING("TextureAtlas");
	SUB_TEXTURE= HX_CSTRING("SubTexture");
	AT= HX_CSTRING("@");
	A_VERSION= HX_CSTRING("version");
	A_FRAME_RATE= HX_CSTRING("frameRate");
	A_NAME= HX_CSTRING("name");
	A_DURATION= HX_CSTRING("dr");
	A_DURATION_TO= HX_CSTRING("to");
	A_DURATION_TWEEN= HX_CSTRING("drTW");
	A_LOOP= HX_CSTRING("lp");
	A_MOVEMENT_SCALE= HX_CSTRING("sc");
	A_MOVEMENT_DELAY= HX_CSTRING("dl");
	A_PARENT= HX_CSTRING("parent");
	A_SKEW_X= HX_CSTRING("kX");
	A_SKEW_Y= HX_CSTRING("kY");
	A_SCALE_X= HX_CSTRING("cX");
	A_SCALE_Y= HX_CSTRING("cY");
	A_Z= HX_CSTRING("z");
	A_DISPLAY_INDEX= HX_CSTRING("dI");
	A_EVENT= HX_CSTRING("evt");
	A_SOUND= HX_CSTRING("sd");
	A_SOUND_EFFECT= HX_CSTRING("sdE");
	A_TWEEN_EASING= HX_CSTRING("twE");
	A_TWEEN_ROTATE= HX_CSTRING("twR");
	A_IS_ARMATURE= HX_CSTRING("isArmature");
	A_MOVEMENT= HX_CSTRING("mov");
	A_VISIBLE= HX_CSTRING("visible");
	A_X= HX_CSTRING("x");
	A_Y= HX_CSTRING("y");
	A_WIDTH= HX_CSTRING("width");
	A_HEIGHT= HX_CSTRING("height");
	A_PIVOT_X= HX_CSTRING("pX");
	A_PIVOT_Y= HX_CSTRING("pY");
	A_ALPHA= HX_CSTRING("a");
	A_RED= HX_CSTRING("r");
	A_GREEN= HX_CSTRING("g");
	A_BLUE= HX_CSTRING("b");
	A_ALPHA_MULTIPLIER= HX_CSTRING("aM");
	A_RED_MULTIPLIER= HX_CSTRING("rM");
	A_GREEN_MULTIPLIER= HX_CSTRING("gM");
	A_BLUE_MULTIPLIER= HX_CSTRING("bM");
	V_SOUND_LEFT= HX_CSTRING("l");
	V_SOUND_RIGHT= HX_CSTRING("r");
	V_SOUND_LEFT_TO_RIGHT= HX_CSTRING("lr");
	V_SOUND_RIGHT_TO_LEFT= HX_CSTRING("rl");
	V_SOUND_FADE_IN= HX_CSTRING("in");
	V_SOUND_FADE_OUT= HX_CSTRING("out");
}

} // end namespace hxDragonBones
} // end namespace utils
