/** \file */

#include "main.h"

#include "CQwrap.h" /* Wrapper module with multiple "instances" of CirQu lib. */
#include "CQobj.h" /* Application interface */

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

    /* Queue 0 Alpha
     */

    (void)puts(APP_PROMPT CTOR_MSG(0Alpha));
    CQobj_qu0AlphaCtor(); /* Init. queue object */

    (void)printf(APP_PROMPT CNT_MSG(0Alpha) "%u\n",
                 CQqu_cntFree0(CQobj_p_qu0Alpha));

    (void)puts(APP_PROMPT "Push (head) items `a`, `b`, `c` to `qu0Alpha` ...");
    CQqu_pushHead0(CQobj_p_qu0Alpha, 'a');
    CQqu_pushHead0(CQobj_p_qu0Alpha, 'b');
    CQqu_pushHead0(CQobj_p_qu0Alpha, 'c');

    (void)printf(APP_PROMPT CNT_MSG(0Alpha) "%u\n",
                 CQqu_cntFree0(CQobj_p_qu0Alpha));

    item0 = *CQqu_peek0(CQobj_p_qu0Alpha, 1u);
    (void)printf(APP_PROMPT "Peeked tail+1 item in `qu0Alpha`:  %c\n", item0);

    (void)printf(APP_PROMPT CNT_MSG(0Alpha) "%u\n",
                 CQqu_cntFree0(CQobj_p_qu0Alpha));

    (void)puts(APP_PROMPT "Push (head) item `d` to `qu0Alpha` ...");
    CQqu_pushHead0(CQobj_p_qu0Alpha, 'd');

    (void)printf(APP_PROMPT CNT_MSG(0Alpha) "%u\n",
                 CQqu_cntFree0(CQobj_p_qu0Alpha));

    (void)CQqu_pull0(CQobj_p_qu0Alpha, &item0);
    (void)printf(APP_PROMPT PULL_MSG(0Alpha) "%c\n", item0);

    (void)printf(APP_PROMPT CNT_MSG(0Alpha) "%u\n",
                 CQqu_cntFree0(CQobj_p_qu0Alpha));

    (void)puts(APP_PROMPT "Push (tail) item `e` to `qu0Alpha` ...");
    CQqu_pushTail0(CQobj_p_qu0Alpha, 'e');

    (void)printf(APP_PROMPT CNT_MSG(0Alpha) "%u\n",
                 CQqu_cntFree0(CQobj_p_qu0Alpha));

    (void)CQqu_pull0(CQobj_p_qu0Alpha, &item0);
    (void)printf(APP_PROMPT PULL_MSG(0Alpha) "%c\n", item0);
    (void)CQqu_pull0(CQobj_p_qu0Alpha, &item0);
    (void)printf(APP_PROMPT PULL_MSG(0Alpha) "%c\n", item0);
    (void)CQqu_pull0(CQobj_p_qu0Alpha, &item0);
    (void)printf(APP_PROMPT PULL_MSG(0Alpha) "%c\n", item0);

    (void)printf(APP_PROMPT CNT_MSG(0Alpha) "%u\n",
                 CQqu_cntFree0(CQobj_p_qu0Alpha));

    /* Queue 0 Beta
     */

    (void)puts(APP_PROMPT CTOR_MSG(0Beta));
    CQobj_qu0BetaCtor(); /* Init. queue object */

    (void)printf(APP_PROMPT CNT_MSG(0Beta) "%u\n",
            CQqu_cntFree0(CQobj_p_qu0Beta));

    /* Queue 1
     */

    (void)puts(APP_PROMPT CTOR_MSG(1));
    CQobj_qu1Ctor(); /* Init. queue object */

    (void)printf(APP_PROMPT CNT_MSG(1) "%u\n", CQqu_cntFree1(CQobj_p_qu1));

    (void)puts(APP_PROMPT
               "Push (head) items `13.1f`, `0.0f`, `-8.0f` to `qu1` ...");
    CQqu_pushHead1(CQobj_p_qu1, 13.1f);
    CQqu_pushHead1(CQobj_p_qu1, 0.0f);
    CQqu_pushHead1(CQobj_p_qu1, -8.0f);

    (void)printf(APP_PROMPT CNT_MSG(1) "%u\n", CQqu_cntFree1(CQobj_p_qu1));

    (void)CQqu_pull1(CQobj_p_qu1, &item1);
    (void)printf(APP_PROMPT PULL_MSG(1) "%f\n", (double_t)item1);
        /* Explicit type cast needed (safe here) */

    (void)printf(APP_PROMPT CNT_MSG(1) "%u\n", CQqu_cntFree1(CQobj_p_qu1));

    (void)puts(APP_PROMPT "~~~ Bye! ~~~");

    return(0);
}
