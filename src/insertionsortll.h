/*
 * insertionsortll.h
 *
 *  Created on: 13/02/2024
 *      Author: Tiago C. Teixeira
 * Description: Content description here.
 */

#ifndef INSERTIONSORTLL_H_
	#define INSERTIONSORTLL_H_

	#include "sort.h"
	#include "linkedlist.h"

	/*
	 * Function to sort a singly linked list using insertion sort.
	 */
	void insertionsortll_sort (struct LinkedList* list, SortCompareFunc comparefunc);

#endif /* INSERTIONSORTLL_H_ */
