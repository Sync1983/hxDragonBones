#include <hxcpp.h>

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
#ifndef INCLUDED_hxDragonBones_animation_Animation
#include <hxDragonBones/animation/Animation.h>
#endif
#ifndef INCLUDED_hxDragonBones_animation_IAnimatable
#include <hxDragonBones/animation/IAnimatable.h>
#endif
#ifndef INCLUDED_hxDragonBones_animation_Tween
#include <hxDragonBones/animation/Tween.h>
#endif
#ifndef INCLUDED_hxDragonBones_events_FrameEvent
#include <hxDragonBones/events/FrameEvent.h>
#endif
#ifndef INCLUDED_hxDragonBones_events_SoundEvent
#include <hxDragonBones/events/SoundEvent.h>
#endif
#ifndef INCLUDED_hxDragonBones_events_SoundEventManager
#include <hxDragonBones/events/SoundEventManager.h>
#endif
#ifndef INCLUDED_hxDragonBones_objects_FrameData
#include <hxDragonBones/objects/FrameData.h>
#endif
#ifndef INCLUDED_hxDragonBones_objects_MovementBoneData
#include <hxDragonBones/objects/MovementBoneData.h>
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
namespace animation{

Void Tween_obj::__construct(::hxDragonBones::Bone bone)
{
HX_STACK_PUSH("Tween::new","hxDragonBones/animation/Tween.hx",41);
{
	HX_STACK_LINE(42)
	this->_bone = bone;
	HX_STACK_LINE(43)
	this->_node = this->_bone->tweenNode;
	HX_STACK_LINE(44)
	this->_colorTransform = this->_bone->tweenColorTransform;
	HX_STACK_LINE(46)
	this->_curNode = ::hxDragonBones::objects::Node_obj::__new();
	HX_STACK_LINE(47)
	this->_curColorTransform = ::native::geom::ColorTransform_obj::__new(null(),null(),null(),null(),null(),null(),null(),null());
	HX_STACK_LINE(49)
	this->_offSetNode = ::hxDragonBones::objects::Node_obj::__new();
	HX_STACK_LINE(50)
	this->_offSetColorTransform = ::native::geom::ColorTransform_obj::__new(null(),null(),null(),null(),null(),null(),null(),null());
}
;
	return null();
}

Tween_obj::~Tween_obj() { }

Dynamic Tween_obj::__CreateEmpty() { return  new Tween_obj; }
hx::ObjectPtr< Tween_obj > Tween_obj::__new(::hxDragonBones::Bone bone)
{  hx::ObjectPtr< Tween_obj > result = new Tween_obj();
	result->__construct(bone);
	return result;}

Dynamic Tween_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Tween_obj > result = new Tween_obj();
	result->__construct(inArgs[0]);
	return result;}

Float Tween_obj::updateFrameData( Float progress,Dynamic activeFrame,Dynamic isList){
	HX_STACK_PUSH("Tween::updateFrameData","hxDragonBones/animation/Tween.hx",269);
	HX_STACK_THIS(this);
	HX_STACK_ARG(progress,"progress");
	HX_STACK_ARG(activeFrame,"activeFrame");
	HX_STACK_ARG(isList,"isList");
	HX_STACK_LINE(270)
	Float playedTime = (this->_rawDuration * progress);		HX_STACK_VAR(playedTime,"playedTime");
	HX_STACK_LINE(271)
	if (((playedTime >= this->_nextFrameDataTimeEdge))){
		HX_STACK_LINE(272)
		int curFrameDataID;		HX_STACK_VAR(curFrameDataID,"curFrameDataID");
		HX_STACK_LINE(273)
		do{
			HX_STACK_LINE(274)
			curFrameDataID = this->_nextFrameDataID;
			HX_STACK_LINE(275)
			this->_frameDuration = this->_movementBoneData->frameList->__get(curFrameDataID)->duration;
			HX_STACK_LINE(276)
			hx::AddEq(this->_nextFrameDataTimeEdge,this->_frameDuration);
			HX_STACK_LINE(277)
			if (((++(this->_nextFrameDataID) >= this->_movementBoneData->frameList->length))){
				HX_STACK_LINE(277)
				this->_nextFrameDataID = (int)0;
			}
		}
while(((playedTime >= this->_nextFrameDataTimeEdge)));
		HX_STACK_LINE(282)
		::hxDragonBones::objects::FrameData curFrameData = this->_movementBoneData->frameList->__get(curFrameDataID);		HX_STACK_VAR(curFrameData,"curFrameData");
		HX_STACK_LINE(283)
		::hxDragonBones::objects::FrameData nextFrameData = this->_movementBoneData->frameList->__get(this->_nextFrameDataID);		HX_STACK_VAR(nextFrameData,"nextFrameData");
		HX_STACK_LINE(285)
		if (((bool((nextFrameData->displayIndex >= (int)0)) && bool(this->_bone->armature->animation->tweenEnabled)))){
			HX_STACK_LINE(285)
			this->_frameTweenEasing = curFrameData->tweenEasing;
		}
		else{
			HX_STACK_LINE(287)
			this->_frameTweenEasing = ::Math_obj::NaN;
		}
		HX_STACK_LINE(291)
		this->setOffset(curFrameData->node,curFrameData->colorTransform,nextFrameData->node,nextFrameData->colorTransform,nextFrameData->tweenRotate);
		HX_STACK_LINE(293)
		if ((activeFrame)){
			HX_STACK_LINE(293)
			this->_curFrameData = curFrameData;
		}
		HX_STACK_LINE(297)
		if (((bool(isList) && bool((this->_nextFrameDataID == (int)0))))){
			HX_STACK_LINE(298)
			this->_isPause = true;
			HX_STACK_LINE(299)
			return (int)0;
		}
	}
	HX_STACK_LINE(303)
	progress = ((int)1 - (Float(((this->_nextFrameDataTimeEdge - playedTime))) / Float(this->_frameDuration)));
	HX_STACK_LINE(305)
	if ((!(::Math_obj::isNaN(this->_frameTweenEasing)))){
		HX_STACK_LINE(306)
		Float tweenEasing = (  ((::Math_obj::isNaN(this->_tweenEasing))) ? Float(this->_frameTweenEasing) : Float(this->_tweenEasing) );		HX_STACK_VAR(tweenEasing,"tweenEasing");
		HX_STACK_LINE(307)
		if (((tweenEasing != (int)0))){
			struct _Function_3_1{
				inline static Float Block( Float &progress,Float &tweenEasing){
					HX_STACK_PUSH("*::closure","hxDragonBones/animation/Tween.hx",308);
					{
						HX_STACK_LINE(308)
						Float value = progress;		HX_STACK_VAR(value,"value");
						Dynamic easing = tweenEasing;		HX_STACK_VAR(easing,"easing");
						HX_STACK_LINE(308)
						Float valueEase = (int)0;		HX_STACK_VAR(valueEase,"valueEase");
						HX_STACK_LINE(308)
						if ((::Math_obj::isNaN(easing))){
							HX_STACK_LINE(308)
							valueEase = (int)0;
							HX_STACK_LINE(308)
							easing = (int)0;
							HX_STACK_LINE(308)
							value = (int)0;
						}
						else{
							HX_STACK_LINE(308)
							if (((easing > (int)1))){
								HX_STACK_LINE(308)
								valueEase = ((0.5 * (((int)1 - ::Math_obj::cos((value * ::Math_obj::PI))))) - value);
								HX_STACK_LINE(308)
								hx::SubEq(easing,(int)1);
							}
							else{
								HX_STACK_LINE(308)
								if (((easing > (int)0))){
									HX_STACK_LINE(308)
									valueEase = (::Math_obj::sin((value * ((::Math_obj::PI * 0.5)))) - value);
								}
								else{
									HX_STACK_LINE(308)
									if (((easing < (int)0))){
										HX_STACK_LINE(308)
										valueEase = (((int)1 - ::Math_obj::cos((value * ((::Math_obj::PI * 0.5))))) - value);
										HX_STACK_LINE(308)
										hx::MultEq(easing,(int)-1);
									}
								}
							}
						}
						HX_STACK_LINE(308)
						return ((valueEase * easing) + value);
					}
					return null();
				}
			};
			HX_STACK_LINE(307)
			progress = _Function_3_1::Block(progress,tweenEasing);
		}
	}
	struct _Function_1_1{
		inline static Float Block( Float &progress,::hxDragonBones::animation::Tween_obj *__this){
			HX_STACK_PUSH("*::closure","hxDragonBones/animation/Tween.hx",311);
			{
				HX_STACK_LINE(311)
				Float value = progress;		HX_STACK_VAR(value,"value");
				Dynamic easing = __this->_frameTweenEasing;		HX_STACK_VAR(easing,"easing");
				HX_STACK_LINE(311)
				Float valueEase = (int)0;		HX_STACK_VAR(valueEase,"valueEase");
				HX_STACK_LINE(311)
				if ((::Math_obj::isNaN(easing))){
					HX_STACK_LINE(311)
					valueEase = (int)0;
					HX_STACK_LINE(311)
					easing = (int)0;
					HX_STACK_LINE(311)
					value = (int)0;
				}
				else{
					HX_STACK_LINE(311)
					if (((easing > (int)1))){
						HX_STACK_LINE(311)
						valueEase = ((0.5 * (((int)1 - ::Math_obj::cos((value * ::Math_obj::PI))))) - value);
						HX_STACK_LINE(311)
						hx::SubEq(easing,(int)1);
					}
					else{
						HX_STACK_LINE(311)
						if (((easing > (int)0))){
							HX_STACK_LINE(311)
							valueEase = (::Math_obj::sin((value * ((::Math_obj::PI * 0.5)))) - value);
						}
						else{
							HX_STACK_LINE(311)
							if (((easing < (int)0))){
								HX_STACK_LINE(311)
								valueEase = (((int)1 - ::Math_obj::cos((value * ((::Math_obj::PI * 0.5))))) - value);
								HX_STACK_LINE(311)
								hx::MultEq(easing,(int)-1);
							}
						}
					}
				}
				HX_STACK_LINE(311)
				return ((valueEase * easing) + value);
			}
			return null();
		}
	};
	HX_STACK_LINE(311)
	return _Function_1_1::Block(progress,this);
}


HX_DEFINE_DYNAMIC_FUNC3(Tween_obj,updateFrameData,return )

Void Tween_obj::arriveFrameData( ::hxDragonBones::objects::FrameData frameData){
{
		HX_STACK_PUSH("Tween::arriveFrameData","hxDragonBones/animation/Tween.hx",244);
		HX_STACK_THIS(this);
		HX_STACK_ARG(frameData,"frameData");
		HX_STACK_LINE(245)
		this->updateBoneDisplayIndex(frameData);
		HX_STACK_LINE(246)
		this->_bone->visible = frameData->visible;
		HX_STACK_LINE(248)
		if (((bool((frameData->event != null())) && bool(this->_bone->armature->hasEventListener(HX_CSTRING("boneFrameEvent")))))){
			HX_STACK_LINE(249)
			::hxDragonBones::events::FrameEvent frameEvent = ::hxDragonBones::events::FrameEvent_obj::__new(HX_CSTRING("boneFrameEvent"),false,null(),this->_bone);		HX_STACK_VAR(frameEvent,"frameEvent");
			HX_STACK_LINE(250)
			frameEvent->movementID = this->_bone->armature->animation->movementID;
			HX_STACK_LINE(251)
			frameEvent->frameLabel = frameData->event;
			HX_STACK_LINE(252)
			this->_bone->armature->dispatchEvent(frameEvent);
		}
		HX_STACK_LINE(255)
		if (((bool((frameData->sound != null())) && bool(::hxDragonBones::animation::Tween_obj::_soundManager->hasEventListener(HX_CSTRING("sound")))))){
			HX_STACK_LINE(256)
			::hxDragonBones::events::SoundEvent soundEvent = ::hxDragonBones::events::SoundEvent_obj::__new(HX_CSTRING("sound"),null());		HX_STACK_VAR(soundEvent,"soundEvent");
			HX_STACK_LINE(257)
			soundEvent->movementID = this->_bone->armature->animation->movementID;
			HX_STACK_LINE(258)
			soundEvent->sound = frameData->sound;
			HX_STACK_LINE(259)
			soundEvent->armature = this->_bone->armature;
			HX_STACK_LINE(260)
			soundEvent->bone = this->_bone;
			HX_STACK_LINE(261)
			::hxDragonBones::animation::Tween_obj::_soundManager->dispatchEvent(soundEvent);
		}
		HX_STACK_LINE(264)
		if (((bool((frameData->movement != null())) && bool((this->_bone->get_childArmature() != null()))))){
			HX_STACK_LINE(264)
			this->_bone->get_childArmature()->animation->gotoAndPlay(frameData->movement,null(),null(),null());
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Tween_obj,arriveFrameData,(void))

Void Tween_obj::updateBoneDisplayIndex( ::hxDragonBones::objects::FrameData frameData){
{
		HX_STACK_PUSH("Tween::updateBoneDisplayIndex","hxDragonBones/animation/Tween.hx",232);
		HX_STACK_THIS(this);
		HX_STACK_ARG(frameData,"frameData");
		HX_STACK_LINE(233)
		if (((frameData->displayIndex >= (int)0))){
			HX_STACK_LINE(233)
			if (((this->_node->z != frameData->node->z))){
				HX_STACK_LINE(235)
				this->_node->z = frameData->node->z;
				HX_STACK_LINE(236)
				if (((this->_bone->armature != null()))){
					HX_STACK_LINE(236)
					this->_bone->armature->bonesIndexChanged = true;
				}
			}
		}
		HX_STACK_LINE(241)
		this->_bone->changeDisplay(frameData->displayIndex);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Tween_obj,updateBoneDisplayIndex,(void))

Void Tween_obj::setOffset( ::hxDragonBones::objects::Node currentNode,::native::geom::ColorTransform curColorTransform,::hxDragonBones::objects::Node nextNode,::native::geom::ColorTransform nextColorTransform,hx::Null< int >  __o_tweenRotate){
int tweenRotate = __o_tweenRotate.Default(0);
	HX_STACK_PUSH("Tween::setOffset","hxDragonBones/animation/Tween.hx",201);
	HX_STACK_THIS(this);
	HX_STACK_ARG(currentNode,"currentNode");
	HX_STACK_ARG(curColorTransform,"curColorTransform");
	HX_STACK_ARG(nextNode,"nextNode");
	HX_STACK_ARG(nextColorTransform,"nextColorTransform");
	HX_STACK_ARG(tweenRotate,"tweenRotate");
{
		HX_STACK_LINE(202)
		this->_curNode->copyFrom(currentNode);
		HX_STACK_LINE(203)
		{
			HX_STACK_LINE(203)
			::hxDragonBones::objects::Node from = this->_curNode;		HX_STACK_VAR(from,"from");
			::hxDragonBones::objects::Node offSet = this->_offSetNode;		HX_STACK_VAR(offSet,"offSet");
			HX_STACK_LINE(203)
			offSet->x = (nextNode->x - from->x);
			HX_STACK_LINE(203)
			offSet->y = (nextNode->y - from->y);
			HX_STACK_LINE(203)
			offSet->skewX = (nextNode->skewX - from->skewX);
			HX_STACK_LINE(203)
			offSet->skewY = (nextNode->skewY - from->skewY);
			HX_STACK_LINE(203)
			offSet->scaleX = (nextNode->scaleX - from->scaleX);
			HX_STACK_LINE(203)
			offSet->scaleY = (nextNode->scaleY - from->scaleY);
			HX_STACK_LINE(203)
			offSet->pivotX = (nextNode->pivotX - from->pivotX);
			HX_STACK_LINE(203)
			offSet->pivotY = (nextNode->pivotY - from->pivotY);
			HX_STACK_LINE(203)
			hx::ModEq(offSet->skewX,(::Math_obj::PI * (int)2));
			HX_STACK_LINE(203)
			if (((offSet->skewX > ::Math_obj::PI))){
				HX_STACK_LINE(203)
				hx::SubEq(offSet->skewX,(::Math_obj::PI * (int)2));
			}
			HX_STACK_LINE(203)
			if (((offSet->skewX < -(::Math_obj::PI)))){
				HX_STACK_LINE(203)
				hx::AddEq(offSet->skewX,(::Math_obj::PI * (int)2));
			}
			HX_STACK_LINE(203)
			hx::ModEq(offSet->skewY,(::Math_obj::PI * (int)2));
			HX_STACK_LINE(203)
			if (((offSet->skewY > ::Math_obj::PI))){
				HX_STACK_LINE(203)
				hx::SubEq(offSet->skewY,(::Math_obj::PI * (int)2));
			}
			HX_STACK_LINE(203)
			if (((offSet->skewY < -(::Math_obj::PI)))){
				HX_STACK_LINE(203)
				hx::AddEq(offSet->skewY,(::Math_obj::PI * (int)2));
			}
			HX_STACK_LINE(203)
			if (((tweenRotate != (int)0))){
				HX_STACK_LINE(203)
				Float value = (tweenRotate * ((::Math_obj::PI * (int)2)));		HX_STACK_VAR(value,"value");
				HX_STACK_LINE(203)
				hx::AddEq(offSet->skewX,value);
				HX_STACK_LINE(203)
				hx::AddEq(offSet->skewY,value);
			}
		}
		HX_STACK_LINE(205)
		this->_curColorTransform->alphaOffset = curColorTransform->alphaOffset;
		HX_STACK_LINE(206)
		this->_curColorTransform->redOffset = curColorTransform->redOffset;
		HX_STACK_LINE(207)
		this->_curColorTransform->greenOffset = curColorTransform->greenOffset;
		HX_STACK_LINE(208)
		this->_curColorTransform->blueOffset = curColorTransform->blueOffset;
		HX_STACK_LINE(209)
		this->_curColorTransform->alphaMultiplier = curColorTransform->alphaMultiplier;
		HX_STACK_LINE(210)
		this->_curColorTransform->redMultiplier = curColorTransform->redMultiplier;
		HX_STACK_LINE(211)
		this->_curColorTransform->greenMultiplier = curColorTransform->greenMultiplier;
		HX_STACK_LINE(212)
		this->_curColorTransform->blueMultiplier = curColorTransform->blueMultiplier;
		HX_STACK_LINE(214)
		{
			HX_STACK_LINE(214)
			::native::geom::ColorTransform from = this->_curColorTransform;		HX_STACK_VAR(from,"from");
			::native::geom::ColorTransform offset = this->_offSetColorTransform;		HX_STACK_VAR(offset,"offset");
			HX_STACK_LINE(214)
			offset->alphaOffset = (nextColorTransform->alphaOffset - from->alphaOffset);
			HX_STACK_LINE(214)
			offset->redOffset = (nextColorTransform->redOffset - from->redOffset);
			HX_STACK_LINE(214)
			offset->greenOffset = (nextColorTransform->greenOffset - from->greenOffset);
			HX_STACK_LINE(214)
			offset->blueOffset = (nextColorTransform->blueOffset - from->blueOffset);
			HX_STACK_LINE(214)
			offset->alphaMultiplier = (nextColorTransform->alphaMultiplier - from->alphaMultiplier);
			HX_STACK_LINE(214)
			offset->redMultiplier = (nextColorTransform->redMultiplier - from->redMultiplier);
			HX_STACK_LINE(214)
			offset->greenMultiplier = (nextColorTransform->greenMultiplier - from->greenMultiplier);
			HX_STACK_LINE(214)
			offset->blueMultiplier = (nextColorTransform->blueMultiplier - from->blueMultiplier);
		}
		HX_STACK_LINE(216)
		if (((bool((bool((bool((bool((bool((bool((bool((this->_offSetColorTransform->alphaOffset != (int)0)) || bool((this->_offSetColorTransform->redOffset != (int)0)))) || bool((this->_offSetColorTransform->greenOffset != (int)0)))) || bool((this->_offSetColorTransform->blueOffset != (int)0)))) || bool((this->_offSetColorTransform->alphaMultiplier != (int)0)))) || bool((this->_offSetColorTransform->redMultiplier != (int)0)))) || bool((this->_offSetColorTransform->greenMultiplier != (int)0)))) || bool((this->_offSetColorTransform->blueMultiplier != (int)0))))){
			HX_STACK_LINE(225)
			this->differentColorTransform = true;
		}
		else{
			HX_STACK_LINE(227)
			this->differentColorTransform = false;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC5(Tween_obj,setOffset,(void))

Void Tween_obj::getLoopListNode( ){
{
		HX_STACK_PUSH("Tween::getLoopListNode","hxDragonBones/animation/Tween.hx",166);
		HX_STACK_THIS(this);
		HX_STACK_LINE(167)
		Float playedTime = (this->_rawDuration * this->_movementBoneData->delay);		HX_STACK_VAR(playedTime,"playedTime");
		HX_STACK_LINE(168)
		int length = this->_movementBoneData->frameList->length;		HX_STACK_VAR(length,"length");
		HX_STACK_LINE(169)
		int nextFrameDataID = (int)0;		HX_STACK_VAR(nextFrameDataID,"nextFrameDataID");
		HX_STACK_LINE(170)
		Float nextFrameDataTimeEdge = (int)0;		HX_STACK_VAR(nextFrameDataTimeEdge,"nextFrameDataTimeEdge");
		HX_STACK_LINE(171)
		int curFrameDataID;		HX_STACK_VAR(curFrameDataID,"curFrameDataID");
		HX_STACK_LINE(172)
		Float frameDuration;		HX_STACK_VAR(frameDuration,"frameDuration");
		HX_STACK_LINE(173)
		do{
			HX_STACK_LINE(174)
			curFrameDataID = nextFrameDataID;
			HX_STACK_LINE(175)
			frameDuration = this->_movementBoneData->frameList->__get(curFrameDataID)->duration;
			HX_STACK_LINE(176)
			hx::AddEq(nextFrameDataTimeEdge,frameDuration);
			HX_STACK_LINE(177)
			if (((++(nextFrameDataID) >= length))){
				HX_STACK_LINE(177)
				nextFrameDataID = (int)0;
			}
		}
while(((playedTime >= nextFrameDataTimeEdge)));
		HX_STACK_LINE(182)
		::hxDragonBones::objects::FrameData currentFrameData = this->_movementBoneData->frameList->__get(curFrameDataID);		HX_STACK_VAR(currentFrameData,"currentFrameData");
		HX_STACK_LINE(183)
		::hxDragonBones::objects::FrameData nextFrameData = this->_movementBoneData->frameList->__get(nextFrameDataID);		HX_STACK_VAR(nextFrameData,"nextFrameData");
		HX_STACK_LINE(185)
		this->setOffset(currentFrameData->node,currentFrameData->colorTransform,nextFrameData->node,nextFrameData->colorTransform,null());
		HX_STACK_LINE(187)
		Float progress = ((int)1 - (Float(((nextFrameDataTimeEdge - playedTime))) / Float(frameDuration)));		HX_STACK_VAR(progress,"progress");
		HX_STACK_LINE(189)
		Float tweenEasing = (  ((::Math_obj::isNaN(this->_tweenEasing))) ? Float(currentFrameData->tweenEasing) : Float(this->_tweenEasing) );		HX_STACK_VAR(tweenEasing,"tweenEasing");
		HX_STACK_LINE(190)
		if (((tweenEasing != (int)0))){
			struct _Function_2_1{
				inline static Float Block( Float &progress,Float &tweenEasing){
					HX_STACK_PUSH("*::closure","hxDragonBones/animation/Tween.hx",191);
					{
						HX_STACK_LINE(191)
						Float value = progress;		HX_STACK_VAR(value,"value");
						Dynamic easing = tweenEasing;		HX_STACK_VAR(easing,"easing");
						HX_STACK_LINE(191)
						Float valueEase = (int)0;		HX_STACK_VAR(valueEase,"valueEase");
						HX_STACK_LINE(191)
						if ((::Math_obj::isNaN(easing))){
							HX_STACK_LINE(191)
							valueEase = (int)0;
							HX_STACK_LINE(191)
							easing = (int)0;
							HX_STACK_LINE(191)
							value = (int)0;
						}
						else{
							HX_STACK_LINE(191)
							if (((easing > (int)1))){
								HX_STACK_LINE(191)
								valueEase = ((0.5 * (((int)1 - ::Math_obj::cos((value * ::Math_obj::PI))))) - value);
								HX_STACK_LINE(191)
								hx::SubEq(easing,(int)1);
							}
							else{
								HX_STACK_LINE(191)
								if (((easing > (int)0))){
									HX_STACK_LINE(191)
									valueEase = (::Math_obj::sin((value * ((::Math_obj::PI * 0.5)))) - value);
								}
								else{
									HX_STACK_LINE(191)
									if (((easing < (int)0))){
										HX_STACK_LINE(191)
										valueEase = (((int)1 - ::Math_obj::cos((value * ((::Math_obj::PI * 0.5))))) - value);
										HX_STACK_LINE(191)
										hx::MultEq(easing,(int)-1);
									}
								}
							}
						}
						HX_STACK_LINE(191)
						return ((valueEase * easing) + value);
					}
					return null();
				}
			};
			HX_STACK_LINE(190)
			progress = _Function_2_1::Block(progress,tweenEasing);
		}
		HX_STACK_LINE(194)
		{
			HX_STACK_LINE(194)
			::hxDragonBones::objects::Node from = currentFrameData->node;		HX_STACK_VAR(from,"from");
			::hxDragonBones::objects::Node to = nextFrameData->node;		HX_STACK_VAR(to,"to");
			::hxDragonBones::objects::Node offSet = this->_offSetNode;		HX_STACK_VAR(offSet,"offSet");
			int tweenRotate = (int)0;		HX_STACK_VAR(tweenRotate,"tweenRotate");
			HX_STACK_LINE(194)
			offSet->x = (to->x - from->x);
			HX_STACK_LINE(194)
			offSet->y = (to->y - from->y);
			HX_STACK_LINE(194)
			offSet->skewX = (to->skewX - from->skewX);
			HX_STACK_LINE(194)
			offSet->skewY = (to->skewY - from->skewY);
			HX_STACK_LINE(194)
			offSet->scaleX = (to->scaleX - from->scaleX);
			HX_STACK_LINE(194)
			offSet->scaleY = (to->scaleY - from->scaleY);
			HX_STACK_LINE(194)
			offSet->pivotX = (to->pivotX - from->pivotX);
			HX_STACK_LINE(194)
			offSet->pivotY = (to->pivotY - from->pivotY);
			HX_STACK_LINE(194)
			hx::ModEq(offSet->skewX,(::Math_obj::PI * (int)2));
			HX_STACK_LINE(194)
			if (((offSet->skewX > ::Math_obj::PI))){
				HX_STACK_LINE(194)
				hx::SubEq(offSet->skewX,(::Math_obj::PI * (int)2));
			}
			HX_STACK_LINE(194)
			if (((offSet->skewX < -(::Math_obj::PI)))){
				HX_STACK_LINE(194)
				hx::AddEq(offSet->skewX,(::Math_obj::PI * (int)2));
			}
			HX_STACK_LINE(194)
			hx::ModEq(offSet->skewY,(::Math_obj::PI * (int)2));
			HX_STACK_LINE(194)
			if (((offSet->skewY > ::Math_obj::PI))){
				HX_STACK_LINE(194)
				hx::SubEq(offSet->skewY,(::Math_obj::PI * (int)2));
			}
			HX_STACK_LINE(194)
			if (((offSet->skewY < -(::Math_obj::PI)))){
				HX_STACK_LINE(194)
				hx::AddEq(offSet->skewY,(::Math_obj::PI * (int)2));
			}
			HX_STACK_LINE(194)
			if (((tweenRotate != (int)0))){
				HX_STACK_LINE(194)
				Float value = (tweenRotate * ((::Math_obj::PI * (int)2)));		HX_STACK_VAR(value,"value");
				HX_STACK_LINE(194)
				hx::AddEq(offSet->skewX,value);
				HX_STACK_LINE(194)
				hx::AddEq(offSet->skewY,value);
			}
		}
		HX_STACK_LINE(195)
		{
			HX_STACK_LINE(195)
			::hxDragonBones::objects::Node current = this->_curNode;		HX_STACK_VAR(current,"current");
			::hxDragonBones::objects::Node offSet = this->_offSetNode;		HX_STACK_VAR(offSet,"offSet");
			::hxDragonBones::objects::Node tween = this->_offSetNode;		HX_STACK_VAR(tween,"tween");
			HX_STACK_LINE(195)
			tween->setValues((current->x + (progress * offSet->x)),(current->y + (progress * offSet->y)),(current->skewX + (progress * offSet->skewX)),(current->skewY + (progress * offSet->skewY)),(current->scaleX + (progress * offSet->scaleX)),(current->scaleY + (progress * offSet->scaleY)),(current->pivotX + (progress * offSet->pivotX)),(current->pivotY + (progress * offSet->pivotY)),::Std_obj::_int(tween->z));
		}
		HX_STACK_LINE(197)
		{
			HX_STACK_LINE(197)
			::native::geom::ColorTransform from = currentFrameData->colorTransform;		HX_STACK_VAR(from,"from");
			::native::geom::ColorTransform to = nextFrameData->colorTransform;		HX_STACK_VAR(to,"to");
			::native::geom::ColorTransform offset = this->_offSetColorTransform;		HX_STACK_VAR(offset,"offset");
			HX_STACK_LINE(197)
			offset->alphaOffset = (to->alphaOffset - from->alphaOffset);
			HX_STACK_LINE(197)
			offset->redOffset = (to->redOffset - from->redOffset);
			HX_STACK_LINE(197)
			offset->greenOffset = (to->greenOffset - from->greenOffset);
			HX_STACK_LINE(197)
			offset->blueOffset = (to->blueOffset - from->blueOffset);
			HX_STACK_LINE(197)
			offset->alphaMultiplier = (to->alphaMultiplier - from->alphaMultiplier);
			HX_STACK_LINE(197)
			offset->redMultiplier = (to->redMultiplier - from->redMultiplier);
			HX_STACK_LINE(197)
			offset->greenMultiplier = (to->greenMultiplier - from->greenMultiplier);
			HX_STACK_LINE(197)
			offset->blueMultiplier = (to->blueMultiplier - from->blueMultiplier);
		}
		HX_STACK_LINE(198)
		{
			HX_STACK_LINE(198)
			::native::geom::ColorTransform current = this->_curColorTransform;		HX_STACK_VAR(current,"current");
			::native::geom::ColorTransform offSet = this->_offSetColorTransform;		HX_STACK_VAR(offSet,"offSet");
			::native::geom::ColorTransform tween = this->_offSetColorTransform;		HX_STACK_VAR(tween,"tween");
			HX_STACK_LINE(198)
			tween->alphaOffset = (current->alphaOffset + (progress * offSet->alphaOffset));
			HX_STACK_LINE(198)
			tween->redOffset = (current->redOffset + (progress * offSet->redOffset));
			HX_STACK_LINE(198)
			tween->greenOffset = (current->greenOffset + (progress * offSet->greenOffset));
			HX_STACK_LINE(198)
			tween->blueOffset = (current->blueOffset + (progress * offSet->blueOffset));
			HX_STACK_LINE(198)
			tween->alphaMultiplier = (current->alphaMultiplier + (progress * offSet->alphaMultiplier));
			HX_STACK_LINE(198)
			tween->redMultiplier = (current->redMultiplier + (progress * offSet->redMultiplier));
			HX_STACK_LINE(198)
			tween->greenMultiplier = (current->greenMultiplier + (progress * offSet->greenMultiplier));
			HX_STACK_LINE(198)
			tween->blueMultiplier = (current->blueMultiplier + (progress * offSet->blueMultiplier));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Tween_obj,getLoopListNode,(void))

Void Tween_obj::advanceTime( Float progress,int playType){
{
		HX_STACK_PUSH("Tween::advanceTime","hxDragonBones/animation/Tween.hx",121);
		HX_STACK_THIS(this);
		HX_STACK_ARG(progress,"progress");
		HX_STACK_ARG(playType,"playType");
		HX_STACK_LINE(122)
		if ((this->_isPause)){
			HX_STACK_LINE(122)
			return null();
		}
		HX_STACK_LINE(126)
		if (((this->_rawDuration == (int)0))){
			HX_STACK_LINE(127)
			playType = (int)0;
			HX_STACK_LINE(128)
			if (((progress == (int)0))){
				HX_STACK_LINE(128)
				progress = (int)1;
			}
		}
		HX_STACK_LINE(133)
		if (((playType == (int)4))){
			HX_STACK_LINE(134)
			hx::DivEq(progress,this->_movementBoneData->scale);
			HX_STACK_LINE(135)
			hx::AddEq(progress,this->_movementBoneData->delay);
			HX_STACK_LINE(136)
			int loop = ::Std_obj::_int(progress);		HX_STACK_VAR(loop,"loop");
			HX_STACK_LINE(137)
			if (((loop != this->_loop))){
				HX_STACK_LINE(138)
				this->_nextFrameDataTimeEdge = (int)0;
				HX_STACK_LINE(139)
				this->_nextFrameDataID = (int)0;
				HX_STACK_LINE(140)
				this->_loop = loop;
			}
			HX_STACK_LINE(142)
			hx::SubEq(progress,loop);
			HX_STACK_LINE(143)
			progress = this->updateFrameData(progress,true,null());
		}
		else{
			HX_STACK_LINE(144)
			if (((playType == (int)3))){
				HX_STACK_LINE(144)
				progress = this->updateFrameData(progress,true,true);
			}
			else{
				HX_STACK_LINE(146)
				if (((bool((playType == (int)0)) && bool((progress == (int)1))))){
					HX_STACK_LINE(147)
					this->_curFrameData = this->_movementBoneData->frameList->__get((int)0);
					HX_STACK_LINE(148)
					this->_isPause = true;
				}
				else{
					HX_STACK_LINE(149)
					progress = ::Math_obj::sin((progress * ((::Math_obj::PI * 0.5))));
				}
			}
		}
		HX_STACK_LINE(153)
		if (((bool(!(::Math_obj::isNaN(this->_frameTweenEasing))) || bool((this->_curFrameData != null()))))){
			HX_STACK_LINE(154)
			{
				HX_STACK_LINE(154)
				::hxDragonBones::objects::Node current = this->_curNode;		HX_STACK_VAR(current,"current");
				::hxDragonBones::objects::Node offSet = this->_offSetNode;		HX_STACK_VAR(offSet,"offSet");
				::hxDragonBones::objects::Node tween = this->_node;		HX_STACK_VAR(tween,"tween");
				HX_STACK_LINE(154)
				tween->setValues((current->x + (progress * offSet->x)),(current->y + (progress * offSet->y)),(current->skewX + (progress * offSet->skewX)),(current->skewY + (progress * offSet->skewY)),(current->scaleX + (progress * offSet->scaleX)),(current->scaleY + (progress * offSet->scaleY)),(current->pivotX + (progress * offSet->pivotX)),(current->pivotY + (progress * offSet->pivotY)),::Std_obj::_int(tween->z));
			}
			HX_STACK_LINE(155)
			if ((this->differentColorTransform)){
				HX_STACK_LINE(156)
				::native::geom::ColorTransform current = this->_curColorTransform;		HX_STACK_VAR(current,"current");
				::native::geom::ColorTransform offSet = this->_offSetColorTransform;		HX_STACK_VAR(offSet,"offSet");
				::native::geom::ColorTransform tween = this->_colorTransform;		HX_STACK_VAR(tween,"tween");
				HX_STACK_LINE(156)
				tween->alphaOffset = (current->alphaOffset + (progress * offSet->alphaOffset));
				HX_STACK_LINE(156)
				tween->redOffset = (current->redOffset + (progress * offSet->redOffset));
				HX_STACK_LINE(156)
				tween->greenOffset = (current->greenOffset + (progress * offSet->greenOffset));
				HX_STACK_LINE(156)
				tween->blueOffset = (current->blueOffset + (progress * offSet->blueOffset));
				HX_STACK_LINE(156)
				tween->alphaMultiplier = (current->alphaMultiplier + (progress * offSet->alphaMultiplier));
				HX_STACK_LINE(156)
				tween->redMultiplier = (current->redMultiplier + (progress * offSet->redMultiplier));
				HX_STACK_LINE(156)
				tween->greenMultiplier = (current->greenMultiplier + (progress * offSet->greenMultiplier));
				HX_STACK_LINE(156)
				tween->blueMultiplier = (current->blueMultiplier + (progress * offSet->blueMultiplier));
			}
		}
		HX_STACK_LINE(160)
		if (((this->_curFrameData != null()))){
			HX_STACK_LINE(161)
			this->arriveFrameData(this->_curFrameData);
			HX_STACK_LINE(162)
			this->_curFrameData = null();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Tween_obj,advanceTime,(void))

Void Tween_obj::stop( ){
{
		HX_STACK_PUSH("Tween::stop","hxDragonBones/animation/Tween.hx",117);
		HX_STACK_THIS(this);
		HX_STACK_LINE(117)
		this->_isPause = true;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Tween_obj,stop,(void))

Void Tween_obj::gotoAndPlay( ::hxDragonBones::objects::MovementBoneData movementBoneData,Float rawDuration,bool loop,Float tweenEasing){
{
		HX_STACK_PUSH("Tween::gotoAndPlay","hxDragonBones/animation/Tween.hx",73);
		HX_STACK_THIS(this);
		HX_STACK_ARG(movementBoneData,"movementBoneData");
		HX_STACK_ARG(rawDuration,"rawDuration");
		HX_STACK_ARG(loop,"loop");
		HX_STACK_ARG(tweenEasing,"tweenEasing");
		HX_STACK_LINE(75)
		if (((movementBoneData == null()))){
			HX_STACK_LINE(75)
			return null();
		}
		HX_STACK_LINE(79)
		this->_movementBoneData = movementBoneData;
		HX_STACK_LINE(80)
		int totalFrames = this->_movementBoneData->frameList->length;		HX_STACK_VAR(totalFrames,"totalFrames");
		HX_STACK_LINE(81)
		if (((totalFrames == (int)0))){
			HX_STACK_LINE(82)
			this->_bone->changeDisplay((int)-1);
			HX_STACK_LINE(83)
			this->stop();
			HX_STACK_LINE(84)
			return null();
		}
		HX_STACK_LINE(87)
		hx::ModEq(this->_node->skewX,(int)360);
		HX_STACK_LINE(88)
		hx::ModEq(this->_node->skewY,(int)360);
		HX_STACK_LINE(89)
		this->_isPause = false;
		HX_STACK_LINE(90)
		this->_curFrameData = null();
		HX_STACK_LINE(91)
		this->_loop = (  ((loop)) ? int((int)0) : int((int)-1) );
		HX_STACK_LINE(93)
		this->_nextFrameDataTimeEdge = (int)0;
		HX_STACK_LINE(94)
		this->_nextFrameDataID = (int)0;
		HX_STACK_LINE(95)
		this->_rawDuration = rawDuration;
		HX_STACK_LINE(96)
		this->_tweenEasing = tweenEasing;
		HX_STACK_LINE(98)
		::hxDragonBones::objects::FrameData nextFrameData = null();		HX_STACK_VAR(nextFrameData,"nextFrameData");
		HX_STACK_LINE(99)
		if (((totalFrames == (int)1))){
			HX_STACK_LINE(100)
			this->_frameTweenEasing = (int)1;
			HX_STACK_LINE(101)
			this->_rawDuration = (int)0;
			HX_STACK_LINE(102)
			nextFrameData = this->_movementBoneData->frameList->__get((int)0);
			HX_STACK_LINE(103)
			this->setOffset(this->_node,this->_colorTransform,nextFrameData->node,nextFrameData->colorTransform,null());
		}
		else{
			HX_STACK_LINE(104)
			if (((bool(loop) && bool((this->_movementBoneData->delay != (int)0))))){
				HX_STACK_LINE(105)
				this->getLoopListNode();
				HX_STACK_LINE(106)
				this->setOffset(this->_node,this->_colorTransform,this->_offSetNode,this->_offSetColorTransform,null());
			}
			else{
				HX_STACK_LINE(108)
				nextFrameData = this->_movementBoneData->frameList->__get((int)0);
				HX_STACK_LINE(109)
				this->setOffset(this->_node,this->_colorTransform,nextFrameData->node,nextFrameData->colorTransform,null());
			}
		}
		HX_STACK_LINE(112)
		if (((nextFrameData != null()))){
			HX_STACK_LINE(112)
			this->updateBoneDisplayIndex(nextFrameData);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(Tween_obj,gotoAndPlay,(void))

Float Tween_obj::HALF_PI;

::hxDragonBones::events::SoundEventManager Tween_obj::_soundManager;

Float Tween_obj::getEaseValue( Float value,Dynamic easing){
	HX_STACK_PUSH("Tween::getEaseValue","hxDragonBones/animation/Tween.hx",23);
	HX_STACK_ARG(value,"value");
	HX_STACK_ARG(easing,"easing");
	HX_STACK_LINE(24)
	Float valueEase = (int)0;		HX_STACK_VAR(valueEase,"valueEase");
	HX_STACK_LINE(25)
	if ((::Math_obj::isNaN(easing))){
		HX_STACK_LINE(26)
		valueEase = (int)0;
		HX_STACK_LINE(27)
		easing = (int)0;
		HX_STACK_LINE(28)
		value = (int)0;
	}
	else{
		HX_STACK_LINE(29)
		if (((easing > (int)1))){
			HX_STACK_LINE(30)
			valueEase = ((0.5 * (((int)1 - ::Math_obj::cos((value * ::Math_obj::PI))))) - value);
			HX_STACK_LINE(31)
			hx::SubEq(easing,(int)1);
		}
		else{
			HX_STACK_LINE(32)
			if (((easing > (int)0))){
				HX_STACK_LINE(32)
				valueEase = (::Math_obj::sin((value * ((::Math_obj::PI * 0.5)))) - value);
			}
			else{
				HX_STACK_LINE(34)
				if (((easing < (int)0))){
					HX_STACK_LINE(35)
					valueEase = (((int)1 - ::Math_obj::cos((value * ((::Math_obj::PI * 0.5))))) - value);
					HX_STACK_LINE(36)
					hx::MultEq(easing,(int)-1);
				}
			}
		}
	}
	HX_STACK_LINE(38)
	return ((valueEase * easing) + value);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Tween_obj,getEaseValue,return )


Tween_obj::Tween_obj()
{
}

void Tween_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Tween);
	HX_MARK_MEMBER_NAME(_loop,"_loop");
	HX_MARK_MEMBER_NAME(_nextFrameDataID,"_nextFrameDataID");
	HX_MARK_MEMBER_NAME(_frameDuration,"_frameDuration");
	HX_MARK_MEMBER_NAME(_nextFrameDataTimeEdge,"_nextFrameDataTimeEdge");
	HX_MARK_MEMBER_NAME(_rawDuration,"_rawDuration");
	HX_MARK_MEMBER_NAME(_isPause,"_isPause");
	HX_MARK_MEMBER_NAME(_frameTweenEasing,"_frameTweenEasing");
	HX_MARK_MEMBER_NAME(_tweenEasing,"_tweenEasing");
	HX_MARK_MEMBER_NAME(_curFrameData,"_curFrameData");
	HX_MARK_MEMBER_NAME(_offSetColorTransform,"_offSetColorTransform");
	HX_MARK_MEMBER_NAME(_offSetNode,"_offSetNode");
	HX_MARK_MEMBER_NAME(_curColorTransform,"_curColorTransform");
	HX_MARK_MEMBER_NAME(_curNode,"_curNode");
	HX_MARK_MEMBER_NAME(_colorTransform,"_colorTransform");
	HX_MARK_MEMBER_NAME(_node,"_node");
	HX_MARK_MEMBER_NAME(_movementBoneData,"_movementBoneData");
	HX_MARK_MEMBER_NAME(_bone,"_bone");
	HX_MARK_MEMBER_NAME(differentColorTransform,"differentColorTransform");
	HX_MARK_END_CLASS();
}

void Tween_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_loop,"_loop");
	HX_VISIT_MEMBER_NAME(_nextFrameDataID,"_nextFrameDataID");
	HX_VISIT_MEMBER_NAME(_frameDuration,"_frameDuration");
	HX_VISIT_MEMBER_NAME(_nextFrameDataTimeEdge,"_nextFrameDataTimeEdge");
	HX_VISIT_MEMBER_NAME(_rawDuration,"_rawDuration");
	HX_VISIT_MEMBER_NAME(_isPause,"_isPause");
	HX_VISIT_MEMBER_NAME(_frameTweenEasing,"_frameTweenEasing");
	HX_VISIT_MEMBER_NAME(_tweenEasing,"_tweenEasing");
	HX_VISIT_MEMBER_NAME(_curFrameData,"_curFrameData");
	HX_VISIT_MEMBER_NAME(_offSetColorTransform,"_offSetColorTransform");
	HX_VISIT_MEMBER_NAME(_offSetNode,"_offSetNode");
	HX_VISIT_MEMBER_NAME(_curColorTransform,"_curColorTransform");
	HX_VISIT_MEMBER_NAME(_curNode,"_curNode");
	HX_VISIT_MEMBER_NAME(_colorTransform,"_colorTransform");
	HX_VISIT_MEMBER_NAME(_node,"_node");
	HX_VISIT_MEMBER_NAME(_movementBoneData,"_movementBoneData");
	HX_VISIT_MEMBER_NAME(_bone,"_bone");
	HX_VISIT_MEMBER_NAME(differentColorTransform,"differentColorTransform");
}

Dynamic Tween_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"stop") ) { return stop_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_loop") ) { return _loop; }
		if (HX_FIELD_EQ(inName,"_node") ) { return _node; }
		if (HX_FIELD_EQ(inName,"_bone") ) { return _bone; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"HALF_PI") ) { return HALF_PI; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"_isPause") ) { return _isPause; }
		if (HX_FIELD_EQ(inName,"_curNode") ) { return _curNode; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"setOffset") ) { return setOffset_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"advanceTime") ) { return advanceTime_dyn(); }
		if (HX_FIELD_EQ(inName,"gotoAndPlay") ) { return gotoAndPlay_dyn(); }
		if (HX_FIELD_EQ(inName,"_offSetNode") ) { return _offSetNode; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"getEaseValue") ) { return getEaseValue_dyn(); }
		if (HX_FIELD_EQ(inName,"_rawDuration") ) { return _rawDuration; }
		if (HX_FIELD_EQ(inName,"_tweenEasing") ) { return _tweenEasing; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"_soundManager") ) { return _soundManager; }
		if (HX_FIELD_EQ(inName,"_curFrameData") ) { return _curFrameData; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"_frameDuration") ) { return _frameDuration; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"updateFrameData") ) { return updateFrameData_dyn(); }
		if (HX_FIELD_EQ(inName,"arriveFrameData") ) { return arriveFrameData_dyn(); }
		if (HX_FIELD_EQ(inName,"getLoopListNode") ) { return getLoopListNode_dyn(); }
		if (HX_FIELD_EQ(inName,"_colorTransform") ) { return _colorTransform; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"_nextFrameDataID") ) { return _nextFrameDataID; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"_frameTweenEasing") ) { return _frameTweenEasing; }
		if (HX_FIELD_EQ(inName,"_movementBoneData") ) { return _movementBoneData; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"_curColorTransform") ) { return _curColorTransform; }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"_offSetColorTransform") ) { return _offSetColorTransform; }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"updateBoneDisplayIndex") ) { return updateBoneDisplayIndex_dyn(); }
		if (HX_FIELD_EQ(inName,"_nextFrameDataTimeEdge") ) { return _nextFrameDataTimeEdge; }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"differentColorTransform") ) { return differentColorTransform; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Tween_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"_loop") ) { _loop=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_node") ) { _node=inValue.Cast< ::hxDragonBones::objects::Node >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_bone") ) { _bone=inValue.Cast< ::hxDragonBones::Bone >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"HALF_PI") ) { HALF_PI=inValue.Cast< Float >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"_isPause") ) { _isPause=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_curNode") ) { _curNode=inValue.Cast< ::hxDragonBones::objects::Node >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"_offSetNode") ) { _offSetNode=inValue.Cast< ::hxDragonBones::objects::Node >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"_rawDuration") ) { _rawDuration=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_tweenEasing") ) { _tweenEasing=inValue.Cast< Float >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"_soundManager") ) { _soundManager=inValue.Cast< ::hxDragonBones::events::SoundEventManager >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_curFrameData") ) { _curFrameData=inValue.Cast< ::hxDragonBones::objects::FrameData >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"_frameDuration") ) { _frameDuration=inValue.Cast< Float >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"_colorTransform") ) { _colorTransform=inValue.Cast< ::native::geom::ColorTransform >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"_nextFrameDataID") ) { _nextFrameDataID=inValue.Cast< int >(); return inValue; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"_frameTweenEasing") ) { _frameTweenEasing=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_movementBoneData") ) { _movementBoneData=inValue.Cast< ::hxDragonBones::objects::MovementBoneData >(); return inValue; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"_curColorTransform") ) { _curColorTransform=inValue.Cast< ::native::geom::ColorTransform >(); return inValue; }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"_offSetColorTransform") ) { _offSetColorTransform=inValue.Cast< ::native::geom::ColorTransform >(); return inValue; }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"_nextFrameDataTimeEdge") ) { _nextFrameDataTimeEdge=inValue.Cast< Float >(); return inValue; }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"differentColorTransform") ) { differentColorTransform=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Tween_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_loop"));
	outFields->push(HX_CSTRING("_nextFrameDataID"));
	outFields->push(HX_CSTRING("_frameDuration"));
	outFields->push(HX_CSTRING("_nextFrameDataTimeEdge"));
	outFields->push(HX_CSTRING("_rawDuration"));
	outFields->push(HX_CSTRING("_isPause"));
	outFields->push(HX_CSTRING("_frameTweenEasing"));
	outFields->push(HX_CSTRING("_tweenEasing"));
	outFields->push(HX_CSTRING("_curFrameData"));
	outFields->push(HX_CSTRING("_offSetColorTransform"));
	outFields->push(HX_CSTRING("_offSetNode"));
	outFields->push(HX_CSTRING("_curColorTransform"));
	outFields->push(HX_CSTRING("_curNode"));
	outFields->push(HX_CSTRING("_colorTransform"));
	outFields->push(HX_CSTRING("_node"));
	outFields->push(HX_CSTRING("_movementBoneData"));
	outFields->push(HX_CSTRING("_bone"));
	outFields->push(HX_CSTRING("differentColorTransform"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("HALF_PI"),
	HX_CSTRING("_soundManager"),
	HX_CSTRING("getEaseValue"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("updateFrameData"),
	HX_CSTRING("arriveFrameData"),
	HX_CSTRING("updateBoneDisplayIndex"),
	HX_CSTRING("setOffset"),
	HX_CSTRING("getLoopListNode"),
	HX_CSTRING("advanceTime"),
	HX_CSTRING("stop"),
	HX_CSTRING("gotoAndPlay"),
	HX_CSTRING("_loop"),
	HX_CSTRING("_nextFrameDataID"),
	HX_CSTRING("_frameDuration"),
	HX_CSTRING("_nextFrameDataTimeEdge"),
	HX_CSTRING("_rawDuration"),
	HX_CSTRING("_isPause"),
	HX_CSTRING("_frameTweenEasing"),
	HX_CSTRING("_tweenEasing"),
	HX_CSTRING("_curFrameData"),
	HX_CSTRING("_offSetColorTransform"),
	HX_CSTRING("_offSetNode"),
	HX_CSTRING("_curColorTransform"),
	HX_CSTRING("_curNode"),
	HX_CSTRING("_colorTransform"),
	HX_CSTRING("_node"),
	HX_CSTRING("_movementBoneData"),
	HX_CSTRING("_bone"),
	HX_CSTRING("differentColorTransform"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Tween_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(Tween_obj::HALF_PI,"HALF_PI");
	HX_MARK_MEMBER_NAME(Tween_obj::_soundManager,"_soundManager");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Tween_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Tween_obj::HALF_PI,"HALF_PI");
	HX_VISIT_MEMBER_NAME(Tween_obj::_soundManager,"_soundManager");
};

Class Tween_obj::__mClass;

void Tween_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("hxDragonBones.animation.Tween"), hx::TCanCast< Tween_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Tween_obj::__boot()
{
	HALF_PI= (::Math_obj::PI * 0.5);
	_soundManager= ::hxDragonBones::events::SoundEventManager_obj::get_instance();
}

} // end namespace hxDragonBones
} // end namespace animation
