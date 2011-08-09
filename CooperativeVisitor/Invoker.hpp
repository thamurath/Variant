#ifndef __COOPERATIVE_VISITOR_INVOKER_H__
#define __COOPERATIVE_VISITOR_INVOKER_H__

#include "CompileTimeTools/CompileTimeMemberMethodChecker.hpp"



#define VISIT_INVOKER( MethodName )                                     \
struct                                                                  \
{                                                                       \
  CREATE_COMPILE_TIME_MEMBER_METHOD_CHECKER(MethodName,CheckHas##MethodName); \
  template < typename VisitorImpl, typename Visitable>                  \
  static void Invoke(VisitorImpl& visitor, Visitable& visitable)        \
  {                                                                     \
    CheckHas##MethodName<VisitorImpl,Visitable&,void>::Check();         \
    visitor.MethodName(visitable);                                      \
  }                                                                     \
}



/* Usage:
 class Shape : public Utilities::DesignPatters::CooperativeVisitor::Visitable<Shape>
 {
 public:

 IS_VISITABLE();

 };
 class ShapeRenderer : public Utilities::DesignPatters::CooperativeVisitor::Visitor <Shape>
 {
public:
    //"visit" methods
   void render (  Shape& )
   {
     // render any shape (degenerated case )
   }

   void render (  Circle&)
   {
     // render a circle
   }

   typedef VISIT_INVOKER(render) RenderInvoker;
 };*/
#endif //__COOPERATIVE_VISITOR_INVOKER_H__
