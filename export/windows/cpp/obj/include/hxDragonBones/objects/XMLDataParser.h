#ifndef INCLUDED_hxDragonBones_objects_XMLDataParser
#define INCLUDED_hxDragonBones_objects_XMLDataParser

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(Xml)
HX_DECLARE_CLASS2(haxe,io,Bytes)
HX_DECLARE_CLASS2(hxDragonBones,objects,AnimationData)
HX_DECLARE_CLASS2(hxDragonBones,objects,ArmatureData)
HX_DECLARE_CLASS2(hxDragonBones,objects,BoneData)
HX_DECLARE_CLASS2(hxDragonBones,objects,DecompressedData)
HX_DECLARE_CLASS2(hxDragonBones,objects,DisplayData)
HX_DECLARE_CLASS2(hxDragonBones,objects,FrameData)
HX_DECLARE_CLASS2(hxDragonBones,objects,MovementBoneData)
HX_DECLARE_CLASS2(hxDragonBones,objects,MovementData)
HX_DECLARE_CLASS2(hxDragonBones,objects,MovementFrameData)
HX_DECLARE_CLASS2(hxDragonBones,objects,Node)
HX_DECLARE_CLASS2(hxDragonBones,objects,SkeletonData)
HX_DECLARE_CLASS2(hxDragonBones,objects,XMLDataParser)
HX_DECLARE_CLASS2(hxDragonBones,utils,IDisposable)
HX_DECLARE_CLASS2(native,geom,ColorTransform)
HX_DECLARE_CLASS2(native,utils,ByteArray)
HX_DECLARE_CLASS2(native,utils,IDataInput)
HX_DECLARE_CLASS2(native,utils,IMemoryRange)
namespace hxDragonBones{
namespace objects{


class XMLDataParser_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef XMLDataParser_obj OBJ_;
		XMLDataParser_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< XMLDataParser_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~XMLDataParser_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("XMLDataParser"); }

		static Float ANGLE_TO_RADIAN; /* REM */ 
		static Float HALF_PI; /* REM */ 
		static ::hxDragonBones::objects::SkeletonData _curSkeletonData; /* REM */ 
		static ::hxDragonBones::objects::Node _helpNode; /* REM */ 
		static ::hxDragonBones::objects::FrameData _helpFrameData; /* REM */ 
		static Void checkSkeletonXMLVersion( ::Xml skeletonXML);
		static Dynamic checkSkeletonXMLVersion_dyn();

		static ::native::utils::ByteArray compressData( ::Xml skeletonXML,::Xml textureAtlasXML,::native::utils::ByteArray byteArray);
		static Dynamic compressData_dyn();

		static ::hxDragonBones::objects::DecompressedData decompressData( ::native::utils::ByteArray compressedBytes);
		static Dynamic decompressData_dyn();

		static ::hxDragonBones::objects::SkeletonData parseSkeletonData( ::Xml skeletonXml);
		static Dynamic parseSkeletonData_dyn();

		static Void parseArmatures( ::Xml armaturesXml);
		static Dynamic parseArmatures_dyn();

		static Void parseArmatureData( ::Xml armatureXml,::hxDragonBones::objects::ArmatureData armatureData);
		static Dynamic parseArmatureData_dyn();

		static Void parseBoneData( ::Xml boneXml,::Xml parentXml,::hxDragonBones::objects::BoneData boneData);
		static Dynamic parseBoneData_dyn();

		static Void parseDisplayData( ::Xml displayXml,::hxDragonBones::objects::DisplayData displayData);
		static Dynamic parseDisplayData_dyn();

		static Void parseAnimations( ::Xml animationsXml);
		static Dynamic parseAnimations_dyn();

		static Void parseAnimationData( ::Xml animationXml,::hxDragonBones::objects::AnimationData animationData,::hxDragonBones::objects::ArmatureData armatureData);
		static Dynamic parseAnimationData_dyn();

		static Void parseMovementData( ::Xml movementXml,::hxDragonBones::objects::ArmatureData armatureData,::hxDragonBones::objects::MovementData movementData);
		static Dynamic parseMovementData_dyn();

		static Void parseMovementBoneData( ::Xml movementBoneXML,::Xml parentMovementBoneXML,::hxDragonBones::objects::BoneData boneData,::hxDragonBones::objects::MovementBoneData movementBoneData);
		static Dynamic parseMovementBoneData_dyn();

		static Void parseMovementFrameData( ::Xml movementFrameXml,::hxDragonBones::objects::MovementFrameData movementFrameData);
		static Dynamic parseMovementFrameData_dyn();

		static Void parseFrameData( ::Xml frameXml,::hxDragonBones::objects::FrameData frameData);
		static Dynamic parseFrameData_dyn();

		static Void parseNode( ::Xml xml,::hxDragonBones::objects::Node node);
		static Dynamic parseNode_dyn();

		static Void parseColorTransform( ::Xml xml,::native::geom::ColorTransform colorTransform);
		static Dynamic parseColorTransform_dyn();

};

} // end namespace hxDragonBones
} // end namespace objects

#endif /* INCLUDED_hxDragonBones_objects_XMLDataParser */ 
