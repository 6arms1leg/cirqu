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
static CQqu_elem_t0 pv_buf0[CQOBJ_BUFSIZ0] = {0u};

/* OPERATIONS
 * ==========
 */

void CQobj_ctor0(void) {
    CQqu_init0(&pv_qu0, pv_buf0, CQOBJ_BUFSIZ0);
}
