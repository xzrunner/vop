#pragma once

#include "vop/Node.h"

#include <hdiop/Variable.h>

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
            {{ hdiop::VarType::Any, "input1" }},
            {{ hdiop::VarType::Any, "input2" }}
        };
        m_exports = {
            {{ hdiop::VarType::Bool, "bool" }}
        };
    }

    virtual hdiop::Variable Eval(size_t idx) const override;

private:
    static bool CalcEqual(const hdiop::Variable& v0, const hdiop::Variable& v1);
    static bool CalcLess(const hdiop::Variable& v0, const hdiop::Variable& v1);
    static bool CalcGreater(const hdiop::Variable& v0, const hdiop::Variable& v1);

    RTTR_ENABLE(Node)

#define PARM_FILEPATH "vop/node/Compare.parm.h"
#include <hdiop/node_parms_gen.h>
#undef PARM_FILEPATH

}; // Compare

}
}