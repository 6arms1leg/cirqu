/** \file */

#include "CQbuf.h"

/* ATTRIBUTES
 * ==========
 */

/* Private buffer instances */
static CQqu_qu_t0 stc_bffr_pv_buf0;
static CQqu_qu_t1 stc_bffr_pv_buf1;

/* Global opaque pointers to buffer objects */
CQqu_qu_t0* const p_stc_bffr_g_buf0 = &stc_bffr_pv_buf0;
CQqu_qu_t1* const p_stc_bffr_g_buf1 = &stc_bffr_pv_buf1;

/* Private storages for buffer objects */
static CQqu_strgElem_t0 a_cirquStrgElem_pv_buf0Strg[CQBUF_STRGSIZ0] = {0};
static CQqu_strgElem_t1 a_cirquStrgElem_pv_buf1Strg[CQBUF_STRGSIZ1] = {0};

/* OPERATIONS
 * ==========
 */

void CQbuf_ctor0(void)
{
    CQqu_init0(&stc_bffr_pv_buf0, a_cirquStrgElem_pv_buf0Strg, CQBUF_STRGSIZ0);

    return;
}

void CQbuf_ctor1(void)
{
    CQqu_init1(&stc_bffr_pv_buf1, a_cirquStrgElem_pv_buf1Strg, CQBUF_STRGSIZ1);

    return;
}
