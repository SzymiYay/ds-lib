#ifndef QUEUE_H
#define QUEUE_H

#include <stdint.h>
#include "linked_list.h"

// typedef struct Node {
//     struct Node* next;
//     int data;
// } Node;

typedef struct {
    Node* front;
    Node* rear;
    size_t length;
} Queue;

/* ------------------------------------------- Creating and freeing ------------------------------------------- */
/**
 * creates queue
 * @param size length of the queue
 * @return the pointer to the Queue strucure
 */
Queue* ds_create_queue(size_t const size);

/**
 * frees all memory allocated for the queue
 * @param queue the queue
 * @return void
 */
void ds_free_queue(Queue* queue);

/**
 * frees memory allocated forthe node
 * @param node the node to be freed
 * @return void
 */
void ds_free_node_queue(Node* node);

/* ------------------------------------------- Operations ------------------------------------------- */
/**
 * enqueue element at the end
 * @param queue the queue
 * @param value the value of the element to be added
 * @return void
 */
void ds_enqueue(Queue* queue, int const value);

/**
 * dequeue element at the front
 * @param queue the queue
 * @return void
 */
void ds_dequeue(Queue* queue);

/* ------------------------------------------- Helpers ------------------------------------------- */
/**
 * prints all information about queue
 * @param queue the queue
 * @return void
 */
void ds_info_queue(Queue const * queue);

/**
 * prints the queue
 * @param queue the queue
 * @return void
 */
void ds_print_queue(Queue const * queue);

#endif // QUEUE_H