#ifndef INCLUDED_hxDragonBones_objects_FrameData
#define INCLUDED_hxDragonBones_objects_FrameData

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(hxDragonBones,objects,FrameData)
HX_DECLARE_CLASS2(hxDragonBones,objects,Node)
HX_DECLARE_CLASS2(native,geom,ColorTransform)
namespace hxDragonBones{
namespace objects{


class FrameData_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef FrameData_obj OBJ_;
		FrameData_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< FrameData_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~FrameData_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("FrameData"); }

		::native::geom::ColorTransform colorTransform; /* REM */ 
		::hxDragonBones::objects::Node node; /* REM */ 
		::String soundEffect; /* REM */ 
		::String sound; /* REM */ 
		::String event; /* REM */ 
		bool visible; /* REM */ 
		::String movement; /* REM */ 
		int displayIndex; /* REM */ 
		int tweenRotate; /* REM */ 
		Float tweenEasing; /* REM */ 
		Float duration; /* REM */ 
};

} // end namespace hxDragonBones
} // end namespace objects

#endif /* INCLUDED_hxDragonBones_objects_FrameData */ 
