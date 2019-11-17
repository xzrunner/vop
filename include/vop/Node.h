#pragma once

#include "vop/Variable.h"

#include <SM_Vector.h>

#include <rttr/registration>

namespace vop
{

class Node
{
public:
    Node(size_t build_in_count = 0);

    virtual sm::vec3 Calc(size_t idx) const = 0;

    virtual void AddInputPorts(size_t num) {}

    struct Port;
    void SetImports(const std::vector<Port>& imports) { m_imports = imports; }
    void SetExports(const std::vector<Port>& exports) { m_exports = exports; }

    auto& GetImports() const { return m_imports; }
    auto& GetExports() const { return m_exports; }

    void SetName(const std::string& name) { m_name = name; }
    auto& GetName() const { return m_name; }

    void ClearConnections();

public:
    struct PortAddr
    {
        PortAddr() {}
        PortAddr(const std::shared_ptr<Node>& node, int idx)
            : node(node), idx(idx) {}
        PortAddr(const PortAddr& addr)
            : node(addr.node), idx(addr.idx) {}

        std::weak_ptr<Node> node;
        int idx = -1;
    };

    struct Port
    {
        Port() {}
        Port(const Variable& var)
            : var(var) {}

        Variable var;
        std::vector<PortAddr> conns;
    };

protected:
    std::vector<Port> m_imports, m_exports;

private:
    std::string m_name;

    RTTR_ENABLE()

}; // Node

void make_connecting(const Node::PortAddr& from, const Node::PortAddr& to);
void disconnect(const Node::PortAddr& from, const Node::PortAddr& to);

}