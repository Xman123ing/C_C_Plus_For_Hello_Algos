#include "generate_list.hpp"

#define N_END_BACKWARD (3)

int main()
{
    // generate lists
    GenList list_obj;
    list_obj.setList(10);
    pNote pHead = list_obj.getList();
    if (pHead == nullptr) {
        std::cout << "generate lists exception" << std::endl;
        return -1;
    }

    // print list
    list_obj.showList();

    // get Nth backward, N_END_BACKWARD
    pNote pCur, pNBackward, pMBackward;  //  m = n -1
    pCur = pNBackward = pMBackward = pHead->pNext_;
    int32_t number = 0;
    while (pCur != nullptr) {
        pCur = pCur->pNext_;
        if (++number > N_END_BACKWARD) {
            pMBackward = pNBackward;
            pNBackward = pNBackward->pNext_;
        }
    }
    pMBackward->pNext_ = nullptr;
    list_obj.removeItemFrom(pNBackward, N_END_BACKWARD);
    // print list
    list_obj.showList();

    return 0;
}