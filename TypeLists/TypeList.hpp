#ifndef __UTILITIES_TYPELISTS_TYPELIST_HPP__
#define __UTILITIES_TYPELISTS_TYPELIST_HPP__

namespace Utilities
{
  namespace TypeLists
  {
    template < class T, class U>
    struct TypeList
    {
      typedef T Head;
      typedef U Tail;
    };

    class NullType{};

    struct EmptyType{};

  }
}

#define TYPELIST_1(T1) Utilities::TypeLists::TypeList<T1, Utilities::TypeLists::NullType>
#define TYPELIST_2(T1, T2) Utilities::TypeLists::TypeList<T1, TYPELIST_1(T2) >
#define TYPELIST_3(T1, T2, T3) Utilities::TypeLists::TypeList<T1, TYPELIST_2(T2, T3) >
#define TYPELIST_4(T1, T2, T3, T4) Utilities::TypeLists::TypeList<T1, TYPELIST_3(T2, T3, T4) >
#define TYPELIST_5(T1, T2, T3, T4, T5) Utilities::TypeLists::TypeList<T1, TYPELIST_4(T2, T3, T4, T5) >
#define TYPELIST_6(T1, T2, T3, T4, T5, T6) Utilities::TypeLists::TypeList<T1, TYPELIST_5(T2, T3, T4, T5, T6) >
#define TYPELIST_7(T1, T2, T3, T4, T5, T6, T7) Utilities::TypeLists::TypeList<T1, TYPELIST_6(T2, T3, T4, T5, T6, T7) >
#define TYPELIST_8(T1, T2, T3, T4, T5, T6, T7, T8) Utilities::TypeLists::TypeList<T1, TYPELIST_7(T2, T3, T4, T5, T6, T7, T8) >
#define TYPELIST_9(T1, T2, T3, T4, T5, T6, T7, T8, T9) Utilities::TypeLists::TypeList<T1, TYPELIST_8(T2, T3, T4, T5, T6, T7, T8, T9) >

#endif //__UTILITIES_TYPELISTS_TYPELIST_HPP__
