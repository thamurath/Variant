README


Esta es la version definitiva por el momento.

Esta version parece que funciona, pero tiene aun algunas cosas que hay que mejorar/arreglar.

Tengo problemas con el ReturnType:
  En algunos sitios el tipo de retorno ha sido sacado de los templates y puesto directamente a void.
  Esto es asi porque en algunos sitios no podia averiguarlo por si solo el compilador y en otros tengo problemas con el return.

Hay que limpiar:
  En la prueba de concepto todas las clases de la jerarquia visitable estan en el mismo fichero de cabecera, por esto no se aprecia
  que hay menos dependencias de compilacion.
  Mirar todos los includes que hay en los ficheros de cabecera de la parte de libreria y asegurarse que no hay dependencias innecesarias.

Eliminar la llamada a la funcion virtual Tag()
  Cada uno de los visitables implementa una funcion virtual Tag() que es la que se utiliza para poder obtener el valor del tag.
  Esta llamada ( segun el articulo del cooperative visitor) se puede eliminar si cada una de las clases guardase el valor del tag
  en una variable miembro ( entiendo que estatica, aunque no lo pone explicitamente ) 
  Aun no he conseguido hacer esto.

Realizar el Variant.
  Esto ya seria cuando todo este terminado en la parte de la libreria.
  
