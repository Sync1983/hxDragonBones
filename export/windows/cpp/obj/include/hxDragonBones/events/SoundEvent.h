#ifndef INCLUDED_hxDragonBones_events_SoundEvent
#define INCLUDED_hxDragonBones_events_SoundEvent

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <native/events/Event.h>
HX_DECLARE_CLASS1(hxDragonBones,Armature)
HX_DECLARE_CLASS1(hxDragonBones,Bone)
HX_DECLARE_CLASS2(hxDragonBones,animation,IAnimatable)
HX_DECLARE_CLASS2(hxDragonBones,events,SoundEvent)
HX_DECLARE_CLASS2(hxDragonBones,utils,IDisposable)
HX_DECLARE_CLASS2(native,events,Event)
HX_DECLARE_CLASS2(native,events,EventDispatcher)
HX_DECLARE_CLASS2(native,events,IEventDispatcher)
namespace hxDragonBones{
namespace events{


class SoundEvent_obj : public ::native::events::Event_obj{
	public:
		typedef ::native::events::Event_obj super;
		typedef SoundEvent_obj OBJ_;
		SoundEvent_obj();
		Void __construct(::String type,hx::Null< bool >  __o_cancelable);

	public:
		static hx::ObjectPtr< SoundEvent_obj > __new(::String type,hx::Null< bool >  __o_cancelable);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~SoundEvent_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("SoundEvent"); }

		virtual ::native::events::Event clone( );

		::hxDragonBones::Bone bone; /* REM */ 
		::hxDragonBones::Armature armature; /* REM */ 
		::String soundEffect; /* REM */ 
		::String sound; /* REM */ 
		::String movementID; /* REM */ 
		static ::String SOUND; /* REM */ 
};

} // end namespace hxDragonBones
} // end namespace events

#endif /* INCLUDED_hxDragonBones_events_SoundEvent */ 
