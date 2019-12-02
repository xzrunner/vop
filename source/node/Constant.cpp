#include "vop/node/Constant.h"

namespace vop
{
namespace node
{

hdiop::Variable Constant::Eval(size_t idx) const 
{
    if (idx != 0) {
        return hdiop::Variable();
    }

    return m_const_value;
}

}
}