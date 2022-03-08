/** \file */

#include "CQqu.h"

/* Setup template to allow multiple "instances" of this library */
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
 * \param me Pointer to a CirQu buffer object
 */
static inline void advHead(stc_bffr_t* const me)
{
    /* No sanity check necessary since `me` argument was already checked in API
     * functions
     */

    /* If head points to last element */
    if(me->cirquElemIdx_strgSize - 1u == me->cirquElemIdx_head)
    {
        /* Wrap head around to first element */
        me->cirquElemIdx_head = 0u;
    }
    else
    {
        me->cirquElemIdx_head++;
    }

    return;
}

/**
 * \brief Advance tail pointer by one element (correctly handles wrap around)
 *
 * \param me Pointer to a CirQu buffer object
 */
static void advTail(stc_bffr_t* const me)
{
    /* No sanity check necessary since `me` argument was already checked in API
     * functions
     */

    /* If tail points to last element */
    if(me->cirquElemIdx_strgSize - 1u == me->cirquElemIdx_tail)
    {
        /* Wrap tail around to first element */
        me->cirquElemIdx_tail = 0u;
    }
    else
    {
        me->cirquElemIdx_tail++;
    }

    return;
}

/**
 * \brief Retreat head pointer by one element (correctly handles wrap around)
 *
 * \param me Pointer to a CirQu buffer object
 */
static inline void retHead(stc_bffr_t* const me)
{
    /* No sanity check necessary since `me` argument was already checked in API
     * functions
     */

    /* If head points to first element */
    if(0u == me->cirquElemIdx_head)
    {
        /* Wrap head around to last element */
        me->cirquElemIdx_head = me->cirquElemIdx_strgSize - (cirquElemIdx_t)1u;
    }
    else
    {
        me->cirquElemIdx_head--;
    }

    return;
}

/**
 * \brief Retreat tail pointer by one element (correctly handles wrap around)
 *
 * \param me Pointer to a CirQu buffer object
 */
static inline void retTail(stc_bffr_t* const me)
{
    /* No sanity check necessary since `me` argument was already checked in API
     * functions
     */

    /* If tail points to first element */
    if(0u == me->cirquElemIdx_tail)
    {
        /* Wrap tail around to last element */
        me->cirquElemIdx_tail = me->cirquElemIdx_strgSize - (cirquElemIdx_t)1u;
    }
    else
    {
        me->cirquElemIdx_tail--;
    }

    return;
}

void CQqu_init(stc_bffr_t* const me,
               cirquStrgElem_t* const a_cirquStrgElem_strg,
               const cirquElemIdx_t cirquElemIdx_strgSize)
{
    /* Sanity check (Design by Contract) */
    assert( (NULL != me) &&
            (NULL != a_cirquStrgElem_strg) &&
            (1u < cirquElemIdx_strgSize) );

    me->a_cirquElem_strg = a_cirquStrgElem_strg;
    me->cirquElemIdx_strgSize = cirquElemIdx_strgSize;

    /* Initialize buffer to empty state */
    me->cirquElemIdx_head = 0u;
    me->cirquElemIdx_tail = 0u;

    return;
}

void CQqu_pushHead(stc_bffr_t* const me, const cirquElem_t cirquElem_elem)
{
    /* Sanity check (Design by Contract) */
    assert(NULL != me);

    /* If full */
    if( 0u == CQqu_cntFree(me) )
    {
        advTail(me);
    }

    me->a_cirquElem_strg[me->cirquElemIdx_head] = cirquElem_elem;
    advHead(me);

    return;
}

void CQqu_pushTail(stc_bffr_t* const me, const cirquElem_t cirquElem_elem)
{
    /* Sanity check (Design by Contract) */
    assert(NULL != me);

    /* If full */
    if( 0u == CQqu_cntFree(me) )
    {
        retHead(me);
    }

    retTail(me);
    me->a_cirquElem_strg[me->cirquElemIdx_tail] = cirquElem_elem;

    return;
}

bool CQqu_pull(stc_bffr_t* const me, cirquElem_t* const p_cirquElem_elem)
{
    /* Sanity check (Design by Contract) */
    assert( (NULL != me) &&
            (NULL != p_cirquElem_elem) );

    bool b_result = false;

    /* If not empty */
    if( me->cirquElemIdx_strgSize - 1u > CQqu_cntFree(me) )
    {
        *p_cirquElem_elem = me->a_cirquElem_strg[me->cirquElemIdx_tail];
        advTail(me);

        b_result = true;
    }

    return(b_result);
}

const CQTYP_ELEMQUAL_T cirquElem_t* CQqu_peek(const stc_bffr_t* const me,
                                              const cirquElemIdx_t
                                                  cirquElemIdx_elemPos)
{
    /* Sanity check (Design by Contract) */
    assert( (NULL != me) &&
            (me->cirquElemIdx_strgSize - 1u > cirquElemIdx_elemPos) );

    /* Initialize variable used in peek element position calculation and return
     * pointer
     */
    cirquElemIdx_t cirquElemIdx_diff = 0u;
    const CQTYP_ELEMQUAL_T cirquElem_t* p_cirquElem_elem = NULL;

    /* If requested element position is in range (points to non-vacant element
     * slot)
     */
    if(me->cirquElemIdx_strgSize - 1u - CQqu_cntFree(me) > cirquElemIdx_elemPos)
    {
        /* Handle wrap around */
        cirquElemIdx_diff = me->cirquElemIdx_strgSize - me->cirquElemIdx_tail;
        if(cirquElemIdx_diff <= cirquElemIdx_elemPos)
        {
            p_cirquElem_elem = &me->a_cirquElem_strg[cirquElemIdx_elemPos
                                                     - cirquElemIdx_diff];
        }
        else
        {
            p_cirquElem_elem = &me->a_cirquElem_strg[me->cirquElemIdx_tail
                                                     + cirquElemIdx_elemPos];
        }
    }

    return(p_cirquElem_elem);
}

cirquElemIdx_t CQqu_cntFree(const stc_bffr_t* const me)
{
    /* Sanity check (Design by Contract) */
    assert(NULL != me);

    /* Initialize variable used in free element count calculation */
    cirquElemIdx_t cirquElemIdx_elemFreeCnt = 0u;

    if(me->cirquElemIdx_tail <= me->cirquElemIdx_head)
    {
        cirquElemIdx_elemFreeCnt =
            (cirquElemIdx_t)( me->cirquElemIdx_strgSize - 1u
                              - (me->cirquElemIdx_head - me->cirquElemIdx_tail) );
    }
    else
    {
        cirquElemIdx_elemFreeCnt =
            (cirquElemIdx_t)(me->cirquElemIdx_tail - me->cirquElemIdx_head - 1u);
    }

    return(cirquElemIdx_elemFreeCnt);
}

/* Cleanup template (multiple "instances") */
#include "CQtemplClUp.h"
#undef advHead
#undef advTail
#undef retHead
#undef retTail
