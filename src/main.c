/*
 * main.c
 *
 *  Created on: 18/03/2023
 *      Author: Tiago C. Teixeira
 *
 * Description: Demo sorting algs in C.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "quicksort.h"
#include "selectionsort.h"
#include "bubblesort.h"
#include "insertionsort.h"
#include "mergesort.h"
#include "heapsort.h"
#include "timsort.h"
#include "combsort.h"
#include "shellsort.h"
#include "countingsort.h"
#include "llsort.h"
#include "bubblesortll.h"
#include "insertionsortll.h"
#include "quicksortll.h"
#include "mergesortll.h"
#include "bucketsort.h"
#include "radixsortlsd.h"
#include "radixsortmsd.h"
#include "treesort.h"
#include "twayquicksort.h"
#include "introsort.h"

/*
 * Prints linked list of ints.
 * */
void print_int_linked_list (struct LinkedList* list) {
	if (!linkedlist_isempty (list)) {
		struct LinkedListNode* node = *(list->headp);
		for (int i = 0; i < list->size; ++i) {
			printf ("%d  ", *((int*)(node->data)) );
			node = node->next;
		}
	}
	else
		printf("List is empty.\n");

	printf("\n");
}

/*
 * Prints linked list of strings.
 * */
void print_string_linked_list (struct LinkedList* list) {
	if (!linkedlist_isempty (list)) {
		struct LinkedListNode* node = *(list->headp);
		for (int i = 0; i < list->size; ++i) {
			printf ("%s  ", (char*)(node->data) );
			node = node->next;
		}
	}
	else
		printf("List is empty.\n");

	printf("\n");
}

/*
 * Prints array of ints.
 * */
void printIntArray (int array[], int size) {
	for (int i = 0; i < size; ++i) {
		printf ("%d  ", array[i]);
	}

	printf("\n");
}

/*
 * Prints array of strings.
 * */
void printStrArray (void* array[], int size) {
	for (int i = 0; i < size; ++i) {
		printf("%s  ", (char*)array[i] );
	}

	printf("\n");
}

/*
 * Prints array of int pointers.
 * */
void printIntPArray (void* array[], int size) {
	for (int i = 0; i < size; ++i) {
		printf ("%d  ", *((int*)array[i]));
	}

	printf("\n");
}

/*
 * Prints array of float pointers.
 * */
void printFloatPArray (void* array[], int size) {
	for (int i = 0; i < size; ++i) {
		printf ("%f  ", *((float*)array[i]));
	}

	printf("\n");
}

/*
 * Prints array of float pointers.
 * */
void printDoublePArray (void* array[], int size) {
	for (int i = 0; i < size; ++i) {
		printf ("%f  ", *((double*)array[i]));
	}

	printf("\n");
}

/*
 * Compare ints function.
 * */
int compareInts (const void* a, const void* b) {
	if (*(int*)a < *(int*)b)
		return -1;
	else if (*(int*)a > *(int*)b)
		return 1;
	else
		return 0;
}

/*
 * Compare floats function.
 * */
int compareFloats (const void* a, const void* b) {
	if (*(float*)a < *(float*)b)
		return -1;
	else if (*(float*)a > *(float*)b)
		return 1;
	else
		return 0;
}

/*
 * Compare doubles function.
 * */
int compareDoubles (const void* a, const void* b) {
	if (*(double*)a < *(double*)b)
		return -1;
	else if (*(double*)a > *(double*)b)
		return 1;
	else
		return 0;
}

/*
 * Compare strings function.
 * */
int compareStrings (const void* a, const void* b) {
	return strcmp ((char*)a, (char*)b);
}

/*
 * Main function for linked lists sort algorithms.
 */
void do_sort_linked_list (const char* algName, SortLinkedListFunc sortfunc) {
	printf ("-- %s sort for linked list demo --\n\n", algName);

	int iArr[] = {2,  10, 24, 2,  10, 11, 27, 4,  2,  4,
        28, 16, 9,  8,  28, 10, 13, 24, 22, 28,
        0,  13, 27, 13, 3,  23, 18, 22, 8,  8 };
//	int iArr[] = {8, 7, 2, 1, 0, 2, 9, 6};
	int ni = sizeof(iArr) / sizeof(iArr[0]);

	struct LinkedList* iL = linkedlist_create (NULL, NULL);
	for (int i = 0; i < ni; ++i) {
		linkedlist_append (iL, &iArr[i]);
	}

	char* sArr[] = {"gfd", "asd", "aab", "aaa", "gdd", "ded", "aab", "ewe"};
	int ns = sizeof(sArr) / sizeof(sArr[0]);

	struct LinkedList* sL = linkedlist_create (NULL, NULL);
	for (int i = 0; i < ns; ++i) {
		linkedlist_push (sL, sArr[i]);
	}

	printf ("Int list header data points to '%d'\n", *((int*)(*(iL->headp))->data) );
	printf ("Int list tail points to '%d'\n\n", *((int*)(*(iL->tailp))->data) );

	printf ("Unsorted linked lists of ints and strings:\n");
	print_int_linked_list (iL);
	print_string_linked_list (sL);

	// Perform quicksort on data
	printf ("\nPerform %s sort on linked lists...\n", algName);
	sortfunc (iL, compareInts);
	sortfunc (sL, compareStrings);

	printf ("\nSorted linked lists in ascending order: \n");
	print_int_linked_list (iL);
	print_string_linked_list (sL);

	printf("\n");
	printf ("Int list header data points to '%d'\n", *((int*)(*(iL->headp))->data) );
	printf ("Int list tail points to '%d'\n", *((int*)(*(iL->tailp))->data) );

	// Destroy lists
	linkedlist_destroy (iL);
	linkedlist_destroy (sL);
}

/*
 * Main function for array sort algorithms.
 */
void do_sort (const char* algName, SortArrayFunc sortfunc) {
	printf ("-- %s sort demo --\n\n", algName);

	int iArr[] = { 2,  10, 24, 2,  10, 11, 27, 4,  2,  4,
            28, 16, 9,  8,  28, 10, 13, 24, 22, 28,
            0,  13, 27, 13, 3,  23, 18, 22, 8,  8 };

			//{8, 7, 2, 1, 0, 9, 6, 2};
	int ni = sizeof(iArr) / sizeof(iArr[0]);

	char* sArr[] = {"gfd", "asd", "aab", "aaa", "gdd", "ded", "ewe", "aab"};
	int ns = sizeof(sArr) / sizeof(sArr[0]);

	// Ints list as void pointers
	void* ip[ni];
	for (int i = 0; i < ni; ++i) {
		ip[i] = &iArr[i];
	}

	// Strings list as void pointers
	void* sp[ns];
	for (int i = 0; i < ns; ++i) {
		sp[i] = sArr[i];
	}

	printf ("Unsorted lists of ints and strings:\n");
	printIntPArray (ip, ni);
	printStrArray (sp, ns);

	// Perform quicksort on data
	printf ("\nPerform %s sort on lists...\n", algName);
	sortfunc (ip, 0, ni-1, compareInts);
	sortfunc (sp, 0, ns-1, compareStrings);

	printf ("\nSorted lists in ascending order: \n");
	printIntPArray (ip, ni);
	printStrArray (sp, ns);
}

/*
 * Main function for array sort counting algorithm.
 */
void do_counting_sort_in_place (const char* algName,
								CountingSortArrayFuncInPlace sortfunc) {
	printf ("-- %s sort demo --\n\n", algName);

	int iArr[] = {8, 7, 2, 1, 0, 2, 9, 6};
	int n = sizeof(iArr) / sizeof(iArr[0]);

	printf ("Unsorted lists of ints and strings:\n");
	printIntArray (iArr, n);

	// Perform quicksort on data
	printf ("\nPerform %s sort on list...\n", algName);
	sortfunc (iArr, 0, n-1);

	printf ("\nSorted lists in ascending order: \n");
	printIntArray (iArr, n);
}

/*
 * Main function for array sort counting algorithm.
 */
void do_counting_sort (const char* algName, CountingSortArrayFunc sortfunc) {
	printf ("-- %s sort demo --\n\n", algName);

	int iArr[] = {8, 7, 2, 1, 0, 2, 9, 6};
	int n = sizeof(iArr) / sizeof(iArr[0]);

	printf ("Unsorted lists of ints and strings:\n");
	printIntArray (iArr, n);

	// Perform quicksort on data
	printf ("\nPerform %s sort on list...\n", algName);
	int* out = sortfunc (iArr, n, 0, n-1);

	printf ("\nSorted lists in ascending order: \n");
	printIntArray (out, n);
	free (out);
}

/*
 * Main function for array sort Radixsort algorithm.
 */
void do_radix_sort_in_place (const char* algName,
							 RadixSortArrayFuncInPlace sortfunc) {
	printf ("-- %s sort for instegers demo --\n\n", algName);

	int iArr[] = {834, 73, 232, 1, 0, 921, 1, 623};
	int n = sizeof(iArr) / sizeof(iArr[0]);

	printf ("Unsorted lists of integers:\n");
	printIntArray (iArr, n);

	// Perform sort on data
	printf ("\nPerform %s sort on list...\n", algName);
	sortfunc (iArr, 0, n-1);

	printf ("\nSorted list in ascending order: \n");
	printIntArray (iArr, n);
}

/*
 * Main function to sort array using Bucketsort algorithm.
 */
void do_bucketsort_sort (const char* algName, SortArrayFunc sortintsfunc,
						 SortArrayFunc sortfloatsfunc,
						 SortArrayFunc sortdoublesfunc)
{
	printf ("-- %s sort demo --\n\n", algName);

	// Samples for int, float and double input
	int iArr[] = {8, 7, -2, 1, 0, 9, 1, 6};
	float fArr[] = {0.8, 0.7, -0.22, 0.12, 0.11, 0.12, 0.91, 0.6};
	double dArr[] = {0.08, 0.7123, 0.245, 0.881, -0.5511, 0.881, 0.9121, 0.0006};
	int n = sizeof(iArr) / sizeof(iArr[0]);

	// Fill void* arrays with input values for sorting
	void* ipArr[n]; void* fpArr[n]; void* dpArr[n];
	for (int i = 0; i < n; ++i) {
		ipArr[i] = &iArr[i]; fpArr[i] = &fArr[i]; dpArr[i] = &dArr[i];
	}

	printf ("Unsorted lists of ints, floats and doubles:\n");
	printIntPArray (ipArr, n);
	printFloatPArray (fpArr, n);
	printDoublePArray (dpArr, n);

	// Perform quicksort on data
	printf ("\nPerform %s sort on list...\n", algName);
	sortintsfunc (ipArr, 0, n-1, compareInts);
	sortfloatsfunc (fpArr, 0, n-1, compareFloats);
	sortdoublesfunc (dpArr, 0, n-1, compareDoubles);

	printf ("\nSorted lists in ascending order: \n");
	printIntPArray (ipArr, n);
	printFloatPArray (fpArr, n);
	printDoublePArray (dpArr, n);
}

/*
 * Selection sort demo for array of ints and strings.
 * */
void selectionsort_demo() {
	do_sort ("Selection", selectionsort_sort);
}

/*
 * Selection sort min/max version demo for array of ints and strings.
 * */
void selectionsort_min_max_demo() {
	do_sort ("Selection min/max", selectionsort_min_max_sort);
}

/*
 * Bubble sort demo for array of ints and strings.
 * */
void bubblesort_demo() {
	do_sort ("Bubble", bubblesort_sort);
}

/*
 * Comb sort demo for array of ints and strings.
 * */
void combsort_demo() {
	do_sort ("Comb", combsort_sort);
}

/*
 * Insertion sort demo for array of ints and strings.
 * */
void insertionsort_demo() {
	do_sort ("Insertion", insertionsort_sort);
}

/*
 * Shell sort demo for array of ints and strings.
 * */
void shellsort_demo() {
	do_sort ("Shell", shellsort_sort);
}

/*
 * Merge sort demo for array of ints and strings.
 * */
void mergesort_demo() {
	do_sort ("Merge", mergesort_sort);
}

/*
 * Heap sort demo for array of ints and strings.
 * */
void heapsort_demo() {
	do_sort ("Heap", heapsort_sort);
}

/*
 * Tim sort demo for array of ints and strings.
 * */
void timsort_demo() {
	do_sort ("Tim", timsort_sort);
}

/*
 * Quicksort demo for array of ints and strings.
 * */
void quicksort_demo() {
	do_sort ("Quicksort", quicksort_sort);
}

/*
 * Countingsort demo for array of ints.
 * */
void countingsort_demo() {
	do_counting_sort_in_place ("Countingsort in place", countingsort_sort_in_place);
	printf ("\n\n");
	do_counting_sort ("Counting", countingsort_sort);
}

/*
 * 3-way quicksort demo.
 * This algorithm is a Quicksort adaptation for better performance with inputs
 * with lot of repeated keys.
 */
void twayquicksort_demo() {
	do_sort ("3-Way Quicksort", twayquicksort_sort);
}

/*
 * Bucket sort function demo of ints, floats and doubles.
 * */
void bucketsort_demo() {
	do_bucketsort_sort ("Bucketsort", bucketsort_sort_ints,
								  	  bucketsort_sort_floats,
									  bucketsort_sort_doubles);
}

/*
 * LSD Radix sort function demo of integers.
 * */
void radixsortlsd_demo() {
	do_radix_sort_in_place ("LSD Radixsort", radixsortlsd_sort_ints);
}

/*
 * MSD Radix sort function demo of integers.
 * */
void radixsortmsd_demo() {
	do_radix_sort_in_place ("MSD Radixsort", radixsortmsd_sort_ints);
}

/*
 * Tree sort function demo for integers and strings.
 * */
void treesort_demo() {
	do_sort ("Treesort", treesort_sort);
}

/*
 * Intro sort function demo for integers and strings.
 * */
void introsort_demo() {
	do_sort ("Introsort", introsort_sort);
}



/*
 * Linked lists section
 */

/*
 * Bubblesort demo for linked lists of ints and strings.
 * */
void llbubblesort_demo() {
	do_sort_linked_list ("Bubble", bubblesortll_sort);
}

/*
 * Insertion sort demo for linked lists of ints and strings.
 * */
void llinsertionsort_demo() {
	do_sort_linked_list ("Insertion", insertionsortll_sort);
}

/*
 * Quick sort demo for linked lists of ints and strings.
 * */
void llquicksort_demo() {
	do_sort_linked_list ("Quick", quicksortll_sort);
}

/*
 * Merge sort with recursive merge function demo for linked lists of ints and strings.
 * */
void llmergesort_demo() {
	do_sort_linked_list ("Merge", mergesortll_sort);
}

/*
 * Merge sort with iterative merge function demo for linked lists of ints and strings.
 * */
void llmergesortitermerge_demo() {
	do_sort_linked_list ("Iterative merge", mergesortll_sort_with_it_merge);
}

int main() {
	selectionsort_demo ();
	printf("\n\n");
	selectionsort_min_max_demo ();
	printf("\n\n");
	bubblesort_demo ();
	printf("\n\n");
	combsort_demo ();
	printf("\n\n");
	insertionsort_demo ();
	printf("\n\n");
	shellsort_demo ();
	printf("\n\n");
	mergesort_demo ();
	printf("\n\n");
	heapsort_demo ();
	printf("\n\n");
	timsort_demo ();
	printf("\n\n");
	quicksort_demo ();
	printf("\n\n");
	countingsort_demo ();
	printf("\n\n");
	bucketsort_demo ();
	printf ("\n\n");
	radixsortlsd_demo ();
	printf ("\n\n");
	radixsortmsd_demo ();
	printf ("\n\n");
	treesort_demo ();
	printf ("\n\n");
	twayquicksort_demo ();
	printf ("\n\n");
	introsort_demo ();

	printf("\n\n\n");
	printf ("------------------------------\n");
	printf ("---- Linked lists sorting ----\n");
	printf ("------------------------------\n\n");

	llbubblesort_demo ();
	printf("\n\n");
	llinsertionsort_demo ();
	printf("\n\n");
	llquicksort_demo ();
	printf("\n\n");
	llmergesort_demo ();
	printf("\n\n");
	llmergesortitermerge_demo ();

	return EXIT_SUCCESS;
}

