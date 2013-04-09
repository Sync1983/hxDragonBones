#include <hxcpp.h>

#ifndef INCLUDED_Lambda
#include <Lambda.h>
#endif
#ifndef INCLUDED_Reflect
#include <Reflect.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_hxDragonBones_Armature
#include <hxDragonBones/Armature.h>
#endif
#ifndef INCLUDED_hxDragonBones_Bone
#include <hxDragonBones/Bone.h>
#endif
#ifndef INCLUDED_hxDragonBones_animation_Animation
#include <hxDragonBones/animation/Animation.h>
#endif
#ifndef INCLUDED_hxDragonBones_animation_IAnimatable
#include <hxDragonBones/animation/IAnimatable.h>
#endif
#ifndef INCLUDED_hxDragonBones_display_IDisplayBridge
#include <hxDragonBones/display/IDisplayBridge.h>
#endif
#ifndef INCLUDED_hxDragonBones_events_ArmatureEvent
#include <hxDragonBones/events/ArmatureEvent.h>
#endif
#ifndef INCLUDED_hxDragonBones_objects_Node
#include <hxDragonBones/objects/Node.h>
#endif
#ifndef INCLUDED_hxDragonBones_utils_IDisposable
#include <hxDragonBones/utils/IDisposable.h>
#endif
#ifndef INCLUDED_native_events_Event
#include <native/events/Event.h>
#endif
#ifndef INCLUDED_native_events_EventDispatcher
#include <native/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_native_events_IEventDispatcher
#include <native/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_native_geom_ColorTransform
#include <native/geom/ColorTransform.h>
#endif
namespace hxDragonBones{

Void Armature_obj::__construct(Dynamic display)
{
HX_STACK_PUSH("Armature::new","hxDragonBones/Armature.hx",17);
{
	HX_STACK_LINE(18)
	super::__construct(null());
	HX_STACK_LINE(19)
	this->display = display;
	HX_STACK_LINE(20)
	this->bones = Array_obj< ::hxDragonBones::Bone >::__new();
	HX_STACK_LINE(21)
	this->_rootBones = Array_obj< ::hxDragonBones::Bone >::__new();
	HX_STACK_LINE(22)
	this->animation = ::hxDragonBones::animation::Animation_obj::__new(hx::ObjectPtr<OBJ_>(this));
	HX_STACK_LINE(23)
	this->bonesIndexChanged = false;
}
;
	return null();
}

Armature_obj::~Armature_obj() { }

Dynamic Armature_obj::__CreateEmpty() { return  new Armature_obj; }
hx::ObjectPtr< Armature_obj > Armature_obj::__new(Dynamic display)
{  hx::ObjectPtr< Armature_obj > result = new Armature_obj();
	result->__construct(display);
	return result;}

Dynamic Armature_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Armature_obj > result = new Armature_obj();
	result->__construct(inArgs[0]);
	return result;}

hx::Object *Armature_obj::__ToInterface(const type_info &inType) {
	if (inType==typeid( ::hxDragonBones::utils::IDisposable_obj)) return operator ::hxDragonBones::utils::IDisposable_obj *();
	if (inType==typeid( ::hxDragonBones::animation::IAnimatable_obj)) return operator ::hxDragonBones::animation::IAnimatable_obj *();
	return super::__ToInterface(inType);
}

int Armature_obj::compareZ( Dynamic a,Dynamic b){
	HX_STACK_PUSH("Armature::compareZ","hxDragonBones/Armature.hx",167);
	HX_STACK_THIS(this);
	HX_STACK_ARG(a,"a");
	HX_STACK_ARG(b,"b");
	HX_STACK_LINE(167)
	return ::Reflect_obj::compare(a->__Field(HX_CSTRING("global"),true)->__Field(HX_CSTRING("z"),true),b->__Field(HX_CSTRING("global"),true)->__Field(HX_CSTRING("z"),true));
}


HX_DEFINE_DYNAMIC_FUNC2(Armature_obj,compareZ,return )

Void Armature_obj::removeFromBones( ::hxDragonBones::Bone bone){
{
		HX_STACK_PUSH("Armature::removeFromBones","hxDragonBones/Armature.hx",155);
		HX_STACK_THIS(this);
		HX_STACK_ARG(bone,"bone");
		HX_STACK_LINE(156)
		this->bones->remove(bone);
		HX_STACK_LINE(157)
		this->_rootBones->remove(bone);
		HX_STACK_LINE(159)
		bone->armature = null();
		HX_STACK_LINE(160)
		bone->displayBridge->removeDisplayFromParent();
		HX_STACK_LINE(161)
		{
			HX_STACK_LINE(161)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			Array< ::hxDragonBones::Bone > _g1 = bone->children;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(161)
			while(((_g < _g1->length))){
				HX_STACK_LINE(161)
				::hxDragonBones::Bone i = _g1->__get(_g);		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(161)
				++(_g);
				HX_STACK_LINE(162)
				this->removeFromBones(i);
			}
		}
		HX_STACK_LINE(164)
		this->bonesIndexChanged = true;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Armature_obj,removeFromBones,(void))

Void Armature_obj::addToBones( ::hxDragonBones::Bone bone,Dynamic root){
{
		HX_STACK_PUSH("Armature::addToBones","hxDragonBones/Armature.hx",134);
		HX_STACK_THIS(this);
		HX_STACK_ARG(bone,"bone");
		HX_STACK_ARG(root,"root");
		HX_STACK_LINE(135)
		if ((!(::Lambda_obj::has(this->bones,bone,null())))){
			HX_STACK_LINE(135)
			this->bones->push(bone);
		}
		HX_STACK_LINE(139)
		if ((root)){
			HX_STACK_LINE(139)
			if ((!(::Lambda_obj::has(this->_rootBones,bone,null())))){
				HX_STACK_LINE(140)
				this->_rootBones->push(bone);
			}
		}
		else{
			HX_STACK_LINE(143)
			this->_rootBones->remove(bone);
		}
		HX_STACK_LINE(147)
		bone->armature = hx::ObjectPtr<OBJ_>(this);
		HX_STACK_LINE(148)
		bone->displayBridge->addDisplayTo(this->display,::Std_obj::_int(bone->global->z));
		HX_STACK_LINE(149)
		{
			HX_STACK_LINE(149)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			Array< ::hxDragonBones::Bone > _g1 = bone->children;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(149)
			while(((_g < _g1->length))){
				HX_STACK_LINE(149)
				::hxDragonBones::Bone i = _g1->__get(_g);		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(149)
				++(_g);
				HX_STACK_LINE(150)
				this->addToBones(i,null());
			}
		}
		HX_STACK_LINE(152)
		this->bonesIndexChanged = true;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Armature_obj,addToBones,(void))

Void Armature_obj::updateBonesZ( ){
{
		HX_STACK_PUSH("Armature::updateBonesZ","hxDragonBones/Armature.hx",120);
		HX_STACK_THIS(this);
		HX_STACK_LINE(121)
		this->bones->sort(this->compareZ_dyn());
		HX_STACK_LINE(122)
		{
			HX_STACK_LINE(122)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			Array< ::hxDragonBones::Bone > _g1 = this->bones;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(122)
			while(((_g < _g1->length))){
				HX_STACK_LINE(122)
				::hxDragonBones::Bone bone = _g1->__get(_g);		HX_STACK_VAR(bone,"bone");
				HX_STACK_LINE(122)
				++(_g);
				HX_STACK_LINE(123)
				if ((bone->isOnStage)){
					HX_STACK_LINE(123)
					bone->displayBridge->addDisplayTo(this->display,null());
				}
			}
		}
		HX_STACK_LINE(127)
		this->bonesIndexChanged = false;
		HX_STACK_LINE(129)
		if ((this->hasEventListener(HX_CSTRING("zOrderUpdated")))){
			HX_STACK_LINE(129)
			this->dispatchEvent(::hxDragonBones::events::ArmatureEvent_obj::__new(HX_CSTRING("zOrderUpdated"),null(),null()));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Armature_obj,updateBonesZ,(void))

Void Armature_obj::update( ){
{
		HX_STACK_PUSH("Armature::update","hxDragonBones/Armature.hx",110);
		HX_STACK_THIS(this);
		HX_STACK_LINE(111)
		{
			HX_STACK_LINE(111)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			Array< ::hxDragonBones::Bone > _g1 = this->_rootBones;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(111)
			while(((_g < _g1->length))){
				HX_STACK_LINE(111)
				::hxDragonBones::Bone i = _g1->__get(_g);		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(111)
				++(_g);
				HX_STACK_LINE(112)
				i->update();
			}
		}
		HX_STACK_LINE(115)
		if ((this->bonesIndexChanged)){
			HX_STACK_LINE(115)
			this->updateBonesZ();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Armature_obj,update,(void))

Void Armature_obj::advanceTime( hx::Null< Float >  __o_passedTime){
Float passedTime = __o_passedTime.Default(-1);
	HX_STACK_PUSH("Armature::advanceTime","hxDragonBones/Armature.hx",105);
	HX_STACK_THIS(this);
	HX_STACK_ARG(passedTime,"passedTime");
{
		HX_STACK_LINE(106)
		this->animation->advanceTime(passedTime);
		HX_STACK_LINE(107)
		this->update();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Armature_obj,advanceTime,(void))

Void Armature_obj::removeBoneByName( ::String boneName){
{
		HX_STACK_PUSH("Armature::removeBoneByName","hxDragonBones/Armature.hx",101);
		HX_STACK_THIS(this);
		HX_STACK_ARG(boneName,"boneName");
		HX_STACK_LINE(101)
		this->removeBone(this->getBone(boneName));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Armature_obj,removeBoneByName,(void))

Void Armature_obj::removeBone( ::hxDragonBones::Bone bone){
{
		HX_STACK_PUSH("Armature::removeBone","hxDragonBones/Armature.hx",91);
		HX_STACK_THIS(this);
		HX_STACK_ARG(bone,"bone");
		HX_STACK_LINE(91)
		if (((bone != null()))){
			HX_STACK_LINE(92)
			if (((bone->parent != null()))){
				HX_STACK_LINE(93)
				bone->removeFromParent();
			}
			else{
				HX_STACK_LINE(95)
				this->removeFromBones(bone);
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Armature_obj,removeBone,(void))

Void Armature_obj::addBone( ::hxDragonBones::Bone bone,::String parentName){
{
		HX_STACK_PUSH("Armature::addBone","hxDragonBones/Armature.hx",79);
		HX_STACK_THIS(this);
		HX_STACK_ARG(bone,"bone");
		HX_STACK_ARG(parentName,"parentName");
		HX_STACK_LINE(79)
		if (((bone != null()))){
			HX_STACK_LINE(81)
			::hxDragonBones::Bone boneParent = this->getBone(parentName);		HX_STACK_VAR(boneParent,"boneParent");
			HX_STACK_LINE(82)
			if (((boneParent != null()))){
				HX_STACK_LINE(82)
				boneParent->addChild(bone);
			}
			else{
				HX_STACK_LINE(85)
				bone->removeFromParent();
				HX_STACK_LINE(86)
				this->addToBones(bone,true);
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Armature_obj,addBone,(void))

::hxDragonBones::Bone Armature_obj::getBoneByDisplay( Dynamic display){
	HX_STACK_PUSH("Armature::getBoneByDisplay","hxDragonBones/Armature.hx",68);
	HX_STACK_THIS(this);
	HX_STACK_ARG(display,"display");
	HX_STACK_LINE(69)
	if (((display != null()))){
		HX_STACK_LINE(70)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		Array< ::hxDragonBones::Bone > _g1 = this->bones;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(70)
		while(((_g < _g1->length))){
			HX_STACK_LINE(70)
			::hxDragonBones::Bone bone = _g1->__get(_g);		HX_STACK_VAR(bone,"bone");
			HX_STACK_LINE(70)
			++(_g);
			HX_STACK_LINE(71)
			if (((bone->get_display() == display))){
				HX_STACK_LINE(71)
				return bone;
			}
		}
	}
	HX_STACK_LINE(76)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Armature_obj,getBoneByDisplay,return )

::hxDragonBones::Bone Armature_obj::getBone( ::String name){
	HX_STACK_PUSH("Armature::getBone","hxDragonBones/Armature.hx",57);
	HX_STACK_THIS(this);
	HX_STACK_ARG(name,"name");
	HX_STACK_LINE(58)
	if (((name != null()))){
		HX_STACK_LINE(59)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		Array< ::hxDragonBones::Bone > _g1 = this->bones;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(59)
		while(((_g < _g1->length))){
			HX_STACK_LINE(59)
			::hxDragonBones::Bone bone = _g1->__get(_g);		HX_STACK_VAR(bone,"bone");
			HX_STACK_LINE(59)
			++(_g);
			HX_STACK_LINE(60)
			if (((bone->name == name))){
				HX_STACK_LINE(60)
				return bone;
			}
		}
	}
	HX_STACK_LINE(65)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Armature_obj,getBone,return )

Void Armature_obj::dispose( ){
{
		HX_STACK_PUSH("Armature::dispose","hxDragonBones/Armature.hx",45);
		HX_STACK_THIS(this);
		HX_STACK_LINE(46)
		{
			HX_STACK_LINE(46)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			Array< ::hxDragonBones::Bone > _g1 = this->_rootBones;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(46)
			while(((_g < _g1->length))){
				HX_STACK_LINE(46)
				::hxDragonBones::Bone i = _g1->__get(_g);		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(46)
				++(_g);
				HX_STACK_LINE(47)
				i->dispose();
			}
		}
		HX_STACK_LINE(50)
		this->set_colorTransform(null());
		HX_STACK_LINE(51)
		this->bones = null();
		HX_STACK_LINE(52)
		this->_rootBones = null();
		HX_STACK_LINE(53)
		this->animation->dispose();
		HX_STACK_LINE(54)
		this->animation = null();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Armature_obj,dispose,(void))

::native::geom::ColorTransform Armature_obj::set_colorTransform( ::native::geom::ColorTransform value){
	HX_STACK_PUSH("Armature::set_colorTransform","hxDragonBones/Armature.hx",34);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(35)
	if (((value == this->colorTransform))){
		HX_STACK_LINE(35)
		return value;
	}
	HX_STACK_LINE(38)
	this->colorTransform = value;
	HX_STACK_LINE(39)
	this->colorTransformChange = true;
	HX_STACK_LINE(40)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(Armature_obj,set_colorTransform,return )


Armature_obj::Armature_obj()
{
}

void Armature_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Armature);
	HX_MARK_MEMBER_NAME(_rootBones,"_rootBones");
	HX_MARK_MEMBER_NAME(colorTransformChange,"colorTransformChange");
	HX_MARK_MEMBER_NAME(colorTransform,"colorTransform");
	HX_MARK_MEMBER_NAME(bonesIndexChanged,"bonesIndexChanged");
	HX_MARK_MEMBER_NAME(bones,"bones");
	HX_MARK_MEMBER_NAME(animation,"animation");
	HX_MARK_MEMBER_NAME(display,"display");
	HX_MARK_MEMBER_NAME(name,"name");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Armature_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_rootBones,"_rootBones");
	HX_VISIT_MEMBER_NAME(colorTransformChange,"colorTransformChange");
	HX_VISIT_MEMBER_NAME(colorTransform,"colorTransform");
	HX_VISIT_MEMBER_NAME(bonesIndexChanged,"bonesIndexChanged");
	HX_VISIT_MEMBER_NAME(bones,"bones");
	HX_VISIT_MEMBER_NAME(animation,"animation");
	HX_VISIT_MEMBER_NAME(display,"display");
	HX_VISIT_MEMBER_NAME(name,"name");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic Armature_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"name") ) { return name; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"bones") ) { return bones; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"addBone") ) { return addBone_dyn(); }
		if (HX_FIELD_EQ(inName,"getBone") ) { return getBone_dyn(); }
		if (HX_FIELD_EQ(inName,"dispose") ) { return dispose_dyn(); }
		if (HX_FIELD_EQ(inName,"display") ) { return display; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"compareZ") ) { return compareZ_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"animation") ) { return animation; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"addToBones") ) { return addToBones_dyn(); }
		if (HX_FIELD_EQ(inName,"removeBone") ) { return removeBone_dyn(); }
		if (HX_FIELD_EQ(inName,"_rootBones") ) { return _rootBones; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"advanceTime") ) { return advanceTime_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"updateBonesZ") ) { return updateBonesZ_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"colorTransform") ) { return colorTransform; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"removeFromBones") ) { return removeFromBones_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"removeBoneByName") ) { return removeBoneByName_dyn(); }
		if (HX_FIELD_EQ(inName,"getBoneByDisplay") ) { return getBoneByDisplay_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"bonesIndexChanged") ) { return bonesIndexChanged; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"set_colorTransform") ) { return set_colorTransform_dyn(); }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"colorTransformChange") ) { return colorTransformChange; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Armature_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"name") ) { name=inValue.Cast< ::String >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"bones") ) { bones=inValue.Cast< Array< ::hxDragonBones::Bone > >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"display") ) { display=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"animation") ) { animation=inValue.Cast< ::hxDragonBones::animation::Animation >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"_rootBones") ) { _rootBones=inValue.Cast< Array< ::hxDragonBones::Bone > >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"colorTransform") ) { if (inCallProp) return set_colorTransform(inValue);colorTransform=inValue.Cast< ::native::geom::ColorTransform >(); return inValue; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"bonesIndexChanged") ) { bonesIndexChanged=inValue.Cast< bool >(); return inValue; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"colorTransformChange") ) { colorTransformChange=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Armature_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_rootBones"));
	outFields->push(HX_CSTRING("colorTransformChange"));
	outFields->push(HX_CSTRING("colorTransform"));
	outFields->push(HX_CSTRING("bonesIndexChanged"));
	outFields->push(HX_CSTRING("bones"));
	outFields->push(HX_CSTRING("animation"));
	outFields->push(HX_CSTRING("display"));
	outFields->push(HX_CSTRING("name"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("compareZ"),
	HX_CSTRING("removeFromBones"),
	HX_CSTRING("addToBones"),
	HX_CSTRING("updateBonesZ"),
	HX_CSTRING("update"),
	HX_CSTRING("advanceTime"),
	HX_CSTRING("removeBoneByName"),
	HX_CSTRING("removeBone"),
	HX_CSTRING("addBone"),
	HX_CSTRING("getBoneByDisplay"),
	HX_CSTRING("getBone"),
	HX_CSTRING("dispose"),
	HX_CSTRING("_rootBones"),
	HX_CSTRING("set_colorTransform"),
	HX_CSTRING("colorTransformChange"),
	HX_CSTRING("colorTransform"),
	HX_CSTRING("bonesIndexChanged"),
	HX_CSTRING("bones"),
	HX_CSTRING("animation"),
	HX_CSTRING("display"),
	HX_CSTRING("name"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Armature_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Armature_obj::__mClass,"__mClass");
};

Class Armature_obj::__mClass;

void Armature_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("hxDragonBones.Armature"), hx::TCanCast< Armature_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Armature_obj::__boot()
{
}

} // end namespace hxDragonBones
