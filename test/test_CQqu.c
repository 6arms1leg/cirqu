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

/** \brief Items to push into queue for testing */
enum item {
    ITEM_ONE = 101,
    ITEM_TWO,
    ITEM_THREE,
    ITEM_FOUR,
    ITEM_FIVE
};

/* OPERATIONS
 * ==========
 */

/** \brief Run before every test */
void setUp(void) {
    CQobj_qu0Ctor(); /* Init. queue object */
}

/** \brief Run after every test */
void tearDown(void) {
    /* Re-init. (private) queue object buffer to all `0` */
    for (uint8_t i = 0u; CQOBJ_BUF0_SIZ > i; i++) {
        CQobj_p_qu0->p_buf[i] = 0u;
    }
}

/**
 * \brief Test that assert fires on attempt to init. queue object with `NULL`
 * pointers or buffer size `< 2`.
 */
void test_CQqu_assertNoNullPtrNoBadBufSizOnInit(void) {
    CQqu_item_t0 buf0[CQOBJ_BUF0_SIZ] = {0}; /* Buffer for queue object */

    TEST_ASSERT_FAIL_ASSERT(CQqu_init0(NULL, buf0, CQOBJ_BUF0_SIZ));
    TEST_ASSERT_FAIL_ASSERT(CQqu_init0(CQobj_p_qu0, NULL, CQOBJ_BUF0_SIZ));
    TEST_ASSERT_FAIL_ASSERT(CQqu_init0(CQobj_p_qu0, buf0, 1u));
}

/**
 * \brief Test that assert fires on attempt to push (head) to queue object with
 * `NULL` pointers or buffer size `< 2`.
 */
void test_CQqu_assertNoNullPtrNoBadBufSizOnPushHead(void) {
    TEST_ASSERT_FAIL_ASSERT(CQqu_pushHead0(NULL, ITEM_ONE));

    CQobj_p_qu0->p_buf = NULL; /* Bad value triggers assertion */

    TEST_ASSERT_FAIL_ASSERT(CQqu_pushHead0(CQobj_p_qu0, ITEM_ONE));

    CQobj_qu0Ctor(); /* Re-init. queue object */
    CQobj_p_qu0->bufSiz = 1u; /* Bad value triggers assertion */

    TEST_ASSERT_FAIL_ASSERT(CQqu_pushHead0(CQobj_p_qu0, ITEM_ONE));
}

/**
 * \brief Test that assert fires on attempt to push (tail) to queue object with
 * `NULL` pointers or buffer size `< 2`.
 */
void test_CQqu_assertNoNullPtrNoBadBufSizOnPushTail(void) {
    TEST_ASSERT_FAIL_ASSERT(CQqu_pushTail0(NULL, ITEM_ONE));

    CQobj_p_qu0->p_buf = NULL; /* Bad value triggers assertion */

    TEST_ASSERT_FAIL_ASSERT(CQqu_pushTail0(CQobj_p_qu0, ITEM_ONE));

    CQobj_qu0Ctor(); /* Re-init. queue object */
    CQobj_p_qu0->bufSiz = 1u; /* Bad value triggers assertion */

    TEST_ASSERT_FAIL_ASSERT(CQqu_pushTail0(CQobj_p_qu0, ITEM_ONE));
}

/**
 * \brief Test that assert fires on attempt to pull from queue object with
 * `NULL` pointers or buffer size `< 2`.
 */
void test_CQqu_assertNoNullPtrNoBadBufSizOnPull(void) {
    CQtyp_item_t0 item = 0u; /* Tmp. buffer for pulled queue item */

    TEST_ASSERT_FAIL_ASSERT((void)CQqu_pull0(NULL, &item));
    TEST_ASSERT_FAIL_ASSERT((void)CQqu_pull0(CQobj_p_qu0, NULL));

    CQobj_p_qu0->p_buf = NULL; /* Bad value triggers assertion */

    TEST_ASSERT_FAIL_ASSERT((void)CQqu_pull0(CQobj_p_qu0, &item));

    CQobj_qu0Ctor(); /* Re-init. queue object */
    CQobj_p_qu0->bufSiz = 1u; /* Bad value triggers assertion */

    TEST_ASSERT_FAIL_ASSERT((void)CQqu_pull0(CQobj_p_qu0, &item));
}

/**
 * \brief Test that assert fires on attempt to peek into queue object with
 * `NULL` pointers, buffer size `< 2` or out of range item position.
 */
void test_CQqu_assertNoNullPtrNoBadBufSizNoBadItemPosOnPeek(void) {
    const CQtyp_idx_t0 itemPos = 0u; /* Item position for peek */

    TEST_ASSERT_FAIL_ASSERT((void)CQqu_peek0(NULL, itemPos));
    TEST_ASSERT_FAIL_ASSERT((void)CQqu_peek0(CQobj_p_qu0, CQOBJ_QU0_SIZ));

    CQobj_p_qu0->p_buf = NULL; /* Bad value triggers assertion */

    TEST_ASSERT_FAIL_ASSERT((void)CQqu_peek0(CQobj_p_qu0, itemPos));

    CQobj_qu0Ctor(); /* Re-init. queue object */
    CQobj_p_qu0->bufSiz = 1u; /* Bad value triggers assertion */

    TEST_ASSERT_FAIL_ASSERT((void)CQqu_peek0(CQobj_p_qu0, itemPos));
}

/**
 * \brief Test that assert fires on attempt to count free items in queue object
 * with `NULL` pointers or buffer size `< 2`.
 */
void test_CQqu_assertNoNullPtrNoBadBufSizOnCntFree(void) {
    TEST_ASSERT_FAIL_ASSERT((void)CQqu_cntFree0(NULL));

    CQobj_p_qu0->p_buf = NULL; /* Bad value triggers assertion */

    TEST_ASSERT_FAIL_ASSERT((void)CQqu_cntFree0(CQobj_p_qu0));

    CQobj_qu0Ctor(); /* Re-init. queue object */
    CQobj_p_qu0->bufSiz = 1u; /* Bad value triggers assertion */

    TEST_ASSERT_FAIL_ASSERT((void)CQqu_cntFree0(CQobj_p_qu0));
}

/** \brief Test queue object init. */
void test_CQqu_initQu(void) {
    TEST_ASSERT_NOT_NULL(CQobj_p_qu0->p_buf);
    TEST_ASSERT_EQUAL_UINT8(CQOBJ_BUF0_SIZ, CQobj_p_qu0->bufSiz);
    TEST_ASSERT_EQUAL_UINT8(0u, CQobj_p_qu0->head);
    TEST_ASSERT_EQUAL_UINT8(0u, CQobj_p_qu0->tail);
    TEST_ASSERT_EQUAL_UINT8(0u, CQobj_p_qu0->p_buf[0]); /* Head, Tail */
    TEST_ASSERT_EQUAL_UINT8(0u, CQobj_p_qu0->p_buf[1]);
    TEST_ASSERT_EQUAL_UINT8(0u, CQobj_p_qu0->p_buf[2]);
    TEST_ASSERT_EQUAL_UINT8(0u, CQobj_p_qu0->p_buf[3]);
}

/**
 * \brief Test push (head) to non-full, then full queue object and test that
 * wrap around is handled correctly
 */
void test_CQqu_pushHeadNonFullThenFullQu(void) {
    CQqu_pushHead0(CQobj_p_qu0, ITEM_ONE);
    CQqu_pushHead0(CQobj_p_qu0, ITEM_TWO);
    CQqu_pushHead0(CQobj_p_qu0, ITEM_THREE);

    TEST_ASSERT_EQUAL_UINT8(3u, CQobj_p_qu0->head);
    TEST_ASSERT_EQUAL_UINT8(0u, CQobj_p_qu0->tail);
    TEST_ASSERT_EQUAL_UINT8(ITEM_ONE, CQobj_p_qu0->p_buf[0]); /* Tail */
    TEST_ASSERT_EQUAL_UINT8(ITEM_TWO, CQobj_p_qu0->p_buf[1]);
    TEST_ASSERT_EQUAL_UINT8(ITEM_THREE, CQobj_p_qu0->p_buf[2]);
    TEST_ASSERT_EQUAL_UINT8(0u, CQobj_p_qu0->p_buf[3]); /* Head */

    CQqu_pushHead0(CQobj_p_qu0, ITEM_FOUR);
    CQqu_pushHead0(CQobj_p_qu0, ITEM_FIVE);

    TEST_ASSERT_EQUAL_UINT8(1u, CQobj_p_qu0->head);
    TEST_ASSERT_EQUAL_UINT8(2u, CQobj_p_qu0->tail);
    TEST_ASSERT_EQUAL_UINT8(ITEM_FIVE, CQobj_p_qu0->p_buf[0]);
    TEST_ASSERT_EQUAL_UINT8(ITEM_TWO, CQobj_p_qu0->p_buf[1]); /* Head */
    TEST_ASSERT_EQUAL_UINT8(ITEM_THREE, CQobj_p_qu0->p_buf[2]); /* Tail */
    TEST_ASSERT_EQUAL_UINT8(ITEM_FOUR, CQobj_p_qu0->p_buf[3]);
}

/**
 * \brief Test push (tail) to non-full, then full queue object and test that
 * wrap around is handled correctly
 */
void test_CQqu_pushTailNonFullThenFullQu(void) {
    CQqu_pushTail0(CQobj_p_qu0, ITEM_ONE);

    TEST_ASSERT_EQUAL_UINT8(0u, CQobj_p_qu0->head);
    TEST_ASSERT_EQUAL_UINT8(3u, CQobj_p_qu0->tail);
    TEST_ASSERT_EQUAL_UINT8(0u, CQobj_p_qu0->p_buf[0]); /* Head */
    TEST_ASSERT_EQUAL_UINT8(0u, CQobj_p_qu0->p_buf[1]);
    TEST_ASSERT_EQUAL_UINT8(0u, CQobj_p_qu0->p_buf[2]);
    TEST_ASSERT_EQUAL_UINT8(ITEM_ONE, CQobj_p_qu0->p_buf[3]); /* Tail */

    CQqu_pushTail0(CQobj_p_qu0, ITEM_TWO);
    CQqu_pushTail0(CQobj_p_qu0, ITEM_THREE);
    CQqu_pushTail0(CQobj_p_qu0, ITEM_FOUR);
    CQqu_pushTail0(CQobj_p_qu0, ITEM_FIVE);

    TEST_ASSERT_EQUAL_UINT8(2u, CQobj_p_qu0->head);
    TEST_ASSERT_EQUAL_UINT8(3u, CQobj_p_qu0->tail);
    TEST_ASSERT_EQUAL_UINT8(ITEM_FOUR, CQobj_p_qu0->p_buf[0]);
    TEST_ASSERT_EQUAL_UINT8(ITEM_THREE, CQobj_p_qu0->p_buf[1]);
    TEST_ASSERT_EQUAL_UINT8(ITEM_TWO, CQobj_p_qu0->p_buf[2]); /* Head */
    TEST_ASSERT_EQUAL_UINT8(ITEM_FIVE, CQobj_p_qu0->p_buf[3]); /* Tail */
}

/** \brief Test pull from empty queue object */
void test_CQqu_pullEmptyQu(void) {
    bool res = true;
    CQtyp_item_t0 item = 0u; /* Tmp. buffer for pulled queue item */

    res = CQqu_pull0(CQobj_p_qu0, &item);

    TEST_ASSERT_FALSE(res);
    TEST_ASSERT_EQUAL_UINT8(0u, item);

    TEST_ASSERT_EQUAL_UINT8(0u, CQobj_p_qu0->head);
    TEST_ASSERT_EQUAL_UINT8(0u, CQobj_p_qu0->tail);
    TEST_ASSERT_EQUAL_UINT8(0u, CQobj_p_qu0->p_buf[0]); /* Head, tail */
    TEST_ASSERT_EQUAL_UINT8(0u, CQobj_p_qu0->p_buf[1]);
    TEST_ASSERT_EQUAL_UINT8(0u, CQobj_p_qu0->p_buf[2]);
    TEST_ASSERT_EQUAL_UINT8(0u, CQobj_p_qu0->p_buf[3]);
}

/** \brief Test pull from non-empty queue */
void test_CQqu_pullNonEmptyQu(void) {
    bool res = false;
    CQtyp_item_t0 item = 0u; /* Tmp. buffer for pulled queue item */

    CQqu_pushHead0(CQobj_p_qu0, ITEM_ONE);

    res = CQqu_pull0(CQobj_p_qu0, &item);

    TEST_ASSERT_TRUE(res);
    TEST_ASSERT_EQUAL_UINT8(ITEM_ONE, item);

    TEST_ASSERT_EQUAL_UINT8(1u, CQobj_p_qu0->head);
    TEST_ASSERT_EQUAL_UINT8(1u, CQobj_p_qu0->tail);
    TEST_ASSERT_EQUAL_UINT8(ITEM_ONE, CQobj_p_qu0->p_buf[0]);
    TEST_ASSERT_EQUAL_UINT8(0u, CQobj_p_qu0->p_buf[1]); /* Head, tail */
    TEST_ASSERT_EQUAL_UINT8(0u, CQobj_p_qu0->p_buf[2]);
    TEST_ASSERT_EQUAL_UINT8(0u, CQobj_p_qu0->p_buf[3]);
}

/**
 * \brief Test pull from non-empty queue object and test that wrap around is
 * handled correctly
 */
void test_CQqu_pullNonEmptyQuWithWrapAround(void) {
    bool res = false;
    CQtyp_item_t0 item = 0u; /* Tmp. buffer for pulled queue item */

    CQqu_pushTail0(CQobj_p_qu0, ITEM_ONE);

    res = CQqu_pull0(CQobj_p_qu0, &item);

    TEST_ASSERT_TRUE(res);
    TEST_ASSERT_EQUAL_UINT8(ITEM_ONE, item);

    TEST_ASSERT_EQUAL_UINT8(0u, CQobj_p_qu0->head);
    TEST_ASSERT_EQUAL_UINT8(0u, CQobj_p_qu0->tail);
    TEST_ASSERT_EQUAL_UINT8(0u, CQobj_p_qu0->p_buf[0]); /* Head, tail */
    TEST_ASSERT_EQUAL_UINT8(0u, CQobj_p_qu0->p_buf[1]);
    TEST_ASSERT_EQUAL_UINT8(0u, CQobj_p_qu0->p_buf[2]);
    TEST_ASSERT_EQUAL_UINT8(ITEM_ONE, CQobj_p_qu0->p_buf[3]);
}

/** \brief Test peek into empty queue object */
void test_CQqu_peekEmptyQu(void) {
    TEST_ASSERT_NULL(CQqu_peek0(CQobj_p_qu0, 0u));
}

/** \brief Test peek into queue object with out of range item position */
void test_CQqu_peekQuOutOfRange(void) {
    CQqu_pushHead0(CQobj_p_qu0, ITEM_ONE);

    TEST_ASSERT_NULL(CQqu_peek0(CQobj_p_qu0, CQOBJ_QU0_SIZ - 1u));
}

/** \brief Test peek into queue object */
void test_CQqu_peekQu(void) {
    CQqu_pushHead0(CQobj_p_qu0, ITEM_ONE);
    CQqu_pushHead0(CQobj_p_qu0, ITEM_TWO);

    TEST_ASSERT_EQUAL_UINT8(ITEM_ONE, *CQqu_peek0(CQobj_p_qu0, 0u));
    TEST_ASSERT_EQUAL_UINT8(ITEM_TWO, *CQqu_peek0(CQobj_p_qu0, 1u));
}

/** \brief Test peek into queue object with wrap around */
void test_CQqu_peekQuWithWrapAround(void) {
    CQqu_pushHead0(CQobj_p_qu0, ITEM_ONE);
    CQqu_pushTail0(CQobj_p_qu0, ITEM_TWO);

    TEST_ASSERT_EQUAL_UINT8(ITEM_TWO, *CQqu_peek0(CQobj_p_qu0, 0u));
    TEST_ASSERT_EQUAL_UINT8(ITEM_ONE, *CQqu_peek0(CQobj_p_qu0, 1u));
}

/** \brief Test count of free items in queue object after init. */
void test_CQqu_cntFreeQuItemsAfterInit(void) {
    TEST_ASSERT_EQUAL_UINT8(CQOBJ_QU0_SIZ, CQqu_cntFree0(CQobj_p_qu0));
}

/** \brief Test count of free items in queue object */
void test_CQqu_cntFreeQuItems(void) {
    CQqu_pushHead0(CQobj_p_qu0, ITEM_ONE);
    CQqu_pushHead0(CQobj_p_qu0, ITEM_TWO);
    CQqu_pushHead0(CQobj_p_qu0, ITEM_THREE);

    TEST_ASSERT_EQUAL_UINT8(0u, CQqu_cntFree0(CQobj_p_qu0));
}

/** \brief Test count of free items in queue object with wrap around */
void test_CQqu_cntFreeQuItemsWithWrapAround(void) {
    CQqu_pushTail0(CQobj_p_qu0, ITEM_ONE);

    TEST_ASSERT_EQUAL_UINT8(2u, CQqu_cntFree0(CQobj_p_qu0));
}

#endif /* TEST */
