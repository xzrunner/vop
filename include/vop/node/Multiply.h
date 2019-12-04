#pragma once

#include "vop/Node.h"

#include <dag/Variable.h>

namespace vop
{
namespace node
{

class Multiply : public Node
{
public:
    Multiply()
    {
        m_imports = {
            {{ dag::VarType::Any, "input1" }},
            {{ dag::VarType::Any, "input2" }}
        };
        m_exports = {
            {{ dag::VarType::Any, "product" }}
        };
    }

    virtual dag::Variable Eval(size_t idx) const override;

    RTTR_ENABLE(Node)

}; // Constant

}
}