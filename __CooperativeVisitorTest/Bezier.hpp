#ifndef __COOPERATIVE_VISITOR_TEST_BEZIER_HPP__
#define __COOPERATIVE_VISITOR_TEST_BEZIER_HPP__

#include "Shape.hpp"

class Bezier : public Shape
{
public:
  Bezier(void);
  virtual ~Bezier(void);

  Bezier(const Bezier&);

  IS_VISITABLE();
};


#endif //__COOPERATIVE_VISITOR_TEST_BEZIER_HPP__
