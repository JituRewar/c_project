/**
 * @file c_utils.h
 * @brief Common mathematical and general C utility functions.
 *
 * Part of the C Learning & DSA Toolkit.
 * Designed for first-year computer science students learning C programming.
 */

#ifndef C_UTILS_H
#define C_UTILS_H

#include <stdbool.h>

/**
 * @brief Swaps the values of two integers.
 * @param a Pointer to the first integer.
 * @param b Pointer to the second integer.
 */
void c_swap(int *a, int *b);

/**
 * @brief Returns the maximum of two integers.
 */
int c_max(int a, int b);

/**
 * @brief Returns the minimum of two integers.
 */
int c_min(int a, int b);

/**
 * @brief Returns the absolute value of an integer.
 */
int c_abs(int n);

/**
 * @brief Calculates base raised to the power of exp (base^exp).
 * @param base The base integer.
 * @param exp The exponent (non-negative).
 * @return base^exp, or 0 if exp < 0 (unsupported).
 */
long long c_power(int base, int exp);

/**
 * @brief Calculates factorial iteratively.
 * @param n Non-negative integer.
 * @return n! or -1 if n < 0.
 */
long long c_factorial(int n);

/**
 * @brief Calculates factorial using recursion.
 * @param n Non-negative integer.
 * @return n! or -1 if n < 0.
 */
long long c_factorial_recursive(int n);

/**
 * @brief Checks if a number is prime.
 * @param n Integer to check.
 * @return true if prime, false otherwise.
 */
bool c_is_prime(int n);

/**
 * @brief Checks if a number is even.
 * @return true if even, false if odd.
 */
bool c_is_even(int n);

/**
 * @brief Computes Greatest Common Divisor (GCD) using Euclidean algorithm.
 * @param a First integer.
 * @param b Second integer.
 * @return GCD of a and b.
 */
int c_gcd(int a, int b);

/**
 * @brief Computes Least Common Multiple (LCM).
 * @param a First integer.
 * @param b Second integer.
 * @return LCM of a and b.
 */
int c_lcm(int a, int b);

/**
 * @brief Reverses the digits of an integer.
 * @param n Integer to reverse (e.g., 1234 -> 4321).
 * @return Reversed integer.
 */
int c_reverse_num(int n);

/**
 * @brief Checks if an integer is a palindrome (e.g. 121, 1331).
 * @param n Integer to check.
 * @return true if palindrome, false otherwise.
 */
bool c_is_palindrome_num(int n);

/**
 * @brief Computes the n-th Fibonacci number iteratively (0-indexed: 0, 1, 1, 2, 3, 5...).
 * @param n Index (n >= 0).
 * @return Fibonacci number, or -1 if n < 0.
 */
long long c_fibonacci(int n);

/**
 * @brief Computes the n-th Fibonacci number recursively.
 * @param n Index (n >= 0).
 * @return Fibonacci number, or -1 if n < 0.
 */
long long c_fibonacci_recursive(int n);

#endif /* C_UTILS_H */
