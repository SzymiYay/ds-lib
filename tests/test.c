#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include "../src/include/dynamic_array.h"


int main() {

    DynamicArray* arr = ds_create_dynamic_array(2);
    
    int choice;
    int index, value;

    do {
        printf("\n----------- MENU -----------\n");
        printf("1. Append\n");
        printf("2. Insert\n");
        printf("3. Delete\n");
        printf("4. Search\n");
        printf("5. Sum\n");
        printf("6. Get value\n");
        printf("7. Set value\n");
        printf("8. Average of elements\n");
        printf("9. Max\n");
        printf("10. Min\n");
        printf("11. Reverse\n");
        printf("12. Is sorted?\n");
        printf("13. BubbleSort\n");
        printf("14. Display\n");
        printf("15. Exit\n");

        printf("\nEnter your choice:\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to append:\n");
                scanf("%d", &value);
                ds_push(arr, value);
                break;
            case 2:
                printf("Enter value of element:\n");
                scanf("%d", &value);
                printf("Enter index:\n");
                scanf("%d", &index);
                ds_insert_at_index(arr, value, index);
                break;
            case 3:
                printf("Enter index of element to delete:\n");
                scanf("%d", &index);
                ds_remove_from_index(arr, index);
                break;
            case 4:
                printf("Enter element to find:\n");
                scanf("%d", &value);
                printf("\nIndex of element is: %d\n", ds_binary_search(arr, value));
                break;
            case 5:
                printf("\nSum of elements is: %d", ds_sum_of_elements(arr));
                break;
            case 6:
                printf("Enter index of element:\n");
                scanf("%d", &index);
                printf("Value at index %d is %d\n", index, ds_get_value(arr, index));
                break;
            case 7:
                printf("Enter value of element:\n");
                scanf("%d", &value);
                printf("Enter index of element to set");
                scanf("%d", &index);
                ds_set_value(arr, value, index);
                break;
            case 8:
                printf("\nAverage of elements is: %d", ds_average_of_elements(arr));
                break;
            case 9:
                printf("\nMax of elements is: %d", ds_max(arr));
                break;
            case 10:
                printf("\nMin of elements is: %d", ds_min(arr));
                break;
            case 11:
                ds_reverse_array(arr);
                break;
            case 12:
                printf("\nIs array sorted: %d", ds_is_sorted(arr) ? "ture" : "false");
                break;
            case 13:
                ds_bubble_sort(arr);
                break;
            case 14:
                ds_info(arr);
                break;
        }
    } while (choice < 15);

    ds_free(arr);

    return 0;
}