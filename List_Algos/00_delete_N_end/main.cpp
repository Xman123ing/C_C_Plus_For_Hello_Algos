#include "generate_list.hpp"

int main()
{
    GenList list_obj(10);
    list_obj.setList();
    pNote pHead = list_obj.getList();
    return 0;
}