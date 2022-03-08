/** \file */

#include "main.h"

/* Wrapper module with multiple "instances" of CirQu library */
#include "CQwrap.h"

/* Include application interfaces */
#include "CQbuf.h"

/* Reoccurring strings */
#define APPPROMPT "CirQu ex-app:  "
#define CTORMSG(ID) "Construct CirQu buffer `buf" #ID "` ..."
#define CNTMSG(ID) "Count of free element slots in `buf" #ID "`:  "
#define PULLMSG(ID) "Pulled (tail) element from `buf" #ID "`:  "

int MAIN(void)
{
    /* Temporary storages for peeked/pulled CirQu elements */
    char c_elem = '\0';
    float_t f_elem = 0.0f;

    puts(APPPROMPT "~~ Welcome to the CirQu buffer example application! ~~");

    /* Buffer 0 */

    puts( APPPROMPT CTORMSG(0) );
    CQbuf_ctor0(); /* Initialize CirQu buffer object */

    printf( APPPROMPT CNTMSG(0) "%i\n", (int)CQqu_cntFree0(p_stc_bffr_g_buf0) );

    puts(APPPROMPT "Push (head) elements `a`, `b`, `c` to `buf0` ...");
    CQqu_pushHead0(p_stc_bffr_g_buf0, 'a');
    CQqu_pushHead0(p_stc_bffr_g_buf0, 'b');
    CQqu_pushHead0(p_stc_bffr_g_buf0, 'c');

    printf( APPPROMPT CNTMSG(0) "%i\n", (int)CQqu_cntFree0(p_stc_bffr_g_buf0) );

    c_elem = *CQqu_peek0(p_stc_bffr_g_buf0, 1u);
    printf(APPPROMPT "Peeked tail+1 element in `buf0`:  %c\n", c_elem);

    printf( APPPROMPT CNTMSG(0) "%i\n", (int)CQqu_cntFree0(p_stc_bffr_g_buf0) );

    puts(APPPROMPT "Push (head) element `d` to `buf0` ...");
    CQqu_pushHead0(p_stc_bffr_g_buf0, 'd');

    printf( APPPROMPT CNTMSG(0) "%i\n", (int)CQqu_cntFree0(p_stc_bffr_g_buf0) );

    (void)CQqu_pull0(p_stc_bffr_g_buf0, &c_elem);
    printf(APPPROMPT PULLMSG(0) "%c\n", c_elem);

    printf( APPPROMPT CNTMSG(0) "%i\n", (int)CQqu_cntFree0(p_stc_bffr_g_buf0) );

    puts(APPPROMPT "Push (tail) element `e` to `buf0` ...");
    CQqu_pushTail0(p_stc_bffr_g_buf0, 'e');

    printf( APPPROMPT CNTMSG(0) "%i\n", (int)CQqu_cntFree0(p_stc_bffr_g_buf0) );

    (void)CQqu_pull0(p_stc_bffr_g_buf0, &c_elem);
    printf(APPPROMPT PULLMSG(0) "%c\n", c_elem);
    (void)CQqu_pull0(p_stc_bffr_g_buf0, &c_elem);
    printf(APPPROMPT PULLMSG(0) "%c\n", c_elem);
    (void)CQqu_pull0(p_stc_bffr_g_buf0, &c_elem);
    printf(APPPROMPT PULLMSG(0) "%c\n", c_elem);

    printf( APPPROMPT CNTMSG(0) "%i\n", (int)CQqu_cntFree0(p_stc_bffr_g_buf0) );

    /* Buffer 1 */

    puts( APPPROMPT CTORMSG(1) );
    CQbuf_ctor1(); /* Initialize CirQu buffer object */

    printf( APPPROMPT CNTMSG(1) "%i\n", (int)CQqu_cntFree1(p_stc_bffr_g_buf1) );

    puts(APPPROMPT "Push (head) elements `13.1f`, `0.0f`, `-8.0f` to `buf1` ...");
    CQqu_pushHead1(p_stc_bffr_g_buf1, 13.1f);
    CQqu_pushHead1(p_stc_bffr_g_buf1, 0.0f);
    CQqu_pushHead1(p_stc_bffr_g_buf1, -8.0f);

    printf( APPPROMPT CNTMSG(1) "%i\n", (int)CQqu_cntFree1(p_stc_bffr_g_buf1) );

    (void)CQqu_pull1(p_stc_bffr_g_buf1, &f_elem);
    printf(APPPROMPT PULLMSG(1) "%f\n", f_elem);

    printf( APPPROMPT CNTMSG(1) "%i\n", (int)CQqu_cntFree1(p_stc_bffr_g_buf1) );

    puts(APPPROMPT "~~ Bye! ~~");

    return(0);
}
