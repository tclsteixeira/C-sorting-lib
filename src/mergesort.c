/*
 * mergesort.c
 *
 *  Created on: 06/02/2024
 *      Author: Tiago C. Teixeira
 * Description: Implements the merge sort algorithm.
 *
 *
 * Merge sort algorithm:
 *
 * The process of merge sort is to divide the array into two halves, sort each half,
 * and then merge the sorted halves back together. This process is repeated until
 * the entire array is sorted.
 *
 * Merge sort is a recursive algorithm that continuously splits the array in half until
 * it cannot be further divided i.e., the array has only one element left (an array
 * with one element is always sorted). Then the sorted subarrays are merged into one
 * sorted array.
 *
 * Pseudocode:
 *
 * 	function MERGE(ARRAY, START, HALF, END)			    (1)
 * 	   	TEMPARRAY = new array[END – START + 1]			(2)
 * 	   	INDEX1 = START							        (3)
 * 	   	INDEX2 = HALF + 1						        (4)
 *  	NEWINDEX = 0							        (5)
 *    	loop while INDEX1 <= HALF and INDEX2 <= END		(6)
 *        	if ARRAY[INDEX1] < ARRAY[INDEX2] then		(7)
 *            	TEMPARRAY[NEWINDEX] = ARRAY[INDEX1]		(8)
 *            	INDEX1 = INDEX1 + 1					    (9)
 *        	else								        (10)
 *            	TEMPARRAY[NEWINDEX] = ARRAY[INDEX2]		(11)
 *            	INDEX2 = INDEX2 + 1					    (12)
 *        	end if							            (13)
 *        	NEWINDEX = NEWINDEX + 1					    (14)
 *    	end loop								        (15)
 *    	loop while INDEX1 <= HALF					    (16)
 *        	TEMPARRAY[NEWINDEX] = ARRAY[INDEX1]			(17)
 *        	INDEX1 = INDEX1 + 1					        (18)
 *        	NEWINDEX = NEWINDEX + 1					    (19)
 *    	end loop								        (20)
 *    	loop while INDEX2 <= END					    (21)
 *        	TEMPARRAY[NEWINDEX] = ARRAY[INDEX2]			(22)
 *        	INDEX2 = INDEX2 + 1					        (23)
 *        	NEWINDEX = NEWINDEX + 1					    (24)
 *    	end loop								        (25)
 *    	loop INDEX from 0 to size of TEMPARRAY – 1		(26)
 *        	ARRAY[START + INDEX] = TEMPARRAY[INDEX]		(27)
 *    	end loop								        (28)
 * 	end function								        (29)
 *
 *	function MERGESORT(ARRAY, START, END)			(1)
 *    	# base case size == 1
 *    	if END - START + 1 == 1 then				(2)
 *        	return						            (3)
 *    	end if							            (4)
 *    	# base case size == 2
 *    	if END - START + 1 == 2 then				(5)
 *       	# check if elements are out of order
 *        	if ARRAY[START] > ARRAY[END] then		(6)
 *            	# swap if so
 *            	TEMP = ARRAY[START]				    (7)
 *            	ARRAY[START] = ARRAY[END]			(8)
 *            	ARRAY[END] = TEMP				    (9)
 *        	end if						            (10)
 *        	return						            (11)
 *    	end if							            (12)
 *    	# find midpoint
 *    	HALF = int(START + (END - START) / 2)    	(13)
 *    	# sort first half
 *    	MERGESORT(ARRAY, START, HALF)			    (14)
 *    	# sort second half
 *    	MERGESORT(ARRAY, HALF + 1, END)			    (15)
 *    	# merge halves
 *    	MERGE(ARRAY, START, HALF, END)			    (16)
 * 	end function							        (17)
 *
 *
 * Complexity Analysis of Merge Sort
 *
 * Time Complexity: O(N log(N)),  Merge Sort is a recursive algorithm and time
 * 								  complexity can be expressed as following recurrence
 * 								  relation.
 *
 *								  T(n) = 2T(n/2) + θ(n)
 *
 * Best/avg/worst case: N log(N),
 * 		as merge sort always divides the array into two halves and takes linear
 * 		time to merge two halves.
 *
 *
 * Auxiliary Space: O(N),
 * 		In merge sort all elements are copied into an auxiliary array.
 * 		So N auxiliary space is required for merge sort.
 *
 *
 * Applications of Merge Sort:
 *
 *    Sorting large datasets: Merge sort is particularly well-suited for sorting large
 *    datasets due to its guaranteed worst-case time complexity of O(n log n).
 *
 *    External sorting: Merge sort is commonly used in external sorting, where the data
 *    to be sorted is too large to fit into memory.
 *
 *    Custom sorting: Merge sort can be adapted to handle different input distributions,
 *     such as partially sorted, nearly sorted, or completely unsorted data.
 *
 *    Inversion Count Problem
 *
 *
 * Advantages of Merge Sort:
 *
 *    Stability: Merge sort is a stable sorting algorithm, which means it maintains
 *    the relative order of equal elements in the input array.
 *
 *    Guaranteed worst-case performance: Merge sort has a worst-case time complexity
 *    of O(N logN), which means it performs well even on large datasets.
 *
 *    Parallelizable: Merge sort is a naturally parallelizable algorithm, which means
 *    it can be easily parallelized to take advantage of multiple processors or threads.
 *
 * Drawbacks of Merge Sort:
 *
 *    Space complexity: Merge sort requires additional memory to store the merged
 *    sub-arrays during the sorting process.
 *
 *    Not in-place: Merge sort is not an in-place sorting algorithm, which means it
 *    requires additional memory to store the sorted data. This can be a disadvantage
 *    in applications where memory usage is a concern.
 *
 *    Not always optimal for small datasets: For small datasets, Merge sort has a
 *    higher time complexity than some other sorting algorithms, such as insertion
 *    sort. This can result in slower performance for very small datasets.
 *
 */

#include <stdlib.h>
#include "sort.h"

/*
 * Merges two subarrays of arr[].
 * First subarray is arr[l..m]
 * Second subarray is arr[m+1..r]
 */
static void mergesort_merge (void* arr[],
							 const int l, const int m, const int r,
							 SortCompareFunc comparefunc)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

    // Create temp arrays
    void* L[n1];
	void* R[n2];

    // Copy data to temp arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Merge the temp arrays back into arr[l..r
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (!(comparefunc (L[i], R[j]) > 0)) {	// (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[],
    // if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[],
    // if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

/*
 * Sorts an array or part of array using the merge sort recursive algorithm.
 * l is for left index and r is right index of the
 * sub-array of arr to be sorted.
 */
void mergesort_sort (void* arr[], const int l, const int r,
					 SortCompareFunc comparefunc)
{
    if (l < r) {
    	int m = l + (r - l) / 2;

        // Sort first and second halves
        mergesort_sort (arr, l, m, comparefunc);
        mergesort_sort (arr, m + 1, r, comparefunc);

        mergesort_merge(arr, l, m, r, comparefunc);
    }
}
