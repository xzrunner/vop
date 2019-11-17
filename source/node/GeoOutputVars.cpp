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

}
}