#include <iostream>
#include <string>

int main()
{
    
    uint32_t a_origin[5] = {9,4,6,2,9};
    uint32_t addition = 1, num = sizeof(a_origin) / sizeof(uint32_t), temp;
    int32_t i;

    std::cout << "\n***************************" << std::endl;
    std::cout << "origin: ";
    for (i = 0; i < num; ++i) {
        std::cout << a_origin[i];
    }

    // 整数加1
    // 时间复杂度：O(n)
    std::cout << "\n***************************" << std::endl;

    for (i = num - 1; i >= 0; --i) {
        temp = a_origin[i] + addition;
        if (temp >= 10) {
            a_origin[i] = 0;
            addition = 1;
        } else {
            a_origin[i] += addition;
            addition = 0;
        }
    }

    std::cout << "\n***************************" << std::endl;
    std::cout << "result: ";
    if (addition != 0) {
        std::cout << addition;
    }
    for (i = 0; i < num; ++i) {
        std::cout << a_origin[i];
    }
    std::cout << "\n***************************" << std::endl;

    return 0;
}