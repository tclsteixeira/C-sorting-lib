/*
 * llsort.h
 *
 *  Created on: 13/02/2024
 *      Author: Tiago C. Teixeira
 * Description: Content description here.
 */

#ifndef LLSORT_H_
	#define LLSORT_H_
	#include "linkedlist.h"
	#include "sort.h"

	typedef void (*SortLinkedListFunc)(struct LinkedList* list,
									   SortCompareFunc comparefunc);

	/*
	 * Function to swap the nodes of a linked list.
	 * Returns the first node after swap.
	 * */
	struct LinkedListNode* llsort_swap (struct LinkedListNode* ptr1,
										struct LinkedListNode* ptr2);

#endif /* LLSORT_H_ */

