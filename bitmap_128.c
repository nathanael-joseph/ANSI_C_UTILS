/*
-------------------------------------------------------------------------------
Author: Nathanael J Y
Last Modified: 06/05/2021
Written for: The Open University Of Israel
Course: 20465 - C Programming Workshop
Assignment: Maman 22 Question 1
-------------------------------------------------------------------------------
*/

#include "bitmap_128.h"

/* --- FUNCTION DEFINITIONS ----------------------------------------- */

/* returns a pointer to a new insatnce of a bitmap, or null if malloc fails */
Bitmap_128 *Bitmap_128_init() {
	/* calloc ensures that Words is zero'd out */
	Bitmap_128 *bm = calloc(1,sizeof(*bm));
	return bm;
}
/* returns the value of a single bit in the bitmap for a given index */
int Bitmap_128_getBit(void *bitmap, int index) {
	Bitmap_128 *bm = bitmap;
	Word mask = 1 << BIT_OFFSET(index);
	return ((bm->words[WORD_OFFSET(index)]) & mask) >> BIT_OFFSET(index);
}
/* sets a single bit to 1 for a given index in the bitmap */
void Bitmap_128_setBit(void *bitmap, int index) {
	Bitmap_128 *bm = bitmap;
	Word mask = 1 << BIT_OFFSET(index);
	bm->words[WORD_OFFSET(index)] |= mask;
}
/* sets a single bit to 0 for a given index in the bitmap */
void Bitmap_128_clearBit(void *bitmap, int index) {
	Bitmap_128 *bm = bitmap;
	Word mask = ~(1 << BIT_OFFSET(index));
	bm->words[WORD_OFFSET(index)] &= mask;
}
/* copies the contents of bitmap_b into bitmap_a */
void Bitmap_128_copy(void *bitmap_a, void *bitmap_b) {
	int i;
	Bitmap_128 *a = bitmap_a, *b = bitmap_b;

	for(i = 0; i < WORD_COUNT; i++) {
		a->words[i] = b->words[i];
	}
}

/* returns true if the bitmap is empty, false otherwise */
Boolean bitmap_128_isEmpty(void *bitmap) {
	int i;
	Bitmap_128 *bm = bitmap;
	Word mask = ~0;
	Word res = 0;

	for(i = 0; i < WORD_COUNT; i++) {
		res |= bm->words[i] & mask;
	}

	return (!res);

}