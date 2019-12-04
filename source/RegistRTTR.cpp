// globals
#include "vop/node/GeoGlobalParams.h"
#include "vop/node/GeoOutputVars.h"
// math
#include "vop/node/Add.h"
#include "vop/node/Multiply.h"
// utility
#include "vop/node/Compare.h"
#include "vop/node/Constant.h"
#include "vop/node/Subnetwork.h"
// vector
#include "vop/node/GetVectorComponent.h"
#include "vop/node/SetVectorComponent.h"

#include "vop/ComponentType.h"

#include <rttr/registration>

#define REGIST_NODE_TYPE(type, name)                           \
	rttr::registration::class_<vop::node::type>("vop::"#name)  \
		.constructor<>()                                       \
	;

#define REGIST_ENUM_ITEM(type, name, label) \
    rttr::value(name, type),                \
    rttr::metadata(type, label)             \

RTTR_REGISTRATION
{

// base
rttr::registration::class_<dag::Node<dag::VarType>::Port>("vop::Node::Port")
	.property("var", &dag::Node<dag::VarType>::Port::var)
;

rttr::registration::class_<vop::Node>("vop::Node")
	.method("GetImports", &vop::Node::GetImports)
	.method("GetExports", &vop::Node::GetExports)
;

// creation
REGIST_NODE_TYPE(GeoGlobalParams, geo_global_params)
REGIST_NODE_TYPE(GeoOutputVars, geo_output_vars)

// math
REGIST_NODE_TYPE(Add, add)
REGIST_NODE_TYPE(Multiply, multiply)

// utility
rttr::registration::class_<vop::node::Compare>("vop::compare")
.constructor<>()
#define PARM_FILEPATH "vop/node/Compare.parm.h"
#define PARM_NODE_CLASS vop::node::Compare
#include <dag/rttr_prop_gen.h>
#undef PARM_NODE_CLASS
#undef PARM_FILEPATH
;
rttr::registration::enumeration<vop::node::Compare::CmpType>("vop_compare_type")
(
    REGIST_ENUM_ITEM(vop::node::Compare::CmpType::Equal,              "equal",                 "Equal (==)"),
    REGIST_ENUM_ITEM(vop::node::Compare::CmpType::LessThan,           "less_than",             "Less Than (<)"),
    REGIST_ENUM_ITEM(vop::node::Compare::CmpType::GreaterThan,        "greater_than",          "Greater Than (>)"),
    REGIST_ENUM_ITEM(vop::node::Compare::CmpType::LessThanOrEqual,    "less_than_or_equal",    "Less Than Or Equal (<=)"),
    REGIST_ENUM_ITEM(vop::node::Compare::CmpType::GreaterThanOrEqual, "greater_than_or_equal", "Greater Than Or Equal (>=)"),
    REGIST_ENUM_ITEM(vop::node::Compare::CmpType::NotEqual,           "not_equal",             "Not Equal (!=)")
);
rttr::registration::class_<vop::node::Constant>("vop::constant")
.constructor<>()
#define PARM_FILEPATH "vop/node/Constant.parm.h"
#define PARM_NODE_CLASS vop::node::Constant
#include <dag/rttr_prop_gen.h>
#undef PARM_NODE_CLASS
#undef PARM_FILEPATH
;
rttr::registration::enumeration<vop::node::Constant::Type>("vop_constant_type")
(
    REGIST_ENUM_ITEM(vop::node::Constant::Type::ConstFloat,   "float",   "Float(float)"),
    REGIST_ENUM_ITEM(vop::node::Constant::Type::ConstInteger, "integer", "Integer(int)"),
    REGIST_ENUM_ITEM(vop::node::Constant::Type::ConstToggle,  "toggle",  "Toggle(int)"),
    REGIST_ENUM_ITEM(vop::node::Constant::Type::ConstAngle,   "angle",   "Angle(float)"),
    REGIST_ENUM_ITEM(vop::node::Constant::Type::ConstFloat2,  "float2",  "2 Floats(vector2)"),
    REGIST_ENUM_ITEM(vop::node::Constant::Type::ConstFloat3,  "float3",  "3 Floats(vector)"),
    REGIST_ENUM_ITEM(vop::node::Constant::Type::ConstFloat4,  "float4",  "4 Floats(vector4)"),
    REGIST_ENUM_ITEM(vop::node::Constant::Type::ConstString,  "string",  "String(string)")
);
REGIST_NODE_TYPE(Subnetwork, subnetwork)

// vector
rttr::registration::enumeration<vop::CompType2>("vop_comp_type2")
(
    REGIST_ENUM_ITEM(vop::CompType2::X, "x", "X"),
    REGIST_ENUM_ITEM(vop::CompType2::Y, "y", "Y")
);
rttr::registration::enumeration<vop::CompType3>("vop_comp_type3")
(
    REGIST_ENUM_ITEM(vop::CompType3::X, "x", "X"),
    REGIST_ENUM_ITEM(vop::CompType3::Y, "y", "Y"),
    REGIST_ENUM_ITEM(vop::CompType3::Z, "z", "Z")
);
rttr::registration::enumeration<vop::CompType4>("vop_comp_type4")
(
    REGIST_ENUM_ITEM(vop::CompType4::X, "x", "X"),
    REGIST_ENUM_ITEM(vop::CompType4::Y, "y", "Y"),
    REGIST_ENUM_ITEM(vop::CompType4::Z, "z", "Z"),
    REGIST_ENUM_ITEM(vop::CompType4::Z, "w", "W")
);
rttr::registration::class_<vop::node::GetVec2Comp>("vop::get_vec2_comp")
.constructor<>()
#define PARM_FILEPATH "vop/node/GetSetVec2Comp.parm.h"
#define PARM_NODE_CLASS vop::node::GetVec2Comp
#include <dag/rttr_prop_gen.h>
#undef PARM_NODE_CLASS
#undef PARM_FILEPATH
;
rttr::registration::class_<vop::node::SetVec2Comp>("vop::set_vec2_comp")
.constructor<>()
#define PARM_FILEPATH "vop/node/GetSetVec2Comp.parm.h"
#define PARM_NODE_CLASS vop::node::SetVec2Comp
#include <dag/rttr_prop_gen.h>
#undef PARM_NODE_CLASS
#undef PARM_FILEPATH
;
rttr::registration::class_<vop::node::GetVec3Comp>("vop::get_vec3_comp")
.constructor<>()
#define PARM_FILEPATH "vop/node/GetSetVec3Comp.parm.h"
#define PARM_NODE_CLASS vop::node::GetVec3Comp
#include <dag/rttr_prop_gen.h>
#undef PARM_NODE_CLASS
#undef PARM_FILEPATH
;
rttr::registration::class_<vop::node::SetVec3Comp>("vop::set_vec3_comp")
.constructor<>()
#define PARM_FILEPATH "vop/node/GetSetVec3Comp.parm.h"
#define PARM_NODE_CLASS vop::node::SetVec3Comp
#include <dag/rttr_prop_gen.h>
#undef PARM_NODE_CLASS
#undef PARM_FILEPATH
;
rttr::registration::class_<vop::node::GetVec4Comp>("vop::get_vec4_comp")
.constructor<>()
#define PARM_FILEPATH "vop/node/GetSetVec4Comp.parm.h"
#define PARM_NODE_CLASS vop::node::GetVec4Comp
#include <dag/rttr_prop_gen.h>
#undef PARM_NODE_CLASS
#undef PARM_FILEPATH
;
rttr::registration::class_<vop::node::SetVec4Comp>("vop::set_vec4_comp")
.constructor<>()
#define PARM_FILEPATH "vop/node/GetSetVec4Comp.parm.h"
#define PARM_NODE_CLASS vop::node::SetVec4Comp
#include <dag/rttr_prop_gen.h>
#undef PARM_NODE_CLASS
#undef PARM_FILEPATH
;

}

namespace vop
{

void regist_rttr()
{
}

}