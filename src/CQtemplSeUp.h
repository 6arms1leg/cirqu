/** \file */

/* No include guards here to allow multiple inclusions due to "template"
 * feature
 */

/* Sanity check */
#ifndef CQTEMPLSEUP_ID
#error CQTEMPLSEUP_ID must be defined
#endif /* CQTEMPLSEUP_ID */

/* Function-like macros to concatenate two names
 *
 * One layer of indirection required to always correctly concatenate and expand
 * macros.
 */
#define CQTEMPLSEUP_CAT_I(a, b) a##b
#define CQTEMPLSEUP_CAT(a, b) CQTEMPLSEUP_CAT_I(a, b) /* Layer of indirection */

/* Rename (concatenate) types (user-provided) */
#define CQTYP_ELEMQUAL_T CQTEMPLSEUP_CAT(CQTYP_ELEMQUAL_T, CQTEMPLSEUP_ID)
#define CQtyp_elem_t CQTEMPLSEUP_CAT(CQtyp_elem_t, CQTEMPLSEUP_ID)
#define CQtyp_idx_t CQTEMPLSEUP_CAT(CQtyp_idx_t, CQTEMPLSEUP_ID)

/* Rename (concatenate) types */
#define CQqu_strgElem_t CQTEMPLSEUP_CAT(CQqu_strgElem_t, CQTEMPLSEUP_ID)
#define CQqu_qu_t CQTEMPLSEUP_CAT(CQqu_qu_t, CQTEMPLSEUP_ID)

/* Rename (concatenate) functions */
#define CQqu_init(a, b, c) CQTEMPLSEUP_CAT(CQqu_init, CQTEMPLSEUP_ID)(a, b, c)
#define CQqu_pushHead(a, b) CQTEMPLSEUP_CAT(CQqu_pushHead, CQTEMPLSEUP_ID)(a, b)
#define CQqu_pushTail(a, b) CQTEMPLSEUP_CAT(CQqu_pushTail, CQTEMPLSEUP_ID)(a, b)
#define CQqu_pull(a, b) CQTEMPLSEUP_CAT(CQqu_pull, CQTEMPLSEUP_ID)(a, b)
#define CQqu_peek(a, b) CQTEMPLSEUP_CAT(CQqu_peek, CQTEMPLSEUP_ID)(a, b)
#define CQqu_cntFree(a) CQTEMPLSEUP_CAT(CQqu_cntFree, CQTEMPLSEUP_ID)(a)
