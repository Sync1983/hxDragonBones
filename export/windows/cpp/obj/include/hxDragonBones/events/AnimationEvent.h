#ifndef INCLUDED_hxDragonBones_events_AnimationEvent
#define INCLUDED_hxDragonBones_events_AnimationEvent

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <native/events/Event.h>
HX_DECLARE_CLASS1(hxDragonBones,Armature)
HX_DECLARE_CLASS2(hxDragonBones,animation,IAnimatable)
HX_DECLARE_CLASS2(hxDragonBones,events,AnimationEvent)
HX_DECLARE_CLASS2(hxDragonBones,utils,IDisposable)
HX_DECLARE_CLASS2(native,events,Event)
HX_DECLARE_CLASS2(native,events,EventDispatcher)
HX_DECLARE_CLASS2(native,events,IEventDispatcher)
namespace hxDragonBones{
namespace events{


class AnimationEvent_obj : public ::native::events::Event_obj{
	public:
		typedef ::native::events::Event_obj super;
		typedef AnimationEvent_obj OBJ_;
		AnimationEvent_obj();
		Void __construct(::String type,hx::Null< bool >  __o_bubbles,hx::Null< bool >  __o_cancelable);

	public:
		static hx::ObjectPtr< AnimationEvent_obj > __new(::String type,hx::Null< bool >  __o_bubbles,hx::Null< bool >  __o_cancelable);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~AnimationEvent_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("AnimationEvent"); }

		virtual ::native::events::Event clone( );

		virtual ::hxDragonBones::Armature get_armature( );
		Dynamic get_armature_dyn();

		::hxDragonBones::Armature armature; /* REM */ 
		::String movementID; /* REM */ 
		::String exMovementID; /* REM */ 
		static ::String MOVEMENT_CHANGE; /* REM */ 
		static ::String START; /* REM */ 
		static ::String COMPLETE; /* REM */ 
		static ::String LOOP_COMPLETE; /* REM */ 
};

} // end namespace hxDragonBones
} // end namespace events

#endif /* INCLUDED_hxDragonBones_events_AnimationEvent */ 
