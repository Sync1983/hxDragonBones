#include <hxcpp.h>

#ifndef INCLUDED_hxDragonBones_animation_IAnimatable
#include <hxDragonBones/animation/IAnimatable.h>
#endif
namespace hxDragonBones{
namespace animation{

HX_DEFINE_DYNAMIC_FUNC1(IAnimatable_obj,advanceTime,)


static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(IAnimatable_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(IAnimatable_obj::__mClass,"__mClass");
};

Class IAnimatable_obj::__mClass;

void IAnimatable_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("hxDragonBones.animation.IAnimatable"), hx::TCanCast< IAnimatable_obj> ,0,0,
	0, 0,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void IAnimatable_obj::__boot()
{
}

} // end namespace hxDragonBones
} // end namespace animation
