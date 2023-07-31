#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int missingNumber(vector<int> &nums)
    {
        int  size       = nums.size();
        long ariphm_sum = size * (size + 1) / 2;

        for (auto &&elem : nums)
            ariphm_sum -= elem;

        return ariphm_sum;
    }
};

int main()
{
    Solution    sol;
    vector<int> vec = {0, 1};

    std::cout << sol.missingNumber(vec) << '\n';

    return 0;
}
