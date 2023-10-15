#include <cstring>
#include <iostream>
#include <string>

using namespace std;

class Solution {
  public:
    bool checkInclusion(string s1, string s2)
    {
        if (s2.length() < s1.length())
            return false;

        unsigned char s1_syms[26] = {0};
        for (auto &&elem : s1)
            s1_syms[elem - 'a']++;

        unsigned char s2_syms[26] = {0};
        // Fill the initial window syms
        for (int i = 0; i < s1.size(); ++i)
            s2_syms[s2[i] - 'a']++;

        auto is_eq = [&]() { return !memcmp(s1_syms, s2_syms, 26); };
        if (is_eq())
            return true;

        // left will be point on last letter before window
        for (int left = 0, right = s1.length(); right < s2.length(); ++right, ++left) {
            s2_syms[s2[left] - 'a']--;
            s2_syms[s2[right] - 'a']++;
            if (is_eq())
                return true;
        }

        return false;
    }
};

int main()
{
    Solution sol;
    string   s1 = "hello", s2 = "ooolleoooleh";

    std::cout << (sol.checkInclusion(s1, s2) ? "true" : "false") << '\n';

    return 0;
}
