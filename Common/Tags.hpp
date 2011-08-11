#ifndef __UTILITIES_DESIGNPATTERNS_COOPERATIVEVISITOR_INTERNAL_TAGS_HPP__
#define __UTILITIES_DESIGNPATTERNS_COOPERATIVEVISITOR_INTERNAL_TAGS_HPP__

#include <cstdlib>
#include <iostream>
#include <typeinfo>


namespace Utilities
{
  namespace DesignPatterns
  {
    namespace CooperativeVisitor
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


        template <typename Visitable, typename Base>
        struct TagHolder
        {
          static size_t s_tag;
        };


        template <typename Visitable,typename Base>
        size_t GetTag(void)
        {
          // std::cout << "GetTag<" << typeid(Visitable).name() <<","
          //           << typeid(Base).name() <<">" << std::endl;
          size_t& tag = TagHolder<const Visitable,const Base>::s_tag;
          if ( 0 == tag)
          {
            tag = ++TagCounter<const Base>::s_counter;
          }
          return tag;
        }

        template<typename Visitable, typename Base>
        size_t TagHolder<Visitable,Base>::s_tag = GetTag<Visitable,Base>();
      }
    }
  }
}


#endif //__UTILITIES_DESIGNPATTERNS_COOPERATIVEVISITOR_INTERNAL_TAGS_HPP__
