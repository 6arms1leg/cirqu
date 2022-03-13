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
 * \brief Advance head pointer by one item (correctly handles wrap around)
 *
 * \param me Pointer to queue object
 */
static inline void advHead(CQqu_qu_t* const me) {
    /* No sanity check necessary since `me` argument was already checked in API
     * functions
     */

    /* If head points to last item */
    if (me->bufSiz - 1u == me->head) {
        /* Wrap head around to first item */
        me->head = 0u;
    }
    else {
        me->head++;
    }
}

/**
 * \brief Advance tail pointer by one item (correctly handles wrap around)
 *
 * \param me Pointer to queue object
 */
static void advTail(CQqu_qu_t* const me) {
    /* No sanity check necessary since `me` argument was already checked in API
     * functions
     */

    /* If tail points to last item */
    if (me->bufSiz - 1u == me->tail) {
        /* Wrap tail around to first item */
        me->tail = 0u;
    }
    else {
        me->tail++;
    }
}

/**
 * \brief Retreat head pointer by one item (correctly handles wrap around)
 *
 * \param me Pointer to queue object
 */
static inline void retHead(CQqu_qu_t* const me) {
    /* No sanity check necessary since `me` argument was already checked in API
     * functions
     */

    /* If head points to first item */
    if (0u == me->head) {
        /* Wrap head around to last item */
        me->head = me->bufSiz - (CQtyp_idx_t)1u;
    }
    else {
        me->head--;
    }
}

/**
 * \brief Retreat tail pointer by one item (correctly handles wrap around)
 *
 * \param me Pointer to queue object
 */
static inline void retTail(CQqu_qu_t* const me) {
    /* No sanity check necessary since `me` argument was already checked in API
     * functions
     */

    /* If tail points to first item */
    if (0u == me->tail) {
        /* Wrap tail around to last item */
        me->tail = me->bufSiz - (CQtyp_idx_t)1u;
    }
    else {
        me->tail--;
    }
}

void CQqu_init(CQqu_qu_t* const me,
               CQqu_item_t* const p_buf,
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

void CQqu_pushHead(CQqu_qu_t* const me, const CQtyp_item_t item) {
    /* Sanity check (Design by Contract) */
    assert(NULL != me);

    /* If full */
    if (0u == CQqu_cntFree(me)) {
        advTail(me);
    }

    me->p_buf[me->head] = item;
    advHead(me);
}

void CQqu_pushTail(CQqu_qu_t* const me, const CQtyp_item_t item) {
    /* Sanity check (Design by Contract) */
    assert(NULL != me);

    /* If full */
    if (0u == CQqu_cntFree(me)) {
        retHead(me);
    }

    retTail(me);
    me->p_buf[me->tail] = item;
}

bool CQqu_pull(CQqu_qu_t* const me, CQtyp_item_t* const p_item) {
    /* Sanity check (Design by Contract) */
    assert((NULL != me) &&
           (NULL != p_item));

    bool res = false;

    /* If not empty */
    if (me->bufSiz - 1u > CQqu_cntFree(me)) {
        *p_item = me->p_buf[me->tail];
        advTail(me);

        res = true;
    }

    return (res);
}

const CQTYP_ITEMQUAL_T CQtyp_item_t* CQqu_peek(const CQqu_qu_t* const me,
                                               const CQtyp_idx_t itemPos) {
    /* Sanity check (Design by Contract) */
    assert((NULL != me) &&
           (me->bufSiz - 1u > itemPos));

    /* Initialize variable used in peek item position calculation and return
     * pointer
     */
    CQtyp_idx_t diff = 0u;
    const CQTYP_ITEMQUAL_T CQtyp_item_t* p_item = NULL;

    /* If requested item position is in range (points to non-vacant item slot) */
    if (me->bufSiz - 1u - CQqu_cntFree(me) > itemPos) {
        /* Handle wrap around */
        diff = me->bufSiz - me->tail;
        if (diff <= itemPos) {
            p_item = &me->p_buf[itemPos - diff];
        }
        else {
            p_item = &me->p_buf[me->tail + itemPos];
        }
    }

    return (p_item);
}

CQtyp_idx_t CQqu_cntFree(const CQqu_qu_t* const me) {
    /* Sanity check (Design by Contract) */
    assert(NULL != me);

    /* Initialize variable used in free item count calculation */
    CQtyp_idx_t itemFreeCnt = 0u;

    if (me->tail <= me->head) {
        itemFreeCnt = (CQtyp_idx_t)(me->bufSiz - 1u - (me->head - me->tail));
    }
    else {
        itemFreeCnt = (CQtyp_idx_t)(me->tail - me->head - 1u);
    }

    return (itemFreeCnt);
}

/* Cleanup template (multiple "instances") */
#include "CQtemplClUp.h"
#undef advHead
#undef advTail
#undef retHead
#undef retTail
