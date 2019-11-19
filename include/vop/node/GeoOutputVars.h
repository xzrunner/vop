#pragma once

#include "vop/Node.h"

namespace vop
{
namespace node
{

class GeoOutputVars : public Node
{
public:
    enum InPortIdx
    {
        IDX_POS = 0,
        IDX_COLOR,
        IDX_NORM,
    };

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

    sm::vec3 GetPos() const;
    sm::vec3 GetColor() const;
    sm::vec3 GetNormal() const;

private:
    sm::vec3 CalcIn(size_t idx) const;

    RTTR_ENABLE(Node)

}; // GeoOutputVars

}
}