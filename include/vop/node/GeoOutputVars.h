#pragma once

#include "vop/Node.h"

namespace vop
{
namespace node
{

class GeoOutputVars : public Node
{
public:
    GeoOutputVars()
    {
        m_imports = {
            {{ VariableType::Float3, "P" }},
            {{ VariableType::Float3, "Cd" }},
            {{ VariableType::Float3, "N" }}
        };
    }

    virtual sm::vec3 Calc(size_t idx) const override;

    RTTR_ENABLE(Node)

}; // GeoOutputVars

}
}