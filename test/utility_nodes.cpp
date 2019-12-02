#include "utility.h"

#include <vop/node/Compare.h>

#include <vop/Evaluator.h>
#include <vop/node/Constant.h>

#include <catch/catch.hpp>

TEST_CASE("compare")
{
    test::init();

    vop::Evaluator eval;

    auto v0 = std::make_shared<vop::node::Constant>();
    eval.AddNode(v0);

    auto v1 = std::make_shared<vop::node::Constant>();
    eval.AddNode(v1);

    auto cmp = std::make_shared<vop::node::Compare>();
    eval.AddNode(cmp);

    eval.Connect({ v0, 0 }, { cmp, 0 });
    eval.Connect({ v1, 0 }, { cmp, 1 });

    SECTION("==")
    {
        cmp->SetCmpType(vop::node::Compare::CmpType::Equal);

        v0->SetConstType(vop::node::Constant::Type::ConstInteger);
        v0->SetConstValue(hdiop::Variable(1));

        v1->SetConstType(vop::node::Constant::Type::ConstInteger);
        v1->SetConstValue(hdiop::Variable(2));

        REQUIRE(cmp->Eval(0) == hdiop::Variable(false));

        v0->SetConstValue(hdiop::Variable(2));
        REQUIRE(cmp->Eval(0) == hdiop::Variable(true));
    }

    SECTION("<")
    {
        cmp->SetCmpType(vop::node::Compare::CmpType::LessThan);

        v0->SetConstType(vop::node::Constant::Type::ConstFloat);
        v0->SetConstValue(hdiop::Variable(1.1f));

        v1->SetConstType(vop::node::Constant::Type::ConstFloat);
        v1->SetConstValue(hdiop::Variable(1.2f));

        REQUIRE(cmp->Eval(0) == hdiop::Variable(true));

        v1->SetConstValue(hdiop::Variable(0.2f));
        REQUIRE(cmp->Eval(0) == hdiop::Variable(false));
    }

    SECTION(">")
    {
        cmp->SetCmpType(vop::node::Compare::CmpType::GreaterThan);

        v0->SetConstType(vop::node::Constant::Type::ConstFloat);
        v0->SetConstValue(hdiop::Variable(1.1f));

        v1->SetConstType(vop::node::Constant::Type::ConstFloat);
        v1->SetConstValue(hdiop::Variable(1.1f));

        REQUIRE(cmp->Eval(0) == hdiop::Variable(false));

        v1->SetConstValue(hdiop::Variable(0.2f));
        REQUIRE(cmp->Eval(0) == hdiop::Variable(true));
    }

    SECTION("<=")
    {
        cmp->SetCmpType(vop::node::Compare::CmpType::LessThanOrEqual);

        v0->SetConstType(vop::node::Constant::Type::ConstFloat);
        v0->SetConstValue(hdiop::Variable(1.1f));

        v1->SetConstType(vop::node::Constant::Type::ConstFloat);
        v1->SetConstValue(hdiop::Variable(1.1f));

        REQUIRE(cmp->Eval(0) == hdiop::Variable(true));

        v0->SetConstValue(hdiop::Variable(0.2f));
        REQUIRE(cmp->Eval(0) == hdiop::Variable(true));
    }

    SECTION(">=")
    {
        cmp->SetCmpType(vop::node::Compare::CmpType::GreaterThanOrEqual);

        v0->SetConstType(vop::node::Constant::Type::ConstFloat);
        v0->SetConstValue(hdiop::Variable(1.1f));

        v1->SetConstType(vop::node::Constant::Type::ConstFloat);
        v1->SetConstValue(hdiop::Variable(1.1f));

        REQUIRE(cmp->Eval(0) == hdiop::Variable(true));

        v1->SetConstValue(hdiop::Variable(0.2f));
        REQUIRE(cmp->Eval(0) == hdiop::Variable(true));
    }

    SECTION("!=")
    {
        cmp->SetCmpType(vop::node::Compare::CmpType::NotEqual);

        v0->SetConstType(vop::node::Constant::Type::ConstFloat);
        v0->SetConstValue(hdiop::Variable(1.1f));

        v1->SetConstType(vop::node::Constant::Type::ConstFloat);
        v1->SetConstValue(hdiop::Variable(1.1f));

        REQUIRE(cmp->Eval(0) == hdiop::Variable(false));

        v0->SetConstValue(hdiop::Variable(0.2f));
        REQUIRE(cmp->Eval(0) == hdiop::Variable(true));
    }
}