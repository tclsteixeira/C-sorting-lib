/*
 * timsort.c
 *
 *  Created on: 08/02/2024
 *      Author: Tiago C. Teixeira
 * Description: Implements the Timsort sorting algorithm.
 *
 *
 * About:
 * 	Tim Sort is a hybrid sorting algorithm derived from merge sort and insertion sort.
 * 	It was designed to perform well on many kinds of real-world data. Tim Sort is the
 * 	default sorting algorithm used by Python’s sorted() and list.sort() functions.
 *
 * Algorithm:
 * 	The main idea behind Tim Sort is to exploit the existing order in the data to
 * 	minimize the number of comparisons and swaps. It achieves this by dividing the
 * 	array into small subarrays called runs, which are already sorted, and then merging
 * 	these runs using a modified merge sort algorithm.
 *
 *
 * Complexity Analysis:
 *
 * Case Complexity
 *
 * 	|---------------------------------------------------|
 * 	| Best Case		Average Case		Worst Case   	|
 * 	| --------------------------------------------------|
 * 	| Ω(n) 			θ(n*log(n))			O(n*log(n))  	|
 * 	|---------------------------------------------------|
 *
 * Space
 *	O(n)
 *
 * Stable
 *	YES
 *
 * In-Place Sorting
 * 	NO, as it requires extra space
 *
 *
 * Complexity Comparison with Merge and Quick Sort:
 *
 *  |-----------------------------------------------------------|
 * 	| Time Complexity											|
 *  |-----------------------------------------------------------|
 * 	| Algorithm		Best			Average			Worst		|
 * 	|-----------------------------------------------------------|
 * 	| Quick Sort	Ω(n*log(n))		θ(n*log(n))		O(n^2)		|
 *  | Merge Sort	Ω(n*log(n))		θ(n*log(n))		O(n*log(n))	|
 *  | Tim Sort		Ω(n)			θ(n*log(n))		O(n*log(n))	|
 *  |-----------------------------------------------------------|
 *
 *
 * Source: https://www.geeksforgeeks.org/timsort/
 *
 */

#include <stdlib.h>
#include "sort.h"

static const int timsort_RUN = 32;


/*
 * Auxiliary function to return min of two values.
 */
static int timsort_min (const int a, const int b) {
	return (a < b) ? a : b;
}

/*
 * This function sorts array from left index to right index which is
 * of size atmost RUN.
 */
static void timsort_insertion_sort (void* arr[], const int left, const int right,
									SortCompareFunc comparefunc)
{
    for (int i = left + 1; i <= right; i++) {
    	void* temp = arr[i];
    	int j = i - 1;
        while (j >= left && (comparefunc (arr[j], temp) > 0)) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

/*
 * Merge function merges the sorted runs.
 */
static void timsort_merge (void* arr[], const int l, const int m, const int r,
						   SortCompareFunc comparefunc)
{
    // Original array is broken in two
    // parts left and right array
	int len1 = m - l + 1;
	int len2 = r - m;
	void* left[len1];
	void* right[len2];

    for (int i = 0; i < len1; i++)
        left[i] = arr[l + i];
    for (int i = 0; i < len2; i++)
        right[i] = arr[m + 1 + i];

    int i = 0;
    int j = 0;
    int k = l;

    // After comparing, we
    // merge those two array
    // in larger sub array
    while (i < len1 && j < len2) {
        if (!(comparefunc (left[i], right[j]) > 0)) {
            arr[k] = left[i];
            i++;
        }
        else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements of
    // left, if any
    while (i < len1) {
        arr[k] = left[i];
        k++;
        i++;
    }

    // Copy remaining element of
    // right, if any
    while (j < len2) {
        arr[k] = right[j];
        k++;
        j++;
    }
}

/*
 * Iterative Timsort function to sort the
 * array[from...to] (similar to merge sort)
 */
void timsort_sort (void* arr[], const int from, const int to,
				   SortCompareFunc comparefunc)
{
    // Sort individual subarrays of size RUN
    for (int i = from; i < (to + 1); i += timsort_RUN)
    	timsort_insertion_sort (arr, i, timsort_min ((i + timsort_RUN - 1), to),
    							comparefunc);

    // Start merging from size RUN (or 32).
    // It will merge
    // to form size 64, then 128, 256
    // and so on ....
    for (int size = timsort_RUN; size < (to + 1); size = 2 * size) {

        // pick starting point of
        // left sub array. We
        // are going to merge
        // arr[left..left+size-1]
        // and arr[left+size, left+2*size-1]
        // After every merge, we
        // increase left by 2*size
        for (int left = from; left < (to + 1); left += 2 * size) {

            // Find ending point of
            // left sub array
            // mid+1 is starting point
            // of right sub array
        	int mid = left + size - 1;
        	int right = timsort_min ( (left + 2 * size - 1), to );

            // merge sub array arr[left.....mid] &
            // arr[mid+1....right]
            if (mid < right)
            	timsort_merge (arr, left, mid, right, comparefunc);
        }
    }
}



