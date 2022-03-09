/** \file */

#include "CQbuf.h"

/* ATTRIBUTES
 * ==========
 */

/* Private buffer instances */
static CQqu_qu_t0 stc_bffr_pv_buf0;

/* Global opaque pointers to buffer objects */
CQqu_qu_t0* const p_stc_bffr_g_buf0 = &stc_bffr_pv_buf0;

/* Private storages for buffer objects */
static CQqu_strgElem_t0 a_cirquStrgElem_pv_buf0Strg[CQBUF_STRGSIZ0] = {0u};

/* OPERATIONS
 * ==========
 */

void CQbuf_ctor0(void)
{
    CQqu_init0(&stc_bffr_pv_buf0, a_cirquStrgElem_pv_buf0Strg, CQBUF_STRGSIZ0);

    return;
}
