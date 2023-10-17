#include <iostream>
#include <vector>

using namespace std;

class Solution {
    int leftBinSearch(int begin, int end, const vector<int> &nums, int target)
    {
        while (begin < end) {
            int mid = (begin + end) / 2;
            if (nums[mid] >= target)
                end = mid;
            else
                begin = mid + 1;
        }

        return begin;
    }

    int rightBinSearch(int begin, int end, const vector<int> &nums, int target)
    {
        while (begin < end) {
            int mid = (begin + end + 1) / 2;
            if (nums[mid] <= target)
                begin = mid;
            else
                end = mid - 1;
        }

        return begin;
    }

  public:
    bool search(const vector<int> &nums, int target)
    {
        int begin = 0;
        int end   = nums.size() - 1;

        if (nums[begin] == target || nums[end] == target)
            return true;
        for (; nums[begin] == nums[end] && begin < end; --end, ++begin)
            continue;
        if (nums[begin] == target)
            return true;

        {
            int end_impl = end;
            while (begin < end_impl) {
                int mid = (begin + end_impl) / 2;
                if (nums[mid] < nums[0])
                    end_impl = mid;
                else
                    begin = mid + 1;
            }
        }

        int pos = leftBinSearch(begin, end, nums, target);
        if (nums[pos] != target)
            pos = leftBinSearch(0, begin - 1, nums, target);

        return nums[pos] == target;
    }
};

int main()
{
    Solution sol;
    std::cout << sol.search({5, 1, 3}, 1);

    return 0;
}
