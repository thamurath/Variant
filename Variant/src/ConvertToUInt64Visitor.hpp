#ifndef __UTILITIES_VARIANT_CONVERTTOUINT64VISITOR_HPP_INCLUDED__
#define __UTILITIES_VARIANT_CONVERTTOUINT64VISITOR_HPP_INCLUDED__

#include "src/ConvertVisitor.hpp"

#include <CooperativeVisitor/Visitor.hpp>
#include <TypeLists/TypeList.hpp>

namespace Utilities
{
  namespace Variant
  {
    namespace internal
    {
      class VariantTypeUInt32;
      class VariantTypeUInt64;
    }



    class ConvertToUInt64Visitor : public ConvertVisitor,
                                    public Utilities::DesignPatterns::CooperativeVisitor::Visitor < VariantTypeBase,uint64_t>
    {
    private:

      typedef TYPELIST_2(internal::VariantTypeUInt32,internal::VariantTypeUInt64) VisitedTypes_t;

    public:
      typedef VISIT_INVOKER(Convert) ConvertToUInt64Invoker;

      ConvertToUInt64Visitor(void)
      {
        // creates the "vtable" to be able to visit all types included in VisitedTypes_t list
        visits(*this,VisitedTypes_t(),ConvertToUInt64Invoker());
      }

      //visit methods
      uint64_t Convert(internal::VariantTypeUInt32& ai_data);
      uint64_t Convert(internal::VariantTypeUInt64& ai_data);



    protected:
    private:

    };
  }
}

#endif // __UTILITIES_VARIANT_CONVERTTOUINT64VISITOR_HPP_INCLUDED__
