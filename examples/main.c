/**
 * @file main.c
 * @brief Demonstration example for the C Learning & DSA Toolkit.
 *
 * This file shows first-year students how to include the toolkit headers
 * and call functions from each module.
 */

#include <stdio.h>
#include <stdbool.h>

#include "c_utils.h"
#include "array.h"
#include "string_utils.h"
#include "searching.h"
#include "sorting.h"
#include "stack.h"
#include "queue.h"
#include "linked_list.h"

static void demo_c_utils(void) {
    printf("========================================\n");
    printf("1. Basic C Utilities\n");
    printf("========================================\n");

    int a = 15, b = 25;
    printf("Original values: a = %d, b = %d\n", a, b);
    c_swap(&a, &b);
    printf("After c_swap:    a = %d, b = %d\n", a, b);

    printf("c_max(10, 25): %d | c_min(10, 25): %d\n", c_max(10, 25), c_min(10, 25));
    printf("c_factorial(5): %lld\n", c_factorial(5));
    printf("c_gcd(48, 18): %d | c_lcm(48, 18): %d\n", c_gcd(48, 18), c_lcm(48, 18));
    printf("c_is_prime(29): %s\n", c_is_prime(29) ? "true" : "false");
    printf("c_reverse_num(12345): %d\n", c_reverse_num(12345));
    printf("c_is_palindrome_num(12321): %s\n", c_is_palindrome_num(12321) ? "true" : "false");
    printf("c_fibonacci(7): %lld\n\n", c_fibonacci(7));
}

static void demo_array_utils(void) {
    printf("========================================\n");
    printf("2. Array Operations\n");
    printf("========================================\n");

    int arr[] = {12, 3, 45, 7, 23, 3, 12};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array: ");
    array_print(arr, size);

    printf("Max: %d | Min: %d | Sum: %lld | Average: %.2f\n",
           array_max(arr, size),
           array_min(arr, size),
           array_sum(arr, size),
           array_average(arr, size));

    int second;
    if (array_second_largest(arr, size, &second)) {
        printf("Second Largest: %d\n", second);
    }

    int idx1, idx2;
    if (array_two_sum(arr, size, 50, &idx1, &idx2)) {
        printf("Two-Sum (target 50): arr[%d] (%d) + arr[%d] (%d) = 50\n",
               idx1, arr[idx1], idx2, arr[idx2]);
    }

    int dedup_arr[] = {1, 2, 2, 3, 4, 4, 5};
    int dedup_size = sizeof(dedup_arr) / sizeof(dedup_arr[0]);
    printf("Before duplicate removal: ");
    array_print(dedup_arr, dedup_size);
    dedup_size = array_remove_duplicates(dedup_arr, dedup_size);
    printf("After duplicate removal:  ");
    array_print(dedup_arr, dedup_size);
    printf("\n");
}

static void demo_string_utils(void) {
    printf("========================================\n");
    printf("3. String Utilities\n");
    printf("========================================\n");

    const char *text = "Hello Open Source World";
    printf("Text: \"%s\"\n", text);
    printf("Length: %d\n", str_length(text));
    printf("Vowels: %d | Consonants: %d | Words: %d\n",
           str_count_vowels(text),
           str_count_consonants(text),
           str_count_words(text));

    char palindrome_test[] = "racecar";
    printf("\"%s\" is palindrome? %s\n",
           palindrome_test,
           str_is_palindrome(palindrome_test) ? "Yes" : "No");

    const char *s1 = "listen";
    const char *s2 = "silent";
    printf("\"%s\" and \"%s\" are anagrams? %s\n\n",
           s1, s2, str_is_anagram(s1, s2) ? "Yes" : "No");
}

static void demo_searching(void) {
    printf("========================================\n");
    printf("4. Searching Algorithms\n");
    printf("========================================\n");

    int sorted_arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int size = sizeof(sorted_arr) / sizeof(sorted_arr[0]);

    printf("Sorted Array: ");
    array_print(sorted_arr, size);

    int target = 23;
    int lin_idx = linear_search(sorted_arr, size, target);
    printf("Linear Search for %d: found at index %d\n", target, lin_idx);

    int bin_idx = binary_search(sorted_arr, size, target);
    printf("Binary Search for %d: found at index %d\n", target, bin_idx);

    int rec_idx = binary_search_recursive(sorted_arr, 0, size - 1, target);
    printf("Recursive Binary Search for %d: found at index %d\n\n", target, rec_idx);
}

static void demo_sorting(void) {
    printf("========================================\n");
    printf("5. Sorting Algorithms\n");
    printf("========================================\n");

    int arr1[] = {64, 34, 25, 12, 22, 11, 90};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    printf("Original: ");
    array_print(arr1, n1);
    bubble_sort(arr1, n1);
    printf("Bubble Sorted:    ");
    array_print(arr1, n1);

    int arr2[] = {38, 27, 43, 3, 9, 82, 10};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    merge_sort(arr2, 0, n2 - 1);
    printf("Merge Sorted:     ");
    array_print(arr2, n2);

    int arr3[] = {10, 80, 30, 90, 40, 50, 70};
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    quick_sort(arr3, 0, n3 - 1);
    printf("Quick Sorted:     ");
    array_print(arr3, n3);
    printf("\n");
}

static void demo_data_structures(void) {
    printf("========================================\n");
    printf("6. Data Structures (Stack, Queue, List)\n");
    printf("========================================\n");

    /* Stack Demo */
    printf("[Stack Demonstration]\n");
    Stack s;
    stack_init(&s);
    stack_push(&s, 10);
    stack_push(&s, 20);
    stack_push(&s, 30);
    stack_print(&s);

    int popped;
    if (stack_pop(&s, &popped)) {
        printf("Popped: %d\n", popped);
    }
    int peeked;
    if (stack_peek(&s, &peeked)) {
        printf("Current top (peek): %d\n", peeked);
    }
    stack_print(&s);
    printf("\n");

    /* Queue Demo */
    printf("[Queue Demonstration]\n");
    Queue q;
    queue_init(&q);
    queue_enqueue(&q, 100);
    queue_enqueue(&q, 200);
    queue_enqueue(&q, 300);
    queue_print(&q);

    int dequeued;
    if (queue_dequeue(&q, &dequeued)) {
        printf("Dequeued: %d\n", dequeued);
    }
    queue_print(&q);
    printf("\n");

    /* Linked List Demo */
    printf("[Linked List Demonstration]\n");
    LinkedList list;
    list_init(&list);
    list_insert_beginning(&list, 20);
    list_insert_beginning(&list, 10);
    list_insert_end(&list, 30);
    list_insert_end(&list, 40);
    list_display(&list);

    printf("Search for 30: index %d\n", list_search(&list, 30));

    printf("Deleting value 20...\n");
    list_delete_value(&list, 20);
    list_display(&list);

    list_free(&list);
    printf("List after list_free(): ");
    list_display(&list);
    printf("\n");
}

int main(void) {
    printf("\n========================================\n");
    printf(" Welcome to C Learning & DSA Toolkit!\n");
    printf("========================================\n\n");

    demo_c_utils();
    demo_array_utils();
    demo_string_utils();
    demo_searching();
    demo_sorting();
    demo_data_structures();

    printf("All module demonstrations finished successfully!\n");
    return 0;
}
