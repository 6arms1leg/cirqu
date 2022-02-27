/** \file */

#ifndef CIRQUWRAPPER_H
#define CIRQUWRAPPER_H

/* Include CirQu buffer interface (configured with ID 0) */
#define CIRQUID 0
#include "buffer.h"
#undef CIRQUID

/* Include CirQu buffer interface (configured with ID 1) */
#define CIRQUID 1
#include "buffer.h"
#undef CIRQUID

#endif /* CIRQUWRAPPER_H */