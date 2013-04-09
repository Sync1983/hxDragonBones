#include <hxcpp.h>

#ifndef INCLUDED_hxDragonBones_display_IDisplayBridge
#include <hxDragonBones/display/IDisplayBridge.h>
#endif
#ifndef INCLUDED_hxDragonBones_objects_Node
#include <hxDragonBones/objects/Node.h>
#endif
#ifndef INCLUDED_native_geom_ColorTransform
#include <native/geom/ColorTransform.h>
#endif
#ifndef INCLUDED_native_geom_Matrix
#include <native/geom/Matrix.h>
#endif
namespace hxDragonBones{
namespace display{

HX_DEFINE_DYNAMIC_FUNC0(IDisplayBridge_obj,removeDisplayFromParent,)

HX_DEFINE_DYNAMIC_FUNC2(IDisplayBridge_obj,addDisplayTo,)

HX_DEFINE_DYNAMIC_FUNC4(IDisplayBridge_obj,update,)


static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(IDisplayBridge_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(IDisplayBridge_obj::__mClass,"__mClass");
};

Class IDisplayBridge_obj::__mClass;

void IDisplayBridge_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("hxDragonBones.display.IDisplayBridge"), hx::TCanCast< IDisplayBridge_obj> ,0,0,
	0, 0,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void IDisplayBridge_obj::__boot()
{
}

} // end namespace hxDragonBones
} // end namespace display
