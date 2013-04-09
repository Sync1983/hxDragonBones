#ifndef INCLUDED_hxDragonBones_utils_TransformUtils
#define INCLUDED_hxDragonBones_utils_TransformUtils

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(hxDragonBones,objects,Node)
HX_DECLARE_CLASS2(hxDragonBones,utils,TransformUtils)
HX_DECLARE_CLASS2(native,geom,ColorTransform)
HX_DECLARE_CLASS2(native,geom,Matrix)
HX_DECLARE_CLASS2(native,geom,Point)
namespace hxDragonBones{
namespace utils{


class TransformUtils_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef TransformUtils_obj OBJ_;
		TransformUtils_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< TransformUtils_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~TransformUtils_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("TransformUtils"); }

		static Float DOUBLE_PI; /* REM */ 
		static ::native::geom::Matrix _helpMatrix; /* REM */ 
		static ::native::geom::Point _helpPoint; /* REM */ 
		static Void transformPointWithParent( ::hxDragonBones::objects::Node bone,::hxDragonBones::objects::Node parent);
		static Dynamic transformPointWithParent_dyn();

		static Void nodeToMatrix( ::hxDragonBones::objects::Node node,::native::geom::Matrix resultMatrix);
		static Dynamic nodeToMatrix_dyn();

		static Void setOffSetColorTransform( ::native::geom::ColorTransform from,::native::geom::ColorTransform to,::native::geom::ColorTransform offset);
		static Dynamic setOffSetColorTransform_dyn();

		static Void setTweenColorTransform( ::native::geom::ColorTransform current,::native::geom::ColorTransform offSet,::native::geom::ColorTransform tween,Float progress);
		static Dynamic setTweenColorTransform_dyn();

		static Void setOffSetNode( ::hxDragonBones::objects::Node from,::hxDragonBones::objects::Node to,::hxDragonBones::objects::Node offSet,hx::Null< int >  tweenRotate);
		static Dynamic setOffSetNode_dyn();

		static Void setTweenNode( ::hxDragonBones::objects::Node current,::hxDragonBones::objects::Node offSet,::hxDragonBones::objects::Node tween,Float progress);
		static Dynamic setTweenNode_dyn();

};

} // end namespace hxDragonBones
} // end namespace utils

#endif /* INCLUDED_hxDragonBones_utils_TransformUtils */ 
