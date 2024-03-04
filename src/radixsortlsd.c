/*
 * radixsort.c
 *
 *  Created on: 19/02/2024
 *      Author: Tiago C. Teixeira
 * Description: Implements the Radix sort sorting algorithm.
 *
 * Note: This LSD radix sort implementation only works for non negative integers.
 *
 *
 * About:
 *
 * 	Radix Sort is a linear sorting algorithm that sorts elements by processing them
 * 	digit by digit. It is an efficient sorting algorithm for integers or strings with
 * 	fixed-size keys.
 *
 *
 * Radix Sort Algorithm:
 *
 * 	The key idea behind Radix Sort is to exploit the concept of place value. It
 * 	assumes that sorting numbers digit by digit will eventually result in a fully
 * 	sorted list. Radix Sort can be performed using different variations, such as
 * 	Least Significant Digit (LSD) Radix Sort or Most Significant Digit (MSD)
 * 	Radix Sort.
 *
 *
 * How does Radix Sort Algorithm work?
 *
 *    To perform radix sort on the array [170, 45, 75, 90, 802, 24, 2, 66], we
 *    follow these steps:
 *
 * 		Step 1: Find the largest element in the array, which is 802. It has three
 * 				digits, so we will iterate three times, once for each significant place.
 *
 * 		Step 2: Sort the elements based on the unit place digits (X=0). We use a
 * 				stable sorting technique, such as counting sort, to sort the digits
 * 				at each significant place.
 *
 * 		Sorting based on the unit place:
 *
 *    	- Perform counting sort on the array based on the unit place digits.
 *    	- The sorted array based on the unit place is [170, 90, 802, 2, 24, 45, 75, 66].
 *
 *
 * 		Step 3: Sort the elements based on the tens place digits.
 *
 * 		Sorting based on the tens place:
 *
 *    	- Perform counting sort on the array based on the tens place digits.
 *    	- The sorted array based on the tens place is [802, 2, 24, 45, 66, 170, 75, 90].
 *
 *
 * 		Step 4: Sort the elements based on the hundreds place digits.
 *
 * 		Sorting based on the hundreds place:
 *
 *    	- Perform counting sort on the array based on the hundreds place digits.
 *    	- The sorted array based on the hundreds place is [2, 24, 45, 66, 75, 90, 170, 802].
 *
 *
 * 		Step 5: The array is now sorted in ascending order.
 *
 * 		- The final sorted array using radix sort is [2, 24, 45, 66, 75, 90, 170, 802].
 *
 *
 * Complexity Analysis of Radix Sort:
 *
 * Time Complexity:
 *
 *    Radix sort is a non-comparative integer sorting algorithm that sorts data with
 *    integer keys by grouping the keys by the individual digits which share the same
 *    significant position and value. It has a time complexity of O(d * (n + b)),
 *    where d is the number of digits, n is the number of elements, and b is the base
 *    of the number system being used.
 *    In practical implementations, radix sort is often faster than other
 *    comparison-based sorting algorithms, such as quicksort or merge sort, for large
 *    datasets, especially when the keys have many digits. However, its time
 *    complexity grows linearly with the number of digits, and so it is not as
 *    efficient for small datasets.
 *
 * Auxiliary Space:
 *
 *    Radix sort also has a space complexity of O(n + b), where n is the number of
 *    elements and b is the base of the number system. This space complexity comes
 *    from the need to create buckets for each digit value and to copy the elements
 *    back to the original array after each digit has been sorted.
 *
 *
 * Frequently Asked Questions about RadixSort
 *
 * 		Q1. Is Radix Sort preferable to Comparison based sorting algorithms like
 * 		Quick-Sort?
 *
 * 		If we have log2n (log n on base 2) bits for every digit, the running time
 * 		of Radix appears to be better than Quick Sort for a wide range of input
 * 		numbers. The constant factors hidden in asymptotic notation are higher for
 * 		Radix Sort and Quick-Sort uses hardware caches more effectively. Also,
 * 		Radix sort uses counting sort as a subroutine and counting sort takes extra
 * 		space to sort numbers.
 *
 * 		Q2. What if the elements are in the range from 1 to n^2?
 *
 *    	The lower bound for the Comparison based sorting algorithm (Merge Sort, Heap
 *    	Sort, Quick-Sort .. etc) is Ω(nLogn), i.e., they cannot do better than nLogn.
 *    	Counting sort is a linear time sorting algorithm that sort in O(n+k) time
 *    	when elements are in the range from 1 to k.
 *    	We can’t use counting sort because counting sort will take O(n^2) which is
 *    	worse than comparison-based sorting algorithms. Can we sort such an array
 *    	in linear time?
 *
 *      Radix Sort is the answer. The idea of Radix Sort is to do digit-by-digit
 *      sorting starting from the least significant digit to the most significant
 *      digit. Radix sort uses counting sort as a subroutine to sort.
 *
 *
 * 	Note: LSD radix sort implementation for non negative integers.
 *
 *
 * When to use Radix Sort vs. Bucket Sort
 *
 *   - Radix Sort is suitable for sorting elements with varying key sizes and
 *     for parallelization.
 *   - Bucket Sort is suitable for sorting uniformly distributed numbers within a
 *     specific range and works well with distributed computing.
 *
 *   Choosing the right algorithm depends on the size of the dataset, the
 *   distribution of the data, and the computing environment.
 *
 * 	Source: https://www.geeksforgeeks.org/radix-sort/?ref=header_search
 *
 */

/*
 * A utility function to get maximum value in arr[from..to].
 */
static int radixsortlsd_get_max (int arr[], const int from, const int to)
{
    int mx = arr[from];
    for (int i = (from + 1); i < (to+1); i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

/*
* A function to do counting sort of arr[] according to the digit represented by exp.
*/
static void radixsortlsd_countsort (int arr[], const int from, const int to, int exp)
{
	const int n = to - from + 1;
	// Output array	\111													111111111111111111
	int output[n];
	int i, count[10] = { 0 };

	// Store count of occurrences
	// in count[]
	for (i = from; i < (to + 1); i++)
		count[(arr[i] / exp) % 10]++;

	// Change count[i] so that count[i]
	// now contains actual position
	// of this digit in output[]
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	int cntidx;
	// Build the output array
	for (i = to; i >= from; i--) {
		cntidx = (arr[i] / exp) % 10;
		output[count[cntidx] - 1] = arr[i];
		count[cntidx]--;
	}

	// Copy the output array to arr[],
	// so that arr[] now contains sorted
	// numbers according to current digit
	for (i = 0; i < n; i++)
		arr[i+from] = output[i];
}

/*
 * The main function to that sorts integer arr[from..to] using Radix Sort.
 * Note: Only works for non-negative integers.
 * LSD radixsort implementation.
 */
void radixsortlsd_sort_ints (int arr[], const int from, const int to)
{
	// Find the maximum number to
    // know number of digits
    int m = radixsortlsd_get_max (arr, from, to);

    // Do counting sort for every digit.
    // Note that instead of passing digit
    // number, exp is passed. exp is 10^i
    // where i is current digit number
    for (int exp = 1; m / exp > 0; exp *= 10)
    	radixsortlsd_countsort (arr, from, to, exp);
}
