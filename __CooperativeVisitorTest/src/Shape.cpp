#include "Shape.hpp"

#include <iostream>

Shape::Shape(void)
{
//  std::cout << "Shape::Shape(void)"
//		  << " Tag: " << Tag()
//		  << std::endl;
}
Shape::~Shape(void)
{
//  std::cout << "Shape::~Shape(void)" << std::endl;
}

Shape::Shape(const Shape& rhs)
{
//  std::cout << "Shape::Shape(const Shape&)" << std::endl;
}


#include "Square.hpp"

Square::Square(void)
{
  std::cout << "Square::Square(void)"
		  << " Tag: " << Tag()
		  << std::endl;
}
Square::~Square(void)
{
  std::cout << "Square::~Square(void)" << std::endl;
}
Square::Square(const Square& rhs)
{
  std::cout << "Square::Square(const Square&)" << std::endl;
}


#include "Circle.hpp"
Circle::Circle(void)
{
  std::cout << "Circle::Circle(void)"
		  << " Tag: " << Tag()
		  << std::endl;
}
Circle::~Circle(void)
{
  std::cout << "Circle::~Circle(void)" << std::endl;
}
Circle::Circle(const Circle& rhs)
{
 std::cout << "Circle::Circle(const Circle&)" << std::endl;
}


#include "Bezier.hpp"
Bezier::Bezier(void)
{
  std::cout << "Bezier::Bezier(void)"
		  << " Tag: " << Tag()
		  << std::endl;
}
Bezier::~Bezier(void)
{
  std::cout << "Bezier::~Bezier(void)" << std::endl;
}
Bezier::Bezier(const Bezier& rhs)
{
  std::cout << "Bezier::Bezier(const Bezier&)" << std::endl;
}


#include "Rect.hpp"
Rect::Rect(void)
{
  std::cout << "Rect::Rect(void)"
		  << " Tag: " << Tag()
		  << std::endl;
}
Rect::~Rect(void)
{
  std::cout << "Rect::~Rect(void)" << std::endl;
}
Rect::Rect(const Rect& rhs)
{
  std::cout << "Rect::Rect(const Rect&)" << std::endl;
}


#include "Poly.hpp"
Poly::Poly(void)
{
  std::cout << "Poly::Poly(void)"
		  << " Tag: " << Tag()
		  << std::endl;
}
Poly::~Poly(void)
{
  std::cout << "Poly::~Poly(void)" << std::endl;
}
Poly::Poly(const Poly& rhs)
{
  std::cout << "Poly::Poly(const Rect&)" << std::endl;
}

#include "AnotherShape.hpp"
AnotherShape::AnotherShape(void)
{
	std::cout << "AnotherShape::AnotherShape(void)"
			 << " Tag: " << Tag()
			 << std::endl;
}
AnotherShape::~AnotherShape(void)
{
	std::cout << "AnotherShape Destructor" << std::endl;
}

AnotherShape::AnotherShape(AnotherShape& rhs)
{
	std::cout << "AnotherShape:: Copy constructor" << std::endl;
}
