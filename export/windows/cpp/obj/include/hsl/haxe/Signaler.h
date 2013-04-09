#ifndef INCLUDED_hsl_haxe_Signaler
#define INCLUDED_hsl_haxe_Signaler

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(hsl,haxe,Bond)
HX_DECLARE_CLASS2(hsl,haxe,Signal)
HX_DECLARE_CLASS2(hsl,haxe,Signaler)
namespace hsl{
namespace haxe{


class Signaler_obj : public hx::Interface{
	public:
		typedef hx::Interface super;
		typedef Signaler_obj OBJ_;
		HX_DO_INTERFACE_RTTI;
		static void __boot();
virtual Void unbindVoid( Dynamic listener)=0;
		Dynamic unbindVoid_dyn();
virtual Void unbindAdvanced( Dynamic listener)=0;
		Dynamic unbindAdvanced_dyn();
virtual Void unbind( Dynamic listener)=0;
		Dynamic unbind_dyn();
virtual Void removeNotificationTarget( ::hsl::haxe::Signaler value)=0;
		Dynamic removeNotificationTarget_dyn();
virtual Void removeBubblingTarget( ::hsl::haxe::Signaler value)=0;
		Dynamic removeBubblingTarget_dyn();
virtual bool getIsListenedTo( )=0;
		Dynamic getIsListenedTo_dyn();
virtual Void dispatch( Dynamic data,Dynamic origin,Dynamic positionInformation)=0;
		Dynamic dispatch_dyn();
virtual ::hsl::haxe::Bond bindVoid( Dynamic listener)=0;
		Dynamic bindVoid_dyn();
virtual ::hsl::haxe::Bond bindAdvanced( Dynamic listener)=0;
		Dynamic bindAdvanced_dyn();
virtual ::hsl::haxe::Bond bind( Dynamic listener)=0;
		Dynamic bind_dyn();
virtual Void addNotificationTarget( ::hsl::haxe::Signaler value)=0;
		Dynamic addNotificationTarget_dyn();
virtual Void addBubblingTarget( ::hsl::haxe::Signaler value)=0;
		Dynamic addBubblingTarget_dyn();
};

#define DELEGATE_hsl_haxe_Signaler \
virtual Void unbindVoid( Dynamic listener) { return mDelegate->unbindVoid(listener);}  \
virtual Dynamic unbindVoid_dyn() { return mDelegate->unbindVoid_dyn();}  \
virtual Void unbindAdvanced( Dynamic listener) { return mDelegate->unbindAdvanced(listener);}  \
virtual Dynamic unbindAdvanced_dyn() { return mDelegate->unbindAdvanced_dyn();}  \
virtual Void unbind( Dynamic listener) { return mDelegate->unbind(listener);}  \
virtual Dynamic unbind_dyn() { return mDelegate->unbind_dyn();}  \
virtual Void removeNotificationTarget( ::hsl::haxe::Signaler value) { return mDelegate->removeNotificationTarget(value);}  \
virtual Dynamic removeNotificationTarget_dyn() { return mDelegate->removeNotificationTarget_dyn();}  \
virtual Void removeBubblingTarget( ::hsl::haxe::Signaler value) { return mDelegate->removeBubblingTarget(value);}  \
virtual Dynamic removeBubblingTarget_dyn() { return mDelegate->removeBubblingTarget_dyn();}  \
virtual bool getIsListenedTo( ) { return mDelegate->getIsListenedTo();}  \
virtual Dynamic getIsListenedTo_dyn() { return mDelegate->getIsListenedTo_dyn();}  \
virtual Void dispatch( Dynamic data,Dynamic origin,Dynamic positionInformation) { return mDelegate->dispatch(data,origin,positionInformation);}  \
virtual Dynamic dispatch_dyn() { return mDelegate->dispatch_dyn();}  \
virtual ::hsl::haxe::Bond bindVoid( Dynamic listener) { return mDelegate->bindVoid(listener);}  \
virtual Dynamic bindVoid_dyn() { return mDelegate->bindVoid_dyn();}  \
virtual ::hsl::haxe::Bond bindAdvanced( Dynamic listener) { return mDelegate->bindAdvanced(listener);}  \
virtual Dynamic bindAdvanced_dyn() { return mDelegate->bindAdvanced_dyn();}  \
virtual ::hsl::haxe::Bond bind( Dynamic listener) { return mDelegate->bind(listener);}  \
virtual Dynamic bind_dyn() { return mDelegate->bind_dyn();}  \
virtual Void addNotificationTarget( ::hsl::haxe::Signaler value) { return mDelegate->addNotificationTarget(value);}  \
virtual Dynamic addNotificationTarget_dyn() { return mDelegate->addNotificationTarget_dyn();}  \
virtual Void addBubblingTarget( ::hsl::haxe::Signaler value) { return mDelegate->addBubblingTarget(value);}  \
virtual Dynamic addBubblingTarget_dyn() { return mDelegate->addBubblingTarget_dyn();}  \


template<typename IMPL>
class Signaler_delegate_ : public Signaler_obj
{
	protected:
		IMPL *mDelegate;
	public:
		Signaler_delegate_(IMPL *inDelegate) : mDelegate(inDelegate) {}
		hx::Object *__GetRealObject() { return mDelegate; }
		void __Visit(HX_VISIT_PARAMS) { HX_VISIT_OBJECT(mDelegate); }
		DELEGATE_hsl_haxe_Signaler
};

} // end namespace hsl
} // end namespace haxe

#endif /* INCLUDED_hsl_haxe_Signaler */ 
