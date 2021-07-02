/*
-------------------------------------------------------------------------------
Author: Nathanael J Y
Last Modified: 30/06/2021
Written for: The Open University Of Israel
Course: 20465 - C Programming Workshop
Assignment: Maman 14
-------------------------------------------------------------------------------
*/

#include "datastructures/singlelinkedlist.h"

/* --- PRIVATE STRUCT/TYPE DEFINITIONS ------------------------------ */

typedef struct singleLinkedListNode SingleLinkedListNode;

struct singleLinkedListNode {
	SingleLinkedListNode *next;
	String key;
	void *data; 
};

struct singleLinkedList {
	SingleLinkedListNode *head;
	SingleLinkedListNode *tail;
}; 

/* --- STATIC FUNCTION DEFINITIONS ---------------------------------- */

/* returns a pointer to a new list node */ 
static void *SingleLinkedListNode_init(String key, void *data) {
	SingleLinkedListNode *node = malloc(sizeof(*node));

	node->key = calloc(strlen(key)+1, 1);
	strcpy(node->key, key);
	node->data = data;

	return node; 
}

/* frees a single list node and it's key String */
static void SingleLinkedListNode_free(void *node) {
	SingleLinkedListNode *nde = node;

	free(nde->key);
	free(nde); 

	return;
}


/* --- FUNCTION DEFINITIONS ----------------------------------------- */

/* Returns a pointer to a new empty linked list */
void *SingleLinkedList_init() {
	SingleLinkedList *lst = malloc(sizeof(*lst));
	lst->head = NULL;
	lst->tail = lst->head;
	return lst;
}

/* Frees the entire list, but does not free the data pointers in the list's nodes */
void SingleLinkedList_free(void *list) {
	SingleLinkedList_freeWithCallback(list, NULL);
}

/* Frees the entire list, and calls callback(node->data) on each node before it is freed. */
void SingleLinkedList_freeWithCallback(void *list, void (*callback)(void *data) ) {
	SingleLinkedList *lst = list;
	SingleLinkedListNode *current, *next;
	
	next = lst->head;

	while(next != NULL) {
		current = next;
		next = current->next;
		if(callback) {
			(*callback)(current->data);
		}
		SingleLinkedListNode_free(current);
	}

	free(lst);
	return;
}

/* Returns true if the linked list is empty, false otherwise. */
Boolean SingleLinkedList_isEmpty(void *list) {
	SingleLinkedList *lst = list;
	if(lst->head == NULL) 
		return true;
	else
		return false;
}

/* Returns true if the linked list contains a node with the same key as the parameter key, false otherwise. */
Boolean SingleLinkedList_containsKey(void *list, String key) {
	SingleLinkedList *lst = list;
	SingleLinkedListNode *current;

	current	= lst->head;
	while (current != NULL) {

		if (String_equals(current->key, key)) {
			return true;
		}

		current = current->next;
	}
	return false;
}

/* Returns a pointer to the first list node's data having the key provided. */
void *SingleLinkedList_getByKey(void *list, String key) {
	SingleLinkedList *lst = list;
	SingleLinkedListNode *current;

	current	= lst->head;
	while (current != NULL) {

		if (String_equals(current->key, key)) {
			return current->data;
		}

		current = current->next;
	}
	return NULL;
}

/* 
  Returns a pointer to the first list node's data for which equals(compareToData, node->data) returns true.
  Returns NULL if no match is found. 
 */
void *SingleLinkedList_getByCallback(void *list, void *compareData, Boolean (*callback)(void *compareData, void *data)) {
	SingleLinkedList *lst = list;
	SingleLinkedListNode *current;

	current	= lst->head;
	while (current != NULL) {

		if ((*callback)(compareData, current->data)) {
			return current->data;
		}

		current = current->next;
	}
	return NULL;	
}

/* Adds a new node with the key and data arguments, to the begining of the list. */
void SingleLinkedList_insert(void *list, String key, void *data) {

	SingleLinkedList *lst = list;
	SingleLinkedListNode *node = SingleLinkedListNode_init(key, data);

	if (SingleLinkedList_isEmpty(lst)) {
		lst->tail = node;
	}

	node->next = lst->head; /* if list is empty, head is NULL, so list->tail->next == NULL */
	lst->head = node;


	return;
}

/* Adds a new node with the key and data arguments, to the end of the list. O(1) */
void SingleLinkedList_append(void *list, String key, void *data) {

	SingleLinkedList *lst = list;
	SingleLinkedListNode *node; 

	if (SingleLinkedList_isEmpty(lst)) {

		SingleLinkedList_insert(lst, key, data);	
		return;
	} 

	node = SingleLinkedListNode_init(key, data);

	node->next = lst->tail->next; /* NULL */
	lst->tail->next = node;
	lst->tail = node;

	return;
}

/* 
	Removes the first node in the list having the same key as argument key. 
	Returns the data pointer of the node removed. If no node was removed, returns NULL.
*/
void *SingleLinkedList_removeFirstByKey(void *list, String key) {
	
	void *data;

	SingleLinkedList *lst = list;
	SingleLinkedListNode *current, *previous;

	current	= lst->head;

	while (current != NULL) {

		if (String_equals(current->key, key)) {
			
			if(current == lst->head) {
				lst->head = current->next;
			} else {
				previous->next = current->next;
			}

			data = current->data;

			SingleLinkedListNode_free(current);
			return data;
		}

		previous = current;
		current = current->next;
	}

	return NULL;
}


/* 
	Removes the first node in the list for which callback(compareData, node->data) returns true. 
	Returns the data pointer of the node removed. If no node was removed, returns NULL.
*/
void *SingleLinkedList_removeFirstByCallback(void *list, void *compareData, Boolean (*callback)(void *compareData, void *data)) {
	
	void *data;

	SingleLinkedList *lst = list;
	SingleLinkedListNode *current, *previous;

	current	= lst->head;

	while (current != NULL) {

		if ((*callback)(compareData, current->data)) {
			
			if(current == lst->head) {
				lst->head = current->next;
			} else {
				previous->next = current->next;
			}

			data = current->data;

			SingleLinkedListNode_free(current);
			return data;
		}

		previous = current;
		current = current->next;
	}

	return NULL;
}

/* executes (*callback)(key, data) on each node in the list */
void SingleLinkedList_foreach(void *list, void (*callback)(String key, void *data, void *args), void *args) {
	SingleLinkedList *lst = list;
	SingleLinkedListNode *current;

	current	= lst->head;
	while (current != NULL) {

		(*callback)(current->key, current->data, args);

		current = current->next;
	}

	return;
}

/* replaces the data for all nodes in the list with the same key as argument key, and returns the number of nodes updated */
unsigned int SingleLinkedList_findAndReplaceByKey(void *list, String key, void *data) {

	unsigned int count = 0;
	SingleLinkedList *lst = list;
	SingleLinkedListNode *current;

	current	= lst->head;
	while (current != NULL) {

		if (String_equals(current->key, key)) {
			current->data = data;
			count++;
		}

		current = current->next;
	}

	return count;
}
