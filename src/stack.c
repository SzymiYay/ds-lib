#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include "include/stack.h"
#include "include/dynamic_array.h"


/* --------------------- Creating and freeing --------------------- */

Stack* ds_create_stack(size_t size) {
    Stack* stack = malloc(sizeof(Stack));

    if (!stack) {
        exit(0);
    }

    stack->size = size;
    stack->top = -1;
    stack->arr = ds_create_dynamic_array(size);
    
    return stack;
}

void ds_free_stack(Stack* stack) {
    ds_free_dynamic_array(stack->arr);
    free(stack);
}



/* --------------------- Operations --------------------- */

bool ds_is_empty_stack(Stack const * stack) {
    if (stack->top == -1) {
        return true;
    }
    return false;
}

bool ds_is_full_stack(Stack const * stack) {
    if (stack->top == stack->size - 1) {
        return true;
    }
    return false;
}

void ds_push_stack(Stack* stack, int value) {
    if (ds_is_full_stack(stack)) {
        printf("Stack overflow!\n");
    } else {
        stack->top++;
        ds_push_dynamic_array(stack->arr, value);
    }
}

void ds_pop_stack(Stack* stack) {
    if (ds_is_empty_stack(stack)) {
        printf("Stack underflow!\n");
    } else {
        stack->top--;
        ds_pop_dynamic_array(stack->arr);
    }
}

int ds_top_stack(Stack* stack) {
    if (ds_is_empty_stack(stack)) {
        printf("Stack is empty!\n");
        return -1;
    } else {
        return ds_get_value_dynamic_array(stack->arr, stack->top);
    }
}



/* --------------------- Helpers --------------------- */

void ds_info_stack(Stack const * stack) {
    printf("\n=========== INFO ============\n");
    printf("Size: %ld\n", stack->size);
    printf("Top: %d\n", stack->top);
    printf("Stack: Bottom => ");
    for (int i = 0; i < stack->size; ++i) {
        if (i > stack->top) {
            printf("None => ");
        } else {
            printf("%d => ", ds_get_value_dynamic_array(stack->arr, i));
        }
    }
    printf("Top\n");
    printf("=============================\n");
}

void ds_print_stack(Stack const * stack) {
    printf("Stack = Bottom => ");
    for (int i = 0; i < stack->size; ++i) {
        if (i > stack->top) {
            printf("None => ");
        } else {
            printf("%d => ", ds_get_value_dynamic_array(stack->arr, i));
        }
    }
    printf("Top\n");
}