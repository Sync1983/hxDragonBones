#ifndef INCLUDED_hxDragonBones_Bone
#define INCLUDED_hxDragonBones_Bone

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <hxDragonBones/utils/IDisposable.h>
HX_DECLARE_CLASS1(hxDragonBones,Armature)
HX_DECLARE_CLASS1(hxDragonBones,Bone)
HX_DECLARE_CLASS2(hxDragonBones,animation,IAnimatable)
HX_DECLARE_CLASS2(hxDragonBones,animation,Tween)
HX_DECLARE_CLASS2(hxDragonBones,display,IDisplayBridge)
HX_DECLARE_CLASS2(hxDragonBones,objects,Node)
HX_DECLARE_CLASS2(hxDragonBones,utils,IDisposable)
HX_DECLARE_CLASS2(native,events,EventDispatcher)
HX_DECLARE_CLASS2(native,events,IEventDispatcher)
HX_DECLARE_CLASS2(native,geom,ColorTransform)
HX_DECLARE_CLASS2(native,geom,Matrix)
HX_DECLARE_CLASS2(native,geom,Point)
namespace hxDragonBones{


class Bone_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Bone_obj OBJ_;
		Bone_obj();
		Void __construct(::hxDragonBones::display::IDisplayBridge bridge);

	public:
		static hx::ObjectPtr< Bone_obj > __new(::hxDragonBones::display::IDisplayBridge bridge);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Bone_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		inline operator ::hxDragonBones::utils::IDisposable_obj *()
			{ return new ::hxDragonBones::utils::IDisposable_delegate_< Bone_obj >(this); }
		hx::Object *__ToInterface(const type_info &inType);
		::String __ToString() const { return HX_CSTRING("Bone"); }

		virtual Void setParent( ::hxDragonBones::Bone parent);
		Dynamic setParent_dyn();

		virtual ::native::geom::ColorTransform getColorTransform( );
		Dynamic getColorTransform_dyn();

		virtual Void update( );
		Dynamic update_dyn();

		virtual Void removeFromParent( );
		Dynamic removeFromParent_dyn();

		virtual Void removeChild( ::hxDragonBones::Bone child);
		Dynamic removeChild_dyn();

		virtual Void addChild( ::hxDragonBones::Bone child);
		Dynamic addChild_dyn();

		virtual bool contains( ::hxDragonBones::Bone bone,Dynamic deepLevel);
		Dynamic contains_dyn();

		virtual Void dispose( );
		Dynamic dispose_dyn();

		virtual Void changeDisplayList( Dynamic list);
		Dynamic changeDisplayList_dyn();

		virtual Void changeDisplay( int displayIndex);
		Dynamic changeDisplay_dyn();

		virtual Dynamic set_display( Dynamic value);
		Dynamic set_display_dyn();

		virtual Dynamic get_display( );
		Dynamic get_display_dyn();

		virtual ::hxDragonBones::Armature get_childArmature( );
		Dynamic get_childArmature_dyn();

		int _displayIndex; /* REM */ 
		Dynamic _displayList; /* REM */ 
		bool isOnStage; /* REM */ 
		::native::geom::Matrix globalTransformMatrix; /* REM */ 
		::hxDragonBones::animation::Tween tween; /* REM */ 
		Array< ::hxDragonBones::Bone > children; /* REM */ 
		::hxDragonBones::display::IDisplayBridge displayBridge; /* REM */ 
		::native::geom::ColorTransform tweenColorTransform; /* REM */ 
		::hxDragonBones::objects::Node tweenNode; /* REM */ 
		bool visible; /* REM */ 
		Dynamic display; /* REM */ 
		::hxDragonBones::Bone parent; /* REM */ 
		::hxDragonBones::Armature childArmature; /* REM */ 
		::hxDragonBones::Armature armature; /* REM */ 
		::hxDragonBones::objects::Node node; /* REM */ 
		::hxDragonBones::objects::Node origin; /* REM */ 
		::hxDragonBones::objects::Node global; /* REM */ 
		Dynamic userData; /* REM */ 
		::String name; /* REM */ 
		static ::native::geom::Point _helpPoint; /* REM */ 
};

} // end namespace hxDragonBones

#endif /* INCLUDED_hxDragonBones_Bone */ 
