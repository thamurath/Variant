#ifndef __UTILITIES_VARIANT_VARIANTEXCEPTIONS_HPP__
#define __UTILITIES_VARIANT_VARIANTEXCEPTIONS_HPP__

#include <StringUtilities/String.hpp>
#include <exception>

namespace Utilities
{
  namespace Variant
  {
    namespace Exceptions
    {
      class VariantException : public std::exception
      {
      public:

        virtual ~VariantException() throw();

        /** Returns a C-style character string describing the general cause
         *    of the current error.  */
        virtual const char* what() const throw()
        {
          return m_what.getCharString();
        }

      protected:
        VariantException(const Utilities::String& ai_what) throw()
          : m_what(ai_what)
        {

        }

      private:

        Utilities::String m_what;

      };

      class UnableToConvertData : public VariantException
      {
      public:
        UnableToConvertData(void)
          : VariantException("Unable to find converter for specified type")
        {

        }
        virtual ~UnableToConvertData(void) throw()
        {

        }
      };

      class UnableToInsertInContainer : public VariantException
      {
      public:
        UnableToInsertInContainer(void)
          : VariantException("Unexpected Error while inserting in the container")
        {

        }
        virtual ~UnableToInsertInContainer(void) throw ()
        {

        }
      };

      class NonExistingVariantType : public VariantException
      {
      public:
        NonExistingVariantType(void)
          : VariantException("Unable to find a variant type")
        {

        }
        virtual ~NonExistingVariantType(void) throw()
        {

        }
      };

      class ConvertException : public VariantException
      {
      public:
        ConvertException(const Utilities::String& ai_what)
          : VariantException(ai_what)
        {

        }
        virtual ~ConvertException(void) throw()
        {

        }
      };

      class TruncatedValueException : public ConvertException
      {
      public:
        TruncatedValueException(void)
          : ConvertException("Unable to convert data, destination type is not big enough")
        {

        }
        virtual ~TruncatedValueException(void) throw()
        {

        }
      };

    }
  }
}

#endif // __UTILITIES_VARIANT_VARIANTEXCEPTIONS_HPP__
