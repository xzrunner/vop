#include "vop/node/Constant.h"

namespace vop
{
namespace node
{

void Constant::SetValue(float v)
{
    m_value = hdiop::Variable(v);
}

}
}