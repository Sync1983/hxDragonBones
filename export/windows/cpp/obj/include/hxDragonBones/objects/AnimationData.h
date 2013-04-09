#ifndef INCLUDED_hxDragonBones_objects_AnimationData
#define INCLUDED_hxDragonBones_objects_AnimationData

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <hxDragonBones/utils/IDisposable.h>
HX_DECLARE_CLASS2(hxDragonBones,objects,AnimationData)
HX_DECLARE_CLASS2(hxDragonBones,objects,DataList)
HX_DECLARE_CLASS2(hxDragonBones,objects,MovementData)
HX_DECLARE_CLASS2(hxDragonBones,utils,IDisposable)
namespace hxDragonBones{
namespace objects{


class AnimationData_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef AnimationData_obj OBJ_;
		AnimationData_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< AnimationData_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~AnimationData_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		inline operator ::hxDragonBones::utils::IDisposable_obj *()
			{ return new ::hxDragonBones::utils::IDisposable_delegate_< AnimationData_obj >(this); }
		hx::Object *__ToInterface(const type_info &inType);
		::String __ToString() const { return HX_CSTRING("AnimationData"); }

		virtual ::hxDragonBones::objects::MovementData getMovementData( ::String name);
		Dynamic getMovementData_dyn();

		virtual Void dispose( );
		Dynamic dispose_dyn();

		virtual Array< ::String > get_movementList( );
		Dynamic get_movementList_dyn();

		::hxDragonBones::objects::DataList movementDataList; /* REM */ 
		Array< ::String > movementList; /* REM */ 
};

} // end namespace hxDragonBones
} // end namespace objects

#endif /* INCLUDED_hxDragonBones_objects_AnimationData */ 
