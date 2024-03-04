/*********************************************************************
 * quicksort.c
 *
 *  Created on: 18/03/2023
 *      Author: Tiago C. Teixeira
 * Description: Quicksort implementation in C.
 *
 *----------------------------------------------------------
 *
 * Note: Simple Quicksort exhibits poor performance for inputs that contain many
 * 		 repeated elements.
 *
 * 1. Time Complexities
 *
 *    Worst Case Complexity [Big-O]: O(n2):
 *
 *    It occurs when the pivot element picked is either the greatest or the smallest element.
 *    This condition leads to the case in which the pivot element lies in an extreme
 *    end of the sorted array. One sub-array is always empty and another sub-array
 *    contains n - 1 elements. Thus, quicksort is called only on this sub-array.
 *    However, the quicksort algorithm has better performance for scattered pivots.
 *
 *
 *    Best Case Complexity [Big-omega]: O(n*log n):
 *
 *    It occurs when the pivot element is always the middle element or near to the middle element.
 *    Average Case Complexity [Big-theta]: O(n*log n)
 *    It occurs when the above conditions do not occur.
 *
 * 2. Space Complexity
 *
 * 	  The space complexity for quicksort is O(log n).
 *
 *
 * Quicksort Applications
 *
 * Quicksort algorithm is used when
 *
 *    the programming language is good for recursion
 *    time complexity matters
 *    space complexity matters
 *
 *******************************************************************/


#include <stdio.h>
#include "quicksort.h"

/*
 * Swap a and b data pointers.
 * */
void quicksort_swap (void** a, void** b) {
	void* t = *a;
	*a = *b;
	*b = t;
}

/*
 * Find the partition position and swap positions.
 * Returns the next pivot position.
 * */
int quicksort_partition (void* array[], int low, int high, int (*comparefunc)(const void* a, const void* b)) {
	// select the rightmost element as pivot
	void* pivot = array[high];

	// pointer for greater element
	int i = (low - 1);

	// traverse each element of the array
	// compare them with the pivot
	for (int j = low; j < high; j++) {
		if (comparefunc (array[j], pivot) <= 0)	{ // (array[j] <= pivot)
			// if element smaller than pivot is found
			// swap it with the greater element pointed by i
			i++;

			// swap element at i with element at j
			quicksort_swap (&array[i], &array[j]);
		}
	}

	// swap the pivot element with the greater element at i
	quicksort_swap (&array[i + 1], &array[high]);

	// return the partition point
	return (i + 1);
}

/*
 * Quicksort recursive algorithm.
 * Returns the source array with its elements sorted.
 * */
void quicksort_sort (void* array[], const int low, const int high,
					 SortCompareFunc comparefunc) {
		//void (*swapfunc)(void* a, void* b)) {
	if (low < high) {

		// find the pivot element such that
		// elements smaller than pivot are on left of pivot
		// elements greater than pivot are on right of pivot
		int pi = quicksort_partition (array, low, high, comparefunc);

		// recursive call on the left of pivot
		quicksort_sort (array, low, pi - 1, comparefunc);

		// recursive call on the right of pivot
		quicksort_sort (array, pi + 1, high, comparefunc);
	}
}

