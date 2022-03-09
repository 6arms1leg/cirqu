/** \file */

#ifndef CQTYP_H
#define CQTYP_H

/* Include libc interfaces */
#include <stdint.h>

/* Optional type qualifiers, e.g. `volatile`.
 * Empty if unused (but must be defined).
 */
#define CQTYP_ELEMQUAL_T0 /* Empty */

/* Buffer element types */
typedef uint8_t CQtyp_elem_t0;

/* Buffer index types.
 * Must be unsigned integer, i.e. `uint8_t`, `uint16_t`, ...
 */
typedef uint8_t CQtyp_idx_t0;

#endif /* CQTYP_H */
