#ifndef __UTILITIES_VARIANT_INTERNAL_VARIANTINT8_HPP__
#define __UTILITIES_VARIANT_INTERNAL_VARIANTINT8_HPP__


#include "VariantTypeBase.hpp"
namespace Utilities
{
  namespace Variant
  {
    namespce internal
    {
      class VariantTypeInt8 : public VariantTypeBase
      {
      public:
        VariantTypeInt8(const int8_t& ai_value=0);
        virtual ~VariantTypeInt8(void);

        int8_t GetValue(void) const;
        void SetValue(const int8_t& ai_value);

      private:
        int8_t m_value;
      };
    }
  }
}




#endif // __UTILITIES_VARIANT_INTERNAL_VARIANTINT8_HPP__
