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

/* ------------------------------------------- Creating and freeing ------------------------------------------- */
/**
 * creates LinkedList structure
 * @param size length of the linked list
 * @return the pointer to the LinkedList structure
 */
LinkedList* ds_create_linked_list(size_t const size);

/**
 * frees all memory allocated for LinkedList structure
 * @param list the linked list
 * @return void
 */
void ds_free_linked_list(LinkedList* list);

/**
 * frees all memory allocated for the node
 * @param node the node
 * @return void
 */
void ds_free_node_linked_list(Node* node);


/* ------------------------------------------- Operations ------------------------------------------- */
/**
 * appends element at the end of the linked list
 * @param list the linked list
 * @param value the value of the new element
 * @return void
 */
void ds_append_node_linked_list(LinkedList* list, int const value);

/**
 * inserts node to the linked list at given index
 * @param list the linked list
 * @param value the value of the new element
 * @param index the index of the position
 * @return void
 */
void ds_insert_node_linked_list(LinkedList* list, int const value, int const index);

/**
 * deletes first node from the linked list
 * @param list the linked list
 * @return void
 */
void ds_delete_first_node_linked_list(LinkedList* list);

/**
 * deletes node from the linked list at given index
 * @param list the linked list
 * @param index the index of the element to be deleted
 * @return void
 */
void ds_delete_node_linked_list(LinkedList* list, int const index);

/**
 * sets value of the element at given index
 * @param list the linked list
 * @param value the value to be set
 * @param index the index of the element to be set
 * @return void
 */
void ds_set_value_linked_list(LinkedList* list, int const value, int const index);

/**
 * gets value of the element at given index
 * @param list the linked list
 * @param index the index of the element
 * @return value of the element
 */
int ds_get_value_linked_list(LinkedList const * list, int const index);

/**
 * sums all values of the nodes
 * @param list the linked list
 * @return the sum
 */
int ds_sum_of_nodes_linked_list(LinkedList const * list);

/**
 * find max element
 * @param list the linked list
 * @return the max value
 */
int ds_max_element_linked_list(LinkedList const * list);

/**
 * find min element
 * @param list the linked list
 * @return the min value
 */
int ds_min_element_linked_list(LinkedList const * list);

/**
 * goes through linked list using linear search alogrithm
 * @param list the linked list
 * @return the node
 */
Node* ds_linear_search_linked_list(LinkedList const * list, int const value);

/**
 * goes through linked list using linear search recursive alogrithm
 * @param list the linked list
 * @return the node
 */
Node* ds_linear_search_recursive_linked_list(LinkedList const * list, int const value);


/* ------------------------------------------- Helpers ------------------------------------------- */
/**
 * prints all information about the linked list
 * @param list the linked list
 * @return void
 */
void ds_info_linked_list(LinkedList const * list);

/**
 * prints the linked list
 * @param list the linked list
 * @return void
 */
void ds_print_linked_list(LinkedList const * list);

#endif //LINKED_LIST_H