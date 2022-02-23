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
#define fn_bffr_ini(a, b, c) CAT(fn_bffr_ini, CIRQUID)(a, b, c)
#define fn_bffr_pushHead(a, b) CAT(fn_bffr_pushHead, CIRQUID)(a, b)
#define fn_bffr_pushTail(a, b) CAT(fn_bffr_pushTail, CIRQUID)(a, b)
#define fn_bffr_pull(a, b) CAT(fn_bffr_pull, CIRQUID)(a, b)
#define fn_bffr_peek(a, b) CAT(fn_bffr_peek, CIRQUID)(a, b)
#define fn_bffr_cntFree(a) CAT(fn_bffr_cntFree, CIRQUID)(a)
