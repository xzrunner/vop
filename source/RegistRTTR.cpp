// globals
#include "vop/node/GeoGlobalParams.h"
#include "vop/node/GeoOutputVars.h"
// math
#include "vop/node/Add.h"
#include "vop/node/Multiply.h"
// utility
#include "vop/node/Constant.h"
#include "vop/node/Subnetwork.h"

#include <rttr/registration>

#define REGIST_NODE_TYPE(type, name)                           \
	rttr::registration::class_<vop::node::type>("vop::"#name)  \
		.constructor<>()                                       \
	;

RTTR_REGISTRATION
{

// base
rttr::registration::class_<hdiop::Node<hdiop::VarType>::Port>("sop::Node::Port")
	.property("var", &hdiop::Node<hdiop::VarType>::Port::var)
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
REGIST_NODE_TYPE(Constant, constant)
REGIST_NODE_TYPE(Subnetwork, subnetwork)

}

namespace vop
{

void regist_rttr()
{
}

}