#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        vector<vector<int>> res;
        std::sort(intervals.begin(), intervals.end(),
                  [](auto &elem1, auto &elem2) { return elem1[0] < elem2[0]; });

        int upper_bound = intervals[0][1], lower_bound = intervals[0][0];

        auto is_intersec = [&](vector<int> first, vector<int> second) {
            auto begin1 = first[0], end1 = first[1];
            auto begin2 = second[0], end2 = second[1];

            return (begin1 <= begin2 && begin2 <= end1) ||
                   (begin2 <= begin1 && begin1 <= end2);
        };

        for (int i = 1; i < intervals.size(); ++i) {
            auto &begin = intervals[i][0], end = intervals[i][1];

            if (is_intersec({lower_bound, upper_bound}, intervals[i])) {
                lower_bound = std::min(begin, lower_bound);
                upper_bound = std::max(end, upper_bound);
            }
            else {
                res.push_back({lower_bound, upper_bound});
                lower_bound = begin;
                upper_bound = end;
            }
        }

        res.push_back({lower_bound, upper_bound});

        return res;
    }
};

int main()
{
    Solution sol;

    vector<vector<int>> vec = {{1, 4}, {0, 4}}; //{{1, 4}, {4, 5}};

    auto res = sol.merge(vec); // ({{1, 3}, {2, 6}, {8, 10}, {15, 18}});
    for (auto &&elem : res)
        std::cout << "[" << elem[0] << ", " << elem[1] << "], ";

    return 0;
}
