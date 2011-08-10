#ifndef __UTILITIES_VARIANT_INTERNAL_VARIANTINTEGRALTYPE_HPP__
#define __UTILITIES_VARIANT_INTERNAL_VARIANTINTEGRALTYPE_HPP__

#include "VariantTypeBase.hpp"
namespace Utilities
{
  namespace Variant
  {
    namespce internal
    {
      template <typename T>
      class VariantIntegralType : public VariantTypeBase
      {
      public:
        VariantIntegralType(const T& ai_value=T());
        virtual ~VariantIntegralType(void);

        T Value(void) const;
        void Value(const T& ai_value);


        IS_VISITABLE();
      private:
        T m_value;
      };
    }
  }
}



#endif //__UTILITIES_VARIANT_INTERNAL_VARIANTINTEGRALTYPE_HPP__
