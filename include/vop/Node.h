#pragma once

#include "vop/VariableType.h"

#include <hdiop/Node.h>

#include <SM_Vector.h>

namespace vop
{

class Node : public hdiop::Node<VariableType>
{
public:
    Node(size_t build_in_count = 0);

    virtual sm::vec3 Calc(size_t idx) const = 0;

    virtual void AddInputPorts(size_t num) {}

    RTTR_ENABLE(hdiop::Node<VariableType>)

}; // Node

}