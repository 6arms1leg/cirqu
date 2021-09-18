/** \file */

#ifndef INCLUDE_MAIN_H
#define INCLUDE_MAIN_H

/* Include libc interfaces */
#include <stdint.h>
#include <stdio.h>

#include "buffer.h" /* Include the CirQu buffer interface */

/* Necessary to make `main()` function unit testable */
#ifndef TEST
#define MAIN main
#else
#define MAIN testable_main
#endif

/** \brief Program entry point */
int MAIN(void);

#endif /* INCLUDE_MAIN_H */
