/*
 * shellsort.c
 *
 *  Created on: 10/02/2024
 *      Author: Tiago C. Teixeira
 * Description: Implements the Shellsort sorting algorithm.
 *
 *
 * About:
 *
 * 	Shell sort is mainly a variation of Insertion Sort. In insertion sort, we move
 * 	elements only one position ahead. When an element has to be moved far ahead, many
 * 	movements are involved. The idea of ShellSort is to allow the exchange of far
 * 	items. In Shell sort, we make the array h-sorted for a large value of h. We keep
 * 	reducing the value of h until it becomes 1. An array is said to be h-sorted if all
 * 	sublists of every h’th element are sorted.
 *
 *
 * Algorithm:
 *
 * 	Step 1 − Start
 * 	Step 2 − Initialize the value of gap size. Example: h
 * 	Step 3 − Divide the list into smaller sub-part. Each must have equal intervals to h
 * 	Step 4 − Sort these sub-lists using insertion sort
 * 	Step 5 – Repeat this step 2 until the list is sorted.
 * 	Step 6 – Print a sorted list.
 * 	Step 7 – Stop.
 *
 *
 * Pseudocode :
 *
 * PROCEDURE SHELL_SORT(ARRAY, N)
 *   WHILE GAP < LENGTH(ARRAY) /3 :
 *                    GAP = ( INTERVAL * 3 ) + 1
 *   END WHILE LOOP
 *   WHILE GAP > 0 :
 *       FOR (OUTER = GAP; OUTER < LENGTH(ARRAY); OUTER++):
 *             INSERTION_VALUE = ARRAY[OUTER]
 *             INNER = OUTER;
 *             WHILE INNER > GAP-1 AND ARRAY[INNER – GAP] >= INSERTION_VALUE:
 *                    ARRAY[INNER] = ARRAY[INNER – GAP]
 *                    INNER = INNER – GAP
 *              END WHILE LOOP
 *              ARRAY[INNER] = INSERTION_VALUE
 *       END FOR LOOP
 *       GAP = (GAP -1) /3;
 *   END WHILE LOOP
 * END SHELL_SORT
 *
 *
 * Time Complexity: Time complexity of the above implementation of Shell sort is O(n^2).
 * In the above implementation, the gap is reduced by half in every iteration. There
 * are many other ways to reduce gaps which leads to better time complexity. See this
 * for more details.
 *
 * Worst Case Complexity
 * The worst-case complexity for shell sort is  O(n^2)
 *
 * Best Case Complexity
 * When the given array list is already sorted the total count of comparisons of each
 * interval is equal to the size of the given array.
 * So best case complexity is Ω(n log(n))
 *
 * Average Case Complexity
 * The shell sort Average Case Complexity depends on the interval selected by
 * the programmer.
 * θ(n log(n)2).
 *
 * THE Average Case Complexity: O(n*log n)~O(n^1.25)
 *
 * Space Complexity
 * The space complexity of the shell sort is O(1).
 *
 *
 * Questions:
 *
 * 1. Which is more efficient shell or heap sort?
 *
 * Ans. As per big-O notation, shell sort has O(n^{1.25}) average time complexity whereas,
 * heap sort has O(N log N) time complexity. According to a strict mathematical
 * interpretation of the big-O notation, heap sort surpasses shell sort in efficiency as
 * we approach 2000 elements to be sorted.
 * Note:- Big-O is a rounded approximation and analytical evaluation is not always
 * 100% correct, it depends on the algorithms’ implementation which can affect actual
 * run time.
 *
 * Shell Sort Applications
 *
 * 1. Replacement for insertion sort, where it takes a long time to complete a given task.
 * 2. To call stack overhead we use shell sort.
 * 3. when recursion exceeds a particular limit we use shell sort.
 * 4. For medium to large-sized datasets.
 * 5. In insertion sort to reduce the number of operations.
 *
 * Source: https://www.geeksforgeeks.org/shellsort/?ref=lbp
 *
 */

#include "sort.h"

/*
 * Function to sort array[from..to] using shellsort algorithm.
 * */
void shellsort_sort (void* arr[], const int from, const int to,
					 SortCompareFunc comparefunc)
{
    // Start with a big gap, then reduce the gap
    for (int gap = (to - from + 1) / 2; gap > 0; gap /= 2)
    {
        // Do a gapped insertion sort for this gap size.
        // The first gap elements a[0..gap-1] are already in gapped order
        // keep adding one more element until the entire array is
        // gap sorted
        for (int i = (from + gap); i < (to + 1); i += 1)
        {
            // add a[i] to the elements that have been gap sorted
            // save a[i] in temp and make a hole at position i
            void* temp = arr[i];

            // shift earlier gap-sorted elements up until the correct
            // location for a[i] is found
            int j=i;
            for (j = i; j >= (from + gap) && (comparefunc (arr[j - gap], temp) > 0); j -= gap)
                arr[j] = arr[j - gap];

            //  put temp (the original a[i]) in its correct location
            arr[j] = temp;
        }
    }
}
