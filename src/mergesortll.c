/*
 * mergesortll.c
 *
 *  Created on: 14/02/2024
 *      Author: Tiago C. Teixeira
 * Description: Implements the Mergesort sorting algorithm for single linked lists.
 *
 *
 * Algorithm:
 *
 * Let the head be the first node of the linked list to be sorted and headRef be the
 * pointer to head. Note that we need a reference to head in MergeSort() as the below
 * implementation changes next links to sort the linked lists (not data at the nodes),
 * so the head node has to be changed if the data at the original head is not the
 * smallest value in the linked list.
 *
 *    MergeSort (headRef)
 *        - If the head is NULL or there is only one element in the Linked List, then
 *        return.
 *        - Else divide the linked list into two halves.
 *           - FrontBackSplit(head, &a, &b); // a and b are two halves
 *        - Sort the two halves a and b.
 *            - MergeSort(a);
 *            - MergeSort(b);
 *        - Merge the sorted a and b (using SortedMerge() discussed here) and update
 *        the head pointer using headRef.
 *            *headRef = SortedMerge(a, b);
 *
 *
 * Time complexity: O(n log n)
 * Auxiliary Space: O(1)
 *
 *
 * Source: https://www.geeksforgeeks.org/sorting-a-singly-linked-list/?ref=header_search
 *
 */

#include "sort.h"
#include "llsort.h"
#include "linkedlist.h"
#include <assert.h>

// Declares merge function prototype that joins two sorted linked lists.
typedef struct LinkedListNode* (*MergeSortllMergeFunc) (struct LinkedListNode* a,
		 	 	 	 	  	  	  	  struct LinkedListNode* b,
									  SortCompareFunc comparefunc);

/*
 * The idea is to move ahead with node in the recursion whose node value is lesser.
 * When any of the node reach the end then append the rest of the linked List.
 *
 * Steps:
 *   - Make a function where two pointers pointing to the linked list will be passed.
 *   - Now, check which value is less from both the current nodes.
 *   - The one with less value makes a recursion call by moving ahead with that pointer
 *   	and simultaneously append that recursion call with the node
 *   - Also put two base cases to check whether one of the linked lists will reach
 *   	the NULL, then append the rest of the linked list.
 *
 *
 * Time Complexity: O(M + N), Where M and N are the size of the list1 and
 * 							  list2 respectively.
 * Auxiliary Space: O(M+N), Function call stack space.
 *
 * See https:// www.geeksforgeeks.org/?p=3622 for details of this function
 */
static struct LinkedListNode* mergesortll_sorted_merge (
									 struct LinkedListNode* a,
									 struct LinkedListNode* b,
									 SortCompareFunc comparefunc)
{
    struct LinkedListNode* result = NULL;

    /* Base cases */
    if (a == NULL)
        return (b);
    else if (b == NULL)
        return (a);

    /* Pick either a or b, and recur */
    if (!(comparefunc (a->data, b->data) > 0)) {
        result = a;
        result->next = mergesortll_sorted_merge (a->next, b, comparefunc);
    }
    else {
        result = b;
        result->next = mergesortll_sorted_merge (a, b->next, comparefunc);
    }

    return result;
}

/*
 * Merge two sorted linked lists using Dummy Nodes
 * Iteractive (non-recursive version) of function to join two sorted linked lists.
 *
 * The idea is to use a temporary dummy node as the start of the result list. The
 * pointer Tail always points to the last node in the result list, so appending new
 * nodes is easy.
 *
 * Algorithm steps:
 *
 * 		- First, make a dummy node for the new merged linked list.
 *   	- Now make two pointers, one will point to list1 and another will point to list2.
 *   	- Now traverse the lists till one of them gets exhausted.
 *   	- If the value of the node pointing to either list is smaller than another
 *   		pointer, add that node to our merged list and increment that pointer.
 *
 *
 * Time Complexity: O(N+M), where N and M are the size of list1 and list2 respectively.
 * Auxiliary Space: O(1)
 *
 */

/* UTILITY FUNCTION FOR ITERACTIVE MERGING VERSION OF TWO SORTED LINKED LISTS
 *  				mergesortll_sorted_merge_iter (..)
 * */

/* move_node() function takes the node from the front of the
 * source, and move it to the front of the dest.
 * It is an error to call this with the source list empty.
 *
 *  Before calling MoveNode():
 *  source == {1, 2, 3}
 *  dest == {1, 2, 3}
 *
 *  After calling MoveNode():
 *  source == {2, 3}
 *  dest == {1, 1, 2, 3}
 **/
static void mergesortll_move_node (struct LinkedListNode** destRef,
              	  	  	  	  	   struct LinkedListNode** sourceRef)
{
    /* the front source node  */
    struct LinkedListNode* newNode = *sourceRef;
    assert (newNode != NULL);

    /* Advance the source pointer */
    *sourceRef = newNode->next;

    /* Link the old dest of the new node */
    newNode->next = *destRef;

    /* Move dest to point to the new node */
    *destRef = newNode;
}

/*
 * Iteractive version of function to merge two sorted linked lists.
 * (since there are no recursion the space complexity is O(1))
 *
 * Takes two lists sorted in increasing order, and splices
 * their nodes together to make one big sorted list which
 * is returned.
 **/
struct LinkedListNode* mergesortll_sorted_merge_iter (struct LinkedListNode* a,
													  struct LinkedListNode* b,
													  SortCompareFunc comparefunc)
{
    /* a dummy first node to hang the result on */
    struct LinkedListNode dummy;	// Stack var

    /* tail points to the last result node  */
    struct LinkedListNode* tail = &dummy;

    /* so tail->next is the place to add new nodes
      to the result. */
    dummy.next = NULL;
    while (1) {
        if (a == NULL) {
            /* if either list runs out, use the
               other list */
            tail->next = b;
            break;
        }
        else if (b == NULL) {
            tail->next = a;
            break;
        }

        if (!(comparefunc (a->data, b->data) > 0))	//(  a->data <= b->data)
            mergesortll_move_node (&(tail->next), &a);	// 'a' also advances to next node
        else
        	mergesortll_move_node (&(tail->next), &b);	// 'b' also advances to next node

        tail = tail->next;	// Move to next insert position
    }

    return (dummy.next);
}

/* UTILITY FUNCTIONS */
/* Split the nodes of the given list into front and back
   halves, and return the two lists using the reference
   parameters. If the length is odd, the extra node should
   go in the front list. Uses the fast/slow pointer
   strategy. */
static void mergesortll_frontback_split (struct LinkedListNode* source,
                    struct LinkedListNode** frontRef,
                    struct LinkedListNode** backRef)
{
    struct LinkedListNode* fast;
    struct LinkedListNode* slow;
    slow = source;
    fast = source->next;

    /* Advance 'fast' two nodes, and advance 'slow' one node
     */
    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    /* 'slow' is before the midpoint in the list, so split
    it in two at that point. */
    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
}

/*
 * UTILITY FUNCTIONS
 *
 * Fixes the tail reference pointer of a sorted linked list.
 */
static void mergesortll_fix_tailref (struct LinkedList* list)
{
	if (!linkedlist_isempty (list)) {
		// Fix tail pointer
		struct LinkedListNode* node = *list->tailp;
		assert (node != NULL);

		if (node->next) {
			while (node->next) {
				node = node->next;
			}

			*list->tailp = node;
		}
	}
}

/*
 * Sorts the linked list using a recursive merge sort algorithm by changing
 * next pointers (not data).
 * Allows to use a custom merge function.
 * If list as no tail ref pointer leave 'tailref' arg with 'NULL'.
 * */
void mergesortll_mergesort (struct LinkedListNode** headRef,
							SortCompareFunc comparefunc,
							MergeSortllMergeFunc mergefunc)
{
    struct LinkedListNode* head = *headRef;
    struct LinkedListNode* a;
    struct LinkedListNode* b;

    /* Base case -- length 0 or 1 */
    if ((head == NULL) || (head->next == NULL)) {
        return;
    }

    /*
     * Split head into 'a' and 'b' sublists.
     * Note: 'a' and 'b' are outupt args.
     * */
    mergesortll_frontback_split (head, &a, &b);

    /* Recursively sort the sublists */
    mergesortll_mergesort (&a, comparefunc, mergefunc);
    mergesortll_mergesort (&b, comparefunc, mergefunc);

    /* answer = merge the two sorted lists together */
    *headRef = mergefunc (a, b, comparefunc);
}

/*
 * Sorts the linked list using merge sort algorithm by changing
 * next pointers (not data).
 * Note: Uses recursive function version to merge two sorted linked lists.
 * */
void mergesortll_sort (struct LinkedList* list, SortCompareFunc comparefunc)
{
	mergesortll_mergesort (list->headp, comparefunc, mergesortll_sorted_merge);

	// Fix tail ref
	mergesortll_fix_tailref (list);
}

/*
 * Sorts the linked list using merge sort algorithm by changing
 * next pointers (not data).
 * Note: Uses iterative function version to merge two sorted linked lists.
 * */
void mergesortll_sort_with_it_merge (struct LinkedList* list, SortCompareFunc comparefunc)
{
	mergesortll_mergesort (list->headp, comparefunc, mergesortll_sorted_merge_iter);

	// Fix tail ref
	mergesortll_fix_tailref (list);
}
