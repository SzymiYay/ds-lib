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
void ds_free_dynamic_array(DynamicArray* arr);
void ds_clear_dynamic_array(DynamicArray* arr);
void ds_allocate_more_memory_dynamic_array(DynamicArray* arr);


/* --------------------- Operations --------------------- */
int ds_get_value_dynamic_array(DynamicArray const * arr, int const index);
void ds_set_value_dynamic_array(DynamicArray* arr, int const value, int const index);
int ds_sum_of_elements_dynamic_array(DynamicArray const * arr);
double ds_average_of_elements_dynamic_array(DynamicArray const * arr);
int ds_max_dynamic_array(DynamicArray const * arr);
int ds_min_dynamic_array(DynamicArray const * arr);


void ds_push_dynamic_array(DynamicArray* arr, int const value);
void ds_insert_at_index_dynamic_array(DynamicArray* arr, int const value, int const index);
void ds_insert_to_sorted_dynamic_array(DynamicArray* arr, int const value);
void ds_pop_dynamic_array(DynamicArray* arr);
void ds_remove_from_index_dynamic_array(DynamicArray* arr, int const index);

void ds_copy_dynamic_array(DynamicArray* from, DynamicArray* to);
int ds_linear_search_dynamic_array(DynamicArray const * arr, int const value);
int ds_binary_search_dynamic_array(DynamicArray const * arr, int const value);
int ds_binary_search_recursive_dynamic_array(DynamicArray const * arr, int low, int high, int const value);
void ds_reverse_dynamic_array(DynamicArray* arr);
bool ds_is_sorted_dynamic_array(DynamicArray const * arr);
void ds_merge_two_arrays_dynamic_array(DynamicArray const * arr1, DynamicArray const * arr2);
void ds_bubble_sort_dynamic_array(DynamicArray* arr);


/* --------------------- Helpers --------------------- */
void ds_info_dynamic_array(DynamicArray const * arr);
void ds_print_dynamic_array(DynamicArray const * arr);
void ds_swap(int* x, int* y); 




#endif //DS_DYNAMIC_ARRAY_H