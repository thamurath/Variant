#ifndef __UTILITIES_VARIANT_CONVERTVISITOR_HPP_INCLUDED__
#define __UTILITIES_VARIANT_CONVERTVISITOR_HPP_INCLUDED__

#include <exception>
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
        throw std::exception("ConvertVisitor::operator() ");
      }
    protected:
    };
  }
}


#endif // __UTILITIES_VARIANT_CONVERTVISITOR_HPP_INCLUDED__
