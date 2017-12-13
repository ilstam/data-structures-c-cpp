#ifndef LIST_CPP
#define LIST_CPP

#include <iostream>

#include "list.h"

template <class T>
LinkedList<T>::LinkedList(): head(nullptr), tail(nullptr), length(0) {}

template <class T>
LinkedList<T>::LinkedList(const LinkedList<T> &that): head(nullptr), tail(nullptr), length(that.length)
{
    if (that.length == 0) {
        return;
    }

    copy(that);
}

template <class T>
LinkedList<T>::~LinkedList()
{
    destroy();
}

template <class T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList &that)
{
    if (this != &that) {
        destroy();
        copy(that);
    }

    return *this;
}

template <class T>
void LinkedList<T>::push_front(T element)
{
    Node<T> *new_node = new Node<T>(element);

    if (head == nullptr) {
        head = tail = new_node;
    } else {
        Node<T> *tmp = head;
        head = new_node;
        new_node->next = tmp;
    }

    length++;
}

template <class T>
void LinkedList<T>::push_back(T element)
{
    Node<T> *new_node = new Node<T>(element);

    if (head == nullptr) {
        head = tail = new_node;
    } else {
        tail->next = new_node;
        tail = new_node;
    }

    length++;
}

template <class T>
T LinkedList<T>::pop_front()
{
    if (is_empty()) {
        throw EmptyListException();
    }

    Node<T> *node = head;

    if (tail == head) {
        tail = nullptr;
    }
    head = node->next;

    T element = node->element;
    delete node;
    length--;

    return element;
}

template <class T>
T LinkedList<T>::pop_back()
{
    if (is_empty()) {
        throw EmptyListException();
    }

    Node<T> *node = head;
    T element = node->element;

    if (node->next == nullptr) {
        tail = head = NULL;
        delete node;
    } else {
        // get last by one node
        for (; node->next != tail; node = node->next) {
        }

        element = node->next->element;
        tail = node;
        delete node->next;
        node->next = nullptr;
    }

    length--;
    return element;
}

template <class T>
bool LinkedList<T>::is_empty()
{
    return length == 0;
}

template <class T>
int LinkedList<T>::get_size()
{
    return length;
}

template <class T>
void LinkedList<T>::print()
{
    for (Node<T> *node = head; node != nullptr; node = node->next) {
        std::cout << node->element << ", ";
    }
    std::cout << std::endl;
}

template <class T>
void LinkedList<T>::copy(const LinkedList &that)
{
    Node<T> *node = new Node<T>(that.head->element);
    head = tail = node;

    for (Node<T> *current = that.head->next; current != nullptr; current = current->next) {
        node = new Node<T>(current->element);
        tail->next = node;
        tail = node;
    }

    length = that.length;
}

template <class T>
void LinkedList<T>::destroy()
{
    for (Node<T> *tmp; head != nullptr; head = tmp) {
        tmp = head->next;
        delete head;
    }

    head = tail = nullptr;
    length = 0;
}

#endif
