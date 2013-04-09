#include <hxcpp.h>

#ifndef INCLUDED_hxDragonBones_textures_ITextureAtlas
#include <hxDragonBones/textures/ITextureAtlas.h>
#endif
#ifndef INCLUDED_hxDragonBones_utils_IDisposable
#include <hxDragonBones/utils/IDisposable.h>
#endif
#ifndef INCLUDED_native_geom_Rectangle
#include <native/geom/Rectangle.h>
#endif
namespace hxDragonBones{
namespace textures{

HX_DEFINE_DYNAMIC_FUNC1(ITextureAtlas_obj,getRegion,return )


static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(ITextureAtlas_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(ITextureAtlas_obj::__mClass,"__mClass");
};

Class ITextureAtlas_obj::__mClass;

void ITextureAtlas_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("hxDragonBones.textures.ITextureAtlas"), hx::TCanCast< ITextureAtlas_obj> ,0,0,
	0, 0,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void ITextureAtlas_obj::__boot()
{
}

} // end namespace hxDragonBones
} // end namespace textures
