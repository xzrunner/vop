#include "vop/node/Multiply.h"
#include "vop/NodeHelper.h"

namespace vop
{
namespace node
{

dag::Variable Multiply::Eval(size_t idx) const
{
    if (idx != 0) {
        return dag::Variable();
    }

    auto var0 = NodeHelper::EvalInputNode(*this, 0);
    auto var1 = NodeHelper::EvalInputNode(*this, 1);
    if (var0.type == dag::VarType::Invalid ||
        var1.type == dag::VarType::Invalid) {
        return dag::Variable();
    }

    switch (var0.type)
    {
    case dag::VarType::Int:
    {
        switch (var1.type)
        {
        case dag::VarType::Int:
            return dag::Variable(var0.i * var1.i);
        default:
            assert(0);
        }
    }
        break;
    case dag::VarType::Float:
    {
        auto v0 = var0.f;
        switch (var1.type)
        {
        case dag::VarType::Float:
            return dag::Variable(var0.f * var1.f);
        case dag::VarType::Float3:
            return dag::Variable(*static_cast<const sm::vec3*>(var1.p) * v0);
        default:
            assert(0);
        }
    }
        break;
    case dag::VarType::Float3:
    {
        auto v0 = static_cast<const sm::vec3*>(var0.p);
        switch (var1.type)
        {
        case dag::VarType::Float:
            return dag::Variable(*v0 * var1.f);
        default:
            assert(0);
        }
    }
        break;
    default:
        assert(0);
    }

    return dag::Variable();
}

}
}