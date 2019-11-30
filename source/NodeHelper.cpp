#include "vop/NodeHelper.h"
#include "vop/Node.h"

namespace vop
{

hdiop::Variable NodeHelper::EvalInputNode(const Node& node, size_t idx)
{
    auto& imports = node.GetImports();
    if (idx < 0 || idx >= imports.size()) {
        return hdiop::Variable();
    }

    auto& conns = imports[idx].conns;
    if (conns.empty()) {
        return hdiop::Variable();
    }

    assert(conns.size() == 1);
    auto& conn = conns.front();
    auto in_node = conn.node.lock();
    if (!in_node) {
        return hdiop::Variable();
    }
    assert(in_node->get_type().is_derived_from<Node>());
    return std::static_pointer_cast<Node>(in_node)->Eval(conn.idx);
}

}