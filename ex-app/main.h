/** \file */

#ifndef MAIN_H
#define MAIN_H

/* Include libc interfaces */
#include <stdint.h>
#include <stdio.h>

/* Necessary to make `main()` function unit testable */
#ifndef TEST
#define MAIN main
#else
#define MAIN testable_main
#endif

/** \brief Program entry point */
int MAIN(void);

#endif /* MAIN_H */
