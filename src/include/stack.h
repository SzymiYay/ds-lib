#ifndef STACK_H
#define STACK_H

#include <stdint.h>
#include "dynamic_array.h"

typedef struct {
    size_t size;
    int top;
    DynamicArray* arr;
} Stack;

/* ------------------------------------------- Creating and freeing ------------------------------------------- */
/**
 * creates Stack strucure
 * @param size the size of the stack
 * @return pointer to the Stack strucure
 */
Stack* ds_create_stack(size_t size);

/**
 * frees all memory allocated for stack strucure
 * @param stack the stack
 * @return void
 */
void ds_free_stack(Stack* stack);


/* ------------------------------------------- Operations ------------------------------------------- */
/**
 * check if the stack is empty
 * @param stack the stack
 * @return true if the stack is empty
 */
bool ds_is_empty_stack(Stack const * stack);

/**
 * checks if the stack is full
 * @param stack the stack
 * @return true if the stack is full
 */
bool ds_is_full_stack(Stack const * stack);

/**
 * pushes the element at the top of the stack
 * @param stack the stack
 * @param value the value of the new element
 * @return void
 */
void ds_push_stack(Stack* stack, int value);

/**
 * removes the element at the top of the stack
 * @param stack the stack
 * @return void
 */
void ds_pop_stack(Stack* stack);

/**
 * gives position of the top pointer - gives information about number of elements 
 * @param stack the stack
 * @return void
 */
int ds_top_stack(Stack* stack);


/* ------------------------------------------- Helpers ------------------------------------------- */
/**
 * prints all information about the stack
 * @param stack the stack
 * @return void
 */
void ds_info_stack(Stack const * stack);

/**
 * prints the stack
 * @param stack the stack
 * @return void
 */
void ds_print_stack(Stack const * stack);


#endif // STACK_H