#include <iostream>

class Solution {
  public:
    int arrangeCoins(int n)
    {
        int i = 0;
        for (; n > 0;)
            n -= ++i;

        return i - (n < 0);
    }
};

int main()
{
    int n = 0;
    std::cin >> n;

    Solution sol;
    std::cout << sol.arrangeCoins(n);

    return 0;
}
