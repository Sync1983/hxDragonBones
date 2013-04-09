#include <hxcpp.h>

#ifndef INCLUDED_hxDragonBones_utils_IDisposable
#include <hxDragonBones/utils/IDisposable.h>
#endif
namespace hxDragonBones{
namespace utils{

HX_DEFINE_DYNAMIC_FUNC0(IDisposable_obj,dispose,)


static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(IDisposable_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(IDisposable_obj::__mClass,"__mClass");
};

Class IDisposable_obj::__mClass;

void IDisposable_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("hxDragonBones.utils.IDisposable"), hx::TCanCast< IDisposable_obj> ,0,0,
	0, 0,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void IDisposable_obj::__boot()
{
}

} // end namespace hxDragonBones
} // end namespace utils
