#ifndef __UTILITIES_VARIANT_INTERNAL_VARIANTINT64_HPP__
#define __UTILITIES_VARIANT_INTERNAL_VARIANTINT64_HPP__


#include "src/VariantTypeBase.hpp"
namespace Utilities
{
  namespace Variant
  {
    namespace internal
    {
      class VariantTypeInt64 : public VariantTypeBaseClonable
      {
      public:
        VariantTypeInt64(const int64_t& ai_value=0);
        virtual ~VariantTypeInt64(void);

        VariantTypeInt64(VariantTypeInt64 const & ai_rhs);

        int64_t GetValue(void) const;
        void SetValue(const int64_t& ai_value);


        IS_VISITABLE();

      private:
        int64_t m_value;
      };
    }
  }
}




#endif // __UTILITIES_VARIANT_INTERNAL_VARIANTINT32_HPP__
