#ifndef __UTILITIES_SWAPPER_HPP__
#define __UTILITIES_SWAPPER_HPP__

namespace Utilities
{
  class Swapper
  {
  public:
    template <typename T>
    static void swap(T& left, T& right)
    {
      T aux(left);
      left = right;
      right = aux;
    }
  };
}

#endif // __UTILITIES_SWAPPER_HPP__
