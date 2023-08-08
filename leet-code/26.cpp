#include <iostream>
#include <vector>

using namespace std;

void vecPrint(vector<int> &vec)
{
    for (auto &&elem : vec)
        std::cout << elem << ' ';

    std::cout << '\n';
}

class Solution {
  public:
    int removeDuplicates(vector<int> &nums)
    {
        int i = 1, j = 1;

        for (; j < nums.size(); ++j) {
            if (nums[j] != nums[i - 1])
                std::swap(nums[i++], nums[j]);
        }

        return i;
    }
};

int main()
{
    Solution    sol;
    vector<int> vec = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};

    std::cout << sol.removeDuplicates(vec) << '\n';
    vecPrint(vec);

    return 0;
}
