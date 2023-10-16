#include <iostream>

using namespace std;

class Solution {
  public:
    int lengthOfLongestSubstring(string s)
    {
        if (s.size() == 0)
            return 0;

        int max_len = 0;

        char syms[127] = {0};
        auto isUniq    = [&]() {
            for (auto &&elem : syms)
                if (elem > 1)
                    return false;

            return true;
        };

        for (int begin = 0, end = 0; end < s.size(); end++) {
            syms[s[end]]++;

            while (!isUniq())
                syms[s[begin++]]--;

            max_len = std::max(max_len, end - begin + 1);
        }

        return max_len;
    }
};

int main()
{
    Solution sol;
    std::cout << sol.lengthOfLongestSubstring("") << '\n';

    return 0;
}
