#ifndef INCLUDED_hxDragonBones_display_NativeDisplayBridge
#define INCLUDED_hxDragonBones_display_NativeDisplayBridge

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <hxDragonBones/display/IDisplayBridge.h>
HX_DECLARE_CLASS2(hxDragonBones,display,IDisplayBridge)
HX_DECLARE_CLASS2(hxDragonBones,display,NativeDisplayBridge)
HX_DECLARE_CLASS2(hxDragonBones,objects,Node)
HX_DECLARE_CLASS2(native,geom,ColorTransform)
HX_DECLARE_CLASS2(native,geom,Matrix)
namespace hxDragonBones{
namespace display{


class NativeDisplayBridge_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef NativeDisplayBridge_obj OBJ_;
		NativeDisplayBridge_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< NativeDisplayBridge_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~NativeDisplayBridge_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		inline operator ::hxDragonBones::display::IDisplayBridge_obj *()
			{ return new ::hxDragonBones::display::IDisplayBridge_delegate_< NativeDisplayBridge_obj >(this); }
		hx::Object *__ToInterface(const type_info &inType);
		::String __ToString() const { return HX_CSTRING("NativeDisplayBridge"); }

		virtual Void removeDisplayFromParent( );
		Dynamic removeDisplayFromParent_dyn();

		virtual Void addDisplayTo( Dynamic container,hx::Null< int >  index);
		Dynamic addDisplayTo_dyn();

		virtual Void update( ::native::geom::Matrix matrix,::hxDragonBones::objects::Node node,::native::geom::ColorTransform colorTransform,bool visible);
		Dynamic update_dyn();

		virtual Dynamic set_display( Dynamic value);
		Dynamic set_display_dyn();

		Dynamic display; /* REM */ 
};

} // end namespace hxDragonBones
} // end namespace display

#endif /* INCLUDED_hxDragonBones_display_NativeDisplayBridge */ 
