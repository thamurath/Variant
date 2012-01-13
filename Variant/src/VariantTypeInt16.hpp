#ifndef __UTILITIES_VARIANT_INTERNAL_VARIANTINT16_HPP__
#define __UTILITIES_VARIANT_INTERNAL_VARIANTINT16_HPP__


#include "VariantTypeBase.hpp"//#include "src/VariantTypeBase.hpp"
namespace Utilities
{
  namespace Variant
  {
    namespace internal
    {
      class VariantTypeInt16 : public VariantTypeBase
      {
      public:
        VariantTypeInt16(const int16_t& ai_value=0);
        virtual ~VariantTypeInt16(void);

        VariantTypeInt16(VariantTypeInt16 const& ai_rhs );

        int16_t GetValue(void) const;
        void SetValue(const int16_t& ai_value);

        IS_VISITABLE();

      private:
        int16_t m_value;
      };
    }
  }
}




#endif // __UTILITIES_VARIANT_INTERNAL_VARIANTINT16_HPP__
