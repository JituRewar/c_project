/**
 * @file string_utils.h
 * @brief Beginner-friendly educational string manipulation functions.
 *
 * Part of the C Learning & DSA Toolkit.
 * Note: These functions are implemented manually for educational purposes
 * rather than simply wrapping string.h library functions.
 */

#ifndef STRING_UTILS_H
#define STRING_UTILS_H

#include <stdbool.h>

/**
 * @brief Computes the length of a null-terminated string.
 * @param str Input string.
 * @return Number of characters before null terminator, or 0 if str is NULL.
 */
int str_length(const char *str);

/**
 * @brief Copies source string into destination buffer (including null terminator).
 * @param dest Destination buffer (must have enough allocated memory).
 * @param src Source string.
 * @return Pointer to dest.
 */
char *str_copy(char *dest, const char *src);

/**
 * @brief Compares two strings lexicographically.
 * @param str1 First string.
 * @param str2 Second string.
 * @return 0 if equal, < 0 if str1 < str2, > 0 if str1 > str2.
 */
int str_compare(const char *str1, const char *str2);

/**
 * @brief Reverses a string in-place.
 * @param str String to reverse.
 */
void str_reverse(char *str);

/**
 * @brief Checks if a string reads the same forwards and backwards.
 * Case-sensitive check ignoring trailing newlines.
 * @param str Input string.
 * @return true if palindrome, false otherwise.
 */
bool str_is_palindrome(const char *str);

/**
 * @brief Counts the total number of vowels (A, E, I, O, U, case-insensitive).
 * @param str Input string.
 * @return Count of vowels.
 */
int str_count_vowels(const char *str);

/**
 * @brief Counts the total number of alphabetic consonants.
 * @param str Input string.
 * @return Count of consonants.
 */
int str_count_consonants(const char *str);

/**
 * @brief Counts the number of words separated by spaces, tabs, or newlines.
 * @param str Input string.
 * @return Total word count.
 */
int str_count_words(const char *str);

/**
 * @brief Counts occurrences of a specific character in a string.
 * @param str Input string.
 * @param ch Character to count.
 * @return Count of occurrences.
 */
int str_count_chars(const char *str, char ch);

/**
 * @brief Converts all uppercase letters in string to lowercase in-place.
 * @param str Input string.
 */
void str_to_lower(char *str);

/**
 * @brief Converts all lowercase letters in string to uppercase in-place.
 * @param str Input string.
 */
void str_to_upper(char *str);

/**
 * @brief Removes all whitespace characters (' ', '\t', '\n', '\r') in-place.
 * @param str Input string.
 */
void str_remove_spaces(char *str);

/**
 * @brief Checks if two strings are anagrams of each other (contain same letters with same frequencies).
 * Ignores spaces and case.
 * @param str1 First string.
 * @param str2 Second string.
 * @return true if anagrams, false otherwise.
 */
bool str_is_anagram(const char *str1, const char *str2);

#endif /* STRING_UTILS_H */
