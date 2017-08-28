#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"


struct list_node {
   struct list_node *next;
   void *element;
};

typedef struct list_node *Node;


struct linked_list {
   Node head;
   Node tail;
};


void *list_malloc(size_t size)
{
    void *ptr = NULL;
    ptr = malloc(size);
    if (ptr == NULL) {
        printf("CRITICAL: Unable to allocate memory!\n");
        exit(EXIT_FAILURE);
    }
    return ptr;
}


LinkedList list_init(void)
{
    LinkedList l = list_malloc(sizeof(struct linked_list));

    l->head = NULL;
    l->tail = NULL;

    return l;
}

ll_result list_destroy(LinkedList list)
{
    Node tmp = NULL;

    for (; list->head != NULL; list->head = tmp) {
        tmp = list->head->next;
        free(list->head);
    }
    list->tail = NULL;

    free(list);

    return LIST_SUCCESS;
}

ll_result list_push_front(LinkedList list, void *element)
{
    Node new_node = list_malloc(sizeof(struct list_node));

    new_node->element = element;

    if (list->head == NULL) {
        new_node->next = NULL;
        list->head = new_node;
        list->tail = new_node;
    } else {
        Node tmp = list->head;
        list->head = new_node;
        new_node->next = tmp;
    }

    return LIST_SUCCESS;
}

ll_result list_push_back(LinkedList list, void *element)
{
    Node new_node = list_malloc(sizeof(struct list_node));

    new_node->element = element;

    if (list->head == NULL) {
        new_node->next = NULL;
        list->head = new_node;
        list->tail = new_node;
    } else {
        list->tail->next = new_node;
        list->tail = new_node;
    }

    return LIST_SUCCESS;
}

ll_result list_pop_front(LinkedList list, void **element)
{
    if (element == NULL) {
        return LIST_NULL_POINTER;
    }

    Node node = list->head;
    if (node == NULL) {
        return LIST_IS_EMPTY;
    }

    if (list->tail == list->head) {
        list->tail = NULL;
    }
    list->head = node->next;
    *element = node->element;
    free(node);

    return LIST_SUCCESS;
}

ll_result list_pop_back(LinkedList list, void **element)
{
    if (element == NULL) {
        return LIST_NULL_POINTER;
    }

    Node node = list->head;
    if (node == NULL) {
        return LIST_IS_EMPTY;
    }

    if (node->next == NULL) { // node is the only node
        *element = node->element;
        list->tail = list->head = NULL;
        free(node);
        return LIST_SUCCESS;
    }

    // there are more nodes; get last but one node
    for(; node->next != list->tail; node = node->next) {
    }

    *element = node->next->element;
    free(node->next);
    list->tail = node;
    node->next = NULL;

    return LIST_SUCCESS;
}
