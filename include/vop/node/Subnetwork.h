#pragma once

#include "vop/Node.h"

#include <set>

namespace vop
{
namespace node
{

class Subnetwork : public Node
{
public:
    Subnetwork()
    {
    }

    virtual hdiop::Variable Eval(size_t idx) const { return hdiop::Variable(); }

    void ClearChildren() { m_children.clear(); }
    static void AddChild(const std::shared_ptr<Subnetwork>& parent,
        const std::shared_ptr<Node>& child);

    std::shared_ptr<Node> QueryChild(const std::string& name) const;

protected:
    std::vector<std::shared_ptr<Node>> m_children;

    RTTR_ENABLE(Node)

}; // Subnetwork

}
}