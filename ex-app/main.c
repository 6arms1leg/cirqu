/** \file */

#include "main.h"

#include "cirquElemType.h" /* Include the CirQu buffer
                              application/project-specific interface */
#include "bufferObject.h" /* Include application interfaces */

/* Reoccurring strings */
#define APPPROMPT "CirQu ex-app:  "
#define CNTMSG "Count of free element slots in `buf0`: "
#define PULLMSG "Pulled (tail) element from `buf0`: "

int MAIN(void)
{
    /* Temporary storage for peeked/pulled CirQu element */
    static cirquElem_t cirquElem_elem = 'z';

    puts(APPPROMPT "~~ Welcome to the CirQu buffer example application! ~~");

    puts(APPPROMPT "Construct CirQu buffer `buf0` ...");
    fn_bffrObj_buf0Ctor(); /* Initialize CirQu buffer object "buffer 0" */

    printf( APPPROMPT CNTMSG "%i\n",
            (int)fn_bffr_cntFree(p_stc_bffr_g_buf0) );

    puts(APPPROMPT "Push elements `a`, `b`, `c` to `buf0` ...");
    fn_bffr_push(p_stc_bffr_g_buf0, (cirquElem_t)'a');
    fn_bffr_push(p_stc_bffr_g_buf0, (cirquElem_t)'b');
    fn_bffr_push(p_stc_bffr_g_buf0, (cirquElem_t)'c');

    printf( APPPROMPT CNTMSG "%i\n",
            (int)fn_bffr_cntFree(p_stc_bffr_g_buf0) );

    (void)fn_bffr_peek(p_stc_bffr_g_buf0, &cirquElem_elem, (cirquElemIdx_t)1U);
    printf(APPPROMPT "Peeked tail+1 element in `buf0`: %c\n",
           (char)cirquElem_elem);

    printf( APPPROMPT CNTMSG "%i\n",
            (int)fn_bffr_cntFree(p_stc_bffr_g_buf0) );

    puts(APPPROMPT "Push element `d` to `buf0` ...");
    fn_bffr_push(p_stc_bffr_g_buf0, (cirquElem_t)'d');

    printf( APPPROMPT CNTMSG "%i\n",
            (int)fn_bffr_cntFree(p_stc_bffr_g_buf0) );

    (void)fn_bffr_pull(p_stc_bffr_g_buf0, &cirquElem_elem);
    printf(APPPROMPT PULLMSG "%c\n",
           (char)cirquElem_elem);
    (void)fn_bffr_pull(p_stc_bffr_g_buf0, &cirquElem_elem);
    printf(APPPROMPT PULLMSG "%c\n",
           (char)cirquElem_elem);
    (void)fn_bffr_pull(p_stc_bffr_g_buf0, &cirquElem_elem);
    printf(APPPROMPT PULLMSG "%c\n",
           (char)cirquElem_elem);

    printf( APPPROMPT CNTMSG "%i\n",
            (int)fn_bffr_cntFree(p_stc_bffr_g_buf0) );

    puts(APPPROMPT "~~ Bye! ~~");

    return( (int)0 );
}
