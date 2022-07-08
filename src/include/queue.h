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

/* --------------------- Creating and freeing --------------------- */
Queue* ds_create_queue(size_t const size);
void ds_free_queue(Queue* queue);
void ds_free_node_queue(Node* node);

/* --------------------- Operations --------------------- */
void ds_enqueue(Queue* queue, int const value);
void ds_dequeue(Queue* queue);

/* --------------------- Helpers --------------------- */
void ds_info_queue(Queue const * queue);
void ds_print_queue(Queue const * queue);

#endif // QUEUE_H