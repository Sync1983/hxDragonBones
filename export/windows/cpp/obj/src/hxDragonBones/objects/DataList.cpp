#include <hxcpp.h>

#ifndef INCLUDED_Hash
#include <Hash.h>
#endif
#ifndef INCLUDED_IntHash
#include <IntHash.h>
#endif
#ifndef INCLUDED_hxDragonBones_objects_DataList
#include <hxDragonBones/objects/DataList.h>
#endif
#ifndef INCLUDED_hxDragonBones_utils_IDisposable
#include <hxDragonBones/utils/IDisposable.h>
#endif
#ifndef INCLUDED_nme_ObjectHash
#include <nme/ObjectHash.h>
#endif
namespace hxDragonBones{
namespace objects{

Void DataList_obj::__construct()
{
HX_STACK_PUSH("DataList::new","hxDragonBones/objects/DataList.hx",10);
{
	HX_STACK_LINE(11)
	this->_data2name = ::nme::ObjectHash_obj::__new();
	HX_STACK_LINE(12)
	this->_name2data = ::Hash_obj::__new();
	HX_STACK_LINE(13)
	this->names = Array_obj< ::String >::__new();
}
;
	return null();
}

DataList_obj::~DataList_obj() { }

Dynamic DataList_obj::__CreateEmpty() { return  new DataList_obj; }
hx::ObjectPtr< DataList_obj > DataList_obj::__new()
{  hx::ObjectPtr< DataList_obj > result = new DataList_obj();
	result->__construct();
	return result;}

Dynamic DataList_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< DataList_obj > result = new DataList_obj();
	result->__construct();
	return result;}

hx::Object *DataList_obj::__ToInterface(const type_info &inType) {
	if (inType==typeid( ::hxDragonBones::utils::IDisposable_obj)) return operator ::hxDragonBones::utils::IDisposable_obj *();
	return super::__ToInterface(inType);
}

Void DataList_obj::removeDataByName( ::String name){
{
		HX_STACK_PUSH("DataList::removeDataByName","hxDragonBones/objects/DataList.hx",47);
		HX_STACK_THIS(this);
		HX_STACK_ARG(name,"name");
		HX_STACK_LINE(48)
		if (((name == null()))){
			HX_STACK_LINE(48)
			return null();
		}
		HX_STACK_LINE(51)
		this->_name2data->remove(name);
		HX_STACK_LINE(52)
		this->names->remove(name);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(DataList_obj,removeDataByName,(void))

Void DataList_obj::removeData( Dynamic data){
{
		HX_STACK_PUSH("DataList::removeData","hxDragonBones/objects/DataList.hx",39);
		HX_STACK_THIS(this);
		HX_STACK_ARG(data,"data");
		HX_STACK_LINE(40)
		if (((data == null()))){
			HX_STACK_LINE(40)
			return null();
		}
		HX_STACK_LINE(43)
		this->removeDataByName(this->_data2name->hashValues->get(::__hxcpp_obj_id(data)));
		HX_STACK_LINE(44)
		{
			HX_STACK_LINE(44)
			::nme::ObjectHash _this = this->_data2name;		HX_STACK_VAR(_this,"_this");
			HX_STACK_LINE(44)
			int id = ::__hxcpp_obj_id(data);		HX_STACK_VAR(id,"id");
			HX_STACK_LINE(44)
			_this->hashKeys->remove(id);
			HX_STACK_LINE(44)
			_this->hashValues->remove(id);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(DataList_obj,removeData,(void))

Void DataList_obj::addData( Dynamic data,::String name){
{
		HX_STACK_PUSH("DataList::addData","hxDragonBones/objects/DataList.hx",30);
		HX_STACK_THIS(this);
		HX_STACK_ARG(data,"data");
		HX_STACK_ARG(name,"name");
		HX_STACK_LINE(31)
		if (((bool((data == null())) || bool((name == null()))))){
			HX_STACK_LINE(31)
			return null();
		}
		HX_STACK_LINE(34)
		this->_name2data->set(name,data);
		HX_STACK_LINE(35)
		{
			HX_STACK_LINE(35)
			::nme::ObjectHash _this = this->_data2name;		HX_STACK_VAR(_this,"_this");
			HX_STACK_LINE(35)
			int id = ::__hxcpp_obj_id(data);		HX_STACK_VAR(id,"id");
			HX_STACK_LINE(35)
			_this->hashKeys->set(id,data);
			HX_STACK_LINE(35)
			_this->hashValues->set(id,name);
		}
		HX_STACK_LINE(36)
		this->names->push(name);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(DataList_obj,addData,(void))

Dynamic DataList_obj::getDataByName( ::String name){
	HX_STACK_PUSH("DataList::getDataByName","hxDragonBones/objects/DataList.hx",26);
	HX_STACK_THIS(this);
	HX_STACK_ARG(name,"name");
	HX_STACK_LINE(26)
	return this->_name2data->get(name);
}


HX_DEFINE_DYNAMIC_FUNC1(DataList_obj,getDataByName,return )

Void DataList_obj::dispose( ){
{
		HX_STACK_PUSH("DataList::dispose","hxDragonBones/objects/DataList.hx",20);
		HX_STACK_THIS(this);
		HX_STACK_LINE(21)
		this->_data2name = null();
		HX_STACK_LINE(22)
		this->_name2data = null();
		HX_STACK_LINE(23)
		this->names = null();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(DataList_obj,dispose,(void))


DataList_obj::DataList_obj()
{
}

void DataList_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(DataList);
	HX_MARK_MEMBER_NAME(_data2name,"_data2name");
	HX_MARK_MEMBER_NAME(_name2data,"_name2data");
	HX_MARK_MEMBER_NAME(names,"names");
	HX_MARK_END_CLASS();
}

void DataList_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_data2name,"_data2name");
	HX_VISIT_MEMBER_NAME(_name2data,"_name2data");
	HX_VISIT_MEMBER_NAME(names,"names");
}

Dynamic DataList_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"names") ) { return names; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"addData") ) { return addData_dyn(); }
		if (HX_FIELD_EQ(inName,"dispose") ) { return dispose_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"removeData") ) { return removeData_dyn(); }
		if (HX_FIELD_EQ(inName,"_data2name") ) { return _data2name; }
		if (HX_FIELD_EQ(inName,"_name2data") ) { return _name2data; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"getDataByName") ) { return getDataByName_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"removeDataByName") ) { return removeDataByName_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic DataList_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"names") ) { names=inValue.Cast< Array< ::String > >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"_data2name") ) { _data2name=inValue.Cast< ::nme::ObjectHash >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_name2data") ) { _name2data=inValue.Cast< ::Hash >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void DataList_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_data2name"));
	outFields->push(HX_CSTRING("_name2data"));
	outFields->push(HX_CSTRING("names"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("removeDataByName"),
	HX_CSTRING("removeData"),
	HX_CSTRING("addData"),
	HX_CSTRING("getDataByName"),
	HX_CSTRING("dispose"),
	HX_CSTRING("_data2name"),
	HX_CSTRING("_name2data"),
	HX_CSTRING("names"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(DataList_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(DataList_obj::__mClass,"__mClass");
};

Class DataList_obj::__mClass;

void DataList_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("hxDragonBones.objects.DataList"), hx::TCanCast< DataList_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void DataList_obj::__boot()
{
}

} // end namespace hxDragonBones
} // end namespace objects
