/*
 * radixsortstr.c
 *
 *  Created on: 21/02/2024
 *      Author: Tiago C. Teixeira
 * Description: Implements the Radixsort sorting algorithm for strings.
 *
 * _________________This is a bad implementation
 *
 * About:
 *
 *		This implementation is for the strings based on the counting sort() method.
 *		As C style ASCII character is 1 byte. So, the 256 size array is used to count
 *		occurrences of characters, and it sorts the strings lexicographically.
 *
 *
 * Adapted from:
 * 		https://www.geeksforgeeks.org/msd-most-significant-digit-radix-sort/?ref=lbp
 */
//
///*
// * C program for the implementation
// * of MSD Radix Sort for strings in lexicographical order using counting sort()
// */
//#include <stdio.h>
//#include <string.h>
//
///*
// * A utility function to get the ASCII value
// * of the character at index d in a string.
// */
//int radixsortstr_char_at (char* str, int d)
//{
//    if (sizeof(str) / sizeof(str[0]) <= d)
//        return -1;
//    else
//        return str[d];
//}
//
///*
// * The main function to sort strings array using
// * MSD Radix Sort recursively.
// */
//void radixsortstr_msd_sort (char** str, int lo, int hi, int d, const int n)
//{
//    // Recursion break condition
//    if (hi <= lo + 1) {
//        return;
//    }
//
//    // Each character is one byte (0..255)
//    int count[256 + 2] = { 0 };
//
//    // Temp is created to easily swap strings in str[]
//    char temp[n][100];
//
//    // Store occurrences of most significant character
//    // from each string in count[]
//    for (int i = lo; i <= hi; i++) {
//        int c = radixsortstr_char_at (str[i], d);
//        count++;
//    }
//
//    // Change count[] so that count[] now contains actual
//    //  position of this digits in temp[]
//    for (int r = 0; r < 256 + 1; r++)
//        count[r + 1] += count[r];
//
//    // Build the temp
//    for (int i = lo; i <= hi; i++) {
//        int c = radixsortstr_char_at (str[i], d);
//        memcpy (temp[count++], str[i],
//                strlen(str[i]) + 1);
//    }
//
//    // Copy all strings of temp to str[], so that str[] now
//    // contains partially sorted strings
//    for (int i = lo; i <= hi; i++) {
//        str[i] = strdup (temp[i - lo]);  // ???? Memory leaks ???
//    }
//
//    // Recursively MSD_sort() on each partially sorted
//    // strings set to sort them by their next character
//    for (int r = 0; r < 256; r++)
//    	radixsortstr_msd_sort (str, lo + count[r], lo + count[r + 1] - 1,
//                 d + 1);
//}
