
#ifndef VARIANTTYPEFACTORY_HPP_
#define VARIANTTYPEFACTORY_HPP_



#include "src/VariantTypeBase.hpp"
#include "src/VariantTypeUInt32.hpp"

#include "VariantExceptions.hpp"

#include <TypeLists/TypeList.hpp>


#include <memory>
#include <cstdio>


namespace Utilities
{
  namespace Variant
  {
    namespace internal
    {
      class VariantTypeFactory
      {

        //We need to store visitors by type so we can retreive them from the container instead of
        // create them each time.
        // I have found no other way that to declare a list of types which visitors can manage and
        // use the IndexOf typelist capability to get the correct index of each type.
        typedef TYPELIST_2(uint32_t,int64_t) SupportedTypes;

        typedef uint32_t TableIndex_t;
        // Container
        typedef std::map<TableIndex_t,boost::shared_ptr<ConvertVisitor> > ConverterTable_t;
        ConverterTable_t m_visitorTable;

      public:
        template<typename CreateType>
        static VariantTypeBase* Create(const CreateType& ai_value)
        {
          return Create(ai_value,Utilities::TypeLists::Type2Type<CreateType>());
        }

        template<typename ToType>
        static ConvertVisitor& GetVisitor(ToType& ao_value)
        {
          const TableIndex_t index = Utilities::TypeLists::IndexOf<SupportedTypes,ToType>::value;

          ///@note See Effective STL Item 24 for reference


          // First search for the key
          // lower_bound: if key is not in the map returns the position where that key should be inserted
          ConverterTable_t::iterator ite ( m_visitorTable.lower_bound(index));

          if ( (ite != m_visitorTable.end()) && (! (m_visitorTable.key_comp()(index,ite->fist))) )
          {// if the position is not nulltype and the key in the returned position is  the one we search for
            // key found ... so we return the converter
            return *(ite->second);
          }
          else
          {
            // key not found so we have to create the converter and store it
            boost::shared_ptr<ConvertVisitor> sptr( CreateVisitor(ao_value,Utilities::TypeLists::Type2Type<ToType>()));

            //insert using the previous position as insert hint to avoid another look up
            std::pair<ConverterTable_t::iterator,bool> ret (m_visitorTable.insert(ite, ConverterTable_t::value_type(index, sptr)));

            // check the insertion for success
            if ( false == ret.second)
            {
              throw Utilities::Variant::Exceptions::UnableToInsertInContainer();
            }
            else
            {// the first parameter of ret is a iterator...
              return *((ret.first)->second);
            }
          }
        }

      private:



        static VariantType* Create(const uint32_t& ai_value,Utilities::TypeLists::Type2Type<uint32_t>)
        {
          return new VariantTypeUIn32(ai_value);
        }

        static VariantType* Create(const int64_t& ai_value,Utilities::TypeLists::Type2Type<int64_t>)
        {
          return new VariantTypeInt64(ai_value);
        }

        template<typename InternalType>
        static VariantType* Create(const InternalType& ai_value,Utilities::TypeLists::Type2Type<InternalType>)
        {
          throw Utilities::Variant::Exceptions::NonExistingVariantType();
          return 0;
        }

        static ConvertVisitor* CreateVisitor(uint32_t& ao_value,Utilities::TypeLists::Type2Type<uint32_t>)
        {
          return 0;
        }
        static ConvertVisitor* CreateVisitor(int64_t& ao_value,Utilities::TypeLists::Type2Type<int64_t>)
        {
          return new VisitorOne();
        }

        template<typename InternalType>
        static ConvertVisitor* CreateVisitor(InternalType& ai_value,Utilities::TypeLists::Type2Type<InternalType>)
        {
          throw Utilities::Variant::Exceptions::UnableToConvertData();
        }

        VariantTypeFactory(void);
        VariantTypeFactory(const VariantTypeFactory&);
        VariantTypeFactory& operator=(const VariantTypeFactory&);

      };

    }
  }
}


#endif /* VARIANTTYPEFACTORY_HPP_ */
