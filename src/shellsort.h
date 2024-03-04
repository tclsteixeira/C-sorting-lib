/*
 * shellsort.h
 *
 *  Created on: 10/02/2024
 *      Author: Tiago C. Teixeira
 * Description: C headers for Shellsort sorting algorithm.
 */

#ifndef SHELLSORT_H_
	#define SHELLSORT_H_

	#include "sort.h"

	/*
	 * Function to sort array[from..to] using shellsort algorithm.
	 * */
	void shellsort_sort (void* arr[], const int from, const int to,
						 SortCompareFunc comparefunc);

#endif /* SHELLSORT_H_ */
