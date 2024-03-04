/*
 * llsort.c
 *
 *  Created on: 13/02/2024
 *      Author: Tiago C. Teixeira
 * Description: Implements utility functions for linked list sorting algorithms.
 */

#include "linkedlist.h"

/*
 * Function to swap the nodes of a linked list.
 * Returns the first node after swap.
 * */
struct LinkedListNode* llsort_swap (struct LinkedListNode* ptr1,
									struct LinkedListNode* ptr2)
{
    struct LinkedListNode* tmp = ptr2->next;
    ptr2->next = ptr1;
    ptr1->next = tmp;
    return ptr2;
}

