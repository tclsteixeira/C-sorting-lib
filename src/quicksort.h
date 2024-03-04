/*********************************************************************
 * quicksort.h
 *
 *  Created on: 18/03/2023
 *      Author: Tiago C. Teixeira
 * Description: Quicksort implementation in C.
 *
 *----------------------------------------------------------
 *
 * 1. Time Complexities
 *
 *    Worst Case Complexity [Big-O]: O(n2):
 *
 *    It occurs when the pivot element picked is either the greatest or the smallest element.
 *    This condition leads to the case in which the pivot element lies in an extreme
 *    end of the sorted array. One sub-array is always empty and another sub-array
 *    contains n - 1 elements. Thus, quicksort is called only on this sub-array.
 *    However, the quicksort algorithm has better performance for scattered pivots.
 *
 *
 *    Best Case Complexity [Big-omega]: O(n*log n):
 *
 *    It occurs when the pivot element is always the middle element or near to the middle element.
 *    Average Case Complexity [Big-theta]: O(n*log n)
 *    It occurs when the above conditions do not occur.
 *
 * 2. Space Complexity
 *
 * 	  The space complexity for quicksort is O(log n).
 *
 *
 * Quicksort Applications
 *
 * Quicksort algorithm is used when
 *
 *    the programming language is good for recursion
 *    time complexity matters
 *    space complexity matters
 *
 *******************************************************************/


#ifndef QUICKSORT_H_
	#define QUICKSORT_H_

	#include "sort.h"

	void quicksort_sort (void* array[], const int low, const int high,
						 SortCompareFunc comparefunc);

#endif /* QUICKSORT_H_ */

