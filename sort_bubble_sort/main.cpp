#include <iostream>
#include <string>
#include <stdint.h>

int main()
{
    // 时间复杂度：O(n^2)
    uint32_t array_a[10] = {68,92,52,66,72,9,72,5,54,2};
    for (uint32_t ia = 0; ia < 10; ++ia) {
        for (uint32_t ja = 0; ja < 10 - ia - 1; ++ja) {
            if (array_a[ja] > array_a[ja + 1]) {
                // 交换两个元素
                array_a[ja] += array_a[ja + 1];
                array_a[ja + 1] = array_a[ja] - array_a[ja + 1];
                array_a[ja] -= array_a[ja + 1];
            }
        }
    }

    std::cout << "bubble sort = { ";
    for (int i = 0; i < 10; ++i) {
        std::cout << array_a[i] << ", ";
    }
    std::cout << "}" << std::endl;

    return 0;
}