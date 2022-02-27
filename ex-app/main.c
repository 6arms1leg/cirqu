/** \file */

#include "main.h"

/* United buffers module with multiple "instances" of CirQu library */
#include "cirquBufferUnited.h"

/* Include application interfaces */
#include "bufferObject.h"

/* Reoccurring strings */
#define APPPROMPT "CirQu ex-app:  "
#define CTORMSG(ID) "Construct CirQu buffer `buf" #ID "` ..."
#define CNTMSG(ID) "Count of free element slots in `buf" #ID "`:  "
#define PULLMSG(ID) "Pulled (tail) element from `buf" #ID "`:  "

int MAIN(void)
{
    /* Temporary storage for peeked/pulled CirQu element */
    static uint8_t u8_elem = 'z';

    puts(APPPROMPT "~~ Welcome to the CirQu buffer example application! ~~");

    puts( APPPROMPT CTORMSG(0) );
    fn_bffrObj_buf0Ctor(); /* Initialize CirQu buffer object "buffer 0" */

    printf( APPPROMPT CNTMSG(0) "%i\n",
            (int)fn_bffr_cntFree0(p_stc_bffr_g_buf0) );

    puts(APPPROMPT "Push (head) elements `a`, `b`, `c` to `buf0` ...");
    fn_bffr_pushHead0(p_stc_bffr_g_buf0, (uint8_t)'a');
    fn_bffr_pushHead0(p_stc_bffr_g_buf0, (uint8_t)'b');
    fn_bffr_pushHead0(p_stc_bffr_g_buf0, (uint8_t)'c');

    printf( APPPROMPT CNTMSG(0) "%i\n",
            (int)fn_bffr_cntFree0(p_stc_bffr_g_buf0) );

    u8_elem = *fn_bffr_peek0(p_stc_bffr_g_buf0, 1U);
    printf(APPPROMPT "Peeked tail+1 element in `buf0`:  %c\n",
           (char)u8_elem);

    printf( APPPROMPT CNTMSG(0) "%i\n",
            (int)fn_bffr_cntFree0(p_stc_bffr_g_buf0) );

    puts(APPPROMPT "Push (head) element `d` to `buf0` ...");
    fn_bffr_pushHead0(p_stc_bffr_g_buf0, (uint8_t)'d');

    printf( APPPROMPT CNTMSG(0) "%i\n",
            (int)fn_bffr_cntFree0(p_stc_bffr_g_buf0) );

    (void)fn_bffr_pull0(p_stc_bffr_g_buf0, &u8_elem);
    printf(APPPROMPT PULLMSG(0) "%c\n",
           (char)u8_elem);

    printf( APPPROMPT CNTMSG(0) "%i\n",
            (int)fn_bffr_cntFree0(p_stc_bffr_g_buf0) );

    puts(APPPROMPT "Push (tail) element `e` to `buf0` ...");
    fn_bffr_pushTail0(p_stc_bffr_g_buf0, (uint8_t)'e');

    printf( APPPROMPT CNTMSG(0) "%i\n",
            (int)fn_bffr_cntFree0(p_stc_bffr_g_buf0) );

    (void)fn_bffr_pull0(p_stc_bffr_g_buf0, &u8_elem);
    printf(APPPROMPT PULLMSG(0) "%c\n",
           (char)u8_elem);
    (void)fn_bffr_pull0(p_stc_bffr_g_buf0, &u8_elem);
    printf(APPPROMPT PULLMSG(0) "%c\n",
           (char)u8_elem);
    (void)fn_bffr_pull0(p_stc_bffr_g_buf0, &u8_elem);
    printf(APPPROMPT PULLMSG(0) "%c\n",
           (char)u8_elem);

    printf( APPPROMPT CNTMSG(0) "%i\n",
            (int)fn_bffr_cntFree0(p_stc_bffr_g_buf0) );

    puts( APPPROMPT CTORMSG(1) );
    fn_bffrObj_buf1Ctor(); /* Initialize CirQu buffer object "buffer 1" */

    printf( APPPROMPT CNTMSG(1) "%i\n",
            (int)fn_bffr_cntFree1(p_stc_bffr_g_buf1) );

    puts(APPPROMPT "Push (head) elements `0`, `1`, `13` to `buf1` ...");
    fn_bffr_pushHead1(p_stc_bffr_g_buf1, 0U);
    fn_bffr_pushHead1(p_stc_bffr_g_buf1, 1U);
    fn_bffr_pushHead1(p_stc_bffr_g_buf1, 13U);

    printf( APPPROMPT CNTMSG(1) "%i\n",
            (int)fn_bffr_cntFree1(p_stc_bffr_g_buf1) );

    puts(APPPROMPT "~~ Bye! ~~");

    return(0);
}
