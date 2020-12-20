#include <iostream>
#include <string>

int main()
{
    int32_t a_origin[7] = {4,9,2,16,19,12,3};
    int32_t num = sizeof(a_origin) / sizeof(int32_t), k = 4;
    int32_t right_k = k % num, left_k = num - right_k;
    
    // 旋转数组：原地旋转，不使用mem*函数
    // 空间复杂度： 0(1)
    // 时间复杂度：O(n)
    
    // 翻转函数
    auto FuncRotate = [&a_origin](int32_t len, int32_t offset){
        int32_t switch_value, left_index, right_index;
        for (int32_t i = 0; i < len - 1 - i; ++i) {
                right_index = i + offset;
                left_index = len - 1 - i + offset;
                switch_value = a_origin[right_index];
                a_origin[right_index] = a_origin[left_index];
                a_origin[left_index] = switch_value;
        };
    };
    // 全部翻转
    FuncRotate(num, 0);
    std::cout << "\nfully rotate: {";
    for (int32_t i = 0; i < num; ++i) {
        std::cout << a_origin[i] << ", ";
    }
    std::cout << "}\n\n" << std::endl;

    // 右边旋转
    FuncRotate(right_k, 0);
    // 左边旋转
    FuncRotate(left_k, right_k);

    std::cout << "\n***************************" << std::endl;
    std::cout << "result: {";
    for (int32_t i = 0; i < num; ++i) {
        std::cout << a_origin[i] << ", ";
    }
    std::cout << "}\n***************************" << std::endl;

    return 0;
}