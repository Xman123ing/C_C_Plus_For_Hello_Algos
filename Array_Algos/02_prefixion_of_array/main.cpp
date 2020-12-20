#include <iostream>
#include <string.h>
#include <string>

int main()
{
    const char *c_array[3] = {"flower", "flow", "flight"};
    size_t min_len = strlen(c_array[1]);
    char c_prefixtion[min_len + 1];
    memcpy(c_prefixtion, c_array[1], min_len);
    // 01: 数组公共前缀，不使用str函数
    // 时间复杂度： O(n^2)
    int i = 0, j =0;
    for (; i < sizeof(c_array) / sizeof(c_array[0]); ++i) {
        const char *a0 = c_array[i];
        j = 0;

        for (; j < min_len; ++j) {
            if (c_prefixtion[j] == a0[j]) {
                continue;
            }
            else
            {
                break;
            }
        }
        if (j == 0) {
            break;
        }
        c_prefixtion[j] = '\0';
        min_len = j;
        std::cout << "current: " << c_prefixtion << std::endl;
    }

    std::cout << "\n***************************" << std::endl;
    std::cout << "result: " << c_prefixtion << std::endl;
    std::cout << "\n***************************" << std::endl;
    return 0;
}