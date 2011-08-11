#ifndef __UTILITIES_VARIANT_INTERNAL_CONVERTERVISITOR_HPP__
#define __UTILITIES_VARIANT_INTERNAL_CONVERTERVISITOR_HPP__

#include "ConvertVisitor.hpp"
#include <CooperativeVisitor/Visitor.hpp>

namespace Utilities
{
  namespace Variant
  {
    namespace internal
    {
      class ConvertToUInt8Visitor : public Utilities::DesignPatterns::CooperativeVisitor::Visitor<VariantType,uint8_t>,
                                    public ConvertVisitor
      {
      public:
        ConvertToUInt8Visitor(void);
        virtual ~ConvertToUInt8Visitor(void);


        //visit methods
        uint8_t Convert(VariantTypeUInt8& ai_data);
        uint8_t Convert(VariantTypeUInt16& ai_data);
        uint8_t Convert(VariantTypeUInt32& ai_data);
        uint8_t Convert(VariantTypeUInt64& ai_data);

        uint8_t Convert(VariantTypeInt8& ai_data);
        uint8_t Convert(VariantTypeInt16& ai_data);
        uint8_t Convert(VariantTypeInt32& ai_data);
        uint8_t Convert(VariantTypeInt64& ai_data);

        IS_CONVERT_VISITOR();

        //Invoker
        typedef VISIT_INVOKER (Convert) ConvertInvoker;
      };

    }
  }
}


#endif /// __UTILITIES_VARIANT_INTERNAL_CONVERTERVISITOR_HPP__
