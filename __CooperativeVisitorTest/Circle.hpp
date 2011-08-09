#ifndef __COOPERATIVE_VISITOR_TEST_CIRCLE_HPP__
#define __COOPERATIVE_VISITOR_TEST_CIRCLE_HPP__

#include "Shape.hpp"

class Circle : public Shape
{
public:
  Circle(void);
  virtual ~Circle(void);

  Circle(const Circle&);

  IS_VISITABLE();
};


#endif // __COOPERATIVE_VISITOR_TEST_CIRCLE_HPP__
