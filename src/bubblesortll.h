/*
 * bubblesortll.h
 *
 *  Created on: 13/02/2024
 *      Author: Tiago C. Teixeira
 * Description: C headers for bubble sort sorting algorithm for linked lists.
 */

#ifndef BUBBLESORTLL_H_
	#define BUBBLESORTLL_H_

	#include <stdlib.h>
	#include "linkedlist.h"
	#include "sort.h"

/*
 * Function to sort a linked list using bubblesort algorithm.
 *  */
void bubblesortll_sort (struct LinkedList* list,
					    SortCompareFunc comparefunc);

#endif /* BUBBLESORTLL_H_ */
