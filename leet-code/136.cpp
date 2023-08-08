#include <algorithm>
#include <vector>

using namespace std;

class Solution {
  public:
    int singleNumber(vector<int> &nums)
    {
        int single = 0;
        std::for_each(nums.begin(), nums.end(), [&single](auto elem) { single ^= elem; });

        return single;
    }
};

int main() { return 0; }
