/** \file */

#include "buffer.h"

/* Modulo operations intentionally not used to handle head/tail wrap around in
 * order to save CPU cycles
 */

/* OPERATIONS
 * ==========
 */

/**
 * \brief Advance head pointer by one element (correctly handles wrap around)
 *
 * \param me Pointer to a CirQu buffer object
 */
static void fn_pv_bffr_advHead(stc_bffr_t* const me)
{
    /* No sanity check necessary since `me` argument was already checked in API
     * functions
     */

    /* If head points to last element */
    if( (cirquElemIdx_t)(me->cirquElemIdx_strgSize - (cirquElemIdx_t)1U) ==
            me->cirquElemIdx_head )
    {
        /* Wrap head around to first element */
        me->cirquElemIdx_head = (cirquElemIdx_t)0U;
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
static void fn_pv_bffr_advTail(stc_bffr_t* const me)
{
    /* No sanity check necessary since `me` argument was already checked in API
     * functions
     */

    /* If tail points to last element */
    if( (cirquElemIdx_t)(me->cirquElemIdx_strgSize - (cirquElemIdx_t)1U) ==
            me->cirquElemIdx_tail )
    {
        /* Wrap tail around to first element */
        me->cirquElemIdx_tail = (cirquElemIdx_t)0U;
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
static void fn_pv_bffr_retHead(stc_bffr_t* const me)
{
    /* No sanity check necessary since `me` argument was already checked in API
     * functions
     */

    /* If head points to first element */
    if( (cirquElemIdx_t)0U == me->cirquElemIdx_head )
    {
        /* Wrap head around to last element */
        me->cirquElemIdx_head = (cirquElemIdx_t)(me->cirquElemIdx_strgSize
                                                 - (cirquElemIdx_t)1U);
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
static void fn_pv_bffr_retTail(stc_bffr_t* const me)
{
    /* No sanity check necessary since `me` argument was already checked in API
     * functions
     */

    /* If tail points to first element */
    if( (cirquElemIdx_t)0U == me->cirquElemIdx_tail )
    {
        /* Wrap tail around to last element */
        me->cirquElemIdx_tail = (cirquElemIdx_t)(me->cirquElemIdx_strgSize
                                                 - (cirquElemIdx_t)1U);
    }
    else
    {
        me->cirquElemIdx_tail--;
    }

    return;
}

void fn_bffr_ini(stc_bffr_t* const me,
                 cirquStrgElem_t* const a_cirquStrgElem_strg,
                 const cirquElemIdx_t cirquElemIdx_strgSize)
{
    /* Sanity check (Design by Contract) */
    assert( (NULL != me) &&
            (NULL != a_cirquStrgElem_strg) &&
            ( (cirquElemIdx_t)1U < cirquElemIdx_strgSize ) );

    me->a_cirquElem_strg = a_cirquStrgElem_strg;
    me->cirquElemIdx_strgSize = cirquElemIdx_strgSize;

    /* Initialize buffer to empty state */
    me->cirquElemIdx_head = (cirquElemIdx_t)0U;
    me->cirquElemIdx_tail = (cirquElemIdx_t)0U;

    return;
}

void fn_bffr_pushHead(stc_bffr_t* const me, const cirquElem_t cirquElem_elem)
{
    /* Sanity check (Design by Contract) */
    assert(NULL != me);

    /* If full */
    if( (cirquElemIdx_t)0U == fn_bffr_cntFree(me) )
    {
        fn_pv_bffr_advTail(me);
    }

    me->a_cirquElem_strg[me->cirquElemIdx_head] = cirquElem_elem;
    fn_pv_bffr_advHead(me);

    return;
}

void fn_bffr_pushTail(stc_bffr_t* const me, const cirquElem_t cirquElem_elem)
{
    /* Sanity check (Design by Contract) */
    assert(NULL != me);

    /* If full */
    if( (cirquElemIdx_t)0U == fn_bffr_cntFree(me) )
    {
        fn_pv_bffr_retHead(me);
    }

    fn_pv_bffr_retTail(me);
    me->a_cirquElem_strg[me->cirquElemIdx_tail] = cirquElem_elem;

    return;
}

bool fn_bffr_pull(stc_bffr_t* const me, cirquElem_t* const p_cirquElem_elem)
{
    /* Sanity check (Design by Contract) */
    assert( (NULL != me) &&
            (NULL != p_cirquElem_elem) );

    bool b_result = false;

    /* If not empty */
    if( (cirquElemIdx_t)(me->cirquElemIdx_strgSize - (cirquElemIdx_t)1U) >
            fn_bffr_cntFree(me) )
    {
        *p_cirquElem_elem = me->a_cirquElem_strg[me->cirquElemIdx_tail];
        fn_pv_bffr_advTail(me);

        b_result = true;
    }

    return(b_result);
}

const cirquElem_t* fn_bffr_peek(const stc_bffr_t* const me,
                                const cirquElemIdx_t cirquElemIdx_elemPos)
{
    /* Sanity check (Design by Contract) */
    assert( (NULL != me) &&
            ( (cirquElemIdx_t)(me->cirquElemIdx_strgSize - (cirquElemIdx_t)1U)
              > cirquElemIdx_elemPos ) );

    /* Initialize variable used in peek element position calculation and return
     * pointer
     */
    cirquElemIdx_t cirquElemIdx_diff = (cirquElemIdx_t)0U;
    const cirquElem_t* p_cirquElem_elem = NULL;

    /* If requested element position is in range (points to non-vacant element
     * slot)
     */
    if( (cirquElemIdx_t)( me->cirquElemIdx_strgSize - (cirquElemIdx_t)1U
                          - fn_bffr_cntFree(me) ) >
            cirquElemIdx_elemPos )
    {
        /* Handle wrap around */
        cirquElemIdx_diff = (cirquElemIdx_t)(me->cirquElemIdx_strgSize
                                             - me->cirquElemIdx_tail);
        if(cirquElemIdx_diff <= cirquElemIdx_elemPos)
        {
            /* Any optional type qualifier must be "cast away" here to return a
             * (read-only) `const` pointer
             */
            p_cirquElem_elem =
                (const cirquElem_t*)&me->a_cirquElem_strg[cirquElemIdx_elemPos
                                                          - cirquElemIdx_diff];
        }
        else
        {
            /* Any optional type qualifier must be "cast away" here to return a
             * (read-only) `const` pointer
             */
            p_cirquElem_elem =
                (const cirquElem_t*)&me->a_cirquElem_strg[me->cirquElemIdx_tail
                                                          + cirquElemIdx_elemPos];
        }
    }

    return(p_cirquElem_elem);
}

cirquElemIdx_t fn_bffr_cntFree(const stc_bffr_t* const me)
{
    /* Sanity check (Design by Contract) */
    assert(NULL != me);

    /* Initialize variable used in free element count calculation */
    cirquElemIdx_t cirquElemIdx_elemFreeCnt = (cirquElemIdx_t)0U;

    if(me->cirquElemIdx_tail <= me->cirquElemIdx_head)
    {
        cirquElemIdx_elemFreeCnt =
            (cirquElemIdx_t)( me->cirquElemIdx_strgSize - (cirquElemIdx_t)1U
                              - (me->cirquElemIdx_head - me->cirquElemIdx_tail)
                              );
    }
    else
    {
        cirquElemIdx_elemFreeCnt =
            (cirquElemIdx_t)(me->cirquElemIdx_tail - me->cirquElemIdx_head
                             - (cirquElemIdx_t)1U);
    }

    return(cirquElemIdx_elemFreeCnt);
}
