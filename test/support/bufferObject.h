/** \file */

#ifndef BUFFEROBJECT_H
#define BUFFEROBJECT_H

/* Include CirQu buffer interface (configured with ID 0).
 * "External" include guards necessary since included module interface has none
 * due to "template" feature.
 */
#ifndef BUFFER_H0
#define BUFFER_H0
#define CIRQUID 0
#include "buffer.h"
#undef CIRQUID
#endif /* BUFFER_H0 */

/* ATTRIBUTES
 * ==========
 */

#define BUF0STRGSIZE (4U)
#define BUF0ELEMSIZE (BUF0STRGSIZE - 1U)
    /* `-1` because one element slot is used to distinguish full and empty fill
       level */

/* Global opaque pointers to buffer objects */
extern stc_bffr_t0* const p_stc_bffr_g_buf0;

/* OPERATIONS
 * ==========
 */

/* Constructors of buffer objects */
void fn_bffrObj_buf0Ctor(void);

#endif /* BUFFEROBJECT_H */
