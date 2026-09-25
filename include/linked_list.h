/**
 * @file linked_list.h
 * @brief Singly Linked List data structure implementation.
 *
 * Part of the C Learning & DSA Toolkit.
 */

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdbool.h>

/**
 * @brief Node in a singly linked list.
 */
typedef struct Node {
    int data;
    struct Node *next;
} Node;

/**
 * @brief Singly linked list container tracking head pointer and node count.
 */
typedef struct {
    Node *head;
    int count;
} LinkedList;

/**
 * @brief Initializes an empty linked list.
 * @param list Pointer to LinkedList.
 */
void list_init(LinkedList *list);

/**
 * @brief Inserts a new node at the beginning of the list.
 * @param list Pointer to LinkedList.
 * @param value Integer value to insert.
 * @return true if memory allocation succeeded, false otherwise.
 */
bool list_insert_beginning(LinkedList *list, int value);

/**
 * @brief Inserts a new node at the end of the list.
 * @param list Pointer to LinkedList.
 * @param value Integer value to insert.
 * @return true if memory allocation succeeded, false otherwise.
 */
bool list_insert_end(LinkedList *list, int value);

/**
 * @brief Deletes the first node containing the specified value.
 * @param list Pointer to LinkedList.
 * @param value Value to remove.
 * @return true if node was found and removed, false if not found.
 */
bool list_delete_value(LinkedList *list, int value);

/**
 * @brief Searches for a value in the list.
 * @param list Pointer to LinkedList.
 * @param value Value to search for.
 * @return 0-based index of first occurrence, or -1 if not found.
 */
int list_search(const LinkedList *list, int value);

/**
 * @brief Returns the total number of nodes in the list.
 * @param list Pointer to LinkedList.
 * @return Node count.
 */
int list_count(const LinkedList *list);

/**
 * @brief Prints the linked list elements in order (e.g. 10 -> 20 -> 30 -> NULL).
 * @param list Pointer to LinkedList.
 */
void list_display(const LinkedList *list);

/**
 * @brief Frees all nodes in the linked list and resets it to empty.
 * @param list Pointer to LinkedList.
 */
void list_free(LinkedList *list);

#endif /* LINKED_LIST_H */
