/**
 * @file searching.h
 * @brief Classical searching algorithms with explanations and complexity details.
 *
 * Part of the C Learning & DSA Toolkit.
 */

#ifndef SEARCHING_H
#define SEARCHING_H

/**
 * @brief Performs Linear Search on an array.
 *
 * Scans each element sequentially from left to right until the target is found
 * or the end of the array is reached.
 *
 * Time Complexity:
 *   - Best Case:    O(1) (target is at index 0)
 *   - Average Case: O(n)
 *   - Worst Case:   O(n) (target is at end or not present)
 * Space Complexity: O(1) auxiliary space
 *
 * @param arr Array to search.
 * @param size Number of elements in the array.
 * @param target Value to search for.
 * @return Index of the first occurrence of target, or -1 if not found.
 */
int linear_search(const int arr[], int size, int target);

/**
 * @brief Performs Binary Search iteratively on a SORTED array.
 *
 * Halves the search space at every step by comparing the middle element with the target.
 * Array MUST be sorted in ascending order prior to calling this function.
 *
 * Time Complexity:
 *   - Best Case:    O(1) (target is at middle)
 *   - Average Case: O(log n)
 *   - Worst Case:   O(log n)
 * Space Complexity: O(1) auxiliary space
 *
 * @param arr Sorted array to search.
 * @param size Number of elements.
 * @param target Value to search for.
 * @return Index of a matching element, or -1 if not found.
 */
int binary_search(const int arr[], int size, int target);

/**
 * @brief Performs Binary Search recursively on a SORTED array.
 *
 * Recursively reduces search range [left, right] by half.
 *
 * Time Complexity:  O(log n)
 * Space Complexity: O(log n) due to recursive call stack frames.
 *
 * @param arr Sorted array to search.
 * @param left Starting index of current search subarray.
 * @param right Ending index of current search subarray.
 * @param target Value to search for.
 * @return Index of target, or -1 if not found.
 */
int binary_search_recursive(const int arr[], int left, int right, int target);

#endif /* SEARCHING_H */
