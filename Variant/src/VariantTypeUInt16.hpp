#ifndef __UTILITIES_VARIANT_INTERNAL_VARIANTUINT16_HPP__
#define __UTILITIES_VARIANT_INTERNAL_VARIANTUINT16_HPP__


#include "VariantTypeBase.hpp"
namespace Utilities
{
  namespace Variant
  {
    namespce internal
    {
      class VariantTypeUInt16 : public VariantTypeBase
      {
      public:
        VariantTypeUInt16(const uint16_t& ai_value=0);
        virtual ~VariantTypeUInt16(void);

        uint16_t GetValue(void) const;
        void SetValue(const uint16_t& ai_value);


        IS_VISITABLE();

      private:
        uint16_t m_value;
      };
    }
  }
}




#endif // __UTILITIES_VARIANT_INTERNAL_VARIANTUINT16_HPP__
