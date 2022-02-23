/** \file */

#include "bufferObject.h"

/* ATTRIBUTES
 * ==========
 */

/* Private buffer instances */
static stc_bffr_t0 stc_bffr_pv_buf0;

/* Global opaque pointers to buffer objects */
stc_bffr_t0* const p_stc_bffr_g_buf0 = &stc_bffr_pv_buf0;

/* Private storages for buffer objects */
static cirquStrgElem_t0 a_cirquStrgElem_pv_buf0Strg[BUF0STRGSIZE] =
    { (uint8_t)0U };

/* OPERATIONS
 * ==========
 */

void fn_bffrObj_buf0Ctor(void)
{
    fn_bffr_ini0(&stc_bffr_pv_buf0, a_cirquStrgElem_pv_buf0Strg,
                (uint8_t)BUF0STRGSIZE);

    return;
}
