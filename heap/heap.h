#ifndef HEAP_H
#define HEAP_H

class BinaryHeap {
public:
    BinaryHeap(int capacity);
    ~BinaryHeap();
    BinaryHeap(const BinaryHeap &that); // copy constructor
    BinaryHeap& operator=(const BinaryHeap &that); // copy assignment operator

    int get_max();
    int pop_max();
    void insert(int elem);
    int remove(int pos);
    void change_priority(int pos, int priority);
    bool is_empty();
    bool is_full();

private:
    int size;
    int capacity;
    int *array;

    int parent(int i);
    int left_child(int i);
    int right_child(int i);

    void shift_up(int i);
    void shift_down(int i);
};

class EmptyHeapException: public std::exception
{
    virtual const char* what() const throw()
    {
        return "Heap is empty!";
    }
};


class FullHeapException: public std::exception
{
    virtual const char* what() const throw()
    {
        return "Heap is full!";
    }
};

class PositionNotInHeapException: public std::exception
{
    virtual const char* what() const throw()
    {
        return "Given position not in heap!";
    }
};

#endif
