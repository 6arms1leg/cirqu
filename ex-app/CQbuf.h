/** \file */

#ifndef CQBUF_H
#define CQBUF_H

/* Wrapper module with multiple "instances" of CirQu library */
#include "CQwrap.h"

/* ATTRIBUTES
 * ==========
 */

#define CQBUF_STRGSIZ0 (4u)
#define CQBUF_STRGSIZ1 (6u)

/* `-1` because one element slot is used to distinguish full and empty fill
 * level
 */
#define CQBUF_ELEMSIZ0 (CQBUF_STRGSIZ0 - 1u)
#define CQBUF_ELEMSIZ1 (CQBUF_STRGSIZ1 - 1u)

/* Global opaque pointers to buffer objects */
extern stc_bffr_t0* const p_stc_bffr_g_buf0;
extern stc_bffr_t1* const p_stc_bffr_g_buf1;

/* OPERATIONS
 * ==========
 */

/* Constructors of buffer objects */
void CQbuf_ctor0(void);
void CQbuf_ctor1(void);

#endif /* CQBUF_H */
