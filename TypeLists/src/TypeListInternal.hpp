#ifndef __COOPERATIVE_VISITOR_TYPELIST_INTERNAL_H__
#define __COOPERATIVE_VISITOR_TYPELIST_INTERNAL_H__

#include "TypeList.hpp"

namespace Utilities
{
  namespace TypeLists
  {
    namespace Algorithms
    {
      namespace internal
      {
        template <typename Func, typename Typelist>
        struct apply_;

        template <typename Func, typename Head, typename Tail>
        struct apply_<Func,TypeList<Head,Tail> >
        {
          void operator() (Func& ai_func)
          {
            Head h;
            ai_func.operator()(&h);
            apply_<Func,Tail> next;
            next(ai_func);
          }
        };

        template<typename Func>
        struct apply_ <Func, NullType>
        {
          void operator() (Func&)
          {

          }
        };
      }// namespace internal
    } // namespace Algorithms
  } // namespace TypeLists
} // namespace Utilities


#endif //__COOPERATIVE_VISITOR_TYPELIST_INTERNAL_H__
