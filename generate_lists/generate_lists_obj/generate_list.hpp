#ifndef __GENERATE_LIST__HPP__
#define __GENERATE_LIST__HPP__
#include <iostream>
#include <string>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

#define RANGE_VALUE 100

typedef struct Note
{
    int32_t value_;
    Note *pNext_;

    Note(int32_t value):value_(value), pNext_(nullptr){}
    Note():value_(NumberRand()), pNext_(nullptr){}

    int32_t NumberRand()
    {
        return rand() % RANGE_VALUE;
    }
} *pNote;

// 对象只能初始化一次
class GenList
{
public:
    GenList():num_(0), pHead_(nullptr){}
    ~GenList(){destroyList();}

    void setList(uint32_t num);
    pNote getList()const{return pHead_;}
    void showList();
    void removeItemFrom(pNote pStartDel, uint32_t num);
    void destroyList();
    void bubble_sort();

private:
    uint32_t num_;
    pNote pHead_;  // 链表节点数不包含头节点
};
#endif