#include "vop/NodeHelper.h"
#include "vop/Node.h"

namespace vop
{

dag::Variable NodeHelper::EvalInputNode(const Node& node, size_t idx)
{
    auto& imports = node.GetImports();
    if (idx < 0 || idx >= imports.size()) {
        return dag::Variable();
    }

    auto& conns = imports[idx].conns;
    if (conns.empty()) {
        return dag::Variable();
    }

    assert(conns.size() == 1);
    auto& conn = conns.front();
    auto in_node = conn.node.lock();
    if (!in_node) {
        return dag::Variable();
    }
    assert(in_node->get_type().is_derived_from<Node>());
    return std::static_pointer_cast<Node>(in_node)->Eval(conn.idx);
}

}