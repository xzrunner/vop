#pragma once

#include "vop/Node.h"
#include "vop/ComponentType.h"

namespace vop
{
namespace node
{

class SetVec2Comp : public Node
{
public:
    SetVec2Comp()
    {
        m_imports = {
            {{ hdiop::VarType::Float2, "vec2" }},
            {{ hdiop::VarType::Float,  "fval" }}
        };
        m_exports = {
            {{ hdiop::VarType::Float2, "newvec2" }}
        };
    }

    virtual hdiop::Variable Eval(size_t idx) const override;

    RTTR_ENABLE(Node)

#define PARM_FILEPATH "vop/node/GetSetVec2Comp.parm.h"
#include <hdiop/node_parms_gen.h>
#undef PARM_FILEPATH

}; // SetVec2Comp

class SetVec3Comp : public Node
{
public:
    SetVec3Comp()
    {
        m_imports = {
            {{ hdiop::VarType::Float3, "vec" }},
            {{ hdiop::VarType::Float,  "fval" }}
        };
        m_exports = {
            {{ hdiop::VarType::Float3, "newvec" }}
        };
    }

    virtual hdiop::Variable Eval(size_t idx) const override;

    RTTR_ENABLE(Node)

#define PARM_FILEPATH "vop/node/GetSetVec3Comp.parm.h"
#include <hdiop/node_parms_gen.h>
#undef PARM_FILEPATH

}; // SetVec3Comp

class SetVec4Comp : public Node
{
public:
    SetVec4Comp()
    {
        m_imports = {
            {{ hdiop::VarType::Float4, "vec4" }},
            {{ hdiop::VarType::Float,  "fval" }}
        };
        m_exports = {
            {{ hdiop::VarType::Float4, "newvec4" }}
        };
    }

    virtual hdiop::Variable Eval(size_t idx) const override;

    RTTR_ENABLE(Node)

#define PARM_FILEPATH "vop/node/GetSetVec4Comp.parm.h"
#include <hdiop/node_parms_gen.h>
#undef PARM_FILEPATH

}; // SetVec4Comp

}
}