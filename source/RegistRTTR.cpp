// base
#include "vop/node/Subnetwork.h"
// globals
#include "vop/node/GeoGlobalParams.h"
#include "vop/node/GeoOutputVars.h"

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

REGIST_NODE_TYPE(Subnetwork, subnetwork)

// creation
REGIST_NODE_TYPE(GeoGlobalParams, geo_global_params)
REGIST_NODE_TYPE(GeoOutputVars, geo_output_vars)

}

namespace vop
{

void regist_rttr()
{
}

}