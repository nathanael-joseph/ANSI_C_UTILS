/*
-------------------------------------------------------------------------------
Author: Nathanael J Y
Last Modified: 29/06/2021
Written for: The Open University Of Israel
Course: 20465 - C Programming Workshop
Assignment: Maman 14
-------------------------------------------------------------------------------
*/

#ifndef SINGLE_LINKED_LIST_H
#define SINGLE_LINKED_LIST_H

#include <stdlib.h>
#include "more_types.h"
#include "system_utils/memory_management.h"

/* --- CONSTANTS ------------------------------------------ */

/* --- TYPE DEFINITIONS ----------------------------------- */


typedef struct singleLinkedList SingleLinkedList;


/* --- FUNCTION DECLARATIONS ------------------------------ */

/* Returns a pointer to a new empty linked list */
void *SingleLinkedList_init();

/* Frees the entire list, but does not free the data pointers in the list's nodes */
void SingleLinkedList_free(void *list);

/* Returns true if the linked list is empty, false otherwise. */
Boolean SingleLinkedList_isEmpty(void *list);

/* Returns true if the linked list contains a node with the same key as the parameter key, false otherwise. */
Boolean SingleLinkedList_containsKey(String key, void *list);

/* Returns a pointer to the first list node's data having the key provided. */
void *SingleLinkedList_getDataByKey(String key, void *list);

/* 
  Returns a pointer to the first list node's data for which equals(compareToData, node->data) returns true.
  Returns NULL if no match is found. 
 */
void *SingleLinkedList_getDataByComparison(void *compareData, void *list, Boolean (*equals)(void *a, void *b));

/* Adds a new node with the key and data arguments, to the begining of the list. */
void SingleLinkedList_insert(String key, void *data, void *list);

/* Adds a new node with the key and data arguments, to the end of the list. */
void SingleLinkedList_append(String key, void *data, void *list);

/* Removes the first node in the list having the same key as argument key.  */
void SingleLinkedList_removeDataByKey(String key, void *list);

/* Removes the first node in the list which equals(compareData, node->data) returns true. */
void SingleLinkedList_removeDataByComparison(void *compareData, void *list, Boolean (*equals)(void *a, void *b));




#endif