#ifndef DS_DYNAMIC_ARRAY_H
#define DS_DYNAMIC_ARRAY_H

#include <stdint.h>

typedef struct {
    size_t capacity;
    size_t length;
    int* data;
} DynamicArray;

/* ------------------------------------------- Creating and freeing ------------------------------------------- */
/**
 * creates dynamic array
 * @param capacity the capacity of created array
 * @return the pointer to DynamicArray structure
 */
DynamicArray* ds_create_dynamic_array(size_t const capacity);

/**
 * frees all alocated memory
 * @param arr the array
 * @return void
 */
void ds_free_dynamic_array(DynamicArray* arr);

/**
 * sets all elements as zero
 * @param arr the array
 * @return void
 */
void ds_clear_dynamic_array(DynamicArray* arr);

/**
 * doubles and reallocates memory for the array
 * @param arr the array
 * @return void
 */
void ds_allocate_more_memory_dynamic_array(DynamicArray* arr);


/* ------------------------------------------- Operations ------------------------------------------- */
/**
 * gets value at given index
 * @param arr the array
 * @param index the index of the element
 * @return the value of the element at given index
 */
int ds_get_value_dynamic_array(DynamicArray const * arr, int const index);

/**
 * sets value at given index
 * @param arr the array
 * @param value the value to be set
 * @param index the index of the element to be set
 * @return void
 */
void ds_set_value_dynamic_array(DynamicArray* arr, int const value, int const index);

/**
 * sums all values of the elements
 * @param arr the array
 * @return the sum of the elements
 */
int ds_sum_of_elements_dynamic_array(DynamicArray const * arr);

/**
 * sums all values of the elements and divide by length
 * @param arr the array
 * @return the average of the elements
 */
double ds_average_of_elements_dynamic_array(DynamicArray const * arr);

/**
 * goes through all elements and finds maximum
 * @param arr the array
 * @return max element
 */
int ds_max_dynamic_array(DynamicArray const * arr);

/**
 * goes through all elements and finds minimum
 * @param arr the array
 * @return min element
 */
int ds_min_dynamic_array(DynamicArray const * arr);

/**
 * push given value at the end of the array
 * @param arr the array
 * @param value the value to be added
 * @return void
 */
void ds_push_dynamic_array(DynamicArray* arr, int const value);

/**
 * inserts the element at given index
 * @param arr the array
 * @param value the value of the new element
 * @param index the index of the position to be added
 * @return void
 */
void ds_insert_at_index_dynamic_array(DynamicArray* arr, int const value, int const index);

/**
 * inserts element in correct order
 * @param arr the array
 * @param value the value of the new element
 * @return void
 */
void ds_insert_to_sorted_dynamic_array(DynamicArray* arr, int const value);

/**
 * removes the last element of the array
 * @param arr the array
 * @return void
 */
void ds_pop_dynamic_array(DynamicArray* arr);

/**
 * removes the element at given index
 * @param arr the array
 * @param index the index of element to be removed
 * @return void
 */
void ds_remove_from_index_dynamic_array(DynamicArray* arr, int const index);

/**
 * copies all information and data from first array to second
 * @param arr the array copying from
 * @param arr the array copying to
 * @return void
 */
void ds_copy_dynamic_array(DynamicArray* from, DynamicArray* to);

/**
 * searchs for the given element using linear algorithm
 * @param arr the array
 * @param value the value of searching element
 * @return the value of found element
 */
int ds_linear_search_dynamic_array(DynamicArray const * arr, int const value);

/**
 * searchs for the given element using binary search algorithm
 * @param arr the array
 * @param value the value of searching element
 * @return the value of found element
 */
int ds_binary_search_dynamic_array(DynamicArray const * arr, int const value);

/**
 * searchs for the given element using binary search algorithm recursive
 * @param arr the array
 * @param low the low element of the searched array
 * @param high the high element of the searched array
 * @param value the value of searching element
 * @return the value of found element
 */
int ds_binary_search_recursive_dynamic_array(DynamicArray const * arr, int low, int high, int const value);

/**
 * reverses the array
 * @param arr the array
 * @return void
 */
void ds_reverse_dynamic_array(DynamicArray* arr);

/**
 * checks if array is sorted
 * @param arr the array
 * @return true if array is sorted
 */
bool ds_is_sorted_dynamic_array(DynamicArray const * arr);

/**
 * merges two arrays into one
 * @param arr1 the array
 * @param arr2 the array
 * @return void
 */
void ds_merge_two_arrays_dynamic_array(DynamicArray const * arr1, DynamicArray const * arr2);

/**
 * sorts the array using bubble sort algorithm
 * @param arr the array
 * @return void
 */
void ds_bubble_sort_dynamic_array(DynamicArray* arr);


/* ------------------------------------------- Helpers ------------------------------------------- */
/**
 * prints all information about the array
 * @param arr the array
 * @return void
 */
void ds_info_dynamic_array(DynamicArray const * arr);

/**
 * prints the array
 * @param arr the array
 * @return void
 */
void ds_print_dynamic_array(DynamicArray const * arr);

/**
 * swaps two elements
 * @param x the first element
 * @param y the second element
 * @return void
 */
void ds_swap(int* x, int* y); 




#endif //DS_DYNAMIC_ARRAY_H