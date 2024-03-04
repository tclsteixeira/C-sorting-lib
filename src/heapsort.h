/*
 * heapsort.h
 *
 *  Created on: 07/02/2024
 *      Author: Tiago C. Teixeira
 * Description: C headers for heap sort algorithm.
 */

#ifndef HEAPSORT_H_
	#define HEAPSORT_H_

	#include <stdlib.h>
	#include "sort.h"

	/*
	 * Sorts an array or part of an array using heap sort algorithm (iteractiva version).
	 * 'from' and 'to' are inclusive array bounds to sort.
	 */
	void heapsort_sort (void* arr[], const int from, const int to,
						SortCompareFunc comparefunc);

#endif /* HEAPSORT_H_ */
