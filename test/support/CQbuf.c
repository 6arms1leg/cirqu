/** \file */

#include "CQbuf.h"

/* ATTRIBUTES
 * ==========
 */

/* Private buffer instances */
static CQqu_qu_t0 pv_buf0;

/* Global opaque pointers to buffer objects */
CQqu_qu_t0* const CQbuf_p_buf0 = &pv_buf0;

/* Private storages for buffer objects */
static CQqu_strgElem_t0 pv_bufStrg0[CQBUF_STRGSIZ0] = {0u};

/* OPERATIONS
 * ==========
 */

void CQbuf_ctor0(void)
{
    CQqu_init0(&pv_buf0, pv_bufStrg0, CQBUF_STRGSIZ0);

    return;
}
