#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int leftBinSearch(int begin, int end, int target, vector<int> &vec)
    {
        while (end > begin) {
            int mid = (end + begin) / 2;
            if (vec[mid] >= target)
                end = mid;
            else
                begin = mid + 1;
        }

        return begin;
    }

    int rightBinSearch(int begin, int end, vector<int> &vec)
    {
        int begin_elem = vec[begin];
        while (end > begin) {
            int mid = (end + begin) / 2;
            if (vec[mid] < begin_elem)
                end = mid;
            else
                begin = mid + 1;
        }

        return begin;
    }

    int search(vector<int> &nums, int target)
    {
        int begin = nums.size() - 1;
        if (nums[0] > nums[nums.size() - 1])
            begin = rightBinSearch(0, nums.size() - 1, nums);

        int res = -1;
        if (target < nums[0])
            res = leftBinSearch(begin, nums.size() - 1, target, nums);
        else
            res = leftBinSearch(0, begin, target, nums);

        return (nums[res] == target) ? res : -1;
    }
};

int main()
{
    Solution    sol;
    vector<int> vec = {3, 1};

    std::cout << sol.search(vec, 1) << '\n';

    return 0;
}
