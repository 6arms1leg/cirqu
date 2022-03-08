/** \file */

#ifndef CQWRAP_H
#define CQWRAP_H

/* Include CirQu buffer interface (configured with ID 0) */
#define CIRQUID 0
#include "CQqu.h"
#undef CIRQUID

/* Include CirQu buffer interface (configured with ID 1) */
#define CIRQUID 1
#include "CQqu.h"
#undef CIRQUID

#endif /* CQWRAP_H */
