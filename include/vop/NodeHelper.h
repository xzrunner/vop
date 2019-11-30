#pragma once

#include <hdiop/Variable.h>

namespace vop
{

class Node;

class NodeHelper
{
public:
    static hdiop::Variable EvalInputNode(const Node& node, size_t idx);

}; // NodeHelper

}