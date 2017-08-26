#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"


int main(void)
{
    LinkedList l1 = list_init();
    ll_result result;
    long *elem = malloc(sizeof(long));

    long i;
    i = 3;
    list_push_front(l1, (void *) i);
    i = 23;
    list_push_back(l1, (void *) i);
    i = 12;
    list_push_front(l1, (void *) i);
    i = 7;
    list_push_back(l1, (void *) i);

    /*list_print(l1);*/

    result = list_pop_front(l1, (void *) elem);
    printf("result: %d element: %ld\n", result, *elem);

    /*list_print(l1);*/

    result = list_pop_back(l1, (void *) elem);
    printf("result: %d element: %ld\n", result, *elem);

    /*list_print(l1);*/

    result = list_destroy(l1);
    printf("result: %d\n", result);

    return EXIT_SUCCESS;
}
