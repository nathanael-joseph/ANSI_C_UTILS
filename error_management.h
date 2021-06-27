/*
-------------------------------------------------------------------------------
Author: Nathanael J Y
Last Modified: 06/05/2021
Written for: The Open University Of Israel
Course: 20465 - C Programming Workshop
Assignment: Maman 22 Question 1
-------------------------------------------------------------------------------
*/

#ifndef ERRORMANAGEMENT_H
#define ERRORMANAGEMENT_H

#include <stdlib.h>
#include <stdio.h>
#include "more_types.h"


/* --- CONSTANTS ------------------------------------------ */

#define MEM_ALLOC_ERR (-1)

/* --- TYPE DEFINITIONS ----------------------------------- */

/* --- FUNCTION DECLARATIONS ------------------------------ */

/* Prints an error message to stderr, and exits the program. */
void em_throwMemoryAllocationErorr();



#endif