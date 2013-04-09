#include <hxcpp.h>

#ifndef INCLUDED_Lambda
#include <Lambda.h>
#endif
#ifndef INCLUDED_hxMath
#include <hxMath.h>
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
#ifndef INCLUDED_hxDragonBones_animation_IAnimatable
#include <hxDragonBones/animation/IAnimatable.h>
#endif
#ifndef INCLUDED_hxDragonBones_animation_Tween
#include <hxDragonBones/animation/Tween.h>
#endif
#ifndef INCLUDED_hxDragonBones_display_IDisplayBridge
#include <hxDragonBones/display/IDisplayBridge.h>
#endif
#ifndef INCLUDED_hxDragonBones_objects_Node
#include <hxDragonBones/objects/Node.h>
#endif
#ifndef INCLUDED_hxDragonBones_utils_IDisposable
#include <hxDragonBones/utils/IDisposable.h>
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
#ifndef INCLUDED_native_geom_Matrix
#include <native/geom/Matrix.h>
#endif
#ifndef INCLUDED_native_geom_Point
#include <native/geom/Point.h>
#endif
namespace hxDragonBones{

Void Bone_obj::__construct(::hxDragonBones::display::IDisplayBridge bridge)
{
HX_STACK_PUSH("Bone::new","hxDragonBones/Bone.hx",18);
{
	HX_STACK_LINE(19)
	this->origin = ::hxDragonBones::objects::Node_obj::__new();
	HX_STACK_LINE(20)
	this->global = ::hxDragonBones::objects::Node_obj::__new();
	HX_STACK_LINE(21)
	this->node = ::hxDragonBones::objects::Node_obj::__new();
	HX_STACK_LINE(23)
	this->displayBridge = bridge;
	HX_STACK_LINE(25)
	this->children = Array_obj< ::hxDragonBones::Bone >::__new();
	HX_STACK_LINE(27)
	this->globalTransformMatrix = ::native::geom::Matrix_obj::__new(null(),null(),null(),null(),null(),null());
	HX_STACK_LINE(28)
	this->_displayList = Dynamic( Array_obj<Dynamic>::__new());
	HX_STACK_LINE(29)
	this->_displayIndex = (int)-1;
	HX_STACK_LINE(30)
	this->visible = true;
	HX_STACK_LINE(32)
	this->tweenNode = ::hxDragonBones::objects::Node_obj::__new();
	HX_STACK_LINE(33)
	this->tweenColorTransform = ::native::geom::ColorTransform_obj::__new(null(),null(),null(),null(),null(),null(),null(),null());
	HX_STACK_LINE(35)
	this->tween = ::hxDragonBones::animation::Tween_obj::__new(hx::ObjectPtr<OBJ_>(this));
	HX_STACK_LINE(36)
	this->isOnStage = false;
}
;
	return null();
}

Bone_obj::~Bone_obj() { }

Dynamic Bone_obj::__CreateEmpty() { return  new Bone_obj; }
hx::ObjectPtr< Bone_obj > Bone_obj::__new(::hxDragonBones::display::IDisplayBridge bridge)
{  hx::ObjectPtr< Bone_obj > result = new Bone_obj();
	result->__construct(bridge);
	return result;}

Dynamic Bone_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Bone_obj > result = new Bone_obj();
	result->__construct(inArgs[0]);
	return result;}

hx::Object *Bone_obj::__ToInterface(const type_info &inType) {
	if (inType==typeid( ::hxDragonBones::utils::IDisposable_obj)) return operator ::hxDragonBones::utils::IDisposable_obj *();
	return super::__ToInterface(inType);
}

Void Bone_obj::setParent( ::hxDragonBones::Bone parent){
{
		HX_STACK_PUSH("Bone::setParent","hxDragonBones/Bone.hx",227);
		HX_STACK_THIS(this);
		HX_STACK_ARG(parent,"parent");
		HX_STACK_LINE(228)
		if (((bool((parent != null())) && bool(parent->contains(hx::ObjectPtr<OBJ_>(this),true))))){
			HX_STACK_LINE(228)
			hx::Throw (HX_CSTRING("An Bone cannot be added as a child to itself or one of its children (or children's children, etc.)"));
		}
		HX_STACK_LINE(231)
		this->parent = parent;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Bone_obj,setParent,(void))

::native::geom::ColorTransform Bone_obj::getColorTransform( ){
	HX_STACK_PUSH("Bone::getColorTransform","hxDragonBones/Bone.hx",211);
	HX_STACK_THIS(this);
	HX_STACK_LINE(212)
	if ((this->tween->differentColorTransform)){
		HX_STACK_LINE(213)
		if (((this->armature->colorTransform != null()))){
			HX_STACK_LINE(213)
			this->tweenColorTransform->concat(this->armature->colorTransform);
		}
		HX_STACK_LINE(216)
		return this->tweenColorTransform;
	}
	HX_STACK_LINE(219)
	if ((this->armature->colorTransformChange)){
		HX_STACK_LINE(220)
		this->armature->colorTransformChange = false;
		HX_STACK_LINE(221)
		return this->armature->colorTransform;
	}
	HX_STACK_LINE(224)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Bone_obj,getColorTransform,return )

Void Bone_obj::update( ){
{
		HX_STACK_PUSH("Bone::update","hxDragonBones/Bone.hx",170);
		HX_STACK_THIS(this);
		HX_STACK_LINE(170)
		if (((bool((this->children->length > (int)0)) || bool(this->isOnStage)))){
			HX_STACK_LINE(172)
			this->global->x = ((this->origin->x + this->node->x) + this->tweenNode->x);
			HX_STACK_LINE(173)
			this->global->y = ((this->origin->y + this->node->y) + this->tweenNode->y);
			HX_STACK_LINE(174)
			this->global->z = ((this->origin->z + this->node->z) + this->tweenNode->z);
			HX_STACK_LINE(175)
			this->global->skewX = ((this->origin->skewX + this->node->skewX) + this->tweenNode->skewX);
			HX_STACK_LINE(176)
			this->global->skewY = ((this->origin->skewY + this->node->skewY) + this->tweenNode->skewY);
			HX_STACK_LINE(177)
			this->global->scaleX = ((this->origin->scaleX + this->node->scaleX) + this->tweenNode->scaleX);
			HX_STACK_LINE(178)
			this->global->scaleY = ((this->origin->scaleY + this->node->scaleY) + this->tweenNode->scaleY);
			HX_STACK_LINE(179)
			this->global->pivotX = ((this->origin->pivotX + this->node->pivotX) + this->tweenNode->pivotX);
			HX_STACK_LINE(180)
			this->global->pivotY = ((this->origin->pivotY + this->node->pivotY) + this->tweenNode->pivotY);
			HX_STACK_LINE(182)
			if (((this->parent != null()))){
				HX_STACK_LINE(183)
				::hxDragonBones::Bone_obj::_helpPoint->x = this->global->x;
				HX_STACK_LINE(184)
				::hxDragonBones::Bone_obj::_helpPoint->y = this->global->y;
				HX_STACK_LINE(185)
				::hxDragonBones::Bone_obj::_helpPoint = this->parent->globalTransformMatrix->transformPoint(::hxDragonBones::Bone_obj::_helpPoint);
				HX_STACK_LINE(186)
				this->global->x = ::hxDragonBones::Bone_obj::_helpPoint->x;
				HX_STACK_LINE(187)
				this->global->y = ::hxDragonBones::Bone_obj::_helpPoint->y;
				HX_STACK_LINE(188)
				hx::AddEq(this->global->skewX,this->parent->global->skewX);
				HX_STACK_LINE(189)
				hx::AddEq(this->global->skewY,this->parent->global->skewY);
			}
			HX_STACK_LINE(192)
			this->globalTransformMatrix->identity();
			HX_STACK_LINE(193)
			this->globalTransformMatrix->rotate(this->global->skewX);
			HX_STACK_LINE(194)
			this->globalTransformMatrix->scale(this->global->scaleX,this->global->scaleY);
			HX_STACK_LINE(195)
			this->globalTransformMatrix->translate(this->global->x,this->global->y);
			HX_STACK_LINE(201)
			if (((this->get_childArmature() != null()))){
				HX_STACK_LINE(201)
				this->get_childArmature()->update();
			}
			HX_STACK_LINE(205)
			if (((bool(this->isOnStage) && bool((this->displayBridge->__Field(HX_CSTRING("display"),true) != null()))))){
				HX_STACK_LINE(205)
				this->displayBridge->update(this->globalTransformMatrix,this->global,this->getColorTransform(),this->visible);
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Bone_obj,update,(void))

Void Bone_obj::removeFromParent( ){
{
		HX_STACK_PUSH("Bone::removeFromParent","hxDragonBones/Bone.hx",164);
		HX_STACK_THIS(this);
		HX_STACK_LINE(164)
		if (((this->parent != null()))){
			HX_STACK_LINE(165)
			this->parent->removeChild(hx::ObjectPtr<OBJ_>(this));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Bone_obj,removeFromParent,(void))

Void Bone_obj::removeChild( ::hxDragonBones::Bone child){
{
		HX_STACK_PUSH("Bone::removeChild","hxDragonBones/Bone.hx",154);
		HX_STACK_THIS(this);
		HX_STACK_ARG(child,"child");
		HX_STACK_LINE(154)
		if ((::Lambda_obj::has(this->children,child,null()))){
			HX_STACK_LINE(156)
			if (((this->armature != null()))){
				HX_STACK_LINE(156)
				this->armature->removeFromBones(child);
			}
			HX_STACK_LINE(159)
			child->setParent(null());
			HX_STACK_LINE(160)
			this->children->remove(child);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Bone_obj,removeChild,(void))

Void Bone_obj::addChild( ::hxDragonBones::Bone child){
{
		HX_STACK_PUSH("Bone::addChild","hxDragonBones/Bone.hx",141);
		HX_STACK_THIS(this);
		HX_STACK_ARG(child,"child");
		HX_STACK_LINE(141)
		if ((!(::Lambda_obj::has(this->children,child,null())))){
			HX_STACK_LINE(143)
			child->removeFromParent();
			HX_STACK_LINE(145)
			this->children->push(child);
			HX_STACK_LINE(146)
			child->setParent(hx::ObjectPtr<OBJ_>(this));
			HX_STACK_LINE(148)
			if (((this->armature != null()))){
				HX_STACK_LINE(148)
				this->armature->addToBones(child,null());
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Bone_obj,addChild,(void))

bool Bone_obj::contains( ::hxDragonBones::Bone bone,Dynamic deepLevel){
	HX_STACK_PUSH("Bone::contains","hxDragonBones/Bone.hx",127);
	HX_STACK_THIS(this);
	HX_STACK_ARG(bone,"bone");
	HX_STACK_ARG(deepLevel,"deepLevel");
	HX_STACK_LINE(128)
	if ((deepLevel)){
		HX_STACK_LINE(129)
		::hxDragonBones::Bone ancestor = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(ancestor,"ancestor");
		HX_STACK_LINE(130)
		while(((bool((ancestor != bone)) && bool((ancestor != null()))))){
			HX_STACK_LINE(130)
			ancestor = ancestor->parent;
		}
		HX_STACK_LINE(133)
		if (((ancestor == bone))){
			HX_STACK_LINE(133)
			return true;
		}
		HX_STACK_LINE(136)
		return false;
	}
	HX_STACK_LINE(138)
	return (bone->parent == hx::ObjectPtr<OBJ_>(this));
}


HX_DEFINE_DYNAMIC_FUNC2(Bone_obj,contains,return )

Void Bone_obj::dispose( ){
{
		HX_STACK_PUSH("Bone::dispose","hxDragonBones/Bone.hx",116);
		HX_STACK_THIS(this);
		HX_STACK_LINE(117)
		{
			HX_STACK_LINE(117)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			Array< ::hxDragonBones::Bone > _g1 = this->children;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(117)
			while(((_g < _g1->length))){
				HX_STACK_LINE(117)
				::hxDragonBones::Bone i = _g1->__get(_g);		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(117)
				++(_g);
				HX_STACK_LINE(118)
				i->dispose();
			}
		}
		HX_STACK_LINE(120)
		this->_displayList = null();
		HX_STACK_LINE(121)
		this->children = null();
		HX_STACK_LINE(122)
		this->armature = null();
		HX_STACK_LINE(123)
		this->parent = null();
		HX_STACK_LINE(124)
		this->userData = null();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Bone_obj,dispose,(void))

Void Bone_obj::changeDisplayList( Dynamic list){
{
		HX_STACK_PUSH("Bone::changeDisplayList","hxDragonBones/Bone.hx",106);
		HX_STACK_THIS(this);
		HX_STACK_ARG(list,"list");
		HX_STACK_LINE(107)
		int indexBackup = this->_displayIndex;		HX_STACK_VAR(indexBackup,"indexBackup");
		HX_STACK_LINE(108)
		int length = ::Std_obj::_int(::Math_obj::min(this->_displayList->__Field(HX_CSTRING("length"),true),list->__Field(HX_CSTRING("length"),true)));		HX_STACK_VAR(length,"length");
		HX_STACK_LINE(109)
		{
			HX_STACK_LINE(109)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(109)
			while(((_g < length))){
				HX_STACK_LINE(109)
				int i = (_g)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(110)
				this->changeDisplay(i);
				HX_STACK_LINE(111)
				this->set_display(list->__GetItem(i));
			}
		}
		HX_STACK_LINE(113)
		this->changeDisplay(indexBackup);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Bone_obj,changeDisplayList,(void))

Void Bone_obj::changeDisplay( int displayIndex){
{
		HX_STACK_PUSH("Bone::changeDisplay","hxDragonBones/Bone.hx",81);
		HX_STACK_THIS(this);
		HX_STACK_ARG(displayIndex,"displayIndex");
		HX_STACK_LINE(81)
		if (((displayIndex < (int)0))){
			HX_STACK_LINE(82)
			if ((this->isOnStage)){
				HX_STACK_LINE(84)
				this->isOnStage = false;
				HX_STACK_LINE(85)
				this->displayBridge->removeDisplayFromParent();
			}
		}
		else{
			HX_STACK_LINE(88)
			if ((!(this->isOnStage))){
				HX_STACK_LINE(89)
				this->isOnStage = true;
				HX_STACK_LINE(90)
				if (((this->armature != null()))){
					HX_STACK_LINE(91)
					this->displayBridge->addDisplayTo(this->armature->display,::Std_obj::_int(this->global->z));
					HX_STACK_LINE(92)
					this->armature->bonesIndexChanged = true;
				}
			}
			HX_STACK_LINE(95)
			if (((displayIndex != this->_displayIndex))){
				HX_STACK_LINE(96)
				int length = this->_displayList->__Field(HX_CSTRING("length"),true);		HX_STACK_VAR(length,"length");
				HX_STACK_LINE(97)
				if (((bool((displayIndex >= length)) && bool((length > (int)0))))){
					HX_STACK_LINE(97)
					displayIndex = (length - (int)1);
				}
				HX_STACK_LINE(100)
				this->_displayIndex = displayIndex;
				HX_STACK_LINE(101)
				this->set_display(this->_displayList->__GetItem(this->_displayIndex));
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Bone_obj,changeDisplay,(void))

Dynamic Bone_obj::set_display( Dynamic value){
	HX_STACK_PUSH("Bone::set_display","hxDragonBones/Bone.hx",69);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(70)
	if (((value == this->displayBridge->__Field(HX_CSTRING("display"),true)))){
		HX_STACK_LINE(70)
		return null();
	}
	HX_STACK_LINE(73)
	hx::IndexRef((this->_displayList).mPtr,this->_displayIndex) = value;
	HX_STACK_LINE(74)
	if ((::Std_obj::is(value,hx::ClassOf< ::hxDragonBones::Armature >()))){
		HX_STACK_LINE(74)
		value = (hx::TCast< hxDragonBones::Armature >::cast(value))->display;
	}
	HX_STACK_LINE(77)
	this->displayBridge->__Field(HX_CSTRING("set_display"),true)(value);
	HX_STACK_LINE(78)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(Bone_obj,set_display,return )

Dynamic Bone_obj::get_display( ){
	HX_STACK_PUSH("Bone::get_display","hxDragonBones/Bone.hx",65);
	HX_STACK_THIS(this);
	HX_STACK_LINE(65)
	return this->displayBridge->__Field(HX_CSTRING("display"),true);
}


HX_DEFINE_DYNAMIC_FUNC0(Bone_obj,get_display,return )

::hxDragonBones::Armature Bone_obj::get_childArmature( ){
	HX_STACK_PUSH("Bone::get_childArmature","hxDragonBones/Bone.hx",60);
	HX_STACK_THIS(this);
	HX_STACK_LINE(61)
	Dynamic d = this->_displayList->__GetItem(this->_displayIndex);		HX_STACK_VAR(d,"d");
	HX_STACK_LINE(62)
	return (  ((::Std_obj::is(d,hx::ClassOf< ::hxDragonBones::Armature >()))) ? ::hxDragonBones::Armature(hx::TCast< hxDragonBones::Armature >::cast(d)) : ::hxDragonBones::Armature(null()) );
}


HX_DEFINE_DYNAMIC_FUNC0(Bone_obj,get_childArmature,return )

::native::geom::Point Bone_obj::_helpPoint;


Bone_obj::Bone_obj()
{
}

void Bone_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Bone);
	HX_MARK_MEMBER_NAME(_displayIndex,"_displayIndex");
	HX_MARK_MEMBER_NAME(_displayList,"_displayList");
	HX_MARK_MEMBER_NAME(isOnStage,"isOnStage");
	HX_MARK_MEMBER_NAME(globalTransformMatrix,"globalTransformMatrix");
	HX_MARK_MEMBER_NAME(tween,"tween");
	HX_MARK_MEMBER_NAME(children,"children");
	HX_MARK_MEMBER_NAME(displayBridge,"displayBridge");
	HX_MARK_MEMBER_NAME(tweenColorTransform,"tweenColorTransform");
	HX_MARK_MEMBER_NAME(tweenNode,"tweenNode");
	HX_MARK_MEMBER_NAME(visible,"visible");
	HX_MARK_MEMBER_NAME(display,"display");
	HX_MARK_MEMBER_NAME(parent,"parent");
	HX_MARK_MEMBER_NAME(childArmature,"childArmature");
	HX_MARK_MEMBER_NAME(armature,"armature");
	HX_MARK_MEMBER_NAME(node,"node");
	HX_MARK_MEMBER_NAME(origin,"origin");
	HX_MARK_MEMBER_NAME(global,"global");
	HX_MARK_MEMBER_NAME(userData,"userData");
	HX_MARK_MEMBER_NAME(name,"name");
	HX_MARK_END_CLASS();
}

void Bone_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_displayIndex,"_displayIndex");
	HX_VISIT_MEMBER_NAME(_displayList,"_displayList");
	HX_VISIT_MEMBER_NAME(isOnStage,"isOnStage");
	HX_VISIT_MEMBER_NAME(globalTransformMatrix,"globalTransformMatrix");
	HX_VISIT_MEMBER_NAME(tween,"tween");
	HX_VISIT_MEMBER_NAME(children,"children");
	HX_VISIT_MEMBER_NAME(displayBridge,"displayBridge");
	HX_VISIT_MEMBER_NAME(tweenColorTransform,"tweenColorTransform");
	HX_VISIT_MEMBER_NAME(tweenNode,"tweenNode");
	HX_VISIT_MEMBER_NAME(visible,"visible");
	HX_VISIT_MEMBER_NAME(display,"display");
	HX_VISIT_MEMBER_NAME(parent,"parent");
	HX_VISIT_MEMBER_NAME(childArmature,"childArmature");
	HX_VISIT_MEMBER_NAME(armature,"armature");
	HX_VISIT_MEMBER_NAME(node,"node");
	HX_VISIT_MEMBER_NAME(origin,"origin");
	HX_VISIT_MEMBER_NAME(global,"global");
	HX_VISIT_MEMBER_NAME(userData,"userData");
	HX_VISIT_MEMBER_NAME(name,"name");
}

Dynamic Bone_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"node") ) { return node; }
		if (HX_FIELD_EQ(inName,"name") ) { return name; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"tween") ) { return tween; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		if (HX_FIELD_EQ(inName,"parent") ) { return parent; }
		if (HX_FIELD_EQ(inName,"origin") ) { return origin; }
		if (HX_FIELD_EQ(inName,"global") ) { return global; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"dispose") ) { return dispose_dyn(); }
		if (HX_FIELD_EQ(inName,"visible") ) { return visible; }
		if (HX_FIELD_EQ(inName,"display") ) { return inCallProp ? get_display() : display; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"addChild") ) { return addChild_dyn(); }
		if (HX_FIELD_EQ(inName,"contains") ) { return contains_dyn(); }
		if (HX_FIELD_EQ(inName,"children") ) { return children; }
		if (HX_FIELD_EQ(inName,"armature") ) { return armature; }
		if (HX_FIELD_EQ(inName,"userData") ) { return userData; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"setParent") ) { return setParent_dyn(); }
		if (HX_FIELD_EQ(inName,"isOnStage") ) { return isOnStage; }
		if (HX_FIELD_EQ(inName,"tweenNode") ) { return tweenNode; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"_helpPoint") ) { return _helpPoint; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"removeChild") ) { return removeChild_dyn(); }
		if (HX_FIELD_EQ(inName,"set_display") ) { return set_display_dyn(); }
		if (HX_FIELD_EQ(inName,"get_display") ) { return get_display_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"_displayList") ) { return _displayList; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"changeDisplay") ) { return changeDisplay_dyn(); }
		if (HX_FIELD_EQ(inName,"_displayIndex") ) { return _displayIndex; }
		if (HX_FIELD_EQ(inName,"displayBridge") ) { return displayBridge; }
		if (HX_FIELD_EQ(inName,"childArmature") ) { return inCallProp ? get_childArmature() : childArmature; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"removeFromParent") ) { return removeFromParent_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"getColorTransform") ) { return getColorTransform_dyn(); }
		if (HX_FIELD_EQ(inName,"changeDisplayList") ) { return changeDisplayList_dyn(); }
		if (HX_FIELD_EQ(inName,"get_childArmature") ) { return get_childArmature_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"tweenColorTransform") ) { return tweenColorTransform; }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"globalTransformMatrix") ) { return globalTransformMatrix; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Bone_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"node") ) { node=inValue.Cast< ::hxDragonBones::objects::Node >(); return inValue; }
		if (HX_FIELD_EQ(inName,"name") ) { name=inValue.Cast< ::String >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"tween") ) { tween=inValue.Cast< ::hxDragonBones::animation::Tween >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"parent") ) { parent=inValue.Cast< ::hxDragonBones::Bone >(); return inValue; }
		if (HX_FIELD_EQ(inName,"origin") ) { origin=inValue.Cast< ::hxDragonBones::objects::Node >(); return inValue; }
		if (HX_FIELD_EQ(inName,"global") ) { global=inValue.Cast< ::hxDragonBones::objects::Node >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"visible") ) { visible=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"display") ) { if (inCallProp) return set_display(inValue);display=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"children") ) { children=inValue.Cast< Array< ::hxDragonBones::Bone > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"armature") ) { armature=inValue.Cast< ::hxDragonBones::Armature >(); return inValue; }
		if (HX_FIELD_EQ(inName,"userData") ) { userData=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"isOnStage") ) { isOnStage=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"tweenNode") ) { tweenNode=inValue.Cast< ::hxDragonBones::objects::Node >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"_helpPoint") ) { _helpPoint=inValue.Cast< ::native::geom::Point >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"_displayList") ) { _displayList=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"_displayIndex") ) { _displayIndex=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"displayBridge") ) { displayBridge=inValue.Cast< ::hxDragonBones::display::IDisplayBridge >(); return inValue; }
		if (HX_FIELD_EQ(inName,"childArmature") ) { childArmature=inValue.Cast< ::hxDragonBones::Armature >(); return inValue; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"tweenColorTransform") ) { tweenColorTransform=inValue.Cast< ::native::geom::ColorTransform >(); return inValue; }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"globalTransformMatrix") ) { globalTransformMatrix=inValue.Cast< ::native::geom::Matrix >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Bone_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_displayIndex"));
	outFields->push(HX_CSTRING("_displayList"));
	outFields->push(HX_CSTRING("isOnStage"));
	outFields->push(HX_CSTRING("globalTransformMatrix"));
	outFields->push(HX_CSTRING("tween"));
	outFields->push(HX_CSTRING("children"));
	outFields->push(HX_CSTRING("displayBridge"));
	outFields->push(HX_CSTRING("tweenColorTransform"));
	outFields->push(HX_CSTRING("tweenNode"));
	outFields->push(HX_CSTRING("visible"));
	outFields->push(HX_CSTRING("display"));
	outFields->push(HX_CSTRING("parent"));
	outFields->push(HX_CSTRING("childArmature"));
	outFields->push(HX_CSTRING("armature"));
	outFields->push(HX_CSTRING("node"));
	outFields->push(HX_CSTRING("origin"));
	outFields->push(HX_CSTRING("global"));
	outFields->push(HX_CSTRING("userData"));
	outFields->push(HX_CSTRING("name"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("_helpPoint"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("setParent"),
	HX_CSTRING("getColorTransform"),
	HX_CSTRING("update"),
	HX_CSTRING("removeFromParent"),
	HX_CSTRING("removeChild"),
	HX_CSTRING("addChild"),
	HX_CSTRING("contains"),
	HX_CSTRING("dispose"),
	HX_CSTRING("changeDisplayList"),
	HX_CSTRING("changeDisplay"),
	HX_CSTRING("set_display"),
	HX_CSTRING("get_display"),
	HX_CSTRING("get_childArmature"),
	HX_CSTRING("_displayIndex"),
	HX_CSTRING("_displayList"),
	HX_CSTRING("isOnStage"),
	HX_CSTRING("globalTransformMatrix"),
	HX_CSTRING("tween"),
	HX_CSTRING("children"),
	HX_CSTRING("displayBridge"),
	HX_CSTRING("tweenColorTransform"),
	HX_CSTRING("tweenNode"),
	HX_CSTRING("visible"),
	HX_CSTRING("display"),
	HX_CSTRING("parent"),
	HX_CSTRING("childArmature"),
	HX_CSTRING("armature"),
	HX_CSTRING("node"),
	HX_CSTRING("origin"),
	HX_CSTRING("global"),
	HX_CSTRING("userData"),
	HX_CSTRING("name"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Bone_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(Bone_obj::_helpPoint,"_helpPoint");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Bone_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Bone_obj::_helpPoint,"_helpPoint");
};

Class Bone_obj::__mClass;

void Bone_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("hxDragonBones.Bone"), hx::TCanCast< Bone_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Bone_obj::__boot()
{
	_helpPoint= ::native::geom::Point_obj::__new(null(),null());
}

} // end namespace hxDragonBones
