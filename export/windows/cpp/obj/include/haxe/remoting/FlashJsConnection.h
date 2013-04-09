#ifndef INCLUDED_haxe_remoting_FlashJsConnection
#define INCLUDED_haxe_remoting_FlashJsConnection

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(haxe,remoting,FlashJsConnection)
namespace haxe{
namespace remoting{


class FlashJsConnection_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef FlashJsConnection_obj OBJ_;
		FlashJsConnection_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< FlashJsConnection_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~FlashJsConnection_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("FlashJsConnection"); }

};

} // end namespace haxe
} // end namespace remoting

#endif /* INCLUDED_haxe_remoting_FlashJsConnection */ 
