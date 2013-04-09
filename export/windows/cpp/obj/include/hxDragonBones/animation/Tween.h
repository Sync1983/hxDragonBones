#ifndef INCLUDED_hxDragonBones_animation_Tween
#define INCLUDED_hxDragonBones_animation_Tween

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(hxDragonBones,Bone)
HX_DECLARE_CLASS2(hxDragonBones,animation,Tween)
HX_DECLARE_CLASS2(hxDragonBones,events,SoundEventManager)
HX_DECLARE_CLASS2(hxDragonBones,objects,FrameData)
HX_DECLARE_CLASS2(hxDragonBones,objects,MovementBoneData)
HX_DECLARE_CLASS2(hxDragonBones,objects,Node)
HX_DECLARE_CLASS2(hxDragonBones,utils,IDisposable)
HX_DECLARE_CLASS2(native,events,EventDispatcher)
HX_DECLARE_CLASS2(native,events,IEventDispatcher)
HX_DECLARE_CLASS2(native,geom,ColorTransform)
namespace hxDragonBones{
namespace animation{


class Tween_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Tween_obj OBJ_;
		Tween_obj();
		Void __construct(::hxDragonBones::Bone bone);

	public:
		static hx::ObjectPtr< Tween_obj > __new(::hxDragonBones::Bone bone);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Tween_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Tween"); }

		virtual Float updateFrameData( Float progress,Dynamic activeFrame,Dynamic isList);
		Dynamic updateFrameData_dyn();

		virtual Void arriveFrameData( ::hxDragonBones::objects::FrameData frameData);
		Dynamic arriveFrameData_dyn();

		virtual Void updateBoneDisplayIndex( ::hxDragonBones::objects::FrameData frameData);
		Dynamic updateBoneDisplayIndex_dyn();

		virtual Void setOffset( ::hxDragonBones::objects::Node currentNode,::native::geom::ColorTransform curColorTransform,::hxDragonBones::objects::Node nextNode,::native::geom::ColorTransform nextColorTransform,hx::Null< int >  tweenRotate);
		Dynamic setOffset_dyn();

		virtual Void getLoopListNode( );
		Dynamic getLoopListNode_dyn();

		virtual Void advanceTime( Float progress,int playType);
		Dynamic advanceTime_dyn();

		virtual Void stop( );
		Dynamic stop_dyn();

		virtual Void gotoAndPlay( ::hxDragonBones::objects::MovementBoneData movementBoneData,Float rawDuration,bool loop,Float tweenEasing);
		Dynamic gotoAndPlay_dyn();

		int _loop; /* REM */ 
		int _nextFrameDataID; /* REM */ 
		Float _frameDuration; /* REM */ 
		Float _nextFrameDataTimeEdge; /* REM */ 
		Float _rawDuration; /* REM */ 
		bool _isPause; /* REM */ 
		Float _frameTweenEasing; /* REM */ 
		Float _tweenEasing; /* REM */ 
		::hxDragonBones::objects::FrameData _curFrameData; /* REM */ 
		::native::geom::ColorTransform _offSetColorTransform; /* REM */ 
		::hxDragonBones::objects::Node _offSetNode; /* REM */ 
		::native::geom::ColorTransform _curColorTransform; /* REM */ 
		::hxDragonBones::objects::Node _curNode; /* REM */ 
		::native::geom::ColorTransform _colorTransform; /* REM */ 
		::hxDragonBones::objects::Node _node; /* REM */ 
		::hxDragonBones::objects::MovementBoneData _movementBoneData; /* REM */ 
		::hxDragonBones::Bone _bone; /* REM */ 
		bool differentColorTransform; /* REM */ 
		static Float HALF_PI; /* REM */ 
		static ::hxDragonBones::events::SoundEventManager _soundManager; /* REM */ 
		static Float getEaseValue( Float value,Dynamic easing);
		static Dynamic getEaseValue_dyn();

};

} // end namespace hxDragonBones
} // end namespace animation

#endif /* INCLUDED_hxDragonBones_animation_Tween */ 
