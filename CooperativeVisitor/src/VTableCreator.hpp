#ifndef __UTILITIES_DESIGNPATTERNS_COOPERATIVEVISITOR_VTABLE_CREATOR_HPP__
#define __UTILITIES_DESIGNPATTERNS_COOPERATIVEVISITOR_VTABLE_CREATOR_HPP__

#include "VTable.hpp"
#include "TypeLists/TypeListAlgorithms.hpp"


namespace Utilities
{
  namespace DesignPatterns
  {
    namespace CooperativeVisitor
    {
      namespace internal
      {
        template <typename Visitor, typename VisitedList, typename Invoker>
        struct CreateVTable
        {
          typename Visitor::VTable_t m_vtable;

          template < typename Visitable>
          void operator() (/*const*/Visitable*)
          {
            m_vtable.template add<Visitable>(&Visitor::template Thunk<Visitor,Visitable,Invoker>);
          }

          CreateVTable(void)
          {
            // primero ponermos la funcion de visit de la clase base en la tabla.(operator())

            (*this) (static_cast<typename Visitor::Base_t*>(0) );

            // Ahora aplicamos lo mismo a cada uno de los tipos de la lista
            TypeLists::Algorithms::Apply(*this,VisitedList());
          }
        };


        template< typename Visitor, typename VisitedList, typename Invoker>
        struct GetStaticVtable
        {
          // declare static instance of vtable
          static CreateVTable<Visitor, VisitedList, Invoker> s_vtable;

          //conversion operator
          operator /*const*/ typename Visitor::VTable_t*() /*const*/
          {
            return &(s_vtable.m_vtable);
          }
        };

        template < typename Visitor, typename VisitedList, typename Invoker>
        CreateVTable<Visitor,VisitedList,Invoker>  GetStaticVtable<Visitor,VisitedList,Invoker>::s_vtable;

        //global helper function
        template <typename Visitor, typename VisitedList, typename Invoker>
        void visits(Visitor& ai_visitor, const VisitedList&, const Invoker&)
        {
          //instanciar la variable statica vtable y hacer el set del puntero a vtable
          ai_visitor.m_vtable = GetStaticVtable<Visitor,VisitedList, Invoker>();
        }
      }
    }
  }
}


#endif //__UTILITIES_DESIGNPATTERNS_COOPERATIVEVISITOR_VTABLE_CREATOR_HPP__
