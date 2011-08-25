#ifndef __UTILITIES_VARIANT_INTERNAL_VARIANT_TYPE_BASE_HPP__
#define __UTILITIES_VARIANT_INTERNAL_VARIANT_TYPE_BASE_HPP__


#include <CooperativeVisitor/Visitable.hpp>


namespace Utilities
{
  namespace Variant
  {
    namespace internal
    {

      class VariantTypeBase : public Utilities::DesignPatterns::CooperativeVisitor::Visitable<VariantTypeBase>
      {
      public:
        VariantTypeBase(){}
        virtual ~VariantTypeBase(){}

        //Clone-idiom to allow polymofphic copy construction.
        virtual VariantTypeBase* Clone(void) = 0;

        IS_VISITABLE();

      };

      template <typename Derived>
      class VariantTypeBaseClonable : public VariantTypeBase
      {
      public:
        virtual VariantTypeBase* Clone(void)
        {
          // Call copy constructor
          return new Derived(static_cast<Derived const&>(*this));
        }
      };
    }
  }
}




#endif //__UTILITIES_VARIANT_INTERNAL_VARIANT_TYPE_BASE_HPP__
