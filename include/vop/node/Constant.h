#pragma once

#include "vop/Node.h"

#include <hdiop/Variable.h>

namespace vop
{
namespace node
{

class Constant : public Node
{
public:
    Constant()
    {
        m_exports = {
            {{ hdiop::VarType::Any, "Value" }}
        };
    }

    virtual hdiop::Variable Eval(size_t idx) const override {
        return m_value;
    }

    void SetValue(float v);

private:
    hdiop::Variable m_value;

    RTTR_ENABLE(Node)

}; // Constant

}
}