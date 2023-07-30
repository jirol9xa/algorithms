#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<string> summaryRanges(vector<int> &nums)
    {
        int size = nums.size();
        if (!size)
            return {};

        vector<string> res;
        int            last_numer = nums[0];
        string         str        = to_string(last_numer);

        for (int i = 1; i < size; ++i) {
            if (nums[i] != nums[i - 1] + 1) {
                if (nums[i - 1] != last_numer) {
                    str += "->";
                    str += to_string(nums[i - 1]);
                }
                res.push_back(str);

                last_numer = nums[i];
                str        = to_string(last_numer);
            }
        }

        if (last_numer != nums[size - 1]) {
            str += "->";
            str += to_string(nums[size - 1]);
        }
        res.push_back(str);

        return res;
    }
};

int main()
{
    Solution    sol;
    vector<int> vec = {0, 2, 3, 4, 6, 8, 9};

    auto res = sol.summaryRanges(vec);
    for (auto &&elem : res)
        cout << elem << ' ';

    return 0;
}
