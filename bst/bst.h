#ifndef BST_H
#define BST_H

#include <stdbool.h>

typedef struct bst_node *BSTNode;


int bst_get_key(BSTNode node);

/*
 * Returns the node of the tree that holds the key value.
 * If the given key is missing from the tree, then it returns the node
 * into which the key would be inserted.
 */
BSTNode bst_find(BSTNode root, int key);
BSTNode bst_insert(BSTNode root, int key);

bool bst_is_root(BSTNode node);
bool bst_is_leaf(BSTNode node);

int bst_height(BSTNode node);
int bst_depth(BSTNode node);

int bst_num_children(BSTNode node);
int bst_num_descendants(BSTNode node);

void bst_print_in_order(BSTNode root);
void bst_print_pre_order(BSTNode root);
void bst_print_post_order(BSTNode root);

void bst_destroy(BSTNode root);

#endif
