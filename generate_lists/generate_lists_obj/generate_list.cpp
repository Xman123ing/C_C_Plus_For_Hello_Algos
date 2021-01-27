#include "generate_list.hpp"

// 调用removeFrom之后，需将pStartDel前一节点的pNext_指针置为NULL
auto removeFrom = [](pNote &pStartDel, uint32_t &num){
        pNote pCur, pNet;
        pCur = pNet = pStartDel;
        while (pCur != nullptr) {
            pNet = pCur->pNext_;
            delete pCur;
            pCur = pNet;
            --num;
        }
        pStartDel = nullptr;
};

void GenList::setList(uint32_t num)
{
    if (pHead_ != nullptr) {
        return;
    } else {
        num_ = num;
        pHead_ = new Note();
        pNote pCur, pPre;
        pCur = pPre = new Note();
        pHead_->pNext_ = pCur;
        int32_t n = 0;
        while (n < num_ - 1) {
            pCur = new Note();
            pPre->pNext_ = pCur;
            pPre = pCur;
            ++n;
        }
    }
}

void GenList::showList()
{
    if (pHead_ == nullptr || pHead_->pNext_ == nullptr) {
        std::cout << "list is null\n" << std::endl;
    } else {
        pNote pCur = pHead_->pNext_;
        std::cout << "total element: " << num_ << std::endl;
        do {
            std::cout << pCur->value_ << ", ";
            pCur = pCur->pNext_;
        } while(pCur != nullptr);
        std::cout << std::endl;
    }
}

void GenList::removeItemFrom(pNote pStartDel, uint32_t num) {removeFrom(pStartDel, num);}

void GenList::destroyList()
{
    if (pHead_ == nullptr) {
        return;
    } else {
        removeFrom(pHead_, num_);
    }
}

void GenList::bubble_sort()
{
    if (pHead_ == nullptr || pHead_->pNext_ == nullptr) {
        std::cout << "list is empty" << std::endl;
    }

    pNote pPrivew, pCur, pNext;
    int32_t i = 0,j;
    while (i < num_ - 1) {
        j = 0;
        pPrivew = pHead_;
        pCur = pHead_->pNext_;
        pNext = pCur->pNext_;
        while (j < num_ - i - 1) {
            if (pCur->value_ > pNext->value_) {
                pPrivew->pNext_ = pNext;
                pNote pTemp = pNext->pNext_;
                pNext->pNext_ = pCur;
                pCur->pNext_ = pTemp;

                pPrivew = pNext;
                pNext = pCur->pNext_;
            } else {
                pPrivew = pCur;
                pCur = pNext;
                pNext = pNext->pNext_;
            }
            ++j;
        }
        ++i;
    }
}