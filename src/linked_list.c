/**
 * @file linked_list.c
 * @brief Implementations of Singly Linked List operations.
 *
 * Part of the C Learning & DSA Toolkit.
 */

#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>

void list_init(LinkedList *list) {
    if (list == NULL) {
        return;
    }
    list->head = NULL;
    list->count = 0;
}

bool list_insert_beginning(LinkedList *list, int value) {
    if (list == NULL) {
        return false;
    }

    Node *new_node = (Node *)malloc(sizeof(Node));
    if (new_node == NULL) {
        return false;
    }

    new_node->data = value;
    new_node->next = list->head;
    list->head = new_node;
    list->count++;
    return true;
}

bool list_insert_end(LinkedList *list, int value) {
    if (list == NULL) {
        return false;
    }

    Node *new_node = (Node *)malloc(sizeof(Node));
    if (new_node == NULL) {
        return false;
    }

    new_node->data = value;
    new_node->next = NULL;

    if (list->head == NULL) {
        list->head = new_node;
    } else {
        Node *current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }

    list->count++;
    return true;
}

bool list_delete_value(LinkedList *list, int value) {
    if (list == NULL || list->head == NULL) {
        return false;
    }

    Node *current = list->head;
    Node *prev = NULL;

    while (current != NULL && current->data != value) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        return false;
    }

    if (prev == NULL) {
        list->head = current->next;
    } else {
        prev->next = current->next;
    }

    free(current);
    list->count--;
    return true;
}

int list_search(const LinkedList *list, int value) {
    if (list == NULL || list->head == NULL) {
        return -1;
    }

    Node *current = list->head;
    int index = 0;

    while (current != NULL) {
        if (current->data == value) {
            return index;
        }
        current = current->next;
        index++;
    }

    return -1;
}

int list_count(const LinkedList *list) {
    if (list == NULL) {
        return 0;
    }
    return list->count;
}

void list_display(const LinkedList *list) {
    if (list == NULL || list->head == NULL) {
        printf("List: [Empty]\n");
        return;
    }

    printf("List: ");
    Node *current = list->head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL (total: %d nodes)\n", list->count);
}

void list_free(LinkedList *list) {
    if (list == NULL) {
        return;
    }

    Node *current = list->head;
    while (current != NULL) {
        Node *temp = current->next;
        free(current);
        current = temp;
    }

    list->head = NULL;
    list->count = 0;
}
