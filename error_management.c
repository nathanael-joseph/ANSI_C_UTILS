/*
-------------------------------------------------------------------------------
Author: Nathanael J Y
Last Modified: 06/05/2021
Written for: The Open University Of Israel
Course: 20465 - C Programming Workshop
Assignment: Maman 22 Question 1
-------------------------------------------------------------------------------
*/

#include "error_management.h"


/* --- FUNCTION DEFINITIONS ----------------------------------------- */

/* Prints an error message to stderr, and exits the program. */
void em_throwMemoryAllocationErorr() {
	fputs("A memory allocation Error occured... \nExiting... \n", stderr);
	exit(MEM_ALLOC_ERR);
}