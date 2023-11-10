#include <algorithm>
#include <vector>

using namespace std;

class Solution {
  public:
    int lengthOfLIS(vector<int> &nums)
    {
        vector<int> subs_len(nums.size(), 1);
        for (size_t i = 1; i < nums.size(); ++i) {
            for (size_t j = 0; j < i; ++j) {
                if (nums[j] < nums[i])
                    subs_len[i] = std::max(subs_len[i], subs_len[j] + 1);
            }
        }

        return *std::max_element(subs_len.begin(), subs_len.end());
    }
};
