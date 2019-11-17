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
        IDX_VERT = 0,
        IDX_COLOR,
        IDX_NORM,
    };

public:
    GeoGlobalParams()
    {
        m_exports = {
            {{ VariableType::Float3, "P" }},
            {{ VariableType::Float3, "Cd" }},
            {{ VariableType::Float3, "N" }}
        };
    }

    virtual sm::vec3 Calc(size_t idx) const override;

    void SetVertex(const sm::vec3& vertex) { m_vertex = vertex; }
    void SetColor(const sm::vec3& color) { m_color = color; }
    void SetNormal(const sm::vec3& normal) { m_normal = normal; }

private:
    sm::vec3 m_vertex;
    sm::vec3 m_color;
    sm::vec3 m_normal;

    RTTR_ENABLE(Node)

}; // GeoGlobalParams

}
}