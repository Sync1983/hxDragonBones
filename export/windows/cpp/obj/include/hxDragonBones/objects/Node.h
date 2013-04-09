#ifndef INCLUDED_hxDragonBones_objects_Node
#define INCLUDED_hxDragonBones_objects_Node

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(hxDragonBones,objects,Node)
namespace hxDragonBones{
namespace objects{


class Node_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Node_obj OBJ_;
		Node_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< Node_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Node_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Node"); }

		virtual Void copyFrom( ::hxDragonBones::objects::Node node);
		Dynamic copyFrom_dyn();

		virtual Void setValues( hx::Null< Float >  x,hx::Null< Float >  y,hx::Null< Float >  skewX,hx::Null< Float >  skewY,hx::Null< Float >  scaleX,hx::Null< Float >  scaleY,hx::Null< Float >  pivotX,hx::Null< Float >  pivotY,hx::Null< int >  z);
		Dynamic setValues_dyn();

		virtual Float set_rotation( Float value);
		Dynamic set_rotation_dyn();

		virtual Float get_rotation( );
		Dynamic get_rotation_dyn();

		Float rotation; /* REM */ 
		Float pivotY; /* REM */ 
		Float pivotX; /* REM */ 
		Float skewY; /* REM */ 
		Float skewX; /* REM */ 
		Float scaleY; /* REM */ 
		Float scaleX; /* REM */ 
		Float z; /* REM */ 
		Float y; /* REM */ 
		Float x; /* REM */ 
};

} // end namespace hxDragonBones
} // end namespace objects

#endif /* INCLUDED_hxDragonBones_objects_Node */ 
