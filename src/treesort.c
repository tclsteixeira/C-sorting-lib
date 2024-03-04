/*
 * treesort.c
 *
 *  Created on: 22/02/2024
 *      Author: Tiago C. Teixeira
 * Description: Implements the Treesort sorting algorithm.
 *
 *
 * Note: In this implementation it will be used a Binary Search Tree for
 * 		 simplicity. To improve performance a self-balanced binary tree should be used.
 *
 *
 * About:
 *
 *    Tree sort is a sorting algorithm that is based on Binary Search Tree data
 *    structure. It first creates a binary search tree from the elements of the
 *    input list or array and then performs an in-order traversal on the created
 *    binary search tree to get the elements in sorted order.
 *
 *
 * Algorithm:
 *
 *    Step 1: Take the elements input in an array.
 *    Step 2: Create a Binary search tree by inserting data items from the array
 *    		  into the binary search tree.
 *    Step 3: Perform in-order traversal on the tree to get the elements in sorted
 *    		  order.
 *
 *
 * Complexity Analysis:
 *
 *    Average Case Time Complexity:
 *    	O(n log n) Adding one item to a Binary Search tree on average takes O(log n)
 *    	time. Therefore, adding n items will take O(n log n) time.
 *
 * 	  Worst Case Time Complexity:
 * 	    O(n^2). The worst case time complexity of Tree Sort can be improved by using
 * 	    a self-balancing binary search tree like Red Black Tree, AVL Tree.
 * 	    Using self-balancing binary tree Tree Sort will take O(n log n) time to
 * 	    sort the array in worst case.
 *
 *
 * Auxiliary Space: O(n)
 *
 *
 * Applications of Tree sort:
 *
 *    Its most common use is to edit the elements online: after each installation,
 *    a set of objects seen so far is available in a structured program.
 *    If you use a splay tree as a binary search tree, the resulting algorithm
 *    (called splaysort) has an additional property that it is an adaptive sort,
 *    which means its working time is faster than O (n log n) for virtual inputs.
 *
 */

#include <stdlib.h>
#include "sort.h"

struct TreesortNode
{
    void* key;
    struct TreesortNode* left;
    struct TreesortNode* right;
};

/*
 * A utility function to create a new BST Node.
 */
static struct TreesortNode* treesort_new_node (void* item)
{
    struct TreesortNode* temp = (struct TreesortNode*)malloc (sizeof (*temp));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

/*
 * Stores inorder traversal of the BST in arr[].
 */
static void treesort_store_sorted (struct TreesortNode* root, void* arr[], int* i)
{
    if (root != NULL)
    {
    	treesort_store_sorted (root->left, arr, i);
        arr[(*i)++] = root->key;
        treesort_store_sorted (root->right, arr, i);
    }
}

/*
 * A utility function to insert a new
 * Node with given key in BST.
 */
static struct TreesortNode* treesort_insert (struct TreesortNode* node, void* key,
							 	 	  	     SortCompareFunc comparefunc)
{
    /* If the tree is empty, return a new Node */
    if (node == NULL) return treesort_new_node (key);

    /* Otherwise, recur down the tree */
    if (comparefunc (node->key, key) > 0) // key < node->key)
        node->left  = treesort_insert (node->left, key, comparefunc);
    else if (comparefunc (key, node->key) > 0)
        node->right = treesort_insert (node->right, key, comparefunc);
    else	// Repeatd key - Insert left is the rule
    	node->left  = treesort_insert (node->left, key, comparefunc);

    /* return the (unchanged) Node pointer */
    return node;
}

/*
 * Releases the tree nodes from memory.
 */
static void treesort_destroy_bst (struct TreesortNode* root)
{
	if (root != NULL) {
		treesort_destroy_bst (root->left);
		treesort_destroy_bst (root->right);
		free (root);
	}
}

/*
 * This function sorts arr[from..to] using Tree Sort
 */
void treesort_sort (void* arr[], const int from, const int to,
					SortCompareFunc comparefunc)
{
    struct TreesortNode* root = NULL;

    // Construct the BST
    root = treesort_insert (root, arr[from], comparefunc);
    for (int i=from+1; i<(to+1); i++)
        root = treesort_insert (root, arr[i], comparefunc);

    // Store inorder traversal of the BST in arr[]
    int i = from;
    treesort_store_sorted (root, arr, &i);

    // Free BST
    treesort_destroy_bst (root);
}
