/*
 * Variant.hpp
 *
 *  Created on: 13/07/2011
 *      Author: eojojos
 */

#ifndef VARIANT_HPP_
#define VARIANT_HPP_


#include <Common/DataTypes.hpp>
#include "VariantTypeFactory.hpp"//#include "src/VariantTypeFactory.hpp"

namespace Utilities
{
  namespace Variant
  {
    //Forward declaration
    namespace internal
    {
      class VariantTypeBase;
    }

    ///@todo Copy constructor, assigment operator default constructor ...
    ///and maybe convert VariantTypeFactory into a manager
    class Variant
    {
    public:
      template <typename T>
      Variant(const T& ai_value)
      {
        m_value = internal::VariantTypeFactory::Create(ai_value);
      }
      virtual ~Variant(void);

      template<typename V>
      ResultCode_t getValue(V& ao_value)
      {
        //Get the visitor, call the operator() and get the returned value
        ao_value = internal::VariantTypeFactory::GetVisitor(ao_value)(m_value);

        return SUCCESS;
      }
    private:
      internal::VariantTypeBase* m_value;
    };
  }
}
#endif /* VARIANT_HPP_ */

