
#ifndef VARIANTTYPEFACTORY_HPP_
#define VARIANTTYPEFACTORY_HPP_



#include "VariantType.hpp"

#include "VariantTypeUInt32.hpp"

#include <cstdio>

class VariantTypeFactory
{
public:
  template<typename CreateType>
  static VariantType* Create(const CreateType& ai_value)
  {
    return Create(ai_value,Type2Type<CreateType>());
  }

  template<typename ToType>
  static ConvertVisitor* CreateVisitor(ToType& ao_value)
  {
    return CreateVisitor(ao_value,Type2Type<ToType>());
  }
private:
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
