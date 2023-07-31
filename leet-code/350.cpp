#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_map<int, int> map;
        vector<int>             res;

        // Fill the map
        for (auto &&elem1 : nums1)
            map[elem1]++;

        // Find in map
        for (auto &&elem2 : nums2) {
            auto &map_elem = map[elem2];
            if (map_elem) {
                --map_elem;
                res.push_back(elem2);
            }
        }

        return res;
    }
};

int main()
{
    Solution    sol;
    vector<int> vec1 = {1, 2, 2, 1};
    vector<int> vec2 = {2, 2};

    auto res = sol.intersect(vec1, vec2);
    for (auto &&elem : res)
        std::cout << elem << ' ';

    return 0;
}
