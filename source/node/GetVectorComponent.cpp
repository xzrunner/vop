#include "vop/node/GetVectorComponent.h"
#include "vop/NodeHelper.h"

namespace vop
{
namespace node
{

//////////////////////////////////////////////////////////////////////////
// class GetVec2Comp
//////////////////////////////////////////////////////////////////////////

dag::Variable GetVec2Comp::Eval(size_t idx) const
{
    if (idx != 0) {
        return dag::Variable();
    }

    auto input = NodeHelper::EvalInputNode(*this, 0);
    if (input.type == dag::VarType::Invalid) {
        return dag::Variable();
    }

    assert(input.type == dag::VarType::Float2);
    auto vec2 = static_cast<const sm::vec2*>(input.p);
    switch (m_comp_idx)
    {
    case 0:
        return dag::Variable(vec2->x);
    case 1:
        return dag::Variable(vec2->y);
    default:
        return dag::Variable();
    }

    return dag::Variable();
}

//////////////////////////////////////////////////////////////////////////
// class GetVec3Comp
//////////////////////////////////////////////////////////////////////////

dag::Variable GetVec3Comp::Eval(size_t idx) const
{
    if (idx != 0) {
        return dag::Variable();
    }

    auto input = NodeHelper::EvalInputNode(*this, 0);
    if (input.type == dag::VarType::Invalid) {
        return dag::Variable();
    }

    assert(input.type == dag::VarType::Float3);
    auto vec3 = static_cast<const sm::vec3*>(input.p);
    switch (m_comp_idx)
    {
    case 0:
        return dag::Variable(vec3->x);
    case 1:
        return dag::Variable(vec3->y);
    case 2:
        return dag::Variable(vec3->z);
    default:
        return dag::Variable();
    }

    return dag::Variable();
}

//////////////////////////////////////////////////////////////////////////
// class GetVec4Comp
//////////////////////////////////////////////////////////////////////////

dag::Variable GetVec4Comp::Eval(size_t idx) const
{
    if (idx != 0) {
        return dag::Variable();
    }

    auto input = NodeHelper::EvalInputNode(*this, 0);
    if (input.type == dag::VarType::Invalid) {
        return dag::Variable();
    }

    assert(input.type == dag::VarType::Float4);
    auto vec4 = static_cast<const sm::vec4*>(input.p);
    switch (m_comp_idx)
    {
    case 0:
        return dag::Variable(vec4->x);
    case 1:
        return dag::Variable(vec4->y);
    case 2:
        return dag::Variable(vec4->z);
    case 3:
        return dag::Variable(vec4->w);
    default:
        return dag::Variable();
    }

    return dag::Variable();
}

}
}