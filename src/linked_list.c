#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include "include/linked_list.h"


/* --------------------- Creating and freeing --------------------- */

LinkedList* ds_create_linked_list(size_t const size) {
    LinkedList* list = malloc(sizeof(LinkedList));
    
    list->length = size;
    list->head = malloc(sizeof(Node));
    list->tail = malloc(sizeof(Node));

    list->head->data = -1;
    list->tail->data = -1;

    list->head->next = list->tail;
    list->tail->next = NULL;

    if (size != 0) {
        Node* t;
        Node* p;
        t = list->head;

        for (int i = 0; i < size; ++i) {
            p = malloc(sizeof(Node));
            p->data = 0;
            p->next = NULL;
            t->next = p;
            t = p;
        }

        p->next = list->tail;
    }

    return list;
}

void ds_free_linked_list(LinkedList* list) {
    Node* p = list->head->next;
    Node* t = list->head->next;
    for (unsigned int i = 0; i < list->length; ++i) {
        t = t->next;
        ds_free_node_linked_list(p);
        p = t;
    }
    ds_free_node_linked_list(list->head);
    ds_free_node_linked_list(list->tail);
    free(list);
}

void ds_free_node_linked_list(Node* node) {
    free(node);
}



/* --------------------- Operations --------------------- */

void ds_append_node_linked_list(LinkedList* list, int const value) {
    Node* t = malloc(sizeof(Node));
    t->data = value;
    t->next = NULL;

    Node* p = list->head;
    while (p->next != list->tail) {
        p = p->next;
    }

    p->next = t;
    t->next = list->tail;

    list->length++;
}

void ds_insert_node_linked_list(LinkedList* list, int const value, int const index) {
    assert(list != NULL);
    assert(index >= 0);
    assert(index <= list->length);

    Node* t = malloc(sizeof(Node));
    t->data = value;
    t->next = NULL;

    Node* p = list->head;
    for (int i = 0; i < index; ++i) {
        p = p->next;
    }

    t->next = p->next;
    p->next = t;
    
    list->length++;
}

void ds_delete_first_node_linked_list(LinkedList* list) {
    assert(list != NULL);

    Node* p = list->head->next;
    list->head->next = p->next;
    ds_free_node_linked_list(p);

    list->length--;
}

void ds_delete_node_linked_list(LinkedList* list, int const index) {
    assert(list != NULL);
    assert(index >= 0);
    assert(index <= list->length);

    Node* p = list->head;
    Node* t;
    for (int i = 0; i < index; ++i) {
        p = p->next;
    }
    t = p->next;
    p->next = t->next;

    ds_free_node_linked_list(t);

    list->length--;
}

void ds_set_value_linked_list(LinkedList* list, int const value, int const index) {
    assert(list != NULL);
    assert(index >= 0);
    assert(index <= list->length - 1);

    Node* p = list->head->next;
    for (int i = 0; i < index; ++i) {
        p = p->next;
    }
    p->data = value;
}

int ds_get_value_linked_list(LinkedList const * list, int const index) {
    assert(list != NULL);
    assert(index >= 0);
    assert(index <= list->length - 1);

    Node* p = list->head->next;
    for (int i = 0; i < index; ++i) {
        p = p->next;
    }
    
    return p->data;
}

int ds_sum_of_nodes_linked_list(LinkedList const * list) {
    Node* p = list->head->next;
    int sum = 0;

    while (p != list->tail) {
        sum += p->data;
        p = p->next;
    }
    return sum;
}

int ds_max_element_linked_list(LinkedList const * list) {
    Node* p = list->head->next;
    int max = p->data;

    while (p != list->tail) {
        if (p->data > max) {
            max = p->data;
        }
        p = p->next;
    }
    return max;
}

int ds_min_element_linked_list(LinkedList const * list) {
    Node* p = list->head->next;
    int min = p->data;

    while (p != list->tail) {
        if (p->data < min) {
            min = p->data;
        }
        p = p->next;
    }
    return min;
}

Node* ds_linear_search_linked_list(LinkedList const * list, int const value) {
    Node* p = list->head->next;

    while (p != list->tail) {
        if (p->data == value) {
            return p;
        }
        p = p->next;
    }
    return NULL;
}

Node* ds_linear_search_recursive_linked_list(LinkedList const * list, int const value) {
    Node* p = list->head;

    if (p == list->tail)
        return NULL;
    if (p->data == value)
        return p;
    return ds_linear_search_recursive_linked_list(p->next, value);
}


/* --------------------- Helpers --------------------- */

void ds_info_linked_list(LinkedList const * list) {
    printf("\n=========== INFO ============\n");
    printf("Length: %ld\n", list->length);

    Node* p = list->head->next;
    printf("HEAD -> ");
    while (p != list->tail) {
        if (p->next == list->tail) {
            printf("%d -> TAIL", p->data);
        } else {
            printf("%d -> ", p->data);
        }
        p = p->next;
    }
    if (list->length == 0) {
        printf("TAIL");
    }
    printf("\n=============================\n");
}

void ds_print_linked_list(LinkedList const * list) {
    Node* p = list->head->next;
    printf("HEAD -> ");
    while (p != list->tail) {
        if (p->next == list->tail) {
            printf("%d -> TAIL", p->data);
        } else {
            printf("%d -> ", p->data);
        }
        p = p->next;
    }
    if (list->length == 0) {
        printf("TAIL");
    }
    printf("\n");
}
