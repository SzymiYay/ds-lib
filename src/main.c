#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
// #include "include/dynamic_array.h"
// #include "include/stack.h"
// #include "include/linked_list.h"
#include "include/binary_search_tree.h"


int main() {



    BST* bst = ds_create_binary_search_tree(10);
    ds_insert_node_binary_search_tree(bst, 12);
    ds_insert_node_binary_search_tree(bst, 1);
    ds_insert_node_binary_search_tree(bst, 2);
    ds_insert_node_binary_search_tree(bst, 23);
    ds_insert_node_binary_search_tree(bst, 45);
    ds_insert_node_binary_search_tree(bst, 21);
    ds_insert_node_binary_search_tree(bst, 7);
    ds_insert_node_binary_search_tree(bst, 55);
    ds_insert_node_binary_search_tree(bst, 54);
    ds_insert_node_binary_search_tree(bst, 53);
    ds_insert_node_binary_search_tree(bst, 58);
    Node* p = bst;
    ds_inorder_binary_search_tree(p);












    // LinkedList* list = ds_create_linked_list(0);
    // ds_info_linked_list(list);
    // ds_print_linked_list(list);

    // ds_append_node_linked_list(list, 10);

    // ds_info_linked_list(list);
    // ds_insert_node_linked_list(list, 6, 0);
    // ds_insert_node_linked_list(list, 5, 1);
    // ds_print_linked_list(list);
    // ds_delete_first_node_linked_list(list);
    // ds_info_linked_list(list);
    // ds_append_node_linked_list(list, 10);
    // ds_append_node_linked_list(list, 16);
    // ds_append_node_linked_list(list, 17);
    // ds_append_node_linked_list(list, 14);
    // ds_info_linked_list(list);
    // ds_delete_node_linked_list(list, 3);
    // ds_info_linked_list(list);

    // ds_free_linked_list(list);











    // Stack* stack = ds_create_stack(10);
    // ds_info_stack(stack);
    // ds_print_stack(stack);
    // ds_push_stack(stack, 1);
    // ds_info_stack(stack);
    // ds_print_stack(stack);
    // ds_push_stack(stack, 2);
    // ds_info_stack(stack);
    // ds_print_stack(stack);
    // ds_push_stack(stack, 3);
    // ds_info_stack(stack);
    // ds_print_stack(stack);
    // ds_push_stack(stack, 4);
    // ds_info_stack(stack);
    // ds_print_stack(stack);
    // ds_push_stack(stack, 5);
    // ds_info_stack(stack);
    // ds_print_stack(stack);
    // ds_push_stack(stack, 6);
    // ds_push_stack(stack, 7);
    // ds_print_stack(stack);
    // ds_push_stack(stack, 8);
    // ds_push_stack(stack, 9);
    // ds_push_stack(stack, 10);
    // ds_print_stack(stack);
    // ds_push_stack(stack, 11);
    // ds_print_stack(stack);
    // ds_push_stack(stack, 11);
    // ds_push_stack(stack, 11);
    // ds_push_stack(stack, 11);
    // ds_info_stack(stack);

    // ds_pop_stack(stack);
    // ds_pop_stack(stack);
    // ds_print_stack(stack);
    // ds_pop_stack(stack);
    // ds_pop_stack(stack);
    // ds_pop_stack(stack);
    // ds_print_stack(stack);
    // ds_pop_stack(stack);
    // ds_pop_stack(stack);
    // ds_print_stack(stack);



    // ds_free_stack(stack);



    // DynamicArray* arr = ds_create_dynamic_array(2);
    
    // int choice;
    // int index, value;

    // do {
    //     printf("\n----------- MENU -----------\n");
    //     printf("1. Append\n");
    //     printf("2. Insert\n");
    //     printf("3. Delete\n");
    //     printf("4. Search\n");
    //     printf("5. Sum\n");
    //     printf("6. Get value\n");
    //     printf("7. Set value\n");
    //     printf("8. Average of elements\n");
    //     printf("9. Max\n");
    //     printf("10. Min\n");
    //     printf("11. Reverse\n");
    //     printf("12. Is sorted?\n");
    //     printf("13. BubbleSort\n");
    //     printf("14. Display\n");
    //     printf("15. Exit\n");

    //     printf("\nEnter your choice:\n");
    //     scanf("%d", &choice);

    //     switch (choice) {
    //         case 1:
    //             printf("Enter element to append:\n");
    //             scanf("%d", &value);
    //             ds_push_dynamic_array(arr, value);
    //             break;
    //         case 2:
    //             printf("Enter value of element:\n");
    //             scanf("%d", &value);
    //             printf("Enter index:\n");
    //             scanf("%d", &index);
    //             ds_insert_at_index_dynamic_array(arr, value, index);
    //             break;
    //         case 3:
    //             printf("Enter index of element to delete:\n");
    //             scanf("%d", &index);
    //             ds_remove_from_index_dynamic_array(arr, index);
    //             break;
    //         case 4:
    //             printf("Enter element to find:\n");
    //             scanf("%d", &value);
    //             printf("\nIndex of element is: %d\n", ds_binary_search_dynamic_array(arr, value));
    //             break;
    //         case 5:
    //             printf("\nSum of elements is: %d", ds_sum_of_elements_dynamic_array(arr));
    //             break;
    //         case 6:
    //             printf("Enter index of element:\n");
    //             scanf("%d", &index);
    //             printf("Value at index %d is %d\n", index, ds_get_value_dynamic_array(arr, index));
    //             break;
    //         case 7:
    //             printf("Enter value of element:\n");
    //             scanf("%d", &value);
    //             printf("Enter index of element to set");
    //             scanf("%d", &index);
    //             ds_set_value_dynamic_array(arr, value, index);
    //             break;
    //         case 8:
    //             printf("\nAverage of elements is: %d", ds_average_of_elements_dynamic_array(arr));
    //             break;
    //         case 9:
    //             printf("\nMax of elements is: %d", ds_max_dynamic_array(arr));
    //             break;
    //         case 10:
    //             printf("\nMin of elements is: %d", ds_min_dynamic_array(arr));
    //             break;
    //         case 11:
    //             ds_reversey_dynamic_array(arr);
    //             break;
    //         case 12:
    //             printf("\nIs array sorted: %d", ds_is_sorted_dynamic_array(arr) ? "ture" : "false");
    //             break;
    //         case 13:
    //             ds_bubble_sort_dynamic_array(arr);
    //             break;
    //         case 14:
    //             ds_info_dynamic_array(arr);
    //             break;
    //     }
    // } while (choice < 15);

    // ds_free(arr);

    return 0;
}