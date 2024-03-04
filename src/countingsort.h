/*
 * countingsort.h
 *
 *  Created on: 11/02/2024
 *      Author: Tiago C. Teixeira
 * Description: C headers for the Countingsort sorting algorithm.
 */

#ifndef COUNTINGSORT_H_
	#define COUNTINGSORT_H_

	/*
	 * Function to sort array[from..to] with Counting sort algorithm with
	 * given min and max values.
	 */
	void countingsort_sort_in_place_mm (int arr[], const int from, const int to,
							   const int min, const int max);

	/*
	 * Function to sort array[from..to] with Counting sort algorithm.
	 */
	void countingsort_sort_in_place (int arr[], const int from, const int to);

	/*
	 * Counting sort function (not in place version)
	 * Sorts array elements at indexes [from..to].
	 * */
	int* countingsort_sort_mm (int arr[], const int n, const int from, const int to,
							   const int min, const int max);

	/*
	 * Counting sort function (not in place version)
	 * Sorts array elements at indexes [from..to].
	 * */
	int* countingsort_sort (int arr[], const int n, const int from, const int to);


#endif /* COUNTINGSORT_H_ */
