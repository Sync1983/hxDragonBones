#ifndef INCLUDED_hxDragonBones_objects_MovementFrameData
#define INCLUDED_hxDragonBones_objects_MovementFrameData

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(hxDragonBones,objects,MovementFrameData)
namespace hxDragonBones{
namespace objects{


class MovementFrameData_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef MovementFrameData_obj OBJ_;
		MovementFrameData_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< MovementFrameData_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~MovementFrameData_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("MovementFrameData"); }

		virtual Void setValues( Float duration,::String movement,::String event,::String sound);
		Dynamic setValues_dyn();

		::String soundEffect; /* REM */ 
		::String sound; /* REM */ 
		::String event; /* REM */ 
		::String movement; /* REM */ 
		Float duration; /* REM */ 
};

} // end namespace hxDragonBones
} // end namespace objects

#endif /* INCLUDED_hxDragonBones_objects_MovementFrameData */ 
