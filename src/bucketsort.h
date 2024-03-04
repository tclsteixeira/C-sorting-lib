/*
 * bucketsort.h
 *
 *  Created on: 16/02/2024
 *      Author: Tiago C. Teixeira
 * Description: C headers for Bucketsort sorting algorithm.
 */

#ifndef BUCKETSORT_H_
	#define BUCKETSORT_H_

	#include "sort.h"
	#include "llsort.h"

	typedef int (*BucketsortCalcIndexFunc)(void* value, void* min, void* max,
										   const int n, const int numBucks);

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
							   SortLinkedListFunc sortfunc);

	/*
	 * Function to sort an array or part of an array[from..to] of ints using the bucket sort
	 * sorting algorithm.
	 * On each bucket input data will be stored in a linked list.
	 * The linked lists will be sorted with Insertion sort sorting algorithm.
	 * To specifie another sorting algorithm use function 'bucketsort_sort_impl ()'.
	 */
	void bucketsort_sort_ints (void* arr[], const int from, const int to,
							   SortCompareFunc comparefunc);

	/*
	 * Function to sort an array or part of an array[from..to] of floats using the bucket sort
	 * sorting algorithm.
	 * On each bucket input data will be stored in a linked list.
	 * The linked lists will be sorted with Insertion sort sorting algorithm.
	 * To specifie another sorting algorithm use function 'bucketsort_sort_impl ()'.
	 */
	void bucketsort_sort_floats (void* arr[], const int from, const int to,
							     SortCompareFunc comparefunc);

	/*
	 * Function to sort an array or part of an array[from..to] of doubles using the bucket sort
	 * sorting algorithm.
	 * On each bucket input data will be stored in a linked list.
	 * The linked lists will be sorted with Insertion sort sorting algorithm.
	 * To specifie another sorting algorithm use function 'bucketsort_sort_impl ()'.
	 */
	void bucketsort_sort_doubles (void* arr[], const int from, const int to,
							      SortCompareFunc comparefunc);

#endif /* BUCKETSORT_H_ */
