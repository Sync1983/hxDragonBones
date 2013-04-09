#include <hxcpp.h>

#ifndef INCLUDED_List
#include <List.h>
#endif
#ifndef INCLUDED_haxe_TypeTools
#include <haxe/TypeTools.h>
#endif
#ifndef INCLUDED_haxe_exception_ArgumentNullException
#include <haxe/exception/ArgumentNullException.h>
#endif
#ifndef INCLUDED_haxe_exception_Exception
#include <haxe/exception/Exception.h>
#endif
#ifndef INCLUDED_hsl_haxe_Bond
#include <hsl/haxe/Bond.h>
#endif
#ifndef INCLUDED_hsl_haxe_DirectSignaler
#include <hsl/haxe/DirectSignaler.h>
#endif
#ifndef INCLUDED_hsl_haxe_Signal
#include <hsl/haxe/Signal.h>
#endif
#ifndef INCLUDED_hsl_haxe_Signaler
#include <hsl/haxe/Signaler.h>
#endif
#ifndef INCLUDED_hsl_haxe__DirectSignaler_AdvancedBond
#include <hsl/haxe/_DirectSignaler/AdvancedBond.h>
#endif
#ifndef INCLUDED_hsl_haxe__DirectSignaler_LinkedBond
#include <hsl/haxe/_DirectSignaler/LinkedBond.h>
#endif
#ifndef INCLUDED_hsl_haxe__DirectSignaler_NiladicBond
#include <hsl/haxe/_DirectSignaler/NiladicBond.h>
#endif
#ifndef INCLUDED_hsl_haxe__DirectSignaler_RegularBond
#include <hsl/haxe/_DirectSignaler/RegularBond.h>
#endif
#ifndef INCLUDED_hsl_haxe__DirectSignaler_SentinelBond
#include <hsl/haxe/_DirectSignaler/SentinelBond.h>
#endif
namespace hsl{
namespace haxe{

Void DirectSignaler_obj::__construct(Dynamic subject,Dynamic rejectNullData)
{
HX_STACK_PUSH("DirectSignaler::new","hsl/haxe/DirectSignaler.hx",54);
{
	HX_STACK_LINE(57)
	if (((null() == subject))){
		HX_STACK_LINE(57)
		hx::Throw (::haxe::exception::ArgumentNullException_obj::__new(HX_CSTRING("subject"),(int)1));
	}
	HX_STACK_LINE(60)
	this->subject = subject;
	HX_STACK_LINE(61)
	this->rejectNullData = rejectNullData;
	HX_STACK_LINE(62)
	this->sentinel = ::hsl::haxe::_DirectSignaler::SentinelBond_obj::__new();
}
;
	return null();
}

DirectSignaler_obj::~DirectSignaler_obj() { }

Dynamic DirectSignaler_obj::__CreateEmpty() { return  new DirectSignaler_obj; }
hx::ObjectPtr< DirectSignaler_obj > DirectSignaler_obj::__new(Dynamic subject,Dynamic rejectNullData)
{  hx::ObjectPtr< DirectSignaler_obj > result = new DirectSignaler_obj();
	result->__construct(subject,rejectNullData);
	return result;}

Dynamic DirectSignaler_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< DirectSignaler_obj > result = new DirectSignaler_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

hx::Object *DirectSignaler_obj::__ToInterface(const type_info &inType) {
	if (inType==typeid( ::hsl::haxe::Signaler_obj)) return operator ::hsl::haxe::Signaler_obj *();
	return super::__ToInterface(inType);
}

Void DirectSignaler_obj::unbindVoid( Dynamic listener){
{
		HX_STACK_PUSH("DirectSignaler::unbindVoid","hsl/haxe/DirectSignaler.hx",221);
		HX_STACK_THIS(this);
		HX_STACK_ARG(listener,"listener");
		HX_STACK_LINE(222)
		::hsl::haxe::_DirectSignaler::SentinelBond _this = this->sentinel;		HX_STACK_VAR(_this,"_this");
		::hsl::haxe::_DirectSignaler::LinkedBond value = ::hsl::haxe::_DirectSignaler::NiladicBond_obj::__new(listener);		HX_STACK_VAR(value,"value");
		HX_STACK_LINE(222)
		::hsl::haxe::_DirectSignaler::LinkedBond node = _this->next;		HX_STACK_VAR(node,"node");
		HX_STACK_LINE(222)
		while(((node != _this))){
			HX_STACK_LINE(222)
			if ((node->determineEquals(value))){
				HX_STACK_LINE(222)
				if (((false == node->destroyed))){
					HX_STACK_LINE(222)
					node->previous->next = node->next;
					HX_STACK_LINE(222)
					node->next->previous = node->previous;
					HX_STACK_LINE(222)
					node->destroyed = true;
				}
				HX_STACK_LINE(222)
				break;
			}
			HX_STACK_LINE(222)
			node = node->next;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(DirectSignaler_obj,unbindVoid,(void))

Void DirectSignaler_obj::unbindAdvanced( Dynamic _tmp_listener){
{
		HX_STACK_PUSH("DirectSignaler::unbindAdvanced","hsl/haxe/DirectSignaler.hx",218);
		HX_STACK_THIS(this);
		HX_STACK_ARG(_tmp_listener,"_tmp_listener");
		HX_STACK_LINE(219)
		Dynamic listener = _tmp_listener;		HX_STACK_VAR(listener,"listener");
		HX_STACK_LINE(219)
		::hsl::haxe::_DirectSignaler::SentinelBond _this = this->sentinel;		HX_STACK_VAR(_this,"_this");
		::hsl::haxe::_DirectSignaler::LinkedBond value = ::hsl::haxe::_DirectSignaler::AdvancedBond_obj::__new(listener);		HX_STACK_VAR(value,"value");
		HX_STACK_LINE(219)
		::hsl::haxe::_DirectSignaler::LinkedBond node = _this->next;		HX_STACK_VAR(node,"node");
		HX_STACK_LINE(219)
		while(((node != _this))){
			HX_STACK_LINE(219)
			if ((node->determineEquals(value))){
				HX_STACK_LINE(219)
				if (((false == node->destroyed))){
					HX_STACK_LINE(219)
					node->previous->next = node->next;
					HX_STACK_LINE(219)
					node->next->previous = node->previous;
					HX_STACK_LINE(219)
					node->destroyed = true;
				}
				HX_STACK_LINE(219)
				break;
			}
			HX_STACK_LINE(219)
			node = node->next;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(DirectSignaler_obj,unbindAdvanced,(void))

Void DirectSignaler_obj::unbind( Dynamic _tmp_listener){
{
		HX_STACK_PUSH("DirectSignaler::unbind","hsl/haxe/DirectSignaler.hx",215);
		HX_STACK_THIS(this);
		HX_STACK_ARG(_tmp_listener,"_tmp_listener");
		HX_STACK_LINE(216)
		Dynamic listener = _tmp_listener;		HX_STACK_VAR(listener,"listener");
		HX_STACK_LINE(216)
		::hsl::haxe::_DirectSignaler::SentinelBond _this = this->sentinel;		HX_STACK_VAR(_this,"_this");
		::hsl::haxe::_DirectSignaler::LinkedBond value = ::hsl::haxe::_DirectSignaler::RegularBond_obj::__new(listener);		HX_STACK_VAR(value,"value");
		HX_STACK_LINE(216)
		::hsl::haxe::_DirectSignaler::LinkedBond node = _this->next;		HX_STACK_VAR(node,"node");
		HX_STACK_LINE(216)
		while(((node != _this))){
			HX_STACK_LINE(216)
			if ((node->determineEquals(value))){
				HX_STACK_LINE(216)
				if (((false == node->destroyed))){
					HX_STACK_LINE(216)
					node->previous->next = node->next;
					HX_STACK_LINE(216)
					node->next->previous = node->previous;
					HX_STACK_LINE(216)
					node->destroyed = true;
				}
				HX_STACK_LINE(216)
				break;
			}
			HX_STACK_LINE(216)
			node = node->next;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(DirectSignaler_obj,unbind,(void))

Void DirectSignaler_obj::removeNotificationTarget( ::hsl::haxe::Signaler value){
{
		HX_STACK_PUSH("DirectSignaler::removeNotificationTarget","hsl/haxe/DirectSignaler.hx",205);
		HX_STACK_THIS(this);
		HX_STACK_ARG(value,"value");
		HX_STACK_LINE(205)
		if (((null() != this->notificationTargets))){
			HX_STACK_LINE(206)
			this->notificationTargets->remove(value);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(DirectSignaler_obj,removeNotificationTarget,(void))

Void DirectSignaler_obj::removeBubblingTarget( ::hsl::haxe::Signaler _tmp_value){
{
		HX_STACK_PUSH("DirectSignaler::removeBubblingTarget","hsl/haxe/DirectSignaler.hx",200);
		HX_STACK_THIS(this);
		HX_STACK_ARG(_tmp_value,"_tmp_value");
		HX_STACK_LINE(200)
		::hsl::haxe::Signaler value = _tmp_value;		HX_STACK_VAR(value,"value");
		HX_STACK_LINE(200)
		if (((null() != this->bubblingTargets))){
			HX_STACK_LINE(201)
			this->bubblingTargets->remove(value);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(DirectSignaler_obj,removeBubblingTarget,(void))

Void DirectSignaler_obj::verifyCaller( Dynamic positionInformation){
{
		HX_STACK_PUSH("DirectSignaler::verifyCaller","hsl/haxe/DirectSignaler.hx",188);
		HX_STACK_THIS(this);
		HX_STACK_ARG(positionInformation,"positionInformation");
		HX_STACK_LINE(189)
		if (((null() == this->subjectClassNames))){
			HX_STACK_LINE(189)
			this->subjectClassNames = ::haxe::TypeTools_obj::getClassNames(this->subject);
		}
		HX_STACK_LINE(192)
		for(::cpp::FastIterator_obj< ::String > *__it = ::cpp::CreateFastIterator< ::String >(this->subjectClassNames->iterator());  __it->hasNext(); ){
			::String subjectClassName = __it->next();
			if (((subjectClassName == positionInformation->__Field(HX_CSTRING("className"),true)))){
				HX_STACK_LINE(193)
				return null();
			}
;
		}
		HX_STACK_LINE(197)
		hx::Throw (::haxe::exception::Exception_obj::__new(HX_CSTRING("This method may only be called by the subject of the signaler."),null(),(int)2));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(DirectSignaler_obj,verifyCaller,(void))

Dynamic DirectSignaler_obj::getOrigin( Dynamic origin){
	HX_STACK_PUSH("DirectSignaler::getOrigin","hsl/haxe/DirectSignaler.hx",168);
	HX_STACK_THIS(this);
	HX_STACK_ARG(origin,"origin");
	HX_STACK_LINE(168)
	return (  (((null() == origin))) ? Dynamic(this->subject) : Dynamic(origin) );
}


HX_DEFINE_DYNAMIC_FUNC1(DirectSignaler_obj,getOrigin,return )

bool DirectSignaler_obj::getIsListenedTo( ){
	HX_STACK_PUSH("DirectSignaler::getIsListenedTo","hsl/haxe/DirectSignaler.hx",162);
	HX_STACK_THIS(this);
	struct _Function_1_1{
		inline static bool Block( ::hsl::haxe::DirectSignaler_obj *__this){
			HX_STACK_PUSH("*::closure","hsl/haxe/DirectSignaler.hx",163);
			{
				HX_STACK_LINE(163)
				::hsl::haxe::_DirectSignaler::SentinelBond _this = __this->sentinel;		HX_STACK_VAR(_this,"_this");
				HX_STACK_LINE(163)
				return (_this->next != _this);
			}
			return null();
		}
	};
	HX_STACK_LINE(162)
	return _Function_1_1::Block(this);
}


HX_DEFINE_DYNAMIC_FUNC0(DirectSignaler_obj,getIsListenedTo,return )

Void DirectSignaler_obj::dispatch( Dynamic _tmp_data,Dynamic origin,Dynamic positionInformation){
{
		HX_STACK_PUSH("DirectSignaler::dispatch","hsl/haxe/DirectSignaler.hx",121);
		HX_STACK_THIS(this);
		HX_STACK_ARG(_tmp_data,"_tmp_data");
		HX_STACK_ARG(origin,"origin");
		HX_STACK_ARG(positionInformation,"positionInformation");
		HX_STACK_LINE(146)
		Dynamic data = _tmp_data;		HX_STACK_VAR(data,"data");
		HX_STACK_LINE(146)
		if (((bool((HX_CSTRING("dispatchNative") != positionInformation->__Field(HX_CSTRING("methodName"),true))) && bool((HX_CSTRING("bubble") != positionInformation->__Field(HX_CSTRING("methodName"),true)))))){
			HX_STACK_LINE(146)
			this->verifyCaller(positionInformation);
		}
		HX_STACK_LINE(152)
		if (((bool(this->rejectNullData) && bool((null() == data))))){
			HX_STACK_LINE(152)
			hx::Throw (::haxe::exception::Exception_obj::__new(HX_CSTRING("Some data that was passed is null, but this signaler has been set to reject null data."),null(),(int)1));
		}
		HX_STACK_LINE(156)
		origin = (  (((null() == origin))) ? Dynamic(this->subject) : Dynamic(origin) );
		HX_STACK_LINE(158)
		if ((((int)3 == this->sentinel->callListener(data,this->subject,origin,(int)3)))){
			HX_STACK_LINE(159)
			if (((null() != this->bubblingTargets))){
				HX_STACK_LINE(159)
				for(::cpp::FastIterator_obj< ::hsl::haxe::Signaler > *__it = ::cpp::CreateFastIterator< ::hsl::haxe::Signaler >(this->bubblingTargets->iterator());  __it->hasNext(); ){
					::hsl::haxe::Signaler bubblingTarget = __it->next();
					bubblingTarget->dispatch(data,origin,hx::SourceInfo(HX_CSTRING("DirectSignaler.hx"),109,HX_CSTRING("hsl.haxe.DirectSignaler"),HX_CSTRING("bubble")));
				}
			}
			HX_STACK_LINE(159)
			if (((null() != this->notificationTargets))){
				HX_STACK_LINE(159)
				for(::cpp::FastIterator_obj< ::hsl::haxe::Signaler > *__it = ::cpp::CreateFastIterator< ::hsl::haxe::Signaler >(this->notificationTargets->iterator());  __it->hasNext(); ){
					::hsl::haxe::Signaler notificationTarget = __it->next();
					notificationTarget->dispatch(null(),origin,hx::SourceInfo(HX_CSTRING("DirectSignaler.hx"),114,HX_CSTRING("hsl.haxe.DirectSignaler"),HX_CSTRING("bubble")));
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(DirectSignaler_obj,dispatch,(void))

Void DirectSignaler_obj::bubble( Dynamic data,Dynamic origin){
{
		HX_STACK_PUSH("DirectSignaler::bubble","hsl/haxe/DirectSignaler.hx",106);
		HX_STACK_THIS(this);
		HX_STACK_ARG(data,"data");
		HX_STACK_ARG(origin,"origin");
		HX_STACK_LINE(107)
		if (((null() != this->bubblingTargets))){
			HX_STACK_LINE(107)
			for(::cpp::FastIterator_obj< ::hsl::haxe::Signaler > *__it = ::cpp::CreateFastIterator< ::hsl::haxe::Signaler >(this->bubblingTargets->iterator());  __it->hasNext(); ){
				::hsl::haxe::Signaler bubblingTarget = __it->next();
				bubblingTarget->dispatch(data,origin,hx::SourceInfo(HX_CSTRING("DirectSignaler.hx"),109,HX_CSTRING("hsl.haxe.DirectSignaler"),HX_CSTRING("bubble")));
			}
		}
		HX_STACK_LINE(112)
		if (((null() != this->notificationTargets))){
			HX_STACK_LINE(112)
			for(::cpp::FastIterator_obj< ::hsl::haxe::Signaler > *__it = ::cpp::CreateFastIterator< ::hsl::haxe::Signaler >(this->notificationTargets->iterator());  __it->hasNext(); ){
				::hsl::haxe::Signaler notificationTarget = __it->next();
				notificationTarget->dispatch(null(),origin,hx::SourceInfo(HX_CSTRING("DirectSignaler.hx"),114,HX_CSTRING("hsl.haxe.DirectSignaler"),HX_CSTRING("bubble")));
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(DirectSignaler_obj,bubble,(void))

::hsl::haxe::Bond DirectSignaler_obj::bindVoid( Dynamic listener){
	HX_STACK_PUSH("DirectSignaler::bindVoid","hsl/haxe/DirectSignaler.hx",96);
	HX_STACK_THIS(this);
	HX_STACK_ARG(listener,"listener");
	HX_STACK_LINE(100)
	if (((null() == listener))){
		HX_STACK_LINE(100)
		hx::Throw (::haxe::exception::ArgumentNullException_obj::__new(HX_CSTRING("listener"),(int)1));
	}
	struct _Function_1_1{
		inline static ::hsl::haxe::_DirectSignaler::LinkedBond Block( ::hsl::haxe::DirectSignaler_obj *__this,Dynamic &listener){
			HX_STACK_PUSH("*::closure","hsl/haxe/DirectSignaler.hx",104);
			{
				HX_STACK_LINE(104)
				::hsl::haxe::_DirectSignaler::SentinelBond _this = __this->sentinel;		HX_STACK_VAR(_this,"_this");
				::hsl::haxe::_DirectSignaler::LinkedBond value = ::hsl::haxe::_DirectSignaler::NiladicBond_obj::__new(listener);		HX_STACK_VAR(value,"value");
				HX_STACK_LINE(104)
				value->next = _this;
				HX_STACK_LINE(104)
				value->previous = _this->previous;
				HX_STACK_LINE(104)
				return _this->previous = _this->previous->next = value;
			}
			return null();
		}
	};
	HX_STACK_LINE(104)
	return _Function_1_1::Block(this,listener);
}


HX_DEFINE_DYNAMIC_FUNC1(DirectSignaler_obj,bindVoid,return )

::hsl::haxe::Bond DirectSignaler_obj::bindAdvanced( Dynamic _tmp_listener){
	HX_STACK_PUSH("DirectSignaler::bindAdvanced","hsl/haxe/DirectSignaler.hx",86);
	HX_STACK_THIS(this);
	HX_STACK_ARG(_tmp_listener,"_tmp_listener");
	HX_STACK_LINE(90)
	Dynamic listener = _tmp_listener;		HX_STACK_VAR(listener,"listener");
	HX_STACK_LINE(90)
	if (((null() == listener))){
		HX_STACK_LINE(90)
		hx::Throw (::haxe::exception::ArgumentNullException_obj::__new(HX_CSTRING("listener"),(int)1));
	}
	struct _Function_1_1{
		inline static ::hsl::haxe::_DirectSignaler::LinkedBond Block( ::hsl::haxe::DirectSignaler_obj *__this,Dynamic &listener){
			HX_STACK_PUSH("*::closure","hsl/haxe/DirectSignaler.hx",94);
			{
				HX_STACK_LINE(94)
				::hsl::haxe::_DirectSignaler::SentinelBond _this = __this->sentinel;		HX_STACK_VAR(_this,"_this");
				::hsl::haxe::_DirectSignaler::LinkedBond value = ::hsl::haxe::_DirectSignaler::AdvancedBond_obj::__new(listener);		HX_STACK_VAR(value,"value");
				HX_STACK_LINE(94)
				value->next = _this;
				HX_STACK_LINE(94)
				value->previous = _this->previous;
				HX_STACK_LINE(94)
				return _this->previous = _this->previous->next = value;
			}
			return null();
		}
	};
	HX_STACK_LINE(94)
	return _Function_1_1::Block(this,listener);
}


HX_DEFINE_DYNAMIC_FUNC1(DirectSignaler_obj,bindAdvanced,return )

::hsl::haxe::Bond DirectSignaler_obj::bind( Dynamic _tmp_listener){
	HX_STACK_PUSH("DirectSignaler::bind","hsl/haxe/DirectSignaler.hx",76);
	HX_STACK_THIS(this);
	HX_STACK_ARG(_tmp_listener,"_tmp_listener");
	HX_STACK_LINE(80)
	Dynamic listener = _tmp_listener;		HX_STACK_VAR(listener,"listener");
	HX_STACK_LINE(80)
	if (((null() == listener))){
		HX_STACK_LINE(80)
		hx::Throw (::haxe::exception::ArgumentNullException_obj::__new(HX_CSTRING("listener"),(int)1));
	}
	struct _Function_1_1{
		inline static ::hsl::haxe::_DirectSignaler::LinkedBond Block( ::hsl::haxe::DirectSignaler_obj *__this,Dynamic &listener){
			HX_STACK_PUSH("*::closure","hsl/haxe/DirectSignaler.hx",84);
			{
				HX_STACK_LINE(84)
				::hsl::haxe::_DirectSignaler::SentinelBond _this = __this->sentinel;		HX_STACK_VAR(_this,"_this");
				::hsl::haxe::_DirectSignaler::LinkedBond value = ::hsl::haxe::_DirectSignaler::RegularBond_obj::__new(listener);		HX_STACK_VAR(value,"value");
				HX_STACK_LINE(84)
				value->next = _this;
				HX_STACK_LINE(84)
				value->previous = _this->previous;
				HX_STACK_LINE(84)
				return _this->previous = _this->previous->next = value;
			}
			return null();
		}
	};
	HX_STACK_LINE(84)
	return _Function_1_1::Block(this,listener);
}


HX_DEFINE_DYNAMIC_FUNC1(DirectSignaler_obj,bind,return )

Void DirectSignaler_obj::addNotificationTarget( ::hsl::haxe::Signaler value){
{
		HX_STACK_PUSH("DirectSignaler::addNotificationTarget","hsl/haxe/DirectSignaler.hx",70);
		HX_STACK_THIS(this);
		HX_STACK_ARG(value,"value");
		HX_STACK_LINE(71)
		if (((null() == this->notificationTargets))){
			HX_STACK_LINE(71)
			this->notificationTargets = ::List_obj::__new();
		}
		HX_STACK_LINE(74)
		this->notificationTargets->add(value);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(DirectSignaler_obj,addNotificationTarget,(void))

Void DirectSignaler_obj::addBubblingTarget( ::hsl::haxe::Signaler _tmp_value){
{
		HX_STACK_PUSH("DirectSignaler::addBubblingTarget","hsl/haxe/DirectSignaler.hx",64);
		HX_STACK_THIS(this);
		HX_STACK_ARG(_tmp_value,"_tmp_value");
		HX_STACK_LINE(65)
		::hsl::haxe::Signaler value = _tmp_value;		HX_STACK_VAR(value,"value");
		HX_STACK_LINE(65)
		if (((null() == this->bubblingTargets))){
			HX_STACK_LINE(65)
			this->bubblingTargets = ::List_obj::__new();
		}
		HX_STACK_LINE(68)
		this->bubblingTargets->add(value);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(DirectSignaler_obj,addBubblingTarget,(void))


DirectSignaler_obj::DirectSignaler_obj()
{
}

void DirectSignaler_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(DirectSignaler);
	HX_MARK_MEMBER_NAME(subjectClassNames,"subjectClassNames");
	HX_MARK_MEMBER_NAME(subject,"subject");
	HX_MARK_MEMBER_NAME(sentinel,"sentinel");
	HX_MARK_MEMBER_NAME(rejectNullData,"rejectNullData");
	HX_MARK_MEMBER_NAME(notificationTargets,"notificationTargets");
	HX_MARK_MEMBER_NAME(isListenedTo,"isListenedTo");
	HX_MARK_MEMBER_NAME(bubblingTargets,"bubblingTargets");
	HX_MARK_END_CLASS();
}

void DirectSignaler_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(subjectClassNames,"subjectClassNames");
	HX_VISIT_MEMBER_NAME(subject,"subject");
	HX_VISIT_MEMBER_NAME(sentinel,"sentinel");
	HX_VISIT_MEMBER_NAME(rejectNullData,"rejectNullData");
	HX_VISIT_MEMBER_NAME(notificationTargets,"notificationTargets");
	HX_VISIT_MEMBER_NAME(isListenedTo,"isListenedTo");
	HX_VISIT_MEMBER_NAME(bubblingTargets,"bubblingTargets");
}

Dynamic DirectSignaler_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"bind") ) { return bind_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"unbind") ) { return unbind_dyn(); }
		if (HX_FIELD_EQ(inName,"bubble") ) { return bubble_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"subject") ) { return subject; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"dispatch") ) { return dispatch_dyn(); }
		if (HX_FIELD_EQ(inName,"bindVoid") ) { return bindVoid_dyn(); }
		if (HX_FIELD_EQ(inName,"sentinel") ) { return sentinel; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"getOrigin") ) { return getOrigin_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"unbindVoid") ) { return unbindVoid_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"verifyCaller") ) { return verifyCaller_dyn(); }
		if (HX_FIELD_EQ(inName,"bindAdvanced") ) { return bindAdvanced_dyn(); }
		if (HX_FIELD_EQ(inName,"isListenedTo") ) { return inCallProp ? getIsListenedTo() : isListenedTo; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"unbindAdvanced") ) { return unbindAdvanced_dyn(); }
		if (HX_FIELD_EQ(inName,"rejectNullData") ) { return rejectNullData; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"getIsListenedTo") ) { return getIsListenedTo_dyn(); }
		if (HX_FIELD_EQ(inName,"bubblingTargets") ) { return bubblingTargets; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"addBubblingTarget") ) { return addBubblingTarget_dyn(); }
		if (HX_FIELD_EQ(inName,"subjectClassNames") ) { return subjectClassNames; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"notificationTargets") ) { return notificationTargets; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"removeBubblingTarget") ) { return removeBubblingTarget_dyn(); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"addNotificationTarget") ) { return addNotificationTarget_dyn(); }
		break;
	case 24:
		if (HX_FIELD_EQ(inName,"removeNotificationTarget") ) { return removeNotificationTarget_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic DirectSignaler_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"subject") ) { subject=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"sentinel") ) { sentinel=inValue.Cast< ::hsl::haxe::_DirectSignaler::SentinelBond >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"isListenedTo") ) { isListenedTo=inValue.Cast< bool >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"rejectNullData") ) { rejectNullData=inValue.Cast< bool >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"bubblingTargets") ) { bubblingTargets=inValue.Cast< ::List >(); return inValue; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"subjectClassNames") ) { subjectClassNames=inValue.Cast< ::List >(); return inValue; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"notificationTargets") ) { notificationTargets=inValue.Cast< ::List >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void DirectSignaler_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("subjectClassNames"));
	outFields->push(HX_CSTRING("subject"));
	outFields->push(HX_CSTRING("sentinel"));
	outFields->push(HX_CSTRING("rejectNullData"));
	outFields->push(HX_CSTRING("notificationTargets"));
	outFields->push(HX_CSTRING("isListenedTo"));
	outFields->push(HX_CSTRING("bubblingTargets"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("unbindVoid"),
	HX_CSTRING("unbindAdvanced"),
	HX_CSTRING("unbind"),
	HX_CSTRING("removeNotificationTarget"),
	HX_CSTRING("removeBubblingTarget"),
	HX_CSTRING("verifyCaller"),
	HX_CSTRING("getOrigin"),
	HX_CSTRING("getIsListenedTo"),
	HX_CSTRING("dispatch"),
	HX_CSTRING("bubble"),
	HX_CSTRING("bindVoid"),
	HX_CSTRING("bindAdvanced"),
	HX_CSTRING("bind"),
	HX_CSTRING("addNotificationTarget"),
	HX_CSTRING("addBubblingTarget"),
	HX_CSTRING("subjectClassNames"),
	HX_CSTRING("subject"),
	HX_CSTRING("sentinel"),
	HX_CSTRING("rejectNullData"),
	HX_CSTRING("notificationTargets"),
	HX_CSTRING("isListenedTo"),
	HX_CSTRING("bubblingTargets"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(DirectSignaler_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(DirectSignaler_obj::__mClass,"__mClass");
};

Class DirectSignaler_obj::__mClass;

void DirectSignaler_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("hsl.haxe.DirectSignaler"), hx::TCanCast< DirectSignaler_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void DirectSignaler_obj::__boot()
{
}

} // end namespace hsl
} // end namespace haxe
