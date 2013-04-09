#ifndef INCLUDED_hxDragonBones_events_SoundEventManager
#define INCLUDED_hxDragonBones_events_SoundEventManager

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <native/events/EventDispatcher.h>
HX_DECLARE_CLASS2(hxDragonBones,events,SoundEventManager)
HX_DECLARE_CLASS2(native,events,EventDispatcher)
HX_DECLARE_CLASS2(native,events,IEventDispatcher)
namespace hxDragonBones{
namespace events{


class SoundEventManager_obj : public ::native::events::EventDispatcher_obj{
	public:
		typedef ::native::events::EventDispatcher_obj super;
		typedef SoundEventManager_obj OBJ_;
		SoundEventManager_obj();
		Void __construct(::native::events::IEventDispatcher target);

	public:
		static hx::ObjectPtr< SoundEventManager_obj > __new(::native::events::IEventDispatcher target);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~SoundEventManager_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("SoundEventManager"); }

		static ::hxDragonBones::events::SoundEventManager instance; /* REM */ 
		static ::hxDragonBones::events::SoundEventManager get_instance( );
		static Dynamic get_instance_dyn();

};

} // end namespace hxDragonBones
} // end namespace events

#endif /* INCLUDED_hxDragonBones_events_SoundEventManager */ 
