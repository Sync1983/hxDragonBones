#ifndef INCLUDED_hxDragonBones_animation_Animation
#define INCLUDED_hxDragonBones_animation_Animation

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <hxDragonBones/utils/IDisposable.h>
HX_DECLARE_CLASS1(hxDragonBones,Armature)
HX_DECLARE_CLASS2(hxDragonBones,animation,Animation)
HX_DECLARE_CLASS2(hxDragonBones,animation,IAnimatable)
HX_DECLARE_CLASS2(hxDragonBones,events,SoundEventManager)
HX_DECLARE_CLASS2(hxDragonBones,objects,AnimationData)
HX_DECLARE_CLASS2(hxDragonBones,objects,MovementData)
HX_DECLARE_CLASS2(hxDragonBones,objects,MovementFrameData)
HX_DECLARE_CLASS2(hxDragonBones,utils,IDisposable)
HX_DECLARE_CLASS2(native,events,EventDispatcher)
HX_DECLARE_CLASS2(native,events,IEventDispatcher)
namespace hxDragonBones{
namespace animation{


class Animation_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Animation_obj OBJ_;
		Animation_obj();
		Void __construct(::hxDragonBones::Armature armature);

	public:
		static hx::ObjectPtr< Animation_obj > __new(::hxDragonBones::Armature armature);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Animation_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		inline operator ::hxDragonBones::utils::IDisposable_obj *()
			{ return new ::hxDragonBones::utils::IDisposable_delegate_< Animation_obj >(this); }
		hx::Object *__ToInterface(const type_info &inType);
		::String __ToString() const { return HX_CSTRING("Animation"); }

		virtual Void arriveFrameData( ::hxDragonBones::objects::MovementFrameData movementFrameData);
		Dynamic arriveFrameData_dyn();

		virtual Void updateFrameData( Float progress);
		Dynamic updateFrameData_dyn();

		virtual Void advanceTime( Float passedTime);
		Dynamic advanceTime_dyn();

		virtual Void stop( );
		Dynamic stop_dyn();

		virtual Void play( );
		Dynamic play_dyn();

		virtual Void gotoAndPlay( ::String movementID,hx::Null< Float >  tweenTime,hx::Null< Float >  duration,Dynamic loop);
		Dynamic gotoAndPlay_dyn();

		virtual Void dispose( );
		Dynamic dispose_dyn();

		virtual Array< ::String > get_movementList( );
		Dynamic get_movementList_dyn();

		virtual Float set_timeScale( Float value);
		Dynamic set_timeScale_dyn();

		virtual bool get_isPause( );
		Dynamic get_isPause_dyn();

		virtual bool get_isComplete( );
		Dynamic get_isComplete_dyn();

		virtual bool get_isPlaying( );
		Dynamic get_isPlaying_dyn();

		virtual ::hxDragonBones::objects::AnimationData set_animationData( ::hxDragonBones::objects::AnimationData value);
		Dynamic set_animationData_dyn();

		::hxDragonBones::Armature _armature; /* REM */ 
		bool _breakFrameWhile; /* REM */ 
		int _loop; /* REM */ 
		int _nextFrameDataID; /* REM */ 
		Float _nextFrameDataTimeEdge; /* REM */ 
		Float _rawDuration; /* REM */ 
		Float _duration; /* REM */ 
		int _playType; /* REM */ 
		::hxDragonBones::objects::MovementData movementData; /* REM */ 
		Array< ::String > movementList; /* REM */ 
		::String movementID; /* REM */ 
		Float timeScale; /* REM */ 
		bool isPause; /* REM */ 
		bool isComplete; /* REM */ 
		bool isPlaying; /* REM */ 
		Float totalTime; /* REM */ 
		Float currentTime; /* REM */ 
		::hxDragonBones::objects::AnimationData animationData; /* REM */ 
		bool tweenEnabled; /* REM */ 
		static int SINGLE; /* REM */ 
		static int LIST_START; /* REM */ 
		static int LOOP_START; /* REM */ 
		static int LIST; /* REM */ 
		static int LOOP; /* REM */ 
		static ::hxDragonBones::events::SoundEventManager _soundManager; /* REM */ 
};

} // end namespace hxDragonBones
} // end namespace animation

#endif /* INCLUDED_hxDragonBones_animation_Animation */ 
