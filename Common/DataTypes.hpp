#ifndef __COMMON_DATATYPES_HPP__
#define __COMMON_DATATYPES_HPP__

#include <stdint.h>

typedef int32_t ResultCode_t;


static const ResultCode_t SUCCESS = 0;
static const ResultCode_t FAILURE = ~SUCCESS;

//non error results
static const ResultCode_t CONVERT_OK = SUCCESS+1;



//errors
static const ResultCode_t CONVERT_NOK = SUCCESS-1;

#endif /* __COMMON_DATATYPES_HPP__ */
