/** \file */

#ifndef MAIN_H
#define MAIN_H

/* libc interfaces */
#include <stdio.h>
#include <math.h>

/* Make `main()` unit testable */
#ifndef TEST
#define MAIN main
#else
#define MAIN testable_main
#endif

/** \brief Program entry point */
int MAIN(void);

#endif /* MAIN_H */
