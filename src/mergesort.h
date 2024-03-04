/*
 * mergesort.h
 *
 *  Created on: 06/02/2024
 *      Author: Tiago C. Teixeira
 * Description: C headers for the merge sort algorithm.
 */

#ifndef MERGESORT_H_
	#define MERGESORT_H_

	#include <stdlib.h>
	#include "sort.h"

	/*
	 * Sorts an array or part of array using the merge sort recursive algorithm.
	 * l is for left index and r is right index of the
	 * sub-array of arr to be sorted.
	 */
	void mergesort_sort (void* arr[], const int l, const int r,
					 	 SortCompareFunc comparefunc);

#endif /* MERGESORT_H_ */
