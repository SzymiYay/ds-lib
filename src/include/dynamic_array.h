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
void ds_clear(DynamicArray* arr);
void ds_allocate_more_memory(DynamicArray* arr);


/* --------------------- Operations --------------------- */
int ds_get_value(DynamicArray const * arr, int const index);
void ds_set_value(DynamicArray* arr, int const value, int const index);
int ds_sum_of_elements(DynamicArray const * arr);
double ds_average_of_elements(DynamicArray const * arr);
int ds_max(DynamicArray const * arr);
int ds_min(DynamicArray const * arr);


void ds_push(DynamicArray* arr, int const value);
void ds_insert_at_index(DynamicArray* arr, int const value, int const index);
void ds_insert_to_sorted_array(DynamicArray* arr, int const value);
void ds_pop(DynamicArray* arr, int const value);
void ds_remove_from_index(DynamicArray* arr, int const index);

void ds_copy(DynamicArray* from, DynamicArray* to);
int ds_linear_search(DynamicArray const * arr, int const value);
int ds_binary_search(DynamicArray const * arr, int const value);
int ds_binary_search_recursive(DynamicArray const * arr, int low, int high, int const value);
void ds_reverse_array(DynamicArray* arr);
bool ds_is_sorted(DynamicArray const * arr);
void ds_merge_two_arrays(DynamicArray const * arr1, DynamicArray const * arr2);
void ds_bubble_sort(DynamicArray* arr);


/* --------------------- Helpers --------------------- */
void ds_info(DynamicArray const * arr);
void ds_print(DynamicArray const * arr);
void ds_swap(int* x, int* y); 




#endif //DS_DYNAMIC_ARRAY_H