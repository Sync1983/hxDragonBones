#ifndef INCLUDED_hsl_haxe_Signal
#define INCLUDED_hsl_haxe_Signal

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(hsl,haxe,Bond)
HX_DECLARE_CLASS2(hsl,haxe,Signal)
namespace hsl{
namespace haxe{


class Signal_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Signal_obj OBJ_;
		Signal_obj();
		Void __construct(Dynamic data,::hsl::haxe::Bond currentBond,Dynamic currentTarget,Dynamic origin);

	public:
		static hx::ObjectPtr< Signal_obj > __new(Dynamic data,::hsl::haxe::Bond currentBond,Dynamic currentTarget,Dynamic origin);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Signal_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Signal"); }

		virtual Void stopPropagation( );
		Dynamic stopPropagation_dyn();

		virtual Void stopImmediatePropagation( );
		Dynamic stopImmediatePropagation_dyn();

		virtual Dynamic getData( );
		Dynamic getData_dyn();

		bool propagationStopped; /* REM */ 
		Dynamic origin; /* REM */ 
		bool immediatePropagationStopped; /* REM */ 
		Dynamic data1; /* REM */ 
		Dynamic data; /* REM */ 
		Dynamic currentTarget; /* REM */ 
		::hsl::haxe::Bond currentBond; /* REM */ 
};

} // end namespace hsl
} // end namespace haxe

#endif /* INCLUDED_hsl_haxe_Signal */ 
