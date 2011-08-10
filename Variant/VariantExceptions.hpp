#ifndef __UTILITIES_VARIANT_VARIANTEXCEPTIONS_HPP__
#define __UTILITIES_VARIANT_VARIANTEXCEPTIONS_HPP__

#include <StringUtilities/String.hpp>
#include <exception>

namespace Utilities
{
  namespace Variant
  {
    class VariantExecption : public std::exception
    {
    public:

      virtual ~VariantException() throw();

      /** Returns a C-style character string describing the general cause
       *    of the current error.  */
      virtual const char* what() const throw()
      {
        return m_what.c_str();
      }

    protected:
      VariantException(const Utilities:::String& ai_what) throw()
        : m_what(ai_what)
      {

      }

    private:

      Utilities::String m_what;

    };
  }
}

#endif // __UTILITIES_VARIANT_VARIANTEXCEPTIONS_HPP__
