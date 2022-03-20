/** \file */

#include "CQobj.h"

/* ATTRIBUTES
 * ==========
 */

/* Private queue instance */
static CQqu_qu_t0 pv_qu0;

/* Global opaque pointer to queue object */
CQqu_qu_t0* const CQobj_p_qu0 = &pv_qu0;

/* Private buffer for queue object */
static CQqu_item_t0 pv_buf0[CQOBJ_BUF0_SIZ];

/* OPERATIONS
 * ==========
 */

void CQobj_qu0Ctor(void) {
    CQqu_init0(&pv_qu0, pv_buf0, CQOBJ_BUF0_SIZ);
}
