#ifndef __UTILITIES_VARIANT_INTERNAL_VARIANTUINT32_HPP__
#define __UTILITIES_VARIANT_INTERNAL_VARIANTUINT32_HPP__


#include "VariantTypeBase.hpp"
namespace Utilities
{
  namespace Variant
  {
    namespce internal
    {
      class VariantTypeUInt32 : public VariantTypeBase
      {
      public:
        VariantTypeUInt32(const uint32_t& ai_value=0);
        virtual ~VariantTypeUInt32(void);

        uint32_t GetValue(void) const;
        void SetValue(const uint32_t& ai_value);

      private:
        uint32_t m_value;
      };
    }
  }
}




#endif // __UTILITIES_VARIANT_INTERNAL_VARIANTUINT32_HPP__
