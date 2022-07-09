#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include "include/binary_search_tree.h"



/* --------------------- Creating and freeing --------------------- */

BST* ds_create_binary_search_tree(int value) {
    BST* bst = malloc(sizeof(BST));

    bst->root = malloc(sizeof(Node));
    bst->root->left = NULL;
    bst->root->right = NULL;
    bst->root->data = value;

    return bst;
}


/* --------------------- Operations --------------------- */

void ds_insert_node_binary_search_tree(BST* bst, int const value) {
    Node* p = bst->root;
    Node* tmp;

    while (p != NULL) {
        tmp = p;
        if (p->data == value) {
            return;
        } 
        else if (p->data > value) {
            p = p->left;
        }
        else {
            p = p->right;
        }
    }
    Node* t = malloc(sizeof(Node));
    t->data = value;
    t->left = t->right = NULL;
    if (t->data < tmp->data) {
        tmp->left = t;
    } else {
        tmp->right = t;
    }
}

Node * inorderPredecessor(Node *p) {
    while (p && p->right != NULL) {
        p = p->right;
    }
    return p;
}

Node * inorderSuccesor(Node *p) {
    while (p && p->left != NULL) {
        p = p->left;
    }
    return p;
}


void ds_preorder_binary_search_tree(Node * p) {
    if (p != NULL) {
        printf("%d ", p->data);
        ds_inorder_binary_search_tree(p->left);
        ds_inorder_binary_search_tree(p->right);
    }
    return;
}

void ds_inorder_binary_search_tree(Node * p) {
    if (p != NULL) {
        ds_inorder_binary_search_tree(p->left);
        printf("%d ", p->data);
        ds_inorder_binary_search_tree(p->right);
    }
    return;
}

void ds_postorder_binary_search_tree(Node * p) {
    if (p != NULL) {
        printf("%d ", p->data);
        ds_inorder_binary_search_tree(p->left);
        ds_inorder_binary_search_tree(p->right);
    }
    return;
}


/* --------------------- Helpers --------------------- */

int ds_height_binary_search_tree(Node *p) {
    int x, y;
    if (p == NULL)
        return 0;
    x = ds_height_binary_search_tree(p->left);
    y = ds_height_binary_search_tree(p->right);
    return x > y ? x + 1 : y + 1;
}