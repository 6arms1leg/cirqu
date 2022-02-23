/** \file */

#ifndef BUFFEROBJECT_H
#define BUFFEROBJECT_H

/* United buffers module with multiple "instances" of CirQu library */
#include "cirquBufferUnited.h"

/* ATTRIBUTES
 * ==========
 */

#define BUF0STRGSIZE (4U)
#define BUF1STRGSIZE (6U)

/* `-1` because one element slot is used to distinguish full and empty fill
 * level
 */
#define BUF0ELEMSIZE (BUF0STRGSIZE - 1U)
#define BUF1ELEMSIZE (BUF1STRGSIZE - 1U)

/* Global opaque pointers to buffer objects */
extern stc_bffr_t0* const p_stc_bffr_g_buf0;
extern stc_bffr_t1* const p_stc_bffr_g_buf1;

/* OPERATIONS
 * ==========
 */

/* Constructors of buffer objects */
void fn_bffrObj_buf0Ctor(void);
void fn_bffrObj_buf1Ctor(void);

#endif /* BUFFEROBJECT_H */
