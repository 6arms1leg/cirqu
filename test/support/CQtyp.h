/** \file */

#ifndef CQTYP_H
#define CQTYP_H

/* libc interface */
#include <stdint.h>

/* Optional type qualifiers, e.g. `volatile`
 *
 * Empty if unused (but must be defined).
 */
#define CQTYP_ITEMQUAL_T0 /* Empty */

/* Queue buffer item types */
typedef uint8_t CQtyp_item_t0;

/* Queue buffer index types
 *
 * Must be unsigned integer, i.e. `uint8_t`, `uint16_t`, ...
 */
typedef uint8_t CQtyp_idx_t0;

#endif /* CQTYP_H */
