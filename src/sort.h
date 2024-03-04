/*
 * sort.h
 *
 *  Created on: 05/02/2024
 *      Author: Tiago C. Teixeira
 * Description: C headers for utilities functions and types for sorting algorithms.
 */

#ifndef SORT_H_
	#define SORT_H_

	#include <stdlib.h>

	/*
	 * Defines function prototype for comparing two values for sort algorithms.
	 * Should return 1 if a > b, -1 if a < b and 0 if a == b.
	 */
	typedef int (*SortCompareFunc)(const void* a, const void* b);


	/*
	 * Defines function prototype for sorting elements in a array.
	 * 'from' and 'to' arguments are the array index bounds to sort,
	 * and are both inclusive.
	 * Ex: to sort entire array, set from = 0 and to = arraysize-1
	 */
	typedef void (*SortArrayFunc)(void* arr[], const int from, const int to,
								  SortCompareFunc comparefunc);

	/*
	 * Defines function prototype for countingsort sorting (in place version).
	 * 'from' and 'to' arguments are the array index bounds to sort,
	 * and are both inclusive.
	 * Ex: to sort entire array, set from = 0 and to = arraysize-1
	 */
	typedef void (*CountingSortArrayFuncInPlace)(int arr[],
												 const int from, const int to);

	/*
	 * Defines function prototype for radixsort sorting (in place version).
	 * 'from' and 'to' arguments are the array index bounds to sort,
	 * and are both inclusive.
	 * Ex: to sort entire array, set from = 0 and to = arraysize-1
	 */
	typedef void (*RadixSortArrayFuncInPlace)(int arr[],
											  const int from, const int to);

	/*
	 * Defines function prototype for countingsort sorting (in place version).
	 * 'from' and 'to' arguments are the array index bounds to sort,
	 * and are both inclusive.
	 * Ex: to sort entire array, set from = 0 and to = arraysize-1
	 */
	typedef int* (*CountingSortArrayFunc)(int arr[], const int n,
										  const int from, const int to);

	/*
	 * Swaps arguments a and b.
	 */
	void sort_swap (void** a, void** b);

#endif /* SORT_H_ */
