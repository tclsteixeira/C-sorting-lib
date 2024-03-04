/*
 * introsort.c
 *
 *  Created on: 24/02/2024
 *      Author: Tiago C. Teixeira
 * Description: Implements the Introsort sorting algorithm.
 *
 * At year of 2024 this is the default algorithm used in the linux kernel
 * and in the GNU C standard library.
 *
 * About:
 *
 *   Here is how Introsort is formulated:
 *
 * 	Choosing the right sorting algorithm depends on the occasion where the sorting
 * 	algorithm is being used. There are a good number of sorting algorithms in hand
 * 	already that has pros and cons of its own. So, to get a better sorting algorithm,
 * 	the solution is to tweak the existing algorithms and produce a new sorting algorithm
 * 	that works better. There are a lot of hybrid algorithms, that outperforms the general
 * 	sorting algorithms. One such is the Introsort. The best versions of Quicksort are
 * 	competitive with both heap sort and merge sort on the vast majority of inputs. Rarely
 * 	Quicksort has the worst case of O(N^2) running time and O(N) stack usage. Both
 * 	Heapsort and Mergesort have O(N log N) worst-case running time, together with a stack
 * 	usage of O(1) for Heapsort and O(log N) for Mergesort respectively. Also, Insertion
 * 	sort performs better than any of the above algorithms if the data set is small.
 *
 *  Combining all the pros of the sorting algorithms, Introsort behaves based on the
 *  data set.
 *
 *    1. If the number of elements in the input gets fewer, the Introsort performs
 *       Insertion sort for the input.
 *    2. Having the least number of comparisons(Quicksort) in mind, for splitting the
 *       array by finding the pivot element, Quicksort is used. Quoted earlier, the worst
 *       case of Quicksort is based on the two phases and here is how we can fix them.
 *         1. Choosing the pivot element: We can use either of median-of-3 concept or
 *            randomized pivot concept or middle as the pivot concept for finding the
 *            pivot element
 *         2. Recursion depth during the course of the algorithm: When the recursion
 *            depth gets higher, Introsort uses Heapsort as it has the definite upper
 *            bound of O(N log N).
 *
 * How does depthLimit work?
 * DepthLimit represents maximum depth for recursion. It is typically chosen as log of
 * length of input array (please refer below implementation). The idea is to ensure that
 * the worst case time complexity remains O(N log N). Note that the worst-case time
 * complexity of HeapSort is O(N log N).
 *
 * Why is Mergesort not used?
 * As the arrays are being dealt with the in-place concept where Quicksort outperforms
 * Mergesort, we are not using Mergesort.
 *
 * Can Introsort be applied everywhere?
 *
 *    1. If the data won’t fit in an array, Introsort cannot be used.
 *    2. Furthermore, like Quicksort and Heapsort, Introsort is not stable. When a
 *       stable sort is needed, Introsort cannot be applied.
 *
 * Pseudocode:
 *
 * sort(A : array):
 *    depthLimit = 2xfloor(log(length(A)))
 *    introsort(A, depthLimit)
 *
 * introsort(A, depthLimit):
 *    n = length(A)
 *    if n<=16:
 *        insertionSort(A)
 *    if depthLimit == 0:
 *        heapsort(A)
 *    else:
 *
 *        // using quick sort, the
 *        // partition point is found
 *        p = partition(A)
 *        introsort(A[0:p-1], depthLimit - 1)
 *        introsort(A[p+1:n], depthLimit - 1)
 *
 *
 * Time Complexity:
 * 		Worst-case performance: O(nlogn) (better than Quicksort)
 * 		Average-case performance: O(nlogn)
 *
 *
 * In the Quicksort phase, the pivot can either be chosen using the median-of-3
 * concept or last element of the array. For data that has a huge number of
 * elements, median-of-3 concept slows down the running time of the Quicksort.
 * In the example described below, the quicksort algorithm calculates the pivot
 * element based on the median-of-3 concept.
 *
 */

#include <math.h>
#include "sort.h"

/*
 * To maxHeap a subtree rooted with node i which is an index
 * in []a. heapN is size of heap.
 */
static void introsort_max_heap (void* arr[],
								int i,
                     	 	 	int heapN,
								int begin, SortCompareFunc comparefunc)
{
	void* temp = arr[begin + i - 1];
	int child;

	while (i <= heapN / 2)
	{
		child = 2 * i;

		if (child < heapN &&
				(comparefunc (arr[begin + child - 1], arr[begin + child]) < 0))
			child++;

		if (!(comparefunc (temp, arr[begin + child - 1]) < 0))
			break;

		arr[begin + i - 1] = arr[begin + child - 1];
		i = child;
	}

	arr[begin + i - 1] = temp;
}

/*
 * Function to build the heap (rearranging the array).
 */
static void introsort_heapify (void* arr[],
							   int begin,
                     	 	   int end,
							   int heapN,
							   SortCompareFunc comparefunc)
{
	for (int i = (heapN) / 2; i >= 1; i--)
		introsort_max_heap (arr, i, heapN, begin, comparefunc);
}

/*
 * Main function to do heapsort.
 */
static void introsort_heapsort (void* arr[], int begin,
                      	  	  	int end, SortCompareFunc comparefunc)
{
	int heapN = end - begin;

	// Build heap (rearrange array)
	introsort_heapify (arr, begin, end, heapN, comparefunc);

	// One by one extract an element
	// from heap
	for (int i = heapN; i >= 1; i--)
	{
		// Move current root to end
		sort_swap (&arr[begin], &arr[begin + i]);

		// call maxHeap() on the
		// reduced heap
		introsort_max_heap (arr, 1, i, begin, comparefunc);
	}
}

/*
 * Function to sort an array using insertion sort.
 */
static void introsort_insertionsort (void* arr[], int from, int to,
									 SortCompareFunc comparefunc)
{
    for (int i = from + 1; i <= to; i++) {
        void* key = arr[i];
        int j = i - 1;

        /* Move elements of arr[0..i-1], that are
                greater than key, to one position ahead
                of their current position */
        while (j >= from && (comparefunc (arr[j], key) > 0)) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }

    return;
}

/*
 * Function for finding the median of the three elements.
 */
static void* introsort_find_pivot (void* arr[], int a1,
                      	  	  	   int b1, int c1, SortCompareFunc comparefunc)
{
	void* a = arr[a1];
	void* b = arr[b1];
	void* c = arr[c1];

	if ((comparefunc (a, b) < 0) && (comparefunc (b, c) < 0))
		return (b);

	if ((comparefunc (a, c) < 0) && (!(comparefunc (c, b) > 0)))
		return (c);

	if ((!(comparefunc (b, a) > 0)) && (comparefunc (a, c) < 0))
		return (a);

	if ((comparefunc (b, c) < 0) && (!(comparefunc (c, a) > 0)))
		return (c);

	if ((!(comparefunc (c, a) > 0)) && (comparefunc (a, b) < 0))
		return (a);

	if ((!(comparefunc (c, b) > 0)) && (!(comparefunc (b, a) > 0)))
		return (b);

	return NULL;	// Sould never happen!
}

/*
 * This function takes the last element
 * as pivot, places the pivot element at
 * its correct position in sorted
 * array, and places all smaller
 * (smaller than pivot) to the left of
 * the pivot and greater elements to
 * the right of the pivot
 */
static int introsort_partition (void* arr[], int low, int high, SortCompareFunc comparefunc)
{
	void* pivot = arr[high]; // pivot
	int i = (low - 1); // Index of smaller element

	for (int j = low; j <= high - 1; j++) {
		// If current element is smaller than or
		// equal to pivot
		if (!(comparefunc (arr[j], pivot) > 0)) {
			// increment index of smaller element
			i++;
			sort_swap (&arr[i], &arr[j]);
		}
	}

	sort_swap (&arr[i + 1], &arr[high]);
	return (i + 1);
}

/*
 * The main function that implements
 * Introsort low  --> Starting index,
 * 			 high --> Ending index, depthLimit
 * 				  --> recursion level
 */
static void introsort_sort_rec (void* arr[],
								int from,
                          	  	int to,
								int depthLimit,
								SortCompareFunc comparefunc)
{
	int n = to - from + 1;
	if (n <= 16) {
		// if the data set is small,
		// call insertion sort
		introsort_insertionsort (arr, from, to, comparefunc);
	}
	else if (depthLimit == 0)
	{
		// if the recursion limit is
		// occurred call heap sort
		introsort_heapsort (arr, from, to, comparefunc);
	}
	else {
		void* pivot = introsort_find_pivot (arr, from, from + ((to - from) / 2) + 1, to,
										    comparefunc);
		sort_swap (&pivot, &arr[to]);

		// p is partitioning index,
		// arr[p] is now at right place
		int p = introsort_partition (arr, from, to, comparefunc);

		// Separately sort elements
		// before partition and after
		// partition
		introsort_sort_rec (arr, from, p - 1, depthLimit - 1, comparefunc);
		introsort_sort_rec (arr, p + 1, to, depthLimit - 1, comparefunc);
	}
}

/*
 *  Implementation of introsort
 **/
void introsort_sort (void* arr[], int from, int to, SortCompareFunc comparefunc)
{
	int depthLimit = 2 * log (to - from + 1);

	// Perform a recursive Introsort
	introsort_sort_rec (arr, from, to, depthLimit, comparefunc);
	return;
}

