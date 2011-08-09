#include "Renderer.hpp"

//Shapes includes
#include "Circle.hpp"
#include "Square.hpp"
#include "Bezier.hpp"
#include "Rect.hpp"
#include "AnotherShape.hpp"

#include "Shape.hpp"

#include <stdio.h>

int main(int argc, char **argv)
{
  const unsigned int max = 15;

  Shape* pointerList[max];

  unsigned int idx = 0;
  for (idx=0;idx<max;++idx)
  {
    pointerList[idx] = 0;
  }
  std::cout << "--- Creating --- " << std::endl;
  idx=0;
  //0
  pointerList[idx++] = new Circle();
  //1
  pointerList[idx++] = new Square();
  //2
  pointerList[idx++] = new Bezier();
  //3
  pointerList[idx++] = new Rect();
  //4
  pointerList[idx++] = new Circle();
  //5
  pointerList[idx++] = new Circle();
  //6
  pointerList[idx++] = new Shape();
  //7
  pointerList[idx++] = new Shape();
  //8
  pointerList[idx++] = new Rect();
  //9
  pointerList[idx++] = new Bezier();
  //10
  pointerList[idx++] = new Square();
  //11
  pointerList[idx++] = new Square();
  //12
  pointerList[idx++] = new AnotherShape();
  //13
  pointerList[idx++] = new Circle();
  //14
  pointerList[idx++] = new AnotherShape();

  Renderer render1;


  std::cout << "--- Renderer1 --- " << std::endl;

  for (idx=0;idx<max;++idx)
  {
    std::cout << "idx=" << idx <<":" ;
    if (0 != pointerList[idx])
    {
      std::cout << "pointer tag : "<< typeid(*pointerList[idx]).name()<< pointerList[idx]->Tag() << " ";
      render1(*(pointerList[idx]));
    }
    else
    {
      std::cout << " null pointer " << std::endl;
    }
  }


  for (idx=0;idx<max;++idx)
  {
    delete pointerList[idx];
    pointerList[idx] = 0;
  }

}
