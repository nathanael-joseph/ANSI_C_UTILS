/*
-------------------------------------------------------------------------------
Author: Nathanael J Y
Last Modified: 30/06/2021
Written for: The Open University Of Israel
Course: 20465 - C Programming Workshop
Assignment: Maman 14
-------------------------------------------------------------------------------
*/

#include "datastructures/dictionary.h"

/* --- PRIVATE STRUCT/TYPE DEFINITIONS ------------------------------ */

struct dictionary {
	unsigned int size;
	unsigned int count;

	SingleLinkedList *hashtable;
};

/* --- STATIC FUNCTION DEFINITIONS ---------------------------------- */



/* --- FUNCTION DEFINITIONS ----------------------------------------- */



/* Returns a pointer to a new empty dictionary */
void *Dictionary_init() {
	return NULL;
}

/* Frees the dictionary, but does not call free on value pointers. */
void Dictionary_free() {
	return;
}

/* Returns true if the dictionary contains the argmuent key, false otherwise. */
Boolean Dictionary_containsKey(String key, void *dictionary) {
	return false;
}

/* Adds a new key value pair to the dictionary. Will throw an error if a duplicate key is provided */
/* void Dictionary_add(String key, void *value, void *dictionary); -- use setvalue instead */

/* Updates the value for the argument key in the dictionary. If no such key exists, it will be created */
void Dictionary_setValue(String key, void *value, void *dictionary) {
	return;
}

/* Returns the value pointer for the given key in the dictionary. Returns NULL if no such key exists */ 
void *Dictionary_getValue(String key, void *dictionary) {
	return NULL;
}

/* removes the entry in the hash table for the argument key */
void Dictionary_removeKey(String key, void *dictionary) {
	return;
}

/* returns the current size of the hastable array */
unsigned int Dictionary_getSize(void *dictionary) {
	return 0;
}

/* returns the number of elements in the hashtable devided by the size */
float Dictionary_getDensity(void *dictionary) {
	return 0;
}



