/** \file */

#ifndef CQBUF_H
#define CQBUF_H

/* Wrapper module with multiple "instances" of CirQu library */
#include "CQwrap.h"

/* ATTRIBUTES
 * ==========
 */

#define BUF0STRGSIZE (4u)
#define BUF1STRGSIZE (6u)

/* `-1` because one element slot is used to distinguish full and empty fill
 * level
 */
#define BUF0ELEMSIZE (BUF0STRGSIZE - 1u)
#define BUF1ELEMSIZE (BUF1STRGSIZE - 1u)

/* Global opaque pointers to buffer objects */
extern stc_bffr_t0* const p_stc_bffr_g_buf0;
extern stc_bffr_t1* const p_stc_bffr_g_buf1;

/* OPERATIONS
 * ==========
 */

/* Constructors of buffer objects */
void fn_bffrObj_buf0Ctor(void);
void fn_bffrObj_buf1Ctor(void);

#endif /* CQBUF_H */
