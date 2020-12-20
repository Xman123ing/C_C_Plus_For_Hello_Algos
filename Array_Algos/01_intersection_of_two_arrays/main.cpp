#include <iostream>
#include <string>

int main()
{
    int array_a[10] = {9,14,20,19,52,66,38,94,78,67};
    int array_b[10] = {68,92,52,66,72,9,72,5,54,2};
    int array_intersection[10 * 10], ii = 0;

    // 01:数组交集
    // 时间复杂度：O(n^2)
    for (int ia = 0; ia < 10; ++ia) {
        for (int ib = 0; ib < 10; ++ib) {
            if (array_a[ia] == array_b[ib]) {
                array_intersection[ii++] = array_a[ia];
            }
        }
    }

    std::cout << std::endl << "***************************************************************" << std::endl;
    std::cout << "intersection = { ";
    for (int i = 0; i < ii; ++i) {
        std::cout << array_intersection[i] << ", ";
    }
    std::cout << "}" << std::endl;
    std::cout << std::endl << "***************************************************************" << std::endl;

    // 02:有序数组交集
    // 时间复杂度：O(n)
    int array_a_sort[10] = { 9, 14, 19, 20, 38, 52, 66, 67, 78, 94,};
    int array_b_sort[10] = { 2, 5, 9, 52, 54, 66, 68, 72, 72, 92};
    memset(array_intersection, 0, sizeof(array_intersection));
    ii = 0;
    for (int ia = 0, ib = 0; ia < 10 && ib < 10;) {
        if (array_a_sort[ia] == array_b_sort[ib]) {
            array_intersection[ii++] = array_a_sort[ia];
            ++ia;
            ++ib;
        } else if (array_a_sort[ia] > array_b_sort[ib]) {
            ++ib;
        } else if (array_a_sort[ia] < array_b_sort[ib]) {
            ++ia;
        }
    }

    std::cout << std::endl << "***************************************************************" << std::endl;
    std::cout << "sort intersection = { ";
    for (int i = 0; i < ii; ++i) {
        std::cout << array_intersection[i] << ", ";
    }
    std::cout << "}" << std::endl;
    std::cout << std::endl << "***************************************************************" << std::endl;
    
    return 0;
}