#include "vop/node/Add.h"
#include "vop/NodeHelper.h"

namespace vop
{
namespace node
{

hdiop::Variable Add::Eval(size_t idx) const
{
    auto var0 = NodeHelper::EvalInputNode(*this, 0);
    auto var1 = NodeHelper::EvalInputNode(*this, 1);
    if (var0.type == hdiop::VarType::Invalid ||
        var1.type == hdiop::VarType::Invalid) {
        return hdiop::Variable();
    }

    switch (var0.type)
    {
    case hdiop::VarType::Float:
    {
        switch (var1.type)
        {
        case hdiop::VarType::Float:
            return hdiop::Variable(var0.f + var1.f);
        default:
            assert(0);
        }
    }
        break;
    case hdiop::VarType::Float3:
    {
        auto v0 = static_cast<const sm::vec3*>(var0.p);
        switch (var1.type)
        {
        case hdiop::VarType::Float3:
            return hdiop::Variable(*v0 + *static_cast<const sm::vec3*>(var1.p));
        default:
            assert(0);
        }
    }
        break;
    default:
        assert(0);
    }

    return hdiop::Variable();
}

}
}