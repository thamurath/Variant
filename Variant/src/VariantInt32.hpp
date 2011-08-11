#ifndef __UTILITIES_VARIANT_INTERNAL_VARIANTINT32_HPP__
#define __UTILITIES_VARIANT_INTERNAL_VARIANTINT32_HPP__


#include "VariantTypeBase.hpp"
namespace Utilities
{
  namespace Variant
  {
    namespce internal
    {
      class VariantTypeInt32 : public VariantTypeBase
      {
      public:
        VariantTypeInt32(const int32_t& ai_value=0);
        virtual ~VariantTypeInt32(void);

        int32_t GetValue(void) const;
        void SetValue(const int32_t& ai_value);

        IS_VISITABLE();

      private:
        int32_t m_value;
      };
    }
  }
}




#endif // __UTILITIES_VARIANT_INTERNAL_VARIANTINT32_HPP__
