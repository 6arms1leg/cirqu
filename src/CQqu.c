/** \file */

#include "CQqu.h"

/* Setup template to allow multiple "instances" of library */
#include "CQtemplSeUp.h"
#define advHead(a) CQTEMPLSEUP_CAT(advHead, CQTEMPLSEUP_ID)(a)
#define advTail(a) CQTEMPLSEUP_CAT(advTail, CQTEMPLSEUP_ID)(a)
#define retHead(a) CQTEMPLSEUP_CAT(retHead, CQTEMPLSEUP_ID)(a)
#define retTail(a) CQTEMPLSEUP_CAT(retTail, CQTEMPLSEUP_ID)(a)

/* OPERATIONS
 * ==========
 */

/* Modulo operations intentionally not used to handle head/tail wrap around in
 * order to save CPU cycles
 */

/**
 * \brief Advance head pointer by one element (correctly handles wrap around)
 *
 * \param me Pointer to queue object
 */
static inline void advHead(CQqu_qu_t* const me) {
    /* No sanity check necessary since `me` argument was already checked in API
     * functions
     */

    /* If head points to last element */
    if (me->bufSiz - 1u == me->head) {
        /* Wrap head around to first element */
        me->head = 0u;
    }
    else {
        me->head++;
    }
}

/**
 * \brief Advance tail pointer by one element (correctly handles wrap around)
 *
 * \param me Pointer to queue object
 */
static void advTail(CQqu_qu_t* const me) {
    /* No sanity check necessary since `me` argument was already checked in API
     * functions
     */

    /* If tail points to last element */
    if (me->bufSiz - 1u == me->tail) {
        /* Wrap tail around to first element */
        me->tail = 0u;
    }
    else {
        me->tail++;
    }
}

/**
 * \brief Retreat head pointer by one element (correctly handles wrap around)
 *
 * \param me Pointer to queue object
 */
static inline void retHead(CQqu_qu_t* const me) {
    /* No sanity check necessary since `me` argument was already checked in API
     * functions
     */

    /* If head points to first element */
    if (0u == me->head) {
        /* Wrap head around to last element */
        me->head = me->bufSiz - (CQtyp_idx_t)1u;
    }
    else {
        me->head--;
    }
}

/**
 * \brief Retreat tail pointer by one element (correctly handles wrap around)
 *
 * \param me Pointer to queue object
 */
static inline void retTail(CQqu_qu_t* const me) {
    /* No sanity check necessary since `me` argument was already checked in API
     * functions
     */

    /* If tail points to first element */
    if (0u == me->tail) {
        /* Wrap tail around to last element */
        me->tail = me->bufSiz - (CQtyp_idx_t)1u;
    }
    else {
        me->tail--;
    }
}

void CQqu_init(CQqu_qu_t* const me,
               CQqu_elem_t* const p_buf,
               const CQtyp_idx_t bufSiz) {
    /* Sanity check (Design by Contract) */
    assert((NULL != me) &&
           (NULL != p_buf) &&
           (1u < bufSiz));

    me->p_buf = p_buf;
    me->bufSiz = bufSiz;

    /* Initialize queue to empty state */
    me->head = 0u;
    me->tail = 0u;
}

void CQqu_pushHead(CQqu_qu_t* const me, const CQtyp_elem_t elem) {
    /* Sanity check (Design by Contract) */
    assert(NULL != me);

    /* If full */
    if (0u == CQqu_cntFree(me)) {
        advTail(me);
    }

    me->p_buf[me->head] = elem;
    advHead(me);
}

void CQqu_pushTail(CQqu_qu_t* const me, const CQtyp_elem_t elem) {
    /* Sanity check (Design by Contract) */
    assert(NULL != me);

    /* If full */
    if (0u == CQqu_cntFree(me)) {
        retHead(me);
    }

    retTail(me);
    me->p_buf[me->tail] = elem;
}

bool CQqu_pull(CQqu_qu_t* const me, CQtyp_elem_t* const p_elem) {
    /* Sanity check (Design by Contract) */
    assert((NULL != me) &&
           (NULL != p_elem));

    bool res = false;

    /* If not empty */
    if (me->bufSiz - 1u > CQqu_cntFree(me)) {
        *p_elem = me->p_buf[me->tail];
        advTail(me);

        res = true;
    }

    return (res);
}

const CQTYP_ELEMQUAL_T CQtyp_elem_t* CQqu_peek(const CQqu_qu_t* const me,
                                               const CQtyp_idx_t elemPos) {
    /* Sanity check (Design by Contract) */
    assert((NULL != me) &&
           (me->bufSiz - 1u > elemPos));

    /* Initialize variable used in peek element position calculation and return
     * pointer
     */
    CQtyp_idx_t diff = 0u;
    const CQTYP_ELEMQUAL_T CQtyp_elem_t* p_elem = NULL;

    /* If requested element position is in range (points to non-vacant element
     * slot)
     */
    if (me->bufSiz - 1u - CQqu_cntFree(me) > elemPos) {
        /* Handle wrap around */
        diff = me->bufSiz - me->tail;
        if (diff <= elemPos) {
            p_elem = &me->p_buf[elemPos - diff];
        }
        else {
            p_elem = &me->p_buf[me->tail + elemPos];
        }
    }

    return (p_elem);
}

CQtyp_idx_t CQqu_cntFree(const CQqu_qu_t* const me) {
    /* Sanity check (Design by Contract) */
    assert(NULL != me);

    /* Initialize variable used in free element count calculation */
    CQtyp_idx_t elemFreeCnt = 0u;

    if (me->tail <= me->head) {
        elemFreeCnt = (CQtyp_idx_t)(me->bufSiz - 1u - (me->head - me->tail));
    }
    else {
        elemFreeCnt = (CQtyp_idx_t)(me->tail - me->head - 1u);
    }

    return (elemFreeCnt);
}

/* Cleanup template (multiple "instances") */
#include "CQtemplClUp.h"
#undef advHead
#undef advTail
#undef retHead
#undef retTail
