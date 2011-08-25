#include "src/VariantTypeUInt64.hpp"

namespace Utilities{namespace Variant{ namespace internal{

VariantTypeUInt64::VariantTypeUInt64(const uint64_t& ai_value)
: m_value (ai_value)
{
}

VariantTypeUInt64::~VariantTypeUInt64(void)
{
}

VariantTypeUInt64::VariantTypeUInt64(VariantTypeUInt64 const& ai_rhs)
: m_value(ai_rhs.m_value)
{
}

uint64_t VariantTypeUInt64::GetValue(void) const
{
  return m_value;
}

void VariantTypeUInt64::SetValue(const uint64_t& ai_value)
{
  m_value = ai_value;
}


}}}
