#pragma once

#include <dag/Variable.h>

namespace vop
{

class Node;

class NodeHelper
{
public:
    static dag::Variable EvalInputNode(const Node& node, size_t idx);

}; // NodeHelper

}