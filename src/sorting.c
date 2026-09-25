/**
 * @file sorting.c
 * @brief Implementations of sorting algorithms.
 *
 * Part of the C Learning & DSA Toolkit.
 */

#include "sorting.h"
#include <stddef.h>
#include <stdbool.h>

/* Helper function to swap two array elements */
static void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort(int arr[], int size) {
    if (arr == NULL || size <= 1) {
        return;
    }

    for (int i = 0; i < size - 1; i++) {
        bool swapped = false;

        /* Last i elements are already in place */
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                swapped = true;
            }
        }

        /* If no two elements were swapped, array is already sorted */
        if (!swapped) {
            break;
        }
    }
}

void selection_sort(int arr[], int size) {
    if (arr == NULL || size <= 1) {
        return;
    }

    for (int i = 0; i < size - 1; i++) {
        int min_idx = i;

        /* Find the minimum element in the remaining unsorted subarray */
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }

        /* Swap found minimum with current element */
        if (min_idx != i) {
            swap(&arr[i], &arr[min_idx]);
        }
    }
}

void insertion_sort(int arr[], int size) {
    if (arr == NULL || size <= 1) {
        return;
    }

    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;

        /* Move elements of arr[0..i-1] that are greater than key one position ahead */
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

/* Helper function to merge two sorted subarrays [left..mid] and [mid+1..right] */
static void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    /* Temporary arrays for left and right subarrays */
    int left_arr[n1];
    int right_arr[n2];

    for (int i = 0; i < n1; i++) {
        left_arr[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        right_arr[j] = arr[mid + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2) {
        if (left_arr[i] <= right_arr[j]) {
            arr[k++] = left_arr[i++];
        } else {
            arr[k++] = right_arr[j++];
        }
    }

    while (i < n1) {
        arr[k++] = left_arr[i++];
    }

    while (j < n2) {
        arr[k++] = right_arr[j++];
    }
}

void merge_sort(int arr[], int left, int right) {
    if (arr == NULL || left >= right) {
        return;
    }

    int mid = left + (right - left) / 2;

    merge_sort(arr, left, mid);
    merge_sort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

/* Lomuto partition scheme using the last element as pivot */
static int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quick_sort(int arr[], int low, int high) {
    if (arr == NULL || low >= high) {
        return;
    }

    int pi = partition(arr, low, high);

    quick_sort(arr, low, pi - 1);
    quick_sort(arr, pi + 1, high);
}
