/*
 * bubblesort.c
 *
 *  Created on: 05/02/2024
 *      Author: Tiago C. Teixeira
 * Description: Implements the bubble sort algorithm.
 *
 *
 * Algorithm:
 *
 *   1. traverse from left and compare adjacent elements and the higher one is placed at
 *       right side.
 *   2. In this way, the largest element is moved to the rightmost end at first.
 *   3. This process is then continued to find the second largest and place it and so on until the data is sorted.
 *
 *
 * Pseudocode:
 *
 * function BUBBLESORT(ARRAY)							        (1)
 *   # loop through the array multiple times
 *   loop INDEX from 0 to size of ARRAY – 1					    (2)
 *       # consider every pair of elements except the sorted ones
 *       loop INDEX2 from 0 to size of ARRAY – 2 – INDEX		(3)
 *           if ARRAY[INDEX2] > ARRAY[INDEX2 + 1] then			(4)
 *               # swap elements if they are out of order
 *               TEMP = ARRAY[INDEX2]						    (5)
 *               ARRAY[INDEX2] = ARRAY[INDEX2 + 1]				(6)
 *               ARRAY[INDEX2 + 1] = TEMP					    (7)
 *           end if
 *       end loop
 *   end loop
 * end function
 *
 *
 * Complexity Analysis of Bubble Sort:
 *
 * Time Complexity: O(N2)
 * Auxiliary Space: O(1)
 *
 *
 *   Best Case: The best case occurs when the array is already sorted. So the number of
 *   comparisons required is N-1 and the number of swaps required = 0. Hence the
 *   best case complexity is O(N).
 *
 *   Worst Case: The worst-case condition for bubble sort occurs when elements of the
 *   array are arranged in decreasing order.
 *   In the worst case, the total number of iterations or passes required to sort a
 *   given array is (N-1). where ‘N’ is the number of elements present in the array.
 *
 * 	 In worst case, Total number of swaps = Total number of comparison
 *   Total number of comparison (Worst case) = N(N-1)/2
 *   Total number of swaps (Worst case) = N(N-1)/2
 *
 *   So worst case time complexity is O(N2) as N2 is the highest order term.
 *
 *   Average Case Time Complexity: The number of comparisons is constant in Bubble Sort.
 *   So in average case, there are O(N2) comparisons. This is because irrespective of
 *   the arrangement of elements, the number of comparisons C(N) is same.
 *
 *
 * Advantages of Bubble Sort:
 *
 *    Bubble sort is easy to understand and implement.
 *    It does not require any additional memory space.
 *    It is a stable sorting algorithm, meaning that elements with the same key value
 *    maintain their relative order in the sorted output.
 *
 * Disadvantages of Bubble Sort:
 *
 *    Bubble sort has a time complexity of O(N^2) which makes it very slow for large
 *    data sets.
 *    Bubble sort is a comparison-based sorting algorithm, which means that it requires
 *    a comparison operator to determine the relative order of elements in the input
 *    data set. It can limit the efficiency of the algorithm in certain cases.
 *
 */

#include <stdlib.h>
#include <stdbool.h>
#include "sort.h"

/*
 * Sorts an array or part of an array items [from..to] using an optimized version
 * of bubble sort algorithm.
 * Note: from (inclusive) .. to (inclusive)
 */
void bubblesort_sort (void* arr[], const int from, const int to,
					  SortCompareFunc comparefunc)
{
	int i, j;
	bool swapped;
	// Index 'to' inclusive
	for (i = from; i < (to + 1); ++i) {
		swapped = false;
		for (j = from; j < (to - (i - from)); ++j) {
			if (comparefunc (arr[j], arr[j+1]) > 0)
			{
				sort_swap (&arr[j], &arr[j+1]);
				swapped = true;
			}
		}

		// If nothing changed in last inner loop means list is already sorted.
		// Exit loop
		if (!swapped)
			break;
	}
}

