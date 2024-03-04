/*
 * combsort.h
 *
 *  Created on: 10/02/2024
 *      Author: Tiago C. Teixeira
 * Description: C headers for Combsort sorting algorithm.
 */

#ifndef COMBSORT_H_
	#define COMBSORT_H_

	#include "sort.h"

	/*
	 * Function to sort a[from..to] using Comb Sort.
	 */
	void combsort_sort (void* arr[], const int from, const int to,
						SortCompareFunc comparefunc);

#endif /* COMBSORT_H_ */
