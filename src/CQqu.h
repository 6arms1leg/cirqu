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
typedef CQTYP_ELEMQUAL_T CQtyp_elem_t CQqu_strgElem_t;

/* One excessive buffer element slot is used to distinguish full and empty fill
 * level, instead of a dedicated state variable.
 * This makes the buffer lock-free (no mutex needed) when there is only one
 * producer and consumer respectively interacting with the buffer.
 */
typedef struct
{
    CQTYP_ELEMQUAL_T CQtyp_elem_t* p_strg;
    CQtyp_idx_t strgSiz;
    CQTYP_ELEMQUAL_T CQtyp_idx_t head;
    CQTYP_ELEMQUAL_T CQtyp_idx_t tail;
} CQqu_qu_t;

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
 * \param p_strg Pointer to allocated storage element array
 * \param strgSiz Size (in count of element slots) of the allocated storage
 * element array
 */
void CQqu_init(CQqu_qu_t* const me,
               CQqu_strgElem_t* const p_strg,
               const CQtyp_idx_t strgSiz);

/**
 * \brief Insert element into buffer (FIFO logic)
 *
 * If full, tail element in buffer is overwritten.
 * Conditional insertion (i.e., if buffer not full) can easily be implemented
 * by checking if buffer is full first (via `fn_bffr_cntFree()`).
 *
 * \param me Pointer to a CirQu buffer object
 * \param elem Element to be inserted into the CirQu buffer
 */
void CQqu_pushHead(CQqu_qu_t* const me, const CQtyp_elem_t elem);

/**
 * \brief Insert element into buffer (LIFO logic)
 *
 * If full, head element in buffer is overwritten.
 * Conditional insertion (i.e., if buffer not full) can easily be implemented
 * by checking if buffer is full first (via `CQqu_cntFree()`).
 *
 * \param me Pointer to a CirQu buffer object
 * \param elem Element to be inserted into the CirQu buffer
 */
void CQqu_pushTail(CQqu_qu_t* const me, const CQtyp_elem_t elem);

/**
 * \brief Retrieve and remove element from buffer
 *
 * \param me Pointer to a CirQu buffer object
 * \param p_elem Pointer to another element storage location to save the
 * retrieved element from the CirQu buffer
 *
 * \return Pull success indicator
 */
bool CQqu_pull(CQqu_qu_t* const me, CQtyp_elem_t* const p_elem);

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
 * \param elemPos Position of the element in the CirQu buffer to retrieve a
 * pointer to (index offset from tail)
 *
 * \return Read-only pointer to element in the CirQu buffer
 */
const CQTYP_ELEMQUAL_T CQtyp_elem_t* CQqu_peek(const CQqu_qu_t* const me,
                                               const CQtyp_idx_t elemPos);

/**
 * \brief Query fill level (in count of empty element slots) of buffer
 *
 * \param me Pointer to a CirQu buffer object
 *
 * \return Count of empty element slots
 */
CQtyp_idx_t CQqu_cntFree(const CQqu_qu_t* const me);

/* Cleanup template (multiple "instances") */
#include "CQtemplClUp.h"
