/** \file */

#include "bufferObject.h"

/* ATTRIBUTES
 * ==========
 */

/* Private buffer 0 instance */
static stc_bffr_t stc_bffr_pv_buf0;

/* Global opaque pointer to buffer object "buffer 0" */
stc_bffr_t* const p_stc_bffr_g_buf0 = &stc_bffr_pv_buf0;

/* Private storage for buffer object "buffer 0" */
static cirquStrgElem_t a_cirquStrgElem_pv_buf0Strg[BUF0STRGSIZE] =
    { (uint8_t)0U };

/* OPERATIONS
 * ==========
 */

void fn_bffrObj_buf0Ctor(void)
{
    fn_bffr_ini(&stc_bffr_pv_buf0, a_cirquStrgElem_pv_buf0Strg,
                (uint8_t)BUF0STRGSIZE);

    return;
}
