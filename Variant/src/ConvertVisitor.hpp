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


      template <typename Visitor, typename VisitedList, typename Invoket>
      void visits(Visitor& ai_visitor, const VisitedList&, const Invoker&)
      {
        ai_visitor.m_table = GetStaticVtable<Visitor,VisitedList,Invoker>();
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
