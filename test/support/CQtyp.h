/** \file */

#ifndef CQTYP_H
#define CQTYP_H

/* libc interface */
#include <stdint.h>

/**
 * \brief Optional type qualifier
 *
 * For example `volatile`.
 * Empty if unused (but must be defined).
 */
#define CQTYP_ITEMQUAL_T0 /* Empty */

/** \brief Queue buffer item type */
typedef uint8_t CQtyp_item_t0;

/**
 * \brief Queue buffer index type
 *
 * Must be unsigned integer, i.e. `uint8_t`, `uint16_t`, ...
 */
typedef uint8_t CQtyp_idx_t0;

#endif /* CQTYP_H */
