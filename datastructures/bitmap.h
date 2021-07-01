/*
-------------------------------------------------------------------------------
Author: Nathanael J Y
Last Modified: 27/06/2021
Written for: The Open University Of Israel
Course: 20465 - C Programming Workshop
Assignment: Maman 22
-------------------------------------------------------------------------------
*/


#ifndef BITMAP_H
#define BITMAP_H

#include <stdlib.h>
#include "more_types.h"
#include "system_utils/memory_management.h"

/* --- CONSTANTS/MACROS ----------------------------------- */

#define WORD_SIZE 	(32)		/* int is 32 bits */
#define GET_WORD_COUNT(size) (((size) + 31) / WORD_SIZE)
#define WORD_OFFSET(x) (x / WORD_SIZE)
#define BIT_OFFSET(x) (x % WORD_SIZE) 

/* --- TYPE DEFINITIONS ----------------------------------- */

typedef unsigned int Word;

typedef struct {
	unsigned int size;
	Word *words; 
} Bitmap;

/* --- FUNCTION DECLARATIONS ------------------------------ */

/* returns a pointer to a new insatnce of a bitmap, or null if malloc fails */
Bitmap *Bitmap_init(unsigned int size);
/* frees an entire bitmap */
void Bitmap_free(void *bitmap);
/* returns the value of a single bit in the bitmap for a given index */
int Bitmap_getBit(void *bitmap, int index);
/* sets a single bit to 1 for a given index in the bitmap */
void Bitmap_setBit(void *bitmap, int index);
/* sets a single bit to 0 for a given index in the bitmap */
void Bitmap_clearBit(void *bitmap, int index);
/* copies the contents of bitmap_source into bitmap_dest */
void Bitmap_copy(void *bitmap_dest, void *bitmap_source);
/* returns true if the bitmap is empty, false otherwise */
Boolean Bitmap_isEmpty(void *bitmap);

#endif