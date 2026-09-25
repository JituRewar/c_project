/**
 * @file queue.c
 * @brief Implementations of array-based Circular Queue operations.
 *
 * Part of the C Learning & DSA Toolkit.
 */

#include "queue.h"
#include <stdio.h>

void queue_init(Queue *q) {
    if (q == NULL) {
        return;
    }
    q->front = 0;
    q->rear = 0;
    q->size = 0;
}

bool queue_is_empty(const Queue *q) {
    if (q == NULL) {
        return true;
    }
    return (q->size == 0);
}

bool queue_is_full(const Queue *q) {
    if (q == NULL) {
        return false;
    }
    return (q->size >= QUEUE_MAX_CAPACITY);
}

bool queue_enqueue(Queue *q, int value) {
    if (q == NULL || queue_is_full(q)) {
        return false; /* Queue overflow or invalid pointer */
    }
    q->data[q->rear] = value;
    q->rear = (q->rear + 1) % QUEUE_MAX_CAPACITY;
    q->size++;
    return true;
}

bool queue_dequeue(Queue *q, int *out_val) {
    if (q == NULL || queue_is_empty(q)) {
        return false; /* Queue underflow or invalid pointer */
    }
    if (out_val != NULL) {
        *out_val = q->data[q->front];
    }
    q->front = (q->front + 1) % QUEUE_MAX_CAPACITY;
    q->size--;
    return true;
}

bool queue_front(const Queue *q, int *out_val) {
    if (q == NULL || queue_is_empty(q) || out_val == NULL) {
        return false;
    }
    *out_val = q->data[q->front];
    return true;
}

int queue_size(const Queue *q) {
    if (q == NULL) {
        return 0;
    }
    return q->size;
}

void queue_print(const Queue *q) {
    if (q == NULL || queue_is_empty(q)) {
        printf("Queue: [Empty]\n");
        return;
    }
    printf("Queue (front -> rear): ");
    for (int i = 0; i < q->size; i++) {
        int idx = (q->front + i) % QUEUE_MAX_CAPACITY;
        printf("%d%s", q->data[idx], (i == q->size - 1) ? "" : " -> ");
    }
    printf("\n");
}
