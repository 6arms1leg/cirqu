/** \file */

/* No include guards here to allow multiple inclusions due to "template"
 * feature
 */

/* `"` used intentionally.  This allows the user to override and provide his
 * own implementation before falling back to libc.
 */
#include "stdint.h"
#include "stddef.h"
#include "stdbool.h"
#include "assert.h" /* For sanity checks (Design by Contract) */

/* Must be provided; application/project-specific */
#include "CQtyp.h"

/* Setup template to allow multiple "instances" of this library */
#include "CQtemplSeUp.h"

/* ATTRIBUTES
 * ==========
 */

/* Buffer storage element */
typedef CIRQUELEMQUAL_T cirquElem_t cirquStrgElem_t;

/* One excessive buffer element slot is used to distinguish full and empty fill
 * level, instead of a dedicated state variable.
 * This makes the buffer lock-free (no mutex needed) when there is only one
 * producer and consumer respectively interacting with the buffer.
 */
typedef struct
{
    CIRQUELEMQUAL_T cirquElem_t* a_cirquElem_strg;
    cirquElemIdx_t cirquElemIdx_strgSize;
    CIRQUELEMQUAL_T cirquElemIdx_t cirquElemIdx_head;
    CIRQUELEMQUAL_T cirquElemIdx_t cirquElemIdx_tail;
} stc_bffr_t;

/* OPERATIONS
 * ==========
 */

/**
 * \brief Initialize buffer
 *
 * *Buffer element capacity = storage size - 1*, since one element slot is used
 * to distinguish full and empty fill level.
 *
 * \param me Pointer to a CirQu buffer object
 * \param a_cirquStrgElem_strg Pointer to allocated storage element array
 * \param cirquElemIdx_strgSize Size (in count of element slots) of the
 * allocated storage element array
 */
void fn_bffr_ini(stc_bffr_t* const me,
                 cirquStrgElem_t* const a_cirquStrgElem_strg,
                 const cirquElemIdx_t cirquElemIdx_strgSize);

/**
 * \brief Insert element into buffer (FIFO logic)
 *
 * If full, tail element in buffer is overwritten.
 * Conditional insertion (i.e., if buffer not full) can easily be implemented
 * by checking if buffer is full first (via `fn_bffr_cntFree()`).
 *
 * \param me Pointer to a CirQu buffer object
 * \param cirquElem_elem Element to be inserted into the CirQu buffer
 */
void fn_bffr_pushHead(stc_bffr_t* const me, const cirquElem_t cirquElem_elem);

/**
 * \brief Insert element into buffer (LIFO logic)
 *
 * If full, head element in buffer is overwritten.
 * Conditional insertion (i.e., if buffer not full) can easily be implemented
 * by checking if buffer is full first (via `fn_bffr_cntFree()`).
 *
 * \param me Pointer to a CirQu buffer object
 * \param cirquElem_elem Element to be inserted into the CirQu buffer
 */
void fn_bffr_pushTail(stc_bffr_t* const me, const cirquElem_t cirquElem_elem);

/**
 * \brief Retrieve and remove element from buffer
 *
 * \param me Pointer to a CirQu buffer object
 * \param p_cirquElem_elem Pointer to another element storage location to save
 * the retrieved element from the CirQu buffer
 *
 * \return Pull success indicator
 */
bool fn_bffr_pull(stc_bffr_t* const me, cirquElem_t* const p_cirquElem_elem);

/**
 * \brief Retrieve pointer to element (without removal) at given position from
 * buffer
 *
 * Position is the index offset from tail (i.e. `0` corresponds to tail and
 * retrieves a pointer to the same element as `fn_bffr_pull()` would retrieve
 * but without removal, `1` corresponds to the element next to tail, etc.).
 * Returns `NULL` if requested element position is not in range (points to
 * vacant element slot).
 *
 * \param me Pointer to a CirQu buffer object
 * \param cirquElemIdx_elemPos Position of the element in the CirQu buffer to
 * retrieve a pointer to (index offset from tail)
 *
 * \return Read-only pointer to element in the CirQu buffer
 */
const CIRQUELEMQUAL_T cirquElem_t* fn_bffr_peek(const stc_bffr_t* const me,
                                                const cirquElemIdx_t
                                                    cirquElemIdx_elemPos);

/**
 * \brief Query fill level (in count of empty element slots) of buffer
 *
 * \param me Pointer to a CirQu buffer object
 *
 * \return Count of empty element slots
 */
cirquElemIdx_t fn_bffr_cntFree(const stc_bffr_t* const me);

/* Cleanup template (multiple "instances") */
#include "CQtemplClUp.h"
