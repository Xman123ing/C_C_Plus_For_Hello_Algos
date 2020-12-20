#include <iostream>
#include <string>

int main()
{
    int32_t a_origin[11] = {8,13,2,13,15,4,14,15,7,11, 13};
    int32_t len = sizeof(a_origin) / sizeof(int32_t), duplicate_num = 0, duplicale_value = 13;

    // 数组元素原地删除
    // 空间复杂度：O(1)
    // 时间复杂度：O(n)
    int32_t i = 1;
    for (; i < len; ++i) {
        if (a_origin[i - 1] == duplicale_value) {
            ++duplicate_num;
            a_origin[i - duplicate_num] = a_origin[i];
        } else {
            a_origin[i - duplicate_num] = a_origin[i];
        }
    }

    if (a_origin[i - 1] == duplicale_value) {
        ++duplicate_num;
    }

    std::cout << "\n***************************" << std::endl;
    std::cout << "result: " << len - duplicate_num << "    {";
    for (i = 0; i < len - duplicate_num; ++i) {
        std::cout << a_origin[i] << ", ";
    }
    std::cout << "}\n***************************" << std::endl;


    return 0;
}