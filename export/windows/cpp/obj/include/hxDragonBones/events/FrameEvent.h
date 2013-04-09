#ifndef INCLUDED_hxDragonBones_events_FrameEvent
#define INCLUDED_hxDragonBones_events_FrameEvent

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <native/events/Event.h>
HX_DECLARE_CLASS1(hxDragonBones,Armature)
HX_DECLARE_CLASS1(hxDragonBones,Bone)
HX_DECLARE_CLASS2(hxDragonBones,animation,IAnimatable)
HX_DECLARE_CLASS2(hxDragonBones,events,FrameEvent)
HX_DECLARE_CLASS2(hxDragonBones,utils,IDisposable)
HX_DECLARE_CLASS2(native,events,Event)
HX_DECLARE_CLASS2(native,events,EventDispatcher)
HX_DECLARE_CLASS2(native,events,IEventDispatcher)
namespace hxDragonBones{
namespace events{


class FrameEvent_obj : public ::native::events::Event_obj{
	public:
		typedef ::native::events::Event_obj super;
		typedef FrameEvent_obj OBJ_;
		FrameEvent_obj();
		Void __construct(::String type,hx::Null< bool >  __o_bubbles,hx::Null< bool >  __o_cancelable,::hxDragonBones::Bone bone);

	public:
		static hx::ObjectPtr< FrameEvent_obj > __new(::String type,hx::Null< bool >  __o_bubbles,hx::Null< bool >  __o_cancelable,::hxDragonBones::Bone bone);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~FrameEvent_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("FrameEvent"); }

		virtual ::native::events::Event clone( );

		virtual ::hxDragonBones::Armature get_armature( );
		Dynamic get_armature_dyn();

		::hxDragonBones::Bone bone; /* REM */ 
		::hxDragonBones::Armature armature; /* REM */ 
		::String frameLabel; /* REM */ 
		::String movementID; /* REM */ 
		static ::String MOVEMENT_FRAME_EVENT; /* REM */ 
		static ::String BONE_FRAME_EVENT; /* REM */ 
};

} // end namespace hxDragonBones
} // end namespace events

#endif /* INCLUDED_hxDragonBones_events_FrameEvent */ 
