#ifndef __COOPERATIVE_VISITOR_TEST_SQUARE_HPP__
#define __COOPERATIVE_VISITOR_TEST_SQUARE_HPP__

#include "Shape.hpp"

class Square : public Shape
{
public:
  Square(void);
  virtual ~Square(void);

  Square(const Square&);

  IS_VISITABLE();
};


#endif // __COOPERATIVE_VISITOR_TEST_SQUARE_HPP__
