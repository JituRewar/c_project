/**
 * @file array.c
 * @brief Implementations of array manipulation and educational array algorithms.
 *
 * Part of the C Learning & DSA Toolkit.
 */

#include "array.h"
#include <stdio.h>
#include <stdbool.h>

void array_print(const int arr[], int size) {
    if (arr == NULL || size <= 0) {
        printf("[]\n");
        return;
    }
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d%s", arr[i], (i == size - 1) ? "" : ", ");
    }
    printf("]\n");
}

int array_max(const int arr[], int size) {
    if (arr == NULL || size <= 0) {
        return 0;
    }
    int max_val = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }
    return max_val;
}

int array_min(const int arr[], int size) {
    if (arr == NULL || size <= 0) {
        return 0;
    }
    int min_val = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < min_val) {
            min_val = arr[i];
        }
    }
    return min_val;
}

long long array_sum(const int arr[], int size) {
    if (arr == NULL || size <= 0) {
        return 0;
    }
    long long total = 0;
    for (int i = 0; i < size; i++) {
        total += arr[i];
    }
    return total;
}

double array_average(const int arr[], int size) {
    if (arr == NULL || size <= 0) {
        return 0.0;
    }
    return (double)array_sum(arr, size) / size;
}

void array_reverse(int arr[], int size) {
    if (arr == NULL || size <= 1) {
        return;
    }
    int left = 0;
    int right = size - 1;
    while (left < right) {
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
        left++;
        right--;
    }
}

void array_copy(const int src[], int dest[], int size) {
    if (src == NULL || dest == NULL || size <= 0) {
        return;
    }
    for (int i = 0; i < size; i++) {
        dest[i] = src[i];
    }
}

int array_remove_duplicates(int arr[], int size) {
    if (arr == NULL || size <= 0) {
        return 0;
    }

    int unique_count = 0;
    for (int i = 0; i < size; i++) {
        bool already_seen = false;
        for (int j = 0; j < unique_count; j++) {
            if (arr[j] == arr[i]) {
                already_seen = true;
                break;
            }
        }
        if (!already_seen) {
            arr[unique_count] = arr[i];
            unique_count++;
        }
    }
    return unique_count;
}

int array_count_occurrences(const int arr[], int size, int target) {
    if (arr == NULL || size <= 0) {
        return 0;
    }
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            count++;
        }
    }
    return count;
}

/* Helper to reverse an array segment */
static void reverse_range(int arr[], int start, int end) {
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

void array_rotate_left(int arr[], int size, int k) {
    if (arr == NULL || size <= 1) {
        return;
    }
    k = k % size;
    if (k < 0) {
        k += size;
    }
    if (k == 0) {
        return;
    }

    /* Reverse first k elements, then remaining, then all */
    reverse_range(arr, 0, k - 1);
    reverse_range(arr, k, size - 1);
    reverse_range(arr, 0, size - 1);
}

void array_merge_sorted(const int arr1[], int size1,
                        const int arr2[], int size2,
                        int result[]) {
    if (result == NULL) {
        return;
    }
    int i = 0;
    int j = 0;
    int k = 0;

    while (i < size1 && j < size2) {
        if (arr1[i] <= arr2[j]) {
            result[k++] = arr1[i++];
        } else {
            result[k++] = arr2[j++];
        }
    }

    while (i < size1) {
        result[k++] = arr1[i++];
    }

    while (j < size2) {
        result[k++] = arr2[j++];
    }
}

bool array_is_sorted(const int arr[], int size) {
    if (arr == NULL || size <= 1) {
        return true;
    }
    for (int i = 0; i < size - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            return false;
        }
    }
    return true;
}

bool array_second_largest(const int arr[], int size, int *result) {
    if (arr == NULL || size < 2 || result == NULL) {
        return false;
    }

    int largest = arr[0];
    int second = -1;
    bool second_found = false;

    for (int i = 1; i < size; i++) {
        if (arr[i] > largest) {
            second = largest;
            largest = arr[i];
            second_found = true;
        } else if (arr[i] < largest) {
            if (!second_found || arr[i] > second) {
                second = arr[i];
                second_found = true;
            }
        }
    }

    if (second_found) {
        *result = second;
        return true;
    }
    return false;
}

bool array_two_sum(const int arr[], int size, int target, int *index1, int *index2) {
    if (arr == NULL || size < 2 || index1 == NULL || index2 == NULL) {
        return false;
    }

    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] + arr[j] == target) {
                *index1 = i;
                *index2 = j;
                return true;
            }
        }
    }

    return false;
}
