#ifndef BST_H
#define BST_H

#include "generic_vector.h"
#include "my_string.h"

//****USED GEEKS FOR GEEKS AND WIKI FOR REFERENCE****//
typedef struct node Node;
typedef struct bst Bst;

Bst* bst_init_default(void);

Node* node_init_key(MY_STRING key);

MY_STRING bst_get_node_key(Node* node);

int bst_get_height(Bst* hTree);

Node* bst_get_root(Bst* hTree);

Status bst_insertion(Bst* hTree, MY_STRING word, MY_STRING key);

Node* bst_search(Node* node, MY_STRING key);

Node* bst_insert_node(Node* node, MY_STRING key);

Node* bst_find_max(Node* node);

void bst_destroy(Bst** phTree);

void node_destroy(Node** phNode);

void bst_in_order_traversal(Node* node);

Bst* generate_key_tree(char guess, GENERIC_VECTOR vWords, MY_STRING pKey);

#endif
