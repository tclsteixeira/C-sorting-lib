/*
 * mergesortll.h
 *
 *  Created on: 15/02/2024
 *      Author: Tiago C. Teixeira
 * Description: C headers for Mergesort sorting algorithm for linked lists.
 */

#ifndef MERGESORTLL_H_
	#define MERGESORTLL_H_

	#include "linkedlist.h"
	#include "sort.h"

	/*
	 * Sorts the linked list using merge sort algorithm by changing
	 * next pointers (not data).
	 * Note: This is the preferable function version to use.
	 * Time complexity: O(nlog(n))
	 * Space complexity: O(1)
	 * */
	void mergesortll_sort (struct LinkedList* list, SortCompareFunc comparefunc);

	/*
	 * Sorts the linked list using merge sort algorithm by changing
	 * next pointers (not data).
	 * Note: Uses iterative function version to merge two sorted linked lists.
	 * Time complexity: O(nlog(n))
	 * Space complexity: O(1)
	 * */
	void mergesortll_sort_with_it_merge (struct LinkedList* list, SortCompareFunc comparefunc);

#endif /* MERGESORTLL_H_ */
