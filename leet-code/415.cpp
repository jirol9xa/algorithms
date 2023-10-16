#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

class Solution {
  public:
    string addStrings(string num1, string num2)
    {
        std::reverse(num1.begin(), num1.end());
        std::reverse(num2.begin(), num2.end());

        string res    = "";
        int    remain = 0;
        for (int i = 0; i < std::min(num1.size(), num2.size()); ++i) {
            char tmp = num1[i] - '0' + num2[i] - '0' + remain;
            remain   = tmp / 10;
            tmp %= 10;

            res += char(tmp + '0');
        }

        for (int i = std::min(num2.size(), num1.size()); i < num1.size(); ++i) {
            char tmp = num1[i] - '0' + remain;
            remain   = tmp / 10;
            tmp %= 10;

            res += char(tmp + '0');
        }

        for (int i = std::min(num1.size(), num2.size()); i < num2.size(); ++i) {
            char tmp = num2[i] - '0' + remain;
            remain   = tmp / 10;
            tmp %= 10;

            res += char(tmp + '0');
        }

        if (remain)
            res += char('0' + remain);

        std::reverse(res.begin(), res.end());

        return res;
    }
};

int main()
{
    Solution sol;
    std::cout << sol.addStrings("11", "123") << '\n';

    return 0;
}
