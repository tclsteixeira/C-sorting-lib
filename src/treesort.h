/*
 * treesort.h
 *
 *  Created on: 22/02/2024
 *      Author: Tiago C. Teixeira
 * Description: C headers for Treesort sorting algorithm using a common BST.
 */

#ifndef TREESORT_H_
	#define TREESORT_H_
	#include "sort.h"

	/*
	 * This function sorts arr[from..to] using Tree Sort
	 */
	void treesort_sort (void* arr[], const int from, const int to,
						SortCompareFunc comparefunc);

#endif /* TREESORT_H_ */
