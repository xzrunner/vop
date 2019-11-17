#include "vop/VOP.h"

namespace vop
{

CU_SINGLETON_DEFINITION(VOP);

extern void regist_rttr();

VOP::VOP()
{
	regist_rttr();
}

}