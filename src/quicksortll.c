/*
 * quicksortll.c
 *
 *  Created on: 13/02/2024
 *      Author: Tiago C. Teixeira
 * Description: Implements the quicksort sorting algorithm for linked lists.
 *
 *
 * Algorithm:
 *
 *    - Call the partition function to get a pivot node placed at its correct position.
 *    	- In the partition function, the last element is considered a pivot.
 *      - Then traverse the current list and if a node has a value greater than the
 *        	pivot, then move it after the tail. If the node has a smaller value, then
 *        	keep it at its current position.
 *      - Return pivot node.
 *
 *    - Find the tail node of the list which is on the left side of the pivot and
 *    	  recur for the left list.
 *
 *    - Similarly, after the left side, recur for the list on the right side of the
 *    	  pivot.
 *
 *    - Now return the head of the linked list after joining the left and the right
 *    	  list, as the whole linked list is now sorted.
 *
 *
 * Time complexity: O(n^2)
 * Auxiliary Space: O(1)
 *
 * Source: https://www.geeksforgeeks.org/sorting-a-singly-linked-list/?ref=header_search
 *
 */

#include <stdlib.h>
#include "sort.h"
#include "linkedlist.h"

/*
 * We are Setting the given last node position to its proper position.
 */
static struct LinkedListNode* quicksortll_partition (struct LinkedListNode* first,
                       	   	   	   	   	   	   	     struct LinkedListNode* last,
													 SortCompareFunc comparefunc)
{
	// Get first node of given linked list
	struct LinkedListNode* pivot = first;
    struct LinkedListNode* front = first;
    while (front != NULL && front != last) {
        if (comparefunc (front->data, last->data) < 0) {
            pivot = first;

            // Swapping node values
            sort_swap (&(first->data), &(front->data));

            // Visiting the next node
            first = first->next;
        }

        // Visiting the next node
        front = front->next;
    }

    // Change last node value to current node
    sort_swap (&(first->data), &(last->data));
    return pivot;
}

/*
 * Performs quick sort in the given linked list.
 * (recursive function)
 */
void quicksortll_sort_recu (struct LinkedListNode* first,
					   struct LinkedListNode* last,
					   SortCompareFunc comparefunc)
{
    if (first == last) {
        return;
    }
    struct LinkedListNode* pivot = quicksortll_partition (first, last, comparefunc);

    if (pivot != NULL && pivot->next != NULL) {
    	quicksortll_sort_recu (pivot->next, last, comparefunc);
    }

    if (pivot != NULL && first != pivot) {
    	quicksortll_sort_recu (first, pivot, comparefunc);
    }
}

/*
 * Performs quick sort in the given linked list.
 * Note: Invokes quicksort recursive function.
 */
void quicksortll_sort (struct LinkedList* list,
					   SortCompareFunc comparefunc)
{
	if (!linkedlist_isempty (list))
		quicksortll_sort_recu (*(list->headp), *(list->tailp), comparefunc);
}
