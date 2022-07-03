#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include "include/dynamic_array.h"


int main() {

    DynamicArray* arr = ds_create_dynamic_array(2);
    ds_print(arr);
    ds_info(arr);

    ds_push(arr, 1);
    ds_info(arr);
    ds_push(arr, 2);
    ds_info(arr);
    ds_push(arr, 3);
    ds_info(arr);
    ds_push(arr, 4);
    ds_info(arr);
    ds_push(arr, 5);
    ds_info(arr);
    ds_push(arr, 6);
    ds_info(arr);
    ds_push(arr, 7);
    ds_info(arr);
    ds_push(arr, 8);
    ds_info(arr);
    ds_push(arr, 9);
    ds_info(arr);
    ds_pop(arr);
    ds_info(arr);
    ds_pop(arr);
    ds_info(arr);
    ds_pop(arr);
    ds_info(arr);
    ds_pop(arr);
    ds_info(arr);
    ds_pop(arr);
    ds_info(arr);
    ds_pop(arr);
    ds_info(arr);
    ds_pop(arr);
    ds_info(arr);
    ds_pop(arr);
    ds_info(arr);
    ds_pop(arr);
    ds_info(arr);
    ds_pop(arr);
    ds_info(arr);
    ds_push(arr, 10);
    ds_info(arr);
    
    


    ds_free(arr);

    return 0;
}