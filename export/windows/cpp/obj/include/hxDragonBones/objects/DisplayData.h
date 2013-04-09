#ifndef INCLUDED_hxDragonBones_objects_DisplayData
#define INCLUDED_hxDragonBones_objects_DisplayData

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(hxDragonBones,objects,DisplayData)
namespace hxDragonBones{
namespace objects{


class DisplayData_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef DisplayData_obj OBJ_;
		DisplayData_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< DisplayData_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~DisplayData_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("DisplayData"); }

		bool isArmature; /* REM */ 
		Float pivotY; /* REM */ 
		Float pivotX; /* REM */ 
};

} // end namespace hxDragonBones
} // end namespace objects

#endif /* INCLUDED_hxDragonBones_objects_DisplayData */ 
