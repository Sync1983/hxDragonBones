#ifndef INCLUDED_hxDragonBones_objects_MovementData
#define INCLUDED_hxDragonBones_objects_MovementData

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <hxDragonBones/utils/IDisposable.h>
HX_DECLARE_CLASS2(hxDragonBones,objects,DataList)
HX_DECLARE_CLASS2(hxDragonBones,objects,MovementBoneData)
HX_DECLARE_CLASS2(hxDragonBones,objects,MovementData)
HX_DECLARE_CLASS2(hxDragonBones,objects,MovementFrameData)
HX_DECLARE_CLASS2(hxDragonBones,utils,IDisposable)
namespace hxDragonBones{
namespace objects{


class MovementData_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef MovementData_obj OBJ_;
		MovementData_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< MovementData_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~MovementData_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		inline operator ::hxDragonBones::utils::IDisposable_obj *()
			{ return new ::hxDragonBones::utils::IDisposable_delegate_< MovementData_obj >(this); }
		hx::Object *__ToInterface(const type_info &inType);
		::String __ToString() const { return HX_CSTRING("MovementData"); }

		virtual ::hxDragonBones::objects::MovementBoneData getMovementBoneData( ::String name);
		Dynamic getMovementBoneData_dyn();

		virtual Void dispose( );
		Dynamic dispose_dyn();

		Float tweenEasing; /* REM */ 
		bool loop; /* REM */ 
		Array< ::hxDragonBones::objects::MovementFrameData > movementFrameList; /* REM */ 
		::hxDragonBones::objects::DataList movementBoneDataList; /* REM */ 
		Float durationTween; /* REM */ 
		Float durationTo; /* REM */ 
		Float duration; /* REM */ 
};

} // end namespace hxDragonBones
} // end namespace objects

#endif /* INCLUDED_hxDragonBones_objects_MovementData */ 
