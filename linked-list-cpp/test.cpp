#include <iostream>

#include "list.h"


int main()
{
    LinkedList l1;

    l1.push_front(4);
    l1.push_front(9);
    l1.push_back(2);

    std::cout << "Print list 1" << std::endl;
    l1.print();

    LinkedList l2(l1);

    LinkedList l3;
    l3 = l2;

    l2.push_back(3);
    std::cout << "list 2 after push_back:" << std::endl;
    l2.print();
    std::cout << "list 1 after push_back:" << std::endl;
    l1.print();

    l3.pop_front();
    std::cout << "list 3 after pop_front:" << std::endl;
    l3.print();
    std::cout << "list 2 after pop_front:" << std::endl;
    l2.print();

    return 0;
}
