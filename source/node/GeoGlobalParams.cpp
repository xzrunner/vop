#include "vop/node/GeoGlobalParams.h"

namespace vop
{
namespace node
{

dag::Variable GeoGlobalParams::Eval(size_t idx) const
{
    switch (idx)
    {
    case IDX_POS:
        return dag::Variable(m_pos);
    case IDX_COLOR:
        return dag::Variable(m_color);
    case IDX_UV:
        return dag::Variable(m_uv);
    case IDX_NORM:
        return dag::Variable(m_normal);
    case IDX_PT_IDX:
        return dag::Variable(m_pt_idx);
    case IDX_PRIM_IDX:
        return dag::Variable(m_prim_idx);
    case IDX_VTX_IDX:
        return dag::Variable(m_vtx_idx);
    case IDX_PT_NUM:
        return dag::Variable(m_pt_num);
    case IDX_PRIM_NUM:
        return dag::Variable(m_prim_num);
    case IDX_VTX_NUM:
        return dag::Variable(m_vtx_num);
    default:
        return dag::Variable();
    }
}

}
}