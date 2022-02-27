/** \file */

#ifndef CIRQUELEMTYPE_H
#define CIRQUELEMTYPE_H

/* Include libc interfaces */
#include <stdint.h>
#include <math.h>

/* Optional type qualifiers, e.g. `volatile`.
 * Empty if unused (but must be defined).
 */
#define CIRQUELEMQUAL_T0 /* Empty */
#define CIRQUELEMQUAL_T1 volatile

/* Buffer element types */
typedef char cirquElem_t0;
typedef float_t cirquElem_t1;

/* Buffer index types.
 * Must be unsigned integer, i.e. `uint8_t`, `uint16_t`, ...
 */
typedef uint8_t cirquElemIdx_t0;
typedef uint32_t cirquElemIdx_t1;

#endif /* CIRQUELEMTYPE_H */
