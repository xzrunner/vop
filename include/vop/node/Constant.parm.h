#ifndef PARAM_INFO
#error "You must define PARAM_INFO macro before include this file"
#endif

PARAM_INFO(ConstType,  Constant::Type,  consttype,  m_const_type,  (Constant::Type::ConstFloat))
PARAM_INFO(ConstValue, dag::Variable, constvalue, m_const_value, ())
PARAM_INFO(ConstName,  std::string,          constname,  m_const_name,  ())
