/** \file */

#include "CQbuf.h"

/* ATTRIBUTES
 * ==========
 */

/* Private buffer instances */
static CQqu_qu_t0 pv_buf0;
static CQqu_qu_t1 pv_buf1;

/* Global opaque pointers to buffer objects */
CQqu_qu_t0* const CQbuf_p_buf0 = &pv_buf0;
CQqu_qu_t1* const CQbuf_p_buf1 = &pv_buf1;

/* Private storages for buffer objects */
static CQqu_strgElem_t0 pv_bufStrg0[CQBUF_STRGSIZ0] = {0};
static CQqu_strgElem_t1 pv_bufStrg1[CQBUF_STRGSIZ1] = {0};

/* OPERATIONS
 * ==========
 */

void CQbuf_ctor0(void) {
    CQqu_init0(&pv_buf0, pv_bufStrg0, CQBUF_STRGSIZ0);
}

void CQbuf_ctor1(void) {
    CQqu_init1(&pv_buf1, pv_bufStrg1, CQBUF_STRGSIZ1);
}
