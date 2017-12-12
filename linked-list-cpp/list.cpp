#include <iostream>

#include "list.h"


struct LinkedList::Node {
    Node *next;
    int element;

    Node(int value): next(nullptr), element(value) {}
};

LinkedList::LinkedList(): head(nullptr), tail(nullptr), length(0) {}

LinkedList::LinkedList(const LinkedList &that): head(nullptr), tail(nullptr), length(that.length)
{
    if (that.length == 0) {
        return;
    }

    copy(that);
}

LinkedList::~LinkedList()
{
    destroy();
}

LinkedList& LinkedList::operator=(const LinkedList &that)
{
    if (this != &that) {
        destroy();
        copy(that);
    }

    return *this;
}

void LinkedList::push_front(int element)
{
    Node *new_node = new Node(element);

    if (head == nullptr) {
        head = tail = new_node;
    } else {
        Node *tmp = head;
        head = new_node;
        new_node->next = tmp;
    }

    length++;
}

void LinkedList::push_back(int element)
{
    Node *new_node = new Node(element);

    if (head == nullptr) {
        head = tail = new_node;
    } else {
        tail->next = new_node;
        tail = new_node;
    }

    length++;
}

int LinkedList::pop_front()
{
    if (is_empty()) {
        throw EmptyListException();
    }

    Node *node = head;

    if (tail == head) {
        tail = nullptr;
    }
    head = node->next;

    int element = node->element;
    delete node;
    length--;

    return element;
}

int LinkedList::pop_back()
{
    if (is_empty()) {
        throw EmptyListException();
    }

    Node *node = head;
    int element = node->element;

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

bool LinkedList::is_empty()
{
    return length == 0;
}

int LinkedList::get_size()
{
    return length;
}

void LinkedList::print()
{
    for (Node *node = head; node != nullptr; node = node->next) {
        std::cout << node->element << ", ";
    }
    std::cout << std::endl;
}

void LinkedList::copy(const LinkedList &that)
{
    Node *node = new Node(that.head->element);
    head = tail = node;

    for (Node *current = that.head->next; current != nullptr; current = current->next) {
        node = new Node(current->element);
        tail->next = node;
        tail = node;
    }

    length = that.length;
}

void LinkedList::destroy()
{
    for (Node *tmp; head != nullptr; head = tmp) {
        tmp = head->next;
        delete head;
    }

    head = tail = nullptr;
    length = 0;
}
