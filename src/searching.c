/**
 * @file searching.c
 * @brief Implementations of searching algorithms.
 *
 * Part of the C Learning & DSA Toolkit.
 */

#include "searching.h"
#include <stddef.h>

int linear_search(const int arr[], int size, int target) {
    if (arr == NULL || size <= 0) {
        return -1;
    }

    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;
        }
    }

    return -1;
}

int binary_search(const int arr[], int size, int target) {
    if (arr == NULL || size <= 0) {
        return -1;
    }

    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid;
        }

        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}

int binary_search_recursive(const int arr[], int left, int right, int target) {
    if (arr == NULL || left > right) {
        return -1;
    }

    int mid = left + (right - left) / 2;

    if (arr[mid] == target) {
        return mid;
    }

    if (arr[mid] < target) {
        return binary_search_recursive(arr, mid + 1, right, target);
    } else {
        return binary_search_recursive(arr, left, mid - 1, target);
    }
}
