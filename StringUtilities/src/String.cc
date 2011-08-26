#include "String.hpp"


#include <Common/Nullptr.hpp>
#include <Common/Swapper.hpp>

#include <string.h>


namespace Utilities
{
  const String String::endl("\n");

  const uint32_t String::s_chunkSize = 4;

  String::String(const uint64_t& ai_initialSize, const uint32_t& ai_chunkSize)
    : m_buffer(Base::nullptr)
    , m_strLength(0)
    , m_bufferSize(ai_initialSize)
    , m_chunkSize(ai_chunkSize)
  {
    if (0 < m_bufferSize)
    {
      m_buffer = new char [m_bufferSize];
    }
  }
  String::String(char const *const ai_cadena)
    : m_buffer(Base::nullptr)
    , m_strLength(0)
    , m_bufferSize(0)
    , m_chunkSize(s_chunkSize)
  {
    buildMeFromABuffer(ai_cadena);
  }
  String::String(const String& ai_string)
    : m_chunkSize(ai_string.m_chunkSize)
  {
    m_strLength = ai_string.GetLength();
    m_bufferSize = CalculateBufferNeeddedMemory(m_strLength);


    if ((m_strLength > 0) && (Base::nullptr != ai_string.m_buffer))
    {
      m_buffer = new char [m_bufferSize];
      memcpy(m_buffer, ai_string.m_buffer, m_strLength);
      m_buffer[m_strLength] = '\0';
    }
    else
    {
      m_buffer = Base::nullptr;
    }
  }

  String::~String(void)
  {
    delete[] m_buffer;
    m_buffer = Base::nullptr;
  }




  char const *const String::getCharString(void) const
  {
    return m_buffer;
  }

  uint64_t String::GetLength(void) const
  {
    return m_strLength;
  }

  // Operators
  String String::operator+(const String& ai_string) const
  {
    uint64_t totalLength(m_strLength + ai_string.m_strLength);
    //assert(0 < totalLength);

    char buffer [totalLength+1];

    strncpy(buffer,m_buffer,m_strLength);
    strncpy((buffer+m_strLength),ai_string.m_buffer,ai_string.m_strLength);
    buffer[totalLength] = '\0';
    return String(buffer);


  /*
    uint64_t bufferNeeded(CalculateBufferNeeddedMemory(m_strLength + ai_string.m_strLength));
    uint8_t* buffer(m_buffer);

    if (  bufferNeeded > m_bufferSize)
    {
      buffer = new uint8_t[bufferNeeded];
      strncpy(buffer,m_buffer,m_strLength);
      buffer[m_strLength] = '\0';
      delete[] m_buffer;
      m_buffer = 0;
    }


    strncpy(buffer+m_strLength,ai_string.m_buffer,ai_string.m_strLength);
    m_strLength += ai_string.m_strLength;
    buffer[m_strLength] = '\0';

    m_buffer = buffer;

    return *this;
  */
  }
  String String::operator+(char const *const ai_data) const
  {
    uint64_t dataLen(GetLengthOfCharArray(ai_data));
    uint64_t totalLength(m_strLength + dataLen);
    //assert(0 < totalLength);

    uint8_t buffer [totalLength+1];

    strncpy((char*)(buffer),m_buffer,m_strLength);
    strncpy((char*)(buffer+m_strLength),ai_data,dataLen);
    buffer[totalLength] = '\0';
    return String((char*)buffer);
  }
  bool String::operator==(const String& ai_string) const
  {
    if (&ai_string == this)
    {
      return true;
    }
    if ( (0 == m_buffer) || ( 0 == ai_string.m_buffer) )
    {
      return false;
    }
    if (m_strLength != ai_string.m_strLength)
    {
      return false;
    }
    return (0 == strncmp(m_buffer,ai_string.m_buffer,m_strLength));
  }
  bool String::operator==(char const * const ai_data) const
  {
    if ( (0 == m_buffer) || ( 0 == ai_data) )
    {
      return false;
    }
    if (m_strLength != strlen(ai_data) )
    {
      return false;
    }
    return (0 == strncmp(m_buffer,ai_data,m_strLength));
  }

  String& String::operator<<(const String& ai_string)
  {
    AddStringAtTheEnd(ai_string);
    return *this;
  }
  String& String::operator<<(char const *const ai_data)
  {
    AddBufferAtTheEnd(ai_data);
    return (*this);
  }

  String& String::operator+=(const String& ai_string)
  {
    AddStringAtTheEnd(ai_string);
    return *this;
  }
  String& String::operator+=(char const *const ai_data)
  {
    AddBufferAtTheEnd(ai_data);
    return *this;
  }

  String& String::operator=(const String& ai_string)
  {
    /*A& A::operator=(const A& other)
    {
      A temp(other);
      swap(temp);
      return *this;
    }*/
    if (this != &ai_string)
    {
      String aux(ai_string);
      swap(aux);
    }
    return *this;

  /*
    m_strLength = ai_string.GetLength();
    uint64_t bufferNeeded (CalculateBufferNeeddedMemory(m_strLength));

    if ( m_bufferSize < bufferNeeded)
    {
      //realloc ?
      delete[] m_buffer;
      m_bufferSize = bufferNeeded;
      m_buffer = new char[m_bufferSize];
    }

    memcpy(m_buffer, ai_string.m_buffer, m_strLength);
    m_buffer[m_strLength] = '\0';

    m_isFreeze = ai_string.isFreeze();

    return *this;
  */
  }
  String& String::operator=(char const *const ai_data)
  {
    buildMeFromABuffer(ai_data);
    return *this;
  }

  //Private methods
  inline uint64_t String::GetLengthOfCharArray(char const* const ai_data) const
  {
    uint64_t len(0);
    const char* ptr(ai_data);
    for (; ('\0' != *ptr); ++ptr)
    {
      ++len;
      if ( 0 == len)
      {//overflow
        return static_cast<uint64_t>(0);
      }
    }
    return (len);
  }

  inline void String::MinimizeBufferMemoryUsage(void)
  {

  }
  inline uint64_t String::CalculateBufferNeeddedMemory(const uint64_t& si_strLength) const
  {
    return (((m_strLength / m_chunkSize) + 1) * m_chunkSize);
  }

  inline void String::AddStringAtTheEnd(const String& ai_string)
  {
    uint64_t totalLength(m_strLength + ai_string.m_strLength);
    char buffer[totalLength+1];
    memcpy(buffer,m_buffer,m_strLength);
    memcpy(buffer+m_strLength,ai_string.m_buffer,ai_string.m_strLength);
    buffer[totalLength]='\0';

    buildMeFromABuffer(buffer);

  }
  inline void String::AddBufferAtTheEnd(char const * const ai_buffer)
  {
    uint64_t dataLength(GetLengthOfCharArray(ai_buffer));
    uint64_t totalLength(m_strLength + dataLength);
    char buffer[totalLength+1];
    memcpy(buffer,m_buffer,m_strLength);
    memcpy(buffer+m_strLength,ai_buffer,dataLength);
    buffer[totalLength]='\0';

    buildMeFromABuffer(buffer);
  }

  inline void String::buildMeFromABuffer(char const * const ai_buffer)
  {
    uint64_t length (GetLengthOfCharArray(ai_buffer));
    if (0 != length)
    {
      m_strLength = length;
      uint64_t bufferSizeNeedded( CalculateBufferNeeddedMemory(m_strLength));
      if ( m_bufferSize < bufferSizeNeedded)
      {
        delete[] m_buffer;
        m_bufferSize = bufferSizeNeedded;
        m_buffer = new char[m_bufferSize];
      }
      memcpy(m_buffer,ai_buffer,m_strLength);
      m_buffer[m_strLength] = '\0';
    }
  }

  inline void String::swap(String& aio_right) throw()
  {
    Swapper::swap(m_strLength,aio_right.m_strLength);
    Swapper::swap(m_bufferSize,aio_right.m_bufferSize);
    Swapper::swap(m_buffer,aio_right.m_buffer);
  }
}


