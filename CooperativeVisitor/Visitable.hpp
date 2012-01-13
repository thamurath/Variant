#ifndef VISITABLE_H
#define VISITABLE_H

#include "Tags.hpp"//#include "src/Tags.hpp"


namespace Utilities
{
  namespace DesignPatterns
  {
    namespace CooperativeVisitor
    {

      template <typename Base>
      class Visitable
      {
      public:
        Visitable(void){}
        virtual ~Visitable(void){}

        template < typename VisitableType>
        static size_t GetTagHelper(const VisitableType*)
        {
          return internal::GetTag<VisitableType,Base>();
        }
      private:
        Visitable(const Visitable& rhs);
        Visitable& operator=(const Visitable& rhs);
      };
    }
  }
}


#define IS_VISITABLE()                                                  \
virtual size_t Tag(void) const                                          \
{                                                                       \
  return Utilities::DesignPatterns::CooperativeVisitor::Visitable::GetTagHelper(this); \
}

#endif // VISITABLE_H
