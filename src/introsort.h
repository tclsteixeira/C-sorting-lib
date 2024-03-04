/*
 * introsort.h
 *
 *  Created on: 29/02/2024
 *      Author: Tiago C. Teixeira
 * Description: Implementation of introsort sorting algorithm.
 */

#ifndef INTROSORT_H_
	#define INTROSORT_H_

    #include "sort.h"

	/*
	 *  Implementation of introsort
	 **/
	void introsort_sort (void* arr[], int from, int to,
						 SortCompareFunc comparefunc);

#endif /* INTROSORT_H_ */
