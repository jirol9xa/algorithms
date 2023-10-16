#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int findUnsortedSubarray(vector<int> &nums)
    {
        if (nums.size() < 2)
            return 0;

        vector<int> nums_sorted = nums;
        std::sort(nums_sorted.begin(), nums_sorted.end());

        int begin = 0;
        for (; begin < nums.size() - 1 && nums[begin] == nums_sorted[begin]; ++begin)
            continue;

        if (begin == nums.size())
            return 0;

        int end = nums.size() - 1;
        for (; end >= begin && nums[end] == nums_sorted[end]; --end)
            continue;

        return end - begin + 1;
    }
};

int main()
{
    Solution    sol;
    vector<int> vec = {2, 6, 4, 8, 10, 9, 15};
    std::cout << sol.findUnsortedSubarray(vec) << '\n';
    return 0;
}
