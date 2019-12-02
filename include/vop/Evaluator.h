#pragma once

#include "vop/typedef.h"

#include <hdiop/Node.h>
#include <hdiop/VarType.h>

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
    void Connect(const hdiop::Node<hdiop::VarType>::PortAddr& from, const hdiop::Node<hdiop::VarType>::PortAddr& to);
    void Disconnect(const hdiop::Node<hdiop::VarType>::PortAddr& from, const hdiop::Node<hdiop::VarType>::PortAddr& to);

    auto& GetAllNodes() const { return m_nodes_sorted; }

    NodePtr FindNode(const std::string& name) const;

private:
    std::map<std::string, NodePtr> m_nodes_map;

    std::vector<NodePtr> m_nodes_sorted;

    bool m_dirty = false;

    size_t m_next_id = 0;

}; // Evaluator

}