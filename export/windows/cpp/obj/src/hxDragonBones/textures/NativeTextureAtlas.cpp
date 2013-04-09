#include <hxcpp.h>

#ifndef INCLUDED_Hash
#include <Hash.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_Xml
#include <Xml.h>
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
#ifndef INCLUDED_native_display_BitmapData
#include <native/display/BitmapData.h>
#endif
#ifndef INCLUDED_native_display_DisplayObject
#include <native/display/DisplayObject.h>
#endif
#ifndef INCLUDED_native_display_DisplayObjectContainer
#include <native/display/DisplayObjectContainer.h>
#endif
#ifndef INCLUDED_native_display_IBitmapDrawable
#include <native/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_native_display_InteractiveObject
#include <native/display/InteractiveObject.h>
#endif
#ifndef INCLUDED_native_display_MovieClip
#include <native/display/MovieClip.h>
#endif
#ifndef INCLUDED_native_display_Sprite
#include <native/display/Sprite.h>
#endif
#ifndef INCLUDED_native_events_EventDispatcher
#include <native/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_native_events_IEventDispatcher
#include <native/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_native_geom_Rectangle
#include <native/geom/Rectangle.h>
#endif
namespace hxDragonBones{
namespace textures{

Void NativeTextureAtlas_obj::__construct(Dynamic texture,::Xml texAtlasXml,hx::Null< Float >  __o_scale,Dynamic isDifferentXML)
{
HX_STACK_PUSH("NativeTextureAtlas::new","hxDragonBones/textures/NativeTextureAtlas.hx",15);
Float scale = __o_scale.Default(1);
{
	HX_STACK_LINE(16)
	this->scale = scale;
	HX_STACK_LINE(17)
	this->_isDifferentXML = isDifferentXML;
	HX_STACK_LINE(19)
	this->_name2SubTexData = ::Hash_obj::__new();
	HX_STACK_LINE(21)
	if ((::Std_obj::is(texture,hx::ClassOf< ::native::display::BitmapData >()))){
		HX_STACK_LINE(21)
		this->bitmapData = hx::TCast< native::display::BitmapData >::cast(texture);
	}
	else{
		HX_STACK_LINE(23)
		if ((::Std_obj::is(texture,hx::ClassOf< ::native::display::MovieClip >()))){
			HX_STACK_LINE(24)
			this->movieClip = hx::TCast< native::display::MovieClip >::cast(texture);
			HX_STACK_LINE(25)
			this->movieClip->stop();
		}
	}
	HX_STACK_LINE(28)
	this->parseData(texAtlasXml);
}
;
	return null();
}

NativeTextureAtlas_obj::~NativeTextureAtlas_obj() { }

Dynamic NativeTextureAtlas_obj::__CreateEmpty() { return  new NativeTextureAtlas_obj; }
hx::ObjectPtr< NativeTextureAtlas_obj > NativeTextureAtlas_obj::__new(Dynamic texture,::Xml texAtlasXml,hx::Null< Float >  __o_scale,Dynamic isDifferentXML)
{  hx::ObjectPtr< NativeTextureAtlas_obj > result = new NativeTextureAtlas_obj();
	result->__construct(texture,texAtlasXml,__o_scale,isDifferentXML);
	return result;}

Dynamic NativeTextureAtlas_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< NativeTextureAtlas_obj > result = new NativeTextureAtlas_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3]);
	return result;}

hx::Object *NativeTextureAtlas_obj::__ToInterface(const type_info &inType) {
	if (inType==typeid( ::hxDragonBones::textures::ITextureAtlas_obj)) return operator ::hxDragonBones::textures::ITextureAtlas_obj *();
	if (inType==typeid( ::hxDragonBones::utils::IDisposable_obj)) return operator ::hxDragonBones::utils::IDisposable_obj *();
	return super::__ToInterface(inType);
}

Void NativeTextureAtlas_obj::parseData( ::Xml texAtlasXml){
{
		HX_STACK_PUSH("NativeTextureAtlas::parseData","hxDragonBones/textures/NativeTextureAtlas.hx",59);
		HX_STACK_THIS(this);
		HX_STACK_ARG(texAtlasXml,"texAtlasXml");
		HX_STACK_LINE(60)
		this->name = texAtlasXml->firstElement()->get(HX_CSTRING("name"));
		HX_STACK_LINE(62)
		Float scale = (  ((this->_isDifferentXML)) ? Float(this->scale) : Float((int)1) );		HX_STACK_VAR(scale,"scale");
		HX_STACK_LINE(64)
		for(::cpp::FastIterator_obj< ::Xml > *__it = ::cpp::CreateFastIterator< ::Xml >(texAtlasXml->firstElement()->elementsNamed(HX_CSTRING("SubTexture")));  __it->hasNext(); ){
			::Xml subTexXml = __it->next();
			{
				HX_STACK_LINE(65)
				::String subTexName = subTexXml->get(HX_CSTRING("name"));		HX_STACK_VAR(subTexName,"subTexName");
				HX_STACK_LINE(66)
				::hxDragonBones::textures::SubTextureData subTexData = ::hxDragonBones::textures::SubTextureData_obj::__new(null(),null(),null(),null());		HX_STACK_VAR(subTexData,"subTexData");
				HX_STACK_LINE(68)
				subTexData->x = (Float(::Std_obj::parseInt(subTexXml->get(HX_CSTRING("x")))) / Float(scale));
				HX_STACK_LINE(69)
				subTexData->y = (Float(::Std_obj::parseInt(subTexXml->get(HX_CSTRING("y")))) / Float(scale));
				HX_STACK_LINE(70)
				subTexData->width = (Float(::Std_obj::parseInt(subTexXml->get(HX_CSTRING("width")))) / Float(scale));
				HX_STACK_LINE(71)
				subTexData->height = (Float(::Std_obj::parseInt(subTexXml->get(HX_CSTRING("height")))) / Float(scale));
				HX_STACK_LINE(74)
				subTexData->pivotX = ::Std_obj::parseInt(subTexXml->get(HX_CSTRING("pX")));
				HX_STACK_LINE(75)
				subTexData->pivotY = ::Std_obj::parseInt(subTexXml->get(HX_CSTRING("pY")));
				HX_STACK_LINE(77)
				this->_name2SubTexData->set(subTexName,subTexData);
			}
;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(NativeTextureAtlas_obj,parseData,(void))

::native::geom::Rectangle NativeTextureAtlas_obj::getRegion( ::String name){
	HX_STACK_PUSH("NativeTextureAtlas::getRegion","hxDragonBones/textures/NativeTextureAtlas.hx",53);
	HX_STACK_THIS(this);
	HX_STACK_ARG(name,"name");
	HX_STACK_LINE(53)
	return this->_name2SubTexData->get(name);
}


HX_DEFINE_DYNAMIC_FUNC1(NativeTextureAtlas_obj,getRegion,return )

Void NativeTextureAtlas_obj::dispose( ){
{
		HX_STACK_PUSH("NativeTextureAtlas::dispose","hxDragonBones/textures/NativeTextureAtlas.hx",42);
		HX_STACK_THIS(this);
		HX_STACK_LINE(43)
		this->movieClip = null();
		HX_STACK_LINE(45)
		if (((this->bitmapData != null()))){
			HX_STACK_LINE(46)
			this->bitmapData->dispose();
			HX_STACK_LINE(47)
			this->bitmapData = null();
		}
		HX_STACK_LINE(50)
		this->_name2SubTexData = null();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(NativeTextureAtlas_obj,dispose,(void))


NativeTextureAtlas_obj::NativeTextureAtlas_obj()
{
}

void NativeTextureAtlas_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(NativeTextureAtlas);
	HX_MARK_MEMBER_NAME(name,"name");
	HX_MARK_MEMBER_NAME(_isDifferentXML,"_isDifferentXML");
	HX_MARK_MEMBER_NAME(_name2SubTexData,"_name2SubTexData");
	HX_MARK_MEMBER_NAME(scale,"scale");
	HX_MARK_MEMBER_NAME(bitmapData,"bitmapData");
	HX_MARK_MEMBER_NAME(movieClip,"movieClip");
	HX_MARK_END_CLASS();
}

void NativeTextureAtlas_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(name,"name");
	HX_VISIT_MEMBER_NAME(_isDifferentXML,"_isDifferentXML");
	HX_VISIT_MEMBER_NAME(_name2SubTexData,"_name2SubTexData");
	HX_VISIT_MEMBER_NAME(scale,"scale");
	HX_VISIT_MEMBER_NAME(bitmapData,"bitmapData");
	HX_VISIT_MEMBER_NAME(movieClip,"movieClip");
}

Dynamic NativeTextureAtlas_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"name") ) { return name; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"scale") ) { return scale; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"dispose") ) { return dispose_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"parseData") ) { return parseData_dyn(); }
		if (HX_FIELD_EQ(inName,"getRegion") ) { return getRegion_dyn(); }
		if (HX_FIELD_EQ(inName,"movieClip") ) { return movieClip; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"bitmapData") ) { return bitmapData; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"_isDifferentXML") ) { return _isDifferentXML; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"_name2SubTexData") ) { return _name2SubTexData; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic NativeTextureAtlas_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"name") ) { name=inValue.Cast< ::String >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"scale") ) { scale=inValue.Cast< Float >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"movieClip") ) { movieClip=inValue.Cast< ::native::display::MovieClip >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"bitmapData") ) { bitmapData=inValue.Cast< ::native::display::BitmapData >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"_isDifferentXML") ) { _isDifferentXML=inValue.Cast< bool >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"_name2SubTexData") ) { _name2SubTexData=inValue.Cast< ::Hash >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void NativeTextureAtlas_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("name"));
	outFields->push(HX_CSTRING("_isDifferentXML"));
	outFields->push(HX_CSTRING("_name2SubTexData"));
	outFields->push(HX_CSTRING("scale"));
	outFields->push(HX_CSTRING("bitmapData"));
	outFields->push(HX_CSTRING("movieClip"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("parseData"),
	HX_CSTRING("getRegion"),
	HX_CSTRING("dispose"),
	HX_CSTRING("name"),
	HX_CSTRING("_isDifferentXML"),
	HX_CSTRING("_name2SubTexData"),
	HX_CSTRING("scale"),
	HX_CSTRING("bitmapData"),
	HX_CSTRING("movieClip"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(NativeTextureAtlas_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(NativeTextureAtlas_obj::__mClass,"__mClass");
};

Class NativeTextureAtlas_obj::__mClass;

void NativeTextureAtlas_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("hxDragonBones.textures.NativeTextureAtlas"), hx::TCanCast< NativeTextureAtlas_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void NativeTextureAtlas_obj::__boot()
{
}

} // end namespace hxDragonBones
} // end namespace textures
