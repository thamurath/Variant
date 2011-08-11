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

        IS_VISITABLE();

      };
    }
  }
}




#endif //__UTILITIES_VARIANT_INTERNAL_VARIANT_TYPE_BASE_HPP__
