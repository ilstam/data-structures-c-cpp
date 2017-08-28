#pragma once

typedef enum ll_result {
    /**
     * LIST_SUCCESS 0 represents that the operation had no errors in processing.
     */
    LIST_SUCCESS = 0,

    /*
     * LIST_NULL_POINTER represents that a NULL pointer was provided to a function
     * that expects a true pointer to valid data.
     */
    LIST_NULL_POINTER,

    /**
     * LIST_IS_EMPTY represents that the list that was provided to a function
     * is empty.
     */
    LIST_IS_EMPTY
} ll_result;


typedef struct linked_list *LinkedList;


/**
 * Initialise a singly linked list by allocating memory for it.
 * Time complexity: O(1)
 *
 * \retval - The newly allocated LinkedList object.
 */
LinkedList list_init(void);

/**
 * Free and delete any internal structures and destroy the list. You must *always*
 * call this function to dispose of this structure.
 * Time complexity: O(1)
 *
 * \param list - The list that you wish to destroy.
 * \retval - ll_result to indicate the status of the operation.
 */
ll_result list_destroy(LinkedList list);

/**
 * Push an item to the front of the list.
 * Time complexity: O(1)
 *
 * \param list - The list that you wish to pop from.
 * \param element - Pointer to the data to be pushed.
 * \retval - ll_result to indicate the status of the operation.
 */
ll_result list_push_front(LinkedList list, void *element);

/**
 * Push an item to the back of the list.
 * Time complexity: O(1)
 *
 * \param list - The list that you wish to pop from.
 * \param element - Pointer to the data to be pushed.
 * \retval - ll_result to indicate the status of the operation.
 */
ll_result list_push_back(LinkedList list, void *element);

/**
 * Pop an item from the front of the list.
 * Time complexity: O(1)
 *
 * \param list - The list that you wish to pop from.
 * \param element - A pointer to a location which will be over-ridden with the
 * data that is poped.
 * \retval - ll_result to indicate the status of the operation.
 */
ll_result list_pop_front(LinkedList list, void **element);

/**
 * Pop an item from the back of the list.
 * Time complexity: O(n)
 *
 * \param list - The list that you wish to pop from.
 * \param element - A pointer to a location which will be over-ridden with the
 * data that is poped.
 * \retval - ll_result to indicate the status of the operation.
 */
ll_result list_pop_back(LinkedList list, void **element);
