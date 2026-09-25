/**
 * @file sorting.h
 * @brief Classical beginner-friendly sorting algorithms with complexity documentation.
 *
 * Part of the C Learning & DSA Toolkit.
 */

#ifndef SORTING_H
#define SORTING_H

/**
 * @brief Sorts an array using Bubble Sort.
 *
 * Repeatedly steps through the list, compares adjacent elements,
 * and swaps them if they are in the wrong order. Includes early-exit
 * optimization if no swaps occur in a pass.
 *
 * Time Complexity:
 *   - Best Case:    O(n) (already sorted)
 *   - Average Case: O(n^2)
 *   - Worst Case:   O(n^2)
 * Space Complexity: O(1) auxiliary space (in-place)
 * Stability:        Stable
 *
 * @param arr Array to sort.
 * @param size Number of elements.
 */
void bubble_sort(int arr[], int size);

/**
 * @brief Sorts an array using Selection Sort.
 *
 * Repeatedly finds the minimum element from the unsorted subarray
 * and places it at the beginning of the unsorted segment.
 *
 * Time Complexity:
 *   - Best Case:    O(n^2)
 *   - Average Case: O(n^2)
 *   - Worst Case:   O(n^2)
 * Space Complexity: O(1) auxiliary space (in-place)
 * Stability:        Not stable (in default array implementation)
 *
 * @param arr Array to sort.
 * @param size Number of elements.
 */
void selection_sort(int arr[], int size);

/**
 * @brief Sorts an array using Insertion Sort.
 *
 * Builds the sorted array one element at a time by repeatedly taking the next
 * element and inserting it into its correct position among previously sorted elements.
 *
 * Time Complexity:
 *   - Best Case:    O(n) (already sorted)
 *   - Average Case: O(n^2)
 *   - Worst Case:   O(n^2) (reverse sorted)
 * Space Complexity: O(1) auxiliary space (in-place)
 * Stability:        Stable
 *
 * @param arr Array to sort.
 * @param size Number of elements.
 */
void insertion_sort(int arr[], int size);

/**
 * @brief Sorts a subarray using Merge Sort (Divide and Conquer).
 *
 * Recursively splits the array into two halves, sorts each half, and merges
 * the two sorted halves back together.
 *
 * Time Complexity:
 *   - Best Case:    O(n log n)
 *   - Average Case: O(n log n)
 *   - Worst Case:   O(n log n)
 * Space Complexity: O(n) auxiliary space (for temporary merge buffer)
 * Stability:        Stable
 *
 * @param arr Array to sort.
 * @param left Starting index.
 * @param right Ending index.
 */
void merge_sort(int arr[], int left, int right);

/**
 * @brief Sorts a subarray using Quick Sort (Divide and Conquer).
 *
 * Selects a pivot element and partitions the array such that elements smaller
 * than the pivot come before it and elements larger come after it.
 *
 * Time Complexity:
 *   - Best Case:    O(n log n)
 *   - Average Case: O(n log n)
 *   - Worst Case:   O(n^2) (e.g., poor pivot selection on sorted array)
 * Space Complexity: O(log n) auxiliary stack space on average, O(n) worst case
 * Stability:        Not stable
 *
 * @param arr Array to sort.
 * @param low Starting index.
 * @param high Ending index.
 */
void quick_sort(int arr[], int low, int high);

#endif /* SORTING_H */
