#ifndef INCLUDED_hxDragonBones_objects_BoneData
#define INCLUDED_hxDragonBones_objects_BoneData

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <hxDragonBones/utils/IDisposable.h>
HX_DECLARE_CLASS2(hxDragonBones,objects,BoneData)
HX_DECLARE_CLASS2(hxDragonBones,objects,Node)
HX_DECLARE_CLASS2(hxDragonBones,utils,IDisposable)
namespace hxDragonBones{
namespace objects{


class BoneData_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef BoneData_obj OBJ_;
		BoneData_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< BoneData_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~BoneData_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		inline operator ::hxDragonBones::utils::IDisposable_obj *()
			{ return new ::hxDragonBones::utils::IDisposable_delegate_< BoneData_obj >(this); }
		hx::Object *__ToInterface(const type_info &inType);
		::String __ToString() const { return HX_CSTRING("BoneData"); }

		virtual Void dispose( );
		Dynamic dispose_dyn();

		Array< ::String > displayNames; /* REM */ 
		::hxDragonBones::objects::Node node; /* REM */ 
		::String parent; /* REM */ 
};

} // end namespace hxDragonBones
} // end namespace objects

#endif /* INCLUDED_hxDragonBones_objects_BoneData */ 
