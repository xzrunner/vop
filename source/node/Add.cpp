#include "vop/node/Add.h"
#include "vop/NodeHelper.h"

namespace vop
{
namespace node
{

dag::Variable Add::Eval(size_t idx) const
{
    if (idx != 0) {
        return dag::Variable();
    }

    auto var0 = NodeHelper::EvalInputNode(*this, 0);
    auto var1 = NodeHelper::EvalInputNode(*this, 1);
    if (var0.type == dag::VarType::Invalid &&
        var1.type == dag::VarType::Invalid) {
        return dag::Variable();
    } else if (var0.type != dag::VarType::Invalid &&
               var1.type == dag::VarType::Invalid) {
        return var0;
    } else if (var0.type == dag::VarType::Invalid &&
               var1.type != dag::VarType::Invalid) {
        return var1;
    }

    switch (var0.type)
    {
    case dag::VarType::Int:
    {
        switch (var1.type)
        {
        case dag::VarType::Int:
            return dag::Variable(var0.i + var1.i);
        default:
            assert(0);
        }
    }
        break;
    case dag::VarType::Float:
    {
        switch (var1.type)
        {
        case dag::VarType::Float:
            return dag::Variable(var0.f + var1.f);
        case dag::VarType::Float3:
            return dag::Variable(
                sm::vec3(var0.f, var0.f, var0.f) + 
                *static_cast<const sm::vec3*>(var1.p)
            );
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
            return dag::Variable(*v0 + sm::vec3(var1.f, var1.f, var1.f));
        case dag::VarType::Float3:
            return dag::Variable(*v0 + *static_cast<const sm::vec3*>(var1.p));
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