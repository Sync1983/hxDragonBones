#ifndef INCLUDED_hxDragonBones_objects_SkeletonData
#define INCLUDED_hxDragonBones_objects_SkeletonData

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <hxDragonBones/utils/IDisposable.h>
HX_DECLARE_CLASS2(hxDragonBones,objects,AnimationData)
HX_DECLARE_CLASS2(hxDragonBones,objects,ArmatureData)
HX_DECLARE_CLASS2(hxDragonBones,objects,DataList)
HX_DECLARE_CLASS2(hxDragonBones,objects,DisplayData)
HX_DECLARE_CLASS2(hxDragonBones,objects,SkeletonData)
HX_DECLARE_CLASS2(hxDragonBones,utils,IDisposable)
namespace hxDragonBones{
namespace objects{


class SkeletonData_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef SkeletonData_obj OBJ_;
		SkeletonData_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< SkeletonData_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~SkeletonData_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		inline operator ::hxDragonBones::utils::IDisposable_obj *()
			{ return new ::hxDragonBones::utils::IDisposable_delegate_< SkeletonData_obj >(this); }
		hx::Object *__ToInterface(const type_info &inType);
		::String __ToString() const { return HX_CSTRING("SkeletonData"); }

		virtual ::hxDragonBones::objects::DisplayData getDisplayData( ::String name);
		Dynamic getDisplayData_dyn();

		virtual ::hxDragonBones::objects::AnimationData getAnimationData( ::String name);
		Dynamic getAnimationData_dyn();

		virtual ::hxDragonBones::objects::ArmatureData getArmatureData( ::String name);
		Dynamic getArmatureData_dyn();

		virtual Void dispose( );
		Dynamic dispose_dyn();

		virtual Array< ::String > get_animationNames( );
		Dynamic get_animationNames_dyn();

		virtual Array< ::String > get_armatureNames( );
		Dynamic get_armatureNames_dyn();

		::hxDragonBones::objects::DataList displayDataList; /* REM */ 
		::hxDragonBones::objects::DataList animationDataList; /* REM */ 
		::hxDragonBones::objects::DataList armatureDataList; /* REM */ 
		Array< ::String > animationNames; /* REM */ 
		Array< ::String > armatureNames; /* REM */ 
		int frameRate; /* REM */ 
		::String name; /* REM */ 
};

} // end namespace hxDragonBones
} // end namespace objects

#endif /* INCLUDED_hxDragonBones_objects_SkeletonData */ 
