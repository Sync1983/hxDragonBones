#include <hxcpp.h>

#ifndef INCLUDED_Lambda
#include <Lambda.h>
#endif
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_Xml
#include <Xml.h>
#endif
#ifndef INCLUDED_haxe_io_Bytes
#include <haxe/io/Bytes.h>
#endif
#ifndef INCLUDED_hxDragonBones_objects_AnimationData
#include <hxDragonBones/objects/AnimationData.h>
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
#ifndef INCLUDED_hxDragonBones_objects_DecompressedData
#include <hxDragonBones/objects/DecompressedData.h>
#endif
#ifndef INCLUDED_hxDragonBones_objects_DisplayData
#include <hxDragonBones/objects/DisplayData.h>
#endif
#ifndef INCLUDED_hxDragonBones_objects_FrameData
#include <hxDragonBones/objects/FrameData.h>
#endif
#ifndef INCLUDED_hxDragonBones_objects_MovementBoneData
#include <hxDragonBones/objects/MovementBoneData.h>
#endif
#ifndef INCLUDED_hxDragonBones_objects_MovementData
#include <hxDragonBones/objects/MovementData.h>
#endif
#ifndef INCLUDED_hxDragonBones_objects_MovementFrameData
#include <hxDragonBones/objects/MovementFrameData.h>
#endif
#ifndef INCLUDED_hxDragonBones_objects_Node
#include <hxDragonBones/objects/Node.h>
#endif
#ifndef INCLUDED_hxDragonBones_objects_SkeletonData
#include <hxDragonBones/objects/SkeletonData.h>
#endif
#ifndef INCLUDED_hxDragonBones_objects_XMLDataParser
#include <hxDragonBones/objects/XMLDataParser.h>
#endif
#ifndef INCLUDED_hxDragonBones_utils_IDisposable
#include <hxDragonBones/utils/IDisposable.h>
#endif
#ifndef INCLUDED_hxDragonBones_utils_TransformUtils
#include <hxDragonBones/utils/TransformUtils.h>
#endif
#ifndef INCLUDED_native_geom_ColorTransform
#include <native/geom/ColorTransform.h>
#endif
#ifndef INCLUDED_native_geom_Matrix
#include <native/geom/Matrix.h>
#endif
#ifndef INCLUDED_native_geom_Point
#include <native/geom/Point.h>
#endif
#ifndef INCLUDED_native_utils_ByteArray
#include <native/utils/ByteArray.h>
#endif
#ifndef INCLUDED_native_utils_CompressionAlgorithm
#include <native/utils/CompressionAlgorithm.h>
#endif
#ifndef INCLUDED_native_utils_IDataInput
#include <native/utils/IDataInput.h>
#endif
#ifndef INCLUDED_native_utils_IMemoryRange
#include <native/utils/IMemoryRange.h>
#endif
namespace hxDragonBones{
namespace objects{

Void XMLDataParser_obj::__construct()
{
	return null();
}

XMLDataParser_obj::~XMLDataParser_obj() { }

Dynamic XMLDataParser_obj::__CreateEmpty() { return  new XMLDataParser_obj; }
hx::ObjectPtr< XMLDataParser_obj > XMLDataParser_obj::__new()
{  hx::ObjectPtr< XMLDataParser_obj > result = new XMLDataParser_obj();
	result->__construct();
	return result;}

Dynamic XMLDataParser_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< XMLDataParser_obj > result = new XMLDataParser_obj();
	result->__construct();
	return result;}

Float XMLDataParser_obj::ANGLE_TO_RADIAN;

Float XMLDataParser_obj::HALF_PI;

::hxDragonBones::objects::SkeletonData XMLDataParser_obj::_curSkeletonData;

::hxDragonBones::objects::Node XMLDataParser_obj::_helpNode;

::hxDragonBones::objects::FrameData XMLDataParser_obj::_helpFrameData;

Void XMLDataParser_obj::checkSkeletonXMLVersion( ::Xml skeletonXML){
{
		HX_STACK_PUSH("XMLDataParser::checkSkeletonXMLVersion","hxDragonBones/objects/XMLDataParser.hx",21);
		HX_STACK_ARG(skeletonXML,"skeletonXML");
		HX_STACK_LINE(22)
		::String version = skeletonXML->firstElement()->get(HX_CSTRING("version"));		HX_STACK_VAR(version,"version");
		HX_STACK_LINE(23)
		if (((bool((version != HX_CSTRING("1.4"))) && bool((version != HX_CSTRING("2.0")))))){
			HX_STACK_LINE(23)
			hx::Throw (HX_CSTRING("Nonsupport data version!"));
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(XMLDataParser_obj,checkSkeletonXMLVersion,(void))

::native::utils::ByteArray XMLDataParser_obj::compressData( ::Xml skeletonXML,::Xml textureAtlasXML,::native::utils::ByteArray byteArray){
	HX_STACK_PUSH("XMLDataParser::compressData","hxDragonBones/objects/XMLDataParser.hx",28);
	HX_STACK_ARG(skeletonXML,"skeletonXML");
	HX_STACK_ARG(textureAtlasXML,"textureAtlasXML");
	HX_STACK_ARG(byteArray,"byteArray");
	HX_STACK_LINE(29)
	::native::utils::ByteArray byteArrayCopy = ::native::utils::ByteArray_obj::__new(null());		HX_STACK_VAR(byteArrayCopy,"byteArrayCopy");
	HX_STACK_LINE(30)
	byteArrayCopy->writeBytes(byteArray,null(),null());
	HX_STACK_LINE(32)
	::native::utils::ByteArray xmlBytes = ::native::utils::ByteArray_obj::__new(null());		HX_STACK_VAR(xmlBytes,"xmlBytes");
	HX_STACK_LINE(33)
	xmlBytes->writeUTFBytes(textureAtlasXML->toString());
	HX_STACK_LINE(34)
	xmlBytes->compress(null());
	HX_STACK_LINE(36)
	byteArrayCopy->position = byteArrayCopy->length;
	HX_STACK_LINE(37)
	byteArrayCopy->writeBytes(xmlBytes,null(),null());
	HX_STACK_LINE(38)
	byteArrayCopy->writeInt(xmlBytes->length);
	HX_STACK_LINE(40)
	xmlBytes->clear();
	HX_STACK_LINE(42)
	xmlBytes->writeUTFBytes(skeletonXML->toString());
	HX_STACK_LINE(43)
	xmlBytes->compress(null());
	HX_STACK_LINE(45)
	byteArrayCopy->position = byteArrayCopy->length;
	HX_STACK_LINE(46)
	byteArrayCopy->writeBytes(xmlBytes,null(),null());
	HX_STACK_LINE(47)
	byteArrayCopy->writeInt(xmlBytes->length);
	HX_STACK_LINE(49)
	return byteArrayCopy;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(XMLDataParser_obj,compressData,return )

::hxDragonBones::objects::DecompressedData XMLDataParser_obj::decompressData( ::native::utils::ByteArray compressedBytes){
	HX_STACK_PUSH("XMLDataParser::decompressData","hxDragonBones/objects/XMLDataParser.hx",52);
	HX_STACK_ARG(compressedBytes,"compressedBytes");
	struct _Function_1_1{
		inline static ::String Block( ::native::utils::ByteArray &compressedBytes){
			HX_STACK_PUSH("*::closure","hxDragonBones/objects/XMLDataParser.hx",53);
			{
				HX_STACK_LINE(53)
				::String type = null();		HX_STACK_VAR(type,"type");
				HX_STACK_LINE(53)
				int b1 = compressedBytes->__get((int)0);		HX_STACK_VAR(b1,"b1");
				HX_STACK_LINE(53)
				int b2 = compressedBytes->__get((int)1);		HX_STACK_VAR(b2,"b2");
				HX_STACK_LINE(53)
				int b3 = compressedBytes->__get((int)2);		HX_STACK_VAR(b3,"b3");
				HX_STACK_LINE(53)
				int b4 = compressedBytes->__get((int)3);		HX_STACK_VAR(b4,"b4");
				HX_STACK_LINE(53)
				if (((bool((bool(((bool((bool((b1 == (int)70)) || bool((b1 == (int)67)))) || bool((b1 == (int)90))))) && bool((b2 == (int)87)))) && bool((b3 == (int)83))))){
					HX_STACK_LINE(53)
					type = HX_CSTRING("swf");
				}
				else{
					HX_STACK_LINE(53)
					if (((bool((bool((bool((b1 == (int)137)) && bool((b2 == (int)80)))) && bool((b3 == (int)78)))) && bool((b4 == (int)71))))){
						HX_STACK_LINE(53)
						type = HX_CSTRING("png");
					}
					else{
						HX_STACK_LINE(53)
						if (((b1 == (int)255))){
							HX_STACK_LINE(53)
							type = HX_CSTRING("jpg");
						}
						else{
							HX_STACK_LINE(53)
							if (((bool((bool((b1 == (int)65)) && bool((b2 == (int)84)))) && bool((b3 == (int)70))))){
								HX_STACK_LINE(53)
								type = HX_CSTRING("atf");
							}
							else{
								HX_STACK_LINE(53)
								if (((bool((b1 == (int)80)) && bool((b2 == (int)75))))){
									HX_STACK_LINE(53)
									type = HX_CSTRING("zip");
								}
							}
						}
					}
				}
				HX_STACK_LINE(53)
				return type;
			}
			return null();
		}
	};
	HX_STACK_LINE(53)
	::String _switch_1 = (_Function_1_1::Block(compressedBytes));
	if (  ( _switch_1==HX_CSTRING("swf")) ||  ( _switch_1==HX_CSTRING("png")) ||  ( _switch_1==HX_CSTRING("jpg"))){
		HX_STACK_LINE(55)
		::Xml skeletonXml = null();		HX_STACK_VAR(skeletonXml,"skeletonXml");
		HX_STACK_LINE(56)
		::Xml texAtlasXml = null();		HX_STACK_VAR(texAtlasXml,"texAtlasXml");
		HX_STACK_LINE(57)
		compressedBytes->position = (compressedBytes->length - (int)4);
		HX_STACK_LINE(58)
		int strSize = compressedBytes->readInt();		HX_STACK_VAR(strSize,"strSize");
		HX_STACK_LINE(59)
		int position = ((compressedBytes->length - (int)4) - strSize);		HX_STACK_VAR(position,"position");
		HX_STACK_LINE(61)
		::native::utils::ByteArray xmlBytes = ::native::utils::ByteArray_obj::__new(null());		HX_STACK_VAR(xmlBytes,"xmlBytes");
		HX_STACK_LINE(62)
		xmlBytes->writeBytes(compressedBytes,position,strSize);
		HX_STACK_LINE(64)
		xmlBytes->uncompress(null());
		HX_STACK_LINE(69)
		compressedBytes->setLength(position);
		HX_STACK_LINE(72)
		skeletonXml = ::Xml_obj::parse(xmlBytes->readUTFBytes(xmlBytes->length));
		HX_STACK_LINE(74)
		compressedBytes->position = (compressedBytes->length - (int)4);
		HX_STACK_LINE(75)
		strSize = compressedBytes->readInt();
		HX_STACK_LINE(76)
		position = ((compressedBytes->length - (int)4) - strSize);
		HX_STACK_LINE(78)
		xmlBytes->clear();
		HX_STACK_LINE(79)
		xmlBytes->writeBytes(compressedBytes,position,strSize);
		HX_STACK_LINE(80)
		xmlBytes->uncompress(null());
		HX_STACK_LINE(85)
		compressedBytes->setLength(position);
		HX_STACK_LINE(88)
		texAtlasXml = ::Xml_obj::parse(xmlBytes->readUTFBytes(xmlBytes->length));
		HX_STACK_LINE(89)
		return ::hxDragonBones::objects::DecompressedData_obj::__new(skeletonXml,texAtlasXml,compressedBytes);
	}
	else if (  ( _switch_1==HX_CSTRING("zip"))){
		HX_STACK_LINE(90)
		hx::Throw (HX_CSTRING("Can not decompress zip!"));
	}
	else  {
		HX_STACK_LINE(91)
		hx::Throw (HX_CSTRING("Unknow format"));
	}
;
;
	HX_STACK_LINE(93)
	return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(XMLDataParser_obj,decompressData,return )

::hxDragonBones::objects::SkeletonData XMLDataParser_obj::parseSkeletonData( ::Xml skeletonXml){
	HX_STACK_PUSH("XMLDataParser::parseSkeletonData","hxDragonBones/objects/XMLDataParser.hx",96);
	HX_STACK_ARG(skeletonXml,"skeletonXml");
	HX_STACK_LINE(97)
	{
		HX_STACK_LINE(97)
		::String version = skeletonXml->firstElement()->get(HX_CSTRING("version"));		HX_STACK_VAR(version,"version");
		HX_STACK_LINE(97)
		if (((bool((version != HX_CSTRING("1.4"))) && bool((version != HX_CSTRING("2.0")))))){
			HX_STACK_LINE(97)
			hx::Throw (HX_CSTRING("Nonsupport data version!"));
		}
	}
	HX_STACK_LINE(99)
	::hxDragonBones::objects::SkeletonData skeletonData = ::hxDragonBones::objects::SkeletonData_obj::__new();		HX_STACK_VAR(skeletonData,"skeletonData");
	HX_STACK_LINE(100)
	skeletonData->name = skeletonXml->firstElement()->get(HX_CSTRING("name"));
	HX_STACK_LINE(101)
	skeletonData->frameRate = ::Std_obj::parseInt(skeletonXml->firstElement()->get(HX_CSTRING("frameRate")));
	HX_STACK_LINE(102)
	::hxDragonBones::objects::XMLDataParser_obj::_curSkeletonData = skeletonData;
	HX_STACK_LINE(104)
	::hxDragonBones::objects::XMLDataParser_obj::parseArmatures(skeletonXml->firstChild());
	HX_STACK_LINE(105)
	::hxDragonBones::objects::XMLDataParser_obj::parseAnimations(skeletonXml->firstChild());
	HX_STACK_LINE(107)
	::hxDragonBones::objects::XMLDataParser_obj::_curSkeletonData = null();
	HX_STACK_LINE(108)
	return skeletonData;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(XMLDataParser_obj,parseSkeletonData,return )

Void XMLDataParser_obj::parseArmatures( ::Xml armaturesXml){
{
		HX_STACK_PUSH("XMLDataParser::parseArmatures","hxDragonBones/objects/XMLDataParser.hx",111);
		HX_STACK_ARG(armaturesXml,"armaturesXml");
		HX_STACK_LINE(111)
		for(::cpp::FastIterator_obj< ::Xml > *__it = ::cpp::CreateFastIterator< ::Xml >(armaturesXml->elementsNamed(HX_CSTRING("armatures")));  __it->hasNext(); ){
			::Xml armatures = __it->next();
			{
				HX_STACK_LINE(112)
				for(::cpp::FastIterator_obj< ::Xml > *__it = ::cpp::CreateFastIterator< ::Xml >(armatures->elementsNamed(HX_CSTRING("armature")));  __it->hasNext(); ){
					::Xml armature = __it->next();
					{
						HX_STACK_LINE(114)
						::String name = armature->get(HX_CSTRING("name"));		HX_STACK_VAR(name,"name");
						HX_STACK_LINE(115)
						::hxDragonBones::objects::ArmatureData armatureData = ::hxDragonBones::objects::XMLDataParser_obj::_curSkeletonData->getArmatureData(name);		HX_STACK_VAR(armatureData,"armatureData");
						HX_STACK_LINE(116)
						if (((armatureData != null()))){
							HX_STACK_LINE(116)
							::hxDragonBones::objects::XMLDataParser_obj::parseArmatureData(armature,armatureData);
						}
						else{
							HX_STACK_LINE(119)
							armatureData = ::hxDragonBones::objects::ArmatureData_obj::__new();
							HX_STACK_LINE(120)
							::hxDragonBones::objects::XMLDataParser_obj::parseArmatureData(armature,armatureData);
							HX_STACK_LINE(121)
							::hxDragonBones::objects::XMLDataParser_obj::_curSkeletonData->armatureDataList->addData(armatureData,name);
						}
					}
;
				}
			}
;
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(XMLDataParser_obj,parseArmatures,(void))

Void XMLDataParser_obj::parseArmatureData( ::Xml armatureXml,::hxDragonBones::objects::ArmatureData armatureData){
{
		HX_STACK_PUSH("XMLDataParser::parseArmatureData","hxDragonBones/objects/XMLDataParser.hx",127);
		HX_STACK_ARG(armatureXml,"armatureXml");
		HX_STACK_ARG(armatureData,"armatureData");
		HX_STACK_LINE(129)
		for(::cpp::FastIterator_obj< ::Xml > *__it = ::cpp::CreateFastIterator< ::Xml >(armatureXml->elementsNamed(HX_CSTRING("b")));  __it->hasNext(); ){
			::Xml boneXml = __it->next();
			{
				HX_STACK_LINE(130)
				::String boneName = boneXml->get(HX_CSTRING("name"));		HX_STACK_VAR(boneName,"boneName");
				HX_STACK_LINE(131)
				::String parentName = boneXml->get(HX_CSTRING("parent"));		HX_STACK_VAR(parentName,"parentName");
				HX_STACK_LINE(132)
				::Xml parentXML = null();		HX_STACK_VAR(parentXML,"parentXML");
				HX_STACK_LINE(133)
				::hxDragonBones::objects::BoneData boneData = armatureData->getBoneData(boneName);		HX_STACK_VAR(boneData,"boneData");
				HX_STACK_LINE(134)
				if (((boneData != null()))){
					HX_STACK_LINE(134)
					::hxDragonBones::objects::XMLDataParser_obj::parseBoneData(boneXml,parentXML,boneData);
				}
				else{
					HX_STACK_LINE(137)
					boneData = ::hxDragonBones::objects::BoneData_obj::__new();
					HX_STACK_LINE(138)
					::hxDragonBones::objects::XMLDataParser_obj::parseBoneData(boneXml,parentXML,boneData);
					HX_STACK_LINE(139)
					armatureData->boneDataList->addData(boneData,boneName);
				}
			}
;
		}
		HX_STACK_LINE(143)
		armatureData->updateBoneList();
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(XMLDataParser_obj,parseArmatureData,(void))

Void XMLDataParser_obj::parseBoneData( ::Xml boneXml,::Xml parentXml,::hxDragonBones::objects::BoneData boneData){
{
		HX_STACK_PUSH("XMLDataParser::parseBoneData","hxDragonBones/objects/XMLDataParser.hx",146);
		HX_STACK_ARG(boneXml,"boneXml");
		HX_STACK_ARG(parentXml,"parentXml");
		HX_STACK_ARG(boneData,"boneData");
		HX_STACK_LINE(147)
		{
			HX_STACK_LINE(147)
			::hxDragonBones::objects::Node node = boneData->node;		HX_STACK_VAR(node,"node");
			HX_STACK_LINE(147)
			node->x = ::Std_obj::parseFloat(boneXml->get(HX_CSTRING("x")));
			HX_STACK_LINE(147)
			node->y = ::Std_obj::parseFloat(boneXml->get(HX_CSTRING("y")));
			HX_STACK_LINE(147)
			node->skewX = (::Std_obj::parseFloat(boneXml->get(HX_CSTRING("kX"))) * ((Float(::Math_obj::PI) / Float((int)180))));
			HX_STACK_LINE(147)
			node->skewY = (::Std_obj::parseFloat(boneXml->get(HX_CSTRING("kY"))) * ((Float(::Math_obj::PI) / Float((int)180))));
			HX_STACK_LINE(147)
			node->scaleX = ::Std_obj::parseFloat(boneXml->get(HX_CSTRING("cX")));
			HX_STACK_LINE(147)
			node->scaleY = ::Std_obj::parseFloat(boneXml->get(HX_CSTRING("cY")));
			HX_STACK_LINE(147)
			node->pivotX = ::Std_obj::parseFloat(boneXml->get(HX_CSTRING("pX")));
			HX_STACK_LINE(147)
			node->pivotY = ::Std_obj::parseFloat(boneXml->get(HX_CSTRING("pY")));
			HX_STACK_LINE(147)
			node->z = ::Std_obj::parseFloat(boneXml->get(HX_CSTRING("z")));
		}
		HX_STACK_LINE(149)
		if (((parentXml != null()))){
			HX_STACK_LINE(150)
			boneData->parent = parentXml->get(HX_CSTRING("name"));
			HX_STACK_LINE(151)
			{
				HX_STACK_LINE(151)
				::hxDragonBones::objects::Node node = ::hxDragonBones::objects::XMLDataParser_obj::_helpNode;		HX_STACK_VAR(node,"node");
				HX_STACK_LINE(151)
				node->x = ::Std_obj::parseFloat(parentXml->get(HX_CSTRING("x")));
				HX_STACK_LINE(151)
				node->y = ::Std_obj::parseFloat(parentXml->get(HX_CSTRING("y")));
				HX_STACK_LINE(151)
				node->skewX = (::Std_obj::parseFloat(parentXml->get(HX_CSTRING("kX"))) * ((Float(::Math_obj::PI) / Float((int)180))));
				HX_STACK_LINE(151)
				node->skewY = (::Std_obj::parseFloat(parentXml->get(HX_CSTRING("kY"))) * ((Float(::Math_obj::PI) / Float((int)180))));
				HX_STACK_LINE(151)
				node->scaleX = ::Std_obj::parseFloat(parentXml->get(HX_CSTRING("cX")));
				HX_STACK_LINE(151)
				node->scaleY = ::Std_obj::parseFloat(parentXml->get(HX_CSTRING("cY")));
				HX_STACK_LINE(151)
				node->pivotX = ::Std_obj::parseFloat(parentXml->get(HX_CSTRING("pX")));
				HX_STACK_LINE(151)
				node->pivotY = ::Std_obj::parseFloat(parentXml->get(HX_CSTRING("pY")));
				HX_STACK_LINE(151)
				node->z = ::Std_obj::parseFloat(parentXml->get(HX_CSTRING("z")));
			}
			HX_STACK_LINE(152)
			{
				HX_STACK_LINE(152)
				::hxDragonBones::objects::Node bone = boneData->node;		HX_STACK_VAR(bone,"bone");
				::hxDragonBones::objects::Node parent = ::hxDragonBones::objects::XMLDataParser_obj::_helpNode;		HX_STACK_VAR(parent,"parent");
				HX_STACK_LINE(152)
				{
					HX_STACK_LINE(152)
					::native::geom::Matrix resultMatrix = ::hxDragonBones::utils::TransformUtils_obj::_helpMatrix;		HX_STACK_VAR(resultMatrix,"resultMatrix");
					HX_STACK_LINE(152)
					resultMatrix->identity();
					HX_STACK_LINE(152)
					resultMatrix->rotate(parent->skewX);
					HX_STACK_LINE(152)
					resultMatrix->scale(parent->scaleX,parent->scaleY);
					HX_STACK_LINE(152)
					resultMatrix->translate(parent->x,parent->y);
				}
				HX_STACK_LINE(152)
				::hxDragonBones::utils::TransformUtils_obj::_helpPoint->x = bone->x;
				HX_STACK_LINE(152)
				::hxDragonBones::utils::TransformUtils_obj::_helpPoint->y = bone->y;
				HX_STACK_LINE(152)
				::hxDragonBones::utils::TransformUtils_obj::_helpMatrix->invert();
				HX_STACK_LINE(152)
				::hxDragonBones::utils::TransformUtils_obj::_helpPoint = ::hxDragonBones::utils::TransformUtils_obj::_helpMatrix->transformPoint(::hxDragonBones::utils::TransformUtils_obj::_helpPoint);
				HX_STACK_LINE(152)
				bone->x = ::hxDragonBones::utils::TransformUtils_obj::_helpPoint->x;
				HX_STACK_LINE(152)
				bone->y = ::hxDragonBones::utils::TransformUtils_obj::_helpPoint->y;
				HX_STACK_LINE(152)
				hx::SubEq(bone->skewX,parent->skewX);
				HX_STACK_LINE(152)
				hx::SubEq(bone->skewY,parent->skewY);
			}
		}
		else{
			HX_STACK_LINE(153)
			boneData->parent = null();
		}
		HX_STACK_LINE(157)
		if (((::hxDragonBones::objects::XMLDataParser_obj::_curSkeletonData != null()))){
			HX_STACK_LINE(158)
			int i = (int)0;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(159)
			for(::cpp::FastIterator_obj< ::Xml > *__it = ::cpp::CreateFastIterator< ::Xml >(boneXml->elementsNamed(HX_CSTRING("d")));  __it->hasNext(); ){
				::Xml displayXML = __it->next();
				{
					HX_STACK_LINE(160)
					::String name = displayXML->get(HX_CSTRING("name"));		HX_STACK_VAR(name,"name");
					HX_STACK_LINE(161)
					boneData->displayNames[(i)++] = name;
					HX_STACK_LINE(162)
					::hxDragonBones::objects::DisplayData displayData = ::hxDragonBones::objects::XMLDataParser_obj::_curSkeletonData->getDisplayData(name);		HX_STACK_VAR(displayData,"displayData");
					HX_STACK_LINE(163)
					if (((displayData != null()))){
						HX_STACK_LINE(163)
						{
							HX_STACK_LINE(164)
							displayData->isArmature = (displayXML->get(HX_CSTRING("isArmature")) != null());
							HX_STACK_LINE(164)
							displayData->pivotX = ::Std_obj::parseInt(displayXML->get(HX_CSTRING("pX")));
							HX_STACK_LINE(164)
							displayData->pivotY = ::Std_obj::parseInt(displayXML->get(HX_CSTRING("pY")));
						}
					}
					else{
						HX_STACK_LINE(166)
						displayData = ::hxDragonBones::objects::DisplayData_obj::__new();
						HX_STACK_LINE(167)
						{
							HX_STACK_LINE(167)
							displayData->isArmature = (displayXML->get(HX_CSTRING("isArmature")) != null());
							HX_STACK_LINE(167)
							displayData->pivotX = ::Std_obj::parseInt(displayXML->get(HX_CSTRING("pX")));
							HX_STACK_LINE(167)
							displayData->pivotY = ::Std_obj::parseInt(displayXML->get(HX_CSTRING("pY")));
						}
						HX_STACK_LINE(168)
						::hxDragonBones::objects::XMLDataParser_obj::_curSkeletonData->displayDataList->addData(displayData,name);
					}
				}
;
			}
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(XMLDataParser_obj,parseBoneData,(void))

Void XMLDataParser_obj::parseDisplayData( ::Xml displayXml,::hxDragonBones::objects::DisplayData displayData){
{
		HX_STACK_PUSH("XMLDataParser::parseDisplayData","hxDragonBones/objects/XMLDataParser.hx",174);
		HX_STACK_ARG(displayXml,"displayXml");
		HX_STACK_ARG(displayData,"displayData");
		HX_STACK_LINE(175)
		displayData->isArmature = (displayXml->get(HX_CSTRING("isArmature")) != null());
		HX_STACK_LINE(176)
		displayData->pivotX = ::Std_obj::parseInt(displayXml->get(HX_CSTRING("pX")));
		HX_STACK_LINE(177)
		displayData->pivotY = ::Std_obj::parseInt(displayXml->get(HX_CSTRING("pY")));
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(XMLDataParser_obj,parseDisplayData,(void))

Void XMLDataParser_obj::parseAnimations( ::Xml animationsXml){
{
		HX_STACK_PUSH("XMLDataParser::parseAnimations","hxDragonBones/objects/XMLDataParser.hx",180);
		HX_STACK_ARG(animationsXml,"animationsXml");
		HX_STACK_LINE(180)
		for(::cpp::FastIterator_obj< ::Xml > *__it = ::cpp::CreateFastIterator< ::Xml >(animationsXml->elementsNamed(HX_CSTRING("animations")));  __it->hasNext(); ){
			::Xml animations = __it->next();
			{
				HX_STACK_LINE(181)
				for(::cpp::FastIterator_obj< ::Xml > *__it = ::cpp::CreateFastIterator< ::Xml >(animations->elementsNamed(HX_CSTRING("animation")));  __it->hasNext(); ){
					::Xml animation = __it->next();
					{
						HX_STACK_LINE(183)
						::String name = animation->get(HX_CSTRING("name"));		HX_STACK_VAR(name,"name");
						HX_STACK_LINE(184)
						::hxDragonBones::objects::ArmatureData armatureData = ::hxDragonBones::objects::XMLDataParser_obj::_curSkeletonData->getArmatureData(name);		HX_STACK_VAR(armatureData,"armatureData");
						HX_STACK_LINE(185)
						::hxDragonBones::objects::AnimationData animationData = ::hxDragonBones::objects::XMLDataParser_obj::_curSkeletonData->getAnimationData(name);		HX_STACK_VAR(animationData,"animationData");
						HX_STACK_LINE(186)
						if (((animationData != null()))){
							HX_STACK_LINE(186)
							::hxDragonBones::objects::XMLDataParser_obj::parseAnimationData(animation,animationData,armatureData);
						}
						else{
							HX_STACK_LINE(189)
							animationData = ::hxDragonBones::objects::AnimationData_obj::__new();
							HX_STACK_LINE(190)
							::hxDragonBones::objects::XMLDataParser_obj::parseAnimationData(animation,animationData,armatureData);
							HX_STACK_LINE(191)
							::hxDragonBones::objects::XMLDataParser_obj::_curSkeletonData->animationDataList->addData(animationData,name);
						}
					}
;
				}
			}
;
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(XMLDataParser_obj,parseAnimations,(void))

Void XMLDataParser_obj::parseAnimationData( ::Xml animationXml,::hxDragonBones::objects::AnimationData animationData,::hxDragonBones::objects::ArmatureData armatureData){
{
		HX_STACK_PUSH("XMLDataParser::parseAnimationData","hxDragonBones/objects/XMLDataParser.hx",197);
		HX_STACK_ARG(animationXml,"animationXml");
		HX_STACK_ARG(animationData,"animationData");
		HX_STACK_ARG(armatureData,"armatureData");
		HX_STACK_LINE(197)
		for(::cpp::FastIterator_obj< ::Xml > *__it = ::cpp::CreateFastIterator< ::Xml >(animationXml->elementsNamed(HX_CSTRING("mov")));  __it->hasNext(); ){
			::Xml movement = __it->next();
			{
				HX_STACK_LINE(199)
				::String name = movement->get(HX_CSTRING("name"));		HX_STACK_VAR(name,"name");
				HX_STACK_LINE(200)
				::hxDragonBones::objects::MovementData movementData = animationData->getMovementData(name);		HX_STACK_VAR(movementData,"movementData");
				HX_STACK_LINE(201)
				if (((movementData != null()))){
					HX_STACK_LINE(201)
					::hxDragonBones::objects::XMLDataParser_obj::parseMovementData(movement,armatureData,movementData);
				}
				else{
					HX_STACK_LINE(204)
					movementData = ::hxDragonBones::objects::MovementData_obj::__new();
					HX_STACK_LINE(205)
					::hxDragonBones::objects::XMLDataParser_obj::parseMovementData(movement,armatureData,movementData);
					HX_STACK_LINE(206)
					animationData->movementDataList->addData(movementData,name);
				}
			}
;
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(XMLDataParser_obj,parseAnimationData,(void))

Void XMLDataParser_obj::parseMovementData( ::Xml movementXml,::hxDragonBones::objects::ArmatureData armatureData,::hxDragonBones::objects::MovementData movementData){
{
		HX_STACK_PUSH("XMLDataParser::parseMovementData","hxDragonBones/objects/XMLDataParser.hx",211);
		HX_STACK_ARG(movementXml,"movementXml");
		HX_STACK_ARG(armatureData,"armatureData");
		HX_STACK_ARG(movementData,"movementData");
		HX_STACK_LINE(212)
		if (((::hxDragonBones::objects::XMLDataParser_obj::_curSkeletonData != null()))){
			HX_STACK_LINE(213)
			int frameRate = ::hxDragonBones::objects::XMLDataParser_obj::_curSkeletonData->frameRate;		HX_STACK_VAR(frameRate,"frameRate");
			HX_STACK_LINE(214)
			int duration = ::Std_obj::parseInt(movementXml->get(HX_CSTRING("dr")));		HX_STACK_VAR(duration,"duration");
			HX_STACK_LINE(216)
			movementData->duration = (  (((duration > (int)1))) ? Float((Float(duration) / Float(frameRate))) : Float((int)0) );
			HX_STACK_LINE(217)
			movementData->durationTo = (Float(::Std_obj::parseInt(movementXml->get(HX_CSTRING("to")))) / Float(frameRate));
			HX_STACK_LINE(218)
			movementData->durationTween = (Float(::Std_obj::parseInt(movementXml->get(HX_CSTRING("drTW")))) / Float(frameRate));
			HX_STACK_LINE(219)
			movementData->loop = (::Std_obj::parseInt(movementXml->get(HX_CSTRING("lp"))) == (int)1);
			HX_STACK_LINE(220)
			movementData->tweenEasing = ::Std_obj::parseFloat(movementXml->get(HX_CSTRING("twE")));
		}
		HX_STACK_LINE(223)
		Array< ::String > boneNames = armatureData->get_boneNames();		HX_STACK_VAR(boneNames,"boneNames");
		HX_STACK_LINE(225)
		Dynamic movementBoneXMLList = movementXml->elementsNamed(HX_CSTRING("b"));		HX_STACK_VAR(movementBoneXMLList,"movementBoneXMLList");
		HX_STACK_LINE(226)
		for(::cpp::FastIterator_obj< ::Xml > *__it = ::cpp::CreateFastIterator< ::Xml >(movementXml->elementsNamed(HX_CSTRING("b")));  __it->hasNext(); ){
			::Xml movementBoneXML = __it->next();
			{
				HX_STACK_LINE(227)
				::String boneName = movementBoneXML->get(HX_CSTRING("name"));		HX_STACK_VAR(boneName,"boneName");
				HX_STACK_LINE(228)
				::hxDragonBones::objects::BoneData boneData = armatureData->getBoneData(boneName);		HX_STACK_VAR(boneData,"boneData");
				HX_STACK_LINE(229)
				::Xml parentMovementBoneXml = null();		HX_STACK_VAR(parentMovementBoneXml,"parentMovementBoneXml");
				HX_STACK_LINE(230)
				::hxDragonBones::objects::MovementBoneData movementBoneData = movementData->getMovementBoneData(boneName);		HX_STACK_VAR(movementBoneData,"movementBoneData");
				HX_STACK_LINE(231)
				if (((movementBoneXML != null()))){
					HX_STACK_LINE(231)
					if (((movementBoneData != null()))){
						HX_STACK_LINE(232)
						::hxDragonBones::objects::XMLDataParser_obj::parseMovementBoneData(movementBoneXML,parentMovementBoneXml,boneData,movementBoneData);
					}
					else{
						HX_STACK_LINE(235)
						movementBoneData = ::hxDragonBones::objects::MovementBoneData_obj::__new();
						HX_STACK_LINE(236)
						::hxDragonBones::objects::XMLDataParser_obj::parseMovementBoneData(movementBoneXML,parentMovementBoneXml,boneData,movementBoneData);
						HX_STACK_LINE(237)
						movementData->movementBoneDataList->addData(movementBoneData,boneName);
					}
				}
				HX_STACK_LINE(241)
				int index = ::Lambda_obj::indexOf(boneNames,boneName);		HX_STACK_VAR(index,"index");
				HX_STACK_LINE(242)
				if (((index != (int)-1))){
					HX_STACK_LINE(242)
					boneNames->splice(index,(int)1);
				}
			}
;
		}
		HX_STACK_LINE(247)
		{
			HX_STACK_LINE(247)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(247)
			while(((_g < boneNames->length))){
				HX_STACK_LINE(247)
				::String boneName = boneNames->__get(_g);		HX_STACK_VAR(boneName,"boneName");
				HX_STACK_LINE(247)
				++(_g);
				HX_STACK_LINE(248)
				movementData->movementBoneDataList->addData(::hxDragonBones::objects::MovementBoneData_obj::HIDE_DATA,boneName);
			}
		}
		HX_STACK_LINE(251)
		int i = (int)0;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(252)
		for(::cpp::FastIterator_obj< ::Xml > *__it = ::cpp::CreateFastIterator< ::Xml >(movementXml->elementsNamed(HX_CSTRING("f")));  __it->hasNext(); ){
			::Xml movementFrameXML = __it->next();
			{
				HX_STACK_LINE(253)
				::hxDragonBones::objects::MovementFrameData movementFrameData = (  (((movementData->movementFrameList->length > i))) ? ::hxDragonBones::objects::MovementFrameData(movementData->movementFrameList->__get(i)) : ::hxDragonBones::objects::MovementFrameData(null()) );		HX_STACK_VAR(movementFrameData,"movementFrameData");
				HX_STACK_LINE(254)
				if (((movementFrameData != null()))){
					HX_STACK_LINE(254)
					movementFrameData->setValues((Float(::Std_obj::parseFloat(movementFrameXML->get(HX_CSTRING("dr")))) / Float(::hxDragonBones::objects::XMLDataParser_obj::_curSkeletonData->frameRate)),movementFrameXML->get(HX_CSTRING("mov")),movementFrameXML->get(HX_CSTRING("evt")),movementFrameXML->get(HX_CSTRING("sd")));
				}
				else{
					HX_STACK_LINE(257)
					movementFrameData = ::hxDragonBones::objects::MovementFrameData_obj::__new();
					HX_STACK_LINE(258)
					movementFrameData->setValues((Float(::Std_obj::parseFloat(movementFrameXML->get(HX_CSTRING("dr")))) / Float(::hxDragonBones::objects::XMLDataParser_obj::_curSkeletonData->frameRate)),movementFrameXML->get(HX_CSTRING("mov")),movementFrameXML->get(HX_CSTRING("evt")),movementFrameXML->get(HX_CSTRING("sd")));
					HX_STACK_LINE(259)
					if ((!(::Lambda_obj::has(movementData->movementFrameList,movementFrameData,null())))){
						HX_STACK_LINE(259)
						movementData->movementFrameList->push(movementFrameData);
					}
				}
				HX_STACK_LINE(263)
				(i)++;
			}
;
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(XMLDataParser_obj,parseMovementData,(void))

Void XMLDataParser_obj::parseMovementBoneData( ::Xml movementBoneXML,::Xml parentMovementBoneXML,::hxDragonBones::objects::BoneData boneData,::hxDragonBones::objects::MovementBoneData movementBoneData){
{
		HX_STACK_PUSH("XMLDataParser::parseMovementBoneData","hxDragonBones/objects/XMLDataParser.hx",267);
		HX_STACK_ARG(movementBoneXML,"movementBoneXML");
		HX_STACK_ARG(parentMovementBoneXML,"parentMovementBoneXML");
		HX_STACK_ARG(boneData,"boneData");
		HX_STACK_ARG(movementBoneData,"movementBoneData");
		HX_STACK_LINE(268)
		Float scale = ::Std_obj::parseFloat(movementBoneXML->get(HX_CSTRING("sc")));		HX_STACK_VAR(scale,"scale");
		HX_STACK_LINE(269)
		Float delay = ::Std_obj::parseFloat(movementBoneXML->get(HX_CSTRING("dl")));		HX_STACK_VAR(delay,"delay");
		HX_STACK_LINE(270)
		movementBoneData->setValues(scale,delay);
		HX_STACK_LINE(272)
		Dynamic parentFrameXMLList = null();		HX_STACK_VAR(parentFrameXMLList,"parentFrameXMLList");
		HX_STACK_LINE(273)
		int parentFrameCount = (int)0;		HX_STACK_VAR(parentFrameCount,"parentFrameCount");
		HX_STACK_LINE(274)
		::Xml parentFrameXML = null();		HX_STACK_VAR(parentFrameXML,"parentFrameXML");
		HX_STACK_LINE(275)
		int parentTotalDuration = (int)0;		HX_STACK_VAR(parentTotalDuration,"parentTotalDuration");
		HX_STACK_LINE(276)
		int totalDuration = (int)0;		HX_STACK_VAR(totalDuration,"totalDuration");
		HX_STACK_LINE(277)
		int currentDuration = (int)0;		HX_STACK_VAR(currentDuration,"currentDuration");
		HX_STACK_LINE(278)
		if (((parentMovementBoneXML != null()))){
			HX_STACK_LINE(279)
			parentFrameXMLList = parentMovementBoneXML->elementsNamed(HX_CSTRING("f"));
			HX_STACK_LINE(280)
			parentFrameCount = ::Lambda_obj::count(parentMovementBoneXML,null());
		}
		HX_STACK_LINE(283)
		Dynamic frameXMLList = movementBoneXML->elementsNamed(HX_CSTRING("f"));		HX_STACK_VAR(frameXMLList,"frameXMLList");
		HX_STACK_LINE(284)
		Array< ::hxDragonBones::objects::FrameData > frameList = movementBoneData->frameList;		HX_STACK_VAR(frameList,"frameList");
		HX_STACK_LINE(286)
		int i = (int)0;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(287)
		int j = (int)0;		HX_STACK_VAR(j,"j");
		HX_STACK_LINE(288)
		for(::cpp::FastIterator_obj< ::Xml > *__it = ::cpp::CreateFastIterator< ::Xml >(frameXMLList);  __it->hasNext(); ){
			::Xml frameXML = __it->next();
			{
				HX_STACK_LINE(289)
				::hxDragonBones::objects::FrameData frameData = (  (((frameList->length > j))) ? ::hxDragonBones::objects::FrameData(frameList->__get(j)) : ::hxDragonBones::objects::FrameData(null()) );		HX_STACK_VAR(frameData,"frameData");
				HX_STACK_LINE(291)
				if (((frameData != null()))){
					HX_STACK_LINE(291)
					::hxDragonBones::objects::XMLDataParser_obj::parseFrameData(frameXML,frameData);
				}
				else{
					HX_STACK_LINE(294)
					frameData = ::hxDragonBones::objects::FrameData_obj::__new();
					HX_STACK_LINE(295)
					frameList->push(frameData);
					HX_STACK_LINE(296)
					::hxDragonBones::objects::XMLDataParser_obj::parseFrameData(frameXML,frameData);
				}
				HX_STACK_LINE(299)
				if (((parentMovementBoneXML != null()))){
					HX_STACK_LINE(300)
					while(((bool((i < parentFrameCount)) && bool(((  (((parentFrameXML != null()))) ? bool((bool((totalDuration < parentTotalDuration)) || bool((totalDuration >= (parentTotalDuration + currentDuration))))) : bool(true) )))))){
						HX_STACK_LINE(301)
						parentFrameXML = parentFrameXMLList->__Field(HX_CSTRING("next"),true)();
						HX_STACK_LINE(302)
						hx::AddEq(parentTotalDuration,currentDuration);
						HX_STACK_LINE(303)
						currentDuration = ::Std_obj::parseInt(parentFrameXML->get(HX_CSTRING("dr")));
						HX_STACK_LINE(304)
						(i)++;
					}
					HX_STACK_LINE(307)
					::hxDragonBones::objects::XMLDataParser_obj::parseFrameData(parentFrameXML,::hxDragonBones::objects::XMLDataParser_obj::_helpFrameData);
					HX_STACK_LINE(309)
					::Xml tweenFrameXML = null();		HX_STACK_VAR(tweenFrameXML,"tweenFrameXML");
					HX_STACK_LINE(310)
					Float progress;		HX_STACK_VAR(progress,"progress");
					HX_STACK_LINE(311)
					if (((tweenFrameXML != null()))){
						HX_STACK_LINE(311)
						progress = (Float(((totalDuration - parentTotalDuration))) / Float(currentDuration));
					}
					else{
						HX_STACK_LINE(314)
						tweenFrameXML = parentFrameXML;
						HX_STACK_LINE(315)
						progress = (int)0;
					}
					HX_STACK_LINE(318)
					if ((::Math_obj::isNaN(::hxDragonBones::objects::XMLDataParser_obj::_helpFrameData->tweenEasing))){
						HX_STACK_LINE(318)
						progress = (int)0;
					}
					else{
						struct _Function_4_1{
							inline static Float Block( Float &progress){
								HX_STACK_PUSH("*::closure","hxDragonBones/objects/XMLDataParser.hx",321);
								{
									HX_STACK_LINE(321)
									Float value = progress;		HX_STACK_VAR(value,"value");
									Dynamic easing = ::hxDragonBones::objects::XMLDataParser_obj::_helpFrameData->tweenEasing;		HX_STACK_VAR(easing,"easing");
									HX_STACK_LINE(321)
									Float valueEase = (int)0;		HX_STACK_VAR(valueEase,"valueEase");
									HX_STACK_LINE(321)
									if ((::Math_obj::isNaN(easing))){
										HX_STACK_LINE(321)
										valueEase = (int)0;
										HX_STACK_LINE(321)
										easing = (int)0;
										HX_STACK_LINE(321)
										value = (int)0;
									}
									else{
										HX_STACK_LINE(321)
										if (((easing > (int)1))){
											HX_STACK_LINE(321)
											valueEase = ((0.5 * (((int)1 - ::Math_obj::cos((value * ::Math_obj::PI))))) - value);
											HX_STACK_LINE(321)
											hx::SubEq(easing,(int)1);
										}
										else{
											HX_STACK_LINE(321)
											if (((easing > (int)0))){
												HX_STACK_LINE(321)
												valueEase = (::Math_obj::sin((value * ((::Math_obj::PI * 0.5)))) - value);
											}
											else{
												HX_STACK_LINE(321)
												if (((easing < (int)0))){
													HX_STACK_LINE(321)
													valueEase = (((int)1 - ::Math_obj::cos((value * ((::Math_obj::PI * 0.5))))) - value);
													HX_STACK_LINE(321)
													hx::MultEq(easing,(int)-1);
												}
											}
										}
									}
									HX_STACK_LINE(321)
									return ((valueEase * easing) + value);
								}
								return null();
							}
						};
						HX_STACK_LINE(320)
						progress = _Function_4_1::Block(progress);
					}
					HX_STACK_LINE(324)
					{
						HX_STACK_LINE(324)
						::hxDragonBones::objects::Node node = ::hxDragonBones::objects::XMLDataParser_obj::_helpNode;		HX_STACK_VAR(node,"node");
						HX_STACK_LINE(324)
						node->x = ::Std_obj::parseFloat(tweenFrameXML->get(HX_CSTRING("x")));
						HX_STACK_LINE(324)
						node->y = ::Std_obj::parseFloat(tweenFrameXML->get(HX_CSTRING("y")));
						HX_STACK_LINE(324)
						node->skewX = (::Std_obj::parseFloat(tweenFrameXML->get(HX_CSTRING("kX"))) * ((Float(::Math_obj::PI) / Float((int)180))));
						HX_STACK_LINE(324)
						node->skewY = (::Std_obj::parseFloat(tweenFrameXML->get(HX_CSTRING("kY"))) * ((Float(::Math_obj::PI) / Float((int)180))));
						HX_STACK_LINE(324)
						node->scaleX = ::Std_obj::parseFloat(tweenFrameXML->get(HX_CSTRING("cX")));
						HX_STACK_LINE(324)
						node->scaleY = ::Std_obj::parseFloat(tweenFrameXML->get(HX_CSTRING("cY")));
						HX_STACK_LINE(324)
						node->pivotX = ::Std_obj::parseFloat(tweenFrameXML->get(HX_CSTRING("pX")));
						HX_STACK_LINE(324)
						node->pivotY = ::Std_obj::parseFloat(tweenFrameXML->get(HX_CSTRING("pY")));
						HX_STACK_LINE(324)
						node->z = ::Std_obj::parseFloat(tweenFrameXML->get(HX_CSTRING("z")));
					}
					HX_STACK_LINE(325)
					{
						HX_STACK_LINE(325)
						::hxDragonBones::objects::Node from = ::hxDragonBones::objects::XMLDataParser_obj::_helpFrameData->node;		HX_STACK_VAR(from,"from");
						::hxDragonBones::objects::Node to = ::hxDragonBones::objects::XMLDataParser_obj::_helpNode;		HX_STACK_VAR(to,"to");
						::hxDragonBones::objects::Node offSet = ::hxDragonBones::objects::XMLDataParser_obj::_helpNode;		HX_STACK_VAR(offSet,"offSet");
						int tweenRotate = ::hxDragonBones::objects::XMLDataParser_obj::_helpFrameData->tweenRotate;		HX_STACK_VAR(tweenRotate,"tweenRotate");
						HX_STACK_LINE(325)
						offSet->x = (to->x - from->x);
						HX_STACK_LINE(325)
						offSet->y = (to->y - from->y);
						HX_STACK_LINE(325)
						offSet->skewX = (to->skewX - from->skewX);
						HX_STACK_LINE(325)
						offSet->skewY = (to->skewY - from->skewY);
						HX_STACK_LINE(325)
						offSet->scaleX = (to->scaleX - from->scaleX);
						HX_STACK_LINE(325)
						offSet->scaleY = (to->scaleY - from->scaleY);
						HX_STACK_LINE(325)
						offSet->pivotX = (to->pivotX - from->pivotX);
						HX_STACK_LINE(325)
						offSet->pivotY = (to->pivotY - from->pivotY);
						HX_STACK_LINE(325)
						hx::ModEq(offSet->skewX,(::Math_obj::PI * (int)2));
						HX_STACK_LINE(325)
						if (((offSet->skewX > ::Math_obj::PI))){
							HX_STACK_LINE(325)
							hx::SubEq(offSet->skewX,(::Math_obj::PI * (int)2));
						}
						HX_STACK_LINE(325)
						if (((offSet->skewX < -(::Math_obj::PI)))){
							HX_STACK_LINE(325)
							hx::AddEq(offSet->skewX,(::Math_obj::PI * (int)2));
						}
						HX_STACK_LINE(325)
						hx::ModEq(offSet->skewY,(::Math_obj::PI * (int)2));
						HX_STACK_LINE(325)
						if (((offSet->skewY > ::Math_obj::PI))){
							HX_STACK_LINE(325)
							hx::SubEq(offSet->skewY,(::Math_obj::PI * (int)2));
						}
						HX_STACK_LINE(325)
						if (((offSet->skewY < -(::Math_obj::PI)))){
							HX_STACK_LINE(325)
							hx::AddEq(offSet->skewY,(::Math_obj::PI * (int)2));
						}
						HX_STACK_LINE(325)
						if (((tweenRotate != (int)0))){
							HX_STACK_LINE(325)
							Float value = (tweenRotate * ((::Math_obj::PI * (int)2)));		HX_STACK_VAR(value,"value");
							HX_STACK_LINE(325)
							hx::AddEq(offSet->skewX,value);
							HX_STACK_LINE(325)
							hx::AddEq(offSet->skewY,value);
						}
					}
					HX_STACK_LINE(327)
					::hxDragonBones::objects::XMLDataParser_obj::_helpNode->setValues((::hxDragonBones::objects::XMLDataParser_obj::_helpFrameData->node->x + (progress * ::hxDragonBones::objects::XMLDataParser_obj::_helpNode->x)),(::hxDragonBones::objects::XMLDataParser_obj::_helpFrameData->node->y + (progress * ::hxDragonBones::objects::XMLDataParser_obj::_helpNode->y)),(::hxDragonBones::objects::XMLDataParser_obj::_helpFrameData->node->skewX + (progress * ::hxDragonBones::objects::XMLDataParser_obj::_helpNode->skewX)),(::hxDragonBones::objects::XMLDataParser_obj::_helpFrameData->node->skewY + (progress * ::hxDragonBones::objects::XMLDataParser_obj::_helpNode->skewY)),(::hxDragonBones::objects::XMLDataParser_obj::_helpFrameData->node->scaleX + (progress * ::hxDragonBones::objects::XMLDataParser_obj::_helpNode->scaleX)),(::hxDragonBones::objects::XMLDataParser_obj::_helpFrameData->node->scaleY + (progress * ::hxDragonBones::objects::XMLDataParser_obj::_helpNode->scaleY)),(::hxDragonBones::objects::XMLDataParser_obj::_helpFrameData->node->pivotX + (progress * ::hxDragonBones::objects::XMLDataParser_obj::_helpNode->pivotX)),(::hxDragonBones::objects::XMLDataParser_obj::_helpFrameData->node->pivotY + (progress * ::hxDragonBones::objects::XMLDataParser_obj::_helpNode->pivotY)),null());
					HX_STACK_LINE(338)
					{
						HX_STACK_LINE(338)
						::hxDragonBones::objects::Node bone = frameData->node;		HX_STACK_VAR(bone,"bone");
						::hxDragonBones::objects::Node parent = ::hxDragonBones::objects::XMLDataParser_obj::_helpNode;		HX_STACK_VAR(parent,"parent");
						HX_STACK_LINE(338)
						{
							HX_STACK_LINE(338)
							::native::geom::Matrix resultMatrix = ::hxDragonBones::utils::TransformUtils_obj::_helpMatrix;		HX_STACK_VAR(resultMatrix,"resultMatrix");
							HX_STACK_LINE(338)
							resultMatrix->identity();
							HX_STACK_LINE(338)
							resultMatrix->rotate(parent->skewX);
							HX_STACK_LINE(338)
							resultMatrix->scale(parent->scaleX,parent->scaleY);
							HX_STACK_LINE(338)
							resultMatrix->translate(parent->x,parent->y);
						}
						HX_STACK_LINE(338)
						::hxDragonBones::utils::TransformUtils_obj::_helpPoint->x = bone->x;
						HX_STACK_LINE(338)
						::hxDragonBones::utils::TransformUtils_obj::_helpPoint->y = bone->y;
						HX_STACK_LINE(338)
						::hxDragonBones::utils::TransformUtils_obj::_helpMatrix->invert();
						HX_STACK_LINE(338)
						::hxDragonBones::utils::TransformUtils_obj::_helpPoint = ::hxDragonBones::utils::TransformUtils_obj::_helpMatrix->transformPoint(::hxDragonBones::utils::TransformUtils_obj::_helpPoint);
						HX_STACK_LINE(338)
						bone->x = ::hxDragonBones::utils::TransformUtils_obj::_helpPoint->x;
						HX_STACK_LINE(338)
						bone->y = ::hxDragonBones::utils::TransformUtils_obj::_helpPoint->y;
						HX_STACK_LINE(338)
						hx::SubEq(bone->skewX,parent->skewX);
						HX_STACK_LINE(338)
						hx::SubEq(bone->skewY,parent->skewY);
					}
				}
				HX_STACK_LINE(340)
				hx::AddEq(totalDuration,::Std_obj::parseInt(frameXML->get(HX_CSTRING("dr"))));
				HX_STACK_LINE(342)
				hx::SubEq(frameData->node->x,boneData->node->x);
				HX_STACK_LINE(343)
				hx::SubEq(frameData->node->y,boneData->node->y);
				HX_STACK_LINE(344)
				hx::SubEq(frameData->node->skewX,boneData->node->skewX);
				HX_STACK_LINE(345)
				hx::SubEq(frameData->node->skewY,boneData->node->skewY);
				HX_STACK_LINE(346)
				hx::SubEq(frameData->node->scaleX,boneData->node->scaleX);
				HX_STACK_LINE(347)
				hx::SubEq(frameData->node->scaleY,boneData->node->scaleY);
				HX_STACK_LINE(348)
				hx::SubEq(frameData->node->pivotX,boneData->node->pivotX);
				HX_STACK_LINE(349)
				hx::SubEq(frameData->node->pivotY,boneData->node->pivotY);
				HX_STACK_LINE(350)
				hx::SubEq(frameData->node->z,boneData->node->z);
				HX_STACK_LINE(352)
				(j)++;
			}
;
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(XMLDataParser_obj,parseMovementBoneData,(void))

Void XMLDataParser_obj::parseMovementFrameData( ::Xml movementFrameXml,::hxDragonBones::objects::MovementFrameData movementFrameData){
{
		HX_STACK_PUSH("XMLDataParser::parseMovementFrameData","hxDragonBones/objects/XMLDataParser.hx",356);
		HX_STACK_ARG(movementFrameXml,"movementFrameXml");
		HX_STACK_ARG(movementFrameData,"movementFrameData");
		HX_STACK_LINE(356)
		movementFrameData->setValues((Float(::Std_obj::parseFloat(movementFrameXml->get(HX_CSTRING("dr")))) / Float(::hxDragonBones::objects::XMLDataParser_obj::_curSkeletonData->frameRate)),movementFrameXml->get(HX_CSTRING("mov")),movementFrameXml->get(HX_CSTRING("evt")),movementFrameXml->get(HX_CSTRING("sd")));
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(XMLDataParser_obj,parseMovementFrameData,(void))

Void XMLDataParser_obj::parseFrameData( ::Xml frameXml,::hxDragonBones::objects::FrameData frameData){
{
		HX_STACK_PUSH("XMLDataParser::parseFrameData","hxDragonBones/objects/XMLDataParser.hx",365);
		HX_STACK_ARG(frameXml,"frameXml");
		HX_STACK_ARG(frameData,"frameData");
		HX_STACK_LINE(366)
		{
			HX_STACK_LINE(366)
			::hxDragonBones::objects::Node node = frameData->node;		HX_STACK_VAR(node,"node");
			HX_STACK_LINE(366)
			node->x = ::Std_obj::parseFloat(frameXml->get(HX_CSTRING("x")));
			HX_STACK_LINE(366)
			node->y = ::Std_obj::parseFloat(frameXml->get(HX_CSTRING("y")));
			HX_STACK_LINE(366)
			node->skewX = (::Std_obj::parseFloat(frameXml->get(HX_CSTRING("kX"))) * ((Float(::Math_obj::PI) / Float((int)180))));
			HX_STACK_LINE(366)
			node->skewY = (::Std_obj::parseFloat(frameXml->get(HX_CSTRING("kY"))) * ((Float(::Math_obj::PI) / Float((int)180))));
			HX_STACK_LINE(366)
			node->scaleX = ::Std_obj::parseFloat(frameXml->get(HX_CSTRING("cX")));
			HX_STACK_LINE(366)
			node->scaleY = ::Std_obj::parseFloat(frameXml->get(HX_CSTRING("cY")));
			HX_STACK_LINE(366)
			node->pivotX = ::Std_obj::parseFloat(frameXml->get(HX_CSTRING("pX")));
			HX_STACK_LINE(366)
			node->pivotY = ::Std_obj::parseFloat(frameXml->get(HX_CSTRING("pY")));
			HX_STACK_LINE(366)
			node->z = ::Std_obj::parseFloat(frameXml->get(HX_CSTRING("z")));
		}
		HX_STACK_LINE(367)
		if (((::hxDragonBones::objects::XMLDataParser_obj::_curSkeletonData != null()))){
			HX_STACK_LINE(368)
			::Xml colorTransformXML = frameXml->elementsNamed(HX_CSTRING("colorTransform"))->__Field(HX_CSTRING("next"),true)();		HX_STACK_VAR(colorTransformXML,"colorTransformXML");
			HX_STACK_LINE(369)
			if (((colorTransformXML != null()))){
				HX_STACK_LINE(370)
				::native::geom::ColorTransform colorTransform = frameData->colorTransform;		HX_STACK_VAR(colorTransform,"colorTransform");
				HX_STACK_LINE(370)
				colorTransform->alphaOffset = ::Std_obj::parseInt(colorTransformXML->get(HX_CSTRING("a")));
				HX_STACK_LINE(370)
				colorTransform->redOffset = ::Std_obj::parseInt(colorTransformXML->get(HX_CSTRING("r")));
				HX_STACK_LINE(370)
				colorTransform->greenOffset = ::Std_obj::parseInt(colorTransformXML->get(HX_CSTRING("g")));
				HX_STACK_LINE(370)
				colorTransform->blueOffset = ::Std_obj::parseInt(colorTransformXML->get(HX_CSTRING("b")));
				HX_STACK_LINE(370)
				colorTransform->alphaMultiplier = (::Std_obj::parseInt(colorTransformXML->get(HX_CSTRING("aM"))) * 0.01);
				HX_STACK_LINE(370)
				colorTransform->redMultiplier = (::Std_obj::parseInt(colorTransformXML->get(HX_CSTRING("rM"))) * 0.01);
				HX_STACK_LINE(370)
				colorTransform->greenMultiplier = (::Std_obj::parseInt(colorTransformXML->get(HX_CSTRING("gM"))) * 0.01);
				HX_STACK_LINE(370)
				colorTransform->blueMultiplier = (::Std_obj::parseInt(colorTransformXML->get(HX_CSTRING("bM"))) * 0.01);
			}
			HX_STACK_LINE(372)
			frameData->duration = (Float(::Std_obj::parseInt(frameXml->get(HX_CSTRING("dr")))) / Float(::hxDragonBones::objects::XMLDataParser_obj::_curSkeletonData->frameRate));
			HX_STACK_LINE(373)
			frameData->tweenEasing = ::Std_obj::parseFloat(frameXml->get(HX_CSTRING("twE")));
			HX_STACK_LINE(374)
			frameData->tweenRotate = ::Std_obj::parseInt(frameXml->get(HX_CSTRING("twR")));
			HX_STACK_LINE(375)
			frameData->displayIndex = ::Std_obj::parseInt(frameXml->get(HX_CSTRING("dI")));
			HX_STACK_LINE(376)
			frameData->movement = frameXml->get(HX_CSTRING("mov"));
			HX_STACK_LINE(377)
			frameData->event = frameXml->get(HX_CSTRING("evt"));
			HX_STACK_LINE(378)
			frameData->sound = frameXml->get(HX_CSTRING("sd"));
			HX_STACK_LINE(379)
			frameData->soundEffect = frameXml->get(HX_CSTRING("sdE"));
			HX_STACK_LINE(381)
			::String visible = frameXml->get(HX_CSTRING("visible"));		HX_STACK_VAR(visible,"visible");
			HX_STACK_LINE(382)
			frameData->visible = (bool((bool((visible == HX_CSTRING("1"))) || bool((visible == HX_CSTRING(""))))) || bool((visible == null())));
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(XMLDataParser_obj,parseFrameData,(void))

Void XMLDataParser_obj::parseNode( ::Xml xml,::hxDragonBones::objects::Node node){
{
		HX_STACK_PUSH("XMLDataParser::parseNode","hxDragonBones/objects/XMLDataParser.hx",386);
		HX_STACK_ARG(xml,"xml");
		HX_STACK_ARG(node,"node");
		HX_STACK_LINE(387)
		node->x = ::Std_obj::parseFloat(xml->get(HX_CSTRING("x")));
		HX_STACK_LINE(388)
		node->y = ::Std_obj::parseFloat(xml->get(HX_CSTRING("y")));
		HX_STACK_LINE(389)
		node->skewX = (::Std_obj::parseFloat(xml->get(HX_CSTRING("kX"))) * ((Float(::Math_obj::PI) / Float((int)180))));
		HX_STACK_LINE(390)
		node->skewY = (::Std_obj::parseFloat(xml->get(HX_CSTRING("kY"))) * ((Float(::Math_obj::PI) / Float((int)180))));
		HX_STACK_LINE(391)
		node->scaleX = ::Std_obj::parseFloat(xml->get(HX_CSTRING("cX")));
		HX_STACK_LINE(392)
		node->scaleY = ::Std_obj::parseFloat(xml->get(HX_CSTRING("cY")));
		HX_STACK_LINE(393)
		node->pivotX = ::Std_obj::parseFloat(xml->get(HX_CSTRING("pX")));
		HX_STACK_LINE(394)
		node->pivotY = ::Std_obj::parseFloat(xml->get(HX_CSTRING("pY")));
		HX_STACK_LINE(395)
		node->z = ::Std_obj::parseFloat(xml->get(HX_CSTRING("z")));
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(XMLDataParser_obj,parseNode,(void))

Void XMLDataParser_obj::parseColorTransform( ::Xml xml,::native::geom::ColorTransform colorTransform){
{
		HX_STACK_PUSH("XMLDataParser::parseColorTransform","hxDragonBones/objects/XMLDataParser.hx",398);
		HX_STACK_ARG(xml,"xml");
		HX_STACK_ARG(colorTransform,"colorTransform");
		HX_STACK_LINE(399)
		colorTransform->alphaOffset = ::Std_obj::parseInt(xml->get(HX_CSTRING("a")));
		HX_STACK_LINE(400)
		colorTransform->redOffset = ::Std_obj::parseInt(xml->get(HX_CSTRING("r")));
		HX_STACK_LINE(401)
		colorTransform->greenOffset = ::Std_obj::parseInt(xml->get(HX_CSTRING("g")));
		HX_STACK_LINE(402)
		colorTransform->blueOffset = ::Std_obj::parseInt(xml->get(HX_CSTRING("b")));
		HX_STACK_LINE(403)
		colorTransform->alphaMultiplier = (::Std_obj::parseInt(xml->get(HX_CSTRING("aM"))) * 0.01);
		HX_STACK_LINE(404)
		colorTransform->redMultiplier = (::Std_obj::parseInt(xml->get(HX_CSTRING("rM"))) * 0.01);
		HX_STACK_LINE(405)
		colorTransform->greenMultiplier = (::Std_obj::parseInt(xml->get(HX_CSTRING("gM"))) * 0.01);
		HX_STACK_LINE(406)
		colorTransform->blueMultiplier = (::Std_obj::parseInt(xml->get(HX_CSTRING("bM"))) * 0.01);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(XMLDataParser_obj,parseColorTransform,(void))


XMLDataParser_obj::XMLDataParser_obj()
{
}

void XMLDataParser_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(XMLDataParser);
	HX_MARK_END_CLASS();
}

void XMLDataParser_obj::__Visit(HX_VISIT_PARAMS)
{
}

Dynamic XMLDataParser_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"HALF_PI") ) { return HALF_PI; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"_helpNode") ) { return _helpNode; }
		if (HX_FIELD_EQ(inName,"parseNode") ) { return parseNode_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"compressData") ) { return compressData_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"parseBoneData") ) { return parseBoneData_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"_helpFrameData") ) { return _helpFrameData; }
		if (HX_FIELD_EQ(inName,"decompressData") ) { return decompressData_dyn(); }
		if (HX_FIELD_EQ(inName,"parseArmatures") ) { return parseArmatures_dyn(); }
		if (HX_FIELD_EQ(inName,"parseFrameData") ) { return parseFrameData_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"ANGLE_TO_RADIAN") ) { return ANGLE_TO_RADIAN; }
		if (HX_FIELD_EQ(inName,"parseAnimations") ) { return parseAnimations_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"_curSkeletonData") ) { return _curSkeletonData; }
		if (HX_FIELD_EQ(inName,"parseDisplayData") ) { return parseDisplayData_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"parseSkeletonData") ) { return parseSkeletonData_dyn(); }
		if (HX_FIELD_EQ(inName,"parseArmatureData") ) { return parseArmatureData_dyn(); }
		if (HX_FIELD_EQ(inName,"parseMovementData") ) { return parseMovementData_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"parseAnimationData") ) { return parseAnimationData_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"parseColorTransform") ) { return parseColorTransform_dyn(); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"parseMovementBoneData") ) { return parseMovementBoneData_dyn(); }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"parseMovementFrameData") ) { return parseMovementFrameData_dyn(); }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"checkSkeletonXMLVersion") ) { return checkSkeletonXMLVersion_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic XMLDataParser_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"HALF_PI") ) { HALF_PI=inValue.Cast< Float >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"_helpNode") ) { _helpNode=inValue.Cast< ::hxDragonBones::objects::Node >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"_helpFrameData") ) { _helpFrameData=inValue.Cast< ::hxDragonBones::objects::FrameData >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"ANGLE_TO_RADIAN") ) { ANGLE_TO_RADIAN=inValue.Cast< Float >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"_curSkeletonData") ) { _curSkeletonData=inValue.Cast< ::hxDragonBones::objects::SkeletonData >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void XMLDataParser_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("ANGLE_TO_RADIAN"),
	HX_CSTRING("HALF_PI"),
	HX_CSTRING("_curSkeletonData"),
	HX_CSTRING("_helpNode"),
	HX_CSTRING("_helpFrameData"),
	HX_CSTRING("checkSkeletonXMLVersion"),
	HX_CSTRING("compressData"),
	HX_CSTRING("decompressData"),
	HX_CSTRING("parseSkeletonData"),
	HX_CSTRING("parseArmatures"),
	HX_CSTRING("parseArmatureData"),
	HX_CSTRING("parseBoneData"),
	HX_CSTRING("parseDisplayData"),
	HX_CSTRING("parseAnimations"),
	HX_CSTRING("parseAnimationData"),
	HX_CSTRING("parseMovementData"),
	HX_CSTRING("parseMovementBoneData"),
	HX_CSTRING("parseMovementFrameData"),
	HX_CSTRING("parseFrameData"),
	HX_CSTRING("parseNode"),
	HX_CSTRING("parseColorTransform"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(XMLDataParser_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(XMLDataParser_obj::ANGLE_TO_RADIAN,"ANGLE_TO_RADIAN");
	HX_MARK_MEMBER_NAME(XMLDataParser_obj::HALF_PI,"HALF_PI");
	HX_MARK_MEMBER_NAME(XMLDataParser_obj::_curSkeletonData,"_curSkeletonData");
	HX_MARK_MEMBER_NAME(XMLDataParser_obj::_helpNode,"_helpNode");
	HX_MARK_MEMBER_NAME(XMLDataParser_obj::_helpFrameData,"_helpFrameData");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(XMLDataParser_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(XMLDataParser_obj::ANGLE_TO_RADIAN,"ANGLE_TO_RADIAN");
	HX_VISIT_MEMBER_NAME(XMLDataParser_obj::HALF_PI,"HALF_PI");
	HX_VISIT_MEMBER_NAME(XMLDataParser_obj::_curSkeletonData,"_curSkeletonData");
	HX_VISIT_MEMBER_NAME(XMLDataParser_obj::_helpNode,"_helpNode");
	HX_VISIT_MEMBER_NAME(XMLDataParser_obj::_helpFrameData,"_helpFrameData");
};

Class XMLDataParser_obj::__mClass;

void XMLDataParser_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("hxDragonBones.objects.XMLDataParser"), hx::TCanCast< XMLDataParser_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void XMLDataParser_obj::__boot()
{
	ANGLE_TO_RADIAN= (Float(::Math_obj::PI) / Float((int)180));
	HALF_PI= (::Math_obj::PI * 0.5);
	_helpNode= ::hxDragonBones::objects::Node_obj::__new();
	_helpFrameData= ::hxDragonBones::objects::FrameData_obj::__new();
}

} // end namespace hxDragonBones
} // end namespace objects
