#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdint.h>

typedef struct Node {
    struct Node* next;
    int data;
} Node;

typedef struct {
    Node* head;
    Node* tail;
    size_t length;
} LinkedList;

/* --------------------- Creating and freeing --------------------- */
LinkedList* ds_create_linked_list(size_t const size);
void ds_free_linked_list(LinkedList* list);
void ds_free_node_linked_list(Node* node);


/* --------------------- Operations --------------------- */
void ds_append_node_linked_list(LinkedList* list, int const value);
void ds_insert_node_linked_list(LinkedList* list, int const value, int const index);
void ds_delete_first_node_linked_list(LinkedList* list);
void ds_delete_node_linked_list(LinkedList* list, int const index);
void ds_set_value_linked_list(LinkedList* list, int const value, int const index);
int ds_get_value_linked_list(LinkedList const * list, int const index);
int ds_sum_of_nodes_linked_list(LinkedList const * list);
int ds_max_element_linked_list(LinkedList const * list);
int ds_min_element_linked_list(LinkedList const * list);
Node* ds_linear_search_linked_list(LinkedList const * list, int const value);
Node* ds_linear_search_recursive_linked_list(LinkedList const * list, int const value);


/* --------------------- Helpers --------------------- */
void ds_info_linked_list(LinkedList const * list);
void ds_print_linked_list(LinkedList const * list);

#endif //LINKED_LIST_H