/*
 * selectionsort.c
 *
 *  Created on: 03/02/2024
 *      Author: Tiago C. Teixeira
 * Description: Implements the selection sort algorithm.
 */

/*
 * Algorithm:
 *
 * Selection sort is a simple and efficient sorting algorithm that works by repeatedly
 * selecting the smallest (or largest) element from the unsorted portion of the list
 * and moving it to the sorted portion of the list.
 *
 * The algorithm repeatedly selects the smallest (or largest) element from the unsorted
 * portion of the list and swaps it with the first element of the unsorted part. This
 * process is repeated for the remaining unsorted portion until the entire list is sorted.
 *
 * PSEUDO CODE:
 *
 * function SELECTIONSORT(ARRAY)					        (1)
 *    loop INDEX from 0 to size of ARRAY – 2			    (2)
 *	  MININDEX = 0						                	(3)
 *        # find minimum index
 *        loop INDEX2 from INDEX to size of ARRAY – 1		(4)
 *            if ARRAY[INDEX2] < ARRAY[MININDEX] then		(5)
 *                MININDEX = INDEX					    	(6)
 *            end if							            (7)
 *        end loop							            	(8)
 *        # swap elements
 *        TEMP = ARRAY[MININDEX]					        (9)
 *        ARRAY[MININDEX] = ARRAY[INDEX]				    (10)
 *        ARRAY[INDEX] = TEMP					            (11)
 *    end loop								            	(12)
 * end function								            	(13)
 *
 *
 * Complexity Analysis of Selection Sort
 *
 * Time Complexity: The time complexity of Selection Sort is O(N2) as there are two
 * 					nested loops:
 *
 *    One loop to select an element of Array one by one = O(N)
 *    Another loop to compare that element with every other Array element = O(N)
 *    Therefore overall complexity = O(N) * O(N) = O(N*N) = O(N2)
 *
 * Auxiliary Space: O(1) as the only extra memory used is for temporary variables while
 * 					swapping two values in Array. The selection sort never makes more than
 * 					O(N) swaps and can be useful when memory writing is costly.
 *
 * Advantages of Selection Sort Algorithm
 *
 *    Simple and easy to understand.
 *    Works well with small datasets.
 *
 * Disadvantages of the Selection Sort Algorithm
 *
 *    Selection sort has a time complexity of O(n^2) in the worst and average case.
 *    Does not work well on large datasets.
 *    Does not preserve the relative order of items with equal keys which means it is not stable.
 */

#include <stdlib.h>
#include "sort.h"

/*
 * Sorts an array or part of an array items [from..to] using the selection sort algorithm.
 * Note: from (inclusive) .. to (inclusive)
 */
void selectionsort_sort (void* arr[], const int from, const int to,
						 SortCompareFunc comparefunc)
{
	int elIdx;
	for (int i = from; i < to; ++i) {
		elIdx = i;
		for (int j = i + 1; j < (to+1); ++j) {
			if (comparefunc (arr[elIdx], arr[j]) > 0)
				elIdx = j;
		}

		sort_swap(&arr[i], &arr[elIdx]);
	}
}

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
								 SortCompareFunc comparefunc)
{
    for (int i = from, j = to; i < j; i++, j--) {
    	void* min = arr[i]; void* max = arr[i];
        int min_i = i; int max_i = i;
        for (int k = i+1; k <= j; k++)  {
        	if (comparefunc (arr[k], max) > 0) {
        		max = arr[k];
                max_i = k;
            } else if (comparefunc (arr[k], min) < 0) {
            	min = arr[k];
                min_i = k;
            }
        }

        // Shifting the min.
        sort_swap (&arr[i], &arr[min_i]);

        // Shifting the max. The equal condition
        // happens if we shifted the max to arr[min_i]
        // in the previous swap.
        if (comparefunc (arr[min_i], max) == 0)
        	sort_swap (&arr[j], &arr[min_i]);
        else
        	sort_swap (&arr[j], &arr[max_i]);
    }
}


