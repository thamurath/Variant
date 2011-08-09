#ifndef __UTILITIES_COMPILETIMECHECKS_MEMBER_METHOD_CHECKER_HPP__
#define __UTILITIES_COMPILETIMECHECKS_MEMBER_METHOD_CHECKER_HPP__

#include "StaticAssert.hpp"


namespace Utilities
{
  namespace CompileTimeTools
  {
  }
}


#define CREATE_COMPILE_TIME_MEMBER_METHOD_CHECKER(MethodName,CheckerName) \
template < typename Implementator,typename Parameter,typename ReturnType> struct CheckerName{ \
  typedef char true_type[1];                                            \
  struct false_type {char no[2];};                                      \
  template<typename U, U> struct type_check;                            \
  typedef ReturnType(Implementator::*MethodSignature) (Parameter);      \
  template<typename T>	static true_type &chk(type_check<MethodSignature,&T::MethodName> * ); \
  template <typename > 	static false_type &chk(...);                    \
  static bool const value = sizeof(chk<Implementator>(0)) == sizeof(true_type); \
  static void Check(void){                                              \
    STATIC_ASSERT((value==true),ERROR_Unable_to_find_method);           \
  }                                                                     \
};                                                                      \
template <typename Implementator,typename ReturnType> struct CheckerName<Implementator,void,ReturnType>{ \
  typedef char true_type[1];                                            \
  struct false_type {char no[2];};                                      \
  template<typename U, U> struct type_check;                            \
  typedef ReturnType(Implementator::*MethodSignature) ();               \
  template<typename T>	static true_type &chk(type_check<MethodSignature,&T::MethodName> * ); \
  template <typename > 	static false_type &chk(...);                    \
  static bool const value = sizeof(chk<Implementator>(0)) == sizeof(true_type); \
  static void Check(void){                                              \
    STATIC_ASSERT((value==true),ERROR_Unable_to_find_method_2);         \
  }                                                                     \
}

#endif //__UTILITIES_COMPILETIMECHECKS_MEMBER_METHOD_CHECKER_HPP__
