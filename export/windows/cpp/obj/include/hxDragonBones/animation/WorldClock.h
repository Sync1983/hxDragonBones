#ifndef INCLUDED_hxDragonBones_animation_WorldClock
#define INCLUDED_hxDragonBones_animation_WorldClock

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <hxDragonBones/animation/IAnimatable.h>
HX_DECLARE_CLASS2(hxDragonBones,animation,IAnimatable)
HX_DECLARE_CLASS2(hxDragonBones,animation,WorldClock)
namespace hxDragonBones{
namespace animation{


class WorldClock_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef WorldClock_obj OBJ_;
		WorldClock_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< WorldClock_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~WorldClock_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		inline operator ::hxDragonBones::animation::IAnimatable_obj *()
			{ return new ::hxDragonBones::animation::IAnimatable_delegate_< WorldClock_obj >(this); }
		hx::Object *__ToInterface(const type_info &inType);
		::String __ToString() const { return HX_CSTRING("WorldClock"); }

		virtual Void advanceTime( hx::Null< Float >  passedTime);
		Dynamic advanceTime_dyn();

		virtual Void clear( );
		Dynamic clear_dyn();

		virtual Void remove( ::hxDragonBones::animation::IAnimatable animatable);
		Dynamic remove_dyn();

		virtual Void add( ::hxDragonBones::animation::IAnimatable animatable);
		Dynamic add_dyn();

		virtual bool has( ::hxDragonBones::animation::IAnimatable animatable);
		Dynamic has_dyn();

		Float _time; /* REM */ 
		Array< ::hxDragonBones::animation::IAnimatable > _animatableList; /* REM */ 
		virtual Float set_timeScale( Float value);
		Dynamic set_timeScale_dyn();

		Float timeScale; /* REM */ 
		Float time; /* REM */ 
		static ::hxDragonBones::animation::WorldClock instance; /* REM */ 
		static ::hxDragonBones::animation::WorldClock get_instance( );
		static Dynamic get_instance_dyn();

};

} // end namespace hxDragonBones
} // end namespace animation

#endif /* INCLUDED_hxDragonBones_animation_WorldClock */ 
