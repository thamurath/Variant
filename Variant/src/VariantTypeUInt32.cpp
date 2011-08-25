#include "src/VariantTypeUInt32.hpp"


namespace Utilities{namespace Variant{ namespace internal{

VariantTypeUInt32::VariantTypeUInt32(const uint32_t& ai_value)
: m_value (ai_value)
{
}

VariantTypeUInt32::~VariantTypeUInt32(void)
{
}

VariantTypeUInt32::VariantTypeUInt32(VariantTypeUInt32 const& ai_rhs)
: m_value(ai_rhs.m_value)
{
}

uint32_t VariantTypeUInt32::GetValue(void) const
{
  return m_value;
}

void VariantTypeUInt32::SetValue(const uint32_t& ai_value)
{
  m_value = ai_value;
}


}}}
