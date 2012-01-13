#include "VariantExceptions.hpp"

#include "ConvertToUInt32Visitor.hpp"

#include "VariantTypeUInt32.hpp"
#include "VariantTypeUInt64.hpp"

#include <stdint.h>
//#include <inttypes.h>
#include <limits>
namespace Utilities
{
  namespace Variant
  {
    uint32_t ConvertToUInt32Visitor::Convert(internal::VariantTypeUInt32& ai_data)
    {
       ai_data.GetValue();
    }

    uint32_t ConvertToUInt32Visitor::Convert(internal::VariantTypeUInt64& ai_data)
    {
      if ( std::numeric_limits<uint32_t>::max() < ai_data.GetValue() )
      //if ( UINT32_MAX < ai_data.GetValue())
      {
        //ERROR Truncated value
        throw Exceptions::TruncatedValueException();
      }
      else
      {
         static_cast<uint32_t>(ai_data.GetValue());
      }
    }
  }
}


