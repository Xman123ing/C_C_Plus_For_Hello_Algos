#include <iostream>
#include <string>

int main()
{
    int32_t a_origin[13] = {-1,15,-31,30,-2,18,1,36,16,0,38,22,-18};
    int32_t nums = sizeof(a_origin) / sizeof(int32_t), target = 0, i = 0;
    // 三数之和为target，且三元组不能重复
    // 时间复杂度：O(n^2)

    // 先排序， 冒泡排序法
    std::cout << "origin = { ";
    for (i = 0; i < nums; ++i) {
        std::cout << a_origin[i] << ", ";
    }
    std::cout << "}" << std::endl;

    // 开始排序
    for (uint32_t ia = 0; ia < nums; ++ia) {
        for (uint32_t ja = 0; ja < nums - ia - 1; ++ja) {
            if (a_origin[ja] > a_origin[ja + 1]) {
                // 交换两个元素
                a_origin[ja] += a_origin[ja + 1];
                a_origin[ja + 1] = a_origin[ja] - a_origin[ja + 1];
                a_origin[ja] -= a_origin[ja + 1];
            }
        }
    }

    std::cout << "bubble sort = { ";
    for (i = 0; i < nums; ++i) {
        std::cout << a_origin[i] << ", ";
    }
    std::cout << "}" << std::endl;

    // 开始查找三元组
    // 方法解析：先排序，然后固定一个数，再设置两个指针，分别指向最大，最小值，
    // 然后根据三者之和与target比较，动态调整两个指针

    std::cout << "result: " << std::endl;
    for (i = 0; i < nums - 2; ++i) {  // 固定一个数
        int32_t left_i = i + 1, right_i = nums - 1;
        while(left_i < right_i) {
            int32_t sum = a_origin[i] + a_origin[left_i] + a_origin[right_i];
            if (sum == target) {
                std::cout << "{" << a_origin[i] << ", " << a_origin[left_i] << ", " << a_origin[right_i] << "}" << std::endl;
                ++left_i;
                --right_i;
            } else if (sum > target) {
                --right_i;
            }
            else {
                ++left_i;
            }
        }
    }

    return 0;
}