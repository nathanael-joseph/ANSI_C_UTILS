/*
-------------------------------------------------------------------------------
Author: Nathanael J Y
Last Modified: 30/06/2021
Written for: The Open University Of Israel
Course: 20465 - C Programming Workshop
Assignment: Maman 14
-------------------------------------------------------------------------------
*/

#ifndef SINGLE_LINKED_LIST_H
#define SINGLE_LINKED_LIST_H

#include <stdlib.h>
#include <stdarg.h>
#include "more_types.h"
#include "system_utils/memory_management.h"
#include "type_utils/string_utils.h"

/* --- CONSTANTS ------------------------------------------ */

/* --- TYPE DEFINITIONS ----------------------------------- */


typedef struct singleLinkedList SingleLinkedList;


/* --- FUNCTION DECLARATIONS ------------------------------ */

/* Returns a pointer to a new empty linked list */
void *SingleLinkedList_init();

/* Frees the entire list, but does not free the data pointers in the list's nodes */
void SingleLinkedList_free(void *list);

/* Frees the entire list, and calls callback(node->data) on each node before it is freed. */
void SingleLinkedList_freeWithCallback(void *list, void (*callback)(void *data) );

/* Returns true if the linked list is empty, false otherwise. */
Boolean SingleLinkedList_isEmpty(void *list);

/* Returns true if the linked list contains a node with the same key as the parameter key, false otherwise. */
Boolean SingleLinkedList_containsKey(String key, void *list);

/* Returns a pointer to the first list node's data having the key provided. */
void *SingleLinkedList_getByKey(String key, void *list);

/* 
  Returns a pointer to the first list node's data for which callback(compareToData, node->data) returns true.
  Returns NULL if no match is found. 
 */
void *SingleLinkedList_getByCallback(void *compareData, void *list, Boolean (*callback)(void *compareData, void *data));

/* Adds a new node with the key and data arguments, to the begining of the list. */
void SingleLinkedList_insert(String key, void *data, void *list);

/* Adds a new node with the key and data arguments, to the end of the list. */
void SingleLinkedList_append(String key, void *data, void *list);

/* 
	Removes the first node in the list having the same key as argument key. 
	Returns the data pointer of the node removed. If no node was removed, returns NULL.
*/
void *SingleLinkedList_removeFirstByKey(String key, void *list);

/* 
	Removes the first node in the list for which callback(compareData, node->data) returns true. 
	Returns the data pointer of the node removed. If no node was removed, returns NULL.
*/
void *SingleLinkedList_removeFirstByCallback(void *compareData, void *list, Boolean (*callback)(void *compareData, void *data));

/* executes (*callback)(key, data) on each node in the list */
void SingleLinkedList_foreach(void *list, void (*callback)(String key, void *data, void *args), void *args);

/* replaces the data for all nodes in the list with the same key as argument key, and returns the number of nodes updated */
unsigned int SingleLinkedList_findAndReplaceByKey(String key, void *data, void *list);



#endif