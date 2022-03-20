/** \file */

#include "CQobj.h"

/* ATTRIBUTES
 * ==========
 */

/* Private queue instances */
static CQqu_qu_t0 pv_qu0Alpha;
static CQqu_qu_t0 pv_qu0Beta;
static CQqu_qu_t1 pv_qu1;

/* Global opaque pointers to queue objects */
CQqu_qu_t0* const CQobj_p_qu0Alpha = &pv_qu0Alpha;
CQqu_qu_t0* const CQobj_p_qu0Beta = &pv_qu0Beta;
CQqu_qu_t1* const CQobj_p_qu1 = &pv_qu1;

/* OPERATIONS
 * ==========
 */

void CQobj_qu0AlphaCtor(void) {
    static CQqu_item_t0 buf0Alpha[CQOBJ_BUF0ALPHA_SIZ]; /* Buffer for queue
                                                           object */

    CQqu_init0(&pv_qu0Alpha, buf0Alpha, CQOBJ_BUF0ALPHA_SIZ);
}

void CQobj_qu0BetaCtor(void) {
    static CQqu_item_t0 buf0Beta[CQOBJ_BUF0BETA_SIZ]; /* Buffer for queue
                                                         object */

    CQqu_init0(&pv_qu0Beta, buf0Beta, CQOBJ_BUF0BETA_SIZ);
}

void CQobj_qu1Ctor(void) {
    static CQqu_item_t1 buf1[CQOBJ_BUF1_SIZ]; /* Buffer for queue object */

    CQqu_init1(&pv_qu1, buf1, CQOBJ_BUF1_SIZ);
}
