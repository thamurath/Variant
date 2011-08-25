#ifndef __UTILITIES_VARIANT_INTERNAL_VARIANTUINT64_HPP__
#define __UTILITIES_VARIANT_INTERNAL_VARIANTUINT64_HPP__


#include "src/VariantTypeBase.hpp"
namespace Utilities
{
  namespace Variant
  {
    namespace internal
    {
      class VariantTypeUInt64 : public VariantTypeBaseClonable
      {
      public:
        VariantTypeUInt64(const uint64_t& ai_value=0);
        virtual ~VariantTypeUInt64(void);


        VariantTypeUInt64(VariantTypeUInt64 const& ai_rhs;

        uint64_t GetValue(void) const;
        void SetValue(const uint64_t& ai_value);



        IS_VISITABLE();

      private:
        uint64_t m_value;
      };
    }
  }
}




#endif // __UTILITIES_VARIANT_INTERNAL_VARIANTUINT32_HPP__
