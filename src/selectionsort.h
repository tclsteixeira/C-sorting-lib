/*
 * selectionsort.h
 *
 *  Created on: 04/02/2024
 *      Author: Tiago C. Teixeira
 * Description: C headers for selection sort algorithm.
 */

#ifndef SELECTIONSORT_H_
	#define SELECTIONSORT_H_
	#include "sort.h"

	/*
	 * Sorts an array or part of an array items [from..to] in some order.
	 * Note: from (inclusive) .. to (inclusive)
	 */
	void selectionsort_sort (void* arr[], const int from, const int to,
							 SortCompareFunc comparefunc);

	/*
	 * Sorts an array or part of an array items [from..to] in some order.
	 * Note: from (inclusive) .. to (inclusive)
	 *
	 * This is a slightly better version of selection sort.
	 *
	 * As we know, selection sort algorithm takes the minimum on every pass on the array,
	 * and place it at its correct position.
	 * The idea is to take also the maximum on every pass and place it at its correct
	 * position. So in every pass, we keep track of both maximum and minimum and array
	 * becomes sorted from both ends.
	 *
	 * Adapted from:
	 * 		https://www.geeksforgeeks.org/sorting-algorithm-slightly-improves-selection-sort/?ref=lbp
	 */
	void selectionsort_min_max_sort (void* arr[], const int from, const int to,
									 SortCompareFunc comparefunc);

#endif /* SELECTIONSORT_H_ */
