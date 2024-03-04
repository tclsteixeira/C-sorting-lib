/*
 * heapsort.c
 *
 *  Created on: 06/02/2024
 *      Author: Tiago C. Teixeira
 * Description: Implements the heap sort algorithm.
 *
 *
 * Algorithm:
 *
 *    First convert the array into heap data structure using heapify, then one by one
 *    delete the root node of the Max-heap and replace it with the last node in the
 *    heap and then heapify the root of the heap. Repeat this process until size of
 *    heap is greater than 1.
 *
 *    - Build a heap from the given input array.
 *      - Repeat the following steps until the heap contains only one element:
 *         - Swap the root element of the heap (which is the largest element) with the
 *           last element of the heap.
 *         - Remove the last element of the heap (which is now in the correct position).
 *         - Heapify the remaining elements of the heap.
 *      - The sorted array is obtained by reversing the order of the elements in the
 *        input array.
 *
 *
 * Complexity Analysis of Heap Sort
 *
 * Time Complexity: O(N log N)
 * Auxiliary Space: O(log n), due to the recursive call stack. However, auxiliary space
 * 					can be O(1) for iterative implementation.
 *
 *
 * Important points about Heap Sort:
 *
 *    Heap sort is an in-place algorithm.
 *    Its typical implementation is not stable but can be made stable.
 *    Typically 2-3 times slower than well-implemented QuickSort. The reason for
 *    slowness is a lack of locality of reference.
 *
 *
 * Advantages of Heap Sort:
 *
 *    Efficient Time Complexity - Heap Sort has a time complexity of O(n log n) in all
 *    	cases. This makes it efficient for sorting large datasets. The log n factor
 *    	comes from the height of the binary heap, and it ensures that the algorithm
 *    	maintains good performance even with a large number of elements.
 *
 *    Memory Usage – Memory usage can be minimal because apart from what is necessary
 *    	to hold the initial list of items to be sorted, it needs no additional memory
 *    	space to work
 *
 *    Simplicity – It is simpler to understand than other equally efficient sorting
 *    	algorithms because it does not use advanced computer science concepts such as
 *    	recursion.
 *
 *
 * Disadvantages of Heap Sort:
 *
 *    Costly: Heap sort is costly.
 *    Unstable: Heap sort is unstable. It might rearrange the relative order.
 *    Efficient: Heap Sort is not very efficient when working with highly complex data.
 *
 *
 *
 * FAZER VERSÃO ITERACTIVA
 *
 *
 */

#include <stdlib.h>
#include "sort.h"

/*
 * Function build Max Heap where value of each child is always smaller
 * than value of their parent.
 * Note: 'from' and 'to' are inclusive array bounds.
 */
static void heapsort_build_max_heap (void* arr[], const int from, const int to,
									 SortCompareFunc comparefunc)
{
    for (int i = from+1; i < (to+1); i++)
    {
        // if child is bigger than parent
    	// Note: parent of i is (i-1) / 2
        if (comparefunc (arr[i], arr[(i - 1) / 2]) > 0)
        {
        	int j = i;

            // swap child and parent until
            // parent is smaller
            while (comparefunc (arr[j], arr[(j - 1) / 2]) > 0)	//(arr[j] > arr[(j - 1) / 2])
            {
            	sort_swap (&arr[j], &arr[(j-1)/2]);
                j = (j - 1) / 2;
            }
        }
    }
}

/*
 * Sorts an array or part of an array using heap sort algorithm (iteractiva version).
 * 'from' and 'to' are inclusive array bounds to sort.
 * Time:  O(N log(N))
 * Space: O(1) (iteractive version)
 */
void heapsort_sort (void* arr[], int from, int to, SortCompareFunc comparefunc)
{
    heapsort_build_max_heap (arr, from, to, comparefunc);

    for (int i = to; i > from; i--)
    {
        // Swap value of first indexed
        // with last indexed
    	sort_swap (&arr[from], &arr[i]);

        // maintaining heap property
        // after each swapping
    	int j = from;
    	int index = 0;
        do
        {
        	// Note: left child of j is 2 * j + 1
            index = (2 * j + 1);

            // If left child is smaller than right child,
            // point index variable to right child
            if (index < (i - 1) &&
            		(comparefunc (arr[index], arr[index + 1]) < 0))
            	index++;

            // if parent is smaller than child
            // then swapping parent with child
            // having higher value
            if ((index < i) && (comparefunc (arr[j], arr[index]) < 0))
            	sort_swap (&arr[j], &arr[index]);

            j = index;

        } while (index < i);
    }
}


