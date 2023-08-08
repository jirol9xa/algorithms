#include <iostream>
#include <string>

using namespace std;

class Solution {
  public:
    string addBinary(string &a, string &b)
    {
        if (a.size() < b.size())
            std::swap(a, b);

        int remain = 0;
        int i      = a.size() - 1;
        for (int j = b.size() - 1; j >= 0; --i, --j) {
            a[i]   = a[i] + b[j] - 2 * '0' + remain;
            remain = a[i] / 2;
            a[i] %= 2;
            a[i] += '0';
        }

        for (; i >= 0; --i) {
            a[i] += remain - '0';
            remain = a[i] / 2;
            a[i] %= 2;
            a[i] += '0';

            if (!remain)
                break;
        }

        if (!remain)
            return a;

        return string("1") + a;
    }
};

int main()
{
    Solution sol;
    string   a = "1010", b = "1011";

    std::cout << sol.addBinary(a, b) << '\n';

    return 0;
}
