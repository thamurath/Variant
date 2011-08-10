#ifndef __UTILITIES_STRINGSPLITTER_HPP__
#define __UTILITIES_STRINGSPLITTER_HPP__




#include <stdint.h>

namespace Utilities
{

  /**
   * @todo Refactoring all this class using String
   */
  class StringSplitter
  {
  public:
    StringSplitter(char const* const ai_string);
    StringSplitter(char const* const ai_string
                   , char const* const ai_separator);
    ~StringSplitter(void);

    bool operator==(const StringSplitter& ai_right) const;
    bool operator!=(const StringSplitter& ai_right) const;
  private:

    class Iterator
    {
    public:
      bool First(void);
      bool Next(void);
      bool isDone(void) const;
      char*& getCurrentItem(void) const;

      Iterator(const Iterator& ai_iterator);
      Iterator& operator=(const Iterator& ai_iterator);
      char*& operator*(void);

      ~Iterator(void);
    private:
      Iterator(const StringSplitter& ai_splitter);
      void swap(Iterator& aio_iterator);
      const StringSplitter& m_splitter;
      uint32_t m_index;
      uint32_t m_length;
      mutable char* m_string;
      bool m_isDone;
      mutable bool m_itemChanged;

      friend class StringSplitter;
    };
  public:
    class IteratorPtr
    {
    public:
      inline IteratorPtr(Iterator* ai_iterator): m_iteratorPointer(ai_iterator)
      {
      }
      inline ~IteratorPtr(void)
      {
        delete m_iteratorPointer;
      }

      inline Iterator* const operator->(void)
      {
        return m_iteratorPointer;
      }
      inline Iterator& operator*(void)
      {
        return *m_iteratorPointer;
      }
    private:
      // disallow copy and assignment to avoid
      // multiple deletions of m_iteratorPointer:

      IteratorPtr(const IteratorPtr&);
      IteratorPtr& operator=(const IteratorPtr&);

      Iterator* m_iteratorPointer;
    };

    Iterator* getIterator(void) const;
  private:
    ResultCode_t getNextString(uint32_t& aio_index, uint32_t& aio_length) const;
    static char const* const s_defaultSeparator;

    char const* const m_string;
    const uint32_t m_stringLength;
    char const* const m_separator;
    const uint32_t m_separatorLength;

    StringSplitter(const StringSplitter&);
    StringSplitter& operator=(const StringSplitter&);
  };
}

#endif // STRINGSPLITTER_H
