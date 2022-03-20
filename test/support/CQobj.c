/** \file */

#include "CQobj.h"

/* ATTRIBUTES
 * ==========
 */

/* Private queue instance */
static CQqu_qu_t0 pv_qu0;

/* Global opaque pointer to queue object */
CQqu_qu_t0* const CQobj_p_qu0 = &pv_qu0;

/* OPERATIONS
 * ==========
 */

void CQobj_qu0Ctor(void) {
    static CQqu_item_t0 buf0[CQOBJ_BUF0_SIZ]; /* Buffer for queue object */

    CQqu_init0(&pv_qu0, buf0, CQOBJ_BUF0_SIZ);
}
