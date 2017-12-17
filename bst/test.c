#include <stdio.h>
#include <stdlib.h>
#include "bst.h"


int main(void)
{
    BSTNode root = bst_insert(NULL, 45);
    BSTNode left = bst_insert(root, 29);
    BSTNode right = bst_insert(root, 54);

    /*BSTNode node = bst_find(root, 100);*/

    /*printf("hello!\n");*/
    /*printf("%d\n", node->key);*/
    printf("%d\n", bst_is_leaf(root));
    printf("%d\n", bst_is_leaf(left));
    printf("%d\n", bst_is_leaf(right));

    // destroy tree

    return 0;
}
