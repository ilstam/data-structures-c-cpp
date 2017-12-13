#include <limits>
#include <exception>

#include "heap.h"


void swap_elements(int &a, int &b) {
    int tmp = b;
    b = a;
    a = tmp;
}

BinaryHeap::BinaryHeap(int capacity = 50): size(0), capacity(capacity)
{
    array = new int[capacity];
}

BinaryHeap::~BinaryHeap()
{
    delete [] array;
}

BinaryHeap::BinaryHeap(const BinaryHeap &that): size(that.size), capacity(that.capacity)
{
    array = new int[capacity];
    for (int i = 0; i < size; i++) {
        array[i] = that.array[i];
    }
}

BinaryHeap& BinaryHeap::operator=(const BinaryHeap &that)
{
    if (this != &that) {
        delete [] array;

        array = new int[capacity];
        for (int i = 0; i < size; i++) {
            array[i] = that.array[i];
        }
    }

    return *this;
}

int BinaryHeap::parent(int i)
{
    return (i-1)/2;
}

int BinaryHeap::left_child(int i)
{
    return i*2 + 1;
}

int BinaryHeap::right_child(int i)
{
    return i*2 + 2;
}

void BinaryHeap::shift_up(int i)
{
    while (i > 0 && array[i] > array[parent(i)]) {
        swap_elements(array[i], array[parent(i)]);
        i = parent(i);
    }
}

void BinaryHeap::shift_down(int i)
{
    int max_val = i;
    int left = left_child(i);
    int right = right_child(i);

    if (left < size && array[left] > array[max_val]) {
        max_val = left;
    }
    if (right < size && array[right] > array[max_val]) {
        max_val = right;
    }

    if (max_val != i) {
        swap_elements(array[i], array[max_val]);
        shift_down(max_val);
    }
}

int BinaryHeap::get_max()
{
    if (is_empty()) {
        throw EmptyHeapException();
    }
    return array[0];
}

int BinaryHeap::pop_max()
{
    if (is_empty()) {
        throw EmptyHeapException();
    }

    swap_elements(array[0], array[size-1]);
    size--;
    shift_down(0);
    return array[size];
}

void BinaryHeap::insert(int elem)
{
    if (is_full()) {
        throw FullHeapException();
    }

    array[size++] = elem;
    shift_up(size-1);
}

int BinaryHeap::remove(int pos)
{
    if (pos >= size) {
        throw PositionNotInHeapException();
    }

    int retval = array[pos];
    array[pos] = std::numeric_limits<int>::max();
    shift_up(pos);
    pop_max();
    return retval;
}

void BinaryHeap::change_priority(int pos, int priority)
{
    if (pos >= size) {
        throw PositionNotInHeapException();
    }

    int old_priority = array[pos];
    array[pos] = priority;

    if (priority > old_priority) {
        shift_up(pos);
    } else {
        shift_down(pos);
    }
}

bool BinaryHeap::is_empty()
{
    return size == 0;
}

bool BinaryHeap::is_full()
{
    return size == capacity;
}

BinaryHeap::BinaryHeap(int *arr, int len): size(len), capacity(len)
{
    array = arr;

    // We only need to shift down the first half elements (in reverse order)
    // in order to create a proper heap.
    for (int i = (len-2)/2; i >= 0; i--) {
        shift_down(i);
    }
}

void BinaryHeap::heapsort(int *arr, int len)
{
    BinaryHeap heap(arr, len);
    while (!heap.is_empty()) {
        arr[--len] = heap.pop_max();
    }

    // We need this otherwise the destructor will try to free the array memory!
    heap.array = nullptr;
}
