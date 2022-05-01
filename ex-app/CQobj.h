/** \file */

#ifndef CQOBJ_H
#define CQOBJ_H

#include "CQwrap.h" /* Wrapper module with multiple "instances" of CirQu lib. */

#define CQOBJ_BUF0ALPHA_SIZ 4u
#define CQOBJ_BUF0BETA_SIZ 3u
#define CQOBJ_BUF1_SIZ 6u

/* One item slot used to discern full/empty fill level */
#define CQOBJ_QU0ALPHA_SIZ (CQOBJ_BUF0ALPHA_SIZ - 1u)
#define CQOBJ_QU0BETA_SIZ (CQOBJ_BUF0BETA_SIZ - 1u)
#define CQOBJ_QU1_SIZ (CQOBJ_BUF1_SIZ - 1u)

/* ATTRIBUTES
 * ==========
 */

/**
 * \{
 * \brief Global opaque pointers to queue objects
 */
extern CQqu_qu_t0* const CQobj_p_qu0Alpha;
extern CQqu_qu_t0* const CQobj_p_qu0Beta;
extern CQqu_qu_t1* const CQobj_p_qu1;
/** \} */

/* OPERATIONS
 * ==========
 */

/**
 * \{
 * \brief Constructors of queue objects
 */
void CQobj_qu0AlphaCtor(void);
void CQobj_qu0BetaCtor(void);
void CQobj_qu1Ctor(void);
/** \} */

#endif /* CQOBJ_H */
