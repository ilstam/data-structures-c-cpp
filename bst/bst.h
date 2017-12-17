#ifndef BST_H
#define BST_H

#include <stdbool.h>

typedef struct bst_node *BSTNode;

/*
 * Returns the node of the tree that holds the key value.
 * If the given key is missing from the tree, then it returns the node
 * into which the key would be inserted.
 */
BSTNode bst_find(BSTNode root, int key);
BSTNode bst_insert(BSTNode root, int key);


bool bst_is_root(BSTNode node);
bool bst_is_leaf(BSTNode node);


#endif
