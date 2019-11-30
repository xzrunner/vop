#include "vop/node/GeoOutputVars.h"
#include "vop/NodeHelper.h"

namespace vop
{
namespace node
{

hdiop::Variable GeoOutputVars::Eval(size_t idx) const
{
    return hdiop::Variable();
}

sm::vec3 GeoOutputVars::GetPos() const
{
    return CalcIn(IDX_POS);
}

sm::vec3 GeoOutputVars::GetColor() const
{
    return CalcIn(IDX_COLOR);
}

sm::vec3 GeoOutputVars::GetNormal() const
{
    return CalcIn(IDX_NORM);
}

sm::vec3 GeoOutputVars::CalcIn(size_t idx) const
{
    auto var = NodeHelper::EvalInputNode(*this, idx);
    if (var.type == hdiop::VarType::Invalid) 
    {
        sm::vec3 ret;
        ret.MakeInvalid();
        return ret;
    }
    else
    {
        assert(var.type == hdiop::VarType::Float3);
        return *static_cast<const sm::vec3*>(var.p);
    }
}

}
}