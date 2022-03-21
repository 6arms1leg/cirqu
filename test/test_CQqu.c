/** \file */

#ifdef TEST

#include <stdint.h>
#include <stdbool.h>
#include "assert.h" /* Sanity checks (Design by Contract); replaced for unit
                       testing */

#include "unity.h"

/* CirQu lib. interface configured with ID.
   "External" include guards necessary since included module interface has none
   due to "template" feature. */
#ifndef CQQU_H0
#define CQQU_H0
#define CQTEMPLSEUP_ID 0
#include "CQqu.h"
#undef CQTEMPLSEUP_ID
#endif /* CQQU_H0 */

#include "CQobj.h"

/* OPERATIONS
 * ==========
 */

/** \brief Run before every test */
void setUp(void) {
    CQobj_qu0Ctor(); /* Init. queue object */
}

/** \brief Run after every test */
void tearDown(void) {
    /* Do nothing */
}

/** \brief Test queue object init. */
void test_CQqu_initQu(void) {
    TEST_ASSERT_EQUAL_UINT8(CQOBJ_BUF0_SIZ, CQobj_p_qu0->bufSiz);
    TEST_ASSERT_EQUAL_UINT8(0u, CQobj_p_qu0->head);
    TEST_ASSERT_EQUAL_UINT8(0u, CQobj_p_qu0->tail);
}

/** \brief Test queue object is empty after init. */
void test_CQqu_quEmptyAfterInit(void) {
    const uint8_t itemFreeCntExp = CQOBJ_QU0_SIZ;
    uint8_t itemFreeCntAct = 0u;

    itemFreeCntAct = CQqu_cntFree0(CQobj_p_qu0);

    TEST_ASSERT_EQUAL_UINT8(itemFreeCntExp, itemFreeCntAct);
}

/** \brief Test pull from empty queue object */
void test_CQqu_pullFromEmptyQuReturnsFalse(void) {
    bool res = true;

    /* Temporary storage for pulled queue item */
    uint8_t item = 0u;
    uint8_t* const p_item = &item;

    res = CQqu_pull0(CQobj_p_qu0, p_item);

    TEST_ASSERT_FALSE(res);
}

#endif /* TEST */
