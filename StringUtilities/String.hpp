#ifndef __UTILITIES_STRING_HPP__
#define __UTILITIES_STRING_HPP__

#include <stdint.h>

namespace Utilities
{
  /**
   * @brief A high level abstraction for a human-readable character string.
   *
   * @class String
  */
  class String
  {
  public:

    /**
     * @brief Default constructor.
     *
     * @fn String
     * @param ai_initialSize Initial number of bytes to be reserved by the string object.
     * @param ai_chunkSize   Number of bytes in which will increase the amount of memory reserved by
     *                        the object whenever it will need it.
    */
    String(const uint64_t& ai_initialSize = 0,const uint32_t& ai_chunkSize = s_chunkSize);

    /**
     * @brief Constructor from a c-style char array.(NULL terminated)
     *
     * @fn String
     * @param ai_cadena null-terminated char array. It will be copy to the string object buffer.
    */
    String(char const *const ai_cadena);


    /**
     * @brief Copy Constructor
     *
     * @fn String
     * @param ai_string  Original object.
    */
    String(const String& ai_string);

    ~String(void);

    /**
     * @brief Getter method to obtain a c-style char array with the same content as the string object.
     *
     * @fn getCharString
     * @param void
     * @return const char *const. A C-style char array ( null-terminated)
    */
    char const *const getCharString(void) const;

    /**
     * @brief To get the current string lenght.
     *
     * @fn GetLength
     * @param void
     * @return uint64_t The string lenght currently.
    */
    uint64_t GetLength(void) const;


    // Operators

    String& operator=(const String& ai_string);
    String& operator=(char const *const ai_data);

    String operator+(const String& ai_string) const;
    String operator+(char const *const ai_data) const;

    String& operator+=(const String& ai_string);
    String& operator+=(char const *const ai_data);

    String& operator<<(const String& ai_string);
    String& operator<<(char const *const ai_data);

    bool operator==(const String& ai_string) const;
    bool operator==(char const * const ai_data) const;

    inline bool operator!=(const String& ai_string) const
    {
      return ! operator==(ai_string);
    }
    inline bool operator!=(char const * const ai_data) const
    {
      return !operator==(ai_data);
    }


    //Constants
    static const String endl; /**< End of line */


  protected:
    /**
     * @brief Swap the content of the current string object with the ones of the input parameter object.
     *
     * @fn swap
     * @param aio_right
    */
    void swap(String& aio_right) throw ();

  private:
    /**
     * @brief Returns the length of a null-terminated char array.
     *        If there is no null returns 0
     *
     * @fn GetLengthOfCharArray
     * @param ai_data. A null-terminated char array
     * @return uint64_t. Length of ai_data in bytes.
    */
    uint64_t GetLengthOfCharArray(char const *const ai_data) const;

    /**
     * @brief Method to reduce the resources used by this String object.
     *
     * @fn MinimizeBufferMemoryUsage
     * @param void
     * @todo TO BE IMPLEMENTED.
    */
    void MinimizeBufferMemoryUsage(void);

    /**
     * @brief Calculate the number of bytes needed to store a char array with ai_strLength bytes.
     *
     * @fn CalculateBufferNeeddedMemory
     * @param si_strLength Number of bytes we want to store in buffer.
     * @return uint64_t internal buffer size needed to store a char array of ai_strLenght bytes.
    */
    uint64_t CalculateBufferNeeddedMemory( const uint64_t& si_strLength) const;

    /**
     * @brief Helpper method to modify string to store the data in ai_buffer.
     *
     * @fn buildMeFromABuffer
     * @param ai_buffer data we want to build string from.
    */
    void buildMeFromABuffer(char const * const ai_buffer);

    /**
     * @brief Helpper method to concatenate the content of a String object with content of this one.
     *
     * @fn AddStringAtTheEnd
     * @param ai_string String to be concatenated.
    */
    void AddStringAtTheEnd(const String& ai_string);

    /**
     * @brief Helpper method to concatenate the content of a char array with the content of this String.
     *
     * @fn AddBufferAtTheEnd
     * @param ai_buffer Char array to be concatenated.
    */
    void AddBufferAtTheEnd(char const * const ai_buffer);

    char* m_buffer; /**< internal buffer to store char array data */
    uint64_t m_strLength; /**< Current string size. */
    uint64_t m_bufferSize; /**< Current buffer size. @note m_bufferSize >= m_strLength */
    const uint32_t m_chunkSize; /**< Number of bytes to increment m_buffer each time it is required */


    static const uint32_t s_chunkSize; /**< Default value for m_chunkSize */

  };

  /**
   * @brief Just for make things easy. This allow us to compare (char array == string)
   *
   * @fn operator ==
   * @param ai_data
   * @param ai_string
   * @return bool operator
  */
  inline bool operator==(char const * const ai_data,const String& ai_string)
  {
    return ai_string==ai_data;
  }

  inline bool operator!=(char const * const ai_data,const String& ai_string)
  {
    return ai_string!=ai_data;
  }
}


#endif // __UTILITIES_STRING_H__


