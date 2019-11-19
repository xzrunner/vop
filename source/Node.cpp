#include "vop/Node.h"

RTTR_REGISTRATION
{

rttr::registration::class_<hdiop::NodePort<vop::VariableType>>("sop::Node::Port")
	.property("var", &hdiop::NodePort<vop::VariableType>::var)
;

rttr::registration::class_<vop::Node>("vop::Node")
	.method("GetImports", &vop::Node::GetImports)
	.method("GetExports", &vop::Node::GetExports)
;

}

namespace vop
{

Node::Node(size_t build_in_count)
{
}

}