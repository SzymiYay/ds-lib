#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <stdint.h>

typedef struct Node {
    struct Node* left;
    struct Node* right;
    int data;
} Node;

typedef struct {
    Node* root;
} BST;

BST* ds_create_binary_search_tree(int value);

#endif // BINARY_SEARCH_TREE_H