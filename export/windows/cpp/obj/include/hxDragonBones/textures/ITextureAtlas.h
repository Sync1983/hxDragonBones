#ifndef INCLUDED_hxDragonBones_textures_ITextureAtlas
#define INCLUDED_hxDragonBones_textures_ITextureAtlas

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <hxDragonBones/utils/IDisposable.h>
HX_DECLARE_CLASS2(hxDragonBones,textures,ITextureAtlas)
HX_DECLARE_CLASS2(hxDragonBones,utils,IDisposable)
HX_DECLARE_CLASS2(native,geom,Rectangle)
namespace hxDragonBones{
namespace textures{


class ITextureAtlas_obj : public hx::Interface{
	public:
		typedef hx::Interface super;
		typedef ITextureAtlas_obj OBJ_;
		HX_DO_INTERFACE_RTTI;
		static void __boot();
virtual ::native::geom::Rectangle getRegion( ::String name)=0;
		Dynamic getRegion_dyn();
};

#define DELEGATE_hxDragonBones_textures_ITextureAtlas \
virtual ::native::geom::Rectangle getRegion( ::String name) { return mDelegate->getRegion(name);}  \
virtual Dynamic getRegion_dyn() { return mDelegate->getRegion_dyn();}  \


template<typename IMPL>
class ITextureAtlas_delegate_ : public ITextureAtlas_obj
{
	protected:
		IMPL *mDelegate;
	public:
		ITextureAtlas_delegate_(IMPL *inDelegate) : mDelegate(inDelegate) {}
		hx::Object *__GetRealObject() { return mDelegate; }
		void __Visit(HX_VISIT_PARAMS) { HX_VISIT_OBJECT(mDelegate); }
		DELEGATE_hxDragonBones_textures_ITextureAtlas
};

} // end namespace hxDragonBones
} // end namespace textures

#endif /* INCLUDED_hxDragonBones_textures_ITextureAtlas */ 
