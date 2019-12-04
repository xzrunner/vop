#include "vop/node/Compare.h"
#include "vop/NodeHelper.h"

namespace vop
{
namespace node
{

dag::Variable Compare::Eval(size_t idx) const
{
    if (idx != 0) {
        return dag::Variable();
    }

    auto var0 = NodeHelper::EvalInputNode(*this, 0);
    auto var1 = NodeHelper::EvalInputNode(*this, 1);
    if (var0.type == dag::VarType::Invalid ||
        var1.type == dag::VarType::Invalid) {
        return dag::Variable();
    }

    switch (m_cmp)
    {
    case CmpType::Equal:
        return dag::Variable(CalcEqual(var0, var1));
    case CmpType::LessThan:
        return dag::Variable(CalcLess(var0, var1));
    case CmpType::GreaterThan:
        return dag::Variable(CalcGreater(var0, var1));
    case CmpType::LessThanOrEqual:
        return dag::Variable(!CalcGreater(var0, var1));
    case CmpType::GreaterThanOrEqual:
        return dag::Variable(!CalcLess(var0, var1));
    case CmpType::NotEqual:
        return dag::Variable(!CalcEqual(var0, var1));
    }

    return dag::Variable();
}

bool Compare::CalcEqual(const dag::Variable& v0, const dag::Variable& v1)
{
    switch (v0.type)
    {
    case dag::VarType::Int:
        switch (v1.type)
        {
            case dag::VarType::Int:
                return v0.i == v1.i;
        }
        break;
    case dag::VarType::Float:
        switch (v1.type)
        {
            case dag::VarType::Float:
                return v0.f == v1.f;
        }
        break;
    case dag::VarType::Float3:
        switch (v1.type)
        {
        case dag::VarType::Float3:
            return *static_cast<const sm::vec3*>(v0.p)
                == *static_cast<const sm::vec3*>(v1.p);
        }
        break;
    }
    return false;
}

bool Compare::CalcLess(const dag::Variable& v0, const dag::Variable& v1)
{
    switch (v0.type)
    {
    case dag::VarType::Int:
        switch (v1.type)
        {
            case dag::VarType::Int:
                return v0.i < v1.i;
        }
        break;
    case dag::VarType::Float:
        switch (v1.type)
        {
            case dag::VarType::Float:
                return v0.f < v1.f;
        }
        break;
    case dag::VarType::Float3:
        switch (v1.type)
        {
        case dag::VarType::Float3:
            return *static_cast<const sm::vec3*>(v0.p)
                 < *static_cast<const sm::vec3*>(v1.p);
        }
        break;
    }
    return false;
}

bool Compare::CalcGreater(const dag::Variable& v0, const dag::Variable& v1)
{
    switch (v0.type)
    {
    case dag::VarType::Int:
        switch (v1.type)
        {
            case dag::VarType::Int:
                return v0.i > v1.i;
        }
        break;
    case dag::VarType::Float:
        switch (v1.type)
        {
            case dag::VarType::Float:
                return v0.f > v1.f;
        }
        break;
    case dag::VarType::Float3:
        switch (v1.type)
        {
        case dag::VarType::Float3:
            return *static_cast<const sm::vec3*>(v0.p)
                 > *static_cast<const sm::vec3*>(v1.p);
        }
        break;
    }
    return false;
}

}
}