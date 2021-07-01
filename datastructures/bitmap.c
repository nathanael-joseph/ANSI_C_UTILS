/*
-------------------------------------------------------------------------------
Author: Nathanael J Y
Last Modified: 27/06/2021
Written for: The Open University Of Israel
Course: 20465 - C Programming Workshop
Assignment: Maman 22
-------------------------------------------------------------------------------
*/

#include "datastructures/bitmap.h"

/* --- STATIC FUNCTION DEFINITIONS ---------------------------------- */
/* returns the number of words stored in the bitmap's words array */
unsigned int _getWordCount(void *bitmap) {
	Bitmap *bm = bitmap;
	return GET_WORD_COUNT(bm->size);
}

/* --- FUNCTION DEFINITIONS ----------------------------------------- */

/* returns a pointer to a new insatnce of a bitmap, throws error if malloc fails */
Bitmap *Bitmap_init(unsigned int size) {
	Bitmap *bm = malloc(sizeof(*bm));
	bm->words = calloc(GET_WORD_COUNT(size), sizeof(Word));
	bm->size = size;
	return bm;
}

/* frees an entire bitmap */
void Bitmap_free(void *bitmap) {
	Bitmap *bm = bitmap;
	free(bm->words);
	free(bm);
}

/* returns the value of a single bit in the bitmap for a given index */
int Bitmap_getBit(void *bitmap, int index) {
	Bitmap *bm = bitmap;
	Word mask = 1 << BIT_OFFSET(index);
	return (*(bm->words + WORD_OFFSET(index)) & mask) >> BIT_OFFSET(index);
}
/* sets a single bit to 1 for a given index in the bitmap */
void Bitmap_setBit(void *bitmap, int index) {
	Bitmap *bm = bitmap;
	Word mask = 1 << BIT_OFFSET(index);
	*(bm->words + WORD_OFFSET(index)) |= mask;
}
/* sets a single bit to 0 for a given index in the bitmap */
void Bitmap_clearBit(void *bitmap, int index) {
	Bitmap *bm = bitmap;
	Word mask = ~(1 << BIT_OFFSET(index));
	*(bm->words + WORD_OFFSET(index)) &= mask;
}
/* copies the contents of bitmap_source into bitmap_dest */
void Bitmap_copy(void *bitmap_dest, void *bitmap_source) {
	int i;
	Bitmap *dest = bitmap_dest, *source = bitmap_source;

	for(i = 0; i < _getWordCount(source); i++) {
		*(dest->words + i) = *(source->words + i);
	}
}

/* returns true if the bitmap is empty, false otherwise */
Boolean bitmap_isEmpty(void *bitmap) {
	int i;
	Bitmap *bm = bitmap;
	Word mask = ~0;
	Word res = 0;

	for(i = 0; i < _getWordCount(bm); i++) {
		res |= *(bm->words + i) & mask;
	}
	return (!res);

}

