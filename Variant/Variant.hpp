/*
 * Variant.hpp
 *
 *  Created on: 13/07/2011
 *      Author: eojojos
 */

#ifndef VARIANT_HPP_
#define VARIANT_HPP_


#include <Common/DataTypes.hpp>
#include "VariantTypeFactory.hpp"

///@todo Copy constructor, assigment operator default constructor ...and maybe convert VariantTypeFactory into a manager
class Variant
{
public:

  template <typename T>
  Variant(const T& ai_value)
  {
    m_value = VariantTypeFactory::Create(ai_value);
  }


  template<typename V>
  ResultCode_t getValue(V& ao_value)
  {
    ///@todo almost everything to be done. Update with Cooperative Visitor
    ConvertVisitor* v = VariantTypeFactory::CreateVisitor(ao_value);
    if ( 0 != v)
    {
      m_value->AcceptVisitor(*v);
    }
    return FAILURE;
  }


  virtual ~Variant(void)
  {
    delete m_value;
    m_value = 0;
  }
private:

  VariantType* m_value;
};


#endif /* VARIANT_HPP_ */
