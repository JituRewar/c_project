/**
 * @file stack.h
 * @brief Array-based Stack (LIFO - Last-In, First-Out) implementation.
 *
 * Part of the C Learning & DSA Toolkit.
 */

#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

#define STACK_MAX_CAPACITY 100

/**
 * @brief Structure representing a fixed-size integer stack.
 */
typedef struct {
    int data[STACK_MAX_CAPACITY];
    int top;  /**< Index of top element, -1 when empty */
} Stack;

/**
 * @brief Initializes an empty stack.
 * @param s Pointer to Stack.
 */
void stack_init(Stack *s);

/**
 * @brief Checks if stack is empty.
 * @param s Pointer to Stack.
 * @return true if empty, false otherwise.
 */
bool stack_is_empty(const Stack *s);

/**
 * @brief Checks if stack is full.
 * @param s Pointer to Stack.
 * @return true if full, false otherwise.
 */
bool stack_is_full(const Stack *s);

/**
 * @brief Pushes a new element onto the top of the stack.
 * @param s Pointer to Stack.
 * @param value Integer value to push.
 * @return true if successfully pushed, false if stack overflow.
 */
bool stack_push(Stack *s, int value);

/**
 * @brief Pops the top element from the stack.
 * @param s Pointer to Stack.
 * @param out_val Pointer to store popped value (can be NULL if caller doesn't need value).
 * @return true if successfully popped, false if stack underflow.
 */
bool stack_pop(Stack *s, int *out_val);

/**
 * @brief Inspects the top element without removing it.
 * @param s Pointer to Stack.
 * @param out_val Pointer to store top value.
 * @return true if successful, false if stack is empty.
 */
bool stack_peek(const Stack *s, int *out_val);

/**
 * @brief Returns the current number of elements in the stack.
 * @param s Pointer to Stack.
 * @return Count of elements in the stack.
 */
int stack_size(const Stack *s);

/**
 * @brief Prints stack contents from top to bottom.
 * @param s Pointer to Stack.
 */
void stack_print(const Stack *s);

#endif /* STACK_H */
