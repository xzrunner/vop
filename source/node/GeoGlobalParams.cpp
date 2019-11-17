#include "vop/node/GeoGlobalParams.h"

namespace vop
{
namespace node
{

sm::vec3 GeoGlobalParams::Calc(size_t idx) const
{
    switch (idx)
    {
    case IDX_VERT:
        return m_vertex;
    case IDX_COLOR:
        return m_color;
    case IDX_NORM:
        return m_normal;
    default:
    {
        sm::vec3 ret;
        ret.MakeInvalid();;
        return ret;
    }
    }
}

}
}