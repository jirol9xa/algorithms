#include <iostream>
#include <utility>
#include <vector>

using namespace std;

class Solution {
  public:
    int maxProfit(vector<int> &prices)
    {
        struct Day {
            int price;
            int date;
        };

        if (prices.size() == 1)
            return 0;

        Day buy                     = {prices[0], 0};
        Day sell                    = {prices[1], 1};
        Day best_for_buy            = (buy.price < sell.price) ? buy : sell;
        Day best_for_sell_after_buy = {};

        for (int i = 2; i < prices.size(); ++i) {
            if (prices[i] >= sell.price)
                sell = {prices[i], i};

            if (best_for_buy.date < sell.date)
                buy = best_for_buy;

            if (best_for_sell_after_buy.price < prices[i] && best_for_buy.date < i)
                best_for_sell_after_buy = {prices[i], i};

            if (prices[i] < best_for_buy.price)
                best_for_buy = {prices[i], i};
        }

        if (best_for_sell_after_buy.price - best_for_buy.price > sell.price - buy.price &&
            best_for_sell_after_buy.date > best_for_buy.date) {
            buy  = best_for_buy;
            sell = best_for_sell_after_buy;
        }

        return (sell.price - buy.price) > 0 ? (sell.price - buy.price) : 0;
    }
};

int main()
{
    Solution    sol;
    vector<int> vec = {3, 3, 5, 0, 0, 3, 1, 4};

    std::cout << sol.maxProfit(vec) << '\n';

    return 0;
}
