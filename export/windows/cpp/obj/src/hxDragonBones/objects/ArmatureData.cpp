#include <hxcpp.h>

#ifndef INCLUDED_Reflect
#include <Reflect.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_hxDragonBones_objects_ArmatureData
#include <hxDragonBones/objects/ArmatureData.h>
#endif
#ifndef INCLUDED_hxDragonBones_objects_BoneData
#include <hxDragonBones/objects/BoneData.h>
#endif
#ifndef INCLUDED_hxDragonBones_objects_DataList
#include <hxDragonBones/objects/DataList.h>
#endif
#ifndef INCLUDED_hxDragonBones_objects_Node
#include <hxDragonBones/objects/Node.h>
#endif
#ifndef INCLUDED_hxDragonBones_utils_IDisposable
#include <hxDragonBones/utils/IDisposable.h>
#endif
namespace hxDragonBones{
namespace objects{

Void ArmatureData_obj::__construct()
{
HX_STACK_PUSH("ArmatureData::new","hxDragonBones/objects/ArmatureData.hx",10);
{
	HX_STACK_LINE(10)
	this->boneDataList = ::hxDragonBones::objects::DataList_obj::__new();
}
;
	return null();
}

ArmatureData_obj::~ArmatureData_obj() { }

Dynamic ArmatureData_obj::__CreateEmpty() { return  new ArmatureData_obj; }
hx::ObjectPtr< ArmatureData_obj > ArmatureData_obj::__new()
{  hx::ObjectPtr< ArmatureData_obj > result = new ArmatureData_obj();
	result->__construct();
	return result;}

Dynamic ArmatureData_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< ArmatureData_obj > result = new ArmatureData_obj();
	result->__construct();
	return result;}

hx::Object *ArmatureData_obj::__ToInterface(const type_info &inType) {
	if (inType==typeid( ::hxDragonBones::utils::IDisposable_obj)) return operator ::hxDragonBones::utils::IDisposable_obj *();
	return super::__ToInterface(inType);
}

int ArmatureData_obj::compareLevel( Dynamic a,Dynamic b){
	HX_STACK_PUSH("ArmatureData::compareLevel","hxDragonBones/objects/ArmatureData.hx",57);
	HX_STACK_THIS(this);
	HX_STACK_ARG(a,"a");
	HX_STACK_ARG(b,"b");
	HX_STACK_LINE(57)
	return ::Reflect_obj::compare(a->__Field(HX_CSTRING("level"),true),b->__Field(HX_CSTRING("level"),true));
}


HX_DEFINE_DYNAMIC_FUNC2(ArmatureData_obj,compareLevel,return )

Void ArmatureData_obj::updateBoneList( ){
{
		HX_STACK_PUSH("ArmatureData::updateBoneList","hxDragonBones/objects/ArmatureData.hx",32);
		HX_STACK_THIS(this);
		HX_STACK_LINE(33)
		Dynamic sortList = Dynamic( Array_obj<Dynamic>::__new());		HX_STACK_VAR(sortList,"sortList");
		HX_STACK_LINE(34)
		{
			HX_STACK_LINE(34)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			Array< ::String > _g1 = this->boneDataList->names;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(34)
			while(((_g < _g1->length))){
				HX_STACK_LINE(34)
				::String name = _g1->__get(_g);		HX_STACK_VAR(name,"name");
				HX_STACK_LINE(34)
				++(_g);
				HX_STACK_LINE(35)
				::hxDragonBones::objects::BoneData boneData = this->boneDataList->getDataByName(name);		HX_STACK_VAR(boneData,"boneData");
				HX_STACK_LINE(36)
				if (((boneData != null()))){
					HX_STACK_LINE(37)
					int levelValue = ::Std_obj::_int(boneData->node->z);		HX_STACK_VAR(levelValue,"levelValue");
					HX_STACK_LINE(38)
					int level = (int)0;		HX_STACK_VAR(level,"level");
					HX_STACK_LINE(39)
					while(((boneData != null()))){
						HX_STACK_LINE(40)
						(level)++;
						HX_STACK_LINE(41)
						hx::AddEq(levelValue,((int)1000 * level));
						HX_STACK_LINE(42)
						boneData = this->getBoneData(boneData->parent);
					}
					struct _Function_4_1{
						inline static Dynamic Block( int &levelValue,::String &name){
							HX_STACK_PUSH("*::closure","hxDragonBones/objects/ArmatureData.hx",44);
							{
								hx::Anon __result = hx::Anon_obj::Create();
								__result->Add(HX_CSTRING("level") , levelValue,false);
								__result->Add(HX_CSTRING("name") , name,false);
								return __result;
							}
							return null();
						}
					};
					HX_STACK_LINE(44)
					sortList->__Field(HX_CSTRING("push"),true)(_Function_4_1::Block(levelValue,name));
				}
			}
		}
		HX_STACK_LINE(48)
		if (((sortList->__Field(HX_CSTRING("length"),true) > (int)0))){
			HX_STACK_LINE(49)
			sortList->__Field(HX_CSTRING("sort"),true)(this->compareLevel_dyn());
			HX_STACK_LINE(50)
			this->boneDataList->names = Array_obj< ::String >::__new();
			HX_STACK_LINE(51)
			{
				HX_STACK_LINE(51)
				int _g = (int)0;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(51)
				while(((_g < sortList->__Field(HX_CSTRING("length"),true)))){
					HX_STACK_LINE(51)
					Dynamic item = sortList->__GetItem(_g);		HX_STACK_VAR(item,"item");
					HX_STACK_LINE(51)
					++(_g);
					HX_STACK_LINE(52)
					this->boneDataList->names->push(item->__Field(HX_CSTRING("name"),true));
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(ArmatureData_obj,updateBoneList,(void))

::hxDragonBones::objects::BoneData ArmatureData_obj::getBoneData( ::String name){
	HX_STACK_PUSH("ArmatureData::getBoneData","hxDragonBones/objects/ArmatureData.hx",28);
	HX_STACK_THIS(this);
	HX_STACK_ARG(name,"name");
	HX_STACK_LINE(28)
	return this->boneDataList->getDataByName(name);
}


HX_DEFINE_DYNAMIC_FUNC1(ArmatureData_obj,getBoneData,return )

Void ArmatureData_obj::dispose( ){
{
		HX_STACK_PUSH("ArmatureData::dispose","hxDragonBones/objects/ArmatureData.hx",21);
		HX_STACK_THIS(this);
		HX_STACK_LINE(22)
		{
			HX_STACK_LINE(22)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			Array< ::String > _g1 = this->boneDataList->names;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(22)
			while(((_g < _g1->length))){
				HX_STACK_LINE(22)
				::String name = _g1->__get(_g);		HX_STACK_VAR(name,"name");
				HX_STACK_LINE(22)
				++(_g);
				HX_STACK_LINE(23)
				{
					HX_STACK_LINE(23)
					::hxDragonBones::utils::IDisposable d = this->boneDataList->getDataByName(name);		HX_STACK_VAR(d,"d");
					HX_STACK_LINE(23)
					if (((d != null()))){
						HX_STACK_LINE(23)
						d->dispose();
					}
				}
			}
		}
		HX_STACK_LINE(25)
		{
			HX_STACK_LINE(25)
			::hxDragonBones::utils::IDisposable d = this->boneDataList;		HX_STACK_VAR(d,"d");
			HX_STACK_LINE(25)
			if (((d != null()))){
				HX_STACK_LINE(25)
				d->dispose();
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(ArmatureData_obj,dispose,(void))

Array< ::String > ArmatureData_obj::get_boneNames( ){
	HX_STACK_PUSH("ArmatureData::get_boneNames","hxDragonBones/objects/ArmatureData.hx",15);
	HX_STACK_THIS(this);
	HX_STACK_LINE(15)
	return this->boneDataList->names->slice((int)0,null());
}


HX_DEFINE_DYNAMIC_FUNC0(ArmatureData_obj,get_boneNames,return )


ArmatureData_obj::ArmatureData_obj()
{
}

void ArmatureData_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(ArmatureData);
	HX_MARK_MEMBER_NAME(boneDataList,"boneDataList");
	HX_MARK_MEMBER_NAME(boneNames,"boneNames");
	HX_MARK_END_CLASS();
}

void ArmatureData_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(boneDataList,"boneDataList");
	HX_VISIT_MEMBER_NAME(boneNames,"boneNames");
}

Dynamic ArmatureData_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"dispose") ) { return dispose_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"boneNames") ) { return inCallProp ? get_boneNames() : boneNames; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"getBoneData") ) { return getBoneData_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"compareLevel") ) { return compareLevel_dyn(); }
		if (HX_FIELD_EQ(inName,"boneDataList") ) { return boneDataList; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"get_boneNames") ) { return get_boneNames_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"updateBoneList") ) { return updateBoneList_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic ArmatureData_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 9:
		if (HX_FIELD_EQ(inName,"boneNames") ) { boneNames=inValue.Cast< Array< ::String > >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"boneDataList") ) { boneDataList=inValue.Cast< ::hxDragonBones::objects::DataList >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void ArmatureData_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("boneDataList"));
	outFields->push(HX_CSTRING("boneNames"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("compareLevel"),
	HX_CSTRING("updateBoneList"),
	HX_CSTRING("getBoneData"),
	HX_CSTRING("dispose"),
	HX_CSTRING("boneDataList"),
	HX_CSTRING("get_boneNames"),
	HX_CSTRING("boneNames"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(ArmatureData_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(ArmatureData_obj::__mClass,"__mClass");
};

Class ArmatureData_obj::__mClass;

void ArmatureData_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("hxDragonBones.objects.ArmatureData"), hx::TCanCast< ArmatureData_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void ArmatureData_obj::__boot()
{
}

} // end namespace hxDragonBones
} // end namespace objects
