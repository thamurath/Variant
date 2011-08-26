#ifndef __UTILITIES_VARIANT_CONVERTVISITOR_HPP_INCLUDED__
#define __UTILITIES_VARIANT_CONVERTVISITOR_HPP_INCLUDED__

#include "VariantExceptions.hpp"

namespace Utilities
{
  namespace Variant
  {
    class ConvertVisitor
    {
    public:
      virtual ~ConvertVisitor(void)
      {
        //nothing to do
      }

      void operator()(void)
      {
        throw Exceptions::ConvertException("ConvertVisitor::operator() ");
      }
    protected:
    };
  }
}


#endif // __UTILITIES_VARIANT_CONVERTVISITOR_HPP_INCLUDED__
