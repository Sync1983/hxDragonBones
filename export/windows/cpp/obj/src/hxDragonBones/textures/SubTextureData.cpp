#include <hxcpp.h>

#ifndef INCLUDED_hxDragonBones_textures_SubTextureData
#include <hxDragonBones/textures/SubTextureData.h>
#endif
#ifndef INCLUDED_native_geom_Rectangle
#include <native/geom/Rectangle.h>
#endif
namespace hxDragonBones{
namespace textures{

Void SubTextureData_obj::__construct(hx::Null< Float >  __o_x,hx::Null< Float >  __o_y,hx::Null< Float >  __o_width,hx::Null< Float >  __o_height)
{
HX_STACK_PUSH("SubTextureData::new","hxDragonBones/textures/SubTextureData.hx",11);
Float x = __o_x.Default(0);
Float y = __o_y.Default(0);
Float width = __o_width.Default(0);
Float height = __o_height.Default(0);
{
	HX_STACK_LINE(12)
	super::__construct(x,y,width,height);
	HX_STACK_LINE(13)
	this->pivotX = (int)0;
	HX_STACK_LINE(14)
	this->pivotY = (int)0;
}
;
	return null();
}

SubTextureData_obj::~SubTextureData_obj() { }

Dynamic SubTextureData_obj::__CreateEmpty() { return  new SubTextureData_obj; }
hx::ObjectPtr< SubTextureData_obj > SubTextureData_obj::__new(hx::Null< Float >  __o_x,hx::Null< Float >  __o_y,hx::Null< Float >  __o_width,hx::Null< Float >  __o_height)
{  hx::ObjectPtr< SubTextureData_obj > result = new SubTextureData_obj();
	result->__construct(__o_x,__o_y,__o_width,__o_height);
	return result;}

Dynamic SubTextureData_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< SubTextureData_obj > result = new SubTextureData_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3]);
	return result;}


SubTextureData_obj::SubTextureData_obj()
{
}

void SubTextureData_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(SubTextureData);
	HX_MARK_MEMBER_NAME(pivotY,"pivotY");
	HX_MARK_MEMBER_NAME(pivotX,"pivotX");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void SubTextureData_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(pivotY,"pivotY");
	HX_VISIT_MEMBER_NAME(pivotX,"pivotX");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic SubTextureData_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"pivotY") ) { return pivotY; }
		if (HX_FIELD_EQ(inName,"pivotX") ) { return pivotX; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic SubTextureData_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"pivotY") ) { pivotY=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"pivotX") ) { pivotX=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void SubTextureData_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("pivotY"));
	outFields->push(HX_CSTRING("pivotX"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("pivotY"),
	HX_CSTRING("pivotX"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(SubTextureData_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(SubTextureData_obj::__mClass,"__mClass");
};

Class SubTextureData_obj::__mClass;

void SubTextureData_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("hxDragonBones.textures.SubTextureData"), hx::TCanCast< SubTextureData_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void SubTextureData_obj::__boot()
{
}

} // end namespace hxDragonBones
} // end namespace textures
