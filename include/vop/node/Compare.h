#pragma once

#include "vop/Node.h"

#include <dag/Variable.h>

namespace vop
{
namespace node
{

class Compare : public Node
{
public:
    enum class CmpType
    {
        Equal,
        LessThan,
        GreaterThan,
        LessThanOrEqual,
        GreaterThanOrEqual,
        NotEqual,
    };

public:
    Compare()
    {
        m_imports = {
            {{ dag::VarType::Any, "input1" }},
            {{ dag::VarType::Any, "input2" }}
        };
        m_exports = {
            {{ dag::VarType::Bool, "bool" }}
        };
    }

    virtual dag::Variable Eval(size_t idx) const override;

private:
    static bool CalcEqual(const dag::Variable& v0, const dag::Variable& v1);
    static bool CalcLess(const dag::Variable& v0, const dag::Variable& v1);
    static bool CalcGreater(const dag::Variable& v0, const dag::Variable& v1);

    RTTR_ENABLE(Node)

#define PARM_FILEPATH "vop/node/Compare.parm.h"
#include <dag/node_parms_gen.h>
#undef PARM_FILEPATH

}; // Compare

}
}