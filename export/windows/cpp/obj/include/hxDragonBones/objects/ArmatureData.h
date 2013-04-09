#ifndef INCLUDED_hxDragonBones_objects_ArmatureData
#define INCLUDED_hxDragonBones_objects_ArmatureData

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <hxDragonBones/utils/IDisposable.h>
HX_DECLARE_CLASS2(hxDragonBones,objects,ArmatureData)
HX_DECLARE_CLASS2(hxDragonBones,objects,BoneData)
HX_DECLARE_CLASS2(hxDragonBones,objects,DataList)
HX_DECLARE_CLASS2(hxDragonBones,utils,IDisposable)
namespace hxDragonBones{
namespace objects{


class ArmatureData_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef ArmatureData_obj OBJ_;
		ArmatureData_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< ArmatureData_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~ArmatureData_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		inline operator ::hxDragonBones::utils::IDisposable_obj *()
			{ return new ::hxDragonBones::utils::IDisposable_delegate_< ArmatureData_obj >(this); }
		hx::Object *__ToInterface(const type_info &inType);
		::String __ToString() const { return HX_CSTRING("ArmatureData"); }

		virtual int compareLevel( Dynamic a,Dynamic b);
		Dynamic compareLevel_dyn();

		virtual Void updateBoneList( );
		Dynamic updateBoneList_dyn();

		virtual ::hxDragonBones::objects::BoneData getBoneData( ::String name);
		Dynamic getBoneData_dyn();

		virtual Void dispose( );
		Dynamic dispose_dyn();

		::hxDragonBones::objects::DataList boneDataList; /* REM */ 
		virtual Array< ::String > get_boneNames( );
		Dynamic get_boneNames_dyn();

		Array< ::String > boneNames; /* REM */ 
};

} // end namespace hxDragonBones
} // end namespace objects

#endif /* INCLUDED_hxDragonBones_objects_ArmatureData */ 
