#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

typedef struct node Node;

struct node {
    MY_STRING key;
    GENERIC_VECTOR words;
    int height;

    Node* left;
    Node* right;
};

struct bst
{
    Node* root;
};
typedef struct bst Bst;

Bst* bst_init_default(void)
{
    Bst* treeStruct = (Bst*)malloc(sizeof(Bst));
    if (treeStruct == NULL)
      {
        return NULL;
      }
    treeStruct->root = NULL;
    return treeStruct;
}

Node* node_init_key(MY_STRING key)
{
    My_string* pKey = (My_string*) key;
    Node* treeNode = (Node*)malloc(sizeof(Node));
    if (treeNode == NULL)
      {
        free(treeNode);
        treeNode = NULL;
        return NULL;
      }
    treeNode->key = my_string_init_c_string(my_string_c_str(pKey));
    treeNode->words = generic_vector_init_default(my_string_assignment, my_string_destroy);
    treeNode->left = NULL;
    treeNode->right = NULL;
    treeNode->height = 0;
    return treeNode;
}

MY_STRING bst_get_node_key(Node* node)
{
    return node->key;
}

int bst_get_height(Bst* hTree)
{
    return hTree->root->height;
}

Node* bst_get_root(Bst* hTree)
{
    return hTree->root;
}

Status bst_insertion(Bst* hTree, MY_STRING word, MY_STRING key)
{
    My_string* pWord = (My_string*) word;
    My_string* pKey = (My_string*) key;
    Node* familyKey = bst_search(hTree->root, pKey);
    if (familyKey != NULL)
      {
        if (generic_vector_push_back(familyKey->words, pWord) == FAILURE)
	  {
            return FAILURE;
	  }
      }
    else
      {
        hTree->root = bst_insert_node(hTree->root, pKey);
        bst_insertion(hTree, pWord, pKey);
      }
    return SUCCESS;
}


Node* bst_search(Node* node, MY_STRING key)
{
    if (node == NULL)
      {
        return NULL;
      }
    else
      {
        if (!my_string_compare(node->key, key))
	  {
            return node;
	  }
        Node* treeNode = bst_search(node->left, key);
        if (treeNode != NULL)
	  {
            return treeNode;
	  }
        treeNode = bst_search(node->right, key);
        if (treeNode != NULL)
	  {
            return treeNode;
	  }
        
      }
    return NULL;
}

Node* bst_insert_node(Node* node, MY_STRING key)
{
  My_string* pKey = (My_string*) key;
    if (node == NULL)
      {
        node = (node_init_key(pKey));
        return (node);
      }
    
    if (my_string_compare(node->key, pKey) > 0)
      {
        node->left = bst_insert_node(node->left, pKey);
        node->height++;
      }
    
    else if (my_string_compare(node->key, pKey) < 0)
      {
        node-> right = bst_insert_node(node->right, pKey);
        node->height++;
      }
    return (node);
}

Node* bst_find_max(Node* node)
{    
    if (node == NULL)
      {
        return node;
      }
    
    int leftSize = 0;
    int rightSize = 0;
    Node* left = bst_find_max(node->left);
    Node* right = bst_find_max(node->right);
    
    int currentSize = generic_vector_get_size(node->words);
    if (right != NULL)
      {
        rightSize = generic_vector_get_size(right->words);
      }
    
    if (left != NULL)
      {
        leftSize = generic_vector_get_size(left->words);
      }

    if (currentSize < leftSize)
      {
        currentSize = leftSize;
        node = left;
      }
    
    if (currentSize < rightSize)
      {
        currentSize = rightSize;
        node = right;
      }
    
    return node;
}

void bst_destroy(Bst** phTree)
{
    Bst* treeStruct = (Bst*)*phTree;
    if (treeStruct != NULL)
      {
        node_destroy(&treeStruct->root);
        free(treeStruct);
        *phTree = NULL;
      }
}

void node_destroy(Node** phNode)
{
    Node* treeNode = (Node*)*phNode;
    if (treeNode == NULL)
      {
        return;
      }
    node_destroy(&(treeNode->left));
    node_destroy(&(treeNode->right));
    my_string_destroy(&(treeNode->key));
    generic_vector_destroy(&(treeNode->words));
    free(treeNode);
    *phNode = NULL;
}


void bst_in_order_traversal(Node* node)
{
    if (node == NULL)
      {
        return;
      }
    else
      {
        bst_in_order_traversal(node->left);
        printf("Key: %s Size: %d\n",my_string_c_str(node->key),
	       generic_vector_get_size(node->words));
        bst_in_order_traversal(node->right);
      }
}

Bst* generate_key_tree(char guess, GENERIC_VECTOR vWords, MY_STRING pKey)
{
  int i;
  Bst* hTree = bst_init_default();
  Vector* pvWords = (Vector*) vWords;
  My_string* ppKey = (My_string*) pKey;
  My_string* nKey = NULL;
    if (generic_vector_empty(pvWords))
      {
        printf("GENERIC_VECTOR is empty!\n");
        return NULL;
      }
    if (hTree != NULL)
      {
        nKey = my_string_init_default();
        for (i = 0; i < generic_vector_get_size(pvWords); i++)
	  {
            bst_insertion(hTree, generic_vector_at(pvWords, i), nKey);
	  }
        my_string_destroy((Item*)&nKey);
    }
    return hTree;
}
