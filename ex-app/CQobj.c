/** \file */

#include "CQobj.h"

/* ATTRIBUTES
 * ==========
 */

/* Private queue instances */
static CQqu_qu_t0 pv_qu0;
static CQqu_qu_t1 pv_qu1;

/* Global opaque pointers to queue objects */
CQqu_qu_t0* const CQobj_p_qu0 = &pv_qu0;
CQqu_qu_t1* const CQobj_p_qu1 = &pv_qu1;

/* Private buffers for queue objects */
static CQqu_elem_t0 pv_buf0[CQOBJ_BUFSIZ0] = {0};
static CQqu_elem_t1 pv_buf1[CQOBJ_BUFSIZ1] = {0};

/* OPERATIONS
 * ==========
 */

void CQobj_ctor0(void) {
    CQqu_init0(&pv_qu0, pv_buf0, CQOBJ_BUFSIZ0);
}

void CQobj_ctor1(void) {
    CQqu_init1(&pv_qu1, pv_buf1, CQOBJ_BUFSIZ1);
}
