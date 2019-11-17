#pragma once

#include "vop/VariableType.h"

#include <string>

namespace vop
{

struct Variable
{
    VariableType type;
    std::string  name;

}; // Variable

}