#ifndef INCLUDED_hxDragonBones_events_ArmatureEvent
#define INCLUDED_hxDragonBones_events_ArmatureEvent

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <native/events/Event.h>
HX_DECLARE_CLASS2(hxDragonBones,events,ArmatureEvent)
HX_DECLARE_CLASS2(native,events,Event)
namespace hxDragonBones{
namespace events{


class ArmatureEvent_obj : public ::native::events::Event_obj{
	public:
		typedef ::native::events::Event_obj super;
		typedef ArmatureEvent_obj OBJ_;
		ArmatureEvent_obj();
		Void __construct(::String type,hx::Null< bool >  __o_bubbles,hx::Null< bool >  __o_cancelable);

	public:
		static hx::ObjectPtr< ArmatureEvent_obj > __new(::String type,hx::Null< bool >  __o_bubbles,hx::Null< bool >  __o_cancelable);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~ArmatureEvent_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("ArmatureEvent"); }

		virtual ::native::events::Event clone( );

		static ::String Z_ORDER_UPDATED; /* REM */ 
};

} // end namespace hxDragonBones
} // end namespace events

#endif /* INCLUDED_hxDragonBones_events_ArmatureEvent */ 
