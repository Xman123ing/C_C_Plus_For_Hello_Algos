#include <iostream>
#include <string>
#include <time.h>
#include <memory>

#ifndef USE_SHARED_PTR
#define USE_SHARED_PTR
#endif

#ifndef USE_SHARED_PTR
#define RANGE_VALUE 50
#define LIST_LEN 5

int32_t NumberRand()
{
    //srand(time(nullptr));
    return rand() % RANGE_VALUE;
}

typedef struct Note
{
    int32_t value_;
    Note *pNext_;

    public:
    Note(int32_t value):value_(value), pNext_(nullptr){}
    Note():value_(NumberRand()), pNext_(nullptr){}
} *pNote;

int main()
{
    pNote pHead, pCur, pPre, pTemp;
    pHead = pCur = pPre = nullptr;

    srand(time(nullptr));
    pHead = new Note();
    pPre = pCur = new Note();
    pHead->pNext_ = pCur;

    // generate list
    int32_t i = 0;
    while(++i < LIST_LEN) {
        pCur = new Note();
        pPre->pNext_ = pCur;
        pPre = pCur;
    }

    // print origin list
    std::cout << "\n***************************************************************" << std::endl;
    i = 0;
    pTemp = pHead;
    while (pTemp->pNext_ != nullptr) {
        std::cout << pTemp->value_ << ", ";
        pTemp = pTemp->pNext_;
        ++i;
    }
    std::cout << "\ntotal len: " << i << std::endl;
    std::cout << "\n***************************************************************" << std::endl;

    return 0;
}

#else

#endif