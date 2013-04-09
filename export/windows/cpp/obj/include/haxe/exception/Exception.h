#ifndef INCLUDED_haxe_exception_Exception
#define INCLUDED_haxe_exception_Exception

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(haxe,StackItem)
HX_DECLARE_CLASS2(haxe,exception,Exception)
namespace haxe{
namespace exception{


class Exception_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Exception_obj OBJ_;
		Exception_obj();
		Void __construct(::String message,::haxe::exception::Exception innerException,Dynamic numberOfStackTraceShifts);

	public:
		static hx::ObjectPtr< Exception_obj > __new(::String message,::haxe::exception::Exception innerException,Dynamic numberOfStackTraceShifts);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Exception_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Exception"); }

		virtual ::String toString( );
		Dynamic toString_dyn();

		virtual ::haxe::exception::Exception getBaseException( );
		Dynamic getBaseException_dyn();

		virtual Void generateStackTrace( int numberOfStackTraceShifts);
		Dynamic generateStackTrace_dyn();

		Array< ::haxe::StackItem > stackTraceArray; /* REM */ 
		Dynamic stackTrace; /* REM */ 
		::String message; /* REM */ 
		::haxe::exception::Exception innerException; /* REM */ 
		::haxe::exception::Exception baseException; /* REM */ 
};

} // end namespace haxe
} // end namespace exception

#endif /* INCLUDED_haxe_exception_Exception */ 
