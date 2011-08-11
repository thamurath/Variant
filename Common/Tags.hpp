#ifndef __COMMON_BASE_INTERNAL_TAGS_HPP__
#define __COMMON_BASE_INTERNAL_TAGS_HPP__

#include <cstdlib>
#include <iostream>
#include <typeinfo>



/**
 * @brief Utility to get a unique number for each of the classes in a hierachy
 *
 * For an example of use @see the Visitable class in CooperativeVisitor Library
 *
 * @todo Change all this file to set the internal namespace in another header and
 * the variable definitions in a source file if possible
 **/
namespace Base
{
  namespace internal
  {
    template<typename Base>
    struct TagCounter
    {
      static size_t s_counter;
    };

    template<typename Base>
    size_t TagCounter<Base>::s_counter = 0;


    template <typename Derived, typename Base>
    struct TagHolder
    {
      static size_t s_tag;
    };

  }

  template <typename Derived,typename Base>
  size_t GetTag(void)
  {
    // std::cout << "GetTag<" << typeid(Derived).name() <<","
    //           << typeid(Base).name() <<">" << std::endl;
    size_t& tag = internal::TagHolder<const Derived,const Base>::s_tag;
    if ( 0 == tag)
    {
      tag = ++(internal::TagCounter<const Base>::s_counter);
    }
    return tag;
  }


  namespace internal
  {
    template<typename Derived, typename Base>
    size_t TagHolder<Derived,Base>::s_tag = GetTag<Derived,Base>();
  }
}



f
#endif //__COMMON_INTERNAL_TAGS_HPP__
