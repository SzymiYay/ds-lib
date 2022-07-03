#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include "include/dynamic_array.h"


/* --------------------- Creating and freeing --------------------- */

DynamicArray* ds_create_dynamic_array(size_t const capacity) {
    DynamicArray* arr = malloc(sizeof(DynamicArray));

    if (!arr) {
        exit(0);
    }

    arr->capacity = capacity;
    arr->length = 0;
    arr->data = malloc(capacity * sizeof(int));

    for (unsigned int i = 0; i < arr->capacity; ++i) {
        arr->data[i] = 0;
    }

    return arr;
}

void ds_free(DynamicArray* arr) {
    free(arr->data);
    free(arr);
}



/* --------------------- Operations --------------------- */

void ds_push(DynamicArray* arr, int const value) {
    if (arr->length == arr->capacity) {
        int capacity = arr->capacity * 2;

        int* tmp = malloc(capacity * sizeof(int));
        for (unsigned int i = 0; i < capacity; ++i) {
            if (i < arr->length) {
                tmp[i] = arr->data[i];
            } else {
                tmp[i] = 0;
            }   
        }

        free(arr->data);
        arr->data = tmp;
        arr->capacity = capacity;
    }
    arr->data[arr->length] = value;
    arr->length++;
}

void ds_pop(DynamicArray* arr, int value) {
    if (arr->length > 0) {
        arr->length--;
        arr->data[arr->length] = 0;
    }
    if (arr->capacity > 1 && arr->length == arr->capacity / 4) {
        int capacity = arr->capacity / 2;

        int* tmp = malloc(capacity * sizeof(int));
        for (unsigned int i = 0; i < capacity; ++i) {
            if (i < arr->length) {
                tmp[i] = arr->data[i];
            } else {
                tmp[i] = 0;
            }   
        }

        free(arr->data);
        arr->data = tmp;
        arr->capacity = capacity;
    }
}

void ds_copy(DynamicArray* from, DynamicArray* to) {
    to->capacity = from->capacity;
    to->length = from->length;
    for (unsigned int i = 0; i < from->length; ++i) {
        to->data[i] = from->data[i];
    }
}



/* --------------------- Helpers --------------------- */

void ds_info(DynamicArray const * arr) {
    printf("\n=========== INFO ============\n");
    printf("Capacity: %ld\n", arr->capacity);
    printf("Length: %ld\n", arr->length);

    printf("Whole DynamicArray = [");
    for (unsigned int i = 0; i < arr->capacity; ++i) {
        if (i == arr->capacity - 1) {
            printf("%d", arr->data[i]);
        } else {
            printf("%d, ", arr->data[i]);
        }
    }
    printf("]\n");

    printf("DynamicArray = [");
    for (unsigned int i = 0; i < arr->length; ++i) {
        if (i == arr->length - 1) {
            printf("%d", arr->data[i]);
        } else {
            printf("%d, ", arr->data[i]);
        }
    }
    printf("]\n");
    printf("=============================\n");
}

void ds_print(DynamicArray const * arr) {
    printf("DynamicArray = [");
    for (unsigned int i = 0; i < arr->length; ++i) {
        if (i == arr->length - 1) {
            printf("%d", arr->data[i]);
        } else {
            printf("%d, ", arr->data[i]);
        }
    }
    printf("]\n");
}