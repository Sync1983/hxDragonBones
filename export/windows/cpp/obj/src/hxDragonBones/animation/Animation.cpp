#include <hxcpp.h>

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
#ifndef INCLUDED_hxDragonBones_events_AnimationEvent
#include <hxDragonBones/events/AnimationEvent.h>
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
#ifndef INCLUDED_hxDragonBones_objects_AnimationData
#include <hxDragonBones/objects/AnimationData.h>
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
#ifndef INCLUDED_native_events_Event
#include <native/events/Event.h>
#endif
#ifndef INCLUDED_native_events_EventDispatcher
#include <native/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_native_events_IEventDispatcher
#include <native/events/IEventDispatcher.h>
#endif
namespace hxDragonBones{
namespace animation{

Void Animation_obj::__construct(::hxDragonBones::Armature armature)
{
HX_STACK_PUSH("Animation::new","hxDragonBones/animation/Animation.hx",26);
{
	HX_STACK_LINE(27)
	this->_armature = armature;
	HX_STACK_LINE(28)
	this->set_timeScale((int)1);
	HX_STACK_LINE(29)
	this->tweenEnabled = true;
}
;
	return null();
}

Animation_obj::~Animation_obj() { }

Dynamic Animation_obj::__CreateEmpty() { return  new Animation_obj; }
hx::ObjectPtr< Animation_obj > Animation_obj::__new(::hxDragonBones::Armature armature)
{  hx::ObjectPtr< Animation_obj > result = new Animation_obj();
	result->__construct(armature);
	return result;}

Dynamic Animation_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Animation_obj > result = new Animation_obj();
	result->__construct(inArgs[0]);
	return result;}

hx::Object *Animation_obj::__ToInterface(const type_info &inType) {
	if (inType==typeid( ::hxDragonBones::utils::IDisposable_obj)) return operator ::hxDragonBones::utils::IDisposable_obj *();
	return super::__ToInterface(inType);
}

Void Animation_obj::arriveFrameData( ::hxDragonBones::objects::MovementFrameData movementFrameData){
{
		HX_STACK_PUSH("Animation::arriveFrameData","hxDragonBones/animation/Animation.hx",296);
		HX_STACK_THIS(this);
		HX_STACK_ARG(movementFrameData,"movementFrameData");
		HX_STACK_LINE(297)
		if (((bool((movementFrameData->event != null())) && bool(this->_armature->hasEventListener(HX_CSTRING("movementFrameEvent")))))){
			HX_STACK_LINE(298)
			::hxDragonBones::events::FrameEvent frameEvent = ::hxDragonBones::events::FrameEvent_obj::__new(HX_CSTRING("movementFrameEvent"),null(),null(),null());		HX_STACK_VAR(frameEvent,"frameEvent");
			HX_STACK_LINE(299)
			frameEvent->movementID = this->movementID;
			HX_STACK_LINE(300)
			frameEvent->frameLabel = movementFrameData->event;
			HX_STACK_LINE(301)
			this->_armature->dispatchEvent(frameEvent);
		}
		HX_STACK_LINE(304)
		if (((bool((movementFrameData->sound != null())) && bool(::hxDragonBones::animation::Animation_obj::_soundManager->hasEventListener(HX_CSTRING("sound")))))){
			HX_STACK_LINE(305)
			::hxDragonBones::events::SoundEvent soundEvent = ::hxDragonBones::events::SoundEvent_obj::__new(HX_CSTRING("sound"),null());		HX_STACK_VAR(soundEvent,"soundEvent");
			HX_STACK_LINE(306)
			soundEvent->movementID = this->movementID;
			HX_STACK_LINE(307)
			soundEvent->sound = movementFrameData->sound;
			HX_STACK_LINE(308)
			soundEvent->armature = this->_armature;
			HX_STACK_LINE(309)
			::hxDragonBones::animation::Animation_obj::_soundManager->dispatchEvent(soundEvent);
		}
		HX_STACK_LINE(312)
		if (((movementFrameData->movement != null()))){
			HX_STACK_LINE(312)
			this->gotoAndPlay(movementFrameData->movement,null(),null(),null());
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Animation_obj,arriveFrameData,(void))

Void Animation_obj::updateFrameData( Float progress){
{
		HX_STACK_PUSH("Animation::updateFrameData","hxDragonBones/animation/Animation.hx",275);
		HX_STACK_THIS(this);
		HX_STACK_ARG(progress,"progress");
		HX_STACK_LINE(276)
		Float playedTime = (this->_rawDuration * progress);		HX_STACK_VAR(playedTime,"playedTime");
		HX_STACK_LINE(277)
		if (((playedTime < this->_nextFrameDataTimeEdge))){
			HX_STACK_LINE(277)
			return null();
		}
		HX_STACK_LINE(281)
		this->_breakFrameWhile = false;
		HX_STACK_LINE(282)
		int length = this->movementData->movementFrameList->length;		HX_STACK_VAR(length,"length");
		HX_STACK_LINE(283)
		do{
			HX_STACK_LINE(284)
			::hxDragonBones::objects::MovementFrameData currentFrameData = this->movementData->movementFrameList->__get(this->_nextFrameDataID);		HX_STACK_VAR(currentFrameData,"currentFrameData");
			HX_STACK_LINE(285)
			hx::AddEq(this->_nextFrameDataTimeEdge,currentFrameData->duration);
			HX_STACK_LINE(286)
			if (((++(this->_nextFrameDataID) >= length))){
				HX_STACK_LINE(286)
				this->_nextFrameDataID = (int)0;
			}
			HX_STACK_LINE(289)
			this->arriveFrameData(currentFrameData);
			HX_STACK_LINE(290)
			if ((this->_breakFrameWhile)){
				HX_STACK_LINE(290)
				break;
			}
		}
while(((playedTime >= this->_nextFrameDataTimeEdge)));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Animation_obj,updateFrameData,(void))

Void Animation_obj::advanceTime( Float passedTime){
{
		HX_STACK_PUSH("Animation::advanceTime","hxDragonBones/animation/Animation.hx",193);
		HX_STACK_THIS(this);
		HX_STACK_ARG(passedTime,"passedTime");
		HX_STACK_LINE(194)
		if ((!(this->get_isPlaying()))){
			HX_STACK_LINE(194)
			return null();
		}
		HX_STACK_LINE(198)
		if (((bool((bool((this->_loop > (int)0)) || bool((this->currentTime < this->totalTime)))) || bool((this->totalTime == (int)0))))){
			HX_STACK_LINE(200)
			::hxDragonBones::events::AnimationEvent event = null();		HX_STACK_VAR(event,"event");
			HX_STACK_LINE(201)
			Float progress;		HX_STACK_VAR(progress,"progress");
			HX_STACK_LINE(203)
			if (((this->totalTime > (int)0))){
				HX_STACK_LINE(204)
				hx::AddEq(this->currentTime,(passedTime * this->timeScale));
				HX_STACK_LINE(205)
				progress = (Float(this->currentTime) / Float(this->totalTime));
			}
			else{
				HX_STACK_LINE(207)
				this->currentTime = (int)1;
				HX_STACK_LINE(208)
				this->totalTime = (int)1;
				HX_STACK_LINE(209)
				progress = (int)1;
			}
			HX_STACK_LINE(212)
			if (((this->_playType == (int)4))){
				HX_STACK_LINE(213)
				int loop = ::Std_obj::_int(progress);		HX_STACK_VAR(loop,"loop");
				HX_STACK_LINE(214)
				if (((loop != this->_loop))){
					HX_STACK_LINE(215)
					this->_loop = loop;
					HX_STACK_LINE(216)
					this->_nextFrameDataTimeEdge = (int)0;
					HX_STACK_LINE(217)
					if ((this->_armature->hasEventListener(HX_CSTRING("loopComplete")))){
						HX_STACK_LINE(217)
						event = ::hxDragonBones::events::AnimationEvent_obj::__new(HX_CSTRING("loopComplete"),null(),null());
					}
				}
			}
			else{
				HX_STACK_LINE(221)
				if (((progress >= (int)1))){
					HX_STACK_LINE(221)
					switch( (int)(this->_playType)){
						case (int)0: case (int)3: {
							HX_STACK_LINE(224)
							progress = (int)1;
							HX_STACK_LINE(225)
							if ((this->_armature->hasEventListener(HX_CSTRING("complete")))){
								HX_STACK_LINE(225)
								event = ::hxDragonBones::events::AnimationEvent_obj::__new(HX_CSTRING("complete"),null(),null());
							}
						}
						;break;
						case (int)1: {
							HX_STACK_LINE(229)
							progress = (int)0;
							HX_STACK_LINE(230)
							this->_playType = (int)3;
							HX_STACK_LINE(231)
							this->currentTime = (int)0;
							HX_STACK_LINE(232)
							this->totalTime = this->_duration;
							HX_STACK_LINE(233)
							if ((this->_armature->hasEventListener(HX_CSTRING("start")))){
								HX_STACK_LINE(233)
								event = ::hxDragonBones::events::AnimationEvent_obj::__new(HX_CSTRING("start"),null(),null());
							}
						}
						;break;
						case (int)2: {
							HX_STACK_LINE(237)
							progress = (int)0;
							HX_STACK_LINE(238)
							this->_playType = (int)4;
							HX_STACK_LINE(239)
							this->currentTime = (int)0;
							HX_STACK_LINE(240)
							this->totalTime = this->_duration;
							HX_STACK_LINE(241)
							if ((this->_armature->hasEventListener(HX_CSTRING("start")))){
								HX_STACK_LINE(241)
								event = ::hxDragonBones::events::AnimationEvent_obj::__new(HX_CSTRING("start"),null(),null());
							}
						}
						;break;
					}
				}
			}
			HX_STACK_LINE(247)
			{
				HX_STACK_LINE(247)
				int _g = (int)0;		HX_STACK_VAR(_g,"_g");
				Array< ::hxDragonBones::Bone > _g1 = this->_armature->bones;		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(247)
				while(((_g < _g1->length))){
					HX_STACK_LINE(247)
					::hxDragonBones::Bone bone = _g1->__get(_g);		HX_STACK_VAR(bone,"bone");
					HX_STACK_LINE(247)
					++(_g);
					HX_STACK_LINE(248)
					bone->tween->advanceTime(progress,this->_playType);
					HX_STACK_LINE(250)
					if (((bone->get_childArmature() != null()))){
						HX_STACK_LINE(250)
						bone->get_childArmature()->animation->advanceTime(passedTime);
					}
				}
			}
			HX_STACK_LINE(255)
			if (((bool(((bool((this->_playType == (int)3)) || bool((this->_playType == (int)4))))) && bool((this->movementData->movementFrameList->length > (int)0))))){
				HX_STACK_LINE(256)
				if (((this->_loop > (int)0))){
					HX_STACK_LINE(256)
					hx::SubEq(progress,this->_loop);
				}
				HX_STACK_LINE(259)
				this->updateFrameData(progress);
			}
			HX_STACK_LINE(262)
			if (((event != null()))){
				HX_STACK_LINE(263)
				event->movementID = this->movementID;
				HX_STACK_LINE(264)
				this->_armature->dispatchEvent(event);
			}
		}
		else{
			HX_STACK_LINE(267)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			Array< ::hxDragonBones::Bone > _g1 = this->_armature->bones;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(267)
			while(((_g < _g1->length))){
				HX_STACK_LINE(267)
				::hxDragonBones::Bone bone = _g1->__get(_g);		HX_STACK_VAR(bone,"bone");
				HX_STACK_LINE(267)
				++(_g);
				HX_STACK_LINE(268)
				if (((bone->get_childArmature() != null()))){
					HX_STACK_LINE(268)
					bone->get_childArmature()->animation->advanceTime(passedTime);
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Animation_obj,advanceTime,(void))

Void Animation_obj::stop( ){
{
		HX_STACK_PUSH("Animation::stop","hxDragonBones/animation/Animation.hx",189);
		HX_STACK_THIS(this);
		HX_STACK_LINE(189)
		this->isPlaying = false;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Animation_obj,stop,(void))

Void Animation_obj::play( ){
{
		HX_STACK_PUSH("Animation::play","hxDragonBones/animation/Animation.hx",170);
		HX_STACK_THIS(this);
		HX_STACK_LINE(171)
		if (((this->animationData == null()))){
			HX_STACK_LINE(171)
			return null();
		}
		HX_STACK_LINE(175)
		if (((this->movementID == null()))){
			HX_STACK_LINE(176)
			if (((this->get_movementList() != null()))){
				HX_STACK_LINE(176)
				this->gotoAndPlay(this->get_movementList()->__get((int)0),null(),null(),null());
			}
			HX_STACK_LINE(179)
			return null();
		}
		HX_STACK_LINE(182)
		if ((this->get_isComplete())){
			HX_STACK_LINE(182)
			this->gotoAndPlay(this->movementID,null(),null(),null());
		}
		else{
			HX_STACK_LINE(184)
			if ((!(this->get_isPlaying()))){
				HX_STACK_LINE(184)
				this->isPlaying = true;
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Animation_obj,play,(void))

Void Animation_obj::gotoAndPlay( ::String movementID,hx::Null< Float >  __o_tweenTime,hx::Null< Float >  __o_duration,Dynamic loop){
Float tweenTime = __o_tweenTime.Default(-1);
Float duration = __o_duration.Default(-1);
	HX_STACK_PUSH("Animation::gotoAndPlay","hxDragonBones/animation/Animation.hx",102);
	HX_STACK_THIS(this);
	HX_STACK_ARG(movementID,"movementID");
	HX_STACK_ARG(tweenTime,"tweenTime");
	HX_STACK_ARG(duration,"duration");
	HX_STACK_ARG(loop,"loop");
{
		HX_STACK_LINE(103)
		if (((this->animationData == null()))){
			HX_STACK_LINE(103)
			return null();
		}
		HX_STACK_LINE(107)
		::hxDragonBones::objects::MovementData movementData = this->animationData->getMovementData(movementID);		HX_STACK_VAR(movementData,"movementData");
		HX_STACK_LINE(108)
		if (((movementData == null()))){
			HX_STACK_LINE(108)
			return null();
		}
		HX_STACK_LINE(112)
		this->movementData = movementData;
		HX_STACK_LINE(113)
		this->isPlaying = true;
		HX_STACK_LINE(114)
		this->currentTime = (int)0;
		HX_STACK_LINE(115)
		this->_breakFrameWhile = true;
		HX_STACK_LINE(117)
		::String exMovementID = this->movementID;		HX_STACK_VAR(exMovementID,"exMovementID");
		HX_STACK_LINE(118)
		this->movementID = movementID;
		HX_STACK_LINE(120)
		if (((tweenTime >= (int)0))){
			HX_STACK_LINE(120)
			this->totalTime = tweenTime;
		}
		else{
			HX_STACK_LINE(122)
			if (((bool(this->tweenEnabled) && bool((exMovementID != null()))))){
				HX_STACK_LINE(122)
				this->totalTime = movementData->durationTo;
			}
			else{
				HX_STACK_LINE(124)
				this->totalTime = (int)0;
			}
		}
		HX_STACK_LINE(128)
		if (((this->totalTime < (int)0))){
			HX_STACK_LINE(128)
			this->totalTime = (int)0;
		}
		HX_STACK_LINE(132)
		this->_duration = (  (((duration >= (int)0))) ? Float(duration) : Float(this->movementData->durationTween) );
		HX_STACK_LINE(133)
		if (((this->_duration < (int)0))){
			HX_STACK_LINE(133)
			this->_duration = (int)0;
		}
		HX_STACK_LINE(137)
		loop = hx::TCast< Bool >::cast((  (((loop == null()))) ? bool(this->movementData->loop) : bool(loop) ));
		HX_STACK_LINE(139)
		this->_rawDuration = this->movementData->duration;
		HX_STACK_LINE(141)
		this->_loop = (  ((loop)) ? int((int)0) : int((int)-1) );
		HX_STACK_LINE(142)
		if (((this->_rawDuration == (int)0))){
			HX_STACK_LINE(142)
			this->_playType = (int)0;
		}
		else{
			HX_STACK_LINE(145)
			this->_nextFrameDataTimeEdge = (int)0;
			HX_STACK_LINE(146)
			this->_nextFrameDataID = (int)0;
			HX_STACK_LINE(147)
			this->_playType = (  ((loop)) ? int((int)2) : int((int)1) );
		}
		HX_STACK_LINE(150)
		{
			HX_STACK_LINE(150)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			Array< ::hxDragonBones::Bone > _g1 = this->_armature->bones;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(150)
			while(((_g < _g1->length))){
				HX_STACK_LINE(150)
				::hxDragonBones::Bone bone = _g1->__get(_g);		HX_STACK_VAR(bone,"bone");
				HX_STACK_LINE(150)
				++(_g);
				HX_STACK_LINE(151)
				::hxDragonBones::objects::MovementBoneData movementBoneData = this->movementData->getMovementBoneData(bone->name);		HX_STACK_VAR(movementBoneData,"movementBoneData");
				HX_STACK_LINE(152)
				if (((movementBoneData != null()))){
					HX_STACK_LINE(153)
					bone->tween->gotoAndPlay(movementBoneData,this->_rawDuration,loop,this->movementData->tweenEasing);
					HX_STACK_LINE(154)
					if (((bone->get_childArmature() != null()))){
						HX_STACK_LINE(154)
						bone->get_childArmature()->animation->gotoAndPlay(movementID,null(),null(),null());
					}
				}
				else{
					HX_STACK_LINE(157)
					bone->tween->stop();
				}
			}
		}
		HX_STACK_LINE(162)
		if ((this->_armature->hasEventListener(HX_CSTRING("movementChange")))){
			HX_STACK_LINE(163)
			::hxDragonBones::events::AnimationEvent event = ::hxDragonBones::events::AnimationEvent_obj::__new(HX_CSTRING("movementChange"),null(),null());		HX_STACK_VAR(event,"event");
			HX_STACK_LINE(164)
			event->exMovementID = exMovementID;
			HX_STACK_LINE(165)
			event->movementID = this->movementID;
			HX_STACK_LINE(166)
			this->_armature->dispatchEvent(event);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(Animation_obj,gotoAndPlay,(void))

Void Animation_obj::dispose( ){
{
		HX_STACK_PUSH("Animation::dispose","hxDragonBones/animation/Animation.hx",95);
		HX_STACK_THIS(this);
		HX_STACK_LINE(96)
		this->stop();
		HX_STACK_LINE(97)
		this->set_animationData(null());
		HX_STACK_LINE(98)
		this->movementData = null();
		HX_STACK_LINE(99)
		this->_armature = null();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Animation_obj,dispose,(void))

Array< ::String > Animation_obj::get_movementList( ){
	HX_STACK_PUSH("Animation::get_movementList","hxDragonBones/animation/Animation.hx",91);
	HX_STACK_THIS(this);
	HX_STACK_LINE(91)
	return (  (((this->animationData != null()))) ? Array< ::String >(this->animationData->get_movementList()) : Array< ::String >(null()) );
}


HX_DEFINE_DYNAMIC_FUNC0(Animation_obj,get_movementList,return )

Float Animation_obj::set_timeScale( Float value){
	HX_STACK_PUSH("Animation::set_timeScale","hxDragonBones/animation/Animation.hx",76);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(77)
	if (((value < (int)0))){
		HX_STACK_LINE(77)
		value = (int)0;
	}
	HX_STACK_LINE(81)
	this->timeScale = value;
	HX_STACK_LINE(83)
	{
		HX_STACK_LINE(83)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		Array< ::hxDragonBones::Bone > _g1 = this->_armature->bones;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(83)
		while(((_g < _g1->length))){
			HX_STACK_LINE(83)
			::hxDragonBones::Bone bone = _g1->__get(_g);		HX_STACK_VAR(bone,"bone");
			HX_STACK_LINE(83)
			++(_g);
			HX_STACK_LINE(84)
			if (((bone->get_childArmature() != null()))){
				HX_STACK_LINE(84)
				bone->get_childArmature()->animation->set_timeScale(this->timeScale);
			}
		}
	}
	HX_STACK_LINE(88)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(Animation_obj,set_timeScale,return )

bool Animation_obj::get_isPause( ){
	HX_STACK_PUSH("Animation::get_isPause","hxDragonBones/animation/Animation.hx",72);
	HX_STACK_THIS(this);
	HX_STACK_LINE(72)
	return !(this->get_isPlaying());
}


HX_DEFINE_DYNAMIC_FUNC0(Animation_obj,get_isPause,return )

bool Animation_obj::get_isComplete( ){
	HX_STACK_PUSH("Animation::get_isComplete","hxDragonBones/animation/Animation.hx",68);
	HX_STACK_THIS(this);
	HX_STACK_LINE(68)
	return (bool((this->_loop < (int)0)) && bool((this->currentTime >= this->totalTime)));
}


HX_DEFINE_DYNAMIC_FUNC0(Animation_obj,get_isComplete,return )

bool Animation_obj::get_isPlaying( ){
	HX_STACK_PUSH("Animation::get_isPlaying","hxDragonBones/animation/Animation.hx",61);
	HX_STACK_THIS(this);
	HX_STACK_LINE(62)
	if ((this->isPlaying)){
		HX_STACK_LINE(62)
		return (bool((this->_loop >= (int)0)) || bool((this->currentTime < this->totalTime)));
	}
	HX_STACK_LINE(65)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC0(Animation_obj,get_isPlaying,return )

::hxDragonBones::objects::AnimationData Animation_obj::set_animationData( ::hxDragonBones::objects::AnimationData value){
	HX_STACK_PUSH("Animation::set_animationData","hxDragonBones/animation/Animation.hx",53);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(54)
	if (((value != null()))){
		HX_STACK_LINE(55)
		this->stop();
		HX_STACK_LINE(56)
		this->animationData = value;
	}
	HX_STACK_LINE(58)
	return this->animationData;
}


HX_DEFINE_DYNAMIC_FUNC1(Animation_obj,set_animationData,return )

int Animation_obj::SINGLE;

int Animation_obj::LIST_START;

int Animation_obj::LOOP_START;

int Animation_obj::LIST;

int Animation_obj::LOOP;

::hxDragonBones::events::SoundEventManager Animation_obj::_soundManager;


Animation_obj::Animation_obj()
{
}

void Animation_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Animation);
	HX_MARK_MEMBER_NAME(_armature,"_armature");
	HX_MARK_MEMBER_NAME(_breakFrameWhile,"_breakFrameWhile");
	HX_MARK_MEMBER_NAME(_loop,"_loop");
	HX_MARK_MEMBER_NAME(_nextFrameDataID,"_nextFrameDataID");
	HX_MARK_MEMBER_NAME(_nextFrameDataTimeEdge,"_nextFrameDataTimeEdge");
	HX_MARK_MEMBER_NAME(_rawDuration,"_rawDuration");
	HX_MARK_MEMBER_NAME(_duration,"_duration");
	HX_MARK_MEMBER_NAME(_playType,"_playType");
	HX_MARK_MEMBER_NAME(movementData,"movementData");
	HX_MARK_MEMBER_NAME(movementList,"movementList");
	HX_MARK_MEMBER_NAME(movementID,"movementID");
	HX_MARK_MEMBER_NAME(timeScale,"timeScale");
	HX_MARK_MEMBER_NAME(isPause,"isPause");
	HX_MARK_MEMBER_NAME(isComplete,"isComplete");
	HX_MARK_MEMBER_NAME(isPlaying,"isPlaying");
	HX_MARK_MEMBER_NAME(totalTime,"totalTime");
	HX_MARK_MEMBER_NAME(currentTime,"currentTime");
	HX_MARK_MEMBER_NAME(animationData,"animationData");
	HX_MARK_MEMBER_NAME(tweenEnabled,"tweenEnabled");
	HX_MARK_END_CLASS();
}

void Animation_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_armature,"_armature");
	HX_VISIT_MEMBER_NAME(_breakFrameWhile,"_breakFrameWhile");
	HX_VISIT_MEMBER_NAME(_loop,"_loop");
	HX_VISIT_MEMBER_NAME(_nextFrameDataID,"_nextFrameDataID");
	HX_VISIT_MEMBER_NAME(_nextFrameDataTimeEdge,"_nextFrameDataTimeEdge");
	HX_VISIT_MEMBER_NAME(_rawDuration,"_rawDuration");
	HX_VISIT_MEMBER_NAME(_duration,"_duration");
	HX_VISIT_MEMBER_NAME(_playType,"_playType");
	HX_VISIT_MEMBER_NAME(movementData,"movementData");
	HX_VISIT_MEMBER_NAME(movementList,"movementList");
	HX_VISIT_MEMBER_NAME(movementID,"movementID");
	HX_VISIT_MEMBER_NAME(timeScale,"timeScale");
	HX_VISIT_MEMBER_NAME(isPause,"isPause");
	HX_VISIT_MEMBER_NAME(isComplete,"isComplete");
	HX_VISIT_MEMBER_NAME(isPlaying,"isPlaying");
	HX_VISIT_MEMBER_NAME(totalTime,"totalTime");
	HX_VISIT_MEMBER_NAME(currentTime,"currentTime");
	HX_VISIT_MEMBER_NAME(animationData,"animationData");
	HX_VISIT_MEMBER_NAME(tweenEnabled,"tweenEnabled");
}

Dynamic Animation_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"LIST") ) { return LIST; }
		if (HX_FIELD_EQ(inName,"LOOP") ) { return LOOP; }
		if (HX_FIELD_EQ(inName,"stop") ) { return stop_dyn(); }
		if (HX_FIELD_EQ(inName,"play") ) { return play_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_loop") ) { return _loop; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"SINGLE") ) { return SINGLE; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"dispose") ) { return dispose_dyn(); }
		if (HX_FIELD_EQ(inName,"isPause") ) { return inCallProp ? get_isPause() : isPause; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"_armature") ) { return _armature; }
		if (HX_FIELD_EQ(inName,"_duration") ) { return _duration; }
		if (HX_FIELD_EQ(inName,"_playType") ) { return _playType; }
		if (HX_FIELD_EQ(inName,"timeScale") ) { return timeScale; }
		if (HX_FIELD_EQ(inName,"isPlaying") ) { return inCallProp ? get_isPlaying() : isPlaying; }
		if (HX_FIELD_EQ(inName,"totalTime") ) { return totalTime; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"LIST_START") ) { return LIST_START; }
		if (HX_FIELD_EQ(inName,"LOOP_START") ) { return LOOP_START; }
		if (HX_FIELD_EQ(inName,"movementID") ) { return movementID; }
		if (HX_FIELD_EQ(inName,"isComplete") ) { return inCallProp ? get_isComplete() : isComplete; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"advanceTime") ) { return advanceTime_dyn(); }
		if (HX_FIELD_EQ(inName,"gotoAndPlay") ) { return gotoAndPlay_dyn(); }
		if (HX_FIELD_EQ(inName,"get_isPause") ) { return get_isPause_dyn(); }
		if (HX_FIELD_EQ(inName,"currentTime") ) { return currentTime; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"_rawDuration") ) { return _rawDuration; }
		if (HX_FIELD_EQ(inName,"movementData") ) { return movementData; }
		if (HX_FIELD_EQ(inName,"movementList") ) { return inCallProp ? get_movementList() : movementList; }
		if (HX_FIELD_EQ(inName,"tweenEnabled") ) { return tweenEnabled; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"_soundManager") ) { return _soundManager; }
		if (HX_FIELD_EQ(inName,"set_timeScale") ) { return set_timeScale_dyn(); }
		if (HX_FIELD_EQ(inName,"get_isPlaying") ) { return get_isPlaying_dyn(); }
		if (HX_FIELD_EQ(inName,"animationData") ) { return animationData; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"get_isComplete") ) { return get_isComplete_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"arriveFrameData") ) { return arriveFrameData_dyn(); }
		if (HX_FIELD_EQ(inName,"updateFrameData") ) { return updateFrameData_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"get_movementList") ) { return get_movementList_dyn(); }
		if (HX_FIELD_EQ(inName,"_breakFrameWhile") ) { return _breakFrameWhile; }
		if (HX_FIELD_EQ(inName,"_nextFrameDataID") ) { return _nextFrameDataID; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"set_animationData") ) { return set_animationData_dyn(); }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"_nextFrameDataTimeEdge") ) { return _nextFrameDataTimeEdge; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Animation_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"LIST") ) { LIST=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"LOOP") ) { LOOP=inValue.Cast< int >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_loop") ) { _loop=inValue.Cast< int >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"SINGLE") ) { SINGLE=inValue.Cast< int >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"isPause") ) { isPause=inValue.Cast< bool >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"_armature") ) { _armature=inValue.Cast< ::hxDragonBones::Armature >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_duration") ) { _duration=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_playType") ) { _playType=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"timeScale") ) { if (inCallProp) return set_timeScale(inValue);timeScale=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"isPlaying") ) { isPlaying=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"totalTime") ) { totalTime=inValue.Cast< Float >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"LIST_START") ) { LIST_START=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"LOOP_START") ) { LOOP_START=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"movementID") ) { movementID=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"isComplete") ) { isComplete=inValue.Cast< bool >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"currentTime") ) { currentTime=inValue.Cast< Float >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"_rawDuration") ) { _rawDuration=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"movementData") ) { movementData=inValue.Cast< ::hxDragonBones::objects::MovementData >(); return inValue; }
		if (HX_FIELD_EQ(inName,"movementList") ) { movementList=inValue.Cast< Array< ::String > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"tweenEnabled") ) { tweenEnabled=inValue.Cast< bool >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"_soundManager") ) { _soundManager=inValue.Cast< ::hxDragonBones::events::SoundEventManager >(); return inValue; }
		if (HX_FIELD_EQ(inName,"animationData") ) { if (inCallProp) return set_animationData(inValue);animationData=inValue.Cast< ::hxDragonBones::objects::AnimationData >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"_breakFrameWhile") ) { _breakFrameWhile=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_nextFrameDataID") ) { _nextFrameDataID=inValue.Cast< int >(); return inValue; }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"_nextFrameDataTimeEdge") ) { _nextFrameDataTimeEdge=inValue.Cast< Float >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Animation_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_armature"));
	outFields->push(HX_CSTRING("_breakFrameWhile"));
	outFields->push(HX_CSTRING("_loop"));
	outFields->push(HX_CSTRING("_nextFrameDataID"));
	outFields->push(HX_CSTRING("_nextFrameDataTimeEdge"));
	outFields->push(HX_CSTRING("_rawDuration"));
	outFields->push(HX_CSTRING("_duration"));
	outFields->push(HX_CSTRING("_playType"));
	outFields->push(HX_CSTRING("movementData"));
	outFields->push(HX_CSTRING("movementList"));
	outFields->push(HX_CSTRING("movementID"));
	outFields->push(HX_CSTRING("timeScale"));
	outFields->push(HX_CSTRING("isPause"));
	outFields->push(HX_CSTRING("isComplete"));
	outFields->push(HX_CSTRING("isPlaying"));
	outFields->push(HX_CSTRING("totalTime"));
	outFields->push(HX_CSTRING("currentTime"));
	outFields->push(HX_CSTRING("animationData"));
	outFields->push(HX_CSTRING("tweenEnabled"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("SINGLE"),
	HX_CSTRING("LIST_START"),
	HX_CSTRING("LOOP_START"),
	HX_CSTRING("LIST"),
	HX_CSTRING("LOOP"),
	HX_CSTRING("_soundManager"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("arriveFrameData"),
	HX_CSTRING("updateFrameData"),
	HX_CSTRING("advanceTime"),
	HX_CSTRING("stop"),
	HX_CSTRING("play"),
	HX_CSTRING("gotoAndPlay"),
	HX_CSTRING("dispose"),
	HX_CSTRING("get_movementList"),
	HX_CSTRING("set_timeScale"),
	HX_CSTRING("get_isPause"),
	HX_CSTRING("get_isComplete"),
	HX_CSTRING("get_isPlaying"),
	HX_CSTRING("set_animationData"),
	HX_CSTRING("_armature"),
	HX_CSTRING("_breakFrameWhile"),
	HX_CSTRING("_loop"),
	HX_CSTRING("_nextFrameDataID"),
	HX_CSTRING("_nextFrameDataTimeEdge"),
	HX_CSTRING("_rawDuration"),
	HX_CSTRING("_duration"),
	HX_CSTRING("_playType"),
	HX_CSTRING("movementData"),
	HX_CSTRING("movementList"),
	HX_CSTRING("movementID"),
	HX_CSTRING("timeScale"),
	HX_CSTRING("isPause"),
	HX_CSTRING("isComplete"),
	HX_CSTRING("isPlaying"),
	HX_CSTRING("totalTime"),
	HX_CSTRING("currentTime"),
	HX_CSTRING("animationData"),
	HX_CSTRING("tweenEnabled"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Animation_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(Animation_obj::SINGLE,"SINGLE");
	HX_MARK_MEMBER_NAME(Animation_obj::LIST_START,"LIST_START");
	HX_MARK_MEMBER_NAME(Animation_obj::LOOP_START,"LOOP_START");
	HX_MARK_MEMBER_NAME(Animation_obj::LIST,"LIST");
	HX_MARK_MEMBER_NAME(Animation_obj::LOOP,"LOOP");
	HX_MARK_MEMBER_NAME(Animation_obj::_soundManager,"_soundManager");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Animation_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Animation_obj::SINGLE,"SINGLE");
	HX_VISIT_MEMBER_NAME(Animation_obj::LIST_START,"LIST_START");
	HX_VISIT_MEMBER_NAME(Animation_obj::LOOP_START,"LOOP_START");
	HX_VISIT_MEMBER_NAME(Animation_obj::LIST,"LIST");
	HX_VISIT_MEMBER_NAME(Animation_obj::LOOP,"LOOP");
	HX_VISIT_MEMBER_NAME(Animation_obj::_soundManager,"_soundManager");
};

Class Animation_obj::__mClass;

void Animation_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("hxDragonBones.animation.Animation"), hx::TCanCast< Animation_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Animation_obj::__boot()
{
	SINGLE= (int)0;
	LIST_START= (int)1;
	LOOP_START= (int)2;
	LIST= (int)3;
	LOOP= (int)4;
	_soundManager= ::hxDragonBones::events::SoundEventManager_obj::get_instance();
}

} // end namespace hxDragonBones
} // end namespace animation
