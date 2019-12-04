#include "vop/node/SetVectorComponent.h"
#include "vop/NodeHelper.h"

namespace vop
{
namespace node
{

//////////////////////////////////////////////////////////////////////////
// class SetVec2Comp
//////////////////////////////////////////////////////////////////////////

dag::Variable SetVec2Comp::Eval(size_t idx) const
{
    if (idx != 0) {
        return dag::Variable();
    }

    auto in_vec2 = NodeHelper::EvalInputNode(*this, 0);
    if (in_vec2.type == dag::VarType::Invalid) {
        return dag::Variable();
    }

    auto in_fval = NodeHelper::EvalInputNode(*this, 1);
    if (in_fval.type == dag::VarType::Invalid) {
        return dag::Variable();
    }

    assert(in_vec2.type == dag::VarType::Float2 
        && in_fval.type == dag::VarType::Float);
    auto vec2 = static_cast<const sm::vec2*>(in_vec2.p);
    switch (m_comp_idx)
    {
    case 0:
        return dag::Variable(sm::vec2(in_fval.f, vec2->y));
    case 1:
        return dag::Variable(sm::vec2(vec2->x, in_fval.f));
    default:
        return dag::Variable();
    }

    return dag::Variable();
}

//////////////////////////////////////////////////////////////////////////
// class SetVec3Comp
//////////////////////////////////////////////////////////////////////////

dag::Variable SetVec3Comp::Eval(size_t idx) const
{
    if (idx != 0) {
        return dag::Variable();
    }

    auto in_vec3 = NodeHelper::EvalInputNode(*this, 0);
    if (in_vec3.type == dag::VarType::Invalid) {
        return dag::Variable();
    }

    auto in_fval = NodeHelper::EvalInputNode(*this, 1);
    if (in_fval.type == dag::VarType::Invalid) {
        return dag::Variable();
    }

    assert(in_vec3.type == dag::VarType::Float3 
        && in_fval.type == dag::VarType::Float);
    auto vec3 = static_cast<const sm::vec3*>(in_vec3.p);
    switch (m_comp_idx)
    {
    case 0:
        return dag::Variable(sm::vec3(in_fval.f, vec3->y, vec3->z));
    case 1:
        return dag::Variable(sm::vec3(vec3->x, in_fval.f, vec3->z));
    case 2:
        return dag::Variable(sm::vec3(vec3->x, vec3->y, in_fval.f));
    default:
        return dag::Variable();
    }

    return dag::Variable();
}

//////////////////////////////////////////////////////////////////////////
// class SetVec4Comp
//////////////////////////////////////////////////////////////////////////

dag::Variable SetVec4Comp::Eval(size_t idx) const
{
    if (idx != 0) {
        return dag::Variable();
    }

    auto in_vec4 = NodeHelper::EvalInputNode(*this, 0);
    if (in_vec4.type == dag::VarType::Invalid) {
        return dag::Variable();
    }

    auto in_fval = NodeHelper::EvalInputNode(*this, 1);
    if (in_fval.type == dag::VarType::Invalid) {
        return dag::Variable();
    }

    assert(in_vec4.type == dag::VarType::Float4 
        && in_fval.type == dag::VarType::Float);
    auto vec4 = static_cast<const sm::vec4*>(in_vec4.p);
    switch (m_comp_idx)
    {
    case 0:
        return dag::Variable(sm::vec4(in_fval.f, vec4->y, vec4->z, vec4->w));
    case 1:
        return dag::Variable(sm::vec4(vec4->x, in_fval.f, vec4->z, vec4->w));
    case 2:
        return dag::Variable(sm::vec4(vec4->x, vec4->y, in_fval.f, vec4->w));
    case 3:
        return dag::Variable(sm::vec4(vec4->x, vec4->y, vec4->z, in_fval.f));
    default:
        return dag::Variable();
    }

    return dag::Variable();
}

}
}