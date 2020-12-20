#include <iostream>
#include <string>

int main()
{
    int32_t stock_price[5] = {9,21,8,19,13};
    int32_t days = sizeof(stock_price) / sizeof(int32_t);
    int32_t wavy_profit[days][2];  // line: 卖出收益  low: 买入收益

    // 03: 股票最大收益，只有在手中没有票的时候买入
    // 时间复杂度：O(n)

    auto getMax = [](int32_t a, int32_t b) ->int32_t {return a > b ? a : b;};
    wavy_profit[0][0] = 0;
    wavy_profit[0][1] = 0 - stock_price[0];
    int32_t i = 1;
    do {
        wavy_profit[i][0] = getMax(wavy_profit[i - 1][0], stock_price[i] + wavy_profit[i - 1][1]);
        wavy_profit[i][1] = getMax(wavy_profit[i - 1][1], wavy_profit[i - 1][0] - stock_price[i]);
    } while (++i < days);
    

    std::cout << "\n***************************" << std::endl;
    std::cout << "max profit: " << wavy_profit[i - 1][0] << std::endl;
    std::cout << "\n***************************" << std::endl;

    return 0;
}