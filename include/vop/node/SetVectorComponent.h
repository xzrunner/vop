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
            {{ dag::VarType::Float2, "vec2" }},
            {{ dag::VarType::Float,  "fval" }}
        };
        m_exports = {
            {{ dag::VarType::Float2, "newvec2" }}
        };
    }

    virtual dag::Variable Eval(size_t idx) const override;

    RTTR_ENABLE(Node)

#define PARM_FILEPATH "vop/node/GetSetVec2Comp.parm.h"
#include <dag/node_parms_gen.h>
#undef PARM_FILEPATH

}; // SetVec2Comp

class SetVec3Comp : public Node
{
public:
    SetVec3Comp()
    {
        m_imports = {
            {{ dag::VarType::Float3, "vec" }},
            {{ dag::VarType::Float,  "fval" }}
        };
        m_exports = {
            {{ dag::VarType::Float3, "newvec" }}
        };
    }

    virtual dag::Variable Eval(size_t idx) const override;

    RTTR_ENABLE(Node)

#define PARM_FILEPATH "vop/node/GetSetVec3Comp.parm.h"
#include <dag/node_parms_gen.h>
#undef PARM_FILEPATH

}; // SetVec3Comp

class SetVec4Comp : public Node
{
public:
    SetVec4Comp()
    {
        m_imports = {
            {{ dag::VarType::Float4, "vec4" }},
            {{ dag::VarType::Float,  "fval" }}
        };
        m_exports = {
            {{ dag::VarType::Float4, "newvec4" }}
        };
    }

    virtual dag::Variable Eval(size_t idx) const override;

    RTTR_ENABLE(Node)

#define PARM_FILEPATH "vop/node/GetSetVec4Comp.parm.h"
#include <dag/node_parms_gen.h>
#undef PARM_FILEPATH

}; // SetVec4Comp

}
}