/**
 * @file test.c
 * @brief Comprehensive automated unit test suite for C Learning & DSA Toolkit.
 *
 * This test file uses simple assertion macros with colored terminal output
 * so first-year students can easily understand how unit tests work in C.
 */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "c_utils.h"
#include "array.h"
#include "string_utils.h"
#include "searching.h"
#include "sorting.h"
#include "stack.h"
#include "queue.h"
#include "linked_list.h"

/* ANSI Color escape sequences for friendly test reports */
#define COLOR_GREEN  "\033[0;32m"
#define COLOR_RED    "\033[0;31m"
#define COLOR_YELLOW "\033[0;33m"
#define COLOR_RESET  "\033[0m"

static int g_tests_run = 0;
static int g_tests_passed = 0;
static int g_tests_failed = 0;

#define ASSERT_TRUE(condition, message) do { \
    g_tests_run++; \
    if (condition) { \
        g_tests_passed++; \
    } else { \
        g_tests_failed++; \
        printf(COLOR_RED "  [FAIL] %s:%d: %s\n" COLOR_RESET, __FILE__, __LINE__, message); \
    } \
} while (0)

#define ASSERT_EQ(actual, expected, message) do { \
    g_tests_run++; \
    if ((actual) == (expected)) { \
        g_tests_passed++; \
    } else { \
        g_tests_failed++; \
        printf(COLOR_RED "  [FAIL] %s:%d: %s (Expected: %lld, Actual: %lld)\n" COLOR_RESET, \
               __FILE__, __LINE__, message, (long long)(expected), (long long)(actual)); \
    } \
} while (0)

#define ASSERT_STR_EQ(actual, expected, message) do { \
    g_tests_run++; \
    if (strcmp((actual), (expected)) == 0) { \
        g_tests_passed++; \
    } else { \
        g_tests_failed++; \
        printf(COLOR_RED "  [FAIL] %s:%d: %s (Expected: \"%s\", Actual: \"%s\")\n" COLOR_RESET, \
               __FILE__, __LINE__, message, expected, actual); \
    } \
} while (0)

/* ========================================================================= */
/* Test Suite: c_utils                                                       */
/* ========================================================================= */
static void test_c_utils(void) {
    printf(COLOR_YELLOW "Running c_utils tests...\n" COLOR_RESET);

    /* Swap */
    int x = 10, y = 20;
    c_swap(&x, &y);
    ASSERT_EQ(x, 20, "c_swap: x should be 20");
    ASSERT_EQ(y, 10, "c_swap: y should be 10");

    /* Max, Min, Abs */
    ASSERT_EQ(c_max(5, 9), 9, "c_max: 5 vs 9");
    ASSERT_EQ(c_max(-3, -7), -3, "c_max: -3 vs -7");
    ASSERT_EQ(c_min(5, 9), 5, "c_min: 5 vs 9");
    ASSERT_EQ(c_min(-3, -7), -7, "c_min: -3 vs -7");
    ASSERT_EQ(c_abs(-42), 42, "c_abs: negative");
    ASSERT_EQ(c_abs(42), 42, "c_abs: positive");
    ASSERT_EQ(c_abs(0), 0, "c_abs: zero");

    /* Power */
    ASSERT_EQ(c_power(2, 5), 32, "c_power: 2^5");
    ASSERT_EQ(c_power(5, 0), 1, "c_power: 5^0");
    ASSERT_EQ(c_power(3, 3), 27, "c_power: 3^3");

    /* Factorial */
    ASSERT_EQ(c_factorial(0), 1, "c_factorial: 0!");
    ASSERT_EQ(c_factorial(5), 120, "c_factorial: 5!");
    ASSERT_EQ(c_factorial_recursive(0), 1, "c_factorial_recursive: 0!");
    ASSERT_EQ(c_factorial_recursive(5), 120, "c_factorial_recursive: 5!");
    ASSERT_EQ(c_factorial(-2), -1, "c_factorial: negative returns -1");

    /* Prime */
    ASSERT_TRUE(c_is_prime(2), "c_is_prime: 2");
    ASSERT_TRUE(c_is_prime(17), "c_is_prime: 17");
    ASSERT_TRUE(!c_is_prime(1), "c_is_prime: 1 is not prime");
    ASSERT_TRUE(!c_is_prime(18), "c_is_prime: 18 is not prime");
    ASSERT_TRUE(!c_is_prime(-7), "c_is_prime: negative not prime");

    /* Even / Odd */
    ASSERT_TRUE(c_is_even(10), "c_is_even: 10");
    ASSERT_TRUE(!c_is_even(11), "c_is_even: 11 is not even");

    /* GCD and LCM */
    ASSERT_EQ(c_gcd(12, 18), 6, "c_gcd: 12 and 18");
    ASSERT_EQ(c_lcm(12, 18), 36, "c_lcm: 12 and 18");

    /* Number reversal and palindrome */
    ASSERT_EQ(c_reverse_num(1234), 4321, "c_reverse_num: 1234");
    ASSERT_TRUE(c_is_palindrome_num(1221), "c_is_palindrome_num: 1221");
    ASSERT_TRUE(!c_is_palindrome_num(1234), "c_is_palindrome_num: 1234");
    ASSERT_TRUE(!c_is_palindrome_num(-121), "c_is_palindrome_num: negative is false");

    /* Fibonacci */
    ASSERT_EQ(c_fibonacci(0), 0, "c_fibonacci: 0th");
    ASSERT_EQ(c_fibonacci(1), 1, "c_fibonacci: 1st");
    ASSERT_EQ(c_fibonacci(6), 8, "c_fibonacci: 6th");
    ASSERT_EQ(c_fibonacci_recursive(6), 8, "c_fibonacci_recursive: 6th");
}

/* ========================================================================= */
/* Test Suite: array                                                         */
/* ========================================================================= */
static void test_array_utils(void) {
    printf(COLOR_YELLOW "Running array tests...\n" COLOR_RESET);

    int arr[] = {10, 5, 20, 8, 15};
    int size = 5;

    ASSERT_EQ(array_max(arr, size), 20, "array_max");
    ASSERT_EQ(array_min(arr, size), 5, "array_min");
    ASSERT_EQ(array_sum(arr, size), 58, "array_sum");

    /* Reverse */
    int rev_arr[] = {1, 2, 3, 4};
    array_reverse(rev_arr, 4);
    ASSERT_EQ(rev_arr[0], 4, "array_reverse: index 0");
    ASSERT_EQ(rev_arr[3], 1, "array_reverse: index 3");

    /* Copy */
    int dest[5];
    array_copy(arr, dest, 5);
    ASSERT_EQ(dest[2], 20, "array_copy: element check");

    /* Count occurrences */
    int occ_arr[] = {1, 3, 3, 7, 3, 9};
    ASSERT_EQ(array_count_occurrences(occ_arr, 6, 3), 3, "array_count_occurrences");
    ASSERT_EQ(array_count_occurrences(occ_arr, 6, 100), 0, "array_count_occurrences missing");

    /* Remove duplicates */
    int dup_arr[] = {1, 2, 2, 3, 1, 4, 3};
    int new_size = array_remove_duplicates(dup_arr, 7);
    ASSERT_EQ(new_size, 4, "array_remove_duplicates: unique count");
    ASSERT_EQ(dup_arr[0], 1, "array_remove_duplicates: elem 0");
    ASSERT_EQ(dup_arr[1], 2, "array_remove_duplicates: elem 1");
    ASSERT_EQ(dup_arr[2], 3, "array_remove_duplicates: elem 2");
    ASSERT_EQ(dup_arr[3], 4, "array_remove_duplicates: elem 3");

    /* Rotate */
    int rot_arr[] = {1, 2, 3, 4, 5};
    array_rotate_left(rot_arr, 5, 2);
    ASSERT_EQ(rot_arr[0], 3, "array_rotate_left: index 0");
    ASSERT_EQ(rot_arr[4], 2, "array_rotate_left: index 4");

    /* Is sorted */
    int sorted[] = {1, 4, 7, 9, 12};
    int unsorted[] = {1, 7, 4, 9};
    ASSERT_TRUE(array_is_sorted(sorted, 5), "array_is_sorted: true");
    ASSERT_TRUE(!array_is_sorted(unsorted, 4), "array_is_sorted: false");

    /* Merge sorted */
    int a1[] = {1, 3, 5};
    int a2[] = {2, 4, 6};
    int merged[6];
    array_merge_sorted(a1, 3, a2, 3, merged);
    ASSERT_TRUE(array_is_sorted(merged, 6), "array_merge_sorted is sorted");
    ASSERT_EQ(merged[0], 1, "merged[0]");
    ASSERT_EQ(merged[5], 6, "merged[5]");

    /* Second largest */
    int sec_res;
    ASSERT_TRUE(array_second_largest(arr, 5, &sec_res), "second largest found");
    ASSERT_EQ(sec_res, 15, "second largest is 15");

    /* Two-Sum */
    int idx1, idx2;
    ASSERT_TRUE(array_two_sum(arr, 5, 25, &idx1, &idx2), "two_sum found (5+20=25)");
    ASSERT_EQ(arr[idx1] + arr[idx2], 25, "two_sum target verified");
}

/* ========================================================================= */
/* Test Suite: string_utils                                                  */
/* ========================================================================= */
static void test_string_utils(void) {
    printf(COLOR_YELLOW "Running string_utils tests...\n" COLOR_RESET);

    /* Length */
    ASSERT_EQ(str_length("hello"), 5, "str_length: \"hello\"");
    ASSERT_EQ(str_length(""), 0, "str_length: empty");
    ASSERT_EQ(str_length(NULL), 0, "str_length: NULL");

    /* Copy */
    char buffer[32];
    str_copy(buffer, "open source");
    ASSERT_STR_EQ(buffer, "open source", "str_copy");

    /* Compare */
    ASSERT_TRUE(str_compare("apple", "apple") == 0, "str_compare: equal");
    ASSERT_TRUE(str_compare("apple", "banana") < 0, "str_compare: apple < banana");
    ASSERT_TRUE(str_compare("zebra", "monkey") > 0, "str_compare: zebra > monkey");

    /* Reverse */
    char rev_buf[] = "abcdef";
    str_reverse(rev_buf);
    ASSERT_STR_EQ(rev_buf, "fedcba", "str_reverse");

    /* Palindrome tests (including Good First Issue test cases) */
    ASSERT_TRUE(str_is_palindrome("madam"), "str_is_palindrome: madam");
    ASSERT_TRUE(str_is_palindrome("racecar"), "str_is_palindrome: racecar");
    ASSERT_TRUE(str_is_palindrome("a"), "str_is_palindrome: single char 'a'");
    ASSERT_TRUE(str_is_palindrome(""), "str_is_palindrome: empty string");
    ASSERT_TRUE(!str_is_palindrome("hello"), "str_is_palindrome: hello");

    /* Vowels and consonants */
    ASSERT_EQ(str_count_vowels("Education"), 5, "str_count_vowels");
    ASSERT_EQ(str_count_consonants("Education"), 4, "str_count_consonants");

    /* Words and chars */
    ASSERT_EQ(str_count_words("First year computer science students"), 5, "str_count_words");
    ASSERT_EQ(str_count_words("   leading   and   trailing   "), 3, "str_count_words with spaces");
    ASSERT_EQ(str_count_chars("mississippi", 's'), 4, "str_count_chars");

    /* Case conversion */
    char lower_test[] = "Hello WORLD 123";
    str_to_lower(lower_test);
    ASSERT_STR_EQ(lower_test, "hello world 123", "str_to_lower");

    char upper_test[] = "Hello world 123";
    str_to_upper(upper_test);
    ASSERT_STR_EQ(upper_test, "HELLO WORLD 123", "str_to_upper");

    /* Space removal */
    char space_test[] = "  a  b   c \t d \n ";
    str_remove_spaces(space_test);
    ASSERT_STR_EQ(space_test, "abcd", "str_remove_spaces");

    /* Anagram */
    ASSERT_TRUE(str_is_anagram("Listen", "Silent"), "str_is_anagram: Listen / Silent");
    ASSERT_TRUE(str_is_anagram("rail safety", "fairy tales"), "str_is_anagram: phrase");
    ASSERT_TRUE(!str_is_anagram("apple", "apply"), "str_is_anagram: false");
}

/* ========================================================================= */
/* Test Suite: searching                                                     */
/* ========================================================================= */
static void test_searching(void) {
    printf(COLOR_YELLOW "Running searching tests...\n" COLOR_RESET);

    int arr[] = {3, 9, 14, 21, 28, 35, 42};
    int size = 7;

    /* Linear search */
    ASSERT_EQ(linear_search(arr, size, 21), 3, "linear_search found");
    ASSERT_EQ(linear_search(arr, size, 100), -1, "linear_search not found");

    /* Binary search */
    ASSERT_EQ(binary_search(arr, size, 3), 0, "binary_search first element");
    ASSERT_EQ(binary_search(arr, size, 21), 3, "binary_search middle element");
    ASSERT_EQ(binary_search(arr, size, 42), 6, "binary_search last element");
    ASSERT_EQ(binary_search(arr, size, 15), -1, "binary_search missing");

    /* Recursive binary search */
    ASSERT_EQ(binary_search_recursive(arr, 0, size - 1, 21), 3, "binary_search_recursive found");
    ASSERT_EQ(binary_search_recursive(arr, 0, size - 1, 99), -1, "binary_search_recursive missing");
}

/* ========================================================================= */
/* Test Suite: sorting                                                       */
/* ========================================================================= */
static void test_sorting(void) {
    printf(COLOR_YELLOW "Running sorting tests...\n" COLOR_RESET);

    int sample[] = {29, 10, 14, 37, 14, 2};
    int expected[] = {2, 10, 14, 14, 29, 37};
    int n = 6;

    /* Bubble Sort */
    int b_arr[6];
    memcpy(b_arr, sample, sizeof(sample));
    bubble_sort(b_arr, n);
    ASSERT_TRUE(array_is_sorted(b_arr, n), "bubble_sort: is sorted");
    ASSERT_EQ(b_arr[0], expected[0], "bubble_sort: min");
    ASSERT_EQ(b_arr[5], expected[5], "bubble_sort: max");

    /* Selection Sort */
    int s_arr[6];
    memcpy(s_arr, sample, sizeof(sample));
    selection_sort(s_arr, n);
    ASSERT_TRUE(array_is_sorted(s_arr, n), "selection_sort: is sorted");

    /* Insertion Sort */
    int i_arr[6];
    memcpy(i_arr, sample, sizeof(sample));
    insertion_sort(i_arr, n);
    ASSERT_TRUE(array_is_sorted(i_arr, n), "insertion_sort: is sorted");

    /* Merge Sort */
    int m_arr[6];
    memcpy(m_arr, sample, sizeof(sample));
    merge_sort(m_arr, 0, n - 1);
    ASSERT_TRUE(array_is_sorted(m_arr, n), "merge_sort: is sorted");

    /* Quick Sort */
    int q_arr[6];
    memcpy(q_arr, sample, sizeof(sample));
    quick_sort(q_arr, 0, n - 1);
    ASSERT_TRUE(array_is_sorted(q_arr, n), "quick_sort: is sorted");
}

/* ========================================================================= */
/* Test Suite: stack                                                         */
/* ========================================================================= */
static void test_stack(void) {
    printf(COLOR_YELLOW "Running stack tests...\n" COLOR_RESET);

    Stack s;
    stack_init(&s);

    ASSERT_TRUE(stack_is_empty(&s), "stack initially empty");
    ASSERT_EQ(stack_size(&s), 0, "stack size 0");

    int val;
    ASSERT_TRUE(!stack_pop(&s, &val), "pop on empty stack returns false");
    ASSERT_TRUE(!stack_peek(&s, &val), "peek on empty stack returns false");

    ASSERT_TRUE(stack_push(&s, 100), "push 100");
    ASSERT_TRUE(stack_push(&s, 200), "push 200");
    ASSERT_EQ(stack_size(&s), 2, "stack size 2");

    ASSERT_TRUE(stack_peek(&s, &val), "peek successful");
    ASSERT_EQ(val, 200, "peek value is 200");

    ASSERT_TRUE(stack_pop(&s, &val), "pop successful");
    ASSERT_EQ(val, 200, "popped value is 200");
    ASSERT_EQ(stack_size(&s), 1, "stack size after pop is 1");

    ASSERT_TRUE(stack_pop(&s, &val), "pop last element");
    ASSERT_EQ(val, 100, "popped value is 100");
    ASSERT_TRUE(stack_is_empty(&s), "stack empty again");
}

/* ========================================================================= */
/* Test Suite: queue                                                         */
/* ========================================================================= */
static void test_queue(void) {
    printf(COLOR_YELLOW "Running queue tests...\n" COLOR_RESET);

    Queue q;
    queue_init(&q);

    ASSERT_TRUE(queue_is_empty(&q), "queue initially empty");
    ASSERT_EQ(queue_size(&q), 0, "queue size 0");

    int val;
    ASSERT_TRUE(!queue_dequeue(&q, &val), "dequeue on empty queue returns false");
    ASSERT_TRUE(!queue_front(&q, &val), "front on empty queue returns false");

    ASSERT_TRUE(queue_enqueue(&q, 10), "enqueue 10");
    ASSERT_TRUE(queue_enqueue(&q, 20), "enqueue 20");
    ASSERT_TRUE(queue_enqueue(&q, 30), "enqueue 30");
    ASSERT_EQ(queue_size(&q), 3, "queue size 3");

    ASSERT_TRUE(queue_front(&q, &val), "queue_front successful");
    ASSERT_EQ(val, 10, "front value is 10");

    ASSERT_TRUE(queue_dequeue(&q, &val), "dequeue successful");
    ASSERT_EQ(val, 10, "dequeued value is 10");
    ASSERT_EQ(queue_size(&q), 2, "queue size after dequeue is 2");

    ASSERT_TRUE(queue_front(&q, &val), "new front is 20");
    ASSERT_EQ(val, 20, "front is 20");

    queue_dequeue(&q, NULL);
    queue_dequeue(&q, NULL);
    ASSERT_TRUE(queue_is_empty(&q), "queue is empty after draining");
}

/* ========================================================================= */
/* Test Suite: linked_list                                                   */
/* ========================================================================= */
static void test_linked_list(void) {
    printf(COLOR_YELLOW "Running linked_list tests...\n" COLOR_RESET);

    LinkedList list;
    list_init(&list);

    ASSERT_EQ(list_count(&list), 0, "list initially empty");
    ASSERT_EQ(list_search(&list, 42), -1, "search in empty list returns -1");

    ASSERT_TRUE(list_insert_beginning(&list, 20), "insert beginning 20");
    ASSERT_TRUE(list_insert_beginning(&list, 10), "insert beginning 10");
    ASSERT_TRUE(list_insert_end(&list, 30), "insert end 30");
    ASSERT_EQ(list_count(&list), 3, "count is 3 (10, 20, 30)");

    ASSERT_EQ(list_search(&list, 10), 0, "search 10 at index 0");
    ASSERT_EQ(list_search(&list, 20), 1, "search 20 at index 1");
    ASSERT_EQ(list_search(&list, 30), 2, "search 30 at index 2");
    ASSERT_EQ(list_search(&list, 999), -1, "search non-existent returns -1");

    /* Delete middle */
    ASSERT_TRUE(list_delete_value(&list, 20), "delete middle 20");
    ASSERT_EQ(list_count(&list), 2, "count is now 2");
    ASSERT_EQ(list_search(&list, 20), -1, "20 no longer found");

    /* Delete non-existent */
    ASSERT_TRUE(!list_delete_value(&list, 999), "delete non-existent returns false");

    /* Delete head */
    ASSERT_TRUE(list_delete_value(&list, 10), "delete head 10");
    ASSERT_EQ(list_count(&list), 1, "count is now 1");

    /* Free list */
    list_free(&list);
    ASSERT_EQ(list_count(&list), 0, "count after free is 0");
    ASSERT_TRUE(list.head == NULL, "head is NULL after free");
}

/* ========================================================================= */
/* Main Test Runner                                                          */
/* ========================================================================= */
int main(void) {
    printf("==================================================\n");
    printf("   C Learning & DSA Toolkit - Test Suite\n");
    printf("==================================================\n\n");

    test_c_utils();
    test_array_utils();
    test_string_utils();
    test_searching();
    test_sorting();
    test_stack();
    test_queue();
    test_linked_list();

    printf("\n==================================================\n");
    printf("Test Results: %d executed | ", g_tests_run);
    if (g_tests_failed == 0) {
        printf(COLOR_GREEN "%d PASSED" COLOR_RESET " | 0 FAILED\n", g_tests_passed);
        printf(COLOR_GREEN "ALL TESTS PASSED!\n" COLOR_RESET);
    } else {
        printf("%d passed | " COLOR_RED "%d FAILED" COLOR_RESET "\n", g_tests_passed, g_tests_failed);
    }
    printf("==================================================\n");

    return (g_tests_failed == 0) ? 0 : 1;
}
