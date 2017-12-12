#ifndef LIST_H
#define LIST_H

#include <exception>

class LinkedList {
public:
    LinkedList();
    LinkedList(const LinkedList &that); // copy constructor
    ~LinkedList();
    LinkedList& operator=(const LinkedList &that); // copy assignment operator

    void push_front(int elem);
    void push_back(int elem);
    int pop_front();
    int pop_back();
    bool is_empty();
    int get_size();
    void print();

private:
    struct Node;
    Node *head;
    Node *tail;
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

#endif
