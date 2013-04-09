#ifndef INCLUDED_hxDragonBones_textures_NativeTextureAtlas
#define INCLUDED_hxDragonBones_textures_NativeTextureAtlas

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <hxDragonBones/textures/ITextureAtlas.h>
HX_DECLARE_CLASS0(Hash)
HX_DECLARE_CLASS0(Xml)
HX_DECLARE_CLASS2(hxDragonBones,textures,ITextureAtlas)
HX_DECLARE_CLASS2(hxDragonBones,textures,NativeTextureAtlas)
HX_DECLARE_CLASS2(hxDragonBones,utils,IDisposable)
HX_DECLARE_CLASS2(native,display,BitmapData)
HX_DECLARE_CLASS2(native,display,DisplayObject)
HX_DECLARE_CLASS2(native,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(native,display,IBitmapDrawable)
HX_DECLARE_CLASS2(native,display,InteractiveObject)
HX_DECLARE_CLASS2(native,display,MovieClip)
HX_DECLARE_CLASS2(native,display,Sprite)
HX_DECLARE_CLASS2(native,events,EventDispatcher)
HX_DECLARE_CLASS2(native,events,IEventDispatcher)
HX_DECLARE_CLASS2(native,geom,Rectangle)
namespace hxDragonBones{
namespace textures{


class NativeTextureAtlas_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef NativeTextureAtlas_obj OBJ_;
		NativeTextureAtlas_obj();
		Void __construct(Dynamic texture,::Xml texAtlasXml,hx::Null< Float >  __o_scale,Dynamic isDifferentXML);

	public:
		static hx::ObjectPtr< NativeTextureAtlas_obj > __new(Dynamic texture,::Xml texAtlasXml,hx::Null< Float >  __o_scale,Dynamic isDifferentXML);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~NativeTextureAtlas_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		inline operator ::hxDragonBones::textures::ITextureAtlas_obj *()
			{ return new ::hxDragonBones::textures::ITextureAtlas_delegate_< NativeTextureAtlas_obj >(this); }
		inline operator ::hxDragonBones::utils::IDisposable_obj *()
			{ return new ::hxDragonBones::utils::IDisposable_delegate_< NativeTextureAtlas_obj >(this); }
		hx::Object *__ToInterface(const type_info &inType);
		::String __ToString() const { return HX_CSTRING("NativeTextureAtlas"); }

		virtual Void parseData( ::Xml texAtlasXml);
		Dynamic parseData_dyn();

		virtual ::native::geom::Rectangle getRegion( ::String name);
		Dynamic getRegion_dyn();

		virtual Void dispose( );
		Dynamic dispose_dyn();

		::String name; /* REM */ 
		bool _isDifferentXML; /* REM */ 
		::Hash _name2SubTexData; /* REM */ 
		Float scale; /* REM */ 
		::native::display::BitmapData bitmapData; /* REM */ 
		::native::display::MovieClip movieClip; /* REM */ 
};

} // end namespace hxDragonBones
} // end namespace textures

#endif /* INCLUDED_hxDragonBones_textures_NativeTextureAtlas */ 
