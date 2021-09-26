/** \file */

#include "main.h"

#include "cirquElemType.h" /* Include the CirQu buffer
                              application/project-specific interface */
#include "bufferObject.h" /* Include application interfaces */

int MAIN(void)
{
    /* Temporary storage for peeked/pulled CirQu element */
    static cirquElem_t cirquElem_elem = 'z';

    puts("CirQu: ~~ Welcome to the CirQu buffer example application! ~~");

    puts("CirQu: Construct CirQu buffer `buf0` ...");
    fn_bffrObj_buf0Ctor(); /* Initialize CirQu buffer object "buffer 0" */

    printf( "CirQu: Count of free element slots in `buf0`: %i\n",
            (int)fn_bffr_cntFree(p_stc_bffr_g_buf0) );

    puts("CirQu: Push elements `a`, `b`, `c` to `buf0` ...");
    fn_bffr_push(p_stc_bffr_g_buf0, (cirquElem_t)'a');
    fn_bffr_push(p_stc_bffr_g_buf0, (cirquElem_t)'b');
    fn_bffr_push(p_stc_bffr_g_buf0, (cirquElem_t)'c');

    printf( "CirQu: Count of free element slots in `buf0`: %i\n",
            (int)fn_bffr_cntFree(p_stc_bffr_g_buf0) );

    (void)fn_bffr_peek(p_stc_bffr_g_buf0, &cirquElem_elem, (cirquElemIdx_t)1U);
    printf("CirQu: Peeked tail+1 element in `buf0`: %c\n",
           (char)cirquElem_elem);

    printf( "CirQu: Count of free element slots in `buf0`: %i\n",
            (int)fn_bffr_cntFree(p_stc_bffr_g_buf0) );

    puts("CirQu: Push element `d` to `buf0` ...");
    fn_bffr_push(p_stc_bffr_g_buf0, (cirquElem_t)'d');

    printf( "CirQu: Count of free element slots in `buf0`: %i\n",
            (int)fn_bffr_cntFree(p_stc_bffr_g_buf0) );

    (void)fn_bffr_pull(p_stc_bffr_g_buf0, &cirquElem_elem);
    printf("CirQu: Pulled (tail) element from `buf0`: %c\n",
           (char)cirquElem_elem);
    (void)fn_bffr_pull(p_stc_bffr_g_buf0, &cirquElem_elem);
    printf("CirQu: Pulled (tail) element from `buf0`: %c\n",
           (char)cirquElem_elem);
    (void)fn_bffr_pull(p_stc_bffr_g_buf0, &cirquElem_elem);
    printf("CirQu: Pulled (tail) element from `buf0`: %c\n",
           (char)cirquElem_elem);

    printf( "CirQu: Count of free element slots in `buf0`: %i\n",
            (int)fn_bffr_cntFree(p_stc_bffr_g_buf0) );

    puts("CirQu: ~~ Bye! ~~");

    return( (int)0 );
}
