#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<int> plusOne(vector<int> &digits)
    {
        int remain = 0;

        digits[digits.size() - 1]++;
        for (int i = digits.size() - 1; i >= 0; --i) {
            digits[i] += remain;
            remain = digits[i] / 10;
            digits[i] %= 10;

            if (!remain)
                break;
        }

        if (!remain)
            return digits;

        vector<int> res{1};
        res.insert(res.end(), digits.begin(), digits.end());
        return res;
    }
};

int main() { return 0; }
