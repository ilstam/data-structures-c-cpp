#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

struct bst_node {
    BSTNode parent;
    BSTNode left;
    BSTNode right;
    int key;
};


static void *bst_malloc(size_t size)
{
    void *ptr = NULL;
    if ((ptr = malloc(size)) == NULL) {
        printf("CRITICAL: Unable to allocate memory!\n");
        exit(-1);
    }
    return ptr;
}

static BSTNode bst_create_node(BSTNode parent, int key) {
    BSTNode node = bst_malloc(sizeof(struct bst_node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->parent = parent;
    return node;
}

int bst_get_key(BSTNode node)
{
    if (node == NULL) {
        return -1;
    }
    return node->key;
}

BSTNode bst_find(BSTNode root, int key)
{
    if (root == NULL) {
        return NULL;
    }

    if (key == root->key) {
        return root;
    }

    if (key < root->key) {
        if (root->left != NULL) {
            return bst_find(root->left, key);
        }
        return root;
    }

    if (key > root->key) {
        if (root->right != NULL) {
            return bst_find(root->right, key);
        }
        return root;
    }

    return NULL;
}

BSTNode bst_insert(BSTNode root, int key)
{
    BSTNode parent = bst_find(root, key);
    BSTNode new_node = bst_create_node(parent, key);

    if (parent == NULL) {
       /* do nothing*/
    } else if (key <= parent->key) {
        parent->left = new_node;
    } else {
        parent->right = new_node;
    }

    return new_node;
}

bool bst_is_root(BSTNode node)
{
    if (node && !node->parent) {
        return true;
    }
    return false;
}

bool bst_is_leaf(BSTNode node)
{
    if (!node->left && !node->right) {
        return true;
    }
    return false;
}

void bst_print_in_order(BSTNode root)
{
    if (root == NULL) {
        return;
    }

    bst_print_in_order(root->left);
    printf("%d\n", root->key);
    bst_print_in_order(root->right);
}

void bst_print_pre_order(BSTNode root)
{
    if (root == NULL) {
        return;
    }

    printf("%d\n", root->key);
    bst_print_pre_order(root->left);
    bst_print_pre_order(root->right);
}

void bst_print_post_order(BSTNode root)
{
    if (root == NULL) {
        return;
    }

    bst_print_post_order(root->left);
    bst_print_post_order(root->right);
    printf("%d\n", root->key);
}
