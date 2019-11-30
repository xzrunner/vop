#include "vop/node/GeoGlobalParams.h"

namespace vop
{
namespace node
{

hdiop::Variable GeoGlobalParams::Eval(size_t idx) const
{
    switch (idx)
    {
    case IDX_POS:
        return hdiop::Variable(m_pos);
    case IDX_COLOR:
        return hdiop::Variable(m_color);
    case IDX_NORM:
        return hdiop::Variable(m_normal);
    default:
        return hdiop::Variable();
    }
}

}
}