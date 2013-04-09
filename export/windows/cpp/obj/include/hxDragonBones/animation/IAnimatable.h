#ifndef INCLUDED_hxDragonBones_animation_IAnimatable
#define INCLUDED_hxDragonBones_animation_IAnimatable

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(hxDragonBones,animation,IAnimatable)
namespace hxDragonBones{
namespace animation{


class IAnimatable_obj : public hx::Interface{
	public:
		typedef hx::Interface super;
		typedef IAnimatable_obj OBJ_;
		HX_DO_INTERFACE_RTTI;
		static void __boot();
virtual Void advanceTime( hx::Null< Float >  passedTime)=0;
		Dynamic advanceTime_dyn();
};

#define DELEGATE_hxDragonBones_animation_IAnimatable \
virtual Void advanceTime( hx::Null< Float >  passedTime) { return mDelegate->advanceTime(passedTime);}  \
virtual Dynamic advanceTime_dyn() { return mDelegate->advanceTime_dyn();}  \


template<typename IMPL>
class IAnimatable_delegate_ : public IAnimatable_obj
{
	protected:
		IMPL *mDelegate;
	public:
		IAnimatable_delegate_(IMPL *inDelegate) : mDelegate(inDelegate) {}
		hx::Object *__GetRealObject() { return mDelegate; }
		void __Visit(HX_VISIT_PARAMS) { HX_VISIT_OBJECT(mDelegate); }
		DELEGATE_hxDragonBones_animation_IAnimatable
};

} // end namespace hxDragonBones
} // end namespace animation

#endif /* INCLUDED_hxDragonBones_animation_IAnimatable */ 
