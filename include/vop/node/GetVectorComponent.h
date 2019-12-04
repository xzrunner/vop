#pragma once

#include "vop/Node.h"
#include "vop/ComponentType.h"

namespace vop
{
namespace node
{

class GetVec2Comp : public Node
{
public:
    GetVec2Comp()
    {
        m_imports = {
            {{ dag::VarType::Float2, "vec2" }}
        };
        m_exports = {
            {{ dag::VarType::Float, "fval" }}
        };
    }

    virtual dag::Variable Eval(size_t idx) const override;

    RTTR_ENABLE(Node)

#define PARM_FILEPATH "vop/node/GetSetVec2Comp.parm.h"
#include <dag/node_parms_gen.h>
#undef PARM_FILEPATH

}; // GetVec2Comp

class GetVec3Comp : public Node
{
public:
    GetVec3Comp()
    {
        m_imports = {
            {{ dag::VarType::Float3, "vec3" }}
        };
        m_exports = {
            {{ dag::VarType::Float, "fval" }}
        };
    }

    virtual dag::Variable Eval(size_t idx) const override;

    RTTR_ENABLE(Node)

#define PARM_FILEPATH "vop/node/GetSetVec3Comp.parm.h"
#include <dag/node_parms_gen.h>
#undef PARM_FILEPATH

}; // GetVec3Comp

class GetVec4Comp : public Node
{
public:
    GetVec4Comp()
    {
        m_imports = {
            {{ dag::VarType::Float4, "vec4" }}
        };
        m_exports = {
            {{ dag::VarType::Float, "fval" }}
        };
    }

    virtual dag::Variable Eval(size_t idx) const override;

    RTTR_ENABLE(Node)

#define PARM_FILEPATH "vop/node/GetSetVec4Comp.parm.h"
#include <dag/node_parms_gen.h>
#undef PARM_FILEPATH

}; // GetVec4Comp

}
}