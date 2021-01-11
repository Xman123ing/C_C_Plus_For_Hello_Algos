#ifndef __GENERATE_LIST__HPP__
#define __GENERATE_LIST__HPP__
#include <iostream>
#include <string>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

#define RANGE_VALUE 50

int32_t NumberRand()
{
    return rand() % RANGE_VALUE;
}

typedef struct Note
{
    int32_t value_;
    Note *pNext_;

    Note(int32_t value):value_(value), pNext_(nullptr){}
    Note():value_(NumberRand()), pNext_(nullptr){}
} *pNote;

// 调用removeFrom之后，需将pStartDel前一节点的pNext_指针置为NULL
auto removeFrom = [](pNote pStartDel, int32_t &num){
        pNote pCur, pNet;
        pCur = pNet = pStartDel;
        do {
            pNet = pCur->pNext_;
            delete pCur;
            pCur = pNet;
            --num;
        } while (pCur != nullptr);
    };

// 对象只能初始化一次
class GenList
{
    public:
    GenList(uint32_t num):num_(num), pHead_(nullptr){}
    ~GenList(){destroyList();}

    void setList()
    {
        if (pHead_ != nullptr) {
            return;
        } else {
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

    pNote getList()const{return pHead_;}

    void showList()
    {
        if (pHead_ == nullptr || pHead_->pNext_ == nullptr) {
            std::cout << "list is null\n" << std::endl;
        } else {
            pNote pCur = pHead_->pNext_;
            std::cout << "list total: " << num_ << std::endl;
            do {
                std::cout << pCur->value_ << ", ";
                pCur = pCur->pNext_;
            } while(pCur != nullptr);

            std::cout << std::endl;
        }
    }

    void removeItemFrom(pNote pStartDel){removeFrom(pStartDel, num_);}

    void destroyList()
    {
        if (pHead_ == nullptr) {
            return;
        } else {
            removeFrom(pHead_, num_);
            pHead_ = nullptr;
        }
    }

    private:
    int32_t num_;
    pNote pHead_;  // 链表节点数不包含头节点
};
#endif