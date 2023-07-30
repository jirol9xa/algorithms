#include <iostream>
#include <utility>
#include <vector>

using namespace std;

// TODO: Make solution without extra mem

class Solution {
  public:
    int longestSubarray(vector<int> &nums)
    {
        int size = nums.size();
        if (nums.size() == 1)
            return 0;

        using elem_t = std::pair<int, int>;

        vector<elem_t> vec;

        int prev_elem = nums[0];
        int curr_amnt = 1;
        for (int i = 1; i < size; ++i) {
            if (nums[i] == prev_elem) {
                curr_amnt++;
            }
            else {
                vec.emplace_back(prev_elem, curr_amnt);
                prev_elem = nums[i];
                curr_amnt = 1;
            }
        }
        vec.emplace_back(prev_elem, curr_amnt);

        // We have array here from <0/1, amount in raw>
        int vec_size = vec.size();
        if (vec_size == 1 && vec[0].first == 1)
            return vec[0].second - 1; // -1 because we must delete one  element

        // Process first elem
        int max_sub = vec[0].second * vec[0].first;
        for (int i = 1; i < vec_size - 1; ++i) {
            const auto &[elem_val, elem_amnt] = vec[i];
            if (elem_val == 0 && elem_amnt == 1) {
                const auto &[left_val, left_amnt]   = vec[i - 1];
                const auto &[right_val, right_amnt] = vec[i + 1];

                if (left_val && right_val)
                    max_sub = std::max(max_sub, left_amnt + right_amnt);
            }
            if (vec[i].first == 1)
                max_sub = std::max(max_sub, vec[i].second);
        }

        // Process last elem
        max_sub = std::max(max_sub, vec[vec_size - 1].second * vec[vec_size - 1].first);

        return max_sub;
    }
};

int main()
{
    Solution    sol;
    vector<int> vec = {0, 0, 1, 1};

    std::cout << sol.longestSubarray(vec) << '\n';

    return 0;
}
