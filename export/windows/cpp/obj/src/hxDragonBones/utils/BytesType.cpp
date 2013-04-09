#include <hxcpp.h>

#ifndef INCLUDED_haxe_io_Bytes
#include <haxe/io/Bytes.h>
#endif
#ifndef INCLUDED_hxDragonBones_utils_BytesType
#include <hxDragonBones/utils/BytesType.h>
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
namespace utils{

Void BytesType_obj::__construct()
{
	return null();
}

BytesType_obj::~BytesType_obj() { }

Dynamic BytesType_obj::__CreateEmpty() { return  new BytesType_obj; }
hx::ObjectPtr< BytesType_obj > BytesType_obj::__new()
{  hx::ObjectPtr< BytesType_obj > result = new BytesType_obj();
	result->__construct();
	return result;}

Dynamic BytesType_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< BytesType_obj > result = new BytesType_obj();
	result->__construct();
	return result;}

::String BytesType_obj::SWF;

::String BytesType_obj::PNG;

::String BytesType_obj::JPG;

::String BytesType_obj::ATF;

::String BytesType_obj::ZIP;

::String BytesType_obj::getType( ::native::utils::ByteArray bytes){
	HX_STACK_PUSH("BytesType::getType","hxDragonBones/utils/BytesType.hx",15);
	HX_STACK_ARG(bytes,"bytes");
	HX_STACK_LINE(16)
	::String type = null();		HX_STACK_VAR(type,"type");
	HX_STACK_LINE(17)
	int b1 = bytes->__get((int)0);		HX_STACK_VAR(b1,"b1");
	HX_STACK_LINE(18)
	int b2 = bytes->__get((int)1);		HX_STACK_VAR(b2,"b2");
	HX_STACK_LINE(19)
	int b3 = bytes->__get((int)2);		HX_STACK_VAR(b3,"b3");
	HX_STACK_LINE(20)
	int b4 = bytes->__get((int)3);		HX_STACK_VAR(b4,"b4");
	HX_STACK_LINE(22)
	if (((bool((bool(((bool((bool((b1 == (int)70)) || bool((b1 == (int)67)))) || bool((b1 == (int)90))))) && bool((b2 == (int)87)))) && bool((b3 == (int)83))))){
		HX_STACK_LINE(22)
		type = HX_CSTRING("swf");
	}
	else{
		HX_STACK_LINE(25)
		if (((bool((bool((bool((b1 == (int)137)) && bool((b2 == (int)80)))) && bool((b3 == (int)78)))) && bool((b4 == (int)71))))){
			HX_STACK_LINE(25)
			type = HX_CSTRING("png");
		}
		else{
			HX_STACK_LINE(28)
			if (((b1 == (int)255))){
				HX_STACK_LINE(28)
				type = HX_CSTRING("jpg");
			}
			else{
				HX_STACK_LINE(30)
				if (((bool((bool((b1 == (int)65)) && bool((b2 == (int)84)))) && bool((b3 == (int)70))))){
					HX_STACK_LINE(30)
					type = HX_CSTRING("atf");
				}
				else{
					HX_STACK_LINE(32)
					if (((bool((b1 == (int)80)) && bool((b2 == (int)75))))){
						HX_STACK_LINE(32)
						type = HX_CSTRING("zip");
					}
				}
			}
		}
	}
	HX_STACK_LINE(35)
	return type;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(BytesType_obj,getType,return )


BytesType_obj::BytesType_obj()
{
}

void BytesType_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(BytesType);
	HX_MARK_END_CLASS();
}

void BytesType_obj::__Visit(HX_VISIT_PARAMS)
{
}

Dynamic BytesType_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"SWF") ) { return SWF; }
		if (HX_FIELD_EQ(inName,"PNG") ) { return PNG; }
		if (HX_FIELD_EQ(inName,"JPG") ) { return JPG; }
		if (HX_FIELD_EQ(inName,"ATF") ) { return ATF; }
		if (HX_FIELD_EQ(inName,"ZIP") ) { return ZIP; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"getType") ) { return getType_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic BytesType_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"SWF") ) { SWF=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"PNG") ) { PNG=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"JPG") ) { JPG=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"ATF") ) { ATF=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"ZIP") ) { ZIP=inValue.Cast< ::String >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void BytesType_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("SWF"),
	HX_CSTRING("PNG"),
	HX_CSTRING("JPG"),
	HX_CSTRING("ATF"),
	HX_CSTRING("ZIP"),
	HX_CSTRING("getType"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(BytesType_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(BytesType_obj::SWF,"SWF");
	HX_MARK_MEMBER_NAME(BytesType_obj::PNG,"PNG");
	HX_MARK_MEMBER_NAME(BytesType_obj::JPG,"JPG");
	HX_MARK_MEMBER_NAME(BytesType_obj::ATF,"ATF");
	HX_MARK_MEMBER_NAME(BytesType_obj::ZIP,"ZIP");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(BytesType_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(BytesType_obj::SWF,"SWF");
	HX_VISIT_MEMBER_NAME(BytesType_obj::PNG,"PNG");
	HX_VISIT_MEMBER_NAME(BytesType_obj::JPG,"JPG");
	HX_VISIT_MEMBER_NAME(BytesType_obj::ATF,"ATF");
	HX_VISIT_MEMBER_NAME(BytesType_obj::ZIP,"ZIP");
};

Class BytesType_obj::__mClass;

void BytesType_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("hxDragonBones.utils.BytesType"), hx::TCanCast< BytesType_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void BytesType_obj::__boot()
{
	SWF= HX_CSTRING("swf");
	PNG= HX_CSTRING("png");
	JPG= HX_CSTRING("jpg");
	ATF= HX_CSTRING("atf");
	ZIP= HX_CSTRING("zip");
}

} // end namespace hxDragonBones
} // end namespace utils
