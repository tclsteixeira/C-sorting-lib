/*
 * radixsortmsd.c
 *
 *  Created on: 20/02/2024
 *      Author: Tiago C. Teixeira
 * Description: Implements the MSD Radixsort sorting algorithm.
 *
 *  Notes: The original aglgorithm fails to sort with repeated keys.
 *  	   So this is basically a recursive version of lsd implementation
 *  	   for non negative integers lists.
 *
 *
 * MSD Radix Sort: It starts sorting from the beginning of strings
 * 			  	   (the Most significant digit).
 *
 *
 * Approach:
 * 		The idea is to perform the following steps for each digit i where the
 * 		value of i varies from the most significant digit to the least significant
 * 		digit:
 *
 *    	- Store elements in different buckets according to their ith digit.
 *    	- Recursively sort each bucket that has more than one element.
 *
 *
 * MSD can be used to sort strings of variable length, unlike LSD. LSD has to be
 * stable in order to work correctly, but MSD can either be made stable or unstable
 * and MSD can work with random strings.
 *
 *
 * Time Complexity:
 *        LSD Radix sort: Best and Worst-Case time complexity is O(N*M) where
 *        M = length of the longest string.
 *        MSD Radix sort: Best Case time complexity is O(N) and the Worst-Case time
 *        complexity is O(N*M) where M = the average length of strings.
 *
 * Auxiliary Space:
 *        LSD Radix sort: O(N + B)
 *        MSD Radix sort: O(N + MB), where M = length of the longest string and
 *        B = size of radix (B=10 possible numbers or B=256 characters or B=2 for Binary).
 *    		  MSD uses recursion, so it requires more space than LSD. This means that
 *    		  MSD is much slower than LSD when working with a few inputs.
 *
 *
 * Advantages And Disadvantages of Radix Sort:
 *
 * Advantages:
 *
 *    - It is fast when the numbers are small If the numbers are small, the number
 *      of passes will also be small. So, it becomes more efficient.
 *    - It is a stable sorting algorithm, i.e., it maintains the relative order of
 *      elements with equal values.
 *    - It is used in many suffix array construction algorithms.
 *
 * Disadvantages:
 *
 *    - It will sometimes consume more memory than is required.
 *    - It is based on digits or letters, so it is less flexible as compared to
 *      other sorting algorithms as one needs to know the entire data priorly only.
 *
 *
 * Sources:
 * 		https://www.geeksforgeeks.org/msd-most-significant-digit-radix-sort/?ref=lbp
 * 		https://www.geeksforgeeks.org/radix-sort-vs-bucket-sort/?ref=lbp
 */

/* C program for the implementation
   of MSD Radix Sort using linked list
   Linked list node structure */

#include <stdio.h>
#include <stdlib.h> // For using malloc
#include <string.h> // For using memset

//// Linked list node declaration
//struct RadixsortMSDNode {
//    int arr_length;
//    struct RadixsortMSDNode* next[10];
//    int arr[];	// Original implementation used fixed array length arr[100]. Really bad choice.
//};

///*
// * Function to create a new node of the Linked List.
// */
//static struct RadixsortMSDNode* radixsortmsd_new_node (size_t numElements)
//{
//	size_t arrSize = sizeof (int) * numElements;
//    struct RadixsortMSDNode* tempNode
//        = (struct RadixsortMSDNode*)malloc (sizeof (struct RadixsortMSDNode) + arrSize);
//
//    tempNode->arr_length = 0;
//
//    for (int i = 0; i < 10; i++) {
//        tempNode->next[i] = NULL;
//    }
//
//    // Return the created node
//    return tempNode;
//}

/*
 * Function to calculate the MSD of the maximum value in the array.
 */
static int radixsortmsd_get_max_exp (int* arr, const int n)
{
    // Stores the maximum element
    int mx = arr[0];

    // Traverse the given array
    for (int i = 1; i < n; i++) {

        // Update the value of maximum
        if (arr[i] > mx) {
            mx = arr[i];
        }
    }

    int exp = 1;

    while (mx > 10) {
        mx /= 10;
        exp *= 10;
    }

    // Return the resultant value
    return exp;
}

/*
 * A recursive function to do counting sort of arr[] according to the digit represented by exp.
 *
 */
static void radixsortmsd_countsort_rec (int arr[], const int from, const int to, const int exp)
{
	if (exp <= 0)
		return;

	// Do counting sort for every digit recursively.
	radixsortmsd_countsort_rec (arr, from, to, exp / 10);

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
void radixsortmsd_sort_ints (int arr[], const int from, const int to)
{
	int n = (to - from + 1);

	// Find the optimal longest exponent
	int maxExp = radixsortmsd_get_max_exp (arr, n);

//    // Do counting sort for every digit.
//    // Note that instead of passing digit
//    // number, exp is passed. exp is 10^i
//    // where i is current digit number
//    for (int e = maxExp; e > 0; e /= 10)
    radixsortmsd_countsort_rec (arr, from, to, maxExp);
}


///*
// * Function to sort the given array
// * using MSD Radix Sort recursively.

// * Note: This algorithm fails to sort lists with repeated keys.
// */
//static void radixsortmsd_sort_rec (struct RadixsortMSDNode* root, int exp,
//								   int* sorted_arr, int* sorted_arr_length)
//{
//    if (exp <= 0) {
//        return;
//    }
//
//    int j;
//
//    // Stores the numbers in different
//    // buckets according their MSD
//    for (int i = 0; i < root->arr_length; i++) {
//
//        // Get the MSD in j
//        j = (root->arr[i] / exp) % 10;
//
//        // If j-th index in the node
//        // array is empty create and
//        // link a new node in index
//        if (root->next[j] == NULL) {
//            root->next[j] = radixsortmsd_new_node (root->arr_length);
//        }
//
//        // Store the number in j-th node
//        root->next[j]->arr[root->next[j]->arr_length] = root->arr[i];
//        root->next[j]->arr_length++;
//    }
//
//    // Sort again every child node that
//    // has more than one number
//    for (int i = 0; i < 10; i++) {
//
//        // If root->next is NULL
//        if (root->next[i] != NULL) {
//
//            if (root->next[i]->arr_length > 1) {
//
//                // Sort recursively
//            	radixsortmsd_sort_rec (root->next[i], exp / 10,
//                         sorted_arr, sorted_arr_length);
//            }
//
//            // If any node have only
//            // one number then it means
//            // the number is sorted
//            else {
//                sorted_arr[*sorted_arr_length]
//                    = root->next[i]->arr[0];
//                *sorted_arr_length += 1;
//            }
//        }
//    }
//}



///*
// * Releases linked list.
// */
//static void radixsortmsd_free_linked_list (struct RadixsortMSDNode* root)
//{
//	if (root == NULL) return;
//	for (int i = 0; i < 10; ++i) {
//		if (root->next[i] != NULL)
//			radixsortmsd_free_linked_list (root->next[i]);
//	}
//
//	free (root);
//}

///*
// * Recursive function to sort an array of integers using MSD Radixsort sorting
// * algorithm.
// * Note: A linked list is used to avoid wasting memory space.
// */
//void radixsortmsd_sort_ints (int arr[], const int from, const int to)
//{
//	// Number of elements to sort
//	int n = (to - from + 1);
//	struct RadixsortMSDNode* root = radixsortmsd_new_node (n);
//
//	// Stores the unsorted array
//	// in the root node and
//	// set arr_length
//	// Note: This is really bad if input array size is greater than root node fixed
//	//		 array size. This was the original implementation.
//	//
//	//		 Maybe an option is to alloc mem for array dinamically since we know the
//	// 		 size of input array to sort.
//	// 		 That's what i did.
//	memcpy (root->arr, (arr + from), sizeof (int) * n);
//	root->arr_length = n;
//
//	// Find the optimal longest exponent
//	int exp = radixsortmsd_get_max_exp (root->arr, root->arr_length);
//
//	// Stores the sorted numbers
//	int output[n];
//	int* sorted_arr = &output[0];
//	int sorted_arr_length = 0;	// Output array filled length
//
//	// Function Call
//	radixsortmsd_sort_rec (root, exp, sorted_arr, &sorted_arr_length);
//
//	// Copy sorted array to arr
//	for (int i = 0, j = from; i < n; ++i, ++j) {
//		arr[j] = sorted_arr[i];
//	}
//
//	// Free linked list
//	radixsortmsd_free_linked_list (root);
//}
