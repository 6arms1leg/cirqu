/** \file */

#ifndef INCLUDE_BUFFEROBJECT_H
#define INCLUDE_BUFFEROBJECT_H

#include <stdint.h>

#include "buffer.h"

/* ATTRIBUTES
 * ==========
 */

#define BUF0STRGSIZE ( (cirquElemIdx_t)4U )
#define BUF0ELEMSIZE (BUF0STRGSIZE - (cirquElemIdx_t)1U) /* *-1*, because one
                                                            element slot is use
                                                            to distinguish full
                                                            and empty fill
                                                            level. */

/* Global opaque pointer to buffer object "buffer 0" */
extern stc_bffr_t* const p_stc_bffr_g_buf0;

/* OPERATIONS
 * ==========
 */

/* Constructor of buffer object "buffer 0" */
void fn_bffrObj_buf0Ctor(void);

#endif /* INCLUDE_BUFFEROBJECT_H */
