#include <iostream>

#include "heap.h"


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

    return 0;
}
