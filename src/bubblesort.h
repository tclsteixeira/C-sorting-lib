/*
 * bubblesort.h
 *
 *  Created on: 05/02/2024
 *      Author: Tiago C. Teixeira
 * Description: C headers for the bubble sort algorithm.
 */

#ifndef BUBBLESORT_H_
	#define BUBBLESORT_H_

	#include "sort.h"

	/*
	 * Sorts an array or part of an array items [from..to] using an optimized version
	 * of the bubble sort algorithm.
	 * Note: from (inclusive) .. to (inclusive)
	 */
	void bubblesort_sort (void* arr[], const int from, const int to,
						  SortCompareFunc comparefunc);

#endif /* BUBBLESORT_H_ */
