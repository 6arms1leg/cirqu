/** \file */

/* Intentionally include implementation files here (against convention) to
 * allow multiple "instances" of lib. while keeping the build process simple
 */

/* Implementation of CirQu lib. configured with ID */
#define CQTEMPLSEUP_ID 0
#include "CQqu.c"
#undef CQTEMPLSEUP_ID

/* Implementation of CirQu lib. configured with ID */
#define CQTEMPLSEUP_ID 1
#include "CQqu.c"
#undef CQTEMPLSEUP_ID
