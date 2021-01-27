#include <iostream>
#include "generate_list.hpp"

int main()
{
    GenList list01, list02;
    list01.setList(10);
    list01.bubble_sort();
    list02.setList(5);
    list02.bubble_sort();
    // show
    std::cout << "list01 ";
    list01.showList();
    std::cout << "\nlist02 ";
    list02.showList();
    return 0;
}