#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include "include/queue.h"



/* --------------------- Creating and freeing --------------------- */

Queue* ds_create_queue(size_t const size) {
    Queue* queue = malloc(sizeof(Queue));
    
    queue->length = size;
    queue->front = malloc(sizeof(Node));
    queue->rear = malloc(sizeof(Node));

    queue->front->data = -1;
    queue->rear->data = -1;

    queue->front->next = queue->rear;
    queue->rear->next = NULL;

    if (size != 0) {
        Node* t;
        Node* p;
        t = queue->front;

        for (int i = 0; i < size; ++i) {
            p = malloc(sizeof(Node));
            p->data = 0;
            p->next = NULL;
            t->next = p;
            t = p;
        }

        p->next = queue->rear;
    }

    return queue;
}

void ds_free_queue(Queue* queue) {
    Node* p = queue->front->next;
    Node* t = queue->front->next;
    for (unsigned int i = 0; i < queue->length; ++i) {
        t = t->next;
        ds_free_node_queue(p);
        p = t;
    }
    ds_free_node_queue(queue->front);
    ds_free_node_queue(queue->rear);
    free(queue);
}

void ds_free_node_queue(Node* node) {
    free(node);
}


/* --------------------- Operations --------------------- */

void ds_enqueue(Queue* queue, int const value) {
    Node* t = malloc(sizeof(Node));
    t->data = value;
    t->next = NULL;

    Node* p = queue->front;
    while (p->next != queue->rear) {
        p = p->next;
    }

    p->next = t;
    t->next = queue->rear;

    queue->length++;
}

void ds_dequeue(Queue* queue) {
    assert(queue != NULL);

    Node* p = queue->front->next;
    queue->front->next = p->next;
    ds_free_node_queue(p);

    queue->length--;
}




/* --------------------- Helpers --------------------- */

void ds_info_queue(Queue const * queue) {
    printf("\n=========== INFO ============\n");
    printf("Length: %ld\n", queue->length);

    Node* p = queue->front->next;
    printf("FRONT <- ");
    while (p != queue->rear) {
        if (p->next == queue->rear) {
            printf("%d <- REAR", p->data);
        } else {
            printf("%d <- ", p->data);
        }
        p = p->next;
    }
    if (queue->length == 0) {
        printf("REAR");
    }
    printf("\n=============================\n");
}

void ds_print_queue(Queue const * queue) {
    Node* p = queue->front->next;
    printf("FRONT <- ");
    while (p != queue->rear) {
        if (p->next == queue->rear) {
            printf("%d <- REAR", p->data);
        } else {
            printf("%d <- ", p->data);
        }
        p = p->next;
    }
    if (queue->length == 0) {
        printf("REAR");
    }
    printf("\n");
}