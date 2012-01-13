#ifndef __UTILITIES_DESIGNPATTERNS_COOPERATIVEVISITOR_INTERNAL_VTABLE_HPP__
#define __UTILITIES_DESIGNPATTERNS_COOPERATIVEVISITOR_INTERNAL_VTABLE_HPP__

#include "Tags.hpp"

#include <vector>
#include <iostream>
#include <typeinfo>

namespace Utilities
{
  namespace DesignPatterns
  {
    namespace CooperativeVisitor
    {
      namespace internal
      {
        template <typename Base, typename Func>
        class VTable
        {

        public:
          VTable(void){}
          virtual ~VTable(void){}

          template<typename Visitable>
          void add(Func ai_funcion)
          {

            size_t index (GetTag<Visitable,Base>()); // Use the class tag as index.
            //std::cout << "add index " << index <<" " << typeid(Visitable).name()<<" "<< std::endl;

            if ( index >= m_vtable.size() )
            {// el indice esta fuera de la tabla ...

              // Buscamos la funcion relacionada con la clase base.
              const size_t base_tag (GetTag<Base,Base>());

              //Obtenemos el puntero de la funcion relacionada con la clase base si existe o 0 si no,
              Func base_function( ( base_tag >= m_vtable.size() )? 0 : m_vtable[base_tag]);

              // Ahora expandimos la tabla utilizando el puntero a la funcion de la clase base como elemento
              // por defecto.
              m_vtable.resize( index + 1, base_function);
            }

            // ahora que lo tenemos todo listo
            // asignamos la funcion al indice adecuado.
            m_vtable[index] = ai_funcion;
          }


          //operador de indexacion
          Func operator[](const size_t& ai_index) const
          {
            std::cout << "Vtable operator[] index: " << ai_index << std::endl;
            if ( ai_index >= m_vtable.size())
            {
              std::cout << "Vtable operator[] return base class thunk: " << std::endl;
              return m_vtable[GetTag<Base,Base>()];
            }
            else
            {

              return m_vtable[ai_index];
            }
          }
        private:
          //non-copyable class
          VTable(const VTable& rhs);
          VTable& operator=(const VTable& rhs);

          ///@todo Try to use de AssocVector from Loki
          typedef std::vector<Func> vtable_t;
          vtable_t m_vtable;
        };
      }
    }
  }
}


#endif // __UTILITIES_DESIGNPATTERNS_COOPERATIVEVISITOR_INTERNAL_VTABLE_HPP__
