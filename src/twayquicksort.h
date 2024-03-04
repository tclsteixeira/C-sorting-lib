/*
 * twayquicksort.h
 *
 *  Created on: 23/02/2024
 *      Author: Tiago C. Teixeira
 * Description: C headers for 3 way quicksort sorting algorithm.
 *
 */

#ifndef TWAYQUICKSORT_H_
	#define TWAYQUICKSORT_H_

	#include "sort.h"

	/*
	 * 3-way partition based quick sort.
	 * Note: When input data repeats many times, this variant is muck more eficient
	 * 		 than simple quicksort.
	 */
	void twayquicksort_sort (void* a[], const int l, const int r,
							 SortCompareFunc comparefunc);

#endif /* TWAYQUICKSORT_H_ */
