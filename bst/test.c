#include <stdio.h>
#include <stdlib.h>
#include "bst.h"


int main(void)
{
    BSTNode root = bst_insert(NULL, 45);
    BSTNode left = bst_insert(root, 29);
    BSTNode right = bst_insert(root, 54);
    bst_insert(left, 18);
    bst_insert(left, 31);
    bst_insert(right, 52);
    BSTNode almost_biggest = bst_insert(right, 60);
    BSTNode biggest = bst_insert(root, 62);

    /*printf("hello!\n");*/
    /*printf("%d\n", bst_get_key(bst_find(root, 53)));*/
    /*printf("%d\n", bst_is_leaf(root));*/
    /*printf("%d\n", bst_is_leaf(left));*/
    /*printf("%d\n", bst_is_leaf(right));*/
    /*printf("%d\n", bst_is_leaf(biggest));*/

    /*bst_print_in_order(root);*/
    /*puts("--");*/
    /*bst_print_pre_order(root);*/
    /*puts("--");*/
    /*bst_print_post_order(root);*/

    /*printf("%d\n", bst_num_descendants(root));*/
    /*printf("%d\n", bst_height(root));*/
    /*printf("%d\n", bst_height(almost_biggest));*/
    /*printf("%d\n", bst_height(biggest));*/

    printf("%d\n", bst_get_key(bst_get_next(root, 52)));

    bst_destroy(root);

    return 0;
}
