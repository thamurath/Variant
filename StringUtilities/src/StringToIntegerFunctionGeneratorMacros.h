/*
 * File:   StringToIntegerFunctionGeneratorMacros.h
 * Author: eojojos
 *
 * Created on 12 de noviembre de 2010, 10:16
 */

#ifndef __UTILITIES_STRINGTOINTEGERFUNCTIONGENERATORMACROS_H__
#define	__UTILITIES_STRINGTOINTEGERFUNCTIONGENERATORMACROS_H__

#include <stdint.h>
#include <errno.h>

/** @todo Try to convert this macros in templates.
 */

#define STRTOINT(bits, max)                                     \
static int                                                      \
strtoint##bits (const char *in, char **inend,                   \
                int##bits##_t *retval, int *err)                \
{                                                               \
    register const char *inptr = in;                            \
    int##bits##_t val = 0;                                      \
    int digit, sign = 1;                                        \
                                                                \
    while (*inptr == ' ')                                       \
        inptr++;                                                \
                                                                \
    if (*inptr == '-') {                                        \
        sign = -1;                                              \
        inptr++;                                                \
    }                                                           \
                                                                \
    in = inptr;                                                 \
    while (*inptr >= '0' && *inptr <= '9') {                    \
        digit = (*inptr - '0');                                 \
        if (val > (max / 10)) {                                 \
            *err = EOVERFLOW;                                   \
            return -1;                                          \
        } else if (val == (max / 10)) {                         \
            if (digit > (max % 10) &&                           \
                (sign > 0 || digit > ((max % 10) + 1))) {       \
                *err = EOVERFLOW;                               \
                return -1;                                      \
            }                                                   \
                                                                \
            if (sign < 0)                                       \
                val = (val * sign * 10) - digit;                \
            else                                                \
                val = (val * 10) + digit;                       \
                                                                \
            inptr++;                                            \
            if (*inptr >= '0' && *inptr <= '9') {               \
                *err = EOVERFLOW;                               \
                return -1;                                      \
            }                                                   \
                                                                \
            goto ret;                                           \
        } else {                                                \
            val = (val * 10) + digit;                           \
        }                                                       \
                                                                \
        inptr++;                                                \
    }                                                           \
                                                                \
    if (inptr == in) {                                          \
        *err = EINVAL;                                          \
        return -1;                                              \
    }                                                           \
                                                                \
    val *= sign;                                                \
                                                                \
 ret:                                                           \
    *inend = (char *) inptr;                                    \
    *retval = val;                                              \
                                                                \
    return 0;                                                   \
}

#define STRTOUINT(bits, max)                                    \
static int                                                      \
strtouint##bits (const char *in, char **inend,                  \
                 uint##bits##_t *retval, int *err)              \
{                                                               \
    register const char *inptr = in;                            \
    uint##bits##_t val = 0;                                     \
    unsigned int digit;                                                  \
                                                                \
    while (*inptr == ' ')                                       \
        inptr++;                                                \
                                                                \
    in = inptr;                                                 \
    while (*inptr >= '0' && *inptr <= '9') {                    \
        digit = (*inptr - '0');                                 \
        if (val > (max / 10)) {                                 \
            *err = EOVERFLOW;                                   \
            return -1;                                          \
        } else if (val == (max / 10) && digit > (max % 10)) {   \
            *err = EOVERFLOW;                                   \
            return -1;                                          \
        } else {                                                \
            val = (val * 10) + digit;                           \
        }                                                       \
                                                                \
        inptr++;                                                \
    }                                                           \
                                                                \
    if (inptr == in) {                                          \
        *err = EINVAL;                                          \
        return -1;                                              \
    }                                                           \
                                                                \
    *inend = (char *) inptr;                                    \
    *retval = val;                                              \
                                                                \
    return 0;                                                   \
}

#endif	/* __UTILITIES_STRINGTOINTEGERFUNCTIONGENERATORMACROS_H__ */

