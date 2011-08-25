#ifndef ___UTILITIES_STRINGUTILITIES_H__
#define ___UTILITIES_STRINGUTILITIES_H__


#include "src/StringToIntegerFunctionGeneratorMacros.hpp"

#include "String.hpp"

#include <cstdio>
#include <cstring>
#include <cmath>
#include <stdint.h>
#include <inttypes.h>


namespace Utilities
{
  STRTOINT(16, INT16_MAX);
  STRTOUINT(16, UINT16_MAX);
  STRTOINT(32, INT32_MAX);
  /* #pragma GCC diagnostic push */
  /* #pragma GCC diagnostic ignored "-Wsign-compare" */
  STRTOUINT(32, UINT32_MAX);
  /* #pragma GCC diagnostic pop */

  STRTOINT(64, INT64_MAX);
  STRTOUINT(64, UINT64_MAX);

  class StringUtilities
  {
  public:
    /** Converts a number in to a String.
     *
     * @param ai_number Number to be converted
     * @return A utilities::String object
     */
    inline static String ToString(const uint64_t& ai_number)
    {
      const uint64_t stringLength(GetCharactersNeededtoStoreNumber(static_cast<uint64_t>(ai_number)));
      char auxString[stringLength + 1];
      memset(auxString,0,stringLength);
      (auxString,stringLength+1,"%"PRIu64,ai_number);
      return String(auxString);
    }

    /** Converts a number in to a String.
     *
     * @param ai_number Number to be converted
     * @return A utilities::String object
     */
    inline static String ToString(const uint32_t& ai_number)
    {
      const uint64_t stringLength(GetCharactersNeededtoStoreNumber(static_cast<uint64_t>(ai_number)));
      char auxString[stringLength + 1];
      memset(auxString,0,stringLength);
      snprintf(auxString,stringLength + 1,"%"PRIu32,ai_number);
      return String(auxString);
    }

    /** Converts a number in to a String.
     *
     * @param ai_number Number to be converted
     * @return A utilities::String object
     */
    inline static String ToString(const uint16_t& ai_number)
    {
      const uint64_t stringLength(GetCharactersNeededtoStoreNumber(static_cast<uint64_t>(ai_number)));
      char auxString[stringLength + 1];
      memset(auxString,0,stringLength);
      snprintf(auxString,stringLength+1,"%"PRIu16,ai_number);
      return String(auxString);
    }

    /** Converts a number in to a String.
     *
     * @param ai_number Number to be converted
     * @return A utilities::String object
     */
    inline static String ToString(const uint8_t& ai_number)
    {
      const uint64_t stringLength(GetCharactersNeededtoStoreNumber(static_cast<uint64_t>(ai_number)));
      char auxString[stringLength + 1];
      memset(auxString,0,stringLength);
      snprintf(auxString,stringLength+1,"%"PRIu8,ai_number);
      return String(auxString);
    }

    /** Converts a number in to a String.
     *
     * @param ai_number Number to be converted
     * @return A utilities::String object
     */
    inline static String ToString(const int64_t& ai_number)
    {
      const uint64_t stringLength(GetCharactersNeededtoStoreNumber(static_cast<int64_t>(ai_number)));
      char auxString[stringLength + 1];
      memset(auxString,0,stringLength);
      snprintf(auxString,stringLength+1,"%"PRId64,ai_number);
      return String(auxString);
    }

    /** Converts a number in to a String.
     *
     * @param ai_number Number to be converted
     * @return A utilities::String object
     */
    inline static String ToString(const int32_t& ai_number)
    {
      const uint64_t stringLength(GetCharactersNeededtoStoreNumber(static_cast<int64_t>(ai_number)));
      char auxString[stringLength + 1 ];
      memset(auxString,0,stringLength);
      snprintf(auxString,stringLength+1,"%"PRId32,ai_number);
      return String(auxString);
    }

    /** Converts a number in to a String.
     *
     * @param ai_number Number to be converted
     * @return A utilities::String object
     */
    inline static String ToString(const int16_t& ai_number)
    {
      const uint64_t stringLength(GetCharactersNeededtoStoreNumber(static_cast<int64_t>(ai_number)));
      char auxString[stringLength + 1];
      memset(auxString,0,stringLength);
      snprintf(auxString,stringLength+1,"%"PRId16,ai_number);
      return String(auxString);
    }

    /** Converts a number in to a String.
     *
     * @param ai_number Number to be converted
     * @return A utilities::String object
     */
    inline static String ToString(const int8_t& ai_number)
    {
      const uint64_t stringLength(GetCharactersNeededtoStoreNumber(static_cast<int64_t>(ai_number)));
      char auxString[stringLength + 1];
      memset(auxString,0,stringLength);
      snprintf(auxString,stringLength+1,"%"PRId8,ai_number);
      return String(auxString);
    }

    /** Extract a numeric value from a string
     *
     * @param ai_string utilities::String where the number is
     * @param ao_value value extracted.
     * @return @code 0 @endcode on SUCCESS, an error code otherwise.
     * @note This method modifies errno global varible.
     */
    inline static int32_t ToNumber(const String& ai_string,uint64_t& ao_value)
    {
      if ( 0 == ai_string.getCharString())
      {
        return EINVAL;
      }
      char* end(0);
      errno = 0;
      return strtouint64(ai_string.getCharString(),&end,&ao_value,&errno);
    }

    /** Extract a numeric value from a string
     *
     * @param ai_string utilities::String where the number is
     * @param ao_value value extracted.
     * @return @code 0 @endcode on SUCCESS, an error code otherwise.
     * @note This method modifies errno global varible.
     */
    inline static int32_t ToNumber(const String& ai_string,int64_t& ao_value)
    {
      if ( 0 == ai_string.getCharString())
      {
        return EINVAL;
      }
      char* end(0);
      errno = 0;
      return strtoint64(ai_string.getCharString(),&end,&ao_value,&errno);
    }

    /** Extract a numeric value from a string
     *
     * @param ai_string utilities::String where the number is
     * @param ao_value value extracted.
     * @return @code 0 @endcode on SUCCESS, an error code otherwise.
     * @note This method modifies errno global varible.
     */
    inline static int32_t ToNumber(const String& ai_string,uint32_t& ao_value)
    {
      if ( 0 == ai_string.getCharString())
      {
        return EINVAL;
      }
      char* end(0);
      errno = 0;
      return strtouint32(ai_string.getCharString(),&end,&ao_value,&errno);
    }

    /** Extract a numeric value from a string
     *
     * @param ai_string utilities::String where the number is
     * @param ao_value value extracted.
     * @return @code 0 @endcode on SUCCESS, an error code otherwise.
     * @note This method modifies errno global varible.
     */
    inline static int32_t ToNumber(const String& ai_string,int32_t& ao_value)
    {
      if ( 0 == ai_string.getCharString())
      {
        return EINVAL;
      }
      char* end(0);
      errno = 0;
      return strtoint32(ai_string.getCharString(),&end,&ao_value,&errno);
    }

    /** Extract a numeric value from a string
     *
     * @param ai_string utilities::String where the number is
     * @param ao_value value extracted.
     * @return @code 0 @endcode on SUCCESS, an error code otherwise.
     * @note This method modifies errno global varible.
     */
    inline static int32_t ToNumber(const String& ai_string,uint16_t& ao_value)
    {
      if ( 0 == ai_string.getCharString())
      {
        return EINVAL;
      }
      char* end(0);
      errno = 0;
      return strtouint16(ai_string.getCharString(),&end,&ao_value,&errno);
    }

    /** Extract a numeric value from a string
     *
     * @param ai_string utilities::String where the number is
     * @param ao_value value extracted.
     * @return @code 0 @endcode on SUCCESS, an error code otherwise.
     * @note This method modifies errno global varible.
     */
    inline static int32_t ToNumber(const String& ai_string,int16_t& ao_value)
    {
      if ( 0 == ai_string.getCharString())
      {
        return EINVAL;
      }
      char* end(0);
      errno = 0;
      return strtoint16(ai_string.getCharString(),&end,&ao_value,&errno);
    }

  private:
    inline static uint64_t absolute(const int64_t& ai_number)
    {
      return static_cast<uint64_t>((0>ai_number)?(-ai_number):(ai_number));
    }

    inline static uint64_t GetCharactersNeededtoStoreNumber(const int64_t& ai_number)
    {
      return ((0 == ai_number)?(1):(floor(log10(absolute(ai_number))) + 1 + ((0>ai_number)?(1):(0))));
    }

    inline static uint64_t GetCharactersNeededtoStoreNumber(const uint64_t& ai_number)
    {
      return ((0 == ai_number)?(1):(floor(log10(ai_number)) + 1 ));
    }

  };


}

#endif //___UTILITIES_STRINGUTILITIES_H__
