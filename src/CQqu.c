/** \file */

#include "CQqu.h"

/* Setup template (allow multiple "instances" of lib.) */
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
    /* No sanity check necessary; `me` arg. already checked in API functions */

    if (me->bufSiz - 1u == me->head) { /* Head points to last item? */
        me->head = 0u; /* Wrap head around to first item */
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
    /* No sanity check necessary; `me` arg. already checked in API functions */

    if (me->bufSiz - 1u == me->tail) { /* Tail points to last item? */
        me->tail = 0u; /* Wrap tail around to first item */
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
    /* No sanity check necessary; `me` arg. already checked in API functions */

    if (0u == me->head) { /* Head points to first item? */
        me->head = me->bufSiz - (CQtyp_idx_t)1u;
            /* Wrap head around to last item; explicit type cast needed (safe
               here) */
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
    /* No sanity check necessary; `me` arg. already checked in API functions */

    if (0u == me->tail) { /* Tail points to first item? */
        me->tail = me->bufSiz - (CQtyp_idx_t)1u;
            /* Wrap tail around to last item; explicit type cast needed (safe
               here) */
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

    /* Init. queue to empty state */
    me->head = 0u;
    me->tail = 0u;
}

void CQqu_pushHead(CQqu_qu_t* const me, const CQtyp_item_t item) {
    /* Sanity check (Design by Contract) */
    assert((NULL != me) &&
           (NULL != me->p_buf) &&
           (1u < me->bufSiz));

    if (0u == CQqu_cntFree(me)) { /* Full? */
        advTail(me);
    }

    me->p_buf[me->head] = item;
    advHead(me);
}

void CQqu_pushTail(CQqu_qu_t* const me, const CQtyp_item_t item) {
    /* Sanity check (Design by Contract) */
    assert((NULL != me) &&
           (NULL != me->p_buf) &&
           (1u < me->bufSiz));

    if (0u == CQqu_cntFree(me)) { /* Full? */
        retHead(me);
    }

    retTail(me);
    me->p_buf[me->tail] = item;
}

bool CQqu_pull(CQqu_qu_t* const me, CQtyp_item_t* const p_item) {
    /* Sanity check (Design by Contract) */
    assert((NULL != me) &&
           (NULL != me->p_buf) &&
           (1u < me->bufSiz) &&
           (NULL != p_item));

    bool res = false;

    if (me->bufSiz - 1u > CQqu_cntFree(me)) { /* Not empty? */
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
           (NULL != me->p_buf) &&
           (1u < me->bufSiz) &&
           (me->bufSiz - 1u > itemPos));

    const CQTYP_ITEMQUAL_T CQtyp_item_t* p_item = NULL; /* Return pointer */

    /* Requested item position is in range (points to non-vacant item slot)? */
    if (me->bufSiz - 1u - CQqu_cntFree(me) > itemPos) {
        CQtyp_idx_t diff = me->bufSiz - me->tail; /* Peek item position calc. */

        /* Handle wrap around */
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
    assert((NULL != me) &&
           (NULL != me->p_buf) &&
           (1u < me->bufSiz));

    CQtyp_idx_t itemFreeCnt = 0u; /* Var. used for free item count calc. */

    /* Handle free item count calculation depending on head/tail position */
    if (me->tail <= me->head) {
        itemFreeCnt = (CQtyp_idx_t)(me->bufSiz - 1u - (me->head - me->tail));
            /* Explicit type cast needed (safe here) */
    }
    else {
        itemFreeCnt = (CQtyp_idx_t)(me->tail - me->head - 1u);
            /* Explicit type cast needed (safe here) */
    }

    return (itemFreeCnt);
}

/* Cleanup template (multiple "instances") */
#include "CQtemplClUp.h"
#undef advHead
#undef advTail
#undef retHead
#undef retTail
