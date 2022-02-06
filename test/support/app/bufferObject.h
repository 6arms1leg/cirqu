/** \file */

#ifndef BUFFEROBJECT_H
#define BUFFEROBJECT_H

#include "buffer.h"

/* ATTRIBUTES
 * ==========
 */

#define BUF0STRGSIZE (4U)
#define BUF0ELEMSIZE (BUF0STRGSIZE - 1U)
    /* `-1` because one element slot is used to distinguish full and empty
       fill level */

/* Global opaque pointer to buffer object "buffer 0" */
extern stc_bffr_t* const p_stc_bffr_g_buf0;

/* OPERATIONS
 * ==========
 */

/* Constructor of buffer object "buffer 0" */
void fn_bffrObj_buf0Ctor(void);

#endif /* BUFFEROBJECT_H */
