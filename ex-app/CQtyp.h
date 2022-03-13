/** \file */

#ifndef CQTYP_H
#define CQTYP_H

/* libc interfaces */
#include <stdint.h>
#include <math.h>

/* Optional type qualifiers, e.g. `volatile`
 *
 * Empty if unused (but must be defined).
 */
#define CQTYP_ELEMQUAL_T0 /* Empty */
#define CQTYP_ELEMQUAL_T1 volatile

/* Queue buffer element types */
typedef char CQtyp_elem_t0;
typedef float_t CQtyp_elem_t1;

/* Queue buffer index types
 *
 * Must be unsigned integer, i.e. `uint8_t`, `uint16_t`, ...
 */
typedef uint8_t CQtyp_idx_t0;
typedef uint32_t CQtyp_idx_t1;

#endif /* CQTYP_H */
