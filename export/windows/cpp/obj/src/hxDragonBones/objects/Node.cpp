#include <hxcpp.h>

#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_hxDragonBones_objects_Node
#include <hxDragonBones/objects/Node.h>
#endif
namespace hxDragonBones{
namespace objects{

Void Node_obj::__construct()
{
HX_STACK_PUSH("Node::new","hxDragonBones/objects/Node.hx",9);
{
	HX_STACK_LINE(9)
	this->setValues(null(),null(),null(),null(),null(),null(),null(),null(),null());
}
;
	return null();
}

Node_obj::~Node_obj() { }

Dynamic Node_obj::__CreateEmpty() { return  new Node_obj; }
hx::ObjectPtr< Node_obj > Node_obj::__new()
{  hx::ObjectPtr< Node_obj > result = new Node_obj();
	result->__construct();
	return result;}

Dynamic Node_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Node_obj > result = new Node_obj();
	result->__construct();
	return result;}

Void Node_obj::copyFrom( ::hxDragonBones::objects::Node node){
{
		HX_STACK_PUSH("Node::copyFrom","hxDragonBones/objects/Node.hx",46);
		HX_STACK_THIS(this);
		HX_STACK_ARG(node,"node");
		HX_STACK_LINE(47)
		this->x = node->x;
		HX_STACK_LINE(48)
		this->y = node->y;
		HX_STACK_LINE(49)
		this->z = node->z;
		HX_STACK_LINE(50)
		this->scaleX = node->scaleX;
		HX_STACK_LINE(51)
		this->scaleY = node->scaleY;
		HX_STACK_LINE(52)
		this->skewX = node->skewX;
		HX_STACK_LINE(53)
		this->skewY = node->skewY;
		HX_STACK_LINE(54)
		this->pivotX = node->pivotX;
		HX_STACK_LINE(55)
		this->pivotY = node->pivotY;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Node_obj,copyFrom,(void))

Void Node_obj::setValues( hx::Null< Float >  __o_x,hx::Null< Float >  __o_y,hx::Null< Float >  __o_skewX,hx::Null< Float >  __o_skewY,hx::Null< Float >  __o_scaleX,hx::Null< Float >  __o_scaleY,hx::Null< Float >  __o_pivotX,hx::Null< Float >  __o_pivotY,hx::Null< int >  __o_z){
Float x = __o_x.Default(0);
Float y = __o_y.Default(0);
Float skewX = __o_skewX.Default(0);
Float skewY = __o_skewY.Default(0);
Float scaleX = __o_scaleX.Default(0);
Float scaleY = __o_scaleY.Default(0);
Float pivotX = __o_pivotX.Default(0);
Float pivotY = __o_pivotY.Default(0);
int z = __o_z.Default(0);
	HX_STACK_PUSH("Node::setValues","hxDragonBones/objects/Node.hx",34);
	HX_STACK_THIS(this);
	HX_STACK_ARG(x,"x");
	HX_STACK_ARG(y,"y");
	HX_STACK_ARG(skewX,"skewX");
	HX_STACK_ARG(skewY,"skewY");
	HX_STACK_ARG(scaleX,"scaleX");
	HX_STACK_ARG(scaleY,"scaleY");
	HX_STACK_ARG(pivotX,"pivotX");
	HX_STACK_ARG(pivotY,"pivotY");
	HX_STACK_ARG(z,"z");
{
		HX_STACK_LINE(35)
		this->x = (  ((!(::Math_obj::isNaN(x)))) ? Float(x) : Float((int)0) );
		HX_STACK_LINE(36)
		this->y = (  ((!(::Math_obj::isNaN(y)))) ? Float(y) : Float((int)0) );
		HX_STACK_LINE(37)
		this->z = z;
		HX_STACK_LINE(38)
		this->skewX = (  ((!(::Math_obj::isNaN(skewX)))) ? Float(skewX) : Float((int)0) );
		HX_STACK_LINE(39)
		this->skewY = (  ((!(::Math_obj::isNaN(skewY)))) ? Float(skewY) : Float((int)0) );
		HX_STACK_LINE(40)
		this->scaleX = (  ((!(::Math_obj::isNaN(scaleX)))) ? Float(scaleX) : Float((int)0) );
		HX_STACK_LINE(41)
		this->scaleY = (  ((!(::Math_obj::isNaN(scaleY)))) ? Float(scaleY) : Float((int)0) );
		HX_STACK_LINE(42)
		this->pivotX = (  ((!(::Math_obj::isNaN(pivotX)))) ? Float(pivotX) : Float((int)0) );
		HX_STACK_LINE(43)
		this->pivotY = (  ((!(::Math_obj::isNaN(pivotY)))) ? Float(pivotY) : Float((int)0) );
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC9(Node_obj,setValues,(void))

Float Node_obj::set_rotation( Float value){
	HX_STACK_PUSH("Node::set_rotation","hxDragonBones/objects/Node.hx",28);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(29)
	this->skewX = value;
	HX_STACK_LINE(30)
	this->skewY = value;
	HX_STACK_LINE(31)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(Node_obj,set_rotation,return )

Float Node_obj::get_rotation( ){
	HX_STACK_PUSH("Node::get_rotation","hxDragonBones/objects/Node.hx",24);
	HX_STACK_THIS(this);
	HX_STACK_LINE(24)
	return this->skewX;
}


HX_DEFINE_DYNAMIC_FUNC0(Node_obj,get_rotation,return )


Node_obj::Node_obj()
{
}

void Node_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Node);
	HX_MARK_MEMBER_NAME(rotation,"rotation");
	HX_MARK_MEMBER_NAME(pivotY,"pivotY");
	HX_MARK_MEMBER_NAME(pivotX,"pivotX");
	HX_MARK_MEMBER_NAME(skewY,"skewY");
	HX_MARK_MEMBER_NAME(skewX,"skewX");
	HX_MARK_MEMBER_NAME(scaleY,"scaleY");
	HX_MARK_MEMBER_NAME(scaleX,"scaleX");
	HX_MARK_MEMBER_NAME(z,"z");
	HX_MARK_MEMBER_NAME(y,"y");
	HX_MARK_MEMBER_NAME(x,"x");
	HX_MARK_END_CLASS();
}

void Node_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(rotation,"rotation");
	HX_VISIT_MEMBER_NAME(pivotY,"pivotY");
	HX_VISIT_MEMBER_NAME(pivotX,"pivotX");
	HX_VISIT_MEMBER_NAME(skewY,"skewY");
	HX_VISIT_MEMBER_NAME(skewX,"skewX");
	HX_VISIT_MEMBER_NAME(scaleY,"scaleY");
	HX_VISIT_MEMBER_NAME(scaleX,"scaleX");
	HX_VISIT_MEMBER_NAME(z,"z");
	HX_VISIT_MEMBER_NAME(y,"y");
	HX_VISIT_MEMBER_NAME(x,"x");
}

Dynamic Node_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"z") ) { return z; }
		if (HX_FIELD_EQ(inName,"y") ) { return y; }
		if (HX_FIELD_EQ(inName,"x") ) { return x; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"skewY") ) { return skewY; }
		if (HX_FIELD_EQ(inName,"skewX") ) { return skewX; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"pivotY") ) { return pivotY; }
		if (HX_FIELD_EQ(inName,"pivotX") ) { return pivotX; }
		if (HX_FIELD_EQ(inName,"scaleY") ) { return scaleY; }
		if (HX_FIELD_EQ(inName,"scaleX") ) { return scaleX; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"copyFrom") ) { return copyFrom_dyn(); }
		if (HX_FIELD_EQ(inName,"rotation") ) { return inCallProp ? get_rotation() : rotation; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"setValues") ) { return setValues_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"set_rotation") ) { return set_rotation_dyn(); }
		if (HX_FIELD_EQ(inName,"get_rotation") ) { return get_rotation_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Node_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"z") ) { z=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"y") ) { y=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"x") ) { x=inValue.Cast< Float >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"skewY") ) { skewY=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"skewX") ) { skewX=inValue.Cast< Float >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"pivotY") ) { pivotY=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"pivotX") ) { pivotX=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"scaleY") ) { scaleY=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"scaleX") ) { scaleX=inValue.Cast< Float >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"rotation") ) { if (inCallProp) return set_rotation(inValue);rotation=inValue.Cast< Float >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Node_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("rotation"));
	outFields->push(HX_CSTRING("pivotY"));
	outFields->push(HX_CSTRING("pivotX"));
	outFields->push(HX_CSTRING("skewY"));
	outFields->push(HX_CSTRING("skewX"));
	outFields->push(HX_CSTRING("scaleY"));
	outFields->push(HX_CSTRING("scaleX"));
	outFields->push(HX_CSTRING("z"));
	outFields->push(HX_CSTRING("y"));
	outFields->push(HX_CSTRING("x"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("copyFrom"),
	HX_CSTRING("setValues"),
	HX_CSTRING("set_rotation"),
	HX_CSTRING("get_rotation"),
	HX_CSTRING("rotation"),
	HX_CSTRING("pivotY"),
	HX_CSTRING("pivotX"),
	HX_CSTRING("skewY"),
	HX_CSTRING("skewX"),
	HX_CSTRING("scaleY"),
	HX_CSTRING("scaleX"),
	HX_CSTRING("z"),
	HX_CSTRING("y"),
	HX_CSTRING("x"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Node_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Node_obj::__mClass,"__mClass");
};

Class Node_obj::__mClass;

void Node_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("hxDragonBones.objects.Node"), hx::TCanCast< Node_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Node_obj::__boot()
{
}

} // end namespace hxDragonBones
} // end namespace objects
