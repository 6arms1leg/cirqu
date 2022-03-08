/** \file */

/* No include guards here to allow multiple inclusions due to "template"
 * feature
 */

/* Sanity check */
#ifndef CIRQUID
#error CIRQUID must be defined
#endif /* CIRQUID */

/* Function-like macros to concatenate two names
 *
 * One layer of indirection required to always correctly concatenate and expand
 * macros.
 */
#define CAT_I(a, b) a##b
#define CAT(a, b) CAT_I(a, b) /* Layer of indirection */

/* Rename (concatenate) types (user-provided) */
#define CIRQUELEMQUAL_T CAT(CIRQUELEMQUAL_T, CIRQUID)
#define cirquElem_t CAT(cirquElem_t, CIRQUID)
#define cirquElemIdx_t CAT(cirquElemIdx_t, CIRQUID)

/* Rename (concatenate) types */
#define cirquStrgElem_t CAT(cirquStrgElem_t, CIRQUID)
#define stc_bffr_t CAT(stc_bffr_t, CIRQUID)

/* Rename (concatenate) functions */
#define CQqu_init(a, b, c) CAT(CQqu_init, CIRQUID)(a, b, c)
#define CQqu_pushHead(a, b) CAT(CQqu_pushHead, CIRQUID)(a, b)
#define CQqu_pushTail(a, b) CAT(CQqu_pushTail, CIRQUID)(a, b)
#define CQqu_pull(a, b) CAT(CQqu_pull, CIRQUID)(a, b)
#define CQqu_peek(a, b) CAT(CQqu_peek, CIRQUID)(a, b)
#define CQqu_cntFree(a) CAT(CQqu_cntFree, CIRQUID)(a)
