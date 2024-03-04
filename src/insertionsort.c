/*
 * insertionsort.c
 *
 *  Created on: 06/02/2024
 *      Author: Tiago C. Teixeira
 * Description: Implements the insertion sort algorithm.
 *
 *
 * Insertion Sort Algorithm
 *
 * 	   To sort an array of size N in ascending order iterate over the array and compare
 * 	   the current element (key) to its predecessor, if the key element is smaller than
 * 	   its predecessor, compare it to the elements before. Move the greater elements
 * 	   one position up to make space for the swapped element.
 *
 *
 * Pseudocode:
 *
 * function INSERTIONSORT(ARRAY)							    (1)
 *   # loop through the array multiple times
 *   loop INDEX from 1 to size of ARRAY – 1					    (2)
 *   	KEY = ARRAY[INDEX]										(3)
 *   	INDEX2 = INDEX - 1										(4)
 *   	whileloop INDEX2 >= 0 and ARRAY[INDEX2] > KEY			(5)
 *   		ARRAY[INDEX2 + 1] = ARRAY[INDEX2]					(6)
 *   		INDEX2 = INDEX2 - 1									(7)
 *   	end while
 *   	ARRAY[INDEX2 + 1] = KEY									(8)
 *   end loop
 * end function
 *
 *
 * Time Complexity: O(N^2)
 * Auxiliary Space: O(1)
 *
 *
 * Complexity Analysis of Insertion Sort:
 *
 * Time Complexity of Insertion Sort
 *
 *    The worst-case time complexity of the Insertion sort is O(N^2)
 *    The average case time complexity of the Insertion sort is O(N^2)
 *    The time complexity of the best case is O(N).
 *
 * Space Complexity of Insertion Sort
 *
 * 	  The auxiliary space complexity of Insertion Sort is O(1)
 *
 * Characteristics of Insertion Sort
 *
 *    This algorithm is one of the simplest algorithms with a simple implementation.
 *    Basically, Insertion sort is efficient for small data values.
 *    Insertion sort is adaptive in nature, i.e. it is appropriate for data sets that
 *    are already partially sorted.
 *    Insertion sort is a stable sorting algorithm.
 *
 *
 * When is the Insertion Sort algorithm used?
 *
 *    Insertion sort is used when number of elements is small.
 *    It can also be useful when the input array is almost sorted, and only a
 *    few elements are misplaced in a complete big array.
 *
 * Source: https://www.geeksforgeeks.org/insertion-sort/?ref=lbp
 */

#include "sort.h"

/*
 * Sorts an array or part of an array items [from..to] using the insertion sort algorithm.
 * Note: from (inclusive) .. to (inclusive)
 */
void insertionsort_sort (void* arr[], const int from, const int to,
						 SortCompareFunc comparefunc)
{
	void* key;
	int i, j;
	for (i = (from+1); i < (to+1); ++i) {
		key = arr[i];
		j = i - 1;

		// Move elements of arr[0..i-1], that are
		// greater than key, to one position ahead
		// of their current position
		while ((j >= 0) && (comparefunc (arr[j], key) > 0)) {
			arr[j + 1] = arr[j];
			j = j - 1;
		}

		arr[j + 1] = key;
	}
}
