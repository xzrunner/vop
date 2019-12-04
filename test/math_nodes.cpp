#include "utility.h"

#include <vop/node/Add.h>
#include <vop/node/Multiply.h>

#include <vop/Evaluator.h>
#include <vop/node/Constant.h>

#include <catch/catch.hpp>

TEST_CASE("add")
{
    test::init();

    vop::Evaluator eval;

    auto v0 = std::make_shared<vop::node::Constant>();
    eval.AddNode(v0);

    auto v1 = std::make_shared<vop::node::Constant>();
    eval.AddNode(v1);

    auto add = std::make_shared<vop::node::Add>();
    eval.AddNode(add);

    eval.Connect({ v0, 0 }, { add, 0 });
    eval.Connect({ v1, 0 }, { add, 1 });

    SECTION("int + int")
    {
        v0->SetConstType(vop::node::Constant::Type::ConstInteger);
        v0->SetConstValue(dag::Variable(1));

        v1->SetConstType(vop::node::Constant::Type::ConstInteger);
        v1->SetConstValue(dag::Variable(2));

        test::check_value_approx(add->Eval(0), dag::Variable(3));
    }

    SECTION("float + float")
    {
        v0->SetConstType(vop::node::Constant::Type::ConstFloat);
        v0->SetConstValue(dag::Variable(1.1f));

        v1->SetConstType(vop::node::Constant::Type::ConstFloat);
        v1->SetConstValue(dag::Variable(2.2f));

        test::check_value_approx(add->Eval(0), dag::Variable(3.3f));
    }

    SECTION("float3 + float3")
    {
        v0->SetConstType(vop::node::Constant::Type::ConstFloat3);
        v0->SetConstValue(dag::Variable(sm::vec3(1, 2, 3)));

        v1->SetConstType(vop::node::Constant::Type::ConstFloat3);
        v1->SetConstValue(dag::Variable(sm::vec3(.1f, .2f, .3f)));

        test::check_value_approx(add->Eval(0), dag::Variable(sm::vec3(1.1f, 2.2f, 3.3f)));
    }

    SECTION("float + float3")
    {
        v0->SetConstType(vop::node::Constant::Type::ConstFloat);
        v0->SetConstValue(dag::Variable(1.1f));

        v1->SetConstType(vop::node::Constant::Type::ConstFloat3);
        v1->SetConstValue(dag::Variable(sm::vec3(.1f, .2f, .3f)));

        test::check_value_approx(add->Eval(0), dag::Variable(sm::vec3(1.2f, 1.3f, 1.4f)));
    }

    SECTION("float3 + float")
    {
        v0->SetConstType(vop::node::Constant::Type::ConstFloat3);
        v0->SetConstValue(dag::Variable(sm::vec3(.1f, .2f, .3f)));

        v1->SetConstType(vop::node::Constant::Type::ConstFloat);
        v1->SetConstValue(dag::Variable(1.1f));

        test::check_value_approx(add->Eval(0), dag::Variable(sm::vec3(1.2f, 1.3f, 1.4f)));
    }
}

TEST_CASE("multiply")
{
    test::init();

    vop::Evaluator eval;

    auto v0 = std::make_shared<vop::node::Constant>();
    eval.AddNode(v0);

    auto v1 = std::make_shared<vop::node::Constant>();
    eval.AddNode(v1);

    auto mul = std::make_shared<vop::node::Multiply>();
    eval.AddNode(mul);

    eval.Connect({ v0, 0 }, { mul, 0 });
    eval.Connect({ v1, 0 }, { mul, 1 });

    SECTION("int * int")
    {
        v0->SetConstType(vop::node::Constant::Type::ConstInteger);
        v0->SetConstValue(dag::Variable(2));

        v1->SetConstType(vop::node::Constant::Type::ConstInteger);
        v1->SetConstValue(dag::Variable(3));

        test::check_value_approx(mul->Eval(0), dag::Variable(6));
    }

    SECTION("float * float")
    {
        v0->SetConstType(vop::node::Constant::Type::ConstFloat);
        v0->SetConstValue(dag::Variable(1.1f));

        v1->SetConstType(vop::node::Constant::Type::ConstFloat);
        v1->SetConstValue(dag::Variable(2.2f));

        test::check_value_approx(mul->Eval(0), dag::Variable(2.42f));
    }

    SECTION("float * float3")
    {
        v0->SetConstType(vop::node::Constant::Type::ConstFloat);
        v0->SetConstValue(dag::Variable(1.1f));

        v1->SetConstType(vop::node::Constant::Type::ConstFloat3);
        v1->SetConstValue(dag::Variable(sm::vec3(.1f, .2f, .3f)));

        test::check_value_approx(mul->Eval(0), dag::Variable(sm::vec3(.11f, .22f, .33f)));
    }

    SECTION("float3 * float")
    {
        v0->SetConstType(vop::node::Constant::Type::ConstFloat3);
        v0->SetConstValue(dag::Variable(sm::vec3(.1f, .2f, .3f)));

        v1->SetConstType(vop::node::Constant::Type::ConstFloat);
        v1->SetConstValue(dag::Variable(1.1f));

        test::check_value_approx(mul->Eval(0), dag::Variable(sm::vec3(.11f, .22f, .33f)));
    }
}