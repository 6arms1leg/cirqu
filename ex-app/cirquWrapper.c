/** \file */

/* Intentionally include implementation files here (against convention) to
 * allow multiple "instances" of this library while keeping the build process
 * simple
 */

/* Include CirQu buffer implementation (configured with ID 0) */
#define CIRQUID 0
#include "buffer.c"
#undef CIRQUID

/* Include CirQu buffer implementation (configured with ID 1) */
#define CIRQUID 1
#include "buffer.c"
#undef CIRQUID
