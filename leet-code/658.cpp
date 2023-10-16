#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<int> findClosestElements(const vector<int> &arr, int k, int x)
    {
        vector<pair<int, int>> vec(arr.size());
        for (int i = 0; i < arr.size(); ++i)
            vec[i] = {arr[i], arr[i]};
        for (auto &elem : vec)
            elem.second = std::abs(elem.second - x);

        std::sort(vec.begin(), vec.end(), [](auto first, auto second) {
            if (first.second == second.second)
                return first.first < second.first;
            return first.second < second.second;
        });

        vector<int> res;
        for (int i = 0; i < k; ++i)
            res.push_back(vec[i].first);

        std::sort(res.begin(), res.end());
        return res;
    }
};

int main()
{
    Solution sol;
    auto     res = sol.findClosestElements({1, 2, 3, 4, 5}, 4, -1);
    for (auto &&elem : res)
        std::cout << elem << ' ';
    std::cout << '\n';

    return 0;
}
