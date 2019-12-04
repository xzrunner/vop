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
        IDX_UV,
        IDX_NORM,

        IDX_PT_IDX,
        IDX_PRIM_IDX,
        IDX_VTX_IDX,
        IDX_PT_NUM,
        IDX_PRIM_NUM,
        IDX_VTX_NUM,
    };

public:
    GeoGlobalParams()
    {
        m_exports = {
            {{ dag::VarType::Float3, "P" }},
            {{ dag::VarType::Float3, "Cd" }},
            {{ dag::VarType::Float3, "uv" }},
            {{ dag::VarType::Float3, "N" }},

            {{ dag::VarType::Int,    "ptnum" }},
            {{ dag::VarType::Int,    "primnum" }},
            {{ dag::VarType::Int,    "vtxnum" }},
            {{ dag::VarType::Int,    "numpt" }},
            {{ dag::VarType::Int,    "numprim" }},
            {{ dag::VarType::Int,    "numvtx" }}
        };
    }

    virtual dag::Variable Eval(size_t idx) const override;

    void SetPos(const sm::vec3& pos) { m_pos = pos; }
    void SetColor(const sm::vec3& color) { m_color = color; }
    void SetUV(const sm::vec3& uv) { m_uv = uv; }
    void SetNormal(const sm::vec3& normal) { m_normal = normal; }

    void SetPointIdx(int idx)  { m_pt_idx = idx; }
    void SetPrimIdx(int idx)   { m_prim_idx = idx; }
    void SetVertexIdx(int idx) { m_vtx_idx = idx; }
    void SetPointNum(int num)  { m_pt_num = num; }
    void SetPrimNum(int num)   { m_prim_num = num; }
    void SetVertexNum(int num) { m_vtx_num = num; }

private:
    sm::vec3 m_pos;
    sm::vec3 m_color;
    sm::vec3 m_uv;
    sm::vec3 m_normal;

    int m_pt_idx = 0;
    int m_prim_idx = 0;
    int m_vtx_idx = 0;
    int m_pt_num = 0;
    int m_prim_num = 0;
    int m_vtx_num = 0;

    RTTR_ENABLE(Node)

}; // GeoGlobalParams

}
}