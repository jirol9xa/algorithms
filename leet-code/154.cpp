#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int findMin(const vector<int> &nums)
    {
        int begin = 0, end = nums.size() - 1;
        if (nums[0] < nums[end])
            return nums[0];
        while (nums[begin] == nums[end] && end > 0)
            --end;
        if (nums[end] == nums[begin])
            return nums[0];

        int end_elem = nums[end];

        while (begin < end) {
            int mid = (begin + end) / 2;
            if (nums[mid] <= end_elem)
                end = mid;
            else
                begin = mid + 1;
        }

        return nums[begin];
    }
};

int main()
{
    Solution    sol;
    vector<int> vec = {3, 3};

    std::cout << sol.findMin(vec) << '\n';

    return 0;
}
