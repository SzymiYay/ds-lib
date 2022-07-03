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

    ds_push(arr, 5);
    ds_push(arr, 6);
    ds_push(arr, 7);
    ds_push(arr, 8);
    ds_push(arr, 9);
    

    ds_info(arr);

    ds_free(arr);

    return 0;
}