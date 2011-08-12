
#ifndef VARIANTTYPEFACTORY_HPP_
#define VARIANTTYPEFACTORY_HPP_



#include "VariantType.hpp"

#include "VariantTypeUInt32.hpp"

#include <cstdio>


///@todo change this factory to a manager and make it a Singleton
class VariantTypeFactory
{
  typedef TYPELIST_2(uint8_t,uint32_t) ConvertibleTypes;
public:

  static VariantTypeFactory& GetInstance(void)
  {
    if (nullptr == s_instance)
    {
      s_instance = new VariantTypeFactory();
    }

    return *s_instance;
  }

  template<typename CreateType>
  VariantType* Create(const CreateType& ai_value)
  {
    return Create(ai_value,Type2Type<CreateType>());
  }

  template<typename ToType>
  ConvertVisitor& GetVisitor(ToType& ao_value)
  {
    //First seach an internal cache
    static const size_t index(TypeLists::IndexOf<ConvertibleTypes,ToType>::value);
    if (-1 == index)
    {
      throw NonConvertibleTypeError();
    }


    ConvertVisitor* visitor(Base::nullptr);
    VisitorPool_t::iterator ite (m_cache.find(index));
    if (m_cahe.end() != ite)
    {
      visitor = ite->second;
    }
    else
    {
      //If there is no visitor of that type in the internal cache, create it
      visitor =  CreateVisitor(ao_value,Type2Type<ToType>());
      if ( nullptr == visitor)
      {
        thow UnableToCreateVisitor();
      }

      //and the insert it in the cache for future conversions
      m_chache.insert(std::make_pair(index,visitor));
    }
    return *visitor;
  }
protected:

  ~VariantTypeFactory(void)
  {
    struct Deleter
    {
      template<typename T>
      void operator()(T* ai_pointer) const
      {
        delete ai_pointer;
        ai_pointer = Base::nullptr;
      }
    };

    std::for_each(m_cache.begin(),m_cache.end(),Deleter());
  }

private:

  ///@todo usar std::auto_ptr<> para que se elimine cuando se destruya el objeto
  static VariantTypeFactory* s_instance;

  typedef std::map<size_t,ConvertVisitor*> VistorPool_t;

  VisitorPool_t m_cache;

  template<typename T>
  struct Type2Type
  {
    typedef T OriginalType;
  };


  static VariantType* Create(const uint32_t& ai_value,Type2Type<uint32_t>)
  {
    return new VariantTypeUIn32(ai_value);
  }

  static VariantType* Create(const int64_t& ai_value,Type2Type<int64_t>)
  {
    return new VariantTypeInt64(ai_value);
  }

  template<typename InternalType>
  static VariantType* Create(const InternalType& ai_value,Type2Type<InternalType>)
  {
    return 0;
  }

  static ConvertVisitor* CreateVisitor(uint32_t& ao_value,Type2Type<uint32_t>)
  {
    return 0;
  }
  static ConvertVisitor* CreateVisitor(int64_t& ao_value,Type2Type<int64_t>)
  {
    return new VisitorOne();
  }

  template<typename InternalType>
  static ConvertVisitor* CreateVisitor(InternalType& ai_value,Type2Type<InternalType>)
  {
    return 0;
  }

  VariantTypeFactory(void);
  VariantTypeFactory(const VariantTypeFactory&);
  VariantTypeFactory& operator=(const VariantTypeFactory&);

};

#endif /* VARIANTTYPEFACTORY_HPP_ */
