#ifndef __UTILITIES_TYPELISTS_ALGORITHMS_HPP__
#define __UTILITIES_TYPELISTS_ALGORITHMS_HPP__


#include "TypeList.hpp"
#include "src/TypeListInternal.hpp"

namespace Utilities
{
  namespace TypeLists
  {
    namespace Algorithms
    {
      template < typename Func, typename Typelist>
      void Apply(Func& ai_func, Typelist)
      {
        internal::apply_<Func,Typelist> a;
        a(ai_func);
      }
    }
  }
}

#endif //__UTILITIES_TYPELISTS_ALGORITHMS_HPP__
