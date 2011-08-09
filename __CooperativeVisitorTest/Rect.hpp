#ifndef __COOPERATIVE_VISITOR_TEST_RECT_HPP__
#define __COOPERATIVE_VISITOR_TEST_RECT_HPP__

#include "Shape.hpp"

class Rect : public Shape
{
public:
  Rect(void);
  virtual ~Rect(void);

  Rect(const Rect&);

  IS_VISITABLE();
};


#endif // __COOPERATIVE_VISITOR_TEST_RECT_HPP__
