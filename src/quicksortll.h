/*
 * quicksortll.h
 *
 *  Created on: 13/02/2024
 *      Author: Tiago C. Teixeira
 * Description: C headers for quicksort sorting algorithm for linked lists.
 */

#ifndef QUICKSORTLL_H_
	#define QUICKSORTLL_H_

	#include "sort.h"
	#include "linkedlist.h"

	/*
	 * Performs quick sort in the given linked list.
	 * (recursive function)
	 */
	void quicksortll_sort_recu (struct LinkedListNode* first,
						   	    struct LinkedListNode* last,
								SortCompareFunc comparefunc);

	/*
	 * Performs quick sort in the given linked list.
	 * Note: Invokes quicksort recursive function.
	 */
	void quicksortll_sort (struct LinkedList* list,
						   SortCompareFunc comparefunc);

#endif /* QUICKSORTLL_H_ */
