#include "vop/node/Compare.h"
#include "vop/NodeHelper.h"

namespace vop
{
namespace node
{

hdiop::Variable Compare::Eval(size_t idx) const
{
    if (idx != 0) {
        return hdiop::Variable();
    }

    auto var0 = NodeHelper::EvalInputNode(*this, 0);
    auto var1 = NodeHelper::EvalInputNode(*this, 1);
    if (var0.type == hdiop::VarType::Invalid ||
        var1.type == hdiop::VarType::Invalid) {
        return hdiop::Variable();
    }

    switch (m_cmp)
    {
    case CmpType::Equal:
        return hdiop::Variable(CalcEqual(var0, var1));
    case CmpType::LessThan:
        return hdiop::Variable(CalcLess(var0, var1));
    case CmpType::GreaterThan:
        return hdiop::Variable(CalcGreater(var0, var1));
    case CmpType::LessThanOrEqual:
        return hdiop::Variable(!CalcGreater(var0, var1));
    case CmpType::GreaterThanOrEqual:
        return hdiop::Variable(!CalcLess(var0, var1));
    case CmpType::NotEqual:
        return hdiop::Variable(!CalcEqual(var0, var1));
    }

    return hdiop::Variable();
}

bool Compare::CalcEqual(const hdiop::Variable& v0, const hdiop::Variable& v1)
{
    switch (v0.type)
    {
    case hdiop::VarType::Int:
        switch (v1.type)
        {
            case hdiop::VarType::Int:
                return v0.i == v1.i;
        }
        break;
    case hdiop::VarType::Float:
        switch (v1.type)
        {
            case hdiop::VarType::Float:
                return v0.f == v1.f;
        }
        break;
    case hdiop::VarType::Float3:
        switch (v1.type)
        {
        case hdiop::VarType::Float3:
            return *static_cast<const sm::vec3*>(v0.p)
                == *static_cast<const sm::vec3*>(v1.p);
        }
        break;
    }
    return false;
}

bool Compare::CalcLess(const hdiop::Variable& v0, const hdiop::Variable& v1)
{
    switch (v0.type)
    {
    case hdiop::VarType::Int:
        switch (v1.type)
        {
            case hdiop::VarType::Int:
                return v0.i < v1.i;
        }
        break;
    case hdiop::VarType::Float:
        switch (v1.type)
        {
            case hdiop::VarType::Float:
                return v0.f < v1.f;
        }
        break;
    case hdiop::VarType::Float3:
        switch (v1.type)
        {
        case hdiop::VarType::Float3:
            return *static_cast<const sm::vec3*>(v0.p)
                 < *static_cast<const sm::vec3*>(v1.p);
        }
        break;
    }
    return false;
}

bool Compare::CalcGreater(const hdiop::Variable& v0, const hdiop::Variable& v1)
{
    switch (v0.type)
    {
    case hdiop::VarType::Int:
        switch (v1.type)
        {
            case hdiop::VarType::Int:
                return v0.i > v1.i;
        }
        break;
    case hdiop::VarType::Float:
        switch (v1.type)
        {
            case hdiop::VarType::Float:
                return v0.f > v1.f;
        }
        break;
    case hdiop::VarType::Float3:
        switch (v1.type)
        {
        case hdiop::VarType::Float3:
            return *static_cast<const sm::vec3*>(v0.p)
                 > *static_cast<const sm::vec3*>(v1.p);
        }
        break;
    }
    return false;
}

}
}