/** \file */

/* No include guards here (allow multiple inclusions due to "template" feature)
 */

/* Function-like macros to concatenate two names */
#undef CQTEMPLSEUP_CAT_I
#undef CQTEMPLSEUP_CAT

/* Rename (concatenate) types (user-provided) */
#undef CQTYP_ITEMQUAL_T
#undef CQtyp_item_t
#undef CQtyp_idx_t

/* Rename (concatenate) types */
#undef CQqu_item_t
#undef CQqu_qu_t

/* Rename (concatenate) functions */
#undef CQqu_init
#undef CQqu_pushHead
#undef CQqu_pushTail
#undef CQqu_pull
#undef CQqu_peek
#undef CQqu_cntFree
