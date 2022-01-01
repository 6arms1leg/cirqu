/** \file */

#ifndef INCLUDE_CIRQUELEMTYPE_H
#define INCLUDE_CIRQUELEMTYPE_H

#include <stdint.h>

#define CIRQUELEMQUAL_T /* Optional type qualifier, e.g. `volatile`. Empty if
                           unused (but must be defined). */
typedef uint8_t cirquElem_t;
typedef uint8_t cirquElemIdx_t; /* Must be unsigned integer, i.e. `uint8_t`,
                                   `uint16_t`, ... */

#endif /* INCLUDE_CIRQUELEMTYPE_H */
