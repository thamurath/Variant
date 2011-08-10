#ifndef __UTILITIES_VARIANT_INTERNAL_VARIANTUINT8_HPP__
#define __UTILITIES_VARIANT_INTERNAL_VARIANTUINT8_HPP__


#include "VariantTypeBase.hpp"
namespace Utilities
{
  namespace Variant
  {
    namespce internal
    {
      class VariantTypeUInt8 : public VariantTypeBase
      {
      public:
        VariantTypeUInt8(const uint8_t& ai_value=0);
        virtual ~VariantTypeUInt8(void);

        uint8_t GetValue(void) const;
        void SetValue(const uint8_t& ai_value);

      private:
        uint8_t m_value;
      };
    }
  }
}




#endif // __UTILITIES_VARIANT_INTERNAL_VARIANTUINT32_HPP__