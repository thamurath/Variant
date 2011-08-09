#ifndef __COOPERATIVE_VISITOR_TEST_ANOTHER_SHAPE_HPP__
#define __COOPERATIVE_VISITOR_TEST_ANOTHER_SHAPE_HPP__

#include "Shape.hpp"

class AnotherShape : public Shape
{
public:
  AnotherShape(void);
  virtual ~AnotherShape(void);

  AnotherShape(AnotherShape&);

  IS_VISITABLE();
};


#endif //__COOPERATIVE_VISITOR_TEST_ANOTHER_SHAPE_HPP__
