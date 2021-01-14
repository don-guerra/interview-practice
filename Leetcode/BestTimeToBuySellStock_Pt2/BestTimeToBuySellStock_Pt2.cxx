#include <stdio.h>
#include <vector>
#include <string>

int maxProfit(std::vector<int> &prices)
{
    int profit = 0;
    for (int i = 1; i < prices.size(); i++)
    {
        if (prices[i] > prices[i - 1])
        {
            profit += prices[i] - prices[i - 1];
        }
    }

    return profit;
}

int main()
{
    std::vector<int> prices{7, 1, 5, 3, 6, 4};
    printf("First Result: %d\n", maxProfit(prices));

    return 0;
}