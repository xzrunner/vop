#pragma once

#include "vop/Node.h"

#include <dag/Variable.h>

namespace vop
{
namespace node
{

class Add : public Node
{
public:
    Add()
    {
        m_imports = {
            {{ dag::VarType::Any, "input1" }},
            {{ dag::VarType::Any, "input2" }}
        };
        m_exports = {
            {{ dag::VarType::Any, "sum" }}
        };
    }

    virtual dag::Variable Eval(size_t idx) const override;

    RTTR_ENABLE(Node)

}; // Constant

}
}