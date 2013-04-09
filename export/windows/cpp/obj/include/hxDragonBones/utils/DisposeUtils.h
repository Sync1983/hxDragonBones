#ifndef INCLUDED_hxDragonBones_utils_DisposeUtils
#define INCLUDED_hxDragonBones_utils_DisposeUtils

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(hxDragonBones,utils,DisposeUtils)
namespace hxDragonBones{
namespace utils{


class DisposeUtils_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef DisposeUtils_obj OBJ_;
		DisposeUtils_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< DisposeUtils_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~DisposeUtils_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("DisposeUtils"); }

		static Void dispose( Dynamic target);
		static Dynamic dispose_dyn();

};

} // end namespace hxDragonBones
} // end namespace utils

#endif /* INCLUDED_hxDragonBones_utils_DisposeUtils */ 
