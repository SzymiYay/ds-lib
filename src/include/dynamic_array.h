#ifndef DS_DYNAMIC_ARRAY_H
#define DS_DYNAMIC_ARRAY_H

#include <stdint.h>

typedef struct {
    size_t capacity;
    size_t length;
    int* data;
} DynamicArray;

/* --------------------- Creating and freeing --------------------- */

DynamicArray* ds_create_dynamic_array(size_t const capacity);
void ds_free(DynamicArray* arr);


/* --------------------- Operations --------------------- */
void ds_push(DynamicArray* arr, int const value);


/* --------------------- Helpers --------------------- */
void ds_info(DynamicArray const * arr);
void ds_print(DynamicArray const * arr);




#endif //DS_DYNAMIC_ARRAY_H