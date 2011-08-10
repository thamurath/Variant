#ifndef __COMMON_BASE_NULLPTR_HPP__
#define __COMMON_BASE_NULLPTR_HPP__

namespace Base
{
  class nullptr_t
  {
  public:
    template<class T>
    operator T*() const // convertible to any type of null non-member pointer...
    { return 0; }

    template<class C, class T>
    operator T C::*() const   // or any type of null member pointer...
    { return 0; }

  private:
    void operator&() const;  // Can't take address of nullptr

  };
  const nullptr_t nullptr = {};

}


#endif //__COMMON_BASE_NULLPTR_HPP__
