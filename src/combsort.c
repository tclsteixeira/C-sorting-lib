/*
 * combsort.c
 *
 *  Created on: 09/02/2024
 *      Author: Tiago C. Teixeira
 * Description: Implements the Combsort sorting algorithm.
 *
 *
 * About:
 *
 * Comb Sort is mainly an improvement over Bubble Sort. Bubble sort always compares
 * adjacent values. So all inversions are removed one by one. Comb Sort improves on
 * Bubble Sort by using a gap of the size of more than 1. The gap starts with a large
 * value and shrinks by a factor of 1.3 in every iteration until it reaches the value 1.
 * Thus Comb Sort removes more than one inversion count with one swap and performs
 * better than Bubble Sort.
 * The shrink factor has been empirically found to be 1.3 (by testing Combsort on over
 * 200,000 random lists).
 * Although it works better than Bubble Sort on average, worst-case remains O(n^2).
 *
 *
 * Time Complexity: Average case time complexity of the algorithm is ?(N^2/2^p),
 * 		where p is the number of increments. The worst-case complexity of this algorithm
 * 		is O(n^2) and the Best Case complexity is O(nlogn).
 *
 * Auxiliary Space : O(1).
 *
 */

#include "sort.h"
#include <stdbool.h>

/*
 * To find next gap between elements (/1.3).
 */
static int combsort_get_next_gap (int gap)
{
    // Shrink gap by Shrink factor (factor = 1.3)
    gap = (gap*10)/13;

    if (gap < 1)
        return 1;
    return gap;
}

/*
 * Function to sort a[from..to] using Comb Sort.
 */
void combsort_sort (void* arr[], const int from, const int to,
					SortCompareFunc comparefunc)
{
    // Initialize gap
    int gap = to - from + 1;	// Number of elements to sort

    // Initialize swapped as true to make sure that
    // loop runs
    bool swapped = true;

    // Keep running while gap is more than 1 and last
    // iteration caused a swap
    while (gap != 1 || swapped == true)
    {
        // Find next gap
        gap = combsort_get_next_gap (gap);

        // Initialize swapped as false so that we can
        // check if swap happened or not
        swapped = false;

        // Compare all elements with current gap
        for (int i = 0; i < (to - from + 1 - gap); i++)
        {
            if (comparefunc (arr[i], arr[i + gap]) > 0)
            {
                sort_swap (&arr[i], &arr[i + gap]);
                swapped = true;
            }
        }
    }
}

