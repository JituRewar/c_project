/**
 * @file queue.h
 * @brief Array-based Circular Queue (FIFO - First-In, First-Out) implementation.
 *
 * Part of the C Learning & DSA Toolkit.
 */

#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

#define QUEUE_MAX_CAPACITY 100

/**
 * @brief Structure representing a fixed-size circular integer queue.
 */
typedef struct {
    int data[QUEUE_MAX_CAPACITY];
    int front;  /**< Index of the front element */
    int rear;   /**< Index where next element will be enqueued */
    int size;   /**< Current number of elements in queue */
} Queue;

/**
 * @brief Initializes an empty queue.
 * @param q Pointer to Queue.
 */
void queue_init(Queue *q);

/**
 * @brief Checks if queue is empty.
 * @param q Pointer to Queue.
 * @return true if empty, false otherwise.
 */
bool queue_is_empty(const Queue *q);

/**
 * @brief Checks if queue is full.
 * @param q Pointer to Queue.
 * @return true if full, false otherwise.
 */
bool queue_is_full(const Queue *q);

/**
 * @brief Adds an element to the rear of the queue.
 * @param q Pointer to Queue.
 * @param value Integer value to enqueue.
 * @return true if successful, false if queue overflow.
 */
bool queue_enqueue(Queue *q, int value);

/**
 * @brief Removes an element from the front of the queue.
 * @param q Pointer to Queue.
 * @param out_val Pointer to store dequeued value (can be NULL).
 * @return true if successful, false if queue underflow.
 */
bool queue_dequeue(Queue *q, int *out_val);

/**
 * @brief Inspects the front element without removing it.
 * @param q Pointer to Queue.
 * @param out_val Pointer to store front value.
 * @return true if successful, false if queue is empty.
 */
bool queue_front(const Queue *q, int *out_val);

/**
 * @brief Returns the current number of elements in the queue.
 * @param q Pointer to Queue.
 * @return Element count.
 */
int queue_size(const Queue *q);

/**
 * @brief Prints queue contents from front to rear.
 * @param q Pointer to Queue.
 */
void queue_print(const Queue *q);

#endif /* QUEUE_H */
