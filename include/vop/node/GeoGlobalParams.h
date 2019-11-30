#pragma once

#include "vop/Node.h"

namespace vop
{
namespace node
{

class GeoGlobalParams : public Node
{
public:
    enum OutPortIdx
    {
        IDX_POS = 0,
        IDX_COLOR,
        IDX_NORM,
    };

public:
    GeoGlobalParams()
    {
        m_exports = {
            {{ hdiop::VarType::Float3, "P" }},
            {{ hdiop::VarType::Float3, "Cd" }},
            {{ hdiop::VarType::Float3, "N" }}
        };
    }

    virtual hdiop::Variable Eval(size_t idx) const override;

    void SetPos(const sm::vec3& pos) { m_pos = pos; }
    void SetColor(const sm::vec3& color) { m_color = color; }
    void SetNormal(const sm::vec3& normal) { m_normal = normal; }

private:
    sm::vec3 m_pos;
    sm::vec3 m_color;
    sm::vec3 m_normal;

    RTTR_ENABLE(Node)

}; // GeoGlobalParams

}
}