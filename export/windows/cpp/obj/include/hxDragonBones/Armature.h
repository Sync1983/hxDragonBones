#ifndef INCLUDED_hxDragonBones_Armature
#define INCLUDED_hxDragonBones_Armature

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <native/events/EventDispatcher.h>
#include <hxDragonBones/utils/IDisposable.h>
#include <hxDragonBones/animation/IAnimatable.h>
HX_DECLARE_CLASS1(hxDragonBones,Armature)
HX_DECLARE_CLASS1(hxDragonBones,Bone)
HX_DECLARE_CLASS2(hxDragonBones,animation,Animation)
HX_DECLARE_CLASS2(hxDragonBones,animation,IAnimatable)
HX_DECLARE_CLASS2(hxDragonBones,utils,IDisposable)
HX_DECLARE_CLASS2(native,events,EventDispatcher)
HX_DECLARE_CLASS2(native,events,IEventDispatcher)
HX_DECLARE_CLASS2(native,geom,ColorTransform)
namespace hxDragonBones{


class Armature_obj : public ::native::events::EventDispatcher_obj{
	public:
		typedef ::native::events::EventDispatcher_obj super;
		typedef Armature_obj OBJ_;
		Armature_obj();
		Void __construct(Dynamic display);

	public:
		static hx::ObjectPtr< Armature_obj > __new(Dynamic display);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Armature_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		inline operator ::hxDragonBones::utils::IDisposable_obj *()
			{ return new ::hxDragonBones::utils::IDisposable_delegate_< Armature_obj >(this); }
		inline operator ::hxDragonBones::animation::IAnimatable_obj *()
			{ return new ::hxDragonBones::animation::IAnimatable_delegate_< Armature_obj >(this); }
		hx::Object *__ToInterface(const type_info &inType);
		::String __ToString() const { return HX_CSTRING("Armature"); }

		virtual int compareZ( Dynamic a,Dynamic b);
		Dynamic compareZ_dyn();

		virtual Void removeFromBones( ::hxDragonBones::Bone bone);
		Dynamic removeFromBones_dyn();

		virtual Void addToBones( ::hxDragonBones::Bone bone,Dynamic root);
		Dynamic addToBones_dyn();

		virtual Void updateBonesZ( );
		Dynamic updateBonesZ_dyn();

		virtual Void update( );
		Dynamic update_dyn();

		virtual Void advanceTime( hx::Null< Float >  passedTime);
		Dynamic advanceTime_dyn();

		virtual Void removeBoneByName( ::String boneName);
		Dynamic removeBoneByName_dyn();

		virtual Void removeBone( ::hxDragonBones::Bone bone);
		Dynamic removeBone_dyn();

		virtual Void addBone( ::hxDragonBones::Bone bone,::String parentName);
		Dynamic addBone_dyn();

		virtual ::hxDragonBones::Bone getBoneByDisplay( Dynamic display);
		Dynamic getBoneByDisplay_dyn();

		virtual ::hxDragonBones::Bone getBone( ::String name);
		Dynamic getBone_dyn();

		virtual Void dispose( );
		Dynamic dispose_dyn();

		Array< ::hxDragonBones::Bone > _rootBones; /* REM */ 
		virtual ::native::geom::ColorTransform set_colorTransform( ::native::geom::ColorTransform value);
		Dynamic set_colorTransform_dyn();

		bool colorTransformChange; /* REM */ 
		::native::geom::ColorTransform colorTransform; /* REM */ 
		bool bonesIndexChanged; /* REM */ 
		Array< ::hxDragonBones::Bone > bones; /* REM */ 
		::hxDragonBones::animation::Animation animation; /* REM */ 
		Dynamic display; /* REM */ 
		::String name; /* REM */ 
};

} // end namespace hxDragonBones

#endif /* INCLUDED_hxDragonBones_Armature */ 
