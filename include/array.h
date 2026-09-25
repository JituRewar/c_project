/**
 * @file array.h
 * @brief Array operations and educational array algorithms.
 *
 * Part of the C Learning & DSA Toolkit.
 */

#ifndef ARRAY_H
#define ARRAY_H

#include <stdbool.h>

/**
 * @brief Prints the elements of an integer array to stdout.
 * @param arr Array to print.
 * @param size Number of elements.
 */
void array_print(const int arr[], int size);

/**
 * @brief Finds the maximum element in an array.
 * @param arr Array of integers.
 * @param size Number of elements (must be > 0).
 * @return Maximum value, or 0 if size <= 0.
 */
int array_max(const int arr[], int size);

/**
 * @brief Finds the minimum element in an array.
 * @param arr Array of integers.
 * @param size Number of elements (must be > 0).
 * @return Minimum value, or 0 if size <= 0.
 */
int array_min(const int arr[], int size);

/**
 * @brief Calculates the sum of all elements in an array.
 * @param arr Array of integers.
 * @param size Number of elements.
 * @return Sum of elements.
 */
long long array_sum(const int arr[], int size);

/**
 * @brief Calculates the average of array elements.
 * @param arr Array of integers.
 * @param size Number of elements (must be > 0).
 * @return Floating-point average, or 0.0 if size <= 0.
 */
double array_average(const int arr[], int size);

/**
 * @brief Reverses an array in-place.
 * @param arr Array to reverse.
 * @param size Number of elements.
 */
void array_reverse(int arr[], int size);

/**
 * @brief Copies elements from source array to destination array.
 * @param src Source array.
 * @param dest Destination array (must be pre-allocated).
 * @param size Number of elements to copy.
 */
void array_copy(const int src[], int dest[], int size);

/**
 * @brief Removes duplicate values in-place from an array.
 * Note: Keeps the first occurrence of each value.
 * @param arr Array to process.
 * @param size Original number of elements.
 * @return New size of the array after duplicates are removed.
 */
int array_remove_duplicates(int arr[], int size);

/**
 * @brief Counts how many times a target value appears in an array.
 * @param arr Array of integers.
 * @param size Number of elements.
 * @param target Value to count.
 * @return Count of occurrences.
 */
int array_count_occurrences(const int arr[], int size, int target);

/**
 * @brief Rotates an array to the left by k positions.
 * Example: [1, 2, 3, 4, 5] rotated left by 2 becomes [3, 4, 5, 1, 2].
 * @param arr Array to rotate.
 * @param size Number of elements.
 * @param k Number of positions to rotate.
 */
void array_rotate_left(int arr[], int size, int k);

/**
 * @brief Merges two already sorted arrays into a new sorted array.
 * @param arr1 First sorted array.
 * @param size1 Size of first array.
 * @param arr2 Second sorted array.
 * @param size2 Size of second array.
 * @param result Pre-allocated array of at least (size1 + size2) elements.
 */
void array_merge_sorted(const int arr1[], int size1,
                        const int arr2[], int size2,
                        int result[]);

/**
 * @brief Checks if an array is sorted in non-decreasing (ascending) order.
 * @param arr Array of integers.
 * @param size Number of elements.
 * @return true if sorted, false otherwise.
 */
bool array_is_sorted(const int arr[], int size);

/**
 * @brief Finds the second largest distinct element in an array.
 * @param arr Array of integers.
 * @param size Number of elements (must have at least 2 distinct values).
 * @param result Pointer to store the second largest element if found.
 * @return true if second largest exists, false otherwise.
 */
bool array_second_largest(const int arr[], int size, int *result);

/**
 * @brief Finds two elements in an array that add up to a specific target sum.
 * @param arr Array of integers.
 * @param size Number of elements.
 * @param target Target sum.
 * @param index1 Pointer to store index of first element.
 * @param index2 Pointer to store index of second element.
 * @return true if a pair exists, false otherwise.
 */
bool array_two_sum(const int arr[], int size, int target, int *index1, int *index2);

#endif /* ARRAY_H */
