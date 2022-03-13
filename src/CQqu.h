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

/* Setup template to allow multiple "instances" of library */
#include "CQtemplSeUp.h"

/* ATTRIBUTES
 * ==========
 */

/* Queue buffer element type */
typedef CQTYP_ELEMQUAL_T CQtyp_elem_t CQqu_elem_t;

/* Queue object type
 *
 * One excessive buffer element slot is used to distinguish full and empty fill
 * level, instead of a dedicated state variable.
 * This makes the queue lock-free (no mutex needed) when there is only one
 * producer and consumer respectively interacting with the queue.
 */
typedef struct {
    CQTYP_ELEMQUAL_T CQtyp_elem_t* p_buf;
    CQtyp_idx_t bufSiz;
    CQTYP_ELEMQUAL_T CQtyp_idx_t head;
    CQTYP_ELEMQUAL_T CQtyp_idx_t tail;
} CQqu_qu_t;

/* OPERATIONS
 * ==========
 */

/**
 * \brief Initialize queue
 *
 * *Queue size = buffer size - 1*, since one element slot is used to
 * distinguish full and empty fill level.
 * Re-initialization can be used to empty/clear the queue again.
 *
 * \param me Pointer to queue object
 * \param p_buf Pointer to queue buffer (allocated storage element array)
 * \param bufSiz Size (in count of element slots) of buffer
 */
void CQqu_init(CQqu_qu_t* const me,
               CQqu_elem_t* const p_buf,
               const CQtyp_idx_t bufSiz);

/**
 * \brief Insert element into queue (FIFO logic)
 *
 * If full, tail element in queue is overwritten.
 * Conditional insertion (i.e., if queue not full) can easily be implemented by
 * checking if queue is full first (via `CQqu_cntFree()`).
 *
 * \param me Pointer to queue object
 * \param elem Element to be inserted into queue
 */
void CQqu_pushHead(CQqu_qu_t* const me, const CQtyp_elem_t elem);

/**
 * \brief Insert element into queue (LIFO logic)
 *
 * If full, head element in queue is overwritten.
 * Conditional insertion (i.e., if queue not full) can easily be implemented by
 * checking if queue is full first (via `CQqu_cntFree()`).
 *
 * \param me Pointer to queue object
 * \param elem Element to be inserted into queue
 */
void CQqu_pushTail(CQqu_qu_t* const me, const CQtyp_elem_t elem);

/**
 * \brief Retrieve and remove element from queue
 *
 * \param me Pointer to queue object
 * \param p_elem Pointer to another element storage location to save retrieved
 * element from queue
 *
 * \return Pull success indicator
 */
bool CQqu_pull(CQqu_qu_t* const me, CQtyp_elem_t* const p_elem);

/**
 * \brief Retrieve pointer to element (without removal) at given position from
 * queue
 *
 * Position is the index offset from tail (i.e. `0` corresponds to tail and
 * retrieves a pointer to the same element as `CQqu_pull()` would retrieve but
 * without removal, `1` corresponds to the element next to tail, etc.).
 * Returns `NULL` if requested element position is not in range (points to
 * vacant element slot).
 *
 * \param me Pointer to queue object
 * \param elemPos Position of element in queue to retrieve pointer to (index
 * offset from tail)
 *
 * \return Read-only pointer to element in queue
 */
const CQTYP_ELEMQUAL_T CQtyp_elem_t* CQqu_peek(const CQqu_qu_t* const me,
                                               const CQtyp_idx_t elemPos);

/**
 * \brief Query fill level (in count of empty element slots) of queue
 *
 * \param me Pointer to queue object
 *
 * \return Count of empty element slots
 */
CQtyp_idx_t CQqu_cntFree(const CQqu_qu_t* const me);

/* Cleanup template (multiple "instances") */
#include "CQtemplClUp.h"
