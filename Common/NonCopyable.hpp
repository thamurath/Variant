#ifndef __COMMON_BASE_POCILIES_NONCOPYABLE_HPP__
#define __COMMON_BASE_POCILIES_NONCOPYABLE_HPP__



namespace Base
{
  namespace Polycies
  {
    /**
     * @brief Utility class to mark another one as non-copyable.
     *
     * Just use private inheritance to use it.
     * @class NonCopyable*/
    class NonCopyable
    {
    protected:
      NonCopyable(void)
      {

      }

      ~NonCopyable(void)
      {

      }
    private:
      NonCopyable(const NonCopyable&);
      NonCopyable& operator=(const NonCopyable&);
    };
  }
}
#endif // __COMMON_BASE_POCILIES_NONCOPYABLE_HPP__
