#include <hxcpp.h>

#ifndef INCLUDED_Xml
#include <Xml.h>
#endif
#ifndef INCLUDED_haxe_io_Bytes
#include <haxe/io/Bytes.h>
#endif
#ifndef INCLUDED_hxDragonBones_objects_DecompressedData
#include <hxDragonBones/objects/DecompressedData.h>
#endif
#ifndef INCLUDED_hxDragonBones_utils_IDisposable
#include <hxDragonBones/utils/IDisposable.h>
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
namespace hxDragonBones{
namespace objects{

Void DecompressedData_obj::__construct(::Xml skeletonXml,::Xml texAtlasXml,::native::utils::ByteArray texBytes)
{
HX_STACK_PUSH("DecompressedData::new","hxDragonBones/objects/DecompressedData.hx",11);
{
	HX_STACK_LINE(12)
	this->skeletonXml = skeletonXml;
	HX_STACK_LINE(13)
	this->texAtlasXml = texAtlasXml;
	HX_STACK_LINE(14)
	this->texBytes = texBytes;
}
;
	return null();
}

DecompressedData_obj::~DecompressedData_obj() { }

Dynamic DecompressedData_obj::__CreateEmpty() { return  new DecompressedData_obj; }
hx::ObjectPtr< DecompressedData_obj > DecompressedData_obj::__new(::Xml skeletonXml,::Xml texAtlasXml,::native::utils::ByteArray texBytes)
{  hx::ObjectPtr< DecompressedData_obj > result = new DecompressedData_obj();
	result->__construct(skeletonXml,texAtlasXml,texBytes);
	return result;}

Dynamic DecompressedData_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< DecompressedData_obj > result = new DecompressedData_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}

hx::Object *DecompressedData_obj::__ToInterface(const type_info &inType) {
	if (inType==typeid( ::hxDragonBones::utils::IDisposable_obj)) return operator ::hxDragonBones::utils::IDisposable_obj *();
	return super::__ToInterface(inType);
}

Void DecompressedData_obj::dispose( ){
{
		HX_STACK_PUSH("DecompressedData::dispose","hxDragonBones/objects/DecompressedData.hx",21);
		HX_STACK_THIS(this);
		HX_STACK_LINE(22)
		this->skeletonXml = null();
		HX_STACK_LINE(23)
		this->texAtlasXml = null();
		HX_STACK_LINE(24)
		this->texBytes = null();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(DecompressedData_obj,dispose,(void))


DecompressedData_obj::DecompressedData_obj()
{
}

void DecompressedData_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(DecompressedData);
	HX_MARK_MEMBER_NAME(texBytes,"texBytes");
	HX_MARK_MEMBER_NAME(texAtlasXml,"texAtlasXml");
	HX_MARK_MEMBER_NAME(skeletonXml,"skeletonXml");
	HX_MARK_END_CLASS();
}

void DecompressedData_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(texBytes,"texBytes");
	HX_VISIT_MEMBER_NAME(texAtlasXml,"texAtlasXml");
	HX_VISIT_MEMBER_NAME(skeletonXml,"skeletonXml");
}

Dynamic DecompressedData_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"dispose") ) { return dispose_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"texBytes") ) { return texBytes; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"texAtlasXml") ) { return texAtlasXml; }
		if (HX_FIELD_EQ(inName,"skeletonXml") ) { return skeletonXml; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic DecompressedData_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"texBytes") ) { texBytes=inValue.Cast< ::native::utils::ByteArray >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"texAtlasXml") ) { texAtlasXml=inValue.Cast< ::Xml >(); return inValue; }
		if (HX_FIELD_EQ(inName,"skeletonXml") ) { skeletonXml=inValue.Cast< ::Xml >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void DecompressedData_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("texBytes"));
	outFields->push(HX_CSTRING("texAtlasXml"));
	outFields->push(HX_CSTRING("skeletonXml"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("dispose"),
	HX_CSTRING("texBytes"),
	HX_CSTRING("texAtlasXml"),
	HX_CSTRING("skeletonXml"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(DecompressedData_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(DecompressedData_obj::__mClass,"__mClass");
};

Class DecompressedData_obj::__mClass;

void DecompressedData_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("hxDragonBones.objects.DecompressedData"), hx::TCanCast< DecompressedData_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void DecompressedData_obj::__boot()
{
}

} // end namespace hxDragonBones
} // end namespace objects
