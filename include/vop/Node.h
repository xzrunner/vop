#pragma once

#include <hdiop/Node.h>
#include <hdiop/Variable.h>

#include <SM_Vector.h>

namespace vop
{

class Node : public hdiop::Node<hdiop::VarType>
{
public:
    Node(size_t build_in_count = 0);

    virtual hdiop::Variable Eval(size_t idx) const = 0;

    virtual void AddInputPorts(size_t num) {}

    RTTR_ENABLE(hdiop::Node<hdiop::VarType>)

}; // Node

}