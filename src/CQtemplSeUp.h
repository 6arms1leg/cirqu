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
#define CAT_I(a, b) a##b
#define CAT(a, b) CAT_I(a, b) /* Layer of indirection */

/* Rename (concatenate) types (user-provided) */
#define CIRQUELEMQUAL_T CAT(CIRQUELEMQUAL_T, CQTEMPLSEUP_ID)
#define cirquElem_t CAT(cirquElem_t, CQTEMPLSEUP_ID)
#define cirquElemIdx_t CAT(cirquElemIdx_t, CQTEMPLSEUP_ID)

/* Rename (concatenate) types */
#define cirquStrgElem_t CAT(cirquStrgElem_t, CQTEMPLSEUP_ID)
#define stc_bffr_t CAT(stc_bffr_t, CQTEMPLSEUP_ID)

/* Rename (concatenate) functions */
#define CQqu_init(a, b, c) CAT(CQqu_init, CQTEMPLSEUP_ID)(a, b, c)
#define CQqu_pushHead(a, b) CAT(CQqu_pushHead, CQTEMPLSEUP_ID)(a, b)
#define CQqu_pushTail(a, b) CAT(CQqu_pushTail, CQTEMPLSEUP_ID)(a, b)
#define CQqu_pull(a, b) CAT(CQqu_pull, CQTEMPLSEUP_ID)(a, b)
#define CQqu_peek(a, b) CAT(CQqu_peek, CQTEMPLSEUP_ID)(a, b)
#define CQqu_cntFree(a) CAT(CQqu_cntFree, CQTEMPLSEUP_ID)(a)
