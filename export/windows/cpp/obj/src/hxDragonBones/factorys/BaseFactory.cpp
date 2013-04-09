#include <hxcpp.h>

#ifndef INCLUDED_Hash
#include <Hash.h>
#endif
#ifndef INCLUDED_IntHash
#include <IntHash.h>
#endif
#ifndef INCLUDED_Lambda
#include <Lambda.h>
#endif
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_Xml
#include <Xml.h>
#endif
#ifndef INCLUDED_haxe_io_Bytes
#include <haxe/io/Bytes.h>
#endif
#ifndef INCLUDED_hsl_haxe_DirectSignaler
#include <hsl/haxe/DirectSignaler.h>
#endif
#ifndef INCLUDED_hsl_haxe_Signaler
#include <hsl/haxe/Signaler.h>
#endif
#ifndef INCLUDED_hxDragonBones_Armature
#include <hxDragonBones/Armature.h>
#endif
#ifndef INCLUDED_hxDragonBones_Bone
#include <hxDragonBones/Bone.h>
#endif
#ifndef INCLUDED_hxDragonBones_animation_Animation
#include <hxDragonBones/animation/Animation.h>
#endif
#ifndef INCLUDED_hxDragonBones_animation_IAnimatable
#include <hxDragonBones/animation/IAnimatable.h>
#endif
#ifndef INCLUDED_hxDragonBones_display_IDisplayBridge
#include <hxDragonBones/display/IDisplayBridge.h>
#endif
#ifndef INCLUDED_hxDragonBones_display_NativeDisplayBridge
#include <hxDragonBones/display/NativeDisplayBridge.h>
#endif
#ifndef INCLUDED_hxDragonBones_factorys_BaseFactory
#include <hxDragonBones/factorys/BaseFactory.h>
#endif
#ifndef INCLUDED_hxDragonBones_objects_AnimationData
#include <hxDragonBones/objects/AnimationData.h>
#endif
#ifndef INCLUDED_hxDragonBones_objects_ArmatureData
#include <hxDragonBones/objects/ArmatureData.h>
#endif
#ifndef INCLUDED_hxDragonBones_objects_BoneData
#include <hxDragonBones/objects/BoneData.h>
#endif
#ifndef INCLUDED_hxDragonBones_objects_DecompressedData
#include <hxDragonBones/objects/DecompressedData.h>
#endif
#ifndef INCLUDED_hxDragonBones_objects_DisplayData
#include <hxDragonBones/objects/DisplayData.h>
#endif
#ifndef INCLUDED_hxDragonBones_objects_Node
#include <hxDragonBones/objects/Node.h>
#endif
#ifndef INCLUDED_hxDragonBones_objects_SkeletonData
#include <hxDragonBones/objects/SkeletonData.h>
#endif
#ifndef INCLUDED_hxDragonBones_objects_XMLDataParser
#include <hxDragonBones/objects/XMLDataParser.h>
#endif
#ifndef INCLUDED_hxDragonBones_textures_ITextureAtlas
#include <hxDragonBones/textures/ITextureAtlas.h>
#endif
#ifndef INCLUDED_hxDragonBones_textures_NativeTextureAtlas
#include <hxDragonBones/textures/NativeTextureAtlas.h>
#endif
#ifndef INCLUDED_hxDragonBones_textures_SubTextureData
#include <hxDragonBones/textures/SubTextureData.h>
#endif
#ifndef INCLUDED_hxDragonBones_utils_IDisposable
#include <hxDragonBones/utils/IDisposable.h>
#endif
#ifndef INCLUDED_native_display_Bitmap
#include <native/display/Bitmap.h>
#endif
#ifndef INCLUDED_native_display_BitmapData
#include <native/display/BitmapData.h>
#endif
#ifndef INCLUDED_native_display_DisplayObject
#include <native/display/DisplayObject.h>
#endif
#ifndef INCLUDED_native_display_DisplayObjectContainer
#include <native/display/DisplayObjectContainer.h>
#endif
#ifndef INCLUDED_native_display_Graphics
#include <native/display/Graphics.h>
#endif
#ifndef INCLUDED_native_display_IBitmapDrawable
#include <native/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_native_display_InteractiveObject
#include <native/display/InteractiveObject.h>
#endif
#ifndef INCLUDED_native_display_Loader
#include <native/display/Loader.h>
#endif
#ifndef INCLUDED_native_display_LoaderInfo
#include <native/display/LoaderInfo.h>
#endif
#ifndef INCLUDED_native_display_MovieClip
#include <native/display/MovieClip.h>
#endif
#ifndef INCLUDED_native_display_Shape
#include <native/display/Shape.h>
#endif
#ifndef INCLUDED_native_display_Sprite
#include <native/display/Sprite.h>
#endif
#ifndef INCLUDED_native_events_Event
#include <native/events/Event.h>
#endif
#ifndef INCLUDED_native_events_EventDispatcher
#include <native/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_native_events_IEventDispatcher
#include <native/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_native_geom_Matrix
#include <native/geom/Matrix.h>
#endif
#ifndef INCLUDED_native_geom_Rectangle
#include <native/geom/Rectangle.h>
#endif
#ifndef INCLUDED_native_net_URLLoader
#include <native/net/URLLoader.h>
#endif
#ifndef INCLUDED_native_utils_ByteArray
#include <native/utils/ByteArray.h>
#endif
#ifndef INCLUDED_native_utils_IDataInput
#include <native/utils/IDataInput.h>
#endif
#ifndef INCLUDED_native_utils_IMemoryRange
#include <native/utils/IMemoryRange.h>
#endif
#ifndef INCLUDED_nme_ObjectHash
#include <nme/ObjectHash.h>
#endif
namespace hxDragonBones{
namespace factorys{

Void BaseFactory_obj::__construct()
{
HX_STACK_PUSH("BaseFactory::new","hxDragonBones/factorys/BaseFactory.hx",39);
{
	HX_STACK_LINE(40)
	this->onDataParsed = ::hsl::haxe::DirectSignaler_obj::__new(hx::ObjectPtr<OBJ_>(this),null());
	HX_STACK_LINE(41)
	this->_name2SkeletonData = ::Hash_obj::__new();
	HX_STACK_LINE(42)
	this->_name2TexAtlas = ::Hash_obj::__new();
	HX_STACK_LINE(43)
	this->_loader2TexAtlasXML = ::nme::ObjectHash_obj::__new();
}
;
	return null();
}

BaseFactory_obj::~BaseFactory_obj() { }

Dynamic BaseFactory_obj::__CreateEmpty() { return  new BaseFactory_obj; }
hx::ObjectPtr< BaseFactory_obj > BaseFactory_obj::__new()
{  hx::ObjectPtr< BaseFactory_obj > result = new BaseFactory_obj();
	result->__construct();
	return result;}

Dynamic BaseFactory_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< BaseFactory_obj > result = new BaseFactory_obj();
	result->__construct();
	return result;}

Dynamic BaseFactory_obj::createTextureDisplay( ::hxDragonBones::textures::ITextureAtlas texAtlas,::String fullName,hx::Null< int >  __o_pivotX,hx::Null< int >  __o_pivotY){
int pivotX = __o_pivotX.Default(0);
int pivotY = __o_pivotY.Default(0);
	HX_STACK_PUSH("BaseFactory::createTextureDisplay","hxDragonBones/factorys/BaseFactory.hx",311);
	HX_STACK_THIS(this);
	HX_STACK_ARG(texAtlas,"texAtlas");
	HX_STACK_ARG(fullName,"fullName");
	HX_STACK_ARG(pivotX,"pivotX");
	HX_STACK_ARG(pivotY,"pivotY");
{
		HX_STACK_LINE(312)
		if ((::Std_obj::is(texAtlas,hx::ClassOf< ::hxDragonBones::textures::NativeTextureAtlas >()))){
			HX_STACK_LINE(313)
			::hxDragonBones::textures::NativeTextureAtlas nativeTexAtlas = hx::TCast< hxDragonBones::textures::NativeTextureAtlas >::cast(texAtlas);		HX_STACK_VAR(nativeTexAtlas,"nativeTexAtlas");
			HX_STACK_LINE(314)
			::native::display::MovieClip clip = nativeTexAtlas->movieClip;		HX_STACK_VAR(clip,"clip");
			HX_STACK_LINE(315)
			if (((bool((clip != null())) && bool((clip->get_totalFrames() >= (int)3))))){
				HX_STACK_LINE(316)
				clip->gotoAndStop(clip->get_totalFrames(),null());
				HX_STACK_LINE(317)
				clip->gotoAndStop(fullName,null());
				HX_STACK_LINE(318)
				if (((clip->get_numChildren() > (int)0))){
					HX_STACK_LINE(319)
					::native::display::DisplayObject displayObject = clip->getChildAt((int)0);		HX_STACK_VAR(displayObject,"displayObject");
					HX_STACK_LINE(320)
					displayObject->set_x((int)0);
					HX_STACK_LINE(321)
					displayObject->set_y((int)0);
					HX_STACK_LINE(322)
					return displayObject;
				}
			}
			else{
				HX_STACK_LINE(324)
				if (((nativeTexAtlas->bitmapData != null()))){
					HX_STACK_LINE(325)
					::native::geom::Rectangle rect = nativeTexAtlas->getRegion(fullName);		HX_STACK_VAR(rect,"rect");
					HX_STACK_LINE(326)
					if ((::Std_obj::is(rect,hx::ClassOf< ::hxDragonBones::textures::SubTextureData >()))){
						HX_STACK_LINE(327)
						::hxDragonBones::textures::SubTextureData subTexData = hx::TCast< hxDragonBones::textures::SubTextureData >::cast(rect);		HX_STACK_VAR(subTexData,"subTexData");
						HX_STACK_LINE(328)
						::native::display::Shape shape = ::native::display::Shape_obj::__new();		HX_STACK_VAR(shape,"shape");
						HX_STACK_LINE(331)
						if (((pivotX == (int)0))){
							HX_STACK_LINE(331)
							pivotX = subTexData->pivotX;
						}
						HX_STACK_LINE(334)
						if (((pivotY == (int)0))){
							HX_STACK_LINE(334)
							pivotY = subTexData->pivotY;
						}
						HX_STACK_LINE(338)
						::hxDragonBones::factorys::BaseFactory_obj::helpMatrix->identity();
						HX_STACK_LINE(339)
						::hxDragonBones::factorys::BaseFactory_obj::helpMatrix->scale(nativeTexAtlas->scale,nativeTexAtlas->scale);
						HX_STACK_LINE(340)
						::hxDragonBones::factorys::BaseFactory_obj::helpMatrix->tx = (-(subTexData->x) - pivotX);
						HX_STACK_LINE(341)
						::hxDragonBones::factorys::BaseFactory_obj::helpMatrix->ty = (-(subTexData->y) - pivotY);
						HX_STACK_LINE(343)
						shape->get_graphics()->beginBitmapFill(nativeTexAtlas->bitmapData,::hxDragonBones::factorys::BaseFactory_obj::helpMatrix,false,true);
						HX_STACK_LINE(344)
						shape->get_graphics()->drawRect(-(pivotX),-(pivotY),subTexData->width,subTexData->height);
						HX_STACK_LINE(345)
						shape->get_graphics()->endFill();
						HX_STACK_LINE(346)
						return shape;
					}
				}
			}
		}
		HX_STACK_LINE(350)
		return null();
	}
}


HX_DEFINE_DYNAMIC_FUNC4(BaseFactory_obj,createTextureDisplay,return )

::hxDragonBones::Bone BaseFactory_obj::createBone( ){
	HX_STACK_PUSH("BaseFactory::createBone","hxDragonBones/factorys/BaseFactory.hx",307);
	HX_STACK_THIS(this);
	HX_STACK_LINE(307)
	return ::hxDragonBones::Bone_obj::__new(::hxDragonBones::display::NativeDisplayBridge_obj::__new());
}


HX_DEFINE_DYNAMIC_FUNC0(BaseFactory_obj,createBone,return )

::hxDragonBones::Armature BaseFactory_obj::createArmature( ){
	HX_STACK_PUSH("BaseFactory::createArmature","hxDragonBones/factorys/BaseFactory.hx",303);
	HX_STACK_THIS(this);
	HX_STACK_LINE(303)
	return ::hxDragonBones::Armature_obj::__new(::native::display::Sprite_obj::__new());
}


HX_DEFINE_DYNAMIC_FUNC0(BaseFactory_obj,createArmature,return )

::hxDragonBones::textures::ITextureAtlas BaseFactory_obj::createTextureAtlas( Dynamic content,Dynamic textureAtlasXML){
	HX_STACK_PUSH("BaseFactory::createTextureAtlas","hxDragonBones/factorys/BaseFactory.hx",299);
	HX_STACK_THIS(this);
	HX_STACK_ARG(content,"content");
	HX_STACK_ARG(textureAtlasXML,"textureAtlasXML");
	HX_STACK_LINE(299)
	return ::hxDragonBones::textures::NativeTextureAtlas_obj::__new(content,hx::TCast< Xml >::cast(textureAtlasXML),null(),null());
}


HX_DEFINE_DYNAMIC_FUNC2(BaseFactory_obj,createTextureAtlas,return )

Dynamic BaseFactory_obj::getContent( ::native::display::LoaderInfo loaderInfo){
	HX_STACK_PUSH("BaseFactory::getContent","hxDragonBones/factorys/BaseFactory.hx",287);
	HX_STACK_THIS(this);
	HX_STACK_ARG(loaderInfo,"loaderInfo");
	HX_STACK_LINE(288)
	if ((::Std_obj::is(loaderInfo->content,hx::ClassOf< ::native::display::Bitmap >()))){
		HX_STACK_LINE(288)
		return (hx::TCast< native::display::Bitmap >::cast(loaderInfo->content))->bitmapData;
	}
	HX_STACK_LINE(292)
	if ((::Std_obj::is(loaderInfo->content,hx::ClassOf< ::native::display::DisplayObjectContainer >()))){
		HX_STACK_LINE(292)
		return (hx::TCast< native::display::DisplayObjectContainer >::cast(loaderInfo->content))->getChildAt((int)0);
	}
	HX_STACK_LINE(296)
	return hx::Throw (HX_CSTRING("non supported type"));
}


HX_DEFINE_DYNAMIC_FUNC1(BaseFactory_obj,getContent,return )

::hxDragonBones::Bone BaseFactory_obj::buildBone( ::hxDragonBones::objects::BoneData boneData){
	HX_STACK_PUSH("BaseFactory::buildBone","hxDragonBones/factorys/BaseFactory.hx",265);
	HX_STACK_THIS(this);
	HX_STACK_ARG(boneData,"boneData");
	HX_STACK_LINE(266)
	::hxDragonBones::Bone bone = this->createBone();		HX_STACK_VAR(bone,"bone");
	HX_STACK_LINE(267)
	bone->origin->copyFrom(boneData->node);
	HX_STACK_LINE(269)
	int i = boneData->displayNames->length;		HX_STACK_VAR(i,"i");
	HX_STACK_LINE(270)
	while((((i)-- > (int)0))){
		HX_STACK_LINE(271)
		::String name = boneData->displayNames->__get(i);		HX_STACK_VAR(name,"name");
		HX_STACK_LINE(272)
		::hxDragonBones::objects::DisplayData data = this->_curSkeletonData->getDisplayData(name);		HX_STACK_VAR(data,"data");
		HX_STACK_LINE(273)
		bone->changeDisplay(i);
		HX_STACK_LINE(274)
		if ((data->isArmature)){
			HX_STACK_LINE(275)
			::hxDragonBones::Armature armature = this->buildArmature(name,null(),this->_curSkeletonName,this->_curTexAtlasName);		HX_STACK_VAR(armature,"armature");
			HX_STACK_LINE(276)
			if (((armature != null()))){
				HX_STACK_LINE(277)
				armature->animation->play();
				HX_STACK_LINE(278)
				bone->set_display(armature);
			}
		}
		else{
			HX_STACK_LINE(280)
			bone->set_display(this->createTextureDisplay(this->_curTexAtlas,name,::Std_obj::_int(data->pivotX),::Std_obj::_int(data->pivotY)));
		}
	}
	HX_STACK_LINE(284)
	return bone;
}


HX_DEFINE_DYNAMIC_FUNC1(BaseFactory_obj,buildBone,return )

Void BaseFactory_obj::loaderCompleteHandler( ::native::events::Event event){
{
		HX_STACK_PUSH("BaseFactory::loaderCompleteHandler","hxDragonBones/factorys/BaseFactory.hx",241);
		HX_STACK_THIS(this);
		HX_STACK_ARG(event,"event");
		HX_STACK_LINE(242)
		::native::display::LoaderInfo loaderInfo = hx::TCast< native::display::LoaderInfo >::cast(event->get_target());		HX_STACK_VAR(loaderInfo,"loaderInfo");
		HX_STACK_LINE(243)
		loaderInfo->removeEventListener(::native::events::Event_obj::COMPLETE,this->loaderCompleteHandler_dyn(),null());
		HX_STACK_LINE(245)
		::Xml texAtlasXML = this->_loader2TexAtlasXML->hashValues->get(::__hxcpp_obj_id(loaderInfo->loader));		HX_STACK_VAR(texAtlasXML,"texAtlasXML");
		HX_STACK_LINE(246)
		{
			HX_STACK_LINE(246)
			::nme::ObjectHash _this = this->_loader2TexAtlasXML;		HX_STACK_VAR(_this,"_this");
			HX_STACK_LINE(246)
			int id = ::__hxcpp_obj_id(loaderInfo->loader);		HX_STACK_VAR(id,"id");
			HX_STACK_LINE(246)
			_this->hashKeys->remove(id);
			HX_STACK_LINE(246)
			_this->hashValues->remove(id);
		}
		HX_STACK_LINE(248)
		if (((bool((loaderInfo->loader->get_name() != null())) && bool((texAtlasXML != null()))))){
			HX_STACK_LINE(250)
			::hxDragonBones::textures::ITextureAtlas texAtlas = this->createTextureAtlas(this->getContent(loaderInfo),texAtlasXML);		HX_STACK_VAR(texAtlas,"texAtlas");
			HX_STACK_LINE(251)
			this->addTextureAtlas(texAtlas,loaderInfo->loader->get_name());
			HX_STACK_LINE(253)
			if (((::Lambda_obj::count(this->_loader2TexAtlasXML,null()) == (int)0))){
				HX_STACK_LINE(253)
				this->onDataParsed->dispatch(null(),null(),hx::SourceInfo(HX_CSTRING("BaseFactory.hx"),254,HX_CSTRING("hxDragonBones.factorys.BaseFactory"),HX_CSTRING("loaderCompleteHandler")));
			}
		}
		HX_STACK_LINE(261)
		loaderInfo->loader->unload();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(BaseFactory_obj,loaderCompleteHandler,(void))

Dynamic BaseFactory_obj::getTextureDisplay( ::String texName,::String texAtlasName,Dynamic pivotX,Dynamic pivotY){
	HX_STACK_PUSH("BaseFactory::getTextureDisplay","hxDragonBones/factorys/BaseFactory.hx",206);
	HX_STACK_THIS(this);
	HX_STACK_ARG(texName,"texName");
	HX_STACK_ARG(texAtlasName,"texAtlasName");
	HX_STACK_ARG(pivotX,"pivotX");
	HX_STACK_ARG(pivotY,"pivotY");
	HX_STACK_LINE(207)
	::hxDragonBones::textures::ITextureAtlas texAtlas = null();		HX_STACK_VAR(texAtlas,"texAtlas");
	HX_STACK_LINE(208)
	if (((texAtlasName != null()))){
		HX_STACK_LINE(208)
		texAtlas = this->_name2TexAtlas->get(texAtlasName);
	}
	else{
		HX_STACK_LINE(210)
		for(::cpp::FastIterator_obj< ::hxDragonBones::textures::ITextureAtlas > *__it = ::cpp::CreateFastIterator< ::hxDragonBones::textures::ITextureAtlas >(this->_name2TexAtlas->iterator());  __it->hasNext(); ){
			::hxDragonBones::textures::ITextureAtlas value = __it->next();
			{
				HX_STACK_LINE(212)
				if (((value->getRegion(texName) != null()))){
					HX_STACK_LINE(213)
					texAtlas = value;
					HX_STACK_LINE(214)
					break;
				}
				HX_STACK_LINE(216)
				texAtlas = null();
			}
;
		}
	}
	HX_STACK_LINE(220)
	if (((texAtlas == null()))){
		HX_STACK_LINE(220)
		return null();
	}
	HX_STACK_LINE(224)
	if (((bool(::Math_obj::isNaN(pivotX)) || bool(::Math_obj::isNaN(pivotY))))){
		HX_STACK_LINE(225)
		::hxDragonBones::objects::SkeletonData skeletonData = this->_name2SkeletonData->get(texAtlasName);		HX_STACK_VAR(skeletonData,"skeletonData");
		HX_STACK_LINE(226)
		if (((skeletonData != null()))){
			HX_STACK_LINE(227)
			::hxDragonBones::objects::DisplayData displayData = skeletonData->getDisplayData(texName);		HX_STACK_VAR(displayData,"displayData");
			HX_STACK_LINE(228)
			if (((displayData != null()))){
				HX_STACK_LINE(229)
				if ((::Math_obj::isNaN(pivotX))){
					HX_STACK_LINE(229)
					pivotX = displayData->pivotX;
				}
				HX_STACK_LINE(232)
				if ((::Math_obj::isNaN(pivotY))){
					HX_STACK_LINE(232)
					pivotY = displayData->pivotY;
				}
			}
		}
	}
	HX_STACK_LINE(238)
	return this->createTextureDisplay(texAtlas,texName,::Std_obj::_int(pivotX),::Std_obj::_int(pivotY));
}


HX_DEFINE_DYNAMIC_FUNC4(BaseFactory_obj,getTextureDisplay,return )

::hxDragonBones::Armature BaseFactory_obj::buildArmature( ::String armatureName,::String animationName,::String skeletonName,::String texAtlasName){
	HX_STACK_PUSH("BaseFactory::buildArmature","hxDragonBones/factorys/BaseFactory.hx",140);
	HX_STACK_THIS(this);
	HX_STACK_ARG(armatureName,"armatureName");
	HX_STACK_ARG(animationName,"animationName");
	HX_STACK_ARG(skeletonName,"skeletonName");
	HX_STACK_ARG(texAtlasName,"texAtlasName");
	HX_STACK_LINE(141)
	if (((animationName == null()))){
		HX_STACK_LINE(141)
		animationName = armatureName;
	}
	HX_STACK_LINE(145)
	::hxDragonBones::objects::SkeletonData skeletonData = null();		HX_STACK_VAR(skeletonData,"skeletonData");
	HX_STACK_LINE(146)
	::hxDragonBones::objects::ArmatureData armatureData = null();		HX_STACK_VAR(armatureData,"armatureData");
	HX_STACK_LINE(147)
	if (((skeletonName != null()))){
		HX_STACK_LINE(148)
		skeletonData = this->_name2SkeletonData->get(skeletonName);
		HX_STACK_LINE(149)
		if (((skeletonData != null()))){
			HX_STACK_LINE(149)
			armatureData = skeletonData->getArmatureData(armatureName);
		}
	}
	else{
		HX_STACK_LINE(152)
		for(::cpp::FastIterator_obj< ::String > *__it = ::cpp::CreateFastIterator< ::String >(this->_name2SkeletonData->keys());  __it->hasNext(); ){
			::String key = __it->next();
			{
				HX_STACK_LINE(154)
				skeletonData = this->_name2SkeletonData->get(key);
				HX_STACK_LINE(155)
				armatureData = skeletonData->getArmatureData(armatureName);
				HX_STACK_LINE(156)
				if (((armatureData != null()))){
					HX_STACK_LINE(157)
					skeletonName = key;
					HX_STACK_LINE(158)
					break;
				}
			}
;
		}
	}
	HX_STACK_LINE(163)
	if (((armatureData == null()))){
		HX_STACK_LINE(163)
		return null();
	}
	HX_STACK_LINE(167)
	this->_curSkeletonName = skeletonName;
	HX_STACK_LINE(168)
	this->_curSkeletonData = skeletonData;
	HX_STACK_LINE(170)
	if (((texAtlasName != null()))){
		HX_STACK_LINE(170)
		this->_curTexAtlasName = texAtlasName;
	}
	else{
		HX_STACK_LINE(172)
		this->_curTexAtlasName = skeletonName;
	}
	HX_STACK_LINE(176)
	this->_curTexAtlas = this->_name2TexAtlas->get(this->_curTexAtlasName);
	HX_STACK_LINE(178)
	::hxDragonBones::objects::AnimationData animationData = this->_curSkeletonData->getAnimationData(animationName);		HX_STACK_VAR(animationData,"animationData");
	HX_STACK_LINE(180)
	if (((animationData == null()))){
		HX_STACK_LINE(180)
		for(::cpp::FastIterator_obj< ::hxDragonBones::objects::SkeletonData > *__it = ::cpp::CreateFastIterator< ::hxDragonBones::objects::SkeletonData >(this->_name2SkeletonData->iterator());  __it->hasNext(); ){
			::hxDragonBones::objects::SkeletonData value = __it->next();
			{
				HX_STACK_LINE(182)
				animationData = value->getAnimationData(animationName);
				HX_STACK_LINE(183)
				if (((animationData != null()))){
					HX_STACK_LINE(183)
					break;
				}
			}
;
		}
	}
	HX_STACK_LINE(189)
	::hxDragonBones::Armature armature = this->createArmature();		HX_STACK_VAR(armature,"armature");
	HX_STACK_LINE(190)
	armature->name = armatureName;
	HX_STACK_LINE(191)
	armature->animation->set_animationData(animationData);
	HX_STACK_LINE(192)
	{
		HX_STACK_LINE(192)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		Array< ::String > _g1 = armatureData->get_boneNames();		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(192)
		while(((_g < _g1->length))){
			HX_STACK_LINE(192)
			::String name = _g1->__get(_g);		HX_STACK_VAR(name,"name");
			HX_STACK_LINE(192)
			++(_g);
			HX_STACK_LINE(193)
			::hxDragonBones::objects::BoneData data = armatureData->getBoneData(name);		HX_STACK_VAR(data,"data");
			HX_STACK_LINE(194)
			if (((data != null()))){
				HX_STACK_LINE(195)
				::hxDragonBones::Bone bone = this->buildBone(data);		HX_STACK_VAR(bone,"bone");
				HX_STACK_LINE(196)
				bone->name = name;
				HX_STACK_LINE(197)
				armature->addBone(bone,data->parent);
			}
		}
	}
	HX_STACK_LINE(200)
	armature->bonesIndexChanged = true;
	HX_STACK_LINE(201)
	armature->update();
	HX_STACK_LINE(202)
	return armature;
}


HX_DEFINE_DYNAMIC_FUNC4(BaseFactory_obj,buildArmature,return )

Void BaseFactory_obj::dispose( hx::Null< bool >  __o_disposeData){
bool disposeData = __o_disposeData.Default(true);
	HX_STACK_PUSH("BaseFactory::dispose","hxDragonBones/factorys/BaseFactory.hx",121);
	HX_STACK_THIS(this);
	HX_STACK_ARG(disposeData,"disposeData");
{
		HX_STACK_LINE(122)
		if ((disposeData)){
			HX_STACK_LINE(123)
			for(::cpp::FastIterator_obj< ::hxDragonBones::objects::SkeletonData > *__it = ::cpp::CreateFastIterator< ::hxDragonBones::objects::SkeletonData >(this->_name2SkeletonData->iterator());  __it->hasNext(); ){
				::hxDragonBones::objects::SkeletonData i = __it->next();
				i->dispose();
			}
			HX_STACK_LINE(126)
			for(::cpp::FastIterator_obj< ::hxDragonBones::textures::ITextureAtlas > *__it = ::cpp::CreateFastIterator< ::hxDragonBones::textures::ITextureAtlas >(this->_name2TexAtlas->iterator());  __it->hasNext(); ){
				::hxDragonBones::textures::ITextureAtlas i = __it->next();
				i->__Field(HX_CSTRING("dispose"),true)();
			}
		}
		HX_STACK_LINE(131)
		this->_name2SkeletonData = null();
		HX_STACK_LINE(132)
		this->_name2TexAtlas = null();
		HX_STACK_LINE(133)
		this->_loader2TexAtlasXML = null();
		HX_STACK_LINE(134)
		this->_curSkeletonData = null();
		HX_STACK_LINE(135)
		this->_curTexAtlas = null();
		HX_STACK_LINE(136)
		this->_curSkeletonName = null();
		HX_STACK_LINE(137)
		this->_curTexAtlasName = null();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(BaseFactory_obj,dispose,(void))

Void BaseFactory_obj::removeTextureAtlas( ::String name){
{
		HX_STACK_PUSH("BaseFactory::removeTextureAtlas","hxDragonBones/factorys/BaseFactory.hx",117);
		HX_STACK_THIS(this);
		HX_STACK_ARG(name,"name");
		HX_STACK_LINE(117)
		this->_name2TexAtlas->remove(name);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(BaseFactory_obj,removeTextureAtlas,(void))

Void BaseFactory_obj::addTextureAtlas( ::hxDragonBones::textures::ITextureAtlas texAtlas,::String name){
{
		HX_STACK_PUSH("BaseFactory::addTextureAtlas","hxDragonBones/factorys/BaseFactory.hx",104);
		HX_STACK_THIS(this);
		HX_STACK_ARG(texAtlas,"texAtlas");
		HX_STACK_ARG(name,"name");
		HX_STACK_LINE(105)
		if (((name == null()))){
			HX_STACK_LINE(105)
			name = texAtlas->__Field(HX_CSTRING("name"),true);
		}
		HX_STACK_LINE(109)
		if (((name == null()))){
			HX_STACK_LINE(109)
			hx::Throw (HX_CSTRING("Unnamed data!"));
		}
		HX_STACK_LINE(113)
		this->_name2TexAtlas->set(name,texAtlas);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(BaseFactory_obj,addTextureAtlas,(void))

Dynamic BaseFactory_obj::getTextureAtlas( ::String name){
	HX_STACK_PUSH("BaseFactory::getTextureAtlas","hxDragonBones/factorys/BaseFactory.hx",99);
	HX_STACK_THIS(this);
	HX_STACK_ARG(name,"name");
	HX_STACK_LINE(99)
	return this->_name2TexAtlas->get(name);
}


HX_DEFINE_DYNAMIC_FUNC1(BaseFactory_obj,getTextureAtlas,return )

Void BaseFactory_obj::removeSkeletonData( ::String name){
{
		HX_STACK_PUSH("BaseFactory::removeSkeletonData","hxDragonBones/factorys/BaseFactory.hx",94);
		HX_STACK_THIS(this);
		HX_STACK_ARG(name,"name");
		HX_STACK_LINE(94)
		this->_name2SkeletonData->remove(name);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(BaseFactory_obj,removeSkeletonData,(void))

Void BaseFactory_obj::addSkeletonData( ::hxDragonBones::objects::SkeletonData skeletonData,::String name){
{
		HX_STACK_PUSH("BaseFactory::addSkeletonData","hxDragonBones/factorys/BaseFactory.hx",81);
		HX_STACK_THIS(this);
		HX_STACK_ARG(skeletonData,"skeletonData");
		HX_STACK_ARG(name,"name");
		HX_STACK_LINE(82)
		if (((name == null()))){
			HX_STACK_LINE(82)
			name = skeletonData->name;
		}
		HX_STACK_LINE(86)
		if (((name == null()))){
			HX_STACK_LINE(86)
			hx::Throw (HX_CSTRING("Unnamed data!"));
		}
		HX_STACK_LINE(90)
		this->_name2SkeletonData->set(name,skeletonData);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(BaseFactory_obj,addSkeletonData,(void))

::hxDragonBones::objects::SkeletonData BaseFactory_obj::getSkeletonData( ::String name){
	HX_STACK_PUSH("BaseFactory::getSkeletonData","hxDragonBones/factorys/BaseFactory.hx",76);
	HX_STACK_THIS(this);
	HX_STACK_ARG(name,"name");
	HX_STACK_LINE(76)
	return this->_name2SkeletonData->get(name);
}


HX_DEFINE_DYNAMIC_FUNC1(BaseFactory_obj,getSkeletonData,return )

::hxDragonBones::objects::SkeletonData BaseFactory_obj::parseData( ::native::utils::ByteArray bytes,::String skeletonName){
	HX_STACK_PUSH("BaseFactory::parseData","hxDragonBones/factorys/BaseFactory.hx",56);
	HX_STACK_THIS(this);
	HX_STACK_ARG(bytes,"bytes");
	HX_STACK_ARG(skeletonName,"skeletonName");
	HX_STACK_LINE(57)
	::hxDragonBones::objects::DecompressedData decompressedData = ::hxDragonBones::objects::XMLDataParser_obj::decompressData(bytes);		HX_STACK_VAR(decompressedData,"decompressedData");
	HX_STACK_LINE(59)
	::hxDragonBones::objects::SkeletonData skeletonData = ::hxDragonBones::objects::XMLDataParser_obj::parseSkeletonData(decompressedData->skeletonXml);		HX_STACK_VAR(skeletonData,"skeletonData");
	HX_STACK_LINE(60)
	if (((skeletonName == null()))){
		HX_STACK_LINE(60)
		skeletonName = skeletonData->name;
	}
	HX_STACK_LINE(63)
	this->addSkeletonData(skeletonData,skeletonName);
	HX_STACK_LINE(65)
	::native::display::Loader loader = ::native::display::Loader_obj::__new();		HX_STACK_VAR(loader,"loader");
	HX_STACK_LINE(66)
	{
		HX_STACK_LINE(66)
		::nme::ObjectHash _this = this->_loader2TexAtlasXML;		HX_STACK_VAR(_this,"_this");
		HX_STACK_LINE(66)
		int id = ::__hxcpp_obj_id(loader);		HX_STACK_VAR(id,"id");
		HX_STACK_LINE(66)
		_this->hashKeys->set(id,loader);
		HX_STACK_LINE(66)
		_this->hashValues->set(id,decompressedData->texAtlasXml);
	}
	HX_STACK_LINE(67)
	loader->set_name(skeletonName);
	HX_STACK_LINE(68)
	loader->contentLoaderInfo->addEventListener(::native::events::Event_obj::COMPLETE,this->loaderCompleteHandler_dyn(),null(),null(),null());
	HX_STACK_LINE(69)
	loader->loadBytes(decompressedData->texBytes);
	HX_STACK_LINE(71)
	decompressedData->dispose();
	HX_STACK_LINE(72)
	return skeletonData;
}


HX_DEFINE_DYNAMIC_FUNC2(BaseFactory_obj,parseData,return )

::native::geom::Matrix BaseFactory_obj::helpMatrix;


BaseFactory_obj::BaseFactory_obj()
{
}

void BaseFactory_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(BaseFactory);
	HX_MARK_MEMBER_NAME(_curTexAtlasName,"_curTexAtlasName");
	HX_MARK_MEMBER_NAME(_curSkeletonName,"_curSkeletonName");
	HX_MARK_MEMBER_NAME(_curTexAtlas,"_curTexAtlas");
	HX_MARK_MEMBER_NAME(_curSkeletonData,"_curSkeletonData");
	HX_MARK_MEMBER_NAME(_loader2TexAtlasXML,"_loader2TexAtlasXML");
	HX_MARK_MEMBER_NAME(_name2TexAtlas,"_name2TexAtlas");
	HX_MARK_MEMBER_NAME(_name2SkeletonData,"_name2SkeletonData");
	HX_MARK_MEMBER_NAME(onDataParsed,"onDataParsed");
	HX_MARK_END_CLASS();
}

void BaseFactory_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_curTexAtlasName,"_curTexAtlasName");
	HX_VISIT_MEMBER_NAME(_curSkeletonName,"_curSkeletonName");
	HX_VISIT_MEMBER_NAME(_curTexAtlas,"_curTexAtlas");
	HX_VISIT_MEMBER_NAME(_curSkeletonData,"_curSkeletonData");
	HX_VISIT_MEMBER_NAME(_loader2TexAtlasXML,"_loader2TexAtlasXML");
	HX_VISIT_MEMBER_NAME(_name2TexAtlas,"_name2TexAtlas");
	HX_VISIT_MEMBER_NAME(_name2SkeletonData,"_name2SkeletonData");
	HX_VISIT_MEMBER_NAME(onDataParsed,"onDataParsed");
}

Dynamic BaseFactory_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"dispose") ) { return dispose_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"buildBone") ) { return buildBone_dyn(); }
		if (HX_FIELD_EQ(inName,"parseData") ) { return parseData_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"helpMatrix") ) { return helpMatrix; }
		if (HX_FIELD_EQ(inName,"createBone") ) { return createBone_dyn(); }
		if (HX_FIELD_EQ(inName,"getContent") ) { return getContent_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"_curTexAtlas") ) { return _curTexAtlas; }
		if (HX_FIELD_EQ(inName,"onDataParsed") ) { return onDataParsed; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"buildArmature") ) { return buildArmature_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"createArmature") ) { return createArmature_dyn(); }
		if (HX_FIELD_EQ(inName,"_name2TexAtlas") ) { return _name2TexAtlas; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"addTextureAtlas") ) { return addTextureAtlas_dyn(); }
		if (HX_FIELD_EQ(inName,"getTextureAtlas") ) { return getTextureAtlas_dyn(); }
		if (HX_FIELD_EQ(inName,"addSkeletonData") ) { return addSkeletonData_dyn(); }
		if (HX_FIELD_EQ(inName,"getSkeletonData") ) { return getSkeletonData_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"_curTexAtlasName") ) { return _curTexAtlasName; }
		if (HX_FIELD_EQ(inName,"_curSkeletonName") ) { return _curSkeletonName; }
		if (HX_FIELD_EQ(inName,"_curSkeletonData") ) { return _curSkeletonData; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"getTextureDisplay") ) { return getTextureDisplay_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"createTextureAtlas") ) { return createTextureAtlas_dyn(); }
		if (HX_FIELD_EQ(inName,"removeTextureAtlas") ) { return removeTextureAtlas_dyn(); }
		if (HX_FIELD_EQ(inName,"removeSkeletonData") ) { return removeSkeletonData_dyn(); }
		if (HX_FIELD_EQ(inName,"_name2SkeletonData") ) { return _name2SkeletonData; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"_loader2TexAtlasXML") ) { return _loader2TexAtlasXML; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"createTextureDisplay") ) { return createTextureDisplay_dyn(); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"loaderCompleteHandler") ) { return loaderCompleteHandler_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic BaseFactory_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 10:
		if (HX_FIELD_EQ(inName,"helpMatrix") ) { helpMatrix=inValue.Cast< ::native::geom::Matrix >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"_curTexAtlas") ) { _curTexAtlas=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"onDataParsed") ) { onDataParsed=inValue.Cast< ::hsl::haxe::Signaler >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"_name2TexAtlas") ) { _name2TexAtlas=inValue.Cast< ::Hash >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"_curTexAtlasName") ) { _curTexAtlasName=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_curSkeletonName") ) { _curSkeletonName=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_curSkeletonData") ) { _curSkeletonData=inValue.Cast< ::hxDragonBones::objects::SkeletonData >(); return inValue; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"_name2SkeletonData") ) { _name2SkeletonData=inValue.Cast< ::Hash >(); return inValue; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"_loader2TexAtlasXML") ) { _loader2TexAtlasXML=inValue.Cast< ::nme::ObjectHash >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void BaseFactory_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_curTexAtlasName"));
	outFields->push(HX_CSTRING("_curSkeletonName"));
	outFields->push(HX_CSTRING("_curTexAtlas"));
	outFields->push(HX_CSTRING("_curSkeletonData"));
	outFields->push(HX_CSTRING("_loader2TexAtlasXML"));
	outFields->push(HX_CSTRING("_name2TexAtlas"));
	outFields->push(HX_CSTRING("_name2SkeletonData"));
	outFields->push(HX_CSTRING("onDataParsed"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("helpMatrix"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("createTextureDisplay"),
	HX_CSTRING("createBone"),
	HX_CSTRING("createArmature"),
	HX_CSTRING("createTextureAtlas"),
	HX_CSTRING("getContent"),
	HX_CSTRING("buildBone"),
	HX_CSTRING("loaderCompleteHandler"),
	HX_CSTRING("getTextureDisplay"),
	HX_CSTRING("buildArmature"),
	HX_CSTRING("dispose"),
	HX_CSTRING("removeTextureAtlas"),
	HX_CSTRING("addTextureAtlas"),
	HX_CSTRING("getTextureAtlas"),
	HX_CSTRING("removeSkeletonData"),
	HX_CSTRING("addSkeletonData"),
	HX_CSTRING("getSkeletonData"),
	HX_CSTRING("parseData"),
	HX_CSTRING("_curTexAtlasName"),
	HX_CSTRING("_curSkeletonName"),
	HX_CSTRING("_curTexAtlas"),
	HX_CSTRING("_curSkeletonData"),
	HX_CSTRING("_loader2TexAtlasXML"),
	HX_CSTRING("_name2TexAtlas"),
	HX_CSTRING("_name2SkeletonData"),
	HX_CSTRING("onDataParsed"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(BaseFactory_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(BaseFactory_obj::helpMatrix,"helpMatrix");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(BaseFactory_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(BaseFactory_obj::helpMatrix,"helpMatrix");
};

Class BaseFactory_obj::__mClass;

void BaseFactory_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("hxDragonBones.factorys.BaseFactory"), hx::TCanCast< BaseFactory_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void BaseFactory_obj::__boot()
{
	helpMatrix= ::native::geom::Matrix_obj::__new(null(),null(),null(),null(),null(),null());
}

} // end namespace hxDragonBones
} // end namespace factorys
