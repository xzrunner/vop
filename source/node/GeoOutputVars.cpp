#include "vop/node/GeoOutputVars.h"

namespace vop
{
namespace node
{

sm::vec3 GeoOutputVars::Calc(size_t idx) const
{
    sm::vec3 ret;
    ret.MakeInvalid();
    return ret;
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
    sm::vec3 ret;
    ret.MakeInvalid();

    assert(idx >= 0 && idx < m_imports.size());
    auto& conns = m_imports[idx].conns;
    if (conns.empty()) {
        return ret;
    }

    assert(conns.size() == 1);
    auto& conn = conns.front();
    auto in_node = conn.node.lock();
    if (!in_node) {
        return ret;
    }

    assert(in_node->get_type().is_derived_from<Node>());
    return std::static_pointer_cast<Node>(in_node)->Calc(conn.idx);
}

}
}