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


/* ------------------------------------------- Creating and freeing ------------------------------------------- */
BST* ds_create_binary_search_tree(int value);


/* ------------------------------------------- Operations ------------------------------------------- */
void ds_insert_node_binary_search_tree(BST* bst, int const value);
Node * inorderPredecessor(Node *p);
Node * inorderSuccesor(Node *p);
void ds_preorder_binary_search_tree(Node * p);
void ds_inorder_binary_search_tree(Node * p);
void ds_postorder_binary_search_tree(Node * p);


/* ------------------------------------------- Helpers ------------------------------------------- */
int ds_height_binary_search_tree(Node *p);

#endif // BINARY_SEARCH_TREE_H