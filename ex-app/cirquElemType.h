/** \file */

#ifndef CIRQUELEMTYPE_H
#define CIRQUELEMTYPE_H

/* Include libc interfaces */
#include <stdint.h>

/* Optional type qualifiers, e.g. `volatile`.
 * Empty if unused (but must be defined).
 */
#define CIRQUELEMQUAL_T0 volatile
#define CIRQUELEMQUAL_T1

/* Buffer element types */
typedef uint8_t cirquElem_t0;
typedef uint32_t cirquElem_t1;

/* Buffer index types.
 * Must be unsigned integer, i.e. `uint8_t`, `uint16_t`, ...
 */
typedef uint8_t cirquElemIdx_t0;
typedef uint32_t cirquElemIdx_t1;

#endif /* CIRQUELEMTYPE_H */
