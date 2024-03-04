/*
 * countsort.h
 *
 *  Created on: 11/02/2024
 *      Author: Tiago C. Teixeira
 * Description: Implements the Countingsort sorting algorithm.
 *
 * About:
 *
 *    Counting Sort is a non-comparison-based sorting algorithm that works well when
 * 	  there is limited range of input values. It is particularly efficient when the range
 * 	  of input values is small compared to the number of elements to be sorted. The basic
 * 	  idea behind Counting Sort is to count the frequency of each distinct element in the
 * 	  input array and use that information to place the elements in their correct sorted
 * 	  positions.
 *
 *
 * Counting Sort Algorithm:
 *
 *    Declare an auxiliary array countArray[] of size max(inputArray[])+1 and
 *    initialize it with 0.
 *
 *    Traverse array inputArray[] and map each element of inputArray[] as an index of
 *    countArray[] array, i.e., execute countArray[inputArray[i]]++ for 0 <= i < N.
 *
 *    Calculate the prefix sum at every index of array inputArray[].
 *
 *    Create an array outputArray[] of size N.
 *
 *    Traverse array inputArray[] from end and update
 *    outputArray[ countArray[ inputArray[i] ] – 1] = inputArray[i]. Also, update
 *    countArray[ inputArray[i] ] = countArray[ inputArray[i] ]- – .
 *
 *
 * Pseudocode:
 *
 * 	function countingSort(array, min, max):					(1)
 *   	count: array of (max - min + 1) elements			(2)
 *   	initialize count with 0								(3)
 *   	for each number in array do							(4)
 *       	count[number - min] := count[number - min] + 1	(5)
 *   	done
 *   	z := 0												(6)
 *   	for i from min to max do							(7)
 *       	while ( count[i - min] > 0 ) do					(8)
 *            	array[z] := i								(9)
 *            	z := z+1									(10)
 *            	count[i - min] := count[i - min] - 1		(11)
 *        	done
 *    	done
 *
 *
 * Complexity Analysis of Counting Sort:
 *
 *    Time Complexity: O(N+M), where N and M are the size of inputArray[] and countArray[] respectively.
 *        Worst-case: O(N+M).
 *        Average-case: O(N+M).
 *        Best-case: O(N+M).
 *
 *    Auxiliary Space: O(N+M), where N and M are the space taken by outputArray[] and countArray[] respectively.
 *						On in place version space complexity is only O(M) for only countArray[].
 *
 * Advantage of Counting Sort:
 *
 *    Counting sort generally performs faster than all comparison-based sorting algorithms, such as merge sort and quicksort, if the range of input is of the order of the number of input.*
 *    Counting sort is easy to code*
 *    Counting sort is a stable algorithm.
 *
 * Disadvantage of Counting Sort:
 *
 *    Counting sort doesn’t work on decimal values.
 *    Counting sort is inefficient if the range of values to be sorted is very large.
 *    Counting sort is not an In-place sorting algorithm, It uses extra space for sorting the array elements.
 *    (Note: This is an in place version implementation)
 *
 *
 * Sources:
 * 		https://www.geeksforgeeks.org/counting-sort/?ref=lbp
 * 		https://www.codingeek.com/algorithms/counting-sort-explanation-pseudocode-and-implementation/
 */

#include "sort.h"

/*
 * Finds min and max values from input array[from..to].
 */
static void countingsort_min_max (int arr[], const int from, const int to,
							 int *min, int *max)
{
	int i;
	*min = *max = arr[from];
	for(i=(from+1); i < (to+1); i++) {
		if ( arr[i] < *min ) {
			*min = arr[i];
		} else if ( arr[i] > *max ) {
			*max = arr[i];
		}
	}
}

/*
 * Function to sort array[from..to] with Counting sort algorithm with
 * given min and max values.
 * Note: This is a in place counting sort version.
 */
void countingsort_sort_in_place_mm (int arr[], const int from, const int to,
						const int min, const int max)
{
	int i, j, z;

	int range = max - min + 1;
	int count[range];// = malloc (range * sizeof(*arr));

	for(i = 0; i < range; i++) count[i] = 0;
	for(i = from; i < (to + 1); i++)
		count[arr[i] - min]++;

	for(i = min, z = from; i <= max; i++) {
		for(j = 0; j < count[i - min]; j++) {
			arr[z++] = i;
		}
	}

//	free (count);
}

/*
 * Function to sort array[from..to] with Counting sort algorithm.
 * Note: In place version.
 */
void countingsort_sort_in_place (int arr[], const int from, const int to)
{
	int min, max;
	countingsort_min_max (arr, from, to, &min, &max);
	countingsort_sort_in_place_mm (arr, from, to,
						  min, max);
}

/*
 * Counting sort function (not in place version)
 * Sorts array elements at indexes [from..to].
 * */
int* countingsort_sort_mm (int arr[], const int n, const int from, const int to,
						   const int min, const int max)
{
    int i, j;
    int* out = malloc (n * sizeof (int));
    int range = max-min+1;
	int count[range];

    // Initializing counting array count[i] to 0
    for (i=0; i<range; i++) count[i] = 0;

    // Store count of each element in array count
    for (j=from; j<(to+1); j++)
        count[arr[j-min]]++;

    /* Change count[i] such that it contains actual
    position of these elements in output array*/
    for (i=1; i<range; i++)
        count[i] = count[i] + count[i-1];

    // Creating Output array from count[i]
    // and decrementing value of count[i].
    for (j=to; j>=from; j--)
    {
        out[count[arr[j]-min]-1] = arr[j];
        count[arr[j]-min]--;
    }

    return out;
}

/*
 * Function to sort array[from..to] with Counting sort algorithm.
 * Note: Not in place version.
 */
int* countingsort_sort (int arr[], const int n, const int from, const int to)
{
	int min, max;
	countingsort_min_max (arr, from, to, &min, &max);
	return countingsort_sort_mm (arr, n, from, to,
						         min, max);
}
