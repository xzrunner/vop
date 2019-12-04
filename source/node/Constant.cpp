#include "vop/node/Constant.h"

namespace vop
{
namespace node
{

dag::Variable Constant::Eval(size_t idx) const 
{
    if (idx != 0) {
        return dag::Variable();
    }

    return m_const_value;
}

}
}