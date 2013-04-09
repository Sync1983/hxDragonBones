#ifndef INCLUDED_hsl_haxe__DirectSignaler_LinkedBond
#define INCLUDED_hsl_haxe__DirectSignaler_LinkedBond

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <hsl/haxe/Bond.h>
HX_DECLARE_CLASS2(hsl,haxe,Bond)
HX_DECLARE_CLASS3(hsl,haxe,_DirectSignaler,LinkedBond)
namespace hsl{
namespace haxe{
namespace _DirectSignaler{


class LinkedBond_obj : public ::hsl::haxe::Bond_obj{
	public:
		typedef ::hsl::haxe::Bond_obj super;
		typedef LinkedBond_obj OBJ_;
		LinkedBond_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< LinkedBond_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~LinkedBond_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("LinkedBond"); }

		virtual Void unlink( );
		Dynamic unlink_dyn();

		virtual Void destroy( );

		virtual bool determineEquals( ::hsl::haxe::_DirectSignaler::LinkedBond value);
		Dynamic determineEquals_dyn();

		virtual int callListener( Dynamic data,Dynamic currentTarget,Dynamic origin,int propagationStatus);
		Dynamic callListener_dyn();

		::hsl::haxe::_DirectSignaler::LinkedBond previous; /* REM */ 
		::hsl::haxe::_DirectSignaler::LinkedBond next; /* REM */ 
		bool destroyed; /* REM */ 
};

} // end namespace hsl
} // end namespace haxe
} // end namespace _DirectSignaler

#endif /* INCLUDED_hsl_haxe__DirectSignaler_LinkedBond */ 
