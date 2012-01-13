#ifndef __UTILITIES_DESIGNPATTERNS_COOPERATIVEVISITOR_VISITOR_HPP__
#define __UTILITIES_DESIGNPATTERNS_COOPERATIVEVISITOR_VISITOR_HPP__


///@todo Maybe this Invoker.hpp file should be in the src folder and be implicitly included by Visitor.hpp
/// so the user has just to include Visitor.hpp
#include "VTable.hpp"//#include "src/VTable.hpp"

#include "VTableCreator.hpp"//#include "src/VTableCreator.hpp"
#include "Invoker.hpp"




namespace Utilities
{
  namespace DesignPatterns
  {
    namespace CooperativeVisitor
    {
      template
      <
        typename Base,
        typename ReturnType
       >
      class Visitor
      {

        typedef ReturnType (Visitor::*Func_t) (Base& b);
      public:
        typedef Base Base_t;

        Visitor(void){}
        virtual ~Visitor(void){}

        template <typename VisitorImpl, typename Visitable,typename Invoker>
        ReturnType Thunk (Base& b)
        {
          VisitorImpl& visitor = static_cast<VisitorImpl&>(*this);
          Visitable& visitable = static_cast<Visitable&>(b);

          ///@todo solve problems with void and return clause
           Invoker::Invoke(visitor, visitable);//return  Invoker::Invoke(visitor, visitable);
        }


        ReturnType operator() (Base& b)
        {
          Func_t thunk((*m_vtable)[b.Tag()]); // tomamos la funcion relacionada con la clase.
          if (0 != thunk)
          {
            return (this->*thunk) (b); // y la llamamos para que comience el proceso de visitacion.
          }
          return (ReturnType)0;
        }

        typedef internal::VTable<const Base, Func_t> VTable_t;
        const VTable_t* m_vtable;

        //global helper function
        ///@note call this methos before any visitation
        template <typename Visitor, typename VisitedList, typename Invoker>
        void CreateVirtualTable(Visitor& ai_visitor, const VisitedList&, const Invoker&)
        {
          //instanciar la variable statica vtable y hacer el set del puntero a vtable
          ai_visitor.m_vtable = Utilities::DesignPatterns::CooperativeVisitor::internal::GetStaticVtable<Visitor,VisitedList, Invoker>();
          //ai_visitor.m_vtable = internal::GetStaticVtable<Visitor,VisitedList, Invoker>();
        }
      private:

        Visitor(const Visitor& rhs);
        Visitor& operator=(const Visitor& rhs);

      };
    }
  }
}


#endif // __UTILITIES_DESIGNPATTERNS_COOPERATIVEVISITOR_VISITOR_HPP__
