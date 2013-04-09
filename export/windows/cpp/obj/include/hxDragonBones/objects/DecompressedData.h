#ifndef INCLUDED_hxDragonBones_objects_DecompressedData
#define INCLUDED_hxDragonBones_objects_DecompressedData

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <hxDragonBones/utils/IDisposable.h>
HX_DECLARE_CLASS0(Xml)
HX_DECLARE_CLASS2(haxe,io,Bytes)
HX_DECLARE_CLASS2(hxDragonBones,objects,DecompressedData)
HX_DECLARE_CLASS2(hxDragonBones,utils,IDisposable)
HX_DECLARE_CLASS2(native,utils,ByteArray)
HX_DECLARE_CLASS2(native,utils,IDataInput)
HX_DECLARE_CLASS2(native,utils,IMemoryRange)
namespace hxDragonBones{
namespace objects{


class DecompressedData_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef DecompressedData_obj OBJ_;
		DecompressedData_obj();
		Void __construct(::Xml skeletonXml,::Xml texAtlasXml,::native::utils::ByteArray texBytes);

	public:
		static hx::ObjectPtr< DecompressedData_obj > __new(::Xml skeletonXml,::Xml texAtlasXml,::native::utils::ByteArray texBytes);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~DecompressedData_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		inline operator ::hxDragonBones::utils::IDisposable_obj *()
			{ return new ::hxDragonBones::utils::IDisposable_delegate_< DecompressedData_obj >(this); }
		hx::Object *__ToInterface(const type_info &inType);
		::String __ToString() const { return HX_CSTRING("DecompressedData"); }

		virtual Void dispose( );
		Dynamic dispose_dyn();

		::native::utils::ByteArray texBytes; /* REM */ 
		::Xml texAtlasXml; /* REM */ 
		::Xml skeletonXml; /* REM */ 
};

} // end namespace hxDragonBones
} // end namespace objects

#endif /* INCLUDED_hxDragonBones_objects_DecompressedData */ 
