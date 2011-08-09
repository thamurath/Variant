#ifndef __COOPERATIVE_VISITOR_TEST_POLY_HPP__
#define __COOPERATIVE_VISITOR_TEST_POLY_HPP__

#include "Shape.hpp"

class Poly: public Shape
{
public:
  Poly(void);
  virtual ~Poly(void);

  Poly(const Poly&);

  IS_VISITABLE();
};


#endif // __COOPERATIVE_VISITOR_TEST_POLY_HPP__
