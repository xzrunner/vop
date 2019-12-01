#pragma once

#include "vop/Node.h"

#include <hdiop/Variable.h>

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
            {{ hdiop::VarType::Any, "input1" }},
            {{ hdiop::VarType::Any, "input2" }}
        };
        m_exports = {
            {{ hdiop::VarType::Any, "sum" }}
        };
    }

    virtual hdiop::Variable Eval(size_t idx) const override;

    RTTR_ENABLE(Node)

}; // Constant

}
}