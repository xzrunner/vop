#pragma once

#include "vop/typedef.h"

#include <dag/Node.h>
#include <dag/VarType.h>

#include <map>
#include <vector>

namespace vop
{

class Evaluator
{
public:
    // update nodes
    void AddNode(const NodePtr& node);
    void RemoveNode(const NodePtr& node);
    void ClearAllNodes();

    // update node conn
    void Connect(const dag::Node<dag::VarType>::PortAddr& from, const dag::Node<dag::VarType>::PortAddr& to);
    void Disconnect(const dag::Node<dag::VarType>::PortAddr& from, const dag::Node<dag::VarType>::PortAddr& to);

    auto& GetAllNodes() const { return m_nodes_sorted; }

    NodePtr FindNode(const std::string& name) const;

private:
    std::map<std::string, NodePtr> m_nodes_map;

    std::vector<NodePtr> m_nodes_sorted;

    bool m_dirty = false;

    size_t m_next_id = 0;

}; // Evaluator

}