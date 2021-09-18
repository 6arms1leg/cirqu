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
    if(me->cirquElemIdx_strgSize - (cirquElemIdx_t)1U == me->cirquElemIdx_head)
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
    if(me->cirquElemIdx_strgSize - (cirquElemIdx_t)1U == me->cirquElemIdx_tail)
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

void fn_bffr_ini(stc_bffr_t* const me,
                 cirquElem_t* const a_cirquElem_strg,
                 const cirquElemIdx_t cirquElemIdx_strgSize)
{
    /* Sanity check (Contract by Design) */
    assert( (NULL != me) &&
            (NULL != a_cirquElem_strg) &&
            ( (cirquElemIdx_t)1U < cirquElemIdx_strgSize ) );

    me->a_cirquElem_strg = a_cirquElem_strg;
    me->cirquElemIdx_strgSize = cirquElemIdx_strgSize;

    /* Initialize buffer to empty state */
    me->cirquElemIdx_head = (cirquElemIdx_t)0U;
    me->cirquElemIdx_tail = (cirquElemIdx_t)0U;

    return;
}

void fn_bffr_push(stc_bffr_t* const me, const cirquElem_t cirquElem_elem)
{
    /* Sanity check (Contract by Design) */
    assert(NULL != me);

    /* If full */
    if( (cirquElemIdx_t)0U == fn_bffr_cntFree(me) )
    {
        fn_pv_bffr_advTail(me);
    }
    else {} /* Do nothing */

    me->a_cirquElem_strg[me->cirquElemIdx_head] = cirquElem_elem;
    fn_pv_bffr_advHead(me);

    return;
}

bool fn_bffr_pull(stc_bffr_t* const me, cirquElem_t* const p_cirquElem_elem)
{
    /* Sanity check (Contract by Design) */
    assert( (NULL != me) &&
            (NULL != p_cirquElem_elem) );

    bool b_result = false;

    /* If not empty */
    if( me->cirquElemIdx_strgSize - (cirquElemIdx_t)1U > fn_bffr_cntFree(me) )
    {
        *p_cirquElem_elem = me->a_cirquElem_strg[me->cirquElemIdx_tail];
        fn_pv_bffr_advTail(me);

        b_result = true;
    }
    else {} /* Do nothing */

    return(b_result);
}

bool fn_bffr_peek(const stc_bffr_t* const me,
                  cirquElem_t* const p_cirquElem_elem,
                  const cirquElemIdx_t cirquElemIdx_elemPos)
{
    /* Sanity check (Contract by Design) */
    assert( (NULL != me) &&
            (NULL != p_cirquElem_elem) &&
            (me->cirquElemIdx_strgSize - (cirquElemIdx_t)1U >
                cirquElemIdx_elemPos) );

    bool b_result = false;

    /* Initialize variable used in peek element position calculation */
    cirquElemIdx_t cirquElemIdx_diff = (cirquElemIdx_t)0U;

    /* If requested element position is in range (points to non-vacant element
     * slot)
     */
    if(me->cirquElemIdx_strgSize - (cirquElemIdx_t)1U - fn_bffr_cntFree(me) >
           cirquElemIdx_elemPos)
    {
        /* Handle wrap around */
        cirquElemIdx_diff = me->cirquElemIdx_strgSize - me->cirquElemIdx_tail;
        if(cirquElemIdx_diff <= cirquElemIdx_elemPos)
        {
            *p_cirquElem_elem =
                me->a_cirquElem_strg[cirquElemIdx_elemPos - cirquElemIdx_diff];
        }
        else
        {
            *p_cirquElem_elem =
                me->a_cirquElem_strg[me->cirquElemIdx_tail
                + cirquElemIdx_elemPos];
        }

        b_result = true;
    }
    else {} /* Do nothing */

    return(b_result);
}

cirquElemIdx_t fn_bffr_cntFree(const stc_bffr_t* const me)
{
    /* Sanity check (Contract by Design) */
    assert(NULL != me);

    /* Initialize variable used in free element count calculation */
    cirquElemIdx_t cirquElemIdx_elemFreeCnt = (cirquElemIdx_t)0U;

    if(me->cirquElemIdx_tail <= me->cirquElemIdx_head)
    {
        cirquElemIdx_elemFreeCnt =
            me->cirquElemIdx_strgSize - (cirquElemIdx_t)1U
            - (me->cirquElemIdx_head - me->cirquElemIdx_tail);
    }
    else
    {
        cirquElemIdx_elemFreeCnt =
            me->cirquElemIdx_tail - me->cirquElemIdx_head
            - (cirquElemIdx_t)1U;
    }

    return(cirquElemIdx_elemFreeCnt);
}
