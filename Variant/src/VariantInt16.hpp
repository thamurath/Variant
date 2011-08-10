#ifndef __UTILITIES_VARIANT_INTERNAL_VARIANTINT16_HPP__
#define __UTILITIES_VARIANT_INTERNAL_VARIANTINT16_HPP__


#include "VariantTypeBase.hpp"
namespace Utilities
{
  namespace Variant
  {
    namespce internal
    {
      class VariantTypeInt16 : public VariantTypeBase
      {
      public:
        VariantTypeInt16(const int16_t& ai_value=0);
        virtual ~VariantTypeInt16(void);

        int16_t GetValue(void) const;
        void SetValue(const int16_t& ai_value);

      private:
        int16_t m_value;
      };
    }
  }
}




#endif // __UTILITIES_VARIANT_INTERNAL_VARIANTINT16_HPP__
