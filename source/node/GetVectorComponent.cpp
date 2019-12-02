#include "vop/node/GetVectorComponent.h"
#include "vop/NodeHelper.h"

namespace vop
{
namespace node
{

//////////////////////////////////////////////////////////////////////////
// class GetVec2Comp
//////////////////////////////////////////////////////////////////////////

hdiop::Variable GetVec2Comp::Eval(size_t idx) const
{
    if (idx != 0) {
        return hdiop::Variable();
    }

    auto input = NodeHelper::EvalInputNode(*this, 0);
    if (input.type == hdiop::VarType::Invalid) {
        return hdiop::Variable();
    }

    assert(input.type == hdiop::VarType::Float2);
    auto vec2 = static_cast<const sm::vec2*>(input.p);
    switch (m_comp_idx)
    {
    case 0:
        return hdiop::Variable(vec2->x);
    case 1:
        return hdiop::Variable(vec2->y);
    default:
        return hdiop::Variable();
    }

    return hdiop::Variable();
}

//////////////////////////////////////////////////////////////////////////
// class GetVec3Comp
//////////////////////////////////////////////////////////////////////////

hdiop::Variable GetVec3Comp::Eval(size_t idx) const
{
    if (idx != 0) {
        return hdiop::Variable();
    }

    auto input = NodeHelper::EvalInputNode(*this, 0);
    if (input.type == hdiop::VarType::Invalid) {
        return hdiop::Variable();
    }

    assert(input.type == hdiop::VarType::Float3);
    auto vec3 = static_cast<const sm::vec3*>(input.p);
    switch (m_comp_idx)
    {
    case 0:
        return hdiop::Variable(vec3->x);
    case 1:
        return hdiop::Variable(vec3->y);
    case 2:
        return hdiop::Variable(vec3->z);
    default:
        return hdiop::Variable();
    }

    return hdiop::Variable();
}

//////////////////////////////////////////////////////////////////////////
// class GetVec4Comp
//////////////////////////////////////////////////////////////////////////

hdiop::Variable GetVec4Comp::Eval(size_t idx) const
{
    if (idx != 0) {
        return hdiop::Variable();
    }

    auto input = NodeHelper::EvalInputNode(*this, 0);
    if (input.type == hdiop::VarType::Invalid) {
        return hdiop::Variable();
    }

    assert(input.type == hdiop::VarType::Float4);
    auto vec4 = static_cast<const sm::vec4*>(input.p);
    switch (m_comp_idx)
    {
    case 0:
        return hdiop::Variable(vec4->x);
    case 1:
        return hdiop::Variable(vec4->y);
    case 2:
        return hdiop::Variable(vec4->z);
    case 3:
        return hdiop::Variable(vec4->w);
    default:
        return hdiop::Variable();
    }

    return hdiop::Variable();
}

}
}