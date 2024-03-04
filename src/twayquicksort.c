/*
 * threewayquicksort.c
 *
 *  Created on: 22/02/2024
 *      Author: Tiago C. Teixeira
 * Description: Implements the Threewayquicksort sorting algorithm.
 *
 * Note: Simple Quicksort exhibits poor performance for inputs that contain many
 * 		 repeated elements. This implementation is more eficient for cases with
 * 		 many repeated elements.
 *
 * About:
 *
 *   In simple QuickSort algorithm, we select an element as pivot, partition the
 *   array around a pivot and recur for subarrays on the left and right of
 *   the pivot.
 *   Consider an array which has many redundant elements. For example,
 *   {1, 4, 2, 4, 2, 4, 1, 2, 4, 1, 2, 2, 2, 2, 4, 1, 4, 4, 4}. If 4 is picked as
 *   a pivot in Simple Quick Sort, we fix only one 4 and recursively process
 *   remaining occurrences.
 *   The idea of 3 way Quick Sort is to process all occurrences of the pivot and
 *   is based on Dutch National Flag algorithm.
 *
 *   In 3 Way QuickSort, an array arr[l..r] is divided in 3 parts:
 *     a) arr[l..i] elements less than pivot.
 *     b) arr[i+1..j-1] elements equal to pivot.
 *     c) arr[j..r] elements greater than pivot.
 *
 *
 * Conclusions:
 * 	   The 3-way partition variation of quick sort has slightly higher overhead
 * 	   compared to the standard 2-way partition version. Both have the same best,
 * 	   typical, and worst case time bounds, but this version is highly adaptive
 * 	   in the very common case of sorting with few unique keys.
 *
 * PROPERTIES:
 *
 *    Not stable
 *    O(lg(n)) extra space
 *    O(n^2) time, but typically O(n·lg(n)) time
 *    Adaptive: O(n) time when O(1) unique keys
 *
 *
 * Souces:
 *    https://www.geeksforgeeks.org/3-way-quicksort-dutch-national-flag/
 * 	  https://www.toptal.com/developers/sorting-algorithms/quick-sort-3-way
 *
 */

#include <stdlib.h>
#include <stdbool.h>
#include "sort.h"

/* This function partitions a[] in three parts
 *  a) a[l..i] contains all elements smaller than pivot
 *  b) a[i+1..j-1] contains all occurrences of pivot
 *  c) a[j..r] contains all elements greater than pivot
 *  */
static void twayquicksort_partition (void* a[], int l, int r, int* i, int* j,
									 SortCompareFunc comparefunc)
{
    *i = l - 1; *j = r;
    int p = l - 1; int q = r;
    void* v = a[r];

    while (true) {
        // From left, find the first element greater than
        // or equal to v. This loop will definitely
        // terminate as v is last element
        while (comparefunc (a[++*i], v) < 0)
            ;

        // From right, find the first element smaller than
        // or equal to v
        while (comparefunc (v, a[--*j]) < 0)	// v < a[--*j])
            if (*j == l)
                break;

        // If i and j cross, then we are done
        if (*i >= *j)
            break;

        // Swap, so that smaller goes on left greater goes
        // on right
        sort_swap (&a[*i], &a[*j]);

        // Move all same left occurrence of pivot to
        // beginning of array and keep count using p
        if (comparefunc (a[*i], v) == 0) {
            p++;
            sort_swap (&a[p], &a[*i]);
        }

        // Move all same right occurrence of pivot to end of
        // array and keep count using q
        if (comparefunc (a[*j], v) == 0) {
            q--;
            sort_swap (&a[*j], &a[q]);
        }
    }

    // Move pivot element to its correct index
    sort_swap (&a[*i], &a[r]);

    // Move all left same occurrences from beginning
    // to adjacent to arr[i]
    *j = *i - 1;
    for (int k = l; k < p; k++, *j--)
        sort_swap (&a[k], &a[*j]);

    // Move all right same occurrences from end
    // to adjacent to arr[i]
    *i = *i + 1;
    for (int k = r - 1; k > q; k--, *i++)
        sort_swap (&a[*i], &a[k]);
}

/*
 * 3-way partition based quick sort.
 * Note: When input data repeats many times, this variant is muck more eficient
 * 		 than simple quicksort.
 */
void twayquicksort_sort (void* a[], const int l, const int r,
							 SortCompareFunc comparefunc)
{
    if (r <= l)
        return;

    int i, j;

    // Note that i and j are passed as reference
    twayquicksort_partition (a, l, r, &i, &j, comparefunc);

    // Recur
    twayquicksort_sort (a, l, j, comparefunc);
    twayquicksort_sort (a, i, r, comparefunc);
}
