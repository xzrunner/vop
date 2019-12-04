#pragma once

#include "vop/Node.h"

#include <dag/Variable.h>

namespace vop
{
namespace node
{

class Constant : public Node
{
public:
    enum class Type
    {
        ConstFloat,
        ConstInteger,
        ConstToggle,
        ConstAngle,
        ConstFloat2,
        ConstFloat3,
        ConstFloat4,
        ConstString,
    };

public:
    Constant()
    {
        m_exports = {
            {{ dag::VarType::Any, "Value" }}
        };
    }

    virtual dag::Variable Eval(size_t idx) const override;

    RTTR_ENABLE(Node)

#define PARM_FILEPATH "vop/node/Constant.parm.h"
#include <dag/node_parms_gen.h>
#undef PARM_FILEPATH

}; // Constant

}
}