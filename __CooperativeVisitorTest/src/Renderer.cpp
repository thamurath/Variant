#include "Renderer.hpp"

#include <iostream>

void Renderer::draw(Shape&)
{
  std::cout << "Renderer::draw( Shape&)" << std::endl;
}

void Renderer::draw(Bezier&)
{
  std::cout << "Renderer::draw(Bezier&)" << std::endl;
}

void Renderer::draw(Circle&)
{
  std::cout << "Renderer::draw( Circle&)" << std::endl;
}

void Renderer::draw(Rect&)
{
  std::cout << "Renderer::draw( Rect&)" << std::endl;
}
void Renderer::draw(Square&)
{
  std::cout << "Renderer::draw( Square&)" << std::endl;
}
void Renderer::draw(Poly&)
{
  std::cout << "Renderer::draw( Poly&)" << std::endl;
}
void Renderer::draw(AnotherShape&)
{
  std::cout << "Render::AnotherShape(AnotherShape&)" << std::endl;
}
