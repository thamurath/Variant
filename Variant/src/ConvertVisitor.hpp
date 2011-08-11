#ifndef __UTILITIES_VARIANT_INTERNAL_CONVERTVISITOR_HPP__
#define __UTILITIES_VARIANT_INTERNAL_CONVERTVISITOR_HPP__


#include <Common/Tags.hpp>

namespace Utilities
{
  namespace Variant
  {
    namespace internal
    {
      class ConvertVisitor
      {
      public:
        ConvertVisitor(void)
        {

        }
        virtual ~ConvertVisitor()
        {

        }

        template <class ConcreteVisitor>
        static size_t GetIdHelper(const ConcreteVisitor* )
        {
          return ::Base::GetTag<ConvertVisitor,ConvertVisitor>();
        }

      };


#define IS_CONVERT_VISITOR()                                            \
      virtual size_t GetId(void) const                                  \
      {                                                                 \
        return ::Utilities::Variant::internal::ConvertVisitor::GetIdHelper(this); \
      }

    }
  }
}


#endif /// __UTILITIES_VARIANT_INTERNAL_CONVERTVISITOR_HPP__
