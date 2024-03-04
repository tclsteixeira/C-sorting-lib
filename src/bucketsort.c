/*
 * bucketsort.c
 *
 *  Created on: 12/02/2024
 *      Author: Tiago C. Teixeira
 * Description: Implements the Bucketsort sorting algorithm.
 *
 * Note; Implements for integers/floats/double lists with support for
 * 		 negative values.
 *
 * About:
 *
 *    Bucket sort is a sorting technique that involves dividing elements into various
 *    groups, or buckets. These buckets are formed by uniformly distributing the elements.
 *    Once the elements are divided into buckets, they can be sorted using any other
 *    (stable) sorting algorithm. Finally, the sorted elements are gathered together in
 *    an ordered fashion.
 *
 *
 * Bucket Sort Algorithm:
 *
 * 	Create n empty buckets (Or lists) and do the following for every array element arr[i].
 *
 *    	- Insert arr[i] into bucket[n*array[i]]
 *    	- Sort individual buckets using insertion sort.
 *    	- Concatenate all sorted buckets.
 *
 *    1. Take the array then find the maximum and minimum elements of the array.
 *    	 Find the range of each bucket.
 *    2. Bucket range:((maximum element – minimum element)/number of elements)
 *    3. Now insert the element into the bucket based on Bucket Index.
 *    	 Bucket Index: floor(a[i]-minimum element)/range
 *    4. Once the elements are inserted into each bucket, sort the elements within
 *    	 each bucket using the insertion sort.
 *
 *
 * Pseudocode:
 *
 * function bucketSort(array, k) is										(1)
 *    buckets ← new array of k empty lists								(2)
 *    range = the buckets interval range = (max-min)/n					(3)
 *    for i = 0 to length(array) do										(4)
 *        insert array[i] into buckets[floor((array[i] - min) / range)]	(5)
 *    for i = 0 to k do 												(6)
 *        nextSort(buckets[i])											(7)
 *   return the concatenation of buckets[0], ...., buckets[k]			(8)
 *
 *
 * Complexity Analysis of Bucket Sort Algorithm
 *
 * Note: The computational complexity depends on the algorithm used to sort each bucket,
 * 		 the number of buckets to use, and whether the input is uniformly distributed.
 *
 * Time Complexity
 *		Best: O(n)
 *		Worst: O(n^2)
 *		Average: O(n+k)
 *
 *	Space Complexity
 *		O(n+k)
 *
 *	Stability
 *		Yes
 *
 *
 * Time Complexity: O(n^2),
 *
 *    If we assume that insertion in a bucket takes O(1) time then steps 1 and 2 of
 *    the above algorithm clearly take O(n) time.
 *    The O(1) is easily possible if we use a linked list to represent a bucket.
 *    Step 4 also takes O(n) time as there will be n items in all buckets.
 *    The main step to analyze is step 3. This step also takes O(n) time on average
 *    if all numbers are uniformly distributed.
 *
 * Best Case Complexity O(n)
 *
 *    It occurs when the elements are distributed uniformly in the buckets, with nearly identical elements in each bucket.
 *    When the elements within the buckets are already sorted, the complexity increases.
 *    If insertion sort is used to sort bucket elements, the overall complexity will be linear, i.e. O(n+k).
 *    O(n) is the complexity of creating buckets, and O(k) is the complexity of sorting
 *    bucket elements using algorithms with linear time complexity in the best case.
 *
 * Average Case Complexity O(n+k)
 *
 *    It happens when the array's elements are distributed at random.
 *    Bucket sorting takes linear time, even if the elements are not distributed uniformly.
 *    It holds until the sum of the squares of the bucket sizes is linear in terms of
 *    the total number of elements.
 *
 * Worst Case Complexity O(n*n)
 *
 *    When elements in the array are close in proximity, they are likely to be placed in the same bucket.
 *    As a result, some buckets may contain more elements than others.
 *    It makes the complexity dependent on the sorting algorithm used to sort the bucket's elements.
 *    When the elements are placed in reverse order, the complexity increases even more.
 *    When insertion sort is used to sort bucket elements, the time complexity becomes O(n^2).
 *
 *
 * Applications of Bucket Sort Algorithm
 *
 * When bucket sorting is used, one of the following conditions must be met:
 *
 *    Bucket sorting is based on the assumption that the input is drawn from a uniform
 *    distribution.
 *    Because of the way elements are assigned to buckets, typically using an array
 *    where the index is the value, bucket sorting can be extremely fast.
 *    This means that more auxiliary memory for the buckets is required at the expense
 *    of running time than more comparison sorts.
 *    By dividing data into small buckets that can be sorted individually, the number
 *    of comparisons that must be performed is reduced.
 *
 *
 * It was found that bucket sort is faster as compared to radix sort, but it uses
 * more memory when compared to radix sort.
 *
 * Advantages And Disadvantages of Bucket Sort:
 *
 * Advantages:
 *
 * 	  - It allows the buckets to be processed independently (you need to sort them
 * 	    independently within the buckets). This plays a great role in the
 * 	    processing of files.
 *
 * Disadvantages:
 *
 *    - It works more efficiently when the data is either less or more evenly
 *      distributed.
 *    - This technique is not valid for all data types due to its bucketing technique.
 *
 *
 *
 * Sources:
 * 		https://www.geeksforgeeks.org/bucket-sort-2/
 * 		https://www.geeksforgeeks.org/radix-sort-vs-bucket-sort/?ref=lbp
 * 		https://www.simplilearn.com/tutorials/data-structure-tutorial/bucket-sort-algorithm
 *
 */

#include <stdlib.h>
#include "sort.h"
#include <assert.h>
#include <stdio.h>
#include "llsort.h"
#include "bucketsort.h"
#include "insertionsortll.h"	// By default Insertion sort for linked lists is used

// Number of buckets
static const int NUM_BUCKETS = 10;

static void bucketsort_get_min_max (void* arr[], const int from, const int to,
									void** min, void** max, SortCompareFunc comparefunc)
{
	*max = arr[from];
	*min = arr[from];

	for (int i = (from + 1); i < (to + 1); ++i) {
		if (comparefunc (arr[i], *max) > 0)
			*max = arr[i];
		else if (comparefunc (*min, arr[i]) > 0)
			*min = arr[i];
	}
}

/*
 * Compute bucket index for a given int value.
 * Common fórmula is: floor((array[i] - min) / range).
 */
static int bucketsort_int_compute_index (void* value, void* min, void* max,
									     const int n, const int numBucks)
{
	int iValue = *((int*)value);
	int iMin = *((int*)min);

	int iRange = ((*((int*)max)) - (*((int*)min))) / n;

	int res = ((iValue - iMin) / iRange);
	if (res > numBucks-1) res = numBucks-1;
	return res;
}

/*
 * Compute bucket index for a given float value.
 * Common fórmula is: floor((array[i] - min) / range).
 */
static int bucketsort_float_compute_index (void* value, void* min, void* max,
										   const int n, const int numBucks)
{
	float fValue = *((float*)value);
	float fMin = *((float*)min);

	float fRange = ((*((float*)max)) - (*((float*)min))) / n;
	int res = ((fValue - fMin) / fRange);
	if (res > numBucks-1) res = numBucks-1;
	return res;

//	float fValue = *((float*)value);
//	float fMax = *((float*)max);
//	return ((numBuckets * fValue) / (fMax * 1.1));
}

/*
 * Compute bucket index for a given double value.
 * Common fórmula is: floor((array[i] - min) / range).
 */
static int bucketsort_double_compute_index (void* value, void* min, void* max,
											const int n, const int numBucks)
{
	double dValue = *((double*)value);
	double dMin = *((double*)min);

	double dRange = ((*((double*)max)) - (*((double*)min))) / n;
	int res = ((dValue - dMin) / dRange);
	if (res > numBucks-1) res = numBucks-1;
	return res;


//	double dValue = *((double*)value);
//	double dMax = *((double*)max);
//	return ((numBuckets * dValue) / (dMax * 1.1));
}

/*
 * Inserts an input element in the linked list of the bucket.
 */
static void bucketsort_insert_in_bucket (struct LinkedList* buckets[],
										 const int index, void* element)
{
	struct LinkedList* list = NULL;
	if (buckets[index] == NULL) {
		// Create linked list
		list = linkedlist_create (NULL, NULL);
		buckets[index] = list;
	}
	else
		list = buckets[index];

	assert (list != NULL);
	if (linkedlist_push (list, element))
		return;
	else
	{
		fprintf (stderr, "Error: failed to insert element in linked list.");
		abort ();
	}
}

///*
// * Releases buckects linked lists.
// */
//static void bucketsort_freebuckets (struct LinkedList* buckets[], const int n)
//{
//	for (int i = 0; i < n; ++i) {
//		if (buckets[i] != NULL)
//			free (buckets[i]);
//	}
//}

/*
 * Function to sort an array or part of an array[from..to] using the bucket sort sorting
 * algorithm.
 * On each bucket input data will be stored in a linked list.
 * A custom function to compute the bucket index for insertion can be specified,
 * since this can impact to performance should be choosen carefully.
 * Any sort algorithm for linked lists can be used to sort the buckets, like
 * insertionsort, quicksort or mergesort for linked lists.
 */
void bucketsort_sort_impl (void* arr[], const int from, const int to,
						   SortCompareFunc comparefunc,
						   BucketsortCalcIndexFunc calcindexfunc,
						   SortLinkedListFunc sortfunc)
{
	// Create buckets array and initialize to NULL
	struct LinkedList* buckets[NUM_BUCKETS];
	for(int i = 0; i < NUM_BUCKETS; ++i) {
		buckets[i] = NULL;
	}

	// Get min/max input value
	int n = (to - from + 1);
	void* max;
	void* min;
	bucketsort_get_min_max(arr, from, to, &min, &max, comparefunc);

	//void* max = max (arr, from, to, comparefunc);

	// Fill buckets with input data
	for (int i = from; i < (to + 1); ++i) {
		// Calc bucket index
		int index = calcindexfunc (arr[i], min, max, n, NUM_BUCKETS);
//		int index = calcindexfunc (arr[i], max, NUM_BUCKETS);
		assert (index >= 0 && index < NUM_BUCKETS);
		bucketsort_insert_in_bucket (buckets, index, arr[i]);
	}

	// Sort buckects using 'sortfunc'
	for (int i = 0; i < NUM_BUCKETS; ++i) {
		if (buckets[i])
			sortfunc (buckets[i], comparefunc);
	}

	int j = from;	// Output index
	struct LinkedListNode* node;
	// Finally, concatenating the sorted buckets elements
	for (int b = 0; b < NUM_BUCKETS; ++b) {
		if (buckets[b] != NULL) {
			struct LinkedList* list = buckets[b];
			while (list->size > 0) {
				node = linkedlist_remove_first (list);
				arr[j++] = node->data;
				free (node);
			}

			linkedlist_destroy (list);
		}
	}
}

/*
 * Function to sort an array or part of an array[from..to] of ints using the bucket sort
 * sorting algorithm.
 * On each bucket input data will be stored in a linked list.
 * The linked lists will be sorted with Insertion sort sorting algorithm.
 * To specifie another sorting algorithm use function 'bucketsort_sort_impl ()'.
 */
void bucketsort_sort_ints (void* arr[], const int from, const int to,
						   SortCompareFunc comparefunc)
{
	bucketsort_sort_impl (arr, from, to, comparefunc,
						  bucketsort_int_compute_index, insertionsortll_sort);
}

/*
 * Function to sort an array or part of an array[from..to] of floats using the bucket sort
 * sorting algorithm.
 * On each bucket input data will be stored in a linked list.
 * The linked lists will be sorted with Insertion sort sorting algorithm.
 * To specifie another sorting algorithm use function 'bucketsort_sort_impl ()'.
 */
void bucketsort_sort_floats (void* arr[], const int from, const int to,
						     SortCompareFunc comparefunc)
{
	bucketsort_sort_impl (arr, from, to, comparefunc,
						  bucketsort_float_compute_index, insertionsortll_sort);
}

/*
 * Function to sort an array or part of an array[from..to] of doubles using the bucket sort
 * sorting algorithm.
 * On each bucket input data will be stored in a linked list.
 * The linked lists will be sorted with Insertion sort sorting algorithm.
 * To specifie another sorting algorithm use function 'bucketsort_sort_impl ()'.
 */
void bucketsort_sort_doubles (void* arr[], const int from, const int to,
						     SortCompareFunc comparefunc)
{
	bucketsort_sort_impl (arr, from, to, comparefunc,
						  bucketsort_double_compute_index, insertionsortll_sort);
}

