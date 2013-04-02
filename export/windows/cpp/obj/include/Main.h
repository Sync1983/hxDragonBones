#ifndef INCLUDED_Main
#define INCLUDED_Main

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <native/display/Sprite.h>
HX_DECLARE_CLASS0(Main)
HX_DECLARE_CLASS2(native,display,DisplayObject)
HX_DECLARE_CLASS2(native,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(native,display,IBitmapDrawable)
HX_DECLARE_CLASS2(native,display,InteractiveObject)
HX_DECLARE_CLASS2(native,display,Sprite)
HX_DECLARE_CLASS2(native,events,Event)
HX_DECLARE_CLASS2(native,events,EventDispatcher)
HX_DECLARE_CLASS2(native,events,IEventDispatcher)


class Main_obj : public ::native::display::Sprite_obj{
	public:
		typedef ::native::display::Sprite_obj super;
		typedef Main_obj OBJ_;
		Main_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< Main_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Main_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Main"); }

		virtual Void onStageResize( ::native::events::Event event);
		Dynamic onStageResize_dyn();

		virtual Void onStageDeactivate( ::native::events::Event event);
		Dynamic onStageDeactivate_dyn();

		virtual Void onStageActivate( ::native::events::Event event);
		Dynamic onStageActivate_dyn();

		virtual Void onStageAddedToStage( ::native::events::Event event);
		Dynamic onStageAddedToStage_dyn();

		virtual Void onFactoryComplete( ::native::events::Event event);
		Dynamic onFactoryComplete_dyn();

		virtual Void initialize( );
		Dynamic initialize_dyn();

		virtual Void addListeners( );
		Dynamic addListeners_dyn();

		virtual Void setupStage( );
		Dynamic setupStage_dyn();

		bool _isInitialized; /* REM */ 
};


#endif /* INCLUDED_Main */ 
