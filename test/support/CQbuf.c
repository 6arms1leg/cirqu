/** \file */

#include "CQbuf.h"

/* ATTRIBUTES
 * ==========
 */

/* Private buffer instances */
static stc_bffr_t0 stc_bffr_pv_buf0;

/* Global opaque pointers to buffer objects */
stc_bffr_t0* const p_stc_bffr_g_buf0 = &stc_bffr_pv_buf0;

/* Private storages for buffer objects */
static cirquStrgElem_t0 a_cirquStrgElem_pv_buf0Strg[BUF0STRGSIZE] = {0u};

/* OPERATIONS
 * ==========
 */

void CQbuf_ctor0(void)
{
    CQqu_init0(&stc_bffr_pv_buf0, a_cirquStrgElem_pv_buf0Strg, BUF0STRGSIZE);

    return;
}
