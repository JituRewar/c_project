/**
 * @file string_utils.c
 * @brief Implementations of educational string operations.
 *
 * Part of the C Learning & DSA Toolkit.
 */

#include "string_utils.h"
#include <stdio.h>
#include <stdbool.h>

int str_length(const char *str) {
    if (str == NULL) {
        return 0;
    }
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

char *str_copy(char *dest, const char *src) {
    if (dest == NULL) {
        return NULL;
    }
    if (src == NULL) {
        dest[0] = '\0';
        return dest;
    }
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}

int str_compare(const char *str1, const char *str2) {
    if (str1 == NULL && str2 == NULL) {
        return 0;
    }
    if (str1 == NULL) {
        return -1;
    }
    if (str2 == NULL) {
        return 1;
    }

    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return (unsigned char)str1[i] - (unsigned char)str2[i];
        }
        i++;
    }
    return (unsigned char)str1[i] - (unsigned char)str2[i];
}

void str_reverse(char *str) {
    if (str == NULL) {
        return;
    }
    int left = 0;
    int right = str_length(str) - 1;
    while (left < right) {
        char temp = str[left];
        str[left] = str[right];
        str[right] = temp;
        left++;
        right--;
    }
}

bool str_is_palindrome(const char *str) {
    if (str == NULL) {
        return false;
    }
    int left = 0;
    int right = str_length(str) - 1;

    while (left < right) {
        if (str[left] != str[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

static bool is_vowel(char ch) {
    if (ch >= 'A' && ch <= 'Z') {
        ch = (char)(ch + ('a' - 'A'));
    }
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}

static bool is_alpha(char ch) {
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

int str_count_vowels(const char *str) {
    if (str == NULL) {
        return 0;
    }
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (is_vowel(str[i])) {
            count++;
        }
    }
    return count;
}

int str_count_consonants(const char *str) {
    if (str == NULL) {
        return 0;
    }
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (is_alpha(str[i]) && !is_vowel(str[i])) {
            count++;
        }
    }
    return count;
}

int str_count_words(const char *str) {
    if (str == NULL) {
        return 0;
    }
    int words = 0;
    bool in_word = false;

    for (int i = 0; str[i] != '\0'; i++) {
        char ch = str[i];
        if (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\r') {
            in_word = false;
        } else {
            if (!in_word) {
                words++;
                in_word = true;
            }
        }
    }
    return words;
}

int str_count_chars(const char *str, char ch) {
    if (str == NULL) {
        return 0;
    }
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ch) {
            count++;
        }
    }
    return count;
}

void str_to_lower(char *str) {
    if (str == NULL) {
        return;
    }
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = (char)(str[i] + ('a' - 'A'));
        }
    }
}

void str_to_upper(char *str) {
    if (str == NULL) {
        return;
    }
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = (char)(str[i] - ('a' - 'A'));
        }
    }
}

void str_remove_spaces(char *str) {
    if (str == NULL) {
        return;
    }
    int write_idx = 0;
    for (int read_idx = 0; str[read_idx] != '\0'; read_idx++) {
        char ch = str[read_idx];
        if (ch != ' ' && ch != '\t' && ch != '\n' && ch != '\r') {
            str[write_idx++] = ch;
        }
    }
    str[write_idx] = '\0';
}

bool str_is_anagram(const char *str1, const char *str2) {
    if (str1 == NULL || str2 == NULL) {
        return false;
    }

    int freq[26] = {0};

    int len1 = 0;
    for (int i = 0; str1[i] != '\0'; i++) {
        char ch = str1[i];
        if (ch >= 'A' && ch <= 'Z') {
            freq[ch - 'A']++;
            len1++;
        } else if (ch >= 'a' && ch <= 'z') {
            freq[ch - 'a']++;
            len1++;
        }
    }

    int len2 = 0;
    for (int i = 0; str2[i] != '\0'; i++) {
        char ch = str2[i];
        if (ch >= 'A' && ch <= 'Z') {
            freq[ch - 'A']--;
            len2++;
        } else if (ch >= 'a' && ch <= 'z') {
            freq[ch - 'a']--;
            len2++;
        }
    }

    if (len1 != len2) {
        return false;
    }

    for (int i = 0; i < 26; i++) {
        if (freq[i] != 0) {
            return false;
        }
    }
    return true;
}
