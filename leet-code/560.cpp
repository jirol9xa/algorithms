#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<int> calcPrefixSum(const vector<int> &nums)
    {
        vector<int> res(nums.size());
        res[0] = nums[0];

        for (int i = 1; i < nums.size(); ++i)
            res[i] = res[i - 1] + nums[i];

        return res;
    }

    int subarraySum(const vector<int> &nums, int k)
    {
        vector<int>             prefix_sum = calcPrefixSum(nums);
        unordered_map<int, int> sum_map;
        int                     res = 0;

        for (auto &&elem : prefix_sum) {
            if (elem == k)
                res++;

            if (sum_map.find(elem - k) != sum_map.end())
                res += sum_map[elem - k];

            sum_map[elem]++;
        }

        return res;
    }
};

int main()
{
    Solution sol;
    std::cout << sol.subarraySum({-1, 1, 0, 1, 0}, 0) << '\n';

    return 0;
}
