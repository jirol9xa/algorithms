#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<int> findAnagrams(string s, string p)
    {
        if (s.size() < p.size())
            return {};

        int p_syms[26] = {0};
        for (auto &&sym : p)
            p_syms[sym - 'a']++;

        int s_syms[26] = {0};
        for (int i = 0; i < p.size(); ++i)
            s_syms[s[i] - 'a']++;

        auto is_equal = [&]() {
            for (int i = 0; i < 26; ++i) {
                if (s_syms[i] != p_syms[i])
                    return false;
            }

            return true;
        };

        vector<int> res;
        if (is_equal())
            res.push_back(0);

        for (int left = 0, right = p.size(); right < s.size(); ++right, ++left) {
            s_syms[s[left] - 'a']--;
            s_syms[s[right] - 'a']++;

            if (is_equal())
                res.push_back(left + 1);
        }

        return res;
    }
};

int main()
{
    Solution sol;

    return 0;
}
