/*
 * radixsortmsd.h
 *
 *  Created on: 20/02/2024
 *      Author: Tiago C. Teixeira
 * Description: C headers for MSD Radixsort sorting algorithm.
 */

#ifndef RADIXSORTMSD_H_
	#define RADIXSORTMSD_H_

	/*
	 * Recursive function to sort an array of integers using MSD Radixsort sorting
	 * algorithm.
	 * Note: A linked list is used to avoid wasting memory space.
	 */
	void radixsortmsd_sort_ints (int arr[], const int from, const int to);

#endif /* RADIXSORTMSD_H_ */
