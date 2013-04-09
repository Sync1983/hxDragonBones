#ifndef INCLUDED_hxDragonBones_textures_SubTextureData
#define INCLUDED_hxDragonBones_textures_SubTextureData

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <native/geom/Rectangle.h>
HX_DECLARE_CLASS2(hxDragonBones,textures,SubTextureData)
HX_DECLARE_CLASS2(native,geom,Rectangle)
namespace hxDragonBones{
namespace textures{


class SubTextureData_obj : public ::native::geom::Rectangle_obj{
	public:
		typedef ::native::geom::Rectangle_obj super;
		typedef SubTextureData_obj OBJ_;
		SubTextureData_obj();
		Void __construct(hx::Null< Float >  __o_x,hx::Null< Float >  __o_y,hx::Null< Float >  __o_width,hx::Null< Float >  __o_height);

	public:
		static hx::ObjectPtr< SubTextureData_obj > __new(hx::Null< Float >  __o_x,hx::Null< Float >  __o_y,hx::Null< Float >  __o_width,hx::Null< Float >  __o_height);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~SubTextureData_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("SubTextureData"); }

		int pivotY; /* REM */ 
		int pivotX; /* REM */ 
};

} // end namespace hxDragonBones
} // end namespace textures

#endif /* INCLUDED_hxDragonBones_textures_SubTextureData */ 
