#ifndef INCLUDED_hxDragonBones_objects_MovementBoneData
#define INCLUDED_hxDragonBones_objects_MovementBoneData

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <hxDragonBones/utils/IDisposable.h>
HX_DECLARE_CLASS2(hxDragonBones,objects,FrameData)
HX_DECLARE_CLASS2(hxDragonBones,objects,MovementBoneData)
HX_DECLARE_CLASS2(hxDragonBones,utils,IDisposable)
namespace hxDragonBones{
namespace objects{


class MovementBoneData_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef MovementBoneData_obj OBJ_;
		MovementBoneData_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< MovementBoneData_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~MovementBoneData_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		inline operator ::hxDragonBones::utils::IDisposable_obj *()
			{ return new ::hxDragonBones::utils::IDisposable_delegate_< MovementBoneData_obj >(this); }
		hx::Object *__ToInterface(const type_info &inType);
		::String __ToString() const { return HX_CSTRING("MovementBoneData"); }

		virtual Void setValues( hx::Null< Float >  scale,hx::Null< Float >  delay);
		Dynamic setValues_dyn();

		virtual Void dispose( );
		Dynamic dispose_dyn();

		Float delay; /* REM */ 
		Float scale; /* REM */ 
		Array< ::hxDragonBones::objects::FrameData > frameList; /* REM */ 
		static ::hxDragonBones::objects::MovementBoneData HIDE_DATA; /* REM */ 
};

} // end namespace hxDragonBones
} // end namespace objects

#endif /* INCLUDED_hxDragonBones_objects_MovementBoneData */ 
