#ifndef INCLUDED_hxDragonBones_utils_BytesType
#define INCLUDED_hxDragonBones_utils_BytesType

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(haxe,io,Bytes)
HX_DECLARE_CLASS2(hxDragonBones,utils,BytesType)
HX_DECLARE_CLASS2(native,utils,ByteArray)
HX_DECLARE_CLASS2(native,utils,IDataInput)
HX_DECLARE_CLASS2(native,utils,IMemoryRange)
namespace hxDragonBones{
namespace utils{


class BytesType_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef BytesType_obj OBJ_;
		BytesType_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< BytesType_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~BytesType_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("BytesType"); }

		static ::String SWF; /* REM */ 
		static ::String PNG; /* REM */ 
		static ::String JPG; /* REM */ 
		static ::String ATF; /* REM */ 
		static ::String ZIP; /* REM */ 
		static ::String getType( ::native::utils::ByteArray bytes);
		static Dynamic getType_dyn();

};

} // end namespace hxDragonBones
} // end namespace utils

#endif /* INCLUDED_hxDragonBones_utils_BytesType */ 
