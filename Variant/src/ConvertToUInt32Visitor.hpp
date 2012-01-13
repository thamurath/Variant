#ifndef __UTILITIES_VARIANT_CONVERTTOUINT32VISITOR_HPP_INCLUDED__
#define __UTILITIES_VARIANT_CONVERTTOUINT32VISITOR_HPP_INCLUDED__

#include "ConvertVisitor.hpp"//#include "src/ConvertVisitor.hpp"


#include <CooperativeVisitor/Visitor.hpp>
#include <TypeLists/TypeList.hpp>

#include "VariantTypeBase.hpp"
#include "VariantTypeUInt32.hpp"
#include "VariantTypeUInt64.hpp"

#include <stdint.h>

namespace Utilities
{
  namespace Variant
  {
    // namespace internal
    // {
    //   class VariantTypeBase;
    //   class VariantTypeUInt32;
    //   class VariantTypeUInt64;
    // }



    class ConvertToUInt32Visitor : public ConvertVisitor,
                                    public Utilities::DesignPatterns::CooperativeVisitor::Visitor <internal::VariantTypeBase,uint32_t>
    {
    private:

      typedef TYPELIST_2(internal::VariantTypeUInt32,internal::VariantTypeUInt64) VisitedTypes_t;

    public:
      typedef VISIT_INVOKER(Convert) ConvertToUInt32Invoker;

      ConvertToUInt32Visitor(void)
      {
        // creates the "vtable" to be able to visit all types included in VisitedTypes_t list
        CreateVirtualTable(*this,VisitedTypes_t(),ConvertToUInt32Invoker());
        
      }

      //visit methods
      uint32_t Convert(internal::VariantTypeUInt32& ai_data);
      uint32_t Convert(internal::VariantTypeUInt64& ai_data);



    protected:
    private:

    };
  }
}

#endif // __UTILITIES_VARIANT_CONVERTTOUINT32VISITOR_HPP_INCLUDED__
