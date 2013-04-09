#include <hxcpp.h>

#ifndef INCLUDED_Lambda
#include <Lambda.h>
#endif
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_haxe_Timer
#include <haxe/Timer.h>
#endif
#ifndef INCLUDED_hxDragonBones_animation_IAnimatable
#include <hxDragonBones/animation/IAnimatable.h>
#endif
#ifndef INCLUDED_hxDragonBones_animation_WorldClock
#include <hxDragonBones/animation/WorldClock.h>
#endif
namespace hxDragonBones{
namespace animation{

Void WorldClock_obj::__construct()
{
HX_STACK_PUSH("WorldClock::new","hxDragonBones/animation/WorldClock.hx",19);
{
	HX_STACK_LINE(20)
	this->time = ::haxe::Timer_obj::stamp();
	HX_STACK_LINE(21)
	this->set_timeScale((int)1);
	HX_STACK_LINE(22)
	this->_animatableList = Array_obj< ::hxDragonBones::animation::IAnimatable >::__new();
}
;
	return null();
}

WorldClock_obj::~WorldClock_obj() { }

Dynamic WorldClock_obj::__CreateEmpty() { return  new WorldClock_obj; }
hx::ObjectPtr< WorldClock_obj > WorldClock_obj::__new()
{  hx::ObjectPtr< WorldClock_obj > result = new WorldClock_obj();
	result->__construct();
	return result;}

Dynamic WorldClock_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< WorldClock_obj > result = new WorldClock_obj();
	result->__construct();
	return result;}

hx::Object *WorldClock_obj::__ToInterface(const type_info &inType) {
	if (inType==typeid( ::hxDragonBones::animation::IAnimatable_obj)) return operator ::hxDragonBones::animation::IAnimatable_obj *();
	return super::__ToInterface(inType);
}

Void WorldClock_obj::advanceTime( hx::Null< Float >  __o_passedTime){
Float passedTime = __o_passedTime.Default(-1);
	HX_STACK_PUSH("WorldClock::advanceTime","hxDragonBones/animation/WorldClock.hx",57);
	HX_STACK_THIS(this);
	HX_STACK_ARG(passedTime,"passedTime");
{
		HX_STACK_LINE(58)
		if (((passedTime < (int)0))){
			HX_STACK_LINE(59)
			Float curTime = ::haxe::Timer_obj::stamp();		HX_STACK_VAR(curTime,"curTime");
			HX_STACK_LINE(60)
			passedTime = (curTime - this->time);
			HX_STACK_LINE(61)
			this->time = curTime;
		}
		HX_STACK_LINE(64)
		hx::MultEq(passedTime,this->timeScale);
		HX_STACK_LINE(66)
		{
			HX_STACK_LINE(66)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			Array< ::hxDragonBones::animation::IAnimatable > _g1 = this->_animatableList;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(66)
			while(((_g < _g1->length))){
				HX_STACK_LINE(66)
				::hxDragonBones::animation::IAnimatable a = _g1->__get(_g);		HX_STACK_VAR(a,"a");
				HX_STACK_LINE(66)
				++(_g);
				HX_STACK_LINE(67)
				a->advanceTime(passedTime);
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(WorldClock_obj,advanceTime,(void))

Void WorldClock_obj::clear( ){
{
		HX_STACK_PUSH("WorldClock::clear","hxDragonBones/animation/WorldClock.hx",53);
		HX_STACK_THIS(this);
		HX_STACK_LINE(53)
		this->_animatableList = Array_obj< ::hxDragonBones::animation::IAnimatable >::__new();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(WorldClock_obj,clear,(void))

Void WorldClock_obj::remove( ::hxDragonBones::animation::IAnimatable animatable){
{
		HX_STACK_PUSH("WorldClock::remove","hxDragonBones/animation/WorldClock.hx",49);
		HX_STACK_THIS(this);
		HX_STACK_ARG(animatable,"animatable");
		HX_STACK_LINE(49)
		this->_animatableList->remove(animatable);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(WorldClock_obj,remove,(void))

Void WorldClock_obj::add( ::hxDragonBones::animation::IAnimatable animatable){
{
		HX_STACK_PUSH("WorldClock::add","hxDragonBones/animation/WorldClock.hx",43);
		HX_STACK_THIS(this);
		HX_STACK_ARG(animatable,"animatable");
		HX_STACK_LINE(43)
		if (((bool((animatable != null())) && bool(!(this->has(animatable)))))){
			HX_STACK_LINE(44)
			this->_animatableList->push(animatable);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(WorldClock_obj,add,(void))

bool WorldClock_obj::has( ::hxDragonBones::animation::IAnimatable animatable){
	HX_STACK_PUSH("WorldClock::has","hxDragonBones/animation/WorldClock.hx",39);
	HX_STACK_THIS(this);
	HX_STACK_ARG(animatable,"animatable");
	HX_STACK_LINE(39)
	return ::Lambda_obj::has(this->_animatableList,animatable,null());
}


HX_DEFINE_DYNAMIC_FUNC1(WorldClock_obj,has,return )

Float WorldClock_obj::set_timeScale( Float value){
	HX_STACK_PUSH("WorldClock::set_timeScale","hxDragonBones/animation/WorldClock.hx",28);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(29)
	if (((bool((value < (int)0)) || bool(::Math_obj::isNaN(value))))){
		HX_STACK_LINE(29)
		value = (int)0;
	}
	HX_STACK_LINE(32)
	this->timeScale = value;
	HX_STACK_LINE(33)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(WorldClock_obj,set_timeScale,return )

::hxDragonBones::animation::WorldClock WorldClock_obj::instance;

::hxDragonBones::animation::WorldClock WorldClock_obj::get_instance( ){
	HX_STACK_PUSH("WorldClock::get_instance","hxDragonBones/animation/WorldClock.hx",12);
	HX_STACK_LINE(13)
	if (((::hxDragonBones::animation::WorldClock_obj::instance == null()))){
		HX_STACK_LINE(13)
		::hxDragonBones::animation::WorldClock_obj::instance = ::hxDragonBones::animation::WorldClock_obj::__new();
	}
	HX_STACK_LINE(16)
	return ::hxDragonBones::animation::WorldClock_obj::instance;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(WorldClock_obj,get_instance,return )


WorldClock_obj::WorldClock_obj()
{
}

void WorldClock_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(WorldClock);
	HX_MARK_MEMBER_NAME(_time,"_time");
	HX_MARK_MEMBER_NAME(_animatableList,"_animatableList");
	HX_MARK_MEMBER_NAME(timeScale,"timeScale");
	HX_MARK_MEMBER_NAME(time,"time");
	HX_MARK_END_CLASS();
}

void WorldClock_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_time,"_time");
	HX_VISIT_MEMBER_NAME(_animatableList,"_animatableList");
	HX_VISIT_MEMBER_NAME(timeScale,"timeScale");
	HX_VISIT_MEMBER_NAME(time,"time");
}

Dynamic WorldClock_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"add") ) { return add_dyn(); }
		if (HX_FIELD_EQ(inName,"has") ) { return has_dyn(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"time") ) { return time; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"clear") ) { return clear_dyn(); }
		if (HX_FIELD_EQ(inName,"_time") ) { return _time; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"remove") ) { return remove_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"instance") ) { return inCallProp ? get_instance() : instance; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"timeScale") ) { return timeScale; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"advanceTime") ) { return advanceTime_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"get_instance") ) { return get_instance_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"set_timeScale") ) { return set_timeScale_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"_animatableList") ) { return _animatableList; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic WorldClock_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"time") ) { time=inValue.Cast< Float >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_time") ) { _time=inValue.Cast< Float >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"instance") ) { instance=inValue.Cast< ::hxDragonBones::animation::WorldClock >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"timeScale") ) { if (inCallProp) return set_timeScale(inValue);timeScale=inValue.Cast< Float >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"_animatableList") ) { _animatableList=inValue.Cast< Array< ::hxDragonBones::animation::IAnimatable > >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void WorldClock_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_time"));
	outFields->push(HX_CSTRING("_animatableList"));
	outFields->push(HX_CSTRING("timeScale"));
	outFields->push(HX_CSTRING("time"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("instance"),
	HX_CSTRING("get_instance"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("advanceTime"),
	HX_CSTRING("clear"),
	HX_CSTRING("remove"),
	HX_CSTRING("add"),
	HX_CSTRING("has"),
	HX_CSTRING("_time"),
	HX_CSTRING("_animatableList"),
	HX_CSTRING("set_timeScale"),
	HX_CSTRING("timeScale"),
	HX_CSTRING("time"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(WorldClock_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(WorldClock_obj::instance,"instance");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(WorldClock_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(WorldClock_obj::instance,"instance");
};

Class WorldClock_obj::__mClass;

void WorldClock_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("hxDragonBones.animation.WorldClock"), hx::TCanCast< WorldClock_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void WorldClock_obj::__boot()
{
}

} // end namespace hxDragonBones
} // end namespace animation
