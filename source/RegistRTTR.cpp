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