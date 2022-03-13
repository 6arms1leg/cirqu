/** \file */

#include "main.h"

/* Wrapper module with multiple "instances" of CirQu lib. */
#include "CQwrap.h"

/* Application interface */
#include "CQobj.h"

/* Re-occurring strings */
#define APP_PROMPT "CirQu ex-app:  "
#define CTOR_MSG(ID) "Construct queue `qu" #ID "` ..."
#define CNT_MSG(ID) "Count of free element slots in `qu" #ID "`:  "
#define PULL_MSG(ID) "Pulled (tail) element from `qu" #ID "`:  "

int MAIN(void) {
    /* Temporary storages for peeked/pulled queue elements */
    char elem0 = '\0';
    float_t elem1 = 0.0f;

    puts(APP_PROMPT "~~ Welcome to the CirQu queue example application! ~~");

    /* Queue 0 */

    puts(APP_PROMPT CTOR_MSG(0));
    CQobj_ctor0(); /* Init. CirQu queue object */

    printf(APP_PROMPT CNT_MSG(0) "%i\n", (int)CQqu_cntFree0(CQobj_p_qu0));

    puts(APP_PROMPT "Push (head) elements `a`, `b`, `c` to `qu0` ...");
    CQqu_pushHead0(CQobj_p_qu0, 'a');
    CQqu_pushHead0(CQobj_p_qu0, 'b');
    CQqu_pushHead0(CQobj_p_qu0, 'c');

    printf(APP_PROMPT CNT_MSG(0) "%i\n", (int)CQqu_cntFree0(CQobj_p_qu0));

    elem0 = *CQqu_peek0(CQobj_p_qu0, 1u);
    printf(APP_PROMPT "Peeked tail+1 element in `qu0`:  %c\n", elem0);

    printf(APP_PROMPT CNT_MSG(0) "%i\n", (int)CQqu_cntFree0(CQobj_p_qu0));

    puts(APP_PROMPT "Push (head) element `d` to `qu0` ...");
    CQqu_pushHead0(CQobj_p_qu0, 'd');

    printf(APP_PROMPT CNT_MSG(0) "%i\n", (int)CQqu_cntFree0(CQobj_p_qu0));

    (void)CQqu_pull0(CQobj_p_qu0, &elem0);
    printf(APP_PROMPT PULL_MSG(0) "%c\n", elem0);

    printf(APP_PROMPT CNT_MSG(0) "%i\n", (int)CQqu_cntFree0(CQobj_p_qu0));

    puts(APP_PROMPT "Push (tail) element `e` to `qu0` ...");
    CQqu_pushTail0(CQobj_p_qu0, 'e');

    printf(APP_PROMPT CNT_MSG(0) "%i\n", (int)CQqu_cntFree0(CQobj_p_qu0));

    (void)CQqu_pull0(CQobj_p_qu0, &elem0);
    printf(APP_PROMPT PULL_MSG(0) "%c\n", elem0);
    (void)CQqu_pull0(CQobj_p_qu0, &elem0);
    printf(APP_PROMPT PULL_MSG(0) "%c\n", elem0);
    (void)CQqu_pull0(CQobj_p_qu0, &elem0);
    printf(APP_PROMPT PULL_MSG(0) "%c\n", elem0);

    printf(APP_PROMPT CNT_MSG(0) "%i\n", (int)CQqu_cntFree0(CQobj_p_qu0));

    /* Queue 1 */

    puts(APP_PROMPT CTOR_MSG(1));
    CQobj_ctor1(); /* Init. CirQu queue object */

    printf(APP_PROMPT CNT_MSG(1) "%i\n", (int)CQqu_cntFree1(CQobj_p_qu1));

    puts(APP_PROMPT "Push (head) elements `13.1f`, `0.0f`, `-8.0f` to `qu1` ...");
    CQqu_pushHead1(CQobj_p_qu1, 13.1f);
    CQqu_pushHead1(CQobj_p_qu1, 0.0f);
    CQqu_pushHead1(CQobj_p_qu1, -8.0f);

    printf(APP_PROMPT CNT_MSG(1) "%i\n", (int)CQqu_cntFree1(CQobj_p_qu1));

    (void)CQqu_pull1(CQobj_p_qu1, &elem1);
    printf(APP_PROMPT PULL_MSG(1) "%f\n", elem1);

    printf(APP_PROMPT CNT_MSG(1) "%i\n", (int)CQqu_cntFree1(CQobj_p_qu1));

    puts(APP_PROMPT "~~ Bye! ~~");

    return(0);
}
