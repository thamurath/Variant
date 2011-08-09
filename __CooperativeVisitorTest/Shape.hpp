#ifndef __COOPERATIVE_VISITOR_TEST_SHAPE_HPP__
#define __COOPERATIVE_VISITOR_TEST_SHAPE_HPP__

#include <CooperativeVisitor/Visitable.hpp>

class Shape : public Utilities::DesignPatterns::CooperativeVisitor::Visitable<Shape>
{
public:
  Shape(void);
  virtual ~Shape(void);
  Shape(const Shape&);

  IS_VISITABLE();
};




#endif //__COOPERATIVE_VISITOR_TEST_SHAPE_HPP__
