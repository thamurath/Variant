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


    /// TypeList utilities

    /** @brief Get the index of a type in a typelist
     *
     *  @param List TypeList with the items
     *  @param Type Type to search for.
     *
     *  @return value The index of Type or -1 if not found
     **/
    template <typename List, typename Type>
    struct IndexOf;


    /// Not found overload
    template <typename T>
    struct IndexOf<NullType,T>
    {
      enum {value = -1};
    };

    /// Overload when the type to look for is the first one in the list
    template <typename Tail, Typename T>
    struct IndexOf<TypeList<T,Tail>,T>
    {
      enum {value = 0};
    };

    /// General overload
    template <typename Head, typename Tail, typename T>
    struct IndexOf<TypeList<Head,Tail>,T>
    {
      ///@note when here we know that the list is not empty ( if so the best overload had been the NUllType one),
      /// and that the Head type is not the one we are looking for
    private:
      /// First we look for the item in the rest of the list
      enum { temp = IndexOf<Tail,T>::value};

    public:
      /// If the type is not found in the rest of the list (Tail) it should be in the second position
      /// (remember that we have an overload for the case the type where in the fisrt position) so
      /// the return value is 1
      /// Otherwise if the type is found in the rest of the list we have to add 1 to the returned position.
      enum { value = (-1 == temp)?(1):(1 + temp)};

    };

    /// Type to type conversion this is handy when need to overload some funcionts
    template<typename T>
    struct Type2Type
    {
      typedef T OriginalType;
    };




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
