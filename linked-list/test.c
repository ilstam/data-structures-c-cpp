#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"


int main(void)
{
    LinkedList l1 = list_init();
    ll_result result;
    int *elem = NULL;

    int a = 3;
    list_push_front(l1, &a);
    int b = 23;
    list_push_back(l1, &b);
    int c = 12;
    list_push_front(l1, &c);

    result = list_pop_front(l1, (void **) &elem);
    printf("result: %d element: %d\n", result, *elem);

    result = list_pop_back(l1, (void **) &elem);
    printf("result: %d element: %d\n", result, *elem);

    result = list_pop_back(l1, (void **) &elem);
    printf("result: %d element: %d\n", result, *elem);

    result = list_destroy(l1);
    printf("result: %d\n", result);

    return EXIT_SUCCESS;
}
