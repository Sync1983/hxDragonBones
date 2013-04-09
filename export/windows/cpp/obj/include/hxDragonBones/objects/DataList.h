#ifndef INCLUDED_hxDragonBones_objects_DataList
#define INCLUDED_hxDragonBones_objects_DataList

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <hxDragonBones/utils/IDisposable.h>
HX_DECLARE_CLASS0(Hash)
HX_DECLARE_CLASS2(hxDragonBones,objects,DataList)
HX_DECLARE_CLASS2(hxDragonBones,utils,IDisposable)
HX_DECLARE_CLASS1(nme,ObjectHash)
namespace hxDragonBones{
namespace objects{


class DataList_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef DataList_obj OBJ_;
		DataList_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< DataList_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~DataList_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		inline operator ::hxDragonBones::utils::IDisposable_obj *()
			{ return new ::hxDragonBones::utils::IDisposable_delegate_< DataList_obj >(this); }
		hx::Object *__ToInterface(const type_info &inType);
		::String __ToString() const { return HX_CSTRING("DataList"); }

		virtual Void removeDataByName( ::String name);
		Dynamic removeDataByName_dyn();

		virtual Void removeData( Dynamic data);
		Dynamic removeData_dyn();

		virtual Void addData( Dynamic data,::String name);
		Dynamic addData_dyn();

		virtual Dynamic getDataByName( ::String name);
		Dynamic getDataByName_dyn();

		virtual Void dispose( );
		Dynamic dispose_dyn();

		::nme::ObjectHash _data2name; /* REM */ 
		::Hash _name2data; /* REM */ 
		Array< ::String > names; /* REM */ 
};

} // end namespace hxDragonBones
} // end namespace objects

#endif /* INCLUDED_hxDragonBones_objects_DataList */ 
