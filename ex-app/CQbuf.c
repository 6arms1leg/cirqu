/** \file */

#include "CQbuf.h"

/* ATTRIBUTES
 * ==========
 */

/* Private buffer instances */
static stc_bffr_t0 stc_bffr_pv_buf0;
static stc_bffr_t1 stc_bffr_pv_buf1;

/* Global opaque pointers to buffer objects */
stc_bffr_t0* const p_stc_bffr_g_buf0 = &stc_bffr_pv_buf0;
stc_bffr_t1* const p_stc_bffr_g_buf1 = &stc_bffr_pv_buf1;

/* Private storages for buffer objects */
static cirquStrgElem_t0 a_cirquStrgElem_pv_buf0Strg[BUF0STRGSIZE] = {0};
static cirquStrgElem_t1 a_cirquStrgElem_pv_buf1Strg[BUF1STRGSIZE] = {0};

/* OPERATIONS
 * ==========
 */

void fn_bffrObj_buf0Ctor(void)
{
    fn_bffr_ini0(&stc_bffr_pv_buf0, a_cirquStrgElem_pv_buf0Strg, BUF0STRGSIZE);

    return;
}

void fn_bffrObj_buf1Ctor(void)
{
    fn_bffr_ini1(&stc_bffr_pv_buf1, a_cirquStrgElem_pv_buf1Strg, BUF1STRGSIZE);

    return;
}
