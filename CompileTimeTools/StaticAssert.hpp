#ifndef __UTILITIES_COMPILETIMECHECKS_STATIC_ASSERT_HPP__
#define __UTILITIES_COMPILETIMECHECKS_STATIC_ASSERT_HPP__


namespace Utilities
{
  namespace CompileTimeTools
  {
    template<bool> struct CompileTimeChecker
    {
      CompileTimeChecker(...){};
    };

    template<>struct CompileTimeChecker<false> {};


// Check "expression" if not true raise a compile error with "message"
// Primero creamos una clase local en cuyo nombre interviene el mensaje que nos pasan
// Segundo: Intentamos crear un objeto temporal del tipo CompileTimeChecker pasandole como parametro
//			un objeto temporal de la clase local recien creada, por ultimo utilizamos sizeof para obtener el tama;o.
//			Si expression es true tendremos la especializacion que admite cualquier tipo como parametro en el
//			constructor, asi que el codigo sera valido.
//			Si expression es false, tendremos un error ya que no hay manera de convertir un objeto del tipo
// 			ERROR_##message en uno CompileTimeChecker<false> y con suerte el compilador mencionara las dos clases
//			que intervienen en la conversion de manera que tendremos un mensaje legible.
// Nota: Cabe recordar que los objetos utilizados por sizeof no llegan a ser instanciados realmente.

  } //namespace Utilities
} // namespace CompileTimeTools


#define STATIC_ASSERT(expression,message)                               \
{                                                                       \
  class ERROR_##message{} ERROR_##message;                              \
  (void)sizeof(Utilities::CompileTimeTools::CompileTimeChecker<(expression) == true>(( ERROR_##message ))); \
}


#endif //__UTILITIES_COMPILETIMECHECKS_STATIC_ASSERT_HPP__
