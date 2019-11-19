#pragma once

#include "vop/VariableType.h"

#include <hdiop/NodeImpl.h>

#include <SM_Vector.h>

#include <rttr/registration>

namespace vop
{

class Node : public hdiop::NodeImpl<VariableType>
{
public:
    Node(size_t build_in_count = 0);

    virtual sm::vec3 Calc(size_t idx) const = 0;

    virtual void AddInputPorts(size_t num) {}

    RTTR_ENABLE(hdiop::NodeImpl<VariableType>)

}; // Node

}