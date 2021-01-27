#include <iostream>
#include <string>
#include <vector>
#include <time.h>

int numbers = 0, rang_number = 0;

int main(int argc, char *argv[])
{
    if (argc != 3) {
        std::cout << "The number of params must be double" << std::endl;
        return -1;
    }

    // argv[1] --- numbers  argv[2] --- rang number
    if (argv[1] != nullptr && argv[2] != nullptr) {
        numbers = atoi(argv[1]);
        rang_number = atoi(argv[2]);
        std::cout << "numbers = " << numbers << std::endl << "rang_number = " << rang_number << std::endl;
    }

    int i = 0;
    std::vector<int> v_array;
    srand(time(nullptr));
    do {
        v_array.emplace_back(rand() % rang_number);
    } while (++i < numbers);

    std::cout << std::endl << "***************************************************************" << std::endl;
    std::cout << "array[" << numbers << "] = {";
    for (const auto &iter : v_array) {
        std::cout << iter << ", ";
    }
    std::cout << "}" << std::endl;
    std::cout << "***************************************************************" << std::endl;
    return 0;
}