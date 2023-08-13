#include <functional>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    int leftBinSearch(int begin, int end, vector<int> &nums,
                      const std::function<bool(int)> &cmp)
    {
        while (end > begin) {
            int mid = (end + begin) / 2;
            if (cmp(nums[mid]))
                end = mid;
            else
                begin = mid + 1;
        }

        return end;
    }

    int rightBinSearch(int begin, int end, vector<int> &nums,
                       const std::function<bool(int)> &cmp)
    {
        while (end > begin) {
            int mid = (end + begin + 1) / 2;
            if (cmp(nums[mid]))
                begin = mid;
            else
                end = mid - 1;
        }

        return end;
    }

  public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        if (nums.empty())
            return {-1, -1};

        int first_pos = leftBinSearch(0, nums.size() - 1, nums,
                                      [=](const int elem) { return elem >= target; });
        int last_pos  = rightBinSearch(first_pos, nums.size() - 1, nums,
                                       [=](const int elem) { return elem <= target; });

        if (nums[first_pos] != target)
            first_pos = -1;
        if (nums[last_pos] != target)
            last_pos = -1;

        return {first_pos, last_pos};
    }
};

int main()
{
    Solution    sol;
    vector<int> vec    = {5, 7, 7, 8, 8, 10};
    int         target = 6;

    auto res = sol.searchRange(vec, target);
    std::cout << "begin = " << res[0] << ", end = " << res[1] << '\n';
    return 0;
}
