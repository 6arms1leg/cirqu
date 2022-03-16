/** \file */

#ifndef CQOBJ_H
#define CQOBJ_H

/* CirQu queue interface configured with ID.
   "External" include guards necessary since included module interface has none
   due to "template" feature. */
#ifndef CQQU_H0
#define CQQU_H0
#define CQTEMPLSEUP_ID 0
#include "CQqu.h"
#undef CQTEMPLSEUP_ID
#endif /* CQQU_H0 */

/* ATTRIBUTES
 * ==========
 */

#define CQOBJ_BUF0_SIZ 4u
#define CQOBJ_QU0_SIZ (CQOBJ_BUF0_SIZ - 1u)
    /* `-1` because one item slot is used to distinguish full and empty fill
       level */

/** \brief Global opaque pointer to queue object */
extern CQqu_qu_t0* const CQobj_p_qu0;

/* OPERATIONS
 * ==========
 */

/** \brief Constructor of queue object */
void CQobj_qu0Ctor(void);

#endif /* CQOBJ_H */
