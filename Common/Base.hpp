#ifndef __COMMON_BASE_HPP__
#define __COMMON_BASE_HPP__



#define UNUSED(x)\
do\
{\
 (void)(x);\
}while(false)\

#define STRINGIFY(x) #x  /**< This macro "convert" the input param  to string  *WITHOUT* evaluate it */
#define TO_STRING(x) STRINGIFY(x) /**< This macro evaluate the input parameter and then "convert" it to atring */


#endif // __COMMON_BASE_HPP__
