#ifndef __COOPERATIVE_VISITOR_EXAMPLE_VISITOR_RENDERER_H__
#define __COOPERATIVE_VISITOR_EXAMPLE_VISITOR_RENDERER_H__


#include <CooperativeVisitor/Visitor.hpp>
#include <TypeLists/TypeList.hpp>

// #include "Invoker.h"
// #include "VTableCreator.h"




class Renderer : public Utilities::DesignPatterns::CooperativeVisitor::Visitor<Shape, void>
{

  typedef TYPELIST_7(Square,Bezier,Circle,AnotherShape,Rect,Poly,Shape) CurvedShapes;


public:

  //visit methods.
  void draw(Shape&);
  void draw(AnotherShape&);
  void draw(Bezier&);
  void draw(Circle&);
  void draw(Rect&);
  void draw(Square&);
  void draw(Poly&);


  typedef VISIT_INVOKER (draw) RenderInvoker;




  Renderer(const bool& ai_curved)
   {
     visits(*this,CurvedShapes(),RenderInvoker());
   }

};

#endif // __COOPERATIVE_VISITOR_EXAMPLE_VISITOR_RENDERER_H__
