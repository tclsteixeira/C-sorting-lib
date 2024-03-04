/*
 * insertionsort.h
 *
 *  Created on: 06/02/2024
 *      Author: Tiago C. Teixeira
 * Description: C headers for insertion sort algorithm.
 */

#ifndef INSERTIONSORT_H_
	#define INSERTIONSORT_H_

	#include "sort.h"

	/*
	 * Sorts an array or part of an array items [from..to] using the insertion sort algorithm.
	 * Note: from (inclusive) .. to (inclusive)
	 */
	void insertionsort_sort (void* arr[], const int from, const int to,
							 SortCompareFunc comparefunc);

#endif /* INSERTIONSORT_H_ */
