/*
-------------------------------------------------------------------------------
Author: Nathanael J Y
Last Modified: 31/06/2021
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

	SingleLinkedList **hashtable;
};

/* --- STATIC FUNCTION DEFINITIONS ---------------------------------- */



/* --- FUNCTION DEFINITIONS ----------------------------------------- */



/* Returns a pointer to a new empty dictionary */
void *Dictionary_init() {
	unsigned int i; 

	Dictionary *dict = malloc(sizeof(*dict));
	dict->hashtable = calloc(DICTIONARY_INIT_SIZE, sizeof(*(dict->hashtable)));
	dict->size = DICTIONARY_INIT_SIZE;
	dict->count = 0;

	for(i = 0; i < dict->size; i++) {
		*(dict->hashtable + i) = SingleLinkedList_init();	
	}

	return dict;
}

/* Frees the dictionary, but does not call free on value pointers. */
void Dictionary_free(void * dictionary) {
	Dictionary_freeWithCallback(dictionary, NULL);
}

/* Frees the dictionary, and calls callback(value) on each value before the entry is freed */
void Dictionary_freeWithCallback(void *dictionary, void (*callback)(void *value) ) {
	Dictionary *dict = dictionary;

	unsigned int i;

	for(i = 0; i< dict->size; i++) {
		SingleLinkedList_freeWithCallback( *(dict->hashtable + i), callback);
	}

	free(dict->hashtable);
	free(dict);

	return;
}


/* Returns true if the dictionary contains the argmuent key, false otherwise. */
Boolean Dictionary_containsKey(String key, void *dictionary) {
	Dictionary *dict = dictionary;
	
	unsigned int hashcode = String_hash(key, dict->size);

	return SingleLinkedList_containsKey(key, *(dict->hashtable + hashcode) );
}

/* Adds a new key value pair to the dictionary. Will throw an error if a duplicate key is provided */
/* void Dictionary_add(String key, void *value, void *dictionary); -- use setvalue instead */

/* Updates the value for the argument key in the dictionary. If no such key exists, it will be created */
void Dictionary_setValue(String key, void *value, void *dictionary) {
	Dictionary *dict = dictionary;
	
	unsigned int hashcode = String_hash(key, dict->size);

	/* if no nodes in the list were updated */
	if (!SingleLinkedList_findAndReplaceByKey(key, value, *(dict->hashtable + hashcode) )) {
		SingleLinkedList_insert(key,value, *(dict->hashtable + hashcode) );
		dict->count++;
	}

	return;
}

/* Returns the value pointer for the given key in the dictionary. Returns NULL if no such key exists */ 
void *Dictionary_getValue(String key, void *dictionary) {	
	Dictionary *dict = dictionary;
	
	unsigned int hashcode = String_hash(key, dict->size);	

	return SingleLinkedList_getByKey(key, *(dict->hashtable + hashcode) );
}

/* 
	Removes the entry in the hash table for the argument key, and returns its value pointer.
	Returns NULL if no matching key was found.
*/
void *Dictionary_removeKey(String key, void *dictionary) {
	Dictionary *dict = dictionary;
	
	void *value;
	unsigned int hashcode = String_hash(key, dict->size);	

	value = SingleLinkedList_removeFirstByKey(key, *(dict->hashtable + hashcode) );

	if(value) {
		dict->count--;
	}

	return value;
}

/* returns the current size of the hastable array */
unsigned int Dictionary_getSize(void *dictionary) {
	Dictionary *dict = dictionary;
	return dict->size;
}

/* returns the current number of keys in the dictionary */
unsigned int Dictionary_getCount(void *dictionary) {
	Dictionary *dict = dictionary;
	return dict->count;
}

/* returns the number of elements in the hashtable devided by the size */
float Dictionary_getDensity(void *dictionary) {
	Dictionary *dict = dictionary;
	return (float)dict->count/dict->size;
}



