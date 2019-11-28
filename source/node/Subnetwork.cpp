#include "vop/node/Subnetwork.h"

namespace vop
{
namespace node
{

void Subnetwork::AddChild(const std::shared_ptr<Subnetwork>& parent,
                            const std::shared_ptr<Node>& child)
{
    if (!parent || !child) {
        return;
    }
    for (auto& c : parent->m_children) {
        if (c == child) {
            return;
        }
    }

    parent->m_children.push_back(child);
    //child->SetParent(parent);
}

std::shared_ptr<Node>
Subnetwork::QueryChild(const std::string& name) const
{
    for (auto& c : m_children) {
        if (c->GetName() == name) {
            return c;
        }
    }
    return nullptr;
}

}
}