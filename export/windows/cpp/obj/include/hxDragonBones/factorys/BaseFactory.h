#ifndef INCLUDED_hxDragonBones_factorys_BaseFactory
#define INCLUDED_hxDragonBones_factorys_BaseFactory

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(Hash)
HX_DECLARE_CLASS2(haxe,io,Bytes)
HX_DECLARE_CLASS2(hsl,haxe,Signaler)
HX_DECLARE_CLASS1(hxDragonBones,Armature)
HX_DECLARE_CLASS1(hxDragonBones,Bone)
HX_DECLARE_CLASS2(hxDragonBones,animation,IAnimatable)
HX_DECLARE_CLASS2(hxDragonBones,factorys,BaseFactory)
HX_DECLARE_CLASS2(hxDragonBones,objects,BoneData)
HX_DECLARE_CLASS2(hxDragonBones,objects,SkeletonData)
HX_DECLARE_CLASS2(hxDragonBones,textures,ITextureAtlas)
HX_DECLARE_CLASS2(hxDragonBones,utils,IDisposable)
HX_DECLARE_CLASS2(native,display,LoaderInfo)
HX_DECLARE_CLASS2(native,events,Event)
HX_DECLARE_CLASS2(native,events,EventDispatcher)
HX_DECLARE_CLASS2(native,events,IEventDispatcher)
HX_DECLARE_CLASS2(native,geom,Matrix)
HX_DECLARE_CLASS2(native,net,URLLoader)
HX_DECLARE_CLASS2(native,utils,ByteArray)
HX_DECLARE_CLASS2(native,utils,IDataInput)
HX_DECLARE_CLASS2(native,utils,IMemoryRange)
HX_DECLARE_CLASS1(nme,ObjectHash)
namespace hxDragonBones{
namespace factorys{


class BaseFactory_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef BaseFactory_obj OBJ_;
		BaseFactory_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< BaseFactory_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~BaseFactory_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("BaseFactory"); }

		virtual Dynamic createTextureDisplay( ::hxDragonBones::textures::ITextureAtlas texAtlas,::String fullName,hx::Null< int >  pivotX,hx::Null< int >  pivotY);
		Dynamic createTextureDisplay_dyn();

		virtual ::hxDragonBones::Bone createBone( );
		Dynamic createBone_dyn();

		virtual ::hxDragonBones::Armature createArmature( );
		Dynamic createArmature_dyn();

		virtual ::hxDragonBones::textures::ITextureAtlas createTextureAtlas( Dynamic content,Dynamic textureAtlasXML);
		Dynamic createTextureAtlas_dyn();

		virtual Dynamic getContent( ::native::display::LoaderInfo loaderInfo);
		Dynamic getContent_dyn();

		virtual ::hxDragonBones::Bone buildBone( ::hxDragonBones::objects::BoneData boneData);
		Dynamic buildBone_dyn();

		virtual Void loaderCompleteHandler( ::native::events::Event event);
		Dynamic loaderCompleteHandler_dyn();

		virtual Dynamic getTextureDisplay( ::String texName,::String texAtlasName,Dynamic pivotX,Dynamic pivotY);
		Dynamic getTextureDisplay_dyn();

		virtual ::hxDragonBones::Armature buildArmature( ::String armatureName,::String animationName,::String skeletonName,::String texAtlasName);
		Dynamic buildArmature_dyn();

		virtual Void dispose( hx::Null< bool >  disposeData);
		Dynamic dispose_dyn();

		virtual Void removeTextureAtlas( ::String name);
		Dynamic removeTextureAtlas_dyn();

		virtual Void addTextureAtlas( ::hxDragonBones::textures::ITextureAtlas texAtlas,::String name);
		Dynamic addTextureAtlas_dyn();

		virtual Dynamic getTextureAtlas( ::String name);
		Dynamic getTextureAtlas_dyn();

		virtual Void removeSkeletonData( ::String name);
		Dynamic removeSkeletonData_dyn();

		virtual Void addSkeletonData( ::hxDragonBones::objects::SkeletonData skeletonData,::String name);
		Dynamic addSkeletonData_dyn();

		virtual ::hxDragonBones::objects::SkeletonData getSkeletonData( ::String name);
		Dynamic getSkeletonData_dyn();

		virtual ::hxDragonBones::objects::SkeletonData parseData( ::native::utils::ByteArray bytes,::String skeletonName);
		Dynamic parseData_dyn();

		::String _curTexAtlasName; /* REM */ 
		::String _curSkeletonName; /* REM */ 
		Dynamic _curTexAtlas; /* REM */ 
		::hxDragonBones::objects::SkeletonData _curSkeletonData; /* REM */ 
		::nme::ObjectHash _loader2TexAtlasXML; /* REM */ 
		::Hash _name2TexAtlas; /* REM */ 
		::Hash _name2SkeletonData; /* REM */ 
		::hsl::haxe::Signaler onDataParsed; /* REM */ 
		static ::native::geom::Matrix helpMatrix; /* REM */ 
};

} // end namespace hxDragonBones
} // end namespace factorys

#endif /* INCLUDED_hxDragonBones_factorys_BaseFactory */ 
