#pragma once

#include <dag/Node.h>
#include <dag/Variable.h>

#include <SM_Vector.h>

namespace vop
{

class Node : public dag::Node<dag::VarType>
{
public:
    Node(size_t build_in_count = 0);

    virtual dag::Variable Eval(size_t idx) const = 0;

    virtual void AddInputPorts(size_t num) {}

    RTTR_ENABLE(dag::Node<dag::VarType>)

}; // Node

}