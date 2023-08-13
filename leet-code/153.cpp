#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int leftBinSearch(int begin, int end, vector<int> &vec)
    {
        auto end_elem = vec[vec.size() - 1];
        while (begin < end) {
            int mid = (begin + end) / 2;
            if (vec[mid] <= end_elem)
                end = mid;
            else
                begin = mid + 1;
        }

        return begin;
    }

    int findMin(vector<int> &nums)
    {
        if (nums[0] <= nums[nums.size() - 1])
            return nums[0];

        int res = leftBinSearch(0, nums.size() - 1, nums);
        return nums[res];
    }
};

int main()
{
    Solution    sol;
    vector<int> vec = {4, 5, 6, 7, 0, 1, 2};

    std::cout << sol.findMin(vec);

    return 0;
}
