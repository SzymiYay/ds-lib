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

void ds_free_dynamic_array(DynamicArray* arr) {
    free(arr->data);
    free(arr);
}

void ds_clear_dynamic_array(DynamicArray* arr) {
    for (unsigned int i = 0; i < arr->length; ++i) {
        arr->data[i] = 0;
    }
    arr->length = 0;
}

void ds_allocate_more_memory_dynamic_array(DynamicArray* arr) {
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



/* --------------------- Operations --------------------- */

int ds_get_value_dynamic_array(DynamicArray const * arr, int const index) {
    if (index >= 0 && index <= arr->length) {
        return arr->data[index];
    }
    return -1;
}

void ds_set_value_dynamic_array(DynamicArray* arr, int const value, int const index) {
    if (index >= 0 && index <= arr->length) {
        arr->data[index] = value;
    }
}

int ds_sum_of_elements_dynamic_array(DynamicArray const * arr) {
    int sum = 0;
    for (unsigned int i = 0; i < arr->length; ++i) {
        sum += arr->data[i];
    }
    return sum;
}

double ds_average_of_elements_dynamic_array(DynamicArray const * arr) {
    return ds_sum_of_elements_dynamic_array(arr) / arr->length;
}

int ds_max_dynamic_array(DynamicArray const * arr) {
    int max = arr->data[0];
    for (unsigned int i = 0; i < arr->length; ++i) {
        if (arr->data[i] > max) {
            max = arr->data[i];
        }
    }
    return max;
}

int ds_min_dynamic_array(DynamicArray const * arr) {
    int min = arr->data[0];
    for (unsigned int i = 0; i < arr->length; ++i) {
        if (arr->data[i] < min) {
            min = arr->data[i];
        }
    }
    return min;
}

void ds_push_dynamic_array(DynamicArray* arr, int const value) {
    if (arr->length == arr->capacity) {
        ds_allocate_more_memory_dynamic_array(arr);
    }
    arr->data[arr->length] = value;
    arr->length++;
}

void ds_insert_at_index_dynamic_array(DynamicArray* arr, int const value, int const index) {
    if (index >= 0 && index <= arr->length) {
        for (unsigned int i = arr->length; i > index; --i) {
            arr->data[i] = arr->data[i - 1];
        }
        arr->data[index] = value;
        arr->length++;
    }
    if (arr->length == arr->capacity) {
        ds_allocate_more_memory_dynamic_array(arr);
    }
}

void ds_insert_to_sorted_dynamic_array(DynamicArray* arr, int const value) {
    int i = arr->length - 1;
    while (arr->data[i] > value) {
        arr->data[i] = arr->data[i - 1];
        --i;
    }
    arr->data[i + 1] = value;
    arr->length++;

    if (arr->length == arr->capacity) {
        ds_allocate_more_memory_dynamic_array(arr);
    }
}

void ds_pop_dynamic_array(DynamicArray* arr) {
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

void ds_remove_from_index_dynamic_array(DynamicArray* arr, int const index) {
    int value = 0;
    if (index >= 0 && index < arr->length) {
        value = arr->data[index];
        for (unsigned int i = index; i < arr->length; ++i) {
            arr->data[i] = arr->data[i + 1];
        }
        arr->length--;
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
    printf("Removed element: %d\n", value);
}

void ds_copy_dynamic_array(DynamicArray* from, DynamicArray* to) {
    to->capacity = from->capacity;
    to->length = from->length;
    for (unsigned int i = 0; i < from->length; ++i) {
        to->data[i] = from->data[i];
    }
}

int ds_linear_search_dynamic_array(DynamicArray const * arr, int const value) {
    for (unsigned int i = 0; i < arr->length; ++i) {
        if (arr->data[i] == value) {
            return i;
        }
    }
    return -1;
}

int ds_binary_search_dynamic_array(DynamicArray const * arr, int const value) {
    int low = 0; 
    int high = arr->length - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr->data[mid] == value) {
            return mid;
        }
        if (arr->data[mid] > value) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return -1;
}

int ds_binary_search_recursive_dynamic_array(DynamicArray const * arr, int low, int high, int const value) {
    if (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr->data[mid] == value) {
            return mid;
        }
        if (arr->data[mid] > value) {
            ds_binary_search_recursive_dynamic_array(arr, low, mid - 1, value);
        } else {
            ds_binary_search_recursive_dynamic_array(arr, mid + 1, high, value);
        }
    }
    return -1;
}

void ds_reverse_dynamic_array(DynamicArray* arr) {
    for (unsigned int i = 0, j = arr->length - 1; i < j; ++i, --j) {
        ds_swap(&arr->data[i], &arr->data[j]);
    }
}

bool ds_is_sorted_dynamic_array(DynamicArray const * arr) {
    for (unsigned int i = 0; i < arr->length - 1; ++i) {
        if (arr->data[i] > arr->data[i + 1]) {
            return false;
        }
    }
    return true;
}

void ds_merge_two_arrays_dynamic_array(DynamicArray const * arr1, DynamicArray const * arr2) {
    int i = 0;
    int j = 0;
    int k = 0;
    DynamicArray* arr3 = ds_create_dynamic_array(arr1->capacity + arr2->capacity);

    while (i < arr1->length && j < arr2->length) {
        if (arr1->data[i] < arr2->data[j]) {
            arr3->data[k++] = arr1->data[i++];
        } else {
            arr3->data[k++] = arr2->data[j++];
        }
    }

    while (i < arr1->length) {
        arr3->data[k++] = arr1->data[i++];
    }
    while (j < arr2->length) {
        arr3->data[k++] = arr2->data[j++];
    }

    arr3->length = arr1->length + arr2->length;
}

void ds_bubble_sort_dynamic_array(DynamicArray* arr) {
    for (unsigned int i = 0; i < arr->length - 1; ++i) {
        for (unsigned int j = i; j < arr->length - 1 - i; ++j) {
            if (arr->data[j] > arr->data[j + 1]) {
                ds_swap(&arr->data[j], &arr->data[j + 1]);
            }
        }
    }
}





/* --------------------- Helpers --------------------- */

void ds_info_dynamic_array(DynamicArray const * arr) {
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

void ds_print_dynamic_array(DynamicArray const * arr) {
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

void ds_swap(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

