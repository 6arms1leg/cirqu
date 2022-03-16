/** \file */

#ifndef CQTYP_H
#define CQTYP_H

#include <stdint.h>
#include <math.h>

/**
 * \{
 * \brief Optional type qualifiers
 *
 * For example `volatile`.
 * Empty if unused (but must be defined).
 */
#define CQTYP_ITEMQUAL_T0 /* Empty */
#define CQTYP_ITEMQUAL_T1 volatile
/** \} */

/**
 * \{
 * \brief Queue buffer item types
 */
typedef char CQtyp_item_t0;
typedef float_t CQtyp_item_t1;
/** \} */

/**
 * \{
 * \brief Queue buffer index types
 *
 * Must be unsigned integer, i.e. `uint8_t`, `uint16_t`, ...
 */
typedef uint8_t CQtyp_idx_t0;
typedef uint32_t CQtyp_idx_t1;
/** \} */

#endif /* CQTYP_H */
