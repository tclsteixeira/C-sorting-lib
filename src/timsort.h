/*
 * timsort.h
 *
 *  Created on: 09/02/2024
 *      Author: Tiago C. Teixeira
 * Description: C headers for Timsort sorting algorithm.
 */

#ifndef TIMSORT_H_
	#define TIMSORT_H_

	#include <stdlib.h>
	#include "sort.h"

	/*
	 * Iterative Timsort function to sort the
	 * array[0...n-1] (similar to merge sort)
	 */
	void timsort_sort (void* arr[], const int from, const int to,
					   SortCompareFunc comparefunc);

#endif /* TIMSORT_H_ */
