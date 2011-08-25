#include "VariantExceptions.hpp"

#include "src/ConvertToUInt32Visitor.hpp"

#include "src/VariantTypeUInt32.hpp"
#include "src/VariantTypeUInt64.hpp"

#include <stdint>

namespace Utilities
{
  namespace Variant
  {
    uint32_t ConvertToUInt32Visitor::Convert(internal::VariantTypeUInt32& ai_data)
    {
      return ai_data.GetValue();
    }

    uint32_t ConvertToUInt32Visitor::Convert(internal::VariantTypeUInt64& ai_data)
    {
      if ( UINT32_MAX < ai_data.GetValue())
      {
        //ERROR Truncated value
        throw Exceptions::TruncatedValue();
      }
      else
      {
        return static_cast<uint32_t>(ai_data.GetValue());
      }
    }
  }
}


