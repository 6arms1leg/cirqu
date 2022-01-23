/** \file */

#ifdef TEST

#include <stdint.h>
#include <stdbool.h>
#include "assert.h" /* For sanity checks (Design by Contract) */

#include "unity.h"

#include "buffer.h"

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
    TEST_ASSERT_EQUAL_UINT8( (uint8_t)0U,
                             p_stc_bffr_g_buf0->cirquElemIdx_head );
    TEST_ASSERT_EQUAL_UINT8( (uint8_t)0U,
                             p_stc_bffr_g_buf0->cirquElemIdx_tail );

    return;
}

void test_bffr_bufferEmptyAfterInitialization(void)
{
    const uint8_t u8_elemFreeCntExpected = BUF0ELEMSIZE;
    uint8_t u8_elemFreeCntActual = (uint8_t)0U;

    u8_elemFreeCntActual = fn_bffr_cntFree(p_stc_bffr_g_buf0);

    TEST_ASSERT_EQUAL_UINT8(u8_elemFreeCntExpected, u8_elemFreeCntActual);

    return;
}

void test_bffr_pullFromEmptyBufferReturnsFalse(void)
{
    bool b_result = true;

    uint8_t u8_elem = (uint8_t)0U;
    uint8_t* const p_u8_elem = &u8_elem;

    b_result = fn_bffr_pull(p_stc_bffr_g_buf0, p_u8_elem);

    TEST_ASSERT_FALSE(b_result);

    return;
}

#endif // TEST
