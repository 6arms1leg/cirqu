/** \file */

#include "main.h"

/* Wrapper module with multiple "instances" of CirQu lib. */
#include "CQwrap.h"

/* Application interface */
#include "CQobj.h"

/* Re-occurring strings */
#define APP_PROMPT "CirQu ex-app:  "
#define CTOR_MSG(ID) ">>> Construct queue `qu" #ID "` ... <<<"
#define CNT_MSG(ID) "Count of free item slots in `qu" #ID "`:  "
#define PULL_MSG(ID) "Pulled (tail) item from `qu" #ID "`:  "

int MAIN(void) {
    /* Temporary storages for peeked/pulled queue items */
    char item0 = '\0';
    float_t item1 = 0.0f;

    (void)puts(APP_PROMPT
               "~~~ Welcome to the CirQu queue example application! ~~~");

    /* Queue 0 */

    (void)puts(APP_PROMPT CTOR_MSG(0));
    CQobj_ctor0(); /* Init. CirQu queue object */

    (void)printf(APP_PROMPT CNT_MSG(0) "%u\n", CQqu_cntFree0(CQobj_p_qu0));

    (void)puts(APP_PROMPT "Push (head) items `a`, `b`, `c` to `qu0` ...");
    CQqu_pushHead0(CQobj_p_qu0, 'a');
    CQqu_pushHead0(CQobj_p_qu0, 'b');
    CQqu_pushHead0(CQobj_p_qu0, 'c');

    (void)printf(APP_PROMPT CNT_MSG(0) "%u\n", CQqu_cntFree0(CQobj_p_qu0));

    item0 = *CQqu_peek0(CQobj_p_qu0, 1u);
    (void)printf(APP_PROMPT "Peeked tail+1 item in `qu0`:  %c\n", item0);

    (void)printf(APP_PROMPT CNT_MSG(0) "%u\n", CQqu_cntFree0(CQobj_p_qu0));

    (void)puts(APP_PROMPT "Push (head) item `d` to `qu0` ...");
    CQqu_pushHead0(CQobj_p_qu0, 'd');

    (void)printf(APP_PROMPT CNT_MSG(0) "%u\n", CQqu_cntFree0(CQobj_p_qu0));

    (void)CQqu_pull0(CQobj_p_qu0, &item0);
    (void)printf(APP_PROMPT PULL_MSG(0) "%c\n", item0);

    (void)printf(APP_PROMPT CNT_MSG(0) "%u\n", CQqu_cntFree0(CQobj_p_qu0));

    (void)puts(APP_PROMPT "Push (tail) item `e` to `qu0` ...");
    CQqu_pushTail0(CQobj_p_qu0, 'e');

    (void)printf(APP_PROMPT CNT_MSG(0) "%u\n", CQqu_cntFree0(CQobj_p_qu0));

    (void)CQqu_pull0(CQobj_p_qu0, &item0);
    (void)printf(APP_PROMPT PULL_MSG(0) "%c\n", item0);
    (void)CQqu_pull0(CQobj_p_qu0, &item0);
    (void)printf(APP_PROMPT PULL_MSG(0) "%c\n", item0);
    (void)CQqu_pull0(CQobj_p_qu0, &item0);
    (void)printf(APP_PROMPT PULL_MSG(0) "%c\n", item0);

    (void)printf(APP_PROMPT CNT_MSG(0) "%u\n", CQqu_cntFree0(CQobj_p_qu0));

    /* Queue 1 */

    (void)puts(APP_PROMPT CTOR_MSG(1));
    CQobj_ctor1(); /* Init. CirQu queue object */

    (void)printf(APP_PROMPT CNT_MSG(1) "%u\n", CQqu_cntFree1(CQobj_p_qu1));

    (void)puts(APP_PROMPT
               "Push (head) items `13.1f`, `0.0f`, `-8.0f` to `qu1` ...");
    CQqu_pushHead1(CQobj_p_qu1, 13.1f);
    CQqu_pushHead1(CQobj_p_qu1, 0.0f);
    CQqu_pushHead1(CQobj_p_qu1, -8.0f);

    (void)printf(APP_PROMPT CNT_MSG(1) "%u\n", CQqu_cntFree1(CQobj_p_qu1));

    (void)CQqu_pull1(CQobj_p_qu1, &item1);
    (void)printf(APP_PROMPT PULL_MSG(1) "%f\n", (double_t)item1);

    (void)printf(APP_PROMPT CNT_MSG(1) "%u\n", CQqu_cntFree1(CQobj_p_qu1));

    (void)puts(APP_PROMPT "~~~ Bye! ~~~");

    return(0);
}
