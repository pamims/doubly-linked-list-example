#include "linked_list.h"

/* - STRUCTS - */
// Contains the data and pointers to its adjacent nodes
struct node {
    DATA_TYPE value;
    struct node *next, *previous;
};

// The list accessor containing pointers to the first and last nodes
struct list {
    struct node *first, *last;
    size_t size;
};


/* - PRIVATE FUNCTIONS - */
// only used internally to this .c file. not intended for end user to see.
// Find the fastest route to the index location and travel to node at the index.
// Return a pointer to that node.
Node *node_travel(List *list, size_t index) {
    Node *temp;
    if (index > list->size / 2) {
        temp = list->last;
        for (int i = list->size - index - 1; i > 0; i--) {
            temp = temp->previous;
        }
    } else {
        temp = list->first;
        for (int i = index; i > 0; i--) {
            temp = temp->next;
        }
    }
    return temp;
}

// Use in the bubble sort algorithm to swap the values held by two nodes.
void value_swap(DATA_TYPE *a, DATA_TYPE *b) {
    DATA_TYPE temp = *a;
    *a = *b;
    *b = temp;
    return;
}


/* - LIST FUNCTIONS - */
// Return a pointer to a new list accessor
List *make_list() {
    List *list = (List *)malloc(sizeof(List));
    if (!list) return NULL;
    list->first = list->last = NULL;
    list->size = 0;
    return list;
}

// Add a node at the end of the list with the given value
bool list_add(List *list, DATA_TYPE value) {
    if (!list) return false;
    Node *node = (Node *)malloc(sizeof(Node));
    if (!node) return false;
    // set node values
    node->value = value;
    node->previous = list->last;
    node->next = NULL;
    // update list values
    if (list->size) {
        list->last->next = node;
    } else {
        list->first = node;
    }
    list->last = node;
    list->size++;
    return true;
}

// Insert a node into the list at the given index with the given value.
bool list_insert(List *list, DATA_TYPE value, size_t index) {
    if (!list || index > list->size) return false;
    if (!list->size || list->size == index) {
        return list_add(list, value);
    }
    Node *node = (Node *)malloc(sizeof(Node));
    if (!node) return false;
    // find fastest route to the index location and travel to node currently at
    // the index
    Node *temp = node_travel(list, index);
    // set node values
    node->value = value;
    node->previous = temp->previous;
    node->next = temp;
    // insert node into the list structure:
    node->previous->next = node;
    node->next->previous = node;
    // increase list size
    list->size++;
    // done
    return true;
}

// Remove the node at the given index and frees its memory
bool list_remove(List *list, size_t index) {
    if (!list || index >= list->size) return false;
    // find fastest route to the index location and travel to node currently at
    // the index
    Node *temp = node_travel(list, index);
    // reconnect list to bypass the node being removed
    temp->next->previous = temp->previous;
    temp->previous->next = temp->next;
    // free the node and decrement the list size
    free(temp);
    list->size--;
    return true;
}

// Return the number of elements in the list
int list_size(List *list) {
    return list ? list->size : -1;
}

// need to set up error handling for this. right now returns 0 on error which
// falsely indicates an empty list when the list might be NULL or index invalid
// Return the value held at the given index
DATA_TYPE list_get_value(List *list, size_t index) {
    if (!list || index >= list->size) return (DATA_TYPE)0;
    return node_travel(list, index)->value;
}

// Free all of the list's memory including all of its nodes' memory
bool destroy_list(List *list) {
    if (!list) return false;
    Node *temp = list->first;
    Node *temp_next = temp;
    while (temp) {
        temp_next = temp->next;
        free(temp);
        temp = temp_next;
    }
    free(list);
    return true;
}


/* - SORT FUNCTIONS - */
// Perform a bubble sort algorithm on the list to order its values low to high
bool list_bubble_sort(List *list) {
    if (!list) return false;
    Node *current;
    int max_unsorted_index;
    for (int i = list->size; i > 1; i = max_unsorted_index) {
        max_unsorted_index = 0;
        current = list->first;
        for (int j = 1; j < i; j++) {
            if (current->value > current->next->value) {
                value_swap(&current->value, &current->next->value);
                max_unsorted_index = j;
            }
            current = current->next;
        }
    }
    return true;
}
