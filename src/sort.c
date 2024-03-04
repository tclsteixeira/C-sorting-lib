/*
 * sort.c
 *
 *  Created on: 05/02/2024
 *      Author: Tiago C. Teixeira
 * Description: Implements utility functions for sorting algorithms.
 *
 */

/*
 * Swaps arguments a and b.
 */
void sort_swap (void** a, void** b) {
	void* t = *a;
	*a = *b;
	*b = t;
}


