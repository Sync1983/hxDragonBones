#ifndef INCLUDED_hsl_haxe_DirectSignaler
#define INCLUDED_hsl_haxe_DirectSignaler

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <hsl/haxe/Signaler.h>
HX_DECLARE_CLASS0(List)
HX_DECLARE_CLASS2(hsl,haxe,Bond)
HX_DECLARE_CLASS2(hsl,haxe,DirectSignaler)
HX_DECLARE_CLASS2(hsl,haxe,Signal)
HX_DECLARE_CLASS2(hsl,haxe,Signaler)
HX_DECLARE_CLASS3(hsl,haxe,_DirectSignaler,LinkedBond)
HX_DECLARE_CLASS3(hsl,haxe,_DirectSignaler,SentinelBond)
namespace hsl{
namespace haxe{


class DirectSignaler_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef DirectSignaler_obj OBJ_;
		DirectSignaler_obj();
		Void __construct(Dynamic subject,Dynamic rejectNullData);

	public:
		static hx::ObjectPtr< DirectSignaler_obj > __new(Dynamic subject,Dynamic rejectNullData);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~DirectSignaler_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		inline operator ::hsl::haxe::Signaler_obj *()
			{ return new ::hsl::haxe::Signaler_delegate_< DirectSignaler_obj >(this); }
		hx::Object *__ToInterface(const type_info &inType);
		::String __ToString() const { return HX_CSTRING("DirectSignaler"); }

		virtual Void unbindVoid( Dynamic listener);
		Dynamic unbindVoid_dyn();

		virtual Void unbindAdvanced( Dynamic _tmp_listener);
		Dynamic unbindAdvanced_dyn();

		virtual Void unbind( Dynamic _tmp_listener);
		Dynamic unbind_dyn();

		virtual Void removeNotificationTarget( ::hsl::haxe::Signaler value);
		Dynamic removeNotificationTarget_dyn();

		virtual Void removeBubblingTarget( ::hsl::haxe::Signaler _tmp_value);
		Dynamic removeBubblingTarget_dyn();

		virtual Void verifyCaller( Dynamic positionInformation);
		Dynamic verifyCaller_dyn();

		virtual Dynamic getOrigin( Dynamic origin);
		Dynamic getOrigin_dyn();

		virtual bool getIsListenedTo( );
		Dynamic getIsListenedTo_dyn();

		virtual Void dispatch( Dynamic _tmp_data,Dynamic origin,Dynamic positionInformation);
		Dynamic dispatch_dyn();

		virtual Void bubble( Dynamic data,Dynamic origin);
		Dynamic bubble_dyn();

		virtual ::hsl::haxe::Bond bindVoid( Dynamic listener);
		Dynamic bindVoid_dyn();

		virtual ::hsl::haxe::Bond bindAdvanced( Dynamic _tmp_listener);
		Dynamic bindAdvanced_dyn();

		virtual ::hsl::haxe::Bond bind( Dynamic _tmp_listener);
		Dynamic bind_dyn();

		virtual Void addNotificationTarget( ::hsl::haxe::Signaler value);
		Dynamic addNotificationTarget_dyn();

		virtual Void addBubblingTarget( ::hsl::haxe::Signaler _tmp_value);
		Dynamic addBubblingTarget_dyn();

		::List subjectClassNames; /* REM */ 
		Dynamic subject; /* REM */ 
		::hsl::haxe::_DirectSignaler::SentinelBond sentinel; /* REM */ 
		bool rejectNullData; /* REM */ 
		::List notificationTargets; /* REM */ 
		bool isListenedTo; /* REM */ 
		::List bubblingTargets; /* REM */ 
};

} // end namespace hsl
} // end namespace haxe

#endif /* INCLUDED_hsl_haxe_DirectSignaler */ 