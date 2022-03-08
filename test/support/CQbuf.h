/** \file */

#ifndef CQBUF_H
#define CQBUF_H

/* Include CirQu buffer interface (configured with ID 0).
 * "External" include guards necessary since included module interface has none
 * due to "template" feature.
 */
#ifndef CQQU_H0
#define CQQU_H0
#define CQTEMPLSEUP_ID 0
#include "CQqu.h"
#undef CQTEMPLSEUP_ID
#endif /* CQQU_H0 */

/* ATTRIBUTES
 * ==========
 */

#define CQBUF_STRGSIZ0 (4u)
#define CQBUF_ELEMSIZ0 (CQBUF_STRGSIZ0 - 1u)
    /* `-1` because one element slot is used to distinguish full and empty fill
       level */

/* Global opaque pointers to buffer objects */
extern stc_bffr_t0* const p_stc_bffr_g_buf0;

/* OPERATIONS
 * ==========
 */

/* Constructors of buffer objects */
void CQbuf_ctor0(void);

#endif /* CQBUF_H */
