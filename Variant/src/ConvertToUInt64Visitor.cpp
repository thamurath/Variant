#include "src/ConvertToUInt64Visitor.hpp"

#include "src/VariantTypeUIn32.hpp"

namespace Utilities
{
  namespace Variant
  {
    uint64_t ConvertToUInt64Visitor::Convert(internal::VariantTypeUInt32& ai_data)
    {
      return static_cast<uint64_t>(ai_data.GetValue());
    }

    uint64_t ConvertToUInt64Visitor::Convert(internal::VariantTypeUInt64& ai_data)
    {
      return ai_data.GetValue();
    }
  }
}


