/**
 * @file c_utils.c
 * @brief Implementations of general C utilities and mathematical functions.
 *
 * Part of the C Learning & DSA Toolkit.
 */

#include "c_utils.h"
#include <stddef.h>
#include <stdbool.h>

void c_swap(int *a, int *b) {
    if (a == NULL || b == NULL) {
        return;
    }
    int temp = *a;
    *a = *b;
    *b = temp;
}

int c_max(int a, int b) {
    return (a > b) ? a : b;
}

int c_min(int a, int b) {
    return (a < b) ? a : b;
}

int c_abs(int n) {
    return (n < 0) ? -n : n;
}

long long c_power(int base, int exp) {
    if (exp < 0) {
        return 0; /* Exponents < 0 return 0 for integer mathematics */
    }
    long long result = 1;
    for (int i = 0; i < exp; i++) {
        result *= base;
    }
    return result;
}

long long c_factorial(int n) {
    if (n < 0) {
        return -1; /* Factorial is undefined for negative integers */
    }
    long long result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

long long c_factorial_recursive(int n) {
    if (n < 0) {
        return -1;
    }
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * c_factorial_recursive(n - 1);
}

bool c_is_prime(int n) {
    if (n <= 1) {
        return false;
    }
    if (n <= 3) {
        return true;
    }
    if (n % 2 == 0 || n % 3 == 0) {
        return false;
    }
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

bool c_is_even(int n) {
    return (n % 2 == 0);
}

int c_gcd(int a, int b) {
    a = c_abs(a);
    b = c_abs(b);
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int c_lcm(int a, int b) {
    if (a == 0 || b == 0) {
        return 0;
    }
    int gcd_val = c_gcd(a, b);
    return c_abs((a / gcd_val) * b);
}

int c_reverse_num(int n) {
    int sign = (n < 0) ? -1 : 1;
    int num = c_abs(n);
    int reversed = 0;

    while (num > 0) {
        int last_digit = num % 10;
        reversed = reversed * 10 + last_digit;
        num /= 10;
    }

    return sign * reversed;
}

bool c_is_palindrome_num(int n) {
    if (n < 0) {
        return false; /* Negative numbers are not palindromes due to sign */
    }
    return n == c_reverse_num(n);
}

long long c_fibonacci(int n) {
    if (n < 0) {
        return -1;
    }
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }

    long long prev2 = 0;
    long long prev1 = 1;
    long long current = 0;

    for (int i = 2; i <= n; i++) {
        current = prev1 + prev2;
        prev2 = prev1;
        prev1 = current;
    }

    return current;
}

long long c_fibonacci_recursive(int n) {
    if (n < 0) {
        return -1;
    }
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    return c_fibonacci_recursive(n - 1) + c_fibonacci_recursive(n - 2);
}
