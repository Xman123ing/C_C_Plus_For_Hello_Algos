#include <iostream>
#include "generate_list.hpp"

int main()
{
    // 01：合并两个有序链表
    // 时间复杂度：O(n)
    GenList list01, list02, list_merge_new;
    // generate
    list01.setList(10);
    list01.bubble_sort();
    list02.setList(5);
    list02.bubble_sort();
    // show
    std::cout << "list01 ";
    list01.showList();
    std::cout << "\nlist02 ";
    list02.showList();

    // merge and new list
    pNote pHead = new Note();
    if (list_merge_new.setHead(pHead) == false) {
        delete pHead;
        return -1;
    }
    pNote pPreview, pCur_01, pCur_02;
    pPreview = pHead;
    pCur_01 = list01.getList()->pNext_;
    pCur_02 = list02.getList()->pNext_;

    bool done_01 = false, done_02 = false;
    auto switchNext = [](bool &done, pNote &pCur, const pNote &pOther) {
        if (pCur->pNext_ == nullptr) {
            done = true;
            pCur->pNext_ = pOther;
        } else {
            pCur = pCur->pNext_;
        }
    };

    while (done_01 == false && done_02 == false) {
        if (pCur_01->value_ < pCur_02->value_) {
            pPreview->pNext_ = pCur_01;
            pPreview = pCur_01;
            switchNext(done_01, pCur_01, pCur_02);
        } else if (pCur_01->value_ > pCur_02->value_) {
            pPreview->pNext_ = pCur_02;
            pPreview = pCur_02;
            switchNext(done_02, pCur_02, pCur_01);
        } else {
            pPreview->pNext_ = pCur_01;
            pPreview = pCur_01;
            switchNext(done_01, pCur_01, pCur_02);
            if (done_01 == false) {
                pPreview->pNext_ = pCur_02;
                pPreview = pCur_02;
                switchNext(done_02, pCur_02, pCur_01);
            }
        }
    }

    // avoid double deleted
    list01.setHead(nullptr);
    list02.setHead(nullptr);

    pHead = list_merge_new.getList();
    if (pHead != nullptr && pHead->pNext_ != nullptr)
    {
        pNote pCur = pHead->pNext_;
        uint32_t num = 0;
        std::cout << "\n\nmerge list:" << std::endl;
        while(pCur != nullptr) {
            std::cout << pCur->value_ << ", ";
            ++num;
            pCur = pCur->pNext_;
        }
        std::cout <<"\ntotal: " << num << std::endl;
        list_merge_new.setNum(num);
    }

    return 0;
}