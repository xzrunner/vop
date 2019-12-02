#pragma once

#include <hdiop/Variable.h>

namespace test
{

void init();

void check_value_approx(const hdiop::Variable& v0, const hdiop::Variable& v1);

}