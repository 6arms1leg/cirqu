/** \file */

#ifdef TEST

/* Include libc interfaces */
#include <stdint.h>
#include <stdbool.h>
#include "assert.h" /* For sanity checks (Design by Contract) */

#include "unity.h"

/* Include CirQu buffer interface (configured with ID 0).
 * "External" include guards necessary since included module interface has none
 * due to "template" feature.
 */
#ifndef CQQU_H0
#define CQQU_H0
#define CQTEMPLSEUP_ID 0
#include "CQqu.h"
#undef CQTEMPLSEUP_ID
#endif /* CQQU_H0 */

#include "CQbuf.h"

/** \brief Run before every test */
void setUp(void)
{
    /* Initialize buffer object "buffer 0" */
    CQbuf_ctor0();

    return;
}

/** \brief Run after every test */
void tearDown(void)
{
    return; /* Do nothing */
}

void test_CQqu_initializeBuffer(void)
{
    TEST_ASSERT_EQUAL_UINT8(CQBUF_STRGSIZ0, CQbuf_p_buf0->strgSiz);
    TEST_ASSERT_EQUAL_UINT8(0u, CQbuf_p_buf0->head);
    TEST_ASSERT_EQUAL_UINT8(0u, CQbuf_p_buf0->tail);

    return;
}

void test_CQqu_bufferEmptyAfterInitialization(void)
{
    const uint8_t elemFreeCntExp = CQBUF_ELEMSIZ0;
    uint8_t elemFreeCntAct = 0u;

    elemFreeCntAct = CQqu_cntFree0(CQbuf_p_buf0);

    TEST_ASSERT_EQUAL_UINT8(elemFreeCntExp, elemFreeCntAct);

    return;
}

void test_CQqu_pullFromEmptyBufferReturnsFalse(void)
{
    bool res = true;

    uint8_t elem = 0u;
    uint8_t* const p_elem = &elem;

    res = CQqu_pull0(CQbuf_p_buf0, p_elem);

    TEST_ASSERT_FALSE(res);

    return;
}

#endif /* TEST */
