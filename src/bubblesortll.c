/*
 * bubblesortll.c
 *
 *  Created on: 13/02/2024
 *      Author: Tiago C. Teixeira
 * Description: Implements the Bubblesort sorting algorithm for a linked list.
 *
 *
 * Sort Linked List using Bubble Sort
 *
 *    - Get the Linked List to be sorted
 *    - Apply Bubble Sort to this linked list, in which, while comparing the two
 *    	adjacent nodes, actual nodes are swapped instead of just swapping the data.
 *
 *
 * Time complexity: O(n ^ 2)
 * Auxiliary Space: O(1)
 *
 */

#include <stdlib.h>
#include <stdbool.h>
#include "sort.h"
#include "llsort.h"
#include "linkedlist.h"

/*
 * Function to sort a linked list using bubblesort algorithm.
 *  */
void bubblesortll_sort (struct LinkedList* list,
					    SortCompareFunc comparefunc)
{
    struct LinkedListNode** h;
    int i, j, swapped;
    struct LinkedListNode** head = list->headp;
	struct LinkedListNode** tail = list->tailp;
	size_t count = list->size;

    for (i = 0; i <= count; i++) {

        h = head;
        swapped = false;

        for (j = 0; j < count - i - 1; j++) {

            struct LinkedListNode* p1 = *h;
            struct LinkedListNode* p2 = p1->next;

            if (comparefunc (p1->data, p2->data) > 0) {

                /* update the link after swapping */
                *h = llsort_swap (p1, p2);
                swapped = true;
            }

            h = &(*h)->next;
        }

        /* break if the loop ended without any swap */
        if (!swapped)
            break;
    }

//    list->headp = head;

    // Fix tail pointer
    if (tail) {
    	struct LinkedListNode* node = *tail;
    	if (node) {
    		while (node->next != NULL)
    			node = node->next;

    		*(list->tailp) = node;
    	}
    }
}


