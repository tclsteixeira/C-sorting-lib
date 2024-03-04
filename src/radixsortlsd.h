/*
 * radixsort.h
 *
 *  Created on: 20/02/2024
 *      Author: Tiago C. Teixeira
 * Description: C headers for LSD Radixsort sorting algorithm.
 *
 *  Note: This LSD radix sort implementation only works for non negative integers.
 *
 */

#ifndef RADIXSORTLSD_H_
	#define RADIXSORTLSD_H_

	/*
	 * The main function to sort array or part of an array of integers
	 * arr[from..to] using LSD Radix Sort algorithm.
	 */
	void radixsortlsd_sort_ints (int arr[], const int from, const int to);

#endif /* RADIXSORTLSD_H_ */
