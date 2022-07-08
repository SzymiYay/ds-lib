#ifndef STACK_H
#define STACK_H

#include <stdint.h>
#include "dynamic_array.h"

typedef struct {
    size_t size;
    int top;
    DynamicArray* arr;
} Stack;

/* --------------------- Creating and freeing --------------------- */
Stack* ds_create_stack(size_t size);
void ds_free_stack(Stack* stack);


/* --------------------- Operations --------------------- */
bool ds_is_empty_stack(Stack const * stack);
bool ds_is_full_stack(Stack const * stack);
void ds_push_stack(Stack* stack, int value);
void ds_pop_stack(Stack* stack);
int ds_top_stack(Stack* stack);


/* --------------------- Helpers --------------------- */
void ds_info_stack(Stack const * stack);
void ds_print_stack(Stack const * stack);


#endif // STACK_H