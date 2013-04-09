#ifndef INCLUDED_hxDragonBones_utils_ConstValues
#define INCLUDED_hxDragonBones_utils_ConstValues

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(hxDragonBones,utils,ConstValues)
namespace hxDragonBones{
namespace utils{


class ConstValues_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef ConstValues_obj OBJ_;
		ConstValues_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< ConstValues_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~ConstValues_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("ConstValues"); }

		static ::String VERSION_14; /* REM */ 
		static ::String VERSION; /* REM */ 
		static ::String SKELETON; /* REM */ 
		static ::String ARMATURES; /* REM */ 
		static ::String ARMATURE; /* REM */ 
		static ::String BONE; /* REM */ 
		static ::String DISPLAY; /* REM */ 
		static ::String ANIMATIONS; /* REM */ 
		static ::String ANIMATION; /* REM */ 
		static ::String MOVEMENT; /* REM */ 
		static ::String FRAME; /* REM */ 
		static ::String COLOR_TRANSFORM; /* REM */ 
		static ::String TEXTURE_ATLAS; /* REM */ 
		static ::String SUB_TEXTURE; /* REM */ 
		static ::String AT; /* REM */ 
		static ::String A_VERSION; /* REM */ 
		static ::String A_FRAME_RATE; /* REM */ 
		static ::String A_NAME; /* REM */ 
		static ::String A_DURATION; /* REM */ 
		static ::String A_DURATION_TO; /* REM */ 
		static ::String A_DURATION_TWEEN; /* REM */ 
		static ::String A_LOOP; /* REM */ 
		static ::String A_MOVEMENT_SCALE; /* REM */ 
		static ::String A_MOVEMENT_DELAY; /* REM */ 
		static ::String A_PARENT; /* REM */ 
		static ::String A_SKEW_X; /* REM */ 
		static ::String A_SKEW_Y; /* REM */ 
		static ::String A_SCALE_X; /* REM */ 
		static ::String A_SCALE_Y; /* REM */ 
		static ::String A_Z; /* REM */ 
		static ::String A_DISPLAY_INDEX; /* REM */ 
		static ::String A_EVENT; /* REM */ 
		static ::String A_SOUND; /* REM */ 
		static ::String A_SOUND_EFFECT; /* REM */ 
		static ::String A_TWEEN_EASING; /* REM */ 
		static ::String A_TWEEN_ROTATE; /* REM */ 
		static ::String A_IS_ARMATURE; /* REM */ 
		static ::String A_MOVEMENT; /* REM */ 
		static ::String A_VISIBLE; /* REM */ 
		static ::String A_X; /* REM */ 
		static ::String A_Y; /* REM */ 
		static ::String A_WIDTH; /* REM */ 
		static ::String A_HEIGHT; /* REM */ 
		static ::String A_PIVOT_X; /* REM */ 
		static ::String A_PIVOT_Y; /* REM */ 
		static ::String A_ALPHA; /* REM */ 
		static ::String A_RED; /* REM */ 
		static ::String A_GREEN; /* REM */ 
		static ::String A_BLUE; /* REM */ 
		static ::String A_ALPHA_MULTIPLIER; /* REM */ 
		static ::String A_RED_MULTIPLIER; /* REM */ 
		static ::String A_GREEN_MULTIPLIER; /* REM */ 
		static ::String A_BLUE_MULTIPLIER; /* REM */ 
		static ::String V_SOUND_LEFT; /* REM */ 
		static ::String V_SOUND_RIGHT; /* REM */ 
		static ::String V_SOUND_LEFT_TO_RIGHT; /* REM */ 
		static ::String V_SOUND_RIGHT_TO_LEFT; /* REM */ 
		static ::String V_SOUND_FADE_IN; /* REM */ 
		static ::String V_SOUND_FADE_OUT; /* REM */ 
};

} // end namespace hxDragonBones
} // end namespace utils

#endif /* INCLUDED_hxDragonBones_utils_ConstValues */ 
