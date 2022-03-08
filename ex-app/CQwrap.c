/** \file */

/* Intentionally include implementation files here (against convention) to
 * allow multiple "instances" of this library while keeping the build process
 * simple
 */

/* Include CirQu buffer implementation (configured with ID 0) */
#define CQTEMPLSEUP_ID 0
#include "CQqu.c"
#undef CQTEMPLSEUP_ID

/* Include CirQu buffer implementation (configured with ID 1) */
#define CQTEMPLSEUP_ID 1
#include "CQqu.c"
#undef CQTEMPLSEUP_ID
