#ifndef LIST_H
#define LIST_H

#include <exception>

template <class T>
struct Node {
    Node<T> *next;
    T element;

    Node(T value): next(nullptr), element(value) {}
};

template <class T>
class LinkedList {
public:
    LinkedList();
    LinkedList(const LinkedList<T> &that); // copy constructor
    ~LinkedList();
    LinkedList& operator=(const LinkedList<T> &that); // copy assignment operator

    void push_front(T elem);
    void push_back(T elem);
    T pop_front();
    T pop_back();
    bool is_empty();
    int get_size();
    void print();

private:
    Node<T> *head;
    Node<T> *tail;
    int length;

    void copy(const LinkedList &that);
    void destroy();
};

class EmptyListException: public std::exception
{
    virtual const char* what() const throw()
    {
        return "List is empty!";
    }
};

// Here's why I do this:
// https://stackoverflow.com/questions/8752837/undefined-reference-to-template-class-constructor
// https://stackoverflow.com/questions/495021/why-can-templates-only-be-implemented-in-the-header-file
#include "list.cpp"

#endif
