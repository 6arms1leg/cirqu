/** \file */

#include "main.h"

/* Wrapper module with multiple "instances" of CirQu library */
#include "CQwrap.h"

/* Include application interfaces */
#include "CQbuf.h"

/* Reoccurring strings */
#define APP_PROMPT "CirQu ex-app:  "
#define CTOR_MSG(ID) "Construct CirQu buffer `buf" #ID "` ..."
#define CNT_MSG(ID) "Count of free element slots in `buf" #ID "`:  "
#define PULL_MSG(ID) "Pulled (tail) element from `buf" #ID "`:  "

int MAIN(void)
{
    /* Temporary storages for peeked/pulled CirQu elements */
    char elem0 = '\0';
    float_t elem1 = 0.0f;

    puts(APP_PROMPT "~~ Welcome to the CirQu buffer example application! ~~");

    /* Buffer 0 */

    puts( APP_PROMPT CTOR_MSG(0) );
    CQbuf_ctor0(); /* Initialize CirQu buffer object */

    printf( APP_PROMPT CNT_MSG(0) "%i\n", (int)CQqu_cntFree0(CQbuf_p_buf0) );

    puts(APP_PROMPT "Push (head) elements `a`, `b`, `c` to `buf0` ...");
    CQqu_pushHead0(CQbuf_p_buf0, 'a');
    CQqu_pushHead0(CQbuf_p_buf0, 'b');
    CQqu_pushHead0(CQbuf_p_buf0, 'c');

    printf( APP_PROMPT CNT_MSG(0) "%i\n", (int)CQqu_cntFree0(CQbuf_p_buf0) );

    elem0 = *CQqu_peek0(CQbuf_p_buf0, 1u);
    printf(APP_PROMPT "Peeked tail+1 element in `buf0`:  %c\n", elem0);

    printf( APP_PROMPT CNT_MSG(0) "%i\n", (int)CQqu_cntFree0(CQbuf_p_buf0) );

    puts(APP_PROMPT "Push (head) element `d` to `buf0` ...");
    CQqu_pushHead0(CQbuf_p_buf0, 'd');

    printf( APP_PROMPT CNT_MSG(0) "%i\n", (int)CQqu_cntFree0(CQbuf_p_buf0) );

    (void)CQqu_pull0(CQbuf_p_buf0, &elem0);
    printf(APP_PROMPT PULL_MSG(0) "%c\n", elem0);

    printf( APP_PROMPT CNT_MSG(0) "%i\n", (int)CQqu_cntFree0(CQbuf_p_buf0) );

    puts(APP_PROMPT "Push (tail) element `e` to `buf0` ...");
    CQqu_pushTail0(CQbuf_p_buf0, 'e');

    printf( APP_PROMPT CNT_MSG(0) "%i\n", (int)CQqu_cntFree0(CQbuf_p_buf0) );

    (void)CQqu_pull0(CQbuf_p_buf0, &elem0);
    printf(APP_PROMPT PULL_MSG(0) "%c\n", elem0);
    (void)CQqu_pull0(CQbuf_p_buf0, &elem0);
    printf(APP_PROMPT PULL_MSG(0) "%c\n", elem0);
    (void)CQqu_pull0(CQbuf_p_buf0, &elem0);
    printf(APP_PROMPT PULL_MSG(0) "%c\n", elem0);

    printf( APP_PROMPT CNT_MSG(0) "%i\n", (int)CQqu_cntFree0(CQbuf_p_buf0) );

    /* Buffer 1 */

    puts( APP_PROMPT CTOR_MSG(1) );
    CQbuf_ctor1(); /* Initialize CirQu buffer object */

    printf( APP_PROMPT CNT_MSG(1) "%i\n", (int)CQqu_cntFree1(CQbuf_p_buf1) );

    puts(APP_PROMPT "Push (head) elements `13.1f`, `0.0f`, `-8.0f` to `buf1` ...");
    CQqu_pushHead1(CQbuf_p_buf1, 13.1f);
    CQqu_pushHead1(CQbuf_p_buf1, 0.0f);
    CQqu_pushHead1(CQbuf_p_buf1, -8.0f);

    printf( APP_PROMPT CNT_MSG(1) "%i\n", (int)CQqu_cntFree1(CQbuf_p_buf1) );

    (void)CQqu_pull1(CQbuf_p_buf1, &elem1);
    printf(APP_PROMPT PULL_MSG(1) "%f\n", elem1);

    printf( APP_PROMPT CNT_MSG(1) "%i\n", (int)CQqu_cntFree1(CQbuf_p_buf1) );

    puts(APP_PROMPT "~~ Bye! ~~");

    return(0);
}
