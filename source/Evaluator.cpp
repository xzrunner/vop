#include "vop/Evaluator.h"
#include "vop/Node.h"

namespace vop
{

void Evaluator::AddNode(const NodePtr& node)
{
    auto name = node->GetName();
    while (name.empty() || m_nodes_map.find(name) != m_nodes_map.end())
    {
        if (node->GetName().empty()) {
            name = "node" + std::to_string(m_next_id++);
        } else {
            name = node->GetName() + std::to_string(m_next_id++);
        }
    }
    node->SetName(name);

    assert(m_nodes_map.size() == m_nodes_sorted.size());
    m_nodes_map.insert({ name, node });
    m_nodes_sorted.insert(m_nodes_sorted.begin(), node);

    m_dirty = true;
}

void Evaluator::RemoveNode(const NodePtr& node)
{
    if (m_nodes_map.empty()) {
        return;
    }

    auto itr = m_nodes_map.find(node->GetName());
    if (itr == m_nodes_map.end()) {
        return;
    }

    assert(m_nodes_map.size() == m_nodes_sorted.size());
    m_nodes_map.erase(itr);
    for (auto itr = m_nodes_sorted.begin(); itr != m_nodes_sorted.end(); ++itr) {
        if (*itr == node) {
            m_nodes_sorted.erase(itr);
            break;
        }
    }

    m_dirty = true;
}

void Evaluator::ClearAllNodes()
{
    if (m_nodes_map.empty()) {
        return;
    }

    assert(m_nodes_map.size() == m_nodes_sorted.size());
    m_nodes_map.clear();
    m_nodes_sorted.clear();

    m_next_id = 0;

    m_dirty = true;
}

NodePtr Evaluator::FindNode(const std::string& name) const
{
    auto itr = m_nodes_map.find(name);
    return itr == m_nodes_map.end() ? nullptr : itr->second;
}

}