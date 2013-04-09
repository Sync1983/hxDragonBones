#ifndef INCLUDED_hxDragonBones_display_IDisplayBridge
#define INCLUDED_hxDragonBones_display_IDisplayBridge

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(hxDragonBones,display,IDisplayBridge)
HX_DECLARE_CLASS2(hxDragonBones,objects,Node)
HX_DECLARE_CLASS2(native,geom,ColorTransform)
HX_DECLARE_CLASS2(native,geom,Matrix)
namespace hxDragonBones{
namespace display{


class IDisplayBridge_obj : public hx::Interface{
	public:
		typedef hx::Interface super;
		typedef IDisplayBridge_obj OBJ_;
		HX_DO_INTERFACE_RTTI;
		static void __boot();
virtual Void removeDisplayFromParent( )=0;
		Dynamic removeDisplayFromParent_dyn();
virtual Void addDisplayTo( Dynamic container,hx::Null< int >  index)=0;
		Dynamic addDisplayTo_dyn();
virtual Void update( ::native::geom::Matrix matrix,::hxDragonBones::objects::Node node,::native::geom::ColorTransform colorTransform,bool visible)=0;
		Dynamic update_dyn();
};

#define DELEGATE_hxDragonBones_display_IDisplayBridge \
virtual Void removeDisplayFromParent( ) { return mDelegate->removeDisplayFromParent();}  \
virtual Dynamic removeDisplayFromParent_dyn() { return mDelegate->removeDisplayFromParent_dyn();}  \
virtual Void addDisplayTo( Dynamic container,hx::Null< int >  index) { return mDelegate->addDisplayTo(container,index);}  \
virtual Dynamic addDisplayTo_dyn() { return mDelegate->addDisplayTo_dyn();}  \
virtual Void update( ::native::geom::Matrix matrix,::hxDragonBones::objects::Node node,::native::geom::ColorTransform colorTransform,bool visible) { return mDelegate->update(matrix,node,colorTransform,visible);}  \
virtual Dynamic update_dyn() { return mDelegate->update_dyn();}  \


template<typename IMPL>
class IDisplayBridge_delegate_ : public IDisplayBridge_obj
{
	protected:
		IMPL *mDelegate;
	public:
		IDisplayBridge_delegate_(IMPL *inDelegate) : mDelegate(inDelegate) {}
		hx::Object *__GetRealObject() { return mDelegate; }
		void __Visit(HX_VISIT_PARAMS) { HX_VISIT_OBJECT(mDelegate); }
		DELEGATE_hxDragonBones_display_IDisplayBridge
};

} // end namespace hxDragonBones
} // end namespace display

#endif /* INCLUDED_hxDragonBones_display_IDisplayBridge */ 
