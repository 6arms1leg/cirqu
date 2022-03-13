/** \file */

#ifndef CQOBJ_H
#define CQOBJ_H

/* Wrapper module with multiple "instances" of CirQu library */
#include "CQwrap.h"

/* ATTRIBUTES
 * ==========
 */

#define CQOBJ_BUFSIZ0 4u
#define CQOBJ_BUFSIZ1 6u

/* `-1` because one item slot is used to distinguish full and empty fill level */
#define CQOBJ_QUSIZ0 (CQOBJ_BUFSIZ0 - 1u)
#define CQOBJ_QUSIZ1 (CQOBJ_BUFSIZ1 - 1u)

/* Global opaque pointers to queue objects */
extern CQqu_qu_t0* const CQobj_p_qu0;
extern CQqu_qu_t1* const CQobj_p_qu1;

/* OPERATIONS
 * ==========
 */

/* Constructors of queue objects */
void CQobj_ctor0(void);
void CQobj_ctor1(void);

#endif /* CQOBJ_H */
