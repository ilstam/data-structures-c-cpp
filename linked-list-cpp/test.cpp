#include <iostream>

#include "list.h"

struct Test {
    int x;
    int y;
};


int main()
{
    std::cout << "hi"  << std::endl;
    LinkedList<int> l1;

    l1.push_front(4);
    l1.push_front(9);
    l1.push_back(2);

    std::cout << "Print list 1" << std::endl;
    l1.print();

    LinkedList<int> l2(l1);

    LinkedList<int> l3;
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

    Test t1 = {3, 5}, t2 = {5, 12};

    LinkedList<Test> list_test;

    list_test.push_front(t1);
    list_test.push_back(t2);

    Test back = list_test.pop_back();
    std::cout << back.x << std::endl;
    std::cout << back.y << std::endl;

    return 0;
}
