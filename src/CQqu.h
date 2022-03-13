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

/* Queue buffer item type */
typedef CQTYP_ITEMQUAL_T CQtyp_item_t CQqu_item_t;

/* Queue object type
 *
 * One excessive buffer item slot is used to distinguish full and empty fill
 * level, instead of a dedicated state variable.
 * This makes the queue lock-free (no mutex needed) when there is only one
 * producer and consumer respectively interacting with the queue.
 */
typedef struct {
    CQTYP_ITEMQUAL_T CQtyp_item_t* p_buf;
    CQtyp_idx_t bufSiz;
    CQTYP_ITEMQUAL_T CQtyp_idx_t head;
    CQTYP_ITEMQUAL_T CQtyp_idx_t tail;
} CQqu_qu_t;

/* OPERATIONS
 * ==========
 */

/**
 * \brief Initialize queue
 *
 * *Queue size = buffer size - 1*, since one item slot is used to distinguish
 * full and empty fill level.
 * Re-initialization can be used to empty/clear the queue again.
 *
 * \param me Pointer to queue object
 * \param p_buf Pointer to queue buffer (allocated storage item array)
 * \param bufSiz Size (in count of item slots) of buffer
 */
void CQqu_init(CQqu_qu_t* const me,
               CQqu_item_t* const p_buf,
               const CQtyp_idx_t bufSiz);

/**
 * \brief Insert item into queue (FIFO logic)
 *
 * If full, tail item in queue is overwritten.
 * Conditional insertion (i.e., if queue not full) can easily be implemented by
 * checking if queue is full first (via `CQqu_cntFree()`).
 *
 * \param me Pointer to queue object
 * \param item Item to be inserted into queue
 */
void CQqu_pushHead(CQqu_qu_t* const me, const CQtyp_item_t item);

/**
 * \brief Insert item into queue (LIFO logic)
 *
 * If full, head item in queue is overwritten.
 * Conditional insertion (i.e., if queue not full) can easily be implemented by
 * checking if queue is full first (via `CQqu_cntFree()`).
 *
 * \param me Pointer to queue object
 * \param item Item to be inserted into queue
 */
void CQqu_pushTail(CQqu_qu_t* const me, const CQtyp_item_t item);

/**
 * \brief Retrieve and remove item from queue
 *
 * \param me Pointer to queue object
 * \param p_item Pointer to another item storage location to save retrieved
 * item from queue
 *
 * \return Pull success indicator
 */
bool CQqu_pull(CQqu_qu_t* const me, CQtyp_item_t* const p_item);

/**
 * \brief Retrieve pointer to item (without removal) at given position from
 * queue
 *
 * Position is the index offset from tail (i.e. `0` corresponds to tail and
 * retrieves a pointer to the same item as `CQqu_pull()` would retrieve but
 * without removal, `1` corresponds to the item next to tail, etc.).
 * Returns `NULL` if requested item position is not in range (points to vacant
 * item slot).
 *
 * \param me Pointer to queue object
 * \param itemPos Position of item in queue to retrieve pointer to (index
 * offset from tail)
 *
 * \return Read-only pointer to item in queue
 */
const CQTYP_ITEMQUAL_T CQtyp_item_t* CQqu_peek(const CQqu_qu_t* const me,
                                               const CQtyp_idx_t itemPos);

/**
 * \brief Query fill level (in count of empty item slots) of queue
 *
 * \param me Pointer to queue object
 *
 * \return Count of empty item slots
 */
CQtyp_idx_t CQqu_cntFree(const CQqu_qu_t* const me);

/* Cleanup template (multiple "instances") */
#include "CQtemplClUp.h"
