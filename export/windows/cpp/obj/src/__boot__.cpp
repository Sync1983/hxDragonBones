#include <hxcpp.h>

#include <sys/io/FileSeek.h>
#include <sys/io/FileOutput.h>
#include <sys/io/FileInput.h>
#include <sys/io/File.h>
#include <sys/FileSystem.h>
#include <sys/_FileSystem/FileKind.h>
#include <nme/installer/Assets.h>
#include <nme/display/FPS.h>
#include <nme/VectorHelper.h>
#include <nme/ObjectHash.h>
#include <nme/Lib.h>
#include <native/utils/WeakRef.h>
#include <native/utils/Timer.h>
#include <native/utils/Endian.h>
#include <native/utils/CompressionAlgorithm.h>
#include <native/utils/ByteArray.h>
#include <native/utils/IDataInput.h>
#include <native/utils/IMemoryRange.h>
#include <native/ui/Keyboard.h>
#include <native/text/TextFormat.h>
#include <native/text/TextFieldType.h>
#include <native/text/TextFieldAutoSize.h>
#include <native/text/TextField.h>
#include <native/text/FontType.h>
#include <native/text/FontStyle.h>
#include <native/text/Font.h>
#include <native/text/AntiAliasType.h>
#include <native/system/System.h>
#include <native/net/URLVariables.h>
#include <native/net/URLRequestMethod.h>
#include <native/net/URLRequestHeader.h>
#include <native/net/URLRequest.h>
#include <native/net/URLLoaderDataFormat.h>
#include <native/media/SoundTransform.h>
#include <native/media/SoundLoaderContext.h>
#include <native/media/SoundChannel.h>
#include <native/media/Sound.h>
#include <native/media/ID3Info.h>
#include <native/geom/Transform.h>
#include <native/filters/BitmapFilter.h>
#include <native/events/TimerEvent.h>
#include <native/events/SampleDataEvent.h>
#include <native/events/ProgressEvent.h>
#include <native/events/KeyboardEvent.h>
#include <native/events/JoystickEvent.h>
#include <native/events/IOErrorEvent.h>
#include <native/events/HTTPStatusEvent.h>
#include <native/events/FocusEvent.h>
#include <native/events/EventPhase.h>
#include <native/events/Listener.h>
#include <native/events/ErrorEvent.h>
#include <native/events/TextEvent.h>
#include <native/errors/RangeError.h>
#include <native/errors/EOFError.h>
#include <native/errors/ArgumentError.h>
#include <native/errors/Error.h>
#include <native/display/TriangleCulling.h>
#include <native/display/Tilesheet.h>
#include <native/display/StageScaleMode.h>
#include <native/display/StageQuality.h>
#include <native/display/StageDisplayState.h>
#include <native/display/StageAlign.h>
#include <native/display/TouchInfo.h>
#include <native/display/SpreadMethod.h>
#include <native/display/Shape.h>
#include <native/display/PixelSnapping.h>
#include <native/display/MovieClip.h>
#include <native/display/ManagedStage.h>
#include <native/display/Stage.h>
#include <native/events/TouchEvent.h>
#include <native/events/MouseEvent.h>
#include <native/display/LoaderInfo.h>
#include <native/net/URLLoader.h>
#include <native/display/Loader.h>
#include <native/display/LineScaleMode.h>
#include <native/display/JointStyle.h>
#include <native/display/InterpolationMethod.h>
#include <native/display/IGraphicsData.h>
#include <native/display/GraphicsPathWinding.h>
#include <native/display/Graphics.h>
#include <native/display/GradientType.h>
#include <native/display/CapsStyle.h>
#include <native/display/BlendMode.h>
#include <native/display/OptimizedPerlin.h>
#include <native/display/BitmapData.h>
#include <native/display/Bitmap.h>
#include <native/Lib.h>
#include <hxDragonBones/utils/TransformUtils.h>
#include <hxDragonBones/utils/DisposeUtils.h>
#include <hxDragonBones/utils/ConstValues.h>
#include <hxDragonBones/utils/BytesType.h>
#include <hxDragonBones/textures/SubTextureData.h>
#include <native/geom/Rectangle.h>
#include <hxDragonBones/textures/NativeTextureAtlas.h>
#include <hxDragonBones/textures/ITextureAtlas.h>
#include <hxDragonBones/objects/XMLDataParser.h>
#include <native/geom/ColorTransform.h>
#include <hxDragonBones/objects/SkeletonData.h>
#include <hxDragonBones/objects/Node.h>
#include <hxDragonBones/objects/MovementFrameData.h>
#include <hxDragonBones/objects/MovementData.h>
#include <hxDragonBones/objects/MovementBoneData.h>
#include <hxDragonBones/objects/FrameData.h>
#include <hxDragonBones/objects/DisplayData.h>
#include <hxDragonBones/objects/DecompressedData.h>
#include <hxDragonBones/objects/DataList.h>
#include <hxDragonBones/objects/BoneData.h>
#include <hxDragonBones/objects/ArmatureData.h>
#include <hxDragonBones/objects/AnimationData.h>
#include <hxDragonBones/factorys/BaseFactory.h>
#include <native/geom/Matrix.h>
#include <hxDragonBones/events/SoundEvent.h>
#include <hxDragonBones/events/FrameEvent.h>
#include <hxDragonBones/events/ArmatureEvent.h>
#include <hxDragonBones/events/AnimationEvent.h>
#include <native/events/Event.h>
#include <hxDragonBones/display/NativeDisplayBridge.h>
#include <hxDragonBones/display/IDisplayBridge.h>
#include <hxDragonBones/animation/WorldClock.h>
#include <hxDragonBones/animation/Tween.h>
#include <hxDragonBones/animation/Animation.h>
#include <hxDragonBones/events/SoundEventManager.h>
#include <hxDragonBones/Bone.h>
#include <native/geom/Point.h>
#include <hxDragonBones/Armature.h>
#include <hxDragonBones/animation/IAnimatable.h>
#include <hxDragonBones/utils/IDisposable.h>
#include <hsl/haxe/Signal.h>
#include <hsl/haxe/_DirectSignaler/PropagationStatus.h>
#include <hsl/haxe/_DirectSignaler/AdvancedBond.h>
#include <hsl/haxe/_DirectSignaler/NiladicBond.h>
#include <hsl/haxe/_DirectSignaler/RegularBond.h>
#include <hsl/haxe/_DirectSignaler/SentinelBond.h>
#include <hsl/haxe/_DirectSignaler/LinkedBond.h>
#include <hsl/haxe/DirectSignaler.h>
#include <hsl/haxe/Signaler.h>
#include <hsl/haxe/Bond.h>
#include <haxe/remoting/FlashJsConnection.h>
#include <haxe/io/Error.h>
#include <haxe/io/Eof.h>
#include <haxe/io/BytesBuffer.h>
#include <haxe/exception/ArgumentNullException.h>
#include <haxe/exception/Exception.h>
#include <haxe/Unserializer.h>
#include <haxe/TypeTools.h>
#include <haxe/Timer.h>
#include <haxe/Stack.h>
#include <haxe/StackItem.h>
#include <haxe/Log.h>
#include <format/display/MovieClip.h>
#include <format/display/FrameLabel.h>
#include <cpp/zip/Uncompress.h>
#include <cpp/zip/Flush.h>
#include <cpp/zip/Compress.h>
#include <cpp/vm/Gc.h>
#include <cpp/rtti/FieldNumericIntegerLookup.h>
#include <com/fermmmtools/debug/Colors.h>
#include <com/fermmmtools/debug/Stats.h>
#include <Xml.h>
#include <XmlType.h>
#include <Type.h>
#include <ValueType.h>
#include <Sys.h>
#include <StringTools.h>
#include <StringBuf.h>
#include <Reflect.h>
#include <Main.h>
#include <native/display/Sprite.h>
#include <native/display/DisplayObjectContainer.h>
#include <native/display/InteractiveObject.h>
#include <native/display/DisplayObject.h>
#include <Std.h>
#include <sys/io/_Process/Stdout.h>
#include <haxe/io/Input.h>
#include <haxe/io/Bytes.h>
#include <sys/io/_Process/Stdin.h>
#include <haxe/io/Output.h>
#include <sys/io/Process.h>
#include <cpp/Lib.h>
#include <native/Loader.h>
#include <native/display/IBitmapDrawable.h>
#include <native/events/EventDispatcher.h>
#include <native/events/IEventDispatcher.h>
#include <List.h>
#include <Lambda.h>
#include <IntIter.h>
#include <IntHash.h>
#include <Hash.h>
#include <Date.h>
#include <ApplicationMain.h>

void __boot_all()
{
hx::RegisterResources( hx::GetResources() );
::sys::io::FileSeek_obj::__register();
::sys::io::FileOutput_obj::__register();
::sys::io::FileInput_obj::__register();
::sys::io::File_obj::__register();
::sys::FileSystem_obj::__register();
::sys::_FileSystem::FileKind_obj::__register();
::nme::installer::Assets_obj::__register();
::nme::display::FPS_obj::__register();
::nme::VectorHelper_obj::__register();
::nme::ObjectHash_obj::__register();
::nme::Lib_obj::__register();
::native::utils::WeakRef_obj::__register();
::native::utils::Timer_obj::__register();
::native::utils::Endian_obj::__register();
::native::utils::CompressionAlgorithm_obj::__register();
::native::utils::ByteArray_obj::__register();
::native::utils::IDataInput_obj::__register();
::native::utils::IMemoryRange_obj::__register();
::native::ui::Keyboard_obj::__register();
::native::text::TextFormat_obj::__register();
::native::text::TextFieldType_obj::__register();
::native::text::TextFieldAutoSize_obj::__register();
::native::text::TextField_obj::__register();
::native::text::FontType_obj::__register();
::native::text::FontStyle_obj::__register();
::native::text::Font_obj::__register();
::native::text::AntiAliasType_obj::__register();
::native::system::System_obj::__register();
::native::net::URLVariables_obj::__register();
::native::net::URLRequestMethod_obj::__register();
::native::net::URLRequestHeader_obj::__register();
::native::net::URLRequest_obj::__register();
::native::net::URLLoaderDataFormat_obj::__register();
::native::media::SoundTransform_obj::__register();
::native::media::SoundLoaderContext_obj::__register();
::native::media::SoundChannel_obj::__register();
::native::media::Sound_obj::__register();
::native::media::ID3Info_obj::__register();
::native::geom::Transform_obj::__register();
::native::filters::BitmapFilter_obj::__register();
::native::events::TimerEvent_obj::__register();
::native::events::SampleDataEvent_obj::__register();
::native::events::ProgressEvent_obj::__register();
::native::events::KeyboardEvent_obj::__register();
::native::events::JoystickEvent_obj::__register();
::native::events::IOErrorEvent_obj::__register();
::native::events::HTTPStatusEvent_obj::__register();
::native::events::FocusEvent_obj::__register();
::native::events::EventPhase_obj::__register();
::native::events::Listener_obj::__register();
::native::events::ErrorEvent_obj::__register();
::native::events::TextEvent_obj::__register();
::native::errors::RangeError_obj::__register();
::native::errors::EOFError_obj::__register();
::native::errors::ArgumentError_obj::__register();
::native::errors::Error_obj::__register();
::native::display::TriangleCulling_obj::__register();
::native::display::Tilesheet_obj::__register();
::native::display::StageScaleMode_obj::__register();
::native::display::StageQuality_obj::__register();
::native::display::StageDisplayState_obj::__register();
::native::display::StageAlign_obj::__register();
::native::display::TouchInfo_obj::__register();
::native::display::SpreadMethod_obj::__register();
::native::display::Shape_obj::__register();
::native::display::PixelSnapping_obj::__register();
::native::display::MovieClip_obj::__register();
::native::display::ManagedStage_obj::__register();
::native::display::Stage_obj::__register();
::native::events::TouchEvent_obj::__register();
::native::events::MouseEvent_obj::__register();
::native::display::LoaderInfo_obj::__register();
::native::net::URLLoader_obj::__register();
::native::display::Loader_obj::__register();
::native::display::LineScaleMode_obj::__register();
::native::display::JointStyle_obj::__register();
::native::display::InterpolationMethod_obj::__register();
::native::display::IGraphicsData_obj::__register();
::native::display::GraphicsPathWinding_obj::__register();
::native::display::Graphics_obj::__register();
::native::display::GradientType_obj::__register();
::native::display::CapsStyle_obj::__register();
::native::display::BlendMode_obj::__register();
::native::display::OptimizedPerlin_obj::__register();
::native::display::BitmapData_obj::__register();
::native::display::Bitmap_obj::__register();
::native::Lib_obj::__register();
::hxDragonBones::utils::TransformUtils_obj::__register();
::hxDragonBones::utils::DisposeUtils_obj::__register();
::hxDragonBones::utils::ConstValues_obj::__register();
::hxDragonBones::utils::BytesType_obj::__register();
::hxDragonBones::textures::SubTextureData_obj::__register();
::native::geom::Rectangle_obj::__register();
::hxDragonBones::textures::NativeTextureAtlas_obj::__register();
::hxDragonBones::textures::ITextureAtlas_obj::__register();
::hxDragonBones::objects::XMLDataParser_obj::__register();
::native::geom::ColorTransform_obj::__register();
::hxDragonBones::objects::SkeletonData_obj::__register();
::hxDragonBones::objects::Node_obj::__register();
::hxDragonBones::objects::MovementFrameData_obj::__register();
::hxDragonBones::objects::MovementData_obj::__register();
::hxDragonBones::objects::MovementBoneData_obj::__register();
::hxDragonBones::objects::FrameData_obj::__register();
::hxDragonBones::objects::DisplayData_obj::__register();
::hxDragonBones::objects::DecompressedData_obj::__register();
::hxDragonBones::objects::DataList_obj::__register();
::hxDragonBones::objects::BoneData_obj::__register();
::hxDragonBones::objects::ArmatureData_obj::__register();
::hxDragonBones::objects::AnimationData_obj::__register();
::hxDragonBones::factorys::BaseFactory_obj::__register();
::native::geom::Matrix_obj::__register();
::hxDragonBones::events::SoundEvent_obj::__register();
::hxDragonBones::events::FrameEvent_obj::__register();
::hxDragonBones::events::ArmatureEvent_obj::__register();
::hxDragonBones::events::AnimationEvent_obj::__register();
::native::events::Event_obj::__register();
::hxDragonBones::display::NativeDisplayBridge_obj::__register();
::hxDragonBones::display::IDisplayBridge_obj::__register();
::hxDragonBones::animation::WorldClock_obj::__register();
::hxDragonBones::animation::Tween_obj::__register();
::hxDragonBones::animation::Animation_obj::__register();
::hxDragonBones::events::SoundEventManager_obj::__register();
::hxDragonBones::Bone_obj::__register();
::native::geom::Point_obj::__register();
::hxDragonBones::Armature_obj::__register();
::hxDragonBones::animation::IAnimatable_obj::__register();
::hxDragonBones::utils::IDisposable_obj::__register();
::hsl::haxe::Signal_obj::__register();
::hsl::haxe::_DirectSignaler::PropagationStatus_obj::__register();
::hsl::haxe::_DirectSignaler::AdvancedBond_obj::__register();
::hsl::haxe::_DirectSignaler::NiladicBond_obj::__register();
::hsl::haxe::_DirectSignaler::RegularBond_obj::__register();
::hsl::haxe::_DirectSignaler::SentinelBond_obj::__register();
::hsl::haxe::_DirectSignaler::LinkedBond_obj::__register();
::hsl::haxe::DirectSignaler_obj::__register();
::hsl::haxe::Signaler_obj::__register();
::hsl::haxe::Bond_obj::__register();
::haxe::remoting::FlashJsConnection_obj::__register();
::haxe::io::Error_obj::__register();
::haxe::io::Eof_obj::__register();
::haxe::io::BytesBuffer_obj::__register();
::haxe::exception::ArgumentNullException_obj::__register();
::haxe::exception::Exception_obj::__register();
::haxe::Unserializer_obj::__register();
::haxe::TypeTools_obj::__register();
::haxe::Timer_obj::__register();
::haxe::Stack_obj::__register();
::haxe::StackItem_obj::__register();
::haxe::Log_obj::__register();
::format::display::MovieClip_obj::__register();
::format::display::FrameLabel_obj::__register();
::cpp::zip::Uncompress_obj::__register();
::cpp::zip::Flush_obj::__register();
::cpp::zip::Compress_obj::__register();
::cpp::vm::Gc_obj::__register();
::cpp::rtti::FieldNumericIntegerLookup_obj::__register();
::com::fermmmtools::debug::Colors_obj::__register();
::com::fermmmtools::debug::Stats_obj::__register();
::Xml_obj::__register();
::XmlType_obj::__register();
::Type_obj::__register();
::ValueType_obj::__register();
::Sys_obj::__register();
::StringTools_obj::__register();
::StringBuf_obj::__register();
::Reflect_obj::__register();
::Main_obj::__register();
::native::display::Sprite_obj::__register();
::native::display::DisplayObjectContainer_obj::__register();
::native::display::InteractiveObject_obj::__register();
::native::display::DisplayObject_obj::__register();
::Std_obj::__register();
::sys::io::_Process::Stdout_obj::__register();
::haxe::io::Input_obj::__register();
::haxe::io::Bytes_obj::__register();
::sys::io::_Process::Stdin_obj::__register();
::haxe::io::Output_obj::__register();
::sys::io::Process_obj::__register();
::cpp::Lib_obj::__register();
::native::Loader_obj::__register();
::native::display::IBitmapDrawable_obj::__register();
::native::events::EventDispatcher_obj::__register();
::native::events::IEventDispatcher_obj::__register();
::List_obj::__register();
::Lambda_obj::__register();
::IntIter_obj::__register();
::IntHash_obj::__register();
::Hash_obj::__register();
::Date_obj::__register();
::ApplicationMain_obj::__register();
::Xml_obj::__init__();
::native::utils::ByteArray_obj::__init__();
::cpp::Lib_obj::__boot();
::Xml_obj::__boot();
::cpp::rtti::FieldNumericIntegerLookup_obj::__boot();
::cpp::vm::Gc_obj::__boot();
::cpp::zip::Compress_obj::__boot();
::cpp::zip::Flush_obj::__boot();
::cpp::zip::Uncompress_obj::__boot();
::haxe::Log_obj::__boot();
::ApplicationMain_obj::__boot();
::Date_obj::__boot();
::Hash_obj::__boot();
::IntHash_obj::__boot();
::IntIter_obj::__boot();
::Lambda_obj::__boot();
::List_obj::__boot();
::native::events::IEventDispatcher_obj::__boot();
::native::events::EventDispatcher_obj::__boot();
::native::display::IBitmapDrawable_obj::__boot();
::native::Loader_obj::__boot();
::sys::io::Process_obj::__boot();
::haxe::io::Output_obj::__boot();
::sys::io::_Process::Stdin_obj::__boot();
::haxe::io::Bytes_obj::__boot();
::haxe::io::Input_obj::__boot();
::sys::io::_Process::Stdout_obj::__boot();
::Std_obj::__boot();
::native::display::DisplayObject_obj::__boot();
::native::display::InteractiveObject_obj::__boot();
::native::display::DisplayObjectContainer_obj::__boot();
::native::display::Sprite_obj::__boot();
::Main_obj::__boot();
::Reflect_obj::__boot();
::StringBuf_obj::__boot();
::StringTools_obj::__boot();
::Sys_obj::__boot();
::ValueType_obj::__boot();
::Type_obj::__boot();
::XmlType_obj::__boot();
::com::fermmmtools::debug::Stats_obj::__boot();
::com::fermmmtools::debug::Colors_obj::__boot();
::format::display::FrameLabel_obj::__boot();
::format::display::MovieClip_obj::__boot();
::haxe::StackItem_obj::__boot();
::haxe::Stack_obj::__boot();
::haxe::Timer_obj::__boot();
::haxe::TypeTools_obj::__boot();
::haxe::Unserializer_obj::__boot();
::haxe::exception::Exception_obj::__boot();
::haxe::exception::ArgumentNullException_obj::__boot();
::haxe::io::BytesBuffer_obj::__boot();
::haxe::io::Eof_obj::__boot();
::haxe::io::Error_obj::__boot();
::haxe::remoting::FlashJsConnection_obj::__boot();
::hsl::haxe::Bond_obj::__boot();
::hsl::haxe::Signaler_obj::__boot();
::hsl::haxe::DirectSignaler_obj::__boot();
::hsl::haxe::_DirectSignaler::LinkedBond_obj::__boot();
::hsl::haxe::_DirectSignaler::SentinelBond_obj::__boot();
::hsl::haxe::_DirectSignaler::RegularBond_obj::__boot();
::hsl::haxe::_DirectSignaler::NiladicBond_obj::__boot();
::hsl::haxe::_DirectSignaler::AdvancedBond_obj::__boot();
::hsl::haxe::_DirectSignaler::PropagationStatus_obj::__boot();
::hsl::haxe::Signal_obj::__boot();
::hxDragonBones::utils::IDisposable_obj::__boot();
::hxDragonBones::animation::IAnimatable_obj::__boot();
::hxDragonBones::Armature_obj::__boot();
::native::geom::Point_obj::__boot();
::hxDragonBones::Bone_obj::__boot();
::hxDragonBones::events::SoundEventManager_obj::__boot();
::hxDragonBones::animation::Animation_obj::__boot();
::hxDragonBones::animation::Tween_obj::__boot();
::hxDragonBones::animation::WorldClock_obj::__boot();
::hxDragonBones::display::IDisplayBridge_obj::__boot();
::hxDragonBones::display::NativeDisplayBridge_obj::__boot();
::native::events::Event_obj::__boot();
::hxDragonBones::events::AnimationEvent_obj::__boot();
::hxDragonBones::events::ArmatureEvent_obj::__boot();
::hxDragonBones::events::FrameEvent_obj::__boot();
::hxDragonBones::events::SoundEvent_obj::__boot();
::native::geom::Matrix_obj::__boot();
::hxDragonBones::factorys::BaseFactory_obj::__boot();
::hxDragonBones::objects::AnimationData_obj::__boot();
::hxDragonBones::objects::ArmatureData_obj::__boot();
::hxDragonBones::objects::BoneData_obj::__boot();
::hxDragonBones::objects::DataList_obj::__boot();
::hxDragonBones::objects::DecompressedData_obj::__boot();
::hxDragonBones::objects::DisplayData_obj::__boot();
::hxDragonBones::objects::FrameData_obj::__boot();
::hxDragonBones::objects::MovementBoneData_obj::__boot();
::hxDragonBones::objects::MovementData_obj::__boot();
::hxDragonBones::objects::MovementFrameData_obj::__boot();
::hxDragonBones::objects::Node_obj::__boot();
::hxDragonBones::objects::SkeletonData_obj::__boot();
::native::geom::ColorTransform_obj::__boot();
::hxDragonBones::objects::XMLDataParser_obj::__boot();
::hxDragonBones::textures::ITextureAtlas_obj::__boot();
::hxDragonBones::textures::NativeTextureAtlas_obj::__boot();
::native::geom::Rectangle_obj::__boot();
::hxDragonBones::textures::SubTextureData_obj::__boot();
::hxDragonBones::utils::BytesType_obj::__boot();
::hxDragonBones::utils::ConstValues_obj::__boot();
::hxDragonBones::utils::DisposeUtils_obj::__boot();
::hxDragonBones::utils::TransformUtils_obj::__boot();
::native::Lib_obj::__boot();
::native::display::Bitmap_obj::__boot();
::native::display::BitmapData_obj::__boot();
::native::display::OptimizedPerlin_obj::__boot();
::native::display::BlendMode_obj::__boot();
::native::display::CapsStyle_obj::__boot();
::native::display::GradientType_obj::__boot();
::native::display::Graphics_obj::__boot();
::native::display::GraphicsPathWinding_obj::__boot();
::native::display::IGraphicsData_obj::__boot();
::native::display::InterpolationMethod_obj::__boot();
::native::display::JointStyle_obj::__boot();
::native::display::LineScaleMode_obj::__boot();
::native::display::Loader_obj::__boot();
::native::net::URLLoader_obj::__boot();
::native::display::LoaderInfo_obj::__boot();
::native::events::MouseEvent_obj::__boot();
::native::events::TouchEvent_obj::__boot();
::native::display::Stage_obj::__boot();
::native::display::ManagedStage_obj::__boot();
::native::display::MovieClip_obj::__boot();
::native::display::PixelSnapping_obj::__boot();
::native::display::Shape_obj::__boot();
::native::display::SpreadMethod_obj::__boot();
::native::display::TouchInfo_obj::__boot();
::native::display::StageAlign_obj::__boot();
::native::display::StageDisplayState_obj::__boot();
::native::display::StageQuality_obj::__boot();
::native::display::StageScaleMode_obj::__boot();
::native::display::Tilesheet_obj::__boot();
::native::display::TriangleCulling_obj::__boot();
::native::errors::Error_obj::__boot();
::native::errors::ArgumentError_obj::__boot();
::native::errors::EOFError_obj::__boot();
::native::errors::RangeError_obj::__boot();
::native::events::TextEvent_obj::__boot();
::native::events::ErrorEvent_obj::__boot();
::native::events::Listener_obj::__boot();
::native::events::EventPhase_obj::__boot();
::native::events::FocusEvent_obj::__boot();
::native::events::HTTPStatusEvent_obj::__boot();
::native::events::IOErrorEvent_obj::__boot();
::native::events::JoystickEvent_obj::__boot();
::native::events::KeyboardEvent_obj::__boot();
::native::events::ProgressEvent_obj::__boot();
::native::events::SampleDataEvent_obj::__boot();
::native::events::TimerEvent_obj::__boot();
::native::filters::BitmapFilter_obj::__boot();
::native::geom::Transform_obj::__boot();
::native::media::ID3Info_obj::__boot();
::native::media::Sound_obj::__boot();
::native::media::SoundChannel_obj::__boot();
::native::media::SoundLoaderContext_obj::__boot();
::native::media::SoundTransform_obj::__boot();
::native::net::URLLoaderDataFormat_obj::__boot();
::native::net::URLRequest_obj::__boot();
::native::net::URLRequestHeader_obj::__boot();
::native::net::URLRequestMethod_obj::__boot();
::native::net::URLVariables_obj::__boot();
::native::system::System_obj::__boot();
::native::text::AntiAliasType_obj::__boot();
::native::text::Font_obj::__boot();
::native::text::FontStyle_obj::__boot();
::native::text::FontType_obj::__boot();
::native::text::TextField_obj::__boot();
::native::text::TextFieldAutoSize_obj::__boot();
::native::text::TextFieldType_obj::__boot();
::native::text::TextFormat_obj::__boot();
::native::ui::Keyboard_obj::__boot();
::native::utils::IMemoryRange_obj::__boot();
::native::utils::IDataInput_obj::__boot();
::native::utils::ByteArray_obj::__boot();
::native::utils::CompressionAlgorithm_obj::__boot();
::native::utils::Endian_obj::__boot();
::native::utils::Timer_obj::__boot();
::native::utils::WeakRef_obj::__boot();
::nme::Lib_obj::__boot();
::nme::ObjectHash_obj::__boot();
::nme::VectorHelper_obj::__boot();
::nme::display::FPS_obj::__boot();
::nme::installer::Assets_obj::__boot();
::sys::_FileSystem::FileKind_obj::__boot();
::sys::FileSystem_obj::__boot();
::sys::io::File_obj::__boot();
::sys::io::FileInput_obj::__boot();
::sys::io::FileOutput_obj::__boot();
::sys::io::FileSeek_obj::__boot();
}

