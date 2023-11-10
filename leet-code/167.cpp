#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<int> twoSum(const vector<int> &numbers, int target)
    {
        for (int i = 0; i < numbers.size(); ++i) {
            int begin = i + 1, end = numbers.size() - 1;
            while (begin < end) {
                int mid = (begin + end) / 2;
                if (numbers[mid] >= target - numbers[i])
                    end = mid;
                else
                    begin = mid + 1;
            }

            if (numbers[begin] + numbers[i] == target) {
                return {std::min(begin, i) + 1, std::max(begin, i) + 1};
            }
        }

        return {};
    }
};

int main()
{
    Solution sol;
    auto res = sol.twoSum({-1, -1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                           1,  1,  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                           1,  1,  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                           1,  1,  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                           1,  1,  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                          -2);
    for (auto &&elem : res)
        std::cout << elem << ' ';
    std::cout << '\n';

    return 0;
}
