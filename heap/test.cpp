#include <iostream>

#include "heap.h"

void print_array(int *array, int len) {
    for (int i = 0; i < len; i++) {
        std::cout << array[i] << ", ";
    }
    std::cout << std::endl;
}


int main()
{
    BinaryHeap bh(100);
    bh.insert(5);
    bh.insert(9);
    bh.insert(7);
    bh.insert(2);
    bh.insert(8);

    std::cout << bh.pop_max() << std::endl;
    std::cout << bh.pop_max() << std::endl;
    std::cout << bh.pop_max() << std::endl;
    std::cout << bh.pop_max() << std::endl;
    std::cout << bh.pop_max() << std::endl;

    try {
        bh.pop_max();
    } catch (EmptyHeapException &ex) {
        std::cout << "Catched empty heap exception!"  << std::endl;
    }

    int array[] = {23, 89, 12, 4, 78, 24, 95, 60, 32, 4, 20, 56};
    int array_len = sizeof(array) / sizeof(array)[0];

    std::cout << "Array:" << std::endl;
    print_array(array, array_len);

    BinaryHeap::heapsort(array, array_len);

    std::cout << "Array after heapsort:" << std::endl;
    print_array(array, array_len);

    return 0;
}
