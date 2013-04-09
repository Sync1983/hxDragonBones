#ifndef INCLUDED_hsl_haxe_Bond
#define INCLUDED_hsl_haxe_Bond

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(hsl,haxe,Bond)
namespace hsl{
namespace haxe{


class Bond_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Bond_obj OBJ_;
		Bond_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< Bond_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Bond_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Bond"); }

		virtual Void resume( );
		Dynamic resume_dyn();

		virtual Void halt( );
		Dynamic halt_dyn();

		virtual ::hsl::haxe::Bond destroyOnUse( );
		Dynamic destroyOnUse_dyn();

		virtual Void destroy( );
		Dynamic destroy_dyn();

		bool willDestroyOnUse; /* REM */ 
		bool halted; /* REM */ 
};

} // end namespace hsl
} // end namespace haxe

#endif /* INCLUDED_hsl_haxe_Bond */ 
