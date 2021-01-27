#include "generate_list.hpp"
#include <time.h>

int main()
{
    srand(time(nullptr));  // for rand seed
    GenList list_test;
    list_test.setList(10);
    list_test.showList();
    list_test.bubble_sort();
    list_test.showList();
    list_test.destroyList();
    return 0;
}