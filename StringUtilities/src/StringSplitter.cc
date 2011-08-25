#include "src/StringSplitter.hpp"

#include <string.h>
#include <stdint.h>


namespace Utilities
{
  char const* const StringSplitter::s_defaultSeparator = ",";

  StringSplitter::StringSplitter(char const* const ai_string)
    : m_string(ai_string)
    , m_stringLength((0 == ai_string) ? (0) : (strlen(ai_string)))
    , m_separator(s_defaultSeparator)
    , m_separatorLength(strlen(s_defaultSeparator))
  {
  }

  StringSplitter::StringSplitter(char const* const ai_string
                                 , char const* const ai_separator)
    : m_string(ai_string)
    , m_stringLength((0 == ai_string) ? (0) : (strlen(ai_string)))
    , m_separator(ai_separator)
    , m_separatorLength((0 == ai_separator) ? (0) : (strlen(ai_separator)))
  {
  }

  StringSplitter::~StringSplitter(void)
  {
  }

  bool StringSplitter::operator ==(const StringSplitter& ai_right) const
  {
    return this == &ai_right;
  }

  bool StringSplitter::operator !=(const StringSplitter& ai_right) const
  {
    return !(*this == ai_right);
  }

  ResultCode_t StringSplitter::getNextString(uint32_t& aio_index, uint32_t& aio_length) const
  {
    if (
      (0 == m_string) ||
      ((aio_index + aio_length) >= m_stringLength)
    )
    {
      return FAILURE;
    }

    if ((0 != m_separator) && (m_separatorLength > 0))
    {
      uint32_t idx(0);

      if ((aio_index + aio_length) > 0)
      {
        idx = aio_index + aio_length + 1;
      }

      char* index(strstr(m_string + idx, m_separator));

      if (0 == index)
      {
        //separator not found
        aio_index = idx;
        aio_length = m_stringLength - aio_index;
        return SUCCESS;
      }
      else
      {
        aio_index = idx;
        aio_length = (index - (m_string + idx));
        return SUCCESS;
      }
    }
    else //no separator at all
    {
      aio_length = m_stringLength;
      aio_index = 0;
      return SUCCESS;
    }
  }

  StringSplitter::Iterator* StringSplitter::getIterator(void) const
  {
    return new StringSplitter::Iterator(*this);
  }


  StringSplitter::Iterator::Iterator(const StringSplitter& ai_splitter)
    : m_splitter(ai_splitter)
    , m_index(0)
    , m_length(0)
    , m_string(0)
    , m_isDone(false)
    , m_itemChanged(false)
  {
  }
  bool StringSplitter::Iterator::First(void)
  {
    m_index = 0;
    m_length = 0;
    m_itemChanged = true;
    m_isDone = (SUCCESS != m_splitter.getNextString(m_index, m_length));
    return !m_isDone;
  }
  bool StringSplitter::Iterator::Next(void)
  {
    m_itemChanged = true;
    m_isDone = (SUCCESS != m_splitter.getNextString(m_index, m_length));
    return !m_isDone;
  }
  bool StringSplitter::Iterator::isDone(void) const
  {
    return m_isDone;
  }

  char*& StringSplitter::Iterator::getCurrentItem(void) const
  {
    if (m_itemChanged)
    {
      m_itemChanged = false;
      delete[] m_string;
      m_string = 0;

      if (false == m_isDone)
      {
        m_string = new char[m_length+1];
        memcpy(m_string, m_splitter.m_string + m_index, m_length);
        m_string[m_length] = 0;
      }
    }

    return m_string;
  }

  StringSplitter::Iterator::Iterator(const Iterator& ai_iterator)
    : m_splitter(ai_iterator.m_splitter)
    , m_index(ai_iterator.m_index)
    , m_length(ai_iterator.m_length)
    , m_string(0)
    , m_isDone(ai_iterator.m_isDone)
    , m_itemChanged(false)
  {
  }
  StringSplitter::Iterator& StringSplitter::Iterator::operator=(const Iterator& ai_iterator)
  {
    StringSplitter::Iterator tmp(ai_iterator);
    swap(tmp);
    return *this;
  }
  void StringSplitter::Iterator::swap(Iterator& aio_iterator)
  {
    if (m_splitter != aio_iterator.m_splitter)
    {
      return;
    }

    uint32_t aux(aio_iterator.m_index);
    aio_iterator.m_index = m_index;
    m_index = aux;
    aux = aio_iterator.m_length;
    aio_iterator.m_length = m_length;
    m_length = aux;
    char* string(aio_iterator.m_string);
    aio_iterator.m_string = m_string;
    m_string = string;
    bool baux(aio_iterator.m_isDone);
    aio_iterator.m_isDone = baux;
    m_isDone = baux;
    baux = aio_iterator.m_itemChanged;
    aio_iterator.m_itemChanged = m_itemChanged;
    m_itemChanged = baux;
  }
  char*& StringSplitter::Iterator::operator*(void)
  {
    return getCurrentItem();
  }

  StringSplitter::Iterator::~Iterator(void)
  {
    delete[] m_string;
    m_string = 0;
  }
}
