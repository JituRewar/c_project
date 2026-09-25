/**
 * @file stack.c
 * @brief Implementations of array-based Stack operations.
 *
 * Part of the C Learning & DSA Toolkit.
 */

#include "stack.h"
#include <stdio.h>

void stack_init(Stack *s) {
    if (s == NULL) {
        return;
    }
    s->top = -1;
}

bool stack_is_empty(const Stack *s) {
    if (s == NULL) {
        return true;
    }
    return (s->top == -1);
}

bool stack_is_full(const Stack *s) {
    if (s == NULL) {
        return false;
    }
    return (s->top >= STACK_MAX_CAPACITY - 1);
}

bool stack_push(Stack *s, int value) {
    if (s == NULL || stack_is_full(s)) {
        return false;
    }
    s->top++;
    s->data[s->top] = value;
    return true;
}

bool stack_pop(Stack *s, int *out_val) {
    if (s == NULL || stack_is_empty(s)) {
        return false;
    }
    if (out_val != NULL) {
        *out_val = s->data[s->top];
    }
    s->top--;
    return true;
}

bool stack_peek(const Stack *s, int *out_val) {
    if (s == NULL || stack_is_empty(s) || out_val == NULL) {
        return false;
    }
    *out_val = s->data[s->top];
    return true;
}

int stack_size(const Stack *s) {
    if (s == NULL) {
        return 0;
    }
    return s->top + 1;
}

void stack_print(const Stack *s) {
    if (s == NULL || stack_is_empty(s)) {
        printf("Stack: [Empty]\n");
        return;
    }
    printf("Stack (top -> bottom): ");
    for (int i = s->top; i >= 0; i--) {
        printf("%d%s", s->data[i], (i == 0) ? "" : " -> ");
    }
    printf("\n");
}
