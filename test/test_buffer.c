/** \file */

#ifdef TEST

#include <stdint.h>
#include <stdbool.h>
#include "assert.h" /* For sanity checks (Contract by Design) */

#include "unity.h"

#include "buffer.h"

#include "cirquElemType.h"
#include "bufferObject.h"

/** \brief Run before every test */
void setUp(void)
{
    /* Initialize buffer object "buffer 0" */
    fn_bffrObj_buf0Ctor();

    return;
}

/** \brief Run after every test */
void tearDown(void)
{
    return; /* Do nothing */
}

void test_bffr_initializeBuffer(void)
{
    TEST_ASSERT_EQUAL_UINT8(BUF0STRGSIZE,
                            p_stc_bffr_g_buf0->cirquElemIdx_strgSize);
    TEST_ASSERT_EQUAL_UINT8( (cirquElem_t)0U,
                             p_stc_bffr_g_buf0->cirquElemIdx_head);
    TEST_ASSERT_EQUAL_UINT8( (cirquElem_t)0U,
                             p_stc_bffr_g_buf0->cirquElemIdx_tail);

    return;
}

void test_bffr_bufferEmptyAfterInitialization(void)
{
    const cirquElemIdx_t cirquElemIdx_elemFreeCntExpected = BUF0ELEMSIZE;
    cirquElemIdx_t cirquElemIdx_elemFreeCntActual = (cirquElemIdx_t)0U;

    cirquElemIdx_elemFreeCntActual = fn_bffr_cntFree(p_stc_bffr_g_buf0);

    TEST_ASSERT_EQUAL_UINT8(cirquElemIdx_elemFreeCntExpected,
                            cirquElemIdx_elemFreeCntActual);

    return;
}

void test_bffr_pullFromEmptyBufferReturnsFalse(void)
{
    bool b_result = true;

    cirquElem_t cirquElem_elem = (cirquElem_t)0U;
    cirquElem_t* const p_cirquElem_elem = &cirquElem_elem;

    b_result = fn_bffr_pull(p_stc_bffr_g_buf0, p_cirquElem_elem);

    TEST_ASSERT_FALSE(b_result);

    return;
}

#endif // TEST
