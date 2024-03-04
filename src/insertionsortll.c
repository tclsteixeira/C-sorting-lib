/*
 * insertionsortll.c
 *
 *  Created on: 13/02/2024
 *      Author: Tiago C. Teixeira
 * Description: Implements the insertion sort sorting algorithm on linked lists.
 *
 *
 * Algorithm:
 *
 *    - Create an empty sorted (or result) list
 *    - Traverse the given list, do following for every node.
 *    - Insert current node in sorted way in sorted or result list.
 *    - Change head of given linked list to head of sorted (or result) list.
 *
 *
 * Time complexity: O(n^2)
 * Auxiliary Space: O(1)
 *
 */

#include <stdlib.h>
#include "llsort.h"
#include "sort.h"
#include <assert.h>
#include "linkedlist.h"


/*
 * Function to insert a new node in a list. Note that
 * this function expects a pointer to head_ref as this
 * can modify the head of the input linked list
 * (similar to push())
 * Returns the last inserted node.
 */
static void insertionsortll_sorted_insert (
									struct LinkedList* list,
									struct LinkedListNode* newNode,
									SortCompareFunc comparefunc)
{
	if (linkedlist_isempty (list)
					|| (!(comparefunc ((*(list->headp))->data, newNode->data) < 0)))
		// Insert at begining
		linkedlist_push_node (list, newNode);
	else
	{
		struct LinkedListNode* current = *(list->headp);
		assert (current != NULL);

		/* Locate the node before the point of insertion
		 */
		while (current->next != NULL
			   && (comparefunc (current->next->data, newNode->data) < 0)) {
			current = current->next;
		}

		linkedlist_insert_node_after (list, current, newNode);
	}
}

/*
 * Function to sort a singly linked list using insertion sort.
 */
void insertionsortll_sort (struct LinkedList* list, SortCompareFunc comparefunc)
{
	if (linkedlist_isempty (list)) return;

	struct LinkedList* sortedList = linkedlist_create (NULL, NULL);
    struct LinkedListNode* current = *(list->headp);

    // Traverse the given linked list and insert every
    // node to sorted
    while (current != NULL) {

        // Store next for next iteration
        struct LinkedListNode* next = current->next;

        // Insert current in sorted linked list
        insertionsortll_sorted_insert (sortedList, current, comparefunc);

        // Update current
        current = next;
    }

    // Update head and tail to point to sorted linked list
    *(list->headp) = *(sortedList->headp);
    *(list->tailp) = *(sortedList->tailp);

    // Now clean up temporary sortedlist
    *(sortedList->headp) = NULL;
    *(sortedList->tailp) = NULL;
    sortedList->size = 0;
    linkedlist_destroy (sortedList);
}







