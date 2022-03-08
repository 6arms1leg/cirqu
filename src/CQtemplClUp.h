/** \file */

/* No include guards here to allow multiple inclusions due to "template"
 * feature
 */

/* Function-like macros to concatenate two names */
#undef CQTEMPLSEUP_CAT_I
#undef CQTEMPLSEUP_CAT

/* Rename (concatenate) types (user-provided) */
#undef CQTYP_ELEMQUAL_T
#undef cirquElem_t
#undef cirquElemIdx_t

/* Rename (concatenate) types */
#undef cirquStrgElem_t
#undef stc_bffr_t

/* Rename (concatenate) functions */
#undef CQqu_init
#undef CQqu_pushHead
#undef CQqu_pushTail
#undef CQqu_pull
#undef CQqu_peek
#undef CQqu_cntFree
